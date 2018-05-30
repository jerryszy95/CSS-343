//------------------------------------------------------------------------------
// STORE.H
// STORE class for managment 
// Author: Hien Nguyen and Shen
//------------------------------------------------------------------------------
// Store class: 

//------------------------------------------------------------------------------
#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>


#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include "hashtable.h"

using namespace std;
class Store {

public:
    //--------------------------constructor-------------------------------------
    // constuctor: initialization
    // precondition: N/A 
    // postcondition: customer is constructed
    //--------------------------------------------------------------------------
    Store();

    //---------------------------destructor-------------------------------------
    // Destructor: destructor
    // precondition: N/A
    // postcondition: customer is destructed
    //--------------------------------------------------------------------------
    ~Store();

    //--------------------------------------------------------------------------
    //*******************WORKING WITH MOVIES IN THE STORE********************* 
    //--------------------------------------------------------------------------
    void buildMovieList(ifstream &movies);

    //--------------------------------------------------------------------------
    //*******************WORKING WITH CUSTOMER IN THE STORE********************* 
    //--------------------------------------------------------------------------

    //---------------------------buildCustomerList------------------------------
    // buildCustomerList: build the list of customer from txt file
    // precondition: ifstream of customer file 
    // postcondition: the customer objects are created, then add to hash table
    //--------------------------------------------------------------------------
    void buildCustomerList(ifstream &customers);

    //---------------------------getCustomerSize--------------------------------
    // getCustomerSize: number of customer in this store
    // precondition: N/A
    // postcondition: return number of customer in the store as an interger
    //--------------------------------------------------------------------------
    int getCustomerSize();

    //---------------------------findCustomerByID-------------------------------
    // findCustomerByID: get the info of a customer
    // precondition: ID of the customer
    // postcondition: all info of the customer is returned as a string, return
    // not found if there is nothing
    //--------------------------------------------------------------------------
    string findCustomerByID(int id);

    //---------------------------removeCustomerByID-----------------------------
    // removeCustomerByID: remove of a customer from the store
    // precondition: ID, firstname and last name of customer
    // postcondition: customer is removed from store, return fail if there is no
    // customer has that ID
    //--------------------------------------------------------------------------
    bool removeCustomerByID(int id);

    //---------------------------addCustomer------------------------------------
    // addCustomer: create customer object then add to hash table
    // precondition: ID, firstname and last name 
    // postcondition: the customer object is created then add to the hash table
    //--------------------------------------------------------------------------
    bool addCustomer(int id, string firstName, string lastName);

    //---------------------------updateCustomerInfo-----------------------------
    // updateCustomerInfo: update info of the customer
    // precondition: ID, firstname and last name of customer
    // postcondition: the customer object is updated, if there is no customer
    // has that id, return false
    //--------------------------------------------------------------------------
    bool updateCustomerInfo(int id, string firstName, string lastName);


    //---------------------------printAllCustomer--------------------------------------
    // printAllCustomer: print all customer 
    // precondition: input false if you want to print with hashtable view
    // postcondition: all customers are printed
    //--------------------------------------------------------------------------
    void printAllCustomer(bool tableView = false);


    //--------------------------------------------------------------------------
    //******************** WORKING WITH COMMAND IN THE STORE******************* 
    //--------------------------------------------------------------------------


    //---------------------------runCommand-------------------------------------
    // runCommand: run the command from users or files
    // precondition: the command line
    // postcondition: the command runs. Return false if invalid input.
    //--------------------------------------------------------------------------
    bool runCommand(string cmd);

    //---------------------------runCommandFile-------------------------------------
    // runCommand: run the command from users or files
    // precondition: the command file
    // postcondition: the command runs. Return false if invalid input.
    //--------------------------------------------------------------------------
    bool runCommandFile(ifstream & commands);

    //---------------------------showHistory-------------------------------------
    // showhistory: check if the ID have the transaction
    // precondition: ID
    // postcondition: true if there is history, otherwise false
    //--------------------------------------------------------------------------
    bool showHistory(int id );
    
private:
    // stores all customers in the hashtable object
    HashTable customerList;

    // stores all movies in the BSTs
     vector<Movie*> moviesF;
     vector<Movie*> moviesD;
     vector<Movie*> moviesC;


     //---------------------------subStrAt--------------------------------------
     // subStrAt: get the position of a character in appear times
     // precondition: str is orignal, index is time of appearing, sign is char
     // postcondition: retuen the position of a character
     //--------------------------------------------------------------------------
     int subStrAt(string str, int index, char sign);

     //---------------------------updataStock--------------------------------------
     // updataStock:  updata stock of movies
     // precondition: plus is undata in stock, the *src is the movie 
     // postcondition: return false when new stock <0, otherwise return true.
     //--------------------------------------------------------------------------
     bool updateStock(int plus,Movie* src);

};