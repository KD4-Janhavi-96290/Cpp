#include<iostream>
using namespace std;

class tollBooth
{
    private:
    unsigned int totalCar;
    unsigned int payCar;
    unsigned int nopay_Car;
    double totalCash;


    public:
    tollBooth()
    {
        totalCar=0;
        payCar=0;
        nopay_Car=0;
        totalCash=0;

    }

    void payingCar()
    {
        totalCar++;
        payCar++;
        totalCash +=0.50;


    }

    void nopayCar()
    {
        totalCar++;
        nopay_Car++;
    }

    void printRecord()
    {
        cout<<"Total Number of  cars: "<<totalCar<<endl;
        cout<<"Total number of paying cars: "<<payCar<<endl;
        cout<<"Total Cash Paid by Cars: "<<nopay_Car<<endl;
        cout<<"Total Number of  Cash: "<<totalCash<<endl;
        
        
    }
};

int main()

{ 
    tollBooth t1;
    t1.payingCar();
    t1.payingCar();
    t1.nopayCar();
    t1.payingCar();
    t1.printRecord();
    

    return 0;
}