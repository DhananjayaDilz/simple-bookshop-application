#include <iostream>
#include <list>
#include <cctype>
#include <algorithm>
#include <vector>
 
using namespace std;

string customerUsername="MISKA";
int customerPassword=1234;
vector <string> bookNameList; //create a vector to store book name
vector <string> bookIDList; //create a vector to store book ID
vector <double> bookPriceList; //create a vector to store book prices
vector <int> bookOrderIDList; //create a vector to ID of ordered books
vector <string> orderedBookNameList;//create a vector to ordered book name
vector <int> orderedBookCountList; //create a vector to ordered book count
vector <int> orderTotalList;  //create a vector to store total price of each orders
vector <string> bookQuotaList; // vector to store book quotations


bool exitProgramme =false;
double discount=0;
int discountBookAmount=3;




// ****************************************************Manager actions***********************************************

// print the menu options for the bookshop manager 
void printManagerMenu(){
    cout << endl;
    cout << "\t| Manager menu |"<< endl<< endl;
    cout <<"Press [1] to View books" <<endl;
    cout <<"Press [2] to Add books" <<endl;
    cout <<"Press [3] to Search books" <<endl;
    cout <<"Press [4] to View book orders" <<endl;
    cout <<"Press [5] to Add discounts" <<endl ;
    cout <<"Press [6] to Exit from the menu" <<endl << endl;
    cout << "Enter your choice here: ";  

    
}



void addBook(){

    bool addAnotherBook=false;
    do{
        //declare three variables to store the book name ,bookID, book price temporary
        string bookName;
        string bookID;
        double bookPrice;

        cout << endl << "Enter the name of the book: ";
        getline(cin >>  ws  ,bookName); // get the more than one word (line of characters) and assign it to the book name variable
        bookNameList.push_back(bookName); // add the book name enterd by the user to the book name vector

        cout << "Enter the book ID: ";
        cin >> bookID;
        bookIDList.push_back(bookID); // add the book ID taken by the user to the book ID vector

        cout << "Enter the price of the book: ";
        cin >> bookPrice;
        bookPriceList.push_back(bookPrice); // add the price of the book to the book price vector

        cout << endl << "book "<< bookName <<" successfully added to the system" << endl;

        char goAgain;
        cout << endl << "press [Y] for Yes and [N] for No" << endl;// asking whether the user want to add another book or not
        cout << "Do you want to add another book? :";
        cin >> goAgain;
        cout << endl;
        if (toupper(goAgain)=='Y')
        {
            addAnotherBook=true;
        }else{
            addAnotherBook=false;
        }   
    } 
    while (addAnotherBook);
   
}


void viewBook(){


    if (bookNameList.size()>0) // check whether the book name list is empty or not
    {
        cout <<endl;
        cout <<"\t\t*********************" << endl;
        cout <<"\t\t|  Nethra Book shop |" << endl;
        cout <<"\t\t*********************" << endl<< endl;
        cout << "book Name\t\tBook ID\t\t\tPrice" << endl<< endl;

        for (int i = 0; i < bookNameList.size(); i++)
        {
            cout << bookNameList[i] << "\t\t\t" << bookIDList[i] << "\t\t\t" <<bookPriceList[i] <<"$"<<endl;
        }
        
        

    }else
    {
        cout << " OOPS! no books to view "<<endl;
    }
    

}

void searchBook(){
    bool isBookFound=false;
    string bookToFind;
    cout<< "Enter the book name you want to search: ";
    cin >> bookToFind;
    // iterate through the bookname vector to find whether the user enterd book name is included or not 
    for (int i = 0; i < bookIDList.size(); i++) 
    {
        if (bookNameList[i] == bookToFind) 
        {
            isBookFound =true;
            cout << endl <<"Book "<<bookToFind <<" is found"<< endl<<endl;
            cout <<"***************************************"<< endl;
            cout << "Book id is "<< bookIDList[i] <<endl;
            cout << "Book name is "<< bookNameList[i]<< endl;
            cout << "Book price is "<< bookPriceList[i]<< "$"<< endl;
            cout <<"***************************************"<<endl;
        }
        
        
    }
    if (! isBookFound)
    {
        cout << endl<<"OOPS! The book you entered is not found in the system"<<endl<< "please try again another book"<<endl;
    }    

}

void viewOrders(){
    if (bookOrderIDList.size()>0)   // Check whether there are at leat one order by checking book order list size
    {
        cout << "Order ID\t\t\t"<< "ordered book count\t\t"<< "total price"<<endl;

        for (int i = 0; i < orderedBookNameList.size(); i++)
        {
            cout << bookOrderIDList[i]<<"\t\t\t"<<orderedBookCountList[i]<<"\t\t"<<orderTotalList[i]<<endl;
        }
    }else
    {
        cout<< endl<<"Thre are no book orders yet "<<endl;
    }
    
    
}

void addDiscount(){
    cout <<endl<<"Enter the minimum amount of books customer need to buy to eligible for the discount: ";
    cin >> discountBookAmount;
    cout<<endl<<"Enter the discount  ( ex:- 10'%' as 0.1): ";
    cin >> discount;
    cout<< endl<<"Discount added successfully"<<endl;
}

void managerMenuAction(){
    bool goToMenuAgain=false;
    do
    {
        int userInput;
        cin >> userInput; //assign the user input value corresponding to the menu options to the variable  

        switch (userInput)
        {
        case 1:
            cout << endl;
            viewBook();
            break;
        case 2:
            cout<< endl;
            addBook();
            break;
        case 3:
            cout << endl;
            searchBook();
            break;
        case 4:
            cout<<endl;
            viewOrders();
            break;
        case 5:
            cout<<endl;
            addDiscount();
            break;
        case 6:
            exitProgramme=true;
            goToMenuAgain=false;
            cout <<endl << "Manager menu is closed "<< endl;
            break;
        default:
            cout <<endl<<"incorrect input";
            break;
        }
        if (! exitProgramme)
        {
            char goAgain1;
            cout << endl << "press [Y] for Yes and [N] for No" << endl;// asking whether the user want to go for the menu again
            cout << "Do you want to go for the manager menu again ? :";
            cin >> goAgain1;
            cout << endl;
            if (toupper(goAgain1)== 'Y')
            {
                goToMenuAgain=true;
                printManagerMenu();
            }else if(toupper(goAgain1)== 'N'){
                goToMenuAgain=false;
                break;
            }
        }  
    } while (goToMenuAgain);



}

// ********************************************** user actions *****************************************

void printUserManu(){
    cout << endl;
    cout << "\t| User menu |"<< endl<< endl;
    cout <<"Press [1] to View books" <<endl;
    cout <<"Press [2] to place an order" <<endl;
    cout <<"Press [3] to prepare quotations"<< endl;
    cout <<"Press [4] to Exit from the menu" <<endl << endl;
    cout <<endl<< "Enter your choice here: "; 

}

void placeOrder(){
    // temporary variables to store ordered book name,book count,order price 
    string orderedBookName;  
    int orderedBookCount;
    double orderPrice=0;
    int num=1541; // number to get as a order ID    
    bool orderAgain=false;
    bool isBookFound=false;
    if(bookNameList.size()>0){
        do
        {
            viewBook(); // print available books 
            cout <<endl<< "Enter the name of the book you want to buy: ";
            getline(cin >> ws , orderedBookName);
            cout << "how many "<< orderedBookName <<" books do you need :";
            cin >>  orderedBookCount;
            
            
            //chechk whether the entered book name is in the book name list 
            for (int i = 0; i < bookNameList.size(); i++)
            {
                if (bookNameList[i]==orderedBookName) 
                {
                    isBookFound =true;
                    orderPrice=bookPriceList[i];
                    orderPrice= orderPrice * orderedBookCount; // Calculate the total book price by multiplying it from the book count
                    
                    bookOrderIDList.push_back(num++); // add book ID to the vector
                    orderedBookNameList.push_back(orderedBookName); // add the ordered book name to the vector
                    orderedBookCountList.push_back(orderedBookCount);
                    if (orderedBookCount>=discountBookAmount)
                    {
                        orderPrice=orderPrice-(orderPrice*discount); // deduct the discount amount from the total
                        orderTotalList.push_back(orderPrice); //add total order price by applying discount to the vector
                        cout <<endl<<"Order placed successfully"<<endl;
                        cout <<"You got a discount for the purchase of "<< orderedBookCount<<" "<< orderedBookName<<" books "<<endl;
                        cout <<"Total payable amount is now "<<orderPrice<<"$"<< endl;

                    }else
                    {
                        cout <<endl<<"Order placed successfully"<<endl;
                        orderTotalList.push_back(orderPrice); //add total order price  to the vector without any discount
                        cout <<"Total payable amount is  "<<orderPrice<<"$"<< endl;
                    }
                    
                    
                }
                
                
            }
            if (! isBookFound)
            {
                cout << endl<<"OOPS! The book you entered is not found in the system"<<endl<< "please try again another book"<<endl;
                    
            }
            
            char goAgain1;
            cout << endl << "press [Y] for Yes and [N] for No" << endl;// asking whether the user want to place an order again
            cout << "Do you want to place  an order again ? :";
            cin >> goAgain1;
            cout << endl;
            if (toupper(goAgain1)== 'Y')
            {
                orderAgain=true;
                printManagerMenu();
            }else if(toupper(goAgain1)== 'N'){
                orderAgain=false;
                break;
            }
            

        } while (orderAgain);

        
    }
    
}

void prepareQuotation(){
    int bookQuota; // variable to store number books included to the quotation
    int contactNum; // variable to store customer contact number 
    string bookNameQ;
    cout<<"Enter the amount of  books you want : "; //get the user input 
    cin>> bookQuota;
    cout <<endl<<"Enter contact number to inform you once we  ready your quotaton: ";
    cin >> contactNum;
    cout<<endl;
    for (int i = 0; i < bookQuota; i++) // get the book names that client need 
    {
        cout<< "Enter the name of the book "<<i<<":  ";
        getline(cin >> ws,bookNameQ);
        bookQuotaList.push_back(bookNameQ); // add each requested  book to the vector 
        cout<<endl;
    }
    cout<<"your quotaion added successfully"<<endl;
    
}

void userMenuAction(){
    bool goToMenuAgain=false;
    do
    {
        int userInput;
        cin >> userInput; //assign the user input value corresponding to the menu options to the variable 
        switch (userInput)
        {
        case 1:
            cout << endl;
            viewBook();
            break;
        case 2:
            cout << endl;
            placeOrder();
            break;
        case 3:
            cout << endl;
            prepareQuotation();
            break;
        case 4:
            exitProgramme=true;
            cout <<endl << "customer menu is closed "<<endl;
            break;
        default:
            cout << endl;
            cout << "Invalid input"<<endl;
            break;
        } 
        if (! exitProgramme)
        {
            char goAgain1;
            cout << endl << "press [Y] for Yes and [N] for No" << endl;// asking whether the user want to place an order again
            cout << "Do you want to go for the customer menu  again ? :";
            cin >> goAgain1;
            cout << endl;
            if (toupper(goAgain1)== 'Y') // check the user input 
            {
                goToMenuAgain=true;
                printUserManu();
            }else if(toupper(goAgain1)== 'N'){
                goToMenuAgain=false;
                break;
            }
        }

    } while (goToMenuAgain);
    
}

bool checkCustomerAccess(string userName,int password){
    if (userName==customerUsername && password==customerPassword) { // check the whether the entered username and the password is correct or not
        return true; //if correct return true 
    }else
    {
        return false;
    }
    
    
}


int main() {
    bool goMainMenuAgain=false;
    do{
        char userChoice;
        cout <<endl << "Are you a Manager or a Customer " << endl ;
        cout << "Press [M] to select Manager and [C] for the Customer :";
        cin >> userChoice;
        //select whether the user is  manager or a customer
        if (toupper(userChoice) == 'M')
        { 
            printManagerMenu();
            
            managerMenuAction();
            
        }else if (toupper(userChoice)=='C')
        {   // 2 variable to store user entered user name and password
            string UserName;
            int UserPassword;
            cout<<endl << "Enter the user name: ";
            cin >>  UserName;
            cout << "Enter the password: ";
            cin>> UserPassword;
            // call the function which returns a boolean value as a parameter , this returns true if the entered user name and password is correct
            if (checkCustomerAccess(UserName,UserPassword))   
            {
                cout <<endl<< "Login successfull "<<endl;
                printUserManu();
                userMenuAction();
            }else
            {
                cout <<endl << "invalid user name or password"<< endl;
            }            
            
        }else{
            cout << "invalid choice"<<endl;
        }

        char goAgain;
        cout << endl << "press [Y] for Yes and [N] for No" << endl;
        cout << "Do you want to go for the main menu  again ? :";
        cin >> goAgain;
        cout << endl;
        if (toupper(goAgain)== 'Y')
        {
            goMainMenuAgain=true;
            exitProgramme=false;
            
        }else
        {
            goMainMenuAgain=false;
            exitProgramme=true;
            cout <<endl<<"program is closed THANK YOU!"<< endl;
        }      
    }while(goMainMenuAgain && !exitProgramme);  
return 0;
    
}
