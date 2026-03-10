#include<iostream>
using namespace std;

class Date
{
    private:
    int date;
    int month;
    int year;
    public:

    void initDate()
    {
        date=01;
        month=01;
        year=2000;
        cout<<"\ndate: "<<date<<"/"<<month<<"/"<<year;
    }

    void acceptDateFromConsol()
    {
        cout<<"------------";
        cout<<"Enter Date: "<<endl;
        cin>>date;
        cout<<"Enter Month: "<<endl;
        cin>>month;
        cout<<"Enter Year: "<<endl;
        cin>>year;

    }

    void printDateOnConsole()
    {
        cout<<"DAY IS: "<<date<<"/"<<month<<"/"<<year<<endl;
    
    }

     bool isLeapYear()
     {
        if(year= ((year%4==0) && (year%100!=0)) || (year%400==0))
         {
            cout<<"Year is leap year.";
        }
         else
            cout<<"\nnot a leap year";
        
     }
    
       
    
     
};

int menuList()
{
    int choice;
    cout<<endl<<"----------"<<endl;
    cout<<"1.To display initDate: "<<endl;
    cout<<"2.To acceptData"<<endl;
    cout<<"3.To printData"<<endl;
    cout<<"4.LeapYear."<<endl;
    cout<<"0-To exit"<<endl;
    cin>>choice;
    return choice;
}

int main()
{
    class Date dt;
    int choice; 
    
    while((choice=menuList())!=0)
    {
    switch (choice)
    {
    case 1:
        dt.initDate();
         break;
    case 2:
        dt.acceptDateFromConsol();
          break;
    case 3:
        dt.printDateOnConsole();
          break;
    case 4:
        dt.isLeapYear();
          break;
    }
    }
    
  return 0;
}