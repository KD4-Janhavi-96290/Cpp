// Q1. Create a class Date with data memebrs day,month and year.
// Cretae a class Person with data members name,address and birthdate. The birthdate should be of
// type Date.
// Create a class Student with data members id, marks, course and joining date, end date. The joining
// date and end date should be of type date.
// Implement above classes. Test all functionalities in main().
// (Note - Only Perform the Association in the above case. No need of Inheritance)

#include<iostream>
using namespace std;

class Date
{
    private:
    int day;
    int month;
    int year;
    public:
    Date(void):day(0),month(0),year(0)
    { }

    Date(int day,int month,int year): day(day),month(month),year(year)
    {
    }
    
    void acceptDate(void)
    {
        cout<<"Day: ";
        cin>>day;
        cout<<"Month: ";
        cin>>month;
        cout<<"Year: ";
        cin>>year;
    }
    void displayDate(void)
    {
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    }
    
};

class Person
{
    private:
    string name;
    string address;
    Date dob;
    public:
    Person(void):name(""),address("")
    { }
    Person(string name,string address):name(name),address(address)
    { }
    Person(string name,string address,Date(dob)):name(name),address(address),dob(dob)
    { }
    Person(string name,string address,int day,int month,int year):name(name),address(address),dob(day,month,year)
    { }
    void acceptRecord()
    {
        cout<<"Name: "<<endl;
        cin>>name;
        cout<<"Address: "<<endl;
        cin>>address;
        cout<<"Enter Date of Birth: "<<endl;
        this->dob.acceptDate();
    }
    void displayRecord()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Adress: "<<address<<endl;
        cout<<"Birthdate: "<<endl;
        this->dob.displayDate();
    }
};

class Student
{
    private:
    int id;
    int marks;
    public:
    string course;
    Date joiningDate;
    Date endDate;
    Student(void):id(0),marks(0)
    {};
    Student(int id,int marks,string course,int jd,int jm,int jy,int ed,int em,int ey):id(id),marks(marks),course(course),joiningDate(jd,jm,jy),endDate(ed,em,ey)
    {}

    void acceptStudent(void)
    {
        cout<<"Enter Student ID: "<<endl;
        cin>>id;
        cout<<"Enter Student Marks: "<<endl;
        cin>>marks;
        cout<<"Enter Course: "<<endl;
        cin>>course;
        cout<<"Enter JoinDate: "<<endl;
        this->joiningDate.acceptDate();
        cout<<"Enter EndDate: "<<endl;
        this->endDate.acceptDate();
    }

    void displayStudent()
    {
        cout<<"Student ID: "<<id<<endl;
        cout<<"Student Marks: "<<marks<<endl;
        cout<<"Student Course: "<<course<<endl;
        cout<<"Joining Date: "<<endl;
        this->joiningDate.displayDate();
        cout<<"End Date: "<<endl;
        this->endDate.displayDate();
 }

};

int main()
{
    Student s;
    s.acceptStudent();
    s.displayStudent();
    return 0;
}

int main1()
{
    Person p;
    p.acceptRecord();
    p.displayRecord();
    return 0;
}