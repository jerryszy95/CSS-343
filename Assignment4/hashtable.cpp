//---------------------------------------------------------------------------
// HASHTABLE.CPP
// Simple class Hash Table 
// Author: Hien Nguyen
//---------------------------------------------------------------------------
// HashTable class: A hashtable is designed to store a list of customer
// pointer objects. 
//---------------------------------------------------------------------------

#include "hashtable.h"
//--------------------------constructor-------------------------------------
// constuctor: initialization
// precondition: N/A
// postcondition: hash table is constructed
//--------------------------------------------------------------------------
HashTable::HashTable() {
    // intialize
    for (int i = 0; i < HASHTABLESIZE; i++) {
        hashTableArr[i] = new map<int, Customer*>;
    }
}

//---------------------------destructor-------------------------------------
// Destructor: destructor
// precondition: N/A
// postcondition: the hashtable is destructed
//--------------------------------------------------------------------------
HashTable::~HashTable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
       delete hashTableArr[i];
    }
}

//------------------------------insert--------------------------------------
// insert: inserts a customer into the hashtable
// precondition: customer is a customer pointer
// postcondition: if the customer object is inserted in the hash table
// return true, otherwise fail. 
//--------------------------------------------------------------------------
bool HashTable::insert(Customer *customer) {
    int id = customer->getID(); // get id
    if (get(id) == NULL) { // if the customer is not in the list
        int index = hashfuc(id); // hash function
        hashTableArr[index]->insert(pair<int, Customer*>(id, customer));
        return true;
    }
    else {
        return false;
    }
}

//-------------------------------get----------------------------------------
// get: get a customer in the hashtable
// precondition: ID is the ID of the customer  
// postcondition: return a pointer to the getting customer, if there is no
// pointer, return NULL
//--------------------------------------------------------------------------
Customer* HashTable::get(const int ID) {
    int index = hashfuc(ID);  // call hash function
    if (hashTableArr[index]->find(ID) != hashTableArr[index]->end()) {
        return  hashTableArr[index]->find(ID)->second;
    }
    else {
        return NULL;
    }
}

//-------------------------------size----------------------------------------
// size: the size of the hashtable
// precondition: N/A
// postcondition: number of elements (customers) in the hashtable
//--------------------------------------------------------------------------
int HashTable::size() const
{
    int size = 0; // default 
    for (int i = 0; i < HASHTABLESIZE; i++) {
        size = size + hashTableArr[i]->size(); // couting
    }
    return size; // total
}

//------------------------------remove--------------------------------------
// remove: remove a customer from the hashtable
// precondition: ID of the customer we want to remove
// postcondition:  if the customer object is deleted in the hash table
// return true, otherwise fail. 
//--------------------------------------------------------------------------
bool HashTable::remove(const int ID)
{
    if (get(ID) != NULL) {
        int index = hashfuc(ID);   // call hash function
        hashTableArr[index]->erase(ID); // remove from the map
        return true;
    }
    else {
        return false;
    }
}

//------------------------------printAll--------------------------------------
// printAll: print out the console all customers with hashtable style
// precondition: N/A
// postcondition: All elements are printed out
//--------------------------------------------------------------------------
void HashTable::printAll() {

    // check for each map of hastable
    for (int i = 0; i < HASHTABLESIZE; i++) {
        map<int, Customer*>::iterator it = hashTableArr[i]->begin();
        if (!hashTableArr[i]->empty()) {
            string prex = "";
            if (i < 10) {
                prex = "0";
            }
            cout << "["<<prex<<i<<"] =>" ;
            // check for each element in the map
            for (it = hashTableArr[i]->begin(); 
                it != hashTableArr[i]->end(); ++it) {
                
                // Friendly print out
                string space_prex = "";
                string space_end = "";

                string name = it->second->getFirstName() 
                    + " " + it->second->getLastName();

                // space checking to have friendly output
                int space = 18 - name.length();
                if (space > 0) {
                    if (space % 2 != 0) {
                        space_end=space_end+" ";
                    }
                    for (int i = 0; i < (space/2); i++) {
                        space_prex += " ";
                        space_end += " ";
                    }
                   
                }
                cout << "[" << space_prex << it->first << " " 
                    << name << space_end << "] ";
              
            }
            cout << endl;
        }
        
    }
}

//------------------------------getAll--------------------------------------
// getAll: get all customers from the hashtable
// precondition: N/A
// postcondition: A vector of pointes which is pointing to customer objects
//--------------------------------------------------------------------------
vector<Customer*> HashTable::getAll()
{
    vector<Customer*> tmp;
    // check for each map
    for (int i = 0; i < HASHTABLESIZE; i++) {
        map<int, Customer*>::iterator it = hashTableArr[i]->begin();
        if (!hashTableArr[i]->empty()) {
            // check for each element in map
            for (it = hashTableArr[i]->begin(); 
                it != hashTableArr[i]->end(); ++it) {
                tmp.push_back(it->second); // add to vector
            }
        }

    }

    return tmp;
}

//------------------------------hashfuc--------------------------------------
// hashfuc: result an index of map in hash table
// precondition: A number which should be customer id
// postcondition: The index of the map in hash table
//--------------------------------------------------------------------------
int HashTable::hashfuc(int id) {
    return (id%HASHTABLESIZE);
}
