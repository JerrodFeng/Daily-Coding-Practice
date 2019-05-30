
//一个简单的矩阵乘法 不知道为啥不对
#include <stdio.h>

#include <stdlib.h>
#include <iostream>
using namespace std;

int r[3*4]={0};
void matrix_multiply(int m1[6], int m2[8]){

    int x=3;
    int y=2;
    int z=4;

    for(int i=0;i<x;i++){
        for(int j=0;j<z;j++){
            for(int k=0;k<y;k++){
                r[z*i+j]+=m1[x*i+k]*m2[z*k+j];
            }
        }
    }
    //return r;
}



//#include <iostream>
//using namespace std;
//
//int d[3*2]={0};

////一维数组存储矩阵乘法
//void multi2(int a[9], int b[6]){
//    int x=3;
//    int y=3;
//    int z=2;
//
//    for (int i=0;i<x;i++)			//i代表a矩阵的行数
//    {
//        for (int j=0;j<z;j++)		//j代表b矩阵的列数
//        {
//            for (int k=0;k<y;k++)	//k代表a矩阵的列数和b数组的行数
//            {
//                //一个矩阵用一维数组存储时(假设该矩阵为m*n的)，则
//                //a[i][j]在这个一维数组中的位置为array[n*i+j]
//                d[z*i+j]+=a[x*i+k]*b[z*k+j];
//            }
//        }
//    }
//}
//
//int main(){
//    //使用一维数组进行矩阵乘法运算
//    int a1[9]={1,1,1,2,2,2,3,3,3};
//    int b1[6]={1,2,3,4,5,6};
//    //for (int i=0;i<6;i++)
//    //	d[i]=0;
//    multi2(a1,b1);
//    for (int i=0;i<6;i++)
//        cout << d[i] << " ";
//    cout << endl;
//
//
//    return 0;
//}
int main(){
    int m1[6]={2,-6,3,5,1,-1};
    int m2[8]={4,-2,-4,-5,-7,-3,6,7};


    matrix_multiply(m1,m2);

    for(int q=0;q<12;q++){
        cout<<r[q]<<" ";
    }
    cout<<endl;
}

