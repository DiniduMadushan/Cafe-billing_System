/*
    develpoed by: J.H.Shenol kavinda thisera
*/

#include<iostream>  //input and output stream
#include<process.h> //memory management.work with threads and processes
#include<fstream>   //reads data from files and displays it
#include <stdlib.h> //converting strings to different data types and vice versa
#include <string>
#include <conio.h>
using namespace std;

class head
{
    char Item_name[80][80];

public:
    int no_of_items;
    float Quantity[3];
    float price[3];
    float cart_price;
    float aft_dis;
    float total_price[3];
    void input();
    void output();
};
class dis : public head
{
   float discount;
public:
    void discountCal(); 
    void outputs();
    
};


// input function


void head::input()
{
    system("CLS");   // Clears the console screen
    cout<<"\n\n\t\t\t\t\t\t\t---- New Entry ----";
    cout<<"\n\n\t\t\t\t\tPlease Enter number of items in the cart = \t ";
    cin>>no_of_items;

    for(int i=0; i<no_of_items; i++)
    {
        cout<<"\n\n\t\t\t\t\tEnter name of item no "<<i+1<<"\t\t:\t ";
        cin>>Item_name[i];
        cout<<"\t\t\t\t\tEnter quantity \t\t\t:\t ";
        cin>>Quantity[i];
        cout<<"\t\t\t\t\tEnter unit price \t\t:\t ";
        cin>>price[i];
        total_price[i]=Quantity[i]*price[i];
    }
}


//       OUTPUT FUNCTION




void head::output()
{
    int x;

    ifstream infile("BILL_NO.TXT");
    infile>>x;

    ofstream outfile("BILL_NO.TXT");
    x+=1;
    outfile<<x;
    outfile.close();

    {ofstream outfile("HISTORY.TXT", ios::app);
    outfile<<endl<<"\n\t\t\t\t\tBill No : "<<x<<endl;
    outfile<<"\t\t\t\t\t|------------------------------------------------------------------------|"<<endl;
cout<<"\n";
    system("PAUSE");
    system("CLS");
    cout<<"\n\n\t\t\t\t\t\t\t\t----- Bill summary -----\n\n";
    cout<<"\t\t\t\t\tItem name\t\tQuantity\t\tPrice\t\tTotal Price\n\n";
    for(int i=0;i<no_of_items;i++)
    {
        outfile<<"\n\t\t\t\t\tItem Name:  "<<Item_name[i]<<" \t\t| Quantity:  "<<Quantity[i]<<"\t\t| Price:  "<< total_price[i]<<endl;
        cout<<"\n\t\t\t\t\t"<<Item_name[i]<<"\t\t\t"<<Quantity[i]<<"\t\t\t"<<price[i]<<"\t\t\t"<< total_price[i]<<'\n';
    }

    outfile<<"\n\t\t\t\t\t------------------------------------------------------------------------"<<endl;
    outfile.close();
    }
    
}



//       discount calculation


void dis::discountCal()
{
    input();

     cart_price=0;
     aft_dis=0;

    for (int i = 0; i < no_of_items; i++)
    {
        cart_price+=total_price[i];
    }

    if (cart_price>=1000)
    {
        aft_dis=cart_price-(0.02*cart_price);
    }else{
        aft_dis=cart_price;
    }
    

}

//        discounts addition



void dis::outputs()
{
    output();

    float cash = 0, sum = 0, sumt = 0;

    
        sumt +=cart_price;
        sum += aft_dis;
       
    
    
  cout << "\n\t\t\t\t\t---------------------------------------------------------------------------\n";
    cout << "\n\t\t\t\t\t\tTotal cost= " << sumt << "\t\tAfter Discount: " << sum;
    cout << "\n\n\t\t\t\t\t---------------------------------------------------------------------------\n";

    system("PAUSE");
    system("CLS");
    cout << "\n\n\t\t\t\t\t\t<<--------- PAYMENT SUMMARY ------->>\n";
    cout << "\n\n\t\t\t\t\tTotal cost to pay\t\t\t: Rs. " << sum;

pay:
    cout << "\n\n\t\t\t\t\tTotal cash given by the customer\t: Rs. ";
    cin >> cash;

    if (cash >= sum)
        cout << "\n\t\t\t\t\tRemainder\t\t\t\t: Rs. " << cash - sum << '\n';

    else
    {
        cout << "\n\t\t\t\t\tGiven cash is not enough. Please repay!!!\n";

        goto pay;
    }
}


//   User authentication


int authenticateUser()
{
    string username, password;
    cout << "\n\n\n\n\t\t\t\t\t\t-- USER LOGIN --";
    cout << "\n\n\n\t\t\t\t\tEnter your username\t: ";
    cin >> username;

    cout << "\t\t\t\t\tEnter your password\t: ";
    char ch;
    password = "";
    while ((ch = getch()) != 13) // 13 is the ASCII code for the Enter key
    {
        cout << '*'; // Print '*' for each character of the password
        password += ch; // Store the entered character in the password string
    }

    // Check if the entered username and password are correct
    if (username == "shenol" && password == "shenol")
    {
        cout << "\n\n\t\t\t\t\tAuthentication successful!\n\n";
        return 1;
    }
    else
    {
        cout << "\n\t\t\t\t\tAuthentication failed!. Invalid username or password.\n";
        return 0;
    }
}
// END of Authentication


//  Main method of the programme



int main()
{
    dis obj;
    char opt, ch;
    int a=1;
    ifstream fin;

    a=authenticateUser();
    if(!a)
    {
        for(int i=0;i<2;i++)
        {
            cout<<"\n\t\t\t\t\tTry once more..!\n";
            if(authenticateUser())
            {
                goto last;
            }
            else
            {
                cout<<"\n\n\t\t\t\t\tAll attempts failed.....";
                cout<<"\n\n\t\t\t\t\tExiting the system.....";
                cout<<"\n\t\t\t\t\tsee you again later..................\n\n";
                exit(0);
            }

        }
        
             }
    else{
last:;


     do{
start:
    system("PAUSE");
    system("CLS");
    cout<<"\n\n\t\t\t\t\t------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t\t\tCafe77 - Billing Management System";
    cout<<"\n\t\t\t\t\t------------------------------------------------------------";
     cout<<"\n\n\t\t\t\t\tWelcome Shenol, what do you want to do??\n ";
     cout<<"\n\t\t\t\t\t\t1. Enter new entry \n\t\t\t\t\t\t2. View billing History\n\t\t\t\t\t\t3. Quit\n";
     cout<<"\n\n\t\t\t\t\tSelect your option: ";
     cin>>opt;
     switch(opt)
     {
     case'1':
         obj.discountCal();

         obj.outputs();
         goto start;
     case'2':
         system("CLS");
         cout<<"\n\t\t\t\t\t\t\t---------- Billing history ----------\n";
         fin.open("HISTORY.TXT", ios::in);
         while(fin.get(ch))
         {
             cout<<ch;
         }
         fin.close();

         goto start;
     case'3':
         cout<<"\n\t\t\t\t\tExiting the system.good bye...!\n\n";
         exit(0);
     default:
         cout<<"\a";
     }

     }while(opt!=3);
    }
    return 0;
}