//---------------------------------------------------------------------------
// HASHTABLE.H
// Simple class Hash Table 
// Author: Hien Nguyen
//---------------------------------------------------------------------------
// HashTable class: A hashtable is designed to store a list of customer
// pointer objects. 
//---------------------------------------------------------------------------

#ifndef HashTable_H
#define HashTable_H

#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define HASHTABLESIZE 10 // must be > 0

#include "customer.h";

class HashTable {

public:
    //--------------------------constructor-------------------------------------
    // constuctor: initialization
    // precondition: N/A
    // postcondition: hash table is constructed
    //--------------------------------------------------------------------------
    HashTable();

    //---------------------------destructor-------------------------------------
    // Destructor: destructor
    // precondition: N/A
    // postcondition: the hashtable is destructed
    //--------------------------------------------------------------------------
    ~HashTable();

    //------------------------------insert--------------------------------------
    // insert: inserts a customer into the hashtable
    // precondition: customer is a customer pointer
    // postcondition: if the customer object is inserted in the hash table
    // return true, otherwise fail. 
    //--------------------------------------------------------------------------
    bool insert(Customer *customer);

    //-------------------------------get----------------------------------------
    // get: get a customer in the hashtable
    // precondition: ID is the ID of the customer  
    // postcondition: return a pointer to the getting customer, if there is no
    // pointer, return NULL
    //--------------------------------------------------------------------------
    Customer* get(const int ID);

    //-------------------------------size----------------------------------------
    // size: the size of the hashtable
    // precondition: N/A
    // postcondition: number of elements (customers) in the hashtable
    //--------------------------------------------------------------------------
    int size() const;

    //------------------------------remove--------------------------------------
    // remove: remove a customer from the hashtable
    // precondition: ID of the customer we want to remove
    // postcondition:  if the customer object is deleted in the hash table
    // return true, otherwise fail. 
    //--------------------------------------------------------------------------
    bool remove(const int ID);

    //------------------------------printAll--------------------------------------
    // printAll: print out the console all customers with hashtable style
    // precondition: N/A
    // postcondition: All elements are printed out
    //--------------------------------------------------------------------------
    void printAll();

    //------------------------------getAll--------------------------------------
    // getAll: get all customers from the hashtable
    // precondition: N/A
    // postcondition: A vector of pointes which is pointing to customer objects
    //--------------------------------------------------------------------------
    vector<Customer*> getAll();

private:
    map<int,Customer*> *hashTableArr[HASHTABLESIZE];     // the hashtable array
    int hashfuc(int ID);                                 // hash function

    

};

#endif