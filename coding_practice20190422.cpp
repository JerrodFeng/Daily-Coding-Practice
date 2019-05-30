//八皇后问题

#include <iostream>
#include <stdio.h>
using namespace std;
int num_solution=0;
int board[8][8];
void print_board(){
    int col;
    int row;


    num_solution+=1;
    cout<<"the solution"<<num_solution<<"is"<<endl;
    for( row=0;row<8;row++){
        for( col=0;col<8;col++){
            if(board[row][col]){
                cout<<"q";
            }
            else
                cout<<"+";
        }
        cout<<endl;
    }
    cout<<endl;


    return;

}

bool check(int row,int col){
    int i;
    for(i=1;i<8;i++){
        if(board[row-i][col]==1&&row-i>=0){
            return false;
        }
        if(board[row][col-i]==1&&col-i>=0){
            return false;
        }
        if(board[row][col+i]==1&&col+i<8){
            return false;
        }
        if(board[row-i][col-i]==1&&col-i>=0&&row-i>=0){
            return false;
        }
        if(board[row-i][col+i]==1&&row-i>=0&&col+i<8){
            return false;
        }
    }
    return true;
}

void find_Queen(int row){
    int col;
    for(col=0;col<8;col++){
        board[row][col]=1;
        if(row == 0 || check(row,col))
            if(row < 7)
                find_Queen(row + 1);
            else
                print_board();
        board[row][col] = 0;
    }
}
int main(){
    find_Queen(0);

    return 0;
}