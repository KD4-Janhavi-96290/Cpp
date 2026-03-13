#include<iostream>
using namespace std;

class Time
{
    private:
    int hrs;
    int mins;
    int secs;

    public:
    Time(void): hrs(0),mins(0),secs(0)
    { }
    Time(int hrs,int mins,int secs): hrs(hrs),mins(mins),secs(secs)
    { }

    void accept(void)
    {
        cout<<"Hrs: "<<endl;
        cin>>hrs;
        cout<<"Mins: "<<endl;
        cin>>mins;
        cout<<"secs: "<<endl;
        cin>>secs;
    }

    void display(void)
    {
        cout<<hrs<<" : "<<mins<<" : "<<secs<<endl;
    }

    void setHrs(int hrs)
    {
        this->hrs=hrs;
    }

    void setMins(int mins)
    {
        this->mins=mins;
    }

    void setSecs(int secs)
    {
        this->secs=secs;
    }

    
    int getHrs(void)
    {
        return this->hrs;
    }

    int getMins(void)
    {
        return this->mins;
    }

    int getsecs(void)
    {
        return this->secs;
    }

    void incSecs(void)
    {
        this->secs++;
        if(this->secs==60)
        {
            this->secs=0;
            this->mins++;
            if(this->mins==60)
            {
                this->mins=0;
                this->hrs++;
                if(this->hrs==24)
                {
                    this->hrs=0;
                }
            }
        }
    }

};

int menuList()
    {
        int choice;
        cout<<"\n0.Exit: "<<endl;
        cout<<"1.Add Time: "<<endl;
        cout<<"2.Display All Time"<<endl;
        cout<<"3. Display only hrs of all time objects"<<endl;
        cin>>choice;
        return choice;
    }

int main()
{
    Time **arr = new Time*[2]; 
    int choice;
    Time t1;

    while((choice = menuList())!=0)
    {
        switch (choice)
        {
        case 1:
             for(int index=0;index<2;index++)
               arr[index]->accept();
        break;
        case 2:
            for(int index=0;index<2;index++)
              arr[index]->display();
            break;
        case 3:
             for(int index=0;index<2;index++)
             cout<<arr[index]->getHrs()<<endl;
           break;
            
        
        default:
           cout<<"Invalid Output";
            break;
        }
    }
    for(int index=0;index<2;index++)
    {
        delete arr[index];
        arr[index]=NULL;
    }
    
   delete [] arr;
   arr=NULL;
   return 0;

}


