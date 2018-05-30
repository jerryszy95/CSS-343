//------------------------------------------------------------------------------
// object class for Drama movies
// Author: Hien Nguyen, Zeyu Shen
// Drama Class: inherits the attributes from Movie Class
//------------------------------------------------------------------------------
#include "drama.h"

//--------------------------------Drama --------------------------------------
// Drama() : default constructor for Comedy class
// precondition : NONE
// postcondition : initialize the private value to NULL
//------------------------------------------------------------------------------
Drama::Drama() {

    stock = 0;
    directorName = "";
    title = "";
    releaseYear = 0;
    type = ' ';
    genre = ' ';

    // For testing construction
    // cout << "Default Drama Class Made" << endl;
}

//------------------------------------------------------------------------------
// Drama : constructor that set the datas for Drama class using the
//	     string in a parameter.
// precondition : NONE
// postcondition : Sets every variables by parsing the string
//------------------------------------------------------------------------------
Drama::Drama(const string &line)
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
            releaseYear = atoi(token.c_str());
        }
        i++;
        //cout << token << endl;
        s.erase(0, pos + delimiter.length());
    }
    releaseYear = (atoi(s.c_str()));
    //cout << s << endl;


    // For testing construction
    // cout << "Drama Class Made w/ Parameter " << title << endl;
}

//------------------------------------------------------------------------------
// Drama() : constructor that set the datas for Drama class
// precondition : NONE
// postcondition : initialize the private value to NULL
//------------------------------------------------------------------------------
Drama::Drama(int s, string n, string t, int r, char ty, char g) {

    stock = s;
    directorName = n;
    title = t;
    releaseYear = r;
    type = ty;
    genre = g;

    // For testing construction with parameter
    // cout << "Drama Class Made w/ Parameter" << endl;
}

//------------------------------------------------------------------------------
// ~Drama() : destructor for Drama class
// precondition : NONE
// postcondition : NONE
//------------------------------------------------------------------------------
Drama::~Drama() {

    // For testing destructor
    cout << "Drama class deleted" << endl;
}

//------------------------------------------------------------------------------
// operator< : operator that compares if lhs is less than rhs
// precondition: rhs is a valid Movie type
// postcondition: returns true if *this < rhs; returns false if *this > rhs
//------------------------------------------------------------------------------
bool Drama::operator<(const Movie & rhs) const {
    return directorName < rhs.getDirName();
}

//------------------------------------------------------------------------------
// operator>: checks if the lhs is greater than the rhs
// precondition: rhs is a valid Movie type
// postcondition: returns true if *this > rhs; returns false if *this < rhs
//------------------------------------------------------------------------------
bool Drama::operator>(const Movie & rhs) const {
    return directorName > rhs.getDirName();
}

//---------------------------------operator==-----------------------------------
// operator==: compares two movies to each other
// precondition: movies exist
// postcondition: returns true if the movies are identical, false otherwise
//------------------------------------------------------------------------------
bool Drama::operator==(const Movie & rhs) const {
    return directorName == rhs.getDirName();
}

//------------------------------operator!=--------------------------------------
// operator!=: not equal
// Precondition: none
// Postcondition: return true if not equal rhs, else false
//------------------------------------------------------------------------------
bool Drama::operator!=(const Movie & rhs) const {
    return directorName != rhs.getDirName();
}