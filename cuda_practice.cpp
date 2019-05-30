//serial
#include <iostream>
#include <string>
#include <array>

int main(){
    int * h_a;
    int * h_b;
    int * h_c;
    int i;
    int N=4096;
    int size=N* sizeof(int);

    h_a=(int*)malloc(size);
    h_b=(int*)malloc(size);
    h_c=(int*)malloc(size);

    for(i=0;i<N;i++){
        h_c[i]=h_a[i]+h_b[i];

    }

    std::cout<<h_c<<std::endl;
    std::cout<<&h_c<<std::endl;//为啥呢
    


    free(h_a);
    free(h_b);
    free(h_c);
    return 0;
}
//cuda simple

#include <iostream>
#include <string>
#include <array>

int main(){
    int * h_a;
    int * h_b;
    int * h_c;
    int * d_a, * d_b, * d_c;
    int i;
    int N=4096;
    int size=N* sizeof(int);
    
    h_a=(int*)malloc(size);
    h_b=(int*)malloc(size);
    h_c=(int*)malloc(size);
    
    for(i=0;i<N;i++){
        h_a[i]=i;
        h_b[i]=i;
    }
    
    //allocate in device memory
    cudaMalloc((void**)&d_a,size);
    cudaMalloc((void**)&d_b,size);
    cudaMalloc((void**)&d_c,size);
    
    //copy vectors from host to device
    cudaMemcpy(d_a,h_a,size,cudaMemcpyHostToDevice);
    
    //invoke kernel function
    int threadsPerBlock=256;
    int blocksPerGrid=N/threadsPerBlock;
    VecAdd<<<blocksPerGrid,threadsPerBlock>>>(d_a,d_b,d_c);
    
    //device code
    _global_ void VecAdd(*d_a,*d_b,*d_c){
        int i=blockDim.x*blockIdx.x+threadIdx.x;
        d_c[i]=d_a[i]+d_b[i];
    }
    
    //copy result from device to host
    cudaMemcpy(h_c,d_c,size,cudaMemcpyDeviceToHost);
    
    free(h_a);
    free(h_b);
    free(h_c);
    codaFree(d_a);
    codaFree(d_b);
    codaFree(d_c);
    
    return 0;
}
//矩阵相乘
#include <iostream>
#include <cstdio>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <cmath>

using namespace std;

const int TILE_WIDTH=16;

_global_ void MatrixMulKernel(int *d_M,int *d_N,int *d_P, int m, int n, int p){
    
    //小的tiled submatrix
    _shared_ int ds_M[TILE_WIDTH][TILE_WIDTH];
    _shared_ int ds_N[TILE_WIDTH][TILE_WIDTH];
    
    //block 的位置
    int bx=blockIdx.x;
    int by=blockIdx.y;
    //thread 的位置
    int tx=threadIdx.x;
    int ty=threadIdx.y;
    
    int row=by*TILE_WIDTH+ty;
    int col=bx*TILE_WIDTH+tx;
    int pValue=0;
    //计算开始
    for(int t=0;t<(n-1)/TILE_WIDTH+1;t++){//以每个tile为单位
        if(row<m&&TILE_WIDTH*t+tx<n){//为什么是tx不是ty
            ds_M[ty][tx] = d_M[row * n + t * TILE_WIDTH + tx];
        }
        else
            ds_M[ty][tx] = 0;
        if(col < k && t * TILE_WIDTH + ty < n)
            ds_N[ty][tx] = d_N[(t * TILE_WIDTH + ty) * k + col];//为啥是加col
        else
            ds_N[ty][tx] = 0;
        _syncthreads();
        for(int i = 0; i < TILE_WIDTH; i++)
            pValue += ds_M[ty][i] * ds_N[i][tx];
        
        _syncthreads();
    }
    if(row < m && col < k)
        d_P[row * k + col] = pValue;//只有一个值？？？
    
}

int main(){
    //freopen("out","w",stdout);
    int m = 600, n = 700, k = 1000;
    int *h_M, *h_N, *d_M, *d_N;
    int *h_P, *d_P;
    size_t sizeM = m * n * sizeof(int);
    size_t sizeN = n * k * sizeof(int);
    size_t sizeP = m * k * sizeof(int);
    
    h_M = (int *) malloc(sizeM);
    h_N = (int *) malloc(sizeN);
    h_P = (int *) malloc(sizeP);
    
    cudaMalloc(&d_M,sizeM);
    cudaMalloc(&d_N,sizeN);
    cudaMalloc(&d_P,sizeP);
    //初始化
    for(int i = 0; i < m * n; ++i){
        if(i % 2 == 0)
            h_M[i] = 1;
        else
            h_M[i] = 0;
    }
    
    for(int i = 0;i < n * k; ++i){
        if(i % 2 == 0)
            h_N[i] = 0;
        else
            h_N[i] = 1;
    }
    
    cudaMemcpy(d_M,h_M,sizeM,cudaMemcpyHostToDevice);
    cudaMemcpy(d_N,h_N,sizeN,cudaMemcpyHostToDevice);
    
    cudaEvent_t start,stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    cudaEventRecord(start,0);
    //计算需要多少个block，即grid的大小
    dim3 grid((int)ceil(k*1.0 / TILE_WIDTH), (int)ceil(m*1.0/ TILE_WIDTH));
    dim3 block(TILE_WIDTH,TILE_WIDTH);
    
    
    MatrixMulKernel<<<grid,block>>>(d_M,d_N,d_P,m,n,k);
    
    cudaEventRecord(stop,0);
    //cudaDeviceSynchronize();
    cudaEventSynchronize(stop);
    float ElapsedTime;
    cudaEventElapsedTime(&ElapsedTime,start,stop);
    printf("Kernel Elpased Time: %.3f ms\n",ElapsedTime);
    
    cudaMemcpy(h_P,d_P,sizeP,cudaMemcpyDeviceToHost);
    
    
    free(h_P);
    free(h_M);
    free(h_N);
    cudaFree(d_P);
    cudaFree(d_M);
    cudaFree(d_N);
    
    return 0;
}
