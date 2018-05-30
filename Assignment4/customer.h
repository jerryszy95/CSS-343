//------------------------------------------------------------------------------
// CUSTOMER.H
// Object class for customers 
// Author: Hien Nguyen
//------------------------------------------------------------------------------
// Customer class: Using this class for creating a new customer, includes
// first name, last name, id. We able to edit and track transaction log
// of a customer.
//------------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<map>

#pragma once
using namespace std;
#define MAXLOG 500  // default transaction log 

class Customer {

public:

    //--------------------------constructor-------------------------------------
    // constuctor: initialization
    // precondition: N/A
    // postcondition: customer is constructed
    //--------------------------------------------------------------------------
    Customer();

    //---------------------------destructor-------------------------------------
    // Destructor: destructor
    // precondition: N/A
    // postcondition: customer is destructed
    //--------------------------------------------------------------------------
    ~Customer();

    //---------------------------customer---------------------------------------
    // Customer: create customer object 
    // precondition: ID, firstname and last name of customer
    // postcondition: the customer object is created
    //--------------------------------------------------------------------------
    Customer(int ID, string firstName, string lastName);


    //---------------------------getID------------------------------------------
    // GetID: getting id of customer 
    // precondition: N/A
    // postcondition: return the ID as an interger
    //--------------------------------------------------------------------------
    int getID() const;

    //-----------------------setFirstname---------------------------------------
    // setFirstName: set the first name of customer object
    // precondition: firstname as a string
    // postcondition: the firstname of the object is updated
    //--------------------------------------------------------------------------
    void setFirstName(string firstname);

    //-------------------------getFirstName-------------------------------------
    // getFirstName: get the first name of customer object
    // precondition: N/A
    // postcondition: the firstname of the object is returned as a string
    //--------------------------------------------------------------------------
    string getFirstName()const;

    //---------------------------setLastName------------------------------------
    // setLastName: set the last name of customer object
    // precondition: lastname as a string
    // postcondition: the lastname of the object is updated
    //--------------------------------------------------------------------------
    void setLastName(string lastname);

    //--------------------------getLastName-------------------------------------
    // getLastName: get the last name of customer object
    // precondition: N/A
    // postcondition: the lastname of the object is returned as a string
    //--------------------------------------------------------------------------
    string getLastName()const;

    //-----------------------logTransaction-------------------------------------
    // logTransaction: write to the log transaction of the customer
    // precondition: key is the title or id of the dvd, action 'B' is borrow,
    //               'R' is return.
    // postcondition: transaction is wrote 
    //--------------------------------------------------------------------------
    void logTransaction(string key, string action);

    //---------------------------showTransaction--------------------------------
    // showTransaction: display the transaction history of the customers
    // precondition: N/A
    // postcondition: transaction history is sorted as latest to newest
    //--------------------------------------------------------------------------
    void showTransaction();

    int getNumberOfTrans();


private:

    int ID;                                 // customer's ID
    string firstName;                       // customer's first name
    string lastName;                        // customer's last name
    int numberOfTrans = 0;                  // number of transactions
    string log[MAXLOG][3];  // tracklog for transaction of this customer
    map<int, string> opens; // transaction of dvds not returned yet.

};