/*
    develpoed by: J.H.Shenol kavinda thisera
*/

#include<iostream>  //input and output stream
#include<process.h> //memory management.work with threads and processes
#include<fstream>   //reads data from files and displays it
#include <stdlib.h> //converting strings to different data types and vice versa
#include <string>
using namespace std;

class head
{
    char Item_name[80][80];

public:
    int no_of_items;
    float Quantity[3];
    float price[3];
    int added_vat[3];
    int total_price[3];
    void input();
    void output();
};
class vat:public head
{
    float vats;
public:
    void vatcal();
    void outputs();
    void sum();
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



//       VAT CALCULATION


void vat::vatcal()
{
    input();
    for(int i=0;i<no_of_items;i++)
    {
        if(price[i]<=100.00)
        {
            added_vat[i]= total_price[i]+(0.03* total_price[i]);
        }
        else
        {
            added_vat[i]= total_price[i]+(0.1* total_price[i]);
        }
    }
}

//        VAT OUTPUTS


void vat::outputs()
{
    output();

    float cash=0,sum=0,qty=0,sumt=0;

    for(int i=0;i<no_of_items;i++)
    {
           sumt+= total_price[i];
           sum+=added_vat[i];
           qty+=Quantity[i];
    }
    
    cout<<"\n\t\t\t\t\t---------------------------------------------------------------------------\n";
    cout<<"\n\t\t\t\t\t\tTotal cost= "<<sumt<<"\t\tInclusive of VAT: "<<sum;
    cout<<"\n\n\t\t\t\t\t---------------------------------------------------------------------------\n";


    system("PAUSE");
    system("CLS");
    cout<<"\n\n\t\t\t\t\t\t<<--------- PAYMENT SUMMARY ------->>\n";
    cout<<"\n\n\t\t\t\t\tTotal cost to pay\t\t\t: Rs. "<<sum;

pay:
    cout<<"\n\n\t\t\t\t\tTotal cash given by the customer\t: Rs. ";
    cin>>cash;

    if(cash>=sum)
        cout<<"\n\t\t\t\t\tRemainder\t\t\t\t: Rs. "<<cash-sum<<'\n';
        
    else
    {    cout<<"\n\t\t\t\t\tGiven cash is not enough.please repay!!!\n";

    goto pay;
    }
}



//   User authentication


int authenticateUser()
{
    std::string username, password;
    cout<<"\n\n\n\n\t\t\t\t\t\t-- USER LOGIN --";
    std::cout << "\n\n\n\t\t\t\t\tEnter your username\t: ";
    std::cin >> username;

    std::cout << "\t\t\t\t\tEnter your password\t: ";
    std::cin >> password;

    // Check if the entered username and password are correct
    if (username == "shenol" && password == "shenol")
    {
        std::cout << "\n\n\t\t\t\t\tAuthentication successful!\n\n";
        return 1;
    }
    else
    {
        std::cout << "\n\t\t\t\t\tAuthentication failed!. Invalid username or password.\n";
        return 0;
    }
}
// END of Authentication


//  Main method of the programme



int main()
{
    vat obj;
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
         obj.vatcal();

         obj.outputs();
         goto start;
     case'2':
         system("CLS");
         cout<<"\n\t\t\t\t\t\t\t---------- Billing history ----------";
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