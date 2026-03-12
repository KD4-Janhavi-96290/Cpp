#include<iostream>
using namespace std;

class Volume
{
private:
    int length, width, height;

public:

    // Parameterless constructor
    Volume()
    {
        length = 10;
        width = 10;
        height = 10;
    }

    // Single parameter constructor
    Volume(int value)
    {
        length = value;
        width = value;
        height = value;
    }

    // Three parameter constructor
    Volume(int l, int w, int h)
    {
        length = l;
        width = w;
        height = h;
    }

    int calculateVolume()
    {
        return length * width * height;
    }
};

int main()
{
    int choice = 0;

    while(choice != 4)
    {
        cout<<"\n1. Calculate Volume with default values"<<endl;
        cout<<"2. Calculate Volume with same length, breadth and height"<<endl;
        cout<<"3. Calculate Volume with different length, breadth and height"<<endl;
        cout<<"4. Exit"<<endl;

        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                Volume v1;
                cout<<"Volume = "<<v1.calculateVolume()<<endl;
                break;
            }

            case 2:
            {
                int value;
                cout<<"Enter value: ";
                cin>>value;

                Volume v2(value);
                cout<<"Volume = "<<v2.calculateVolume()<<endl;
                break;
            }

            case 3:
            {
                int l,w,h;
                cout<<"Enter length width height: ";
                cin>>l>>w>>h;

                Volume v3(l,w,h);
                cout<<"Volume = "<<v3.calculateVolume()<<endl;
                break;
            }

            case 4:
                cout<<"Exiting program..."<<endl;
                break;

            default:
                cout<<"Invalid choice"<<endl;
        }
    }

    return 0;
}