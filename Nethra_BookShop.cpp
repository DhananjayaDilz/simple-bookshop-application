#include <iostream>
#include <list>
#include <vector>
 
using namespace std;
 

vector <string> bookNameList ;
vector <double> bookPriceList ;
vector <string> bookIdList; 





// print the menu options for the bookshop manager 
void printManagerMenu(){
    cout << "\t| Manager menu |"<< endl<< endl;
    cout <<"Press [1] to View books" <<endl;
    cout <<"Press [2] to Add books" <<endl;
    cout <<"Press [3] to Search books" <<endl;
    cout <<"Press [4] to View book orders" <<endl;
    cout <<"Press [5] to prepare quotations" <<endl;
    cout <<"Press [6] to Add discounts" <<endl << endl;
    cout << "Enter your choice here: ";
    
    
    
}


void addBook(){

    bool addAnotherBook = false;
    do{
        string bookName;
        string bookID;
        double bookPrice;
        cout<< endl << "Enter the book name: "; // get the book name from the user and add it to the vector
        getline(cin >> ws, bookName);
        bookNameList.push_back(bookName);

        cout << "Enter book ID: "; // get the book ID from the user and add it to the vector
        cin >> bookID;
        bookIdList.push_back(bookID);

        cout << "Enter the book price: "; //get the book price from the user and add it to the vector
        cin >> bookPrice;
        bookPriceList.push_back(bookPrice);

        char userInput;
        cout << endl<< "Press [Y] for yes and [N] for no " << endl; // ask the user whether he want add another book or not
        cout << "Do you want to add another book: ";
        cin >>  userInput;

        if (toupper(userInput)== 'Y')
        {
           addAnotherBook = true;
        }else
        {
            addAnotherBook= false;
        }
        
        
    }while(addAnotherBook);


    
}

void viewBook(){
    if (true)
    {
        cout <<"\t\t*********************" << endl;
        cout <<"\t\t|  Nethra Book shop |" << endl;
        cout <<"\t\t*********************" << endl<< endl;
        cout << "book Name\t\tBook ID\t\t\tPrice" << endl<< endl;

        for (int i = 0; i < bookNameList.size(); i++)
        {
            cout << bookNameList[i] << "\t\t\t" << bookIdList[i] << "\t\t\t" <<bookPriceList[i] <<endl;
        }
        
        

    }else
    {
        cout << " OOPS! no books to view ";
    }
    
    

}
 
void searchBook(){

    string bookToSearch;
    bool isBookFound=false;
    cout << "Enter the name of the book you want: "; 
    getline(cin >> ws,bookToSearch);

    for (int i = 0; i < bookNameList.size(); i++) 
    {
        if (bookNameList[i]==bookToSearch) 
        {
            cout << endl<< "The book "<< bookToSearch << " is available"<< endl;
            cout << "*****************************************"<< endl;
            cout << "Book Name: " << bookNameList[i]<<endl;
            cout << "Book ID: " << bookIdList[i]<< endl;
            cout << "Book price: "<< bookPriceList[i]<<endl;
            cout<< "*******************************************"<<endl;
            isBookFound=true;

        }

        
    }
    if (! isBookFound)
    {
       cout << "The book you enterd not available in the store "<<endl; 
    }
    
    




}


void managerMenuAction(){
    bool viewManagerMenuAgain=false;
    do{
        int userInput;
        cin >> userInput;

        switch (userInput)
        {
        case 1:
            viewBook(); //call view book fuction 
            break;
        case 2:
            addBook(); // call view add Book function
            break;
        case 3:
            searchBook();
            break;
        case 4:
            cout<<"call the view book orders function";
            break;
        case 5:
            cout << "call the prepare quotations function";
            break;
        case 6:
            cout<<"call the add discount function";
            break;
        default:
            cout <<"incorrect input";
            break;
        }

        char input;
        cout << endl<< "Please enter [Y] for yes and [N] for no";
        cout <<endl<< "Do you want to go for the menu again: ";
        cin >> input;
        if (toupper(input)=='Y')
        {
            viewManagerMenuAgain=true;
            printManagerMenu();
        }else
        {
            viewManagerMenuAgain= false;
        }
        
        

    }while(viewManagerMenuAgain);


}


int main() {
    char userChoice;
    cout << "Are you a Manager or a Customer " << endl ;
    cout << "Press [M] to select Manager and [C] for the Customer :";
    cin >> userChoice;
    //select whether the user is  manager or a customer
    if (toupper(userChoice)== 'M') // capitalize the user input 
    {
        cout<< "manager selected"<< endl ;
        printManagerMenu();
        managerMenuAction();
    }else if (toupper(userChoice)=='C')
    {
        cout << "Customer selected";
    }else{
        cout << "invalid choice";
    }
    
    

  
return 0;
    
}
