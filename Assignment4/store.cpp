//------------------------------------------------------------------------------
// STORE.CPP
// STORE class for managment 
// Author: Hien Nguyen and Shen
//------------------------------------------------------------------------------
// Store class: 

//------------------------------------------------------------------------------
#include "store.h"

//--------------------------constructor-------------------------------------
// constuctor: initialization
// precondition: N/A
// postcondition: customer is constructed
//--------------------------------------------------------------------------
Store::Store() {};

//---------------------------destructor-------------------------------------
// Destructor: destructor
// precondition: N/A
// postcondition: customer is destructed
//--------------------------------------------------------------------------
Store::~Store()
{
    // Deallocate movie inventory by calling
    // a destructor on three BST pointers

    // Deallocate the customerBase by calling
    // a destructor on the hashtable
}

//--------------------------------------------------------------------------
//*******************WORKING WITH MOVIES IN THE STORE********************* 
//--------------------------------------------------------------------------

//---------------------------buildCustomerList------------------------------
//--------------------------------------------------------------------------
void Store::buildMovieList(ifstream & movies)
{
    while (!movies.eof())
    {
        string line;
        getline(movies, line);
        
        istringstream ss(line);
        string genre;
        getline(ss, genre, ',');

        // build Comedy movies
        if (genre == "F") {
            string stock;
            getline(ss, stock, ',');

            string director;
            getline(ss, director, ',');

            string title;
            getline(ss, title, ',');

            string year;
            getline(ss, year, ',');
         

            Movie* myMoviePtr = new Movie(stoi(stock),director,title, stoi(year),'D','F');
            moviesF.push_back(myMoviePtr);
        }

        // build Drama movies
        if (genre == "D") {

            string stock;
            getline(ss, stock, ',');

            string director;
            getline(ss, director, ',');

            string title;
            getline(ss, title, ',');

            string year;
            getline(ss, year, ',');


            Movie* myMoviePtr = new Movie(stoi(stock), director, title, stoi(year), 'D', 'D');
            moviesD.push_back(myMoviePtr);
        }

        // build classic movie
        if (genre == "C") {

            string stock;
            getline(ss, stock, ',');

            string director;
            getline(ss, director, ',');

            string title;
            getline(ss, title, ',');

            string last_str;
            getline(ss, last_str, ',');

            istringstream ss(last_str);
           
            int pos1 = 0;
            int pos2 = subStrAt(last_str, 2, ' ');
            string actor = last_str.substr(pos1, pos2-pos1);

            pos1 = pos2 + 1;
            pos2 = last_str.length();
            string year = last_str.substr(pos1,pos2-pos1);

            pos1 = subStrAt(year, 0, ' ');
            pos2 = year.length() - pos1;
            int iyear = stoi(year.substr(pos1, pos2 - pos1+1));

            Movie * myMoviePtr = new Classic(stoi(stock), director, title, actor+" "+year,iyear, 'D', 'C');
            moviesC.push_back(myMoviePtr);
        }
   
    }
    movies.close();
    
}

//--------------------------------------------------------------------------
//*******************WORKING WITH CUSTOMER IN THE STORE********************* 
//--------------------------------------------------------------------------

//---------------------------buildCustomerList------------------------------
// buildCustomerList: build the list of customer from txt file
// precondition: ifstream of customer file 
// postcondition: the customer objects are created, then add to hash table
//--------------------------------------------------------------------------
void Store::buildCustomerList(ifstream & customers)
{
    Customer *customer;

    while (!customers.eof())
    {
        string ID, last, first;

        customers >> ID;
        customers >> last;
        customers >> first;

        // convert string to int
        int id = atoi(ID.c_str());
        customer = new Customer(id, last, first);
        if (id != 0 && first != "" && last != "") {
            customerList.insert(customer);
        }
    }
}

//---------------------------getCustomerSize--------------------------------
// getCustomerSize: number of customer in this store
// precondition: N/A
// postcondition: return number of customer in the store as an interger
//--------------------------------------------------------------------------
int Store::getCustomerSize()
{
    return customerList.size();
}

//---------------------------findCustomerByID-------------------------------
// findCustomerByID: get the info of a customer
// precondition: ID of the customer
// postcondition: all info of the customer is returned as a string, return
// not found if there is nothing
//--------------------------------------------------------------------------
string Store::findCustomerByID(int id)
{
    Customer* tmp = customerList.get(id);

    if (tmp != NULL) {
        return tmp->getFirstName() + " " + tmp->getLastName();
    }
    else {
        return "Not found!";
    }
}

//---------------------------removeCustomerByID-----------------------------
// removeCustomerByID: remove of a customer from the store
// precondition: ID, firstname and last name of customer
// postcondition: customer is removed from store, return fail if there is no
// customer has that ID
//--------------------------------------------------------------------------
bool Store::removeCustomerByID(int id)
{ 
    return customerList.remove(id);
}

//---------------------------addCustomer------------------------------------
// addCustomer: create customer object then add to hash table
// precondition: ID, firstname and last name 
// postcondition: the customer object is created then add to the hash table
//--------------------------------------------------------------------------
bool Store::addCustomer(int id, string firstName, string lastName)
{
    Customer* tmp = new Customer(id, firstName, lastName);
    return customerList.insert(tmp);
}

//---------------------------updateCustomerInfo-----------------------------
// updateCustomerInfo: update info of the customer
// precondition: ID, firstname and last name of customer
// postcondition: the customer object is updated, if there is no customer
// has that id, return false
//--------------------------------------------------------------------------
bool Store::updateCustomerInfo(int id, string firstName, string lastName)
{
    Customer* tmp = customerList.get(id);
    if (tmp != NULL) {
        tmp->setFirstName(firstName);
        tmp->setLastName(lastName);
    }
    else {
        return false;
    }
    
}

//--------------------------------------------------------------------------
//******************** WORKING WITH CUSTOMER IN THE STORE******************* 
//--------------------------------------------------------------------------

//---------------------------runCommand-------------------------------------
// runCommand: run the command from users or files
// precondition: the command line
// postcondition: the command runs. Return false if invalid input.
//--------------------------------------------------------------------------
bool Store::runCommand(string cmd)
{
    // show all
    if (cmd[0] == 'I') {

        // print out all F movie
        for (int i = 0; i < moviesF.size(); i++) {
            cout << moviesF[i]->getGenre() << " ";
            cout << moviesF[i]->getType() << " ";
            cout << moviesF[i]->getStock() << " ";
            cout << moviesF[i]->getDirName() << " ";
            cout << moviesF[i]->getTitle() << " ";
            cout << moviesF[i]->getReleaseYear() << endl;
        }

        // print out all D movie
        for (int i = 0; i < moviesD.size(); i++) {
            cout << moviesD[i]->getGenre() << " ";
            cout << moviesD[i]->getType() << " ";
            cout << moviesD[i]->getStock() << " ";
            cout << moviesD[i]->getDirName() << " ";
            cout << moviesD[i]->getTitle() << " ";
            cout << moviesD[i]->getReleaseYear() << endl;
        }

        // print out all C movie
        for (int i = 0; i < moviesC.size(); i++) {
            cout << moviesC[i]->getGenre() << " ";
            cout << moviesC[i]->getType() << " ";
            cout << moviesC[i]->getStock() << " ";
            cout << moviesC[i]->getDirName() << " ";
            cout << moviesC[i]->getTitle() << " ";
            cout << moviesC[i]->getActorAndRelease()<<endl;
        }
       
    }
    // show the history
    else if (cmd[0] == 'H') {

        string type;
        string ID;
        stringstream s;
        s << cmd;
        s >> type;
        s >> ID;

        int id = atoi(ID.c_str());
        showHistory(id);     // show history

    }
    // if there is borrow or return
    else if (cmd[0] == 'B' || cmd[0] == 'R')
    {
        string act;         //action
        string ID;          // id customer
        string type;        // type
        char genre;         // genre
        stringstream s;
        s << cmd;
        s >> act;
        s >> ID;
        s >> type;
        s >> genre;
       
        Customer* cus = customerList.get(stoi(ID));
        if (cus == NULL) {
            cout << "There is no customer: " << ID << endl;
            return false; // there is no customer
        }
        
        if (genre == 'F') {
            // using substring for getting info from cmd line
            int pos1 = subStrAt(cmd, 3, ' ');
            int pos2 = subStrAt(cmd, 0, ',');

            string title = cmd.substr(pos1,(pos2-pos1));
            // check every movies 
            for (int i = 0; i < moviesF.size(); i++) {
                if (moviesF[i]->getTitle() == title) {
                    if (cmd[0] == 'B') {                        
                        cus->logTransaction(moviesF[i]->getTitle(), "B");
                        return updateStock(-1, moviesF[i]);
                       
                    }
                    if (cmd[0] == 'R') {
                        cus->logTransaction(moviesF[i]->getTitle(), "R");
                        return updateStock(1, moviesF[i]);
                    }
                }
            }
            
        }
        if (genre == 'D') {
            int pos1 = subStrAt(cmd, 3, ' ');
            int pos2 = subStrAt(cmd, 0, ',');
            string dir = cmd.substr(pos1, (pos2 - pos1));
            
            pos1 = subStrAt(cmd, 0, ',');
            pos2 = subStrAt(cmd, 1, ',');
            string title = cmd.substr(pos1+1, (pos2 - pos1)-1);
            // check every movies 
            for (int i = 0; i < moviesD.size(); i++) {
                if (moviesD[i]->getTitle() == title) {
                    if (cmd[0] == 'B') {
                        cus->logTransaction(moviesD[i]->getTitle(), "B");
                        return updateStock(-1, moviesD[i]);

                    }
                    if (cmd[0] == 'R') {
                        cus->logTransaction(moviesD[i]->getTitle(), "R");
                        return updateStock(1, moviesD[i]);
                    }
                }
            }

        }

        if (genre == 'C') {

            int pos1 = subStrAt(cmd, 3, ' ');
            int pos2 = subStrAt(cmd, 5, ' ');
            string myear = cmd.substr(pos1, (pos2 - pos1));

            pos1 = subStrAt(cmd, 5, ' ');
            pos2 = cmd.length();
            string act = cmd.substr(pos1 + 1, (pos2 - pos1) - 1);
            // check every movies 
            for (int i = 0; i < moviesC.size(); i++) {
                if (moviesC[i]->getActorAndRelease() == (" "+act+myear)) {
                    if (cmd[0] == 'B') {
                        cus->logTransaction(moviesC[i]->getTitle(), "B");
                        return updateStock(-1, moviesC[i]);

                    }
                    if (cmd[0] == 'R') {
                        cus->logTransaction(moviesC[i]->getTitle(), "R");
                        return updateStock(1, moviesC[i]);
                    }
                }
            }

        }


        
    }
    else
    {
        cout << "Invalid command type! " << cmd[0] << endl;
        return false;
    }
    return true;
}


//---------------------------runCommandFile-------------------------------------
// runCommand: run the command from users or files
// precondition: the command file
// postcondition: the command runs. Return false if invalid input.
//--------------------------------------------------------------------------
bool Store::runCommandFile(ifstream & commands)
{
    while (!commands.eof())
    {
        string line;
        getline(commands, line);
        runCommand(line);
    }
   
    return false;
}

//---------------------------showHistory-------------------------------------
// showhistory: check if the ID have the transaction
// precondition: ID
// postcondition: true if there is history, otherwise false
//--------------------------------------------------------------------------
bool Store::showHistory(int id)
{
    //customer's id
    Customer *tmp;

    tmp = customerList.get(id);
    if (tmp->getNumberOfTrans() == 0)
    {
        cout << "No history for : " << tmp->getFirstName() << " "
            << tmp->getLastName() << endl;
        return false;
    }
    else
    {
        tmp->showTransaction();
    }

    return true;
}


//---------------------------printAll--------------------------------------
// printAll: print all customer 
// precondition: input false if you want to print with hashtable view
// postcondition: all customers are printed
//--------------------------------------------------------------------------
void Store::printAllCustomer(bool tableView)
{
    if (!tableView) {
        vector<Customer*> tmp = customerList.getAll();
        for (int i = 0; i < tmp.size(); i++) {
            cout << tmp[i]->getID() << " "
                << tmp[i]->getFirstName() << " "
                << tmp[i]->getLastName() << endl;
        }
    }
    else {
        customerList.printAll();
    }

}

//---------------------------subStrAt--------------------------------------
// subStrAt: get the position of a character in appear times
// precondition: str is orignal, index is time of appearing, sign is char
// postcondition: retuen the position of a character
//--------------------------------------------------------------------------
int Store::subStrAt(string str, int index, char sign)
{
    int count = 0;
    int pos = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == sign) {
            count++;
        }
        if (count == index) {
            pos = i;
        }
    }

    return (pos+1);
}

//---------------------------updataStock--------------------------------------
// updataStock:  updata stock of movies
// precondition: plus is undata in stock, the *src is the movie 
// postcondition: return false when new stock <0, otherwise return true.
//--------------------------------------------------------------------------
bool Store::updateStock(int plus, Movie *src)
{
    int curr_stock = src->getStock();
    int cal = curr_stock + plus;

    if (cal < 0) {
        cout << "Out of stock for" << src->getTitle() << endl;
        return false;
    }
    else {
        src->setStock(cal);
    }

    return true;
}
