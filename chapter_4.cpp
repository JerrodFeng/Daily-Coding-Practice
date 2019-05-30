//practice 4

#include <iostream>
#include <string>
#include <array>
using namespace std;



int main(int argc, char **argv)
{
    string first_name;
    string last_name;
    
    cout << "Enter your first name: ";
    //  cin.getline()  // cin.getline不适用于string类
    getline(cin,first_name);
    cout << "Enter your last name: ";
    getline(cin,last_name);
    cout << "Here's your information is a single string: " << last_name << ", " << first_name << endl;

    
    return 0;
}
//practice 5
#include <iostream>
#include <string>
#include <array>
using namespace std;

struct CandyBar{
    string name;
    double weight;
    int calories;
};



int main()
{
    CandyBar snake;
    snake.name="Mocha Munch";
    snake.weight=2.3;
    snake.calories=350;
    cout<<snake.name<<endl;
    
}
//practice 6
#include <iostream>
#include <string>
#include <array>
using namespace std;

struct CandyBar{
    string name;
    double weight;
    int calories;
};



int main()
{
    CandyBar snake [3]={
        {"Mocha Munch", 2.3, 350},
        {"Banana", 3.5, 400},
        {"HAHAHAHA", 3.0, 370}
    };
    for(int i=0;i<3;i++){
        cout<<snake[i].name<<"   "<<snake[i].weight<<"    "<<snake[i].calories<<"==="<<endl;
    }
    
    
}

//practice 8
#include <iostream>
#include <string>
#include <array>
using namespace std;

struct CandyBar{
    string name;
    double weight;
    int calories;
};

int main(){
    CandyBar *snake=new CandyBar;
    cout<<"enter name:"<<endl;
    cin>>snake->name;
    cout<<"enter weight"<<endl;
    cin>>snake->weight;
    cout<<"enter calories"<<endl;
    cin>>snake->calories;
    
    
    cout<<snake->name<<"  "<<snake->weight<<"  "<<snake->calories<<endl;
    delete snake;
    
    
    
    //    CandyBar snake [3]={
    //            {"Mocha Munch", 2.3, 350},
    //            {"Banana", 3.5, 400},
    //            {"HAHAHAHA", 3.0, 370}
    //    };
    //    for(int i=0;i<3;i++){
    //        cout<<snake[i].name<<"   "<<snake[i].weight<<"    "<<snake[i].calories<<"==="<<endl;
    //    }
    
    
}




