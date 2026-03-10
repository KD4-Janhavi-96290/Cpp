#include <stdio.h>

struct Date{
    int day;
    int month;
    int year;
};


void initDate(struct Date* ptrDate){
    ptrDate->day = 21;
    ptrDate->month = 02;
    ptrDate->year = 2002;
    printf("Date : %02d/%02d/%04d\n",
       ptrDate->day,
       ptrDate->month,
       ptrDate->year);
}

void printDateOnConsole(struct Date* ptrDate){
    printf("Date : %02d/%02d/%04d\n",
           ptrDate->day,
           ptrDate->month,
           ptrDate->year);
}

void acceptDateFromConsole(struct Date* ptrDate){
    printf("Enter Day : ");
    scanf("%d", &ptrDate->day);

    printf("Enter Month : ");
    scanf("%d", &ptrDate->month);

    printf("Enter Year : ");
    scanf("%d", &ptrDate->year);
}

int menuList(){
    int choice; 
    printf("0.Exit.\n"); 
    printf("1.initDate.\n"); 
    printf("2.AcceptRecord.\n");
    printf("3.printRecord.\n");
    printf("Enter the choice : "); 
    scanf("%d",&choice); 
    return choice; 
}

int main(){
    int choice; 
    struct Date dt;
    while((choice = menuList())!=0)
    {
        switch (choice)
        {
        case 1: 
            initDate(&dt); 
            break;
        case 2: 
            acceptDateFromConsole(&dt); 
            break; 
        case 3:
            printDateOnConsole(&dt);
            break;      
        }
    }
    return 0;
}