#include <iostream>
using namespace std;

int main() {
    int ilong=0;
    cin>>ilong;
    cout<<ilong*220<<endl;



}
//practice 1
void p2_1(){
    cout<<"Jerrod_F"<<endl;
    cout<<"hong kong University of science and technology"<<endl;
    return;

}

//practice 2

void p2_2(){
    int ilong=0;
    cin>>ilong;
    cout<<ilong*220<<endl;
    return;
}

//pratice 3
void print_1(){
    cout<<"three blind mice"<<endl;
    return;
}

void print_2(){
    cout<<"see how they run"<<endl;
    return;
}

int main(void) {
    print_1();
    print_1();
    print_2();
    print_2();
    //cout<<"hello world"<<endl;
    return 0;
    
}

//pratice 7
#include <iostream>
using namespace std;
char time_test(int hours,int minutes){
    cout<<"time:"<<hours<<":"<<minutes<<endl;
    return 0;
}

int main(void) {
    int hours;
    int minutes;
    cout<<"enter hours"<<endl;
    cin>>hours;
    cout<<"enter minutes"<<endl;
    cin>>minutes;
    time_test(hours,minutes);
    
    
    
    return 0;
    
}


