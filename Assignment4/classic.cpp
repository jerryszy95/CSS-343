//------------------------------------------------------------------------------
// classic.h
// object class for classic movies
// Author: Hien Nguyen, Zeyu Shen
// Classic Class inherits the attributes from Movie Class
//------------------------------------------------------------------------------
#include "classic.h"

//--------------------------------Classic-----------------------------------
// constructor : default constructor for Classic class
// precondition : NONE
// postcondition : initialize the private value to NULL
//--------------------------------------------------------------------------
Classic::Classic() {

    stock = 0;
    directorName = "";
    title = "";
    actorAndRelease = "";
    releaseYear = 0;
    type = ' ';
    genre = ' ';

    // For testing construction
    //cout << "Default Classic Class Made" << endl;
}

//--------------------------------Classic-----------------------------------
// constructor : constructor that set the datas for Classic class using the
//	       string in a parameter.
// precondition : NONE
// postcondition : Sets every variables by parsing the string
//--------------------------------------------------------------------------
Classic::Classic(const string &line)
{
    string s = line;
    string delimiter = ", ";

    size_t pos = 0;
    string token;
    int i = 0;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        if (i == 0) {
            type = token[0];
        }
        else if (i == 1) {
            stock = atoi(token.c_str());
        }
        else if (i == 2) {
            directorName = token;
        }
        else if (i == 3) {
            title = token;
        }
        else if (i == 4) {
            actorAndRelease = token;
        }
        i++;
        //cout << token << endl;
        s.erase(0, pos + delimiter.length());
    }
    actorAndRelease = s;
    //cout << s << endl;


    // For testing construction
    //cout << "Classic Class Made w/ Parameter " << releaseYear << endl;
}

//--------------------------------Classic-----------------------------------
// constructor : constructor that set the datas for Classic class
// precondition : NONE
// postcondition : initialize the private value to NULL
//--------------------------------------------------------------------------
Classic::Classic(int s, string n, string t, string a, int r, char ty, char g) {

    stock = s;
    directorName = n;
    title = t;
    actorAndRelease = a;
    releaseYear = r;
    type = ty;
    genre = g;

    // For testing construction with parameter
    //cout << "Classic Class Made w/ Parameter" << endl;
}

//-------------------------------destructor---------------------------------
// ~Classic() : destructor for Classic class
// precondition : NONE
// postcondition : NONE
//--------------------------------------------------------------------------
Classic::~Classic() {

    // For testing destructor
    // cout << "Classic class deleted" << endl;
}

//------------------------setActorAndRelease--------------------------------
// setActorName: sets actor's name and release date
// precondition: s is a valid string object
// postconditon: the actor’s first name of a movie is store set
//--------------------------------------------------------------------------
void Classic::setActorAndRelease(string a) {
    actorAndRelease = a;
}

//------------------------getActorAndRelease------------------------------------
// getTitle: returns actor's name and release date
// precondition: None
// postconditon: the actor name is returned
//------------------------------------------------------------------------------
string Classic::getActorAndRelease() {
    return actorAndRelease;
}

//----------------------------operator<-------------------------------------
// operator< : operator that compares if lhs is less than rhs
// precondition: rhs is a valid Movie type
// postcondition: returns true if *this < rhs; returns false if *this > rhs
//--------------------------------------------------------------------------
bool Classic::operator<(Classic & rhs) const {
    return actorAndRelease < rhs.getActorAndRelease();
}

///--------------------------------------------------------------------------
// operator>: checks if the lhs is greater than the rhs
// precondition: rhs is a valid Movie type
// postcondition: returns true if *this > rhs; returns false if *this < rhs
//---------------------------operator>--------------------------------------
bool Classic::operator>(Classic & rhs) const {
    return actorAndRelease > rhs.getActorAndRelease();
}

//---------------------------------operator==-----------------------------------
// operator==: compares two movies to each other
// precondition: movies exist
// postcondition: returns true if the movies are identical, false otherwise
//------------------------------------------------------------------------------
bool Classic::operator==(Classic & rhs) const {
    return actorAndRelease == rhs.getActorAndRelease();
}

//------------------------------operator!=--------------------------------------
// operator!=: not equal
// Precondition: none
// Postcondition: return true if not equal rhs, else false
//------------------------------------------------------------------------------
bool Classic::operator!=(Classic & rhs) const {
    return actorAndRelease != rhs.getActorAndRelease();
}
