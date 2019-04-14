#include <stdio.h>
#include <stdlib.h>
/*从标准输入复制到标准输出并且标出行号c和指针编程练习1.2*/
int main(){
    int ch;
    int line;
    bool at_beg;

    line=0;
    at_beg=true;
    while((ch=getchar())!=EOF){
        if(at_beg== true){
            line+=1;
            at_beg= false;
            printf("%d",line);
        }
        putchar(ch);
        if(ch=='\n'){
            at_beg= true;
        }
        if(ch=='a'){
            break;
        }

    }

    return EXIT_SUCCESS;
}

/*c和指针第一章经典例子*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 20
#define MAX_INPUT 1000

int read_col_num(int columns[], int max);
void rearrange(char *output, char const *input, int n_column, int const columns[]);
int main(void){
    int n_columns;
    int columns[MAX_COLS];
    char output[MAX_INPUT];
    char input[MAX_INPUT];
    
    n_columns=read_col_num(columns,MAX_COLS);
    
    while(gets(input)!=NULL){
        printf("original input is:%s\n",input);
        rearrange(output,input,n_columns,columns);
        printf("rearrangeline: %s\n",output);
        
    }
    return EXIT_SUCCESS;
}

int read_col_num(int columns[], int max){
    int num=0;
    int ch;
    
    while(num<max&&scanf("%d",&columns[num])==1&&columns[num]>0){
        ++num;
    }
    printf("num is:%d\n",num);
    if(num%2!=0){
        printf("这个不行得是偶数");
        exit (EXIT_FAILURE);
    }
    
    while((ch=getchar())!=EOF&&ch!='\n'){
        ;
    }
    return num;
}

void rearrange(char *output, char const *input, int n_column, int const columns[]){
    int col;
    int output_col;
    int len;
    
    len=strlen(input);
    output_col=0;
    for(col=0;col<n_column;col+=2){
        int nchar=columns[col+1]-columns[col]+1;
        
        if(columns[col]>len||output_col>MAX_INPUT-1){
            break;
        }
        if(output_col+nchar>MAX_INPUT){
            nchar=MAX_INPUT-output_col-1;
        }
        strncpy(output+output_col,input+columns[col],nchar);
        output_col+=nchar;
    }
    output[output_col]='\0';
}


/*归并排序   reference:  https://www.cnblogs.com/rio2607/p/4489893.html*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
void merge(int *data,int start,int end,int *result);
void merge_sort(int *data, int start, int end, int *result);

void merge(int *data,int start,int end,int *result){
    int leftlength=(end-start)/2+1;
    int rightlength=end-leftlength+1;
    int left_index=start;
    int right_index=start+leftlength;
    int index=start;
    while(left_index<start+leftlength&&right_index<end+1){
        if(data[left_index]<=data[right_index])
            result[index++]=data[left_index++];
        else
            result[index++]=data[right_index++];
    }
    while(left_index < start + leftlength)
        result[index++] = data[left_index++];
    while(right_index < end+1)
        result[index++] = data[right_index++];
}

void merge_sort(int *data, int start, int end, int *result){
    if(end-start==1){
        if(data[start] > data[end])
        {
            int temp  = data[start];
            data[start] = data[end];
            data[end] = temp;
        }
        else
            ;
        return;
    }
    else if(start==end){
        return;
    }
    else{
        merge_sort(data,start,(end-start)/2+start,result);
        merge_sort(data,(end-start)/2+start+1,end,result);
        merge(data,start,end,result);
        for(int i = start;i <= end;++i)
            data[i] = result[i];
    }
    
}

int main(){
    using namespace std;
    int data[] = {9,6,7,22,20,33,16,20};
    const int length = 8;
    int result[length];
    cout << "Before sorted:" << endl;
    for(int i = 0;i < length;++i)
        cout << data[i] << endl;
    cout << "After sorted:" << endl;
    merge_sort(data,0,length-1,result);
    for(int i = 0;i < length;++i)
        cout << data[i] <<endl;
    
    return 0;
}
