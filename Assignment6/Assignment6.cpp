// Q1. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
// holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
// Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program
// should be menu driven and should not cause memory leakage.
// Hint - Create class Product and inherit into Book and Tape. Also create array like Product* arr[3]

#include<iostream>
using namespace std;

class Product
{
    protected:
    double price;
    private:
    int id;
    string title;
   

    public:
    Product(void)
    { }
    Product(int id,string title,double price):id(0),title(""),price(0.0)
    { }

    virtual void acceptRecord()
    {
        cout<<"Enter ID: "<<endl;
        cin>>id;
        cout<<"Enter Title: "<<endl;
        cin>>title;
        cout<<"Enter Price: "<<endl;
        cin>>price;
    }
    virtual void printRecord()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
    }
    virtual double calculateDiscount()=0;

};

class Book :public Product
{
    private: 
    string author;

    public:
    Book(void)
    { }
    Book(string author):author("")
    { }
    

    void acceptRecord()
    {
        Product::acceptRecord();
        cout<<"Enter Author: "<<endl;
        cin>>author;
    }

    void printRecord()
    {
        Product::printRecord();
        cout<<"Author: "<<author<<endl;
    }

    double calculateDiscount()
    {
        
        return price *0.90; // (100% - 5% = 95%)

    }


};

class Tape : public Product
{
    private: 
    string artist;

    public:
    Tape(void)
    { }
    Tape(string artist):artist("")
    { }
    

    void acceptRecord()
    {
        Product::acceptRecord();
        cout<<"Enter Artist: "<<endl;
        cin>>artist;
    }

    double calculateDiscount()
    {

        return price*0.10;
    }

    
     

};

int menuList()
{
    int choice;
    cout<<"0.Exit"<<endl;
    cout<<"1.Book"<<endl;
    cout<<"2.Tape"<<endl;
    cin>>choice;
    return choice;
}

int main()
{
    int choice;
    int count=0;
    Product* arr[3];
    while ((choice = menuList()) != 0)
    {
        switch (choice)
        {
        case 1:
            if (count < 3)
            {
                arr[count] = new Book();
                arr[count]->acceptRecord();
                count++;
            }
            else
                cout << "Only 3 products allowed!\n";
            break;

        case 2:
            if (count < 3)
            {
                arr[count] = new Tape();
                arr[count]->acceptRecord();
                count++;
            }
            else
                cout << "Only 3 products allowed!\n";
            break;

        case 3:
        {
            double total = 0;
            for (int i = 0; i < count; i++)
            {
                arr[i]->printRecord();
                double finalPrice = arr[i]->calculateDiscount();
                cout << "Price after discount: " << finalPrice << endl;
                total += finalPrice;
                
            }
            cout << "Total Bill = " << total << endl;
            break;
        }

        default:
            cout << "Invalid choice!\n";
        }
    }
    for (int i=0;i<count;i++)
    {
        delete arr[i];
    }
    return 0;
}