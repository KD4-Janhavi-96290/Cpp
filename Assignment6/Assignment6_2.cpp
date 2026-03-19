#include<iostream>
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

    void acceptRecord()
    {
        cout<<"Enter ID: "<<endl;
        cin>>id;
        cout<<"Enter Salary: "<<endl;
        cin>>salary;
    }

    void displayRecord()
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

    void acceptManager()
    {
        Employee::acceptRecord();
        cout<<"Enter Bonus: "<<endl;
        cin>>this->bonus;
    }

    void displayManager()
    {
        Employee::displayRecord();
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

    

    void acceptSalesMan()
    {
        Employee::acceptRecord();
        cout<<"Enter Commision: ";
        cin>>commision;

    }

    void displaySalesman()
    {
       Employee::displayRecord();
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
        Employee::acceptRecord();

        double b, c;
        cout << "Enter Bonus: ";
        cin >> b;
        setBonus(b);

        cout << "Enter Commission: ";
        cin >> c;
        setCommision(c);
    }

    void display()
    {
        Employee::displayRecord();
        cout << "Bonus: " << getBonus() << endl;
        cout << "Commission: " << getCommision() << endl;
    }
};

int main()
{
    SalesManager s1;
    s1.accept();
    s1.display();

    return 0;
}