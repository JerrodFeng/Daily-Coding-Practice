//程序清单4.9
#include <iostream>
#include <string>
#include <array>

unsigned int c_in_str(const char * str, char ch);

int main(){
    using namespace std;
    char mmm[20]="jnsabvjdskamcsiamj";
    char *nnn="ueiancdsaklsahfiaundksa";
    unsigned int a=c_in_str(mmm,'m');
    unsigned int b=c_in_str(nnn,'a');
    cout<<a<<"------"<<"\n";
    cout<<b<<endl;

    return 0;

}

unsigned int c_in_str(const char * str, char ch){
    unsigned int count=0;
    while(* str){
        if(*str==ch){
            count++;
        }
        *str++;
    }
    return count;
}


////程序实例7.10有问题
#include <iostream>
#include <string>
#include <array>

char * buildstr(char c, int n);

int main(){
    using namespace std;
    int times;
    char ch;
    cout<<"enter a character :";
    cin>>ch;
    cout<<"enter an integer";
    cin>>times;
    char *ps=buildstr(ch,times);
    cout<<ps<<endl;
    delete [] ps;
    
    *ps=*buildstr('+',40);
    cout<<ps<<endl;
    delete [] ps;
    //    ps=buildstr('+',40);
    //    cout<<ps<<endl;
    //    delete [] ps;
    
    
    
    return 0;
    
}

char * buildstr(char c, int n){
    char *pstr=new char[n+1];
    pstr[n]='\0';
    while(n-->0){
        pstr[n]=c;
    }
    return pstr;
    
}

//程序清单 7.13 有问题
#include <iostream>
#include <string>
#include <cmath>

struct polar{
    double distance;
    double angle;
};
struct rect{
    double x;
    double y;
};

void rect_to_polar(const rect * pxy, polar * pda );
void show_polar(const polar * pda);

int main(){
    using namespace std;
    //    polar *pplace=new polar;
    //    rect *rplace= new rect;
    polar pplace;
    rect rplace;
    cout<<"enter x and y values:";
    while(cin>>rplace.x>>rplace.y){
        rect_to_polar(&rplace, &pplace);
        show_polar(&pplace);
        cout<<"next two numbers (q to quit):";
    }
    return 0;
}

void show_polar(const polar * pda){
    using namespace std;
    const double reg_to_deg=57.29;
    cout<<"distance="<<pda->distance;
    cout<<", angle="<<pda->angle*reg_to_deg<<endl;
}
void rect_to_polar(const rect * pxy, polar * pda){
    using namespace std;
    pda->distance=sqrt(pxy->x*pxy->x+pxy->y*pxy->y);
    pda->angle=atan2(pxy->y,pxy->x);
}

//程序清单7.19函数指针
#include <iostream>
#include <string>
#include <cmath>

const double * f1(const double ar[], int n);
const double * f2(const double [], int n);
const double * f3(const double *, int n);

int main(){
    using namespace std;
    double av[3]={1133.1,2232.4,4322.9};
    
    const double *(*p1)(const double *,int)=f1;
    auto p2=f2;
    cout<<"using pointers to functions:\n";
    cout<<"address value:\n";
    cout<<(*p1)(av,3)<<":"<<*(*p1)(av,3)<<endl;
    cout<<p2(av,3)<<":"<<*p2(av,3)<<endl;
    
    const double *(*pa[3])(const double *,int)={f1,f2,f3};
    
    auto pb=pa;
    
    cout<<"\nusing an array of pointers to functions\n";
    cout<<"address value\n";
    for(int i=0;i<3;i++){
        cout<<pa[i](av,3)<<":"<<*pa[i](av,3)<<endl;
    }
    cout<<"\nusing a pointer to a pointer to a function:\n";
    cout<<"address value\n";
    for(int i=0;i<3;i++)
        cout<<pb[i](av,3)<<":"<<*pb[i](av,3)<<endl;
    cout<<"\nusing pointers to an array of pointers:\n";
    cout<<"address value\n";
    auto pc=&pa;
    cout<<(*pc)[0](av,3)<<":"<<*(*pc)[0](av,3)<<endl;
    const double *(*(*pd)[3])(const double *,int)=&pa;
    const double *pdb=(*pd)[1](av,3);
    cout<<pdb<<":"<<*pdb<<endl;
    cout<<(*(*pd)[2])(av,3)<<":"<<*(*(*pd)[2])(av,3)<<endl;
    return 0;
    
    
}

const double * f1(const double * ar, int n){
    return ar;
}
const double * f2(const double ar[], int n){
    return ar+1;
    
}
const double * f3(const double ar[], int n){
    return ar+2;
}




//编程练习10 函数指针没太明白
#include <iostream>
#include <string>
#include <cmath>

double calculate(double x, double y,double (*fun)(double, double));
double *add(double x,double y);
double *mul(double x,double y);

int main(){
    using namespace std;
    double *(*pfun[2])(double x,double y)={add,mul};
    double x;
    double y;
    double a=calculate(x,y,(*add)(x,y));
    cin>>x>>y;
    cout<<"add is :"<<calculate(x,y,*pfun[0](x,y))<<endl;
 
    
}


double add(double x,double y){
    return (x+y);
}
double mul(double x, double y){
    return x * y;
}
double calculate(double x, double y,double (*fun)(double x, double y)){
    return fun(x,y);
}
