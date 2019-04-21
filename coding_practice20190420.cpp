//贼重要的指针小实验
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>

int main(){
    using namespace std;
//    int a=21;
//    int * p=&a;
//    cout<<"*p="<<*p<<endl;
//    cout<<"p="<<p<<endl;
//    cout<<"a="<<a<<endl;
//    cout<<"&a="<<&a<<endl;
//
//
//    *(int *)p=100;
//    cout<<"new *p="<<*p<<endl;
//    cout<<"new p="<< p<<endl;
//    int **b=&p;
//    cout<<"b="<<b<<endl;
//    cout<<"*b="<<*b<<endl;
//    cout<<"**b="<<**b<<endl;
//    cout<<"&p="<<&p<<endl;
//    int c=a+1;
//    cout<<"c="<<c<<endl;
//    int d=*a+1;
//    cout<<"d="<<d<<endl;
//    char ch='a';
//    char *cp=&ch;

    //cout<<"&ch="<<&ch<<endl;//左值非法

//    char *new_ch=&ch+1;
//    cout<<"&ch+1="<<new_ch<<endl;
//    cout<<"ch="<<ch<<endl;
//    cout<<"*cp="<<*cp<<endl;
//    cout<<"cp="<<cp<<endl;

//    char *p="Jerrod";
//    cout<<"p="<<p<<endl;
//    cout<<"*p="<<*p<<endl;
//    printf("&a=%p\n",&ch);
//    printf("&a=%p\n",ch);//阿斯克码的a的地址
//    printf("&a=%p\n",'a');//阿斯克码的a的地址
//    printf("&a=%p\n",cp);
    int a=1;
    int * p=&a;
    int * c=p+1;
    cout<<"*c="<<*c<<endl;
    cout<<"c="<<c<<endl;

    return 0;
}

//c和指针编程练习6.1
#include <stdio.h>
#include <stdlib.h>

char *find_char(char const *source,char const *chars)
{
    int source_len = 0,chars_len = 0;
    int i = 0,j = 0;
    char ch;
    while(*(source+i++)!='\0')//这个操作很重要否则如果while(*(source++)!='\0')source就会变短
        source_len++;
    while(*(chars+j++)!='\0')
        chars_len++;
    for (i=0;i<source_len;i++)
    {
        for (j=0;j<chars_len;j++)
        {
            if (*(chars+j)==*(source+i))
            {
                ch = *(chars+j);
                return &ch;
            }
        }
    }
    return NULL;
}
int main()
{
    const char *source = "china";
    const char *chars = "America";
    char ch;
    ch = *find_char(source,chars);
    printf("%c\n",ch);
    system("pause");
    return 0;
}

