//程序清单8.4 函数探幽中的引用
#include <iostream>
//引用很重要，在交换的时候如果按照值来传递就会只交换副本而本身并没有进行传递
void swapr(int & a,int & b);
void swapp(int *p,int *q);
int main(){
    using namespace std;
    int value1=111;
    int value2=222;
    cout<<"value1="<<value1<<endl;
    cout<<"value2="<<value2<<endl;
    cout<<"------"<<endl;

    swapr(value1,value2);

    cout<<"result of change reference"<<value1<<"  "<<value2<<endl;
    cout<<"--------"<<endl;
    swapp(&value1,&value2);
    cout<<"result of change pointer"<<value1<<"  "<<value2<<endl;

}

void swapr(int &a, int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;

}
void swapp(int *p,int *q){
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}

//程序清单8.10 函数重载
#include <iostream>
#include <string>
using namespace std;

//函数重载
unsigned long left(unsigned long num, unsigned ct);
char * left(const char * str, int n=1);

int main(){
    using namespace std;
    char *trip ="hawaii!!";
    unsigned long n=123456789;
    int i;
    char * temp;
    for(i=1;i<10;i++){
        cout<<left(n,i)<<endl;
        temp=left(trip,i);
        cout<<temp<<endl;
        delete [] temp;
    }
    return 0;
}

unsigned long left(unsigned long num, unsigned ct){
    unsigned digits=1;
    unsigned long n =num;
    if(ct==0||num==0)
        return 0;
    while(n/=10){
        digits++;
    }
    if (digits>ct){
        ct=digits-ct;
        while(ct--){
            num/=10;
        }
        return num;
        
    }
    else
        return num;
}
char * left(const char * str, int n){
    if(n<0){
        n=0;
    }
    char * p=new char[n+1];
    int i;
    for(i=0;i<n&&str[i];i++){
        p[i]=str[i];
    }
    while(i<=n){
        p[i++]='\0';
    }
    return p;
    
}
//程序清单8.11函数模版 注意函数声明要大写
#include <iostream>

template <typename T>
void Swap(T &a,T &b);

int main(){
    using namespace std;
    int i=10;
    int j=20;
    cout<<"i,j="<<i<<", "<<j<<endl;
    Swap(i,j);
    cout<<"now i,j="<<i<<", "<<j<<endl;
    
    
    double x=11.111;
    double y=22.222;
    cout<<"-------"<<endl;
    cout<<"x,y="<<x<<", "<<y<<endl;
    Swap(x,y);
    cout<<"now i,j="<<x<<", "<<y<<endl;
    
    
}

template <typename T>
void Swap(T &a,T &b){
    T temp;
    temp=a;
    a=b;
    b=temp;
}
