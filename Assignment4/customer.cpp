//------------------------------------------------------------------------------
// CUSTOMER.CPP
// Object class for customers 
// Author: Hien Nguyen
//------------------------------------------------------------------------------
// Customer class: Using this class for creating a new customer, includes
// first name, last name, id. We able to edit and track transaction log
// of a customer.
//------------------------------------------------------------------------------
#include "customer.h"

//--------------------------constructor-----------------------------------------
// constuctor: initialization
// precondition: N/A
// postcondition: customer is constructed
//------------------------------------------------------------------------------
Customer::Customer() {
    ID = 0;
    firstName = "";
    lastName = "";
}

//---------------------------destructor-----------------------------------------
// Destructor: destructor
// precondition: N/A
// postcondition: customer is destructed
//------------------------------------------------------------------------------
Customer::~Customer() {
}

//---------------------------customer-------------------------------------------
// Customer: create customer object 
// precondition: ID, firstname and last name of customer
// postcondition: the customer object is created
//------------------------------------------------------------------------------
Customer::Customer(int id, string firstName, string lastName) {

    if (id != 0 && firstName != "" && lastName != "") {
        this->ID = id;
        this->firstName = firstName;
        this->lastName = lastName;
    }
}

//---------------------------getID----------------------------------------------
// GetID: getting id of customer 
// precondition: N/A
// postcondition: return the ID as an interger
//------------------------------------------------------------------------------
int Customer::getID() const {
    return ID;
}

//-----------------------setFirstname-------------------------------------------
// setFirstName: set the first name of customer object
// precondition: firstname as a string
// postcondition: the firstname of the object is updated
//------------------------------------------------------------------------------
void Customer::setFirstName(string firstname)
{
    this->firstName = firstname;
}

//-------------------------getFirstName-----------------------------------------
// getFirstName: get the first name of customer object
// precondition: N/A
// postcondition: the firstname of the object is returned as a string
//------------------------------------------------------------------------------
string Customer::getFirstName() const
{
    return firstName;
}

//---------------------------setLastName----------------------------------------
// setLastName: set the last name of customer object
// precondition: lastname as a string
// postcondition: the lastname of the object is updated
//------------------------------------------------------------------------------
void Customer::setLastName(string lastName)
{
    this->lastName = lastName;
}

//--------------------------getLastName-----------------------------------------
// getLastName: get the last name of customer object
// precondition: N/A
// postcondition: the lastname of the object is returned as a string
//------------------------------------------------------------------------------
string Customer::getLastName() const
{
    return lastName;
}

//-----------------------logTransaction-----------------------------------------
// logTransaction: write to the log transaction of the customer
// precondition: key is the title or id of the dvd, action 'B' is borrow,
//               'R' is return.
// postcondition: transaction is wrote 
//------------------------------------------------------------------------------
void Customer::logTransaction(string title, string action)
{
    // if borrow 
    if (action[0] == 'B') {
        log[numberOfTrans][1] = title;
        log[numberOfTrans][2] = "[OPEN]";
        log[numberOfTrans][3] = "Borrowing ";
        opens.insert(pair<int, string>(numberOfTrans, title));
        numberOfTrans++;
    }
    // if return
    if (action[0] == 'R') {
        map<int, string>::iterator it = opens.begin();
        // mark if the dvd is returned
        for (it = opens.begin(); it != opens.end(); ++it) {
            if (it->second == title) {
                log[it->first][2] = "[CLOSED]";
                log[it->first][3] = "Borrowed  ";
                opens.erase(it->first); // remove from open
                log[numberOfTrans][1] = title;
                log[numberOfTrans][3] = "Returned  ";
                numberOfTrans++;
                break;
            }
        }
    }


}

//---------------------------showTransaction------------------------------------
// showTransaction: display the transaction history of the customers
// precondition: N/A
// postcondition: transaction history is sorted as latest to newest
//------------------------------------------------------------------------------
void Customer::showTransaction()
{
    cout << "Transaction Log of " << getFirstName() << 
        " " << getLastName() << endl;
    int index = 0;
    for (int i = 0; i < numberOfTrans; i++) {
        cout << ++index << ". " << log[i][3] << " " << log[i][1] << " "
            << log[i][2] << endl;
    }
}

int Customer::getNumberOfTrans()
{
    return numberOfTrans;
}
