//practice 矩阵相乘
#include <iostream>
#include <string>
#include <array>
using namespace std;


int main(){
    int matrix_A[2][3]={{1,2,3},{4,5,6}};
    int matrix_B[3][4]={{1,2,3,4},{5,6,7,8},{1,2,3,4}};
    int matrix_C[2][4];
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            matrix_C[i][j]=0;
            for(int p=0;p<3;p++){
                matrix_C[i][j]+=matrix_A[i][p]*matrix_B[p][j];
            }
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            cout<<matrix_C[i][j]<<"\t";
        }
        cout<<endl;
    }


}
