#include<iostream>
#include<typeinfo>
using namespace std;

class Employee
{
    private:
    int id;
    double salary;

    public:
    Employee():id(0),salary(0.0)
    { }
    Employee(int id,double salary):id(id),salary(salary)
    {  }

    void setId(int id)
    {
        this->id=id;
    }

    int getId(void)
    {
        return this->id;
    }

    void setSalary(double salary)
    {
        this->salary=salary;
    }

    double getSalary(void)
    {
        return this->salary;
    }

    virtual void accept()
    {
        cout<<"Enter ID: "<<endl;
        cin>>id;
        cout<<"Enter Salary: "<<endl;
        cin>>salary;
    }

    virtual void display()
    {
        cout<<"ID IS: "<<id<<endl;
        cout<<"Salary is: "<<salary<<endl;
    }


};

class Manager : virtual  public Employee
{
    private:
    double bonus;

    public:
    Manager(void):bonus(0.0)
    {
    }

    Manager(int id,double salary,double bonus):Employee( id,salary),bonus(bonus)
    { 
       
    }

    void setBonus(double bonus)
    {
        this->bonus=bonus;
    }

    double getBonus(void)
    {
        return this->bonus;
    }

    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }

    protected:
    void acceptManager()
    {
        
        cout<<"Enter Bonus: "<<endl;
        cin>>this->bonus;
    }

    void displayManager()
    {
        
        cout<<"Bonus is"<<this->bonus;
    }


};

class Salesman: virtual  public Employee
{
    private:
    double commision;

    public:
    Salesman():commision(0.0)
    { }

    Salesman(int id,double salary,double commision):Employee(id,salary),commision(commision)
    { }

    void setCommision(double commision)
    {
        this->commision=commision;
    }

    double getCommision(void)
    {
        return this->commision;
    }

    void accept()
    {
        Employee::accept();
        acceptSalesMan();
    }

    void display()
    {
        Employee::display();
        displaySalesman();
    }
    
    protected:
    void acceptSalesMan()
    {
        
        cout<<"Enter Commision: ";
        cin>>commision;

    }

    void displaySalesman()
    {
       
       cout<<"Commision: "<<commision<<endl;
    }
    

};

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager() { }

    SalesManager(int id, double salary, double bonus, double commision)
        : Employee(id, salary), Manager(id, salary, bonus), Salesman(id, salary, commision)
    { }

    void accept()
    {
        Employee::accept();
        Manager::acceptManager();
        Salesman::acceptSalesMan();

    }

    void display()
    {
       Employee::display();
        Manager::displayManager();
        Salesman::displaySalesman();
    }
};

int menuList()
{
    int choice;
    cout<<"0.Exit: "<<endl;
    cout<<"1.Add Manager"<<endl;
    cout<<"2.Add Salesman"<<endl;
    cout<<"3.Add Salesmanager"<<endl;
    cout<<"4.Display the count of all employees with respect to designation"<<endl;
    cout<<"5.Display All Manager"<<endl;
    cout<<"6.Display All Salesman"<<endl;
    cout<<"7. Display All SalesManagers"<<endl;
    cout<<"Enter choice: ";
    cin>>choice;
    return choice;
}


int main()
{
    Employee* arr[5];
    int choice;
    int count=0;
    int m=0;
    int s=0;
    int sm=0;
    while((choice=menuList())!=0)
    {
        switch (choice)
        {
        case 1:
            arr[count]=new Manager;
            arr[count]->accept();
            count++;
            m++;
            break;
        case 2:
           arr[count]=new Salesman;
            arr[count]->accept();
            count++;
            s++;
            break;
        case 3:
            arr[count]=new SalesManager;
            arr[count]->accept();
            count++;
            sm++;
            break;
        case 4:
                cout<<"Number of Manager count is: "<<m<<endl;
                cout<<"Number of SalesMan count is: "<<s<<endl;
                cout<<"Number of SalesManager count is"<<sm<<endl;
                break;
        case 5:
             for(int i=0;i<count;i++)
             {
                if(typeid (*arr[i])==typeid(Manager))
                  arr[i]->display();
             }
        case 6:
             for(int i=0;i<count;i++)
             {
                if(typeid (*arr[i])==typeid(Salesman))
                  arr[i]->display();
             }
        case 7:
             for(int i=0;i<count;i++)
             {
                if(typeid (*arr[i])==typeid(SalesManager))
                  arr[i]->display();
             }
       
        }
    }
    for(int i=0;i<count;i++)
    {
        delete[] arr[i];
        arr[i]=NULL;
    }

    return 0;
}