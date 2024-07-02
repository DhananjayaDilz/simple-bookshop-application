#include <iostream>
#include <vector>

using namespace std;






















int main(){

   
    vector <string> bookname ={"hath pana","magul kema", "miska" , "dhana"}                       ;
    
   for (int i = 0; i <bookname.size(); i++) // 4
   {
      cout << bookname[i] << endl; //0 1   
   }

   cout <<endl<< bookname[0] << endl;
   cout << bookname[1]<< endl;
   cout << bookname[2]<< endl;
   cout << bookname[3] << endl;

   
    
    cout << "**          **" <<endl;
    cout << "* *        * *"<<endl;
    cout << "*  *      *  *" <<endl;
    cout << "*   *    *   *" <<endl;
    cout << "*    *  *    *" <<endl;
    cout << "*     **     *" <<endl;

    return 0;
}