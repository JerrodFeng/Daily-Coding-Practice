//pratice_4

int main(void) {

    long long enter_seconds;
    int days;
    int hours;
    int minutes;
    int seconds;
    cout<<"enter seconds:";
    cin>>enter_seconds;


    days=enter_seconds/(60*60*24);
    hours=(enter_seconds%(60*60*24))/(60*60);
    minutes=((enter_seconds%(60*60*24))%(60*60))/60;
    seconds=((enter_seconds%(60*60*24))%(60*60))%60;


    cout<<"----"<<enter_seconds<<"is  "<<days<<"days"<<hours<<"hours"<<minutes<<"minutes"<<
    seconds<<"seconds"<<endl;

    days=enter_seconds/(60*60*24);
    hours=(enter_seconds%(60*60*24))/(60*60);
    minutes=((enter_seconds%(60*60*24))%(60*60))/60;
    seconds=((enter_seconds%(60*60*24))%(60*60))%60;





}
//practice 7


void p3_7(void)
{
    double fuel_comsuption_eu = 0.0;
    double fuel_comsuption_us = 0.0;
    
    cout << "Enter the fuel comsuption in Europ standard: ";
    cin >> fuel_comsuption_eu;
    
    fuel_comsuption_us = fuel_comsuption_eu / 19 * 12.41;
    cout << "the fuel comsuption in US standard is " << fuel_comsuption_us << "/100KM" << endl;
}


int main(int argc, char **argv)
{
    p3_7();
    
    
    return 0;
}
