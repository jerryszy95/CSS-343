//---------------------------------------------------------------------------
// main.cpp
// Implement Assignment 4 - Movie Rental Store 
// Authors: Nguyen, Shen 
// March 2018
//---------------------------------------------------------------------------
// Main class: This driver will read files for building a store
//   -- data4movies.txt - The list of movies
//   -- data4customers.txt  - The list of customers
//   -- data4commands.txt   - The list of commands to test trasactions
//
// Assumptions:
//   -- there is no error in the reading file
//   -- all customers must have first & last name
//---------------------------------------------------------------------------

#include "store.h";
#include "customer.h";
using namespace std;

int main() {

    /********** CREATING STORE ******************/
    Store myStore;

    /********** CREATING MOVIE ******************/
    // reading movies
    ifstream db_movies("data4movies.txt");
    if (!db_movies) {
        cout << "File could not be opened." << endl;
        system("pause");
        return -1;
    }

    myStore.buildMovieList(db_movies);

    /********** WORKING WITH CUSTOMER **********/
    // reading customers
    ifstream db_customers("data4customers.txt");
    if (!db_customers) {
        cout << "File could not be opened." << endl;
        system("pause");
        return -1;
    }
   
    // building customer list from file
    myStore.buildCustomerList(db_customers);
    myStore.printAllCustomer();
/*  // geting customer size
    cout << "Number of customer: " << myStore.getCustomerSize() <<endl;
    // finding an exist customer
    cout << "Find ID 9000: " << myStore.findCustomerByID(9000) <<endl;
    // finding a nonexist customer
    cout << "Find ID 9111: " << myStore.findCustomerByID(9111) <<endl;
    // removing a customer
    cout << "Remove customer 9000: ";
    if (myStore.removeCustomerByID(9000)) {
        cout << "Done" << endl;
    }
    else { cout << "Can't remove" << endl; }
    // finding an removed customer
    cout << "Find ID 9000: " << myStore.findCustomerByID(9000) <<endl;
    // geting customer size
    cout << "Number of customer: " << myStore.getCustomerSize() << endl;
    // adding a customer
    cout << "Add 2222 Hien Nguyen" <<endl; 
    myStore.addCustomer(2222, "Hien", "Nguyen");
    // geting customer size
    cout << "Number of customer: " << myStore.getCustomerSize() << endl;
    // finding an exist customer
    cout << "Find ID 2222: " << myStore.findCustomerByID(2222) << endl;
    cout << "Update info 2222 Zeyu Shen"<<endl;
    myStore.updateCustomerInfo(2222, "Zeyu", "Shen");
    cout << "Find ID 2222: " << myStore.findCustomerByID(2222) << endl;
    // geting customer size
    cout << "Number of customer: " << myStore.getCustomerSize() << endl;
    // print all customer
    myStore.printAll();
    myStore.printAll(true); // print with hashtable style
  */  
    
    /** HISTORY TEST *
    Customer hien(001, "Hien", "Nguyen");
    hien.logTransaction("Power Ranger ", "B");
    hien.logTransaction("Cuon Theo Chieu Gio", "B");
    hien.logTransaction("Thep Da Toi The Day", "B");
    hien.logTransaction("Nhung nguoi khon kho", "B");
    hien.logTransaction("Anh Hung Xa Dieu", "B");
    hien.logTransaction("Thep Da Toi The Day", "B");
    hien.logTransaction("Power Ranger", "R");
    hien.logTransaction("Cuon Theo Chieu Gio", "R");
    hien.logTransaction("Nhung nguoi khon kho", "R");
    hien.logTransaction("Thep Da Toi The Day", "R");
    hien.showTransaction();
    */

    /*****  END WORKING WITH CUSTOMER ***********/


    /********** WORKING WITH COMMANDS ***********/
    // reading commands
    ifstream db_commands("data4commands.txt");
    if (!db_commands) {
        cout << "File could not be opened." << endl;
        system("pause");
        return -1;
    }

    myStore.runCommandFile(db_commands);

    //myStore.runCommand("I");
    // myStore.runCommand("B 8000 D F You've Got Mail, 1998");
    // myStore.runCommand("B 1000 D D Barry Levinson, Good Morning Vietnam,");
    // myStore.runCommand("B 1000 D D Barry Levinson, Good Morning Vietnam,");

    //myStore.runCommand("R 1000 D F Sleepless in Seattle, 1993");
    //  myStore.runCommand("B 5000 D C 3 1971 Ruth Gordon");
    //  myStore.runCommand("B 5000 D C 3 1971 Ruth Gordon");

    myStore.runCommand("I");

    cout << "----------------------------------------------" << endl;
    myStore.runCommand("H 4444");
    cout << "----------------------------------------------" << endl;
    myStore.runCommand("B 4444 D C 2 1971 Malcolm McDowell");
    myStore.runCommand("H 4444");
    myStore.runCommand("I");

    /*****  END WORKING WITH COMMANDS ***********/


   

    system("pause");
    return 0;
}