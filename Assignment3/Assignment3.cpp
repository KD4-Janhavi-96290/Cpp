// Q1. Write a class to find volume of a Cylinder by using following members. (volume of
// Cylinder=3.14 * radius * radius *height) ( use static wherever needed. hint-PI)
// Class having following member functions:
// Cylinder()
// Cylinder(double radius, double height)
// getRadius()
// setRadius()
// getHeight()
// setHeight()
// calculateVolume()
// Initialize members using constructor member initializer list.

#include<iostream>
using namespace std;

class Cylinder
{
    private:
    double radius;
    double height;
    double volume;
    static  double pi;

    public:
    Cylinder()
    {

        volume=0;
        radius=0;
        height=0;
    }

    Cylinder(double radius,double height)
    {
        this->radius=radius;
        this->height=height;
        this->volume=volume;
    }

    void setRadius(double radius)
    {
        this->radius=radius;
    }

    double getRadius(void)
    {
       return  radius;
    }

    double getHeight(void)
    {
       return  height;
    }

    void setHeight(double height)
    {
        this->height=height;
    }

    double calculateVolume()
    {
    
      volume=pi * radius * radius *height;
      return volume;
    }

    void printRecord()
    {
        cout<<"Volume of Cylinder: "<<volume<<endl;
    }




};

double Cylinder::pi=3.14;

int main()
{
    Cylinder c1;
    
   
    c1.setHeight(3);
    c1.getHeight();
    c1.setRadius(2);
    c1.getRadius();
    c1.calculateVolume();
    c1.printRecord();
    return 0;
}
