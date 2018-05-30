//------------------------------------------------------------------------------
// The object class for comedy movies
// Author: Hien Nguyen, Zeyu Shen
// Comedy Class: inherits the attributes from Movie Class
//------------------------------------------------------------------------------
#include "comedy.h"

//--------------------------------Comedy()--------------------------------------
// Comedy() : default constructor for Comedy class
// precondition : NONE
// postcondition : initialize the private value to NULL
//------------------------------------------------------------------------------
Comedy::Comedy() {

    stock = 0;
    directorName = "";
    title = "";
    releaseYear = 0;
    type = ' ';
    genre = ' ';

    // For testing construction
    // cout << "Default Comedy Class Made" << endl;
}

//----------------------------------Comedy()------------------------------------
// Comedy() : constructor that set the datas for Comedy class using the
//	   	  string in a parameter.
// precondition : NONE
// postcondition : Sets every variables by parsing the string
//------------------------------------------------------------------------------
Comedy::Comedy(const string &line)
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
    // cout << "Comedy Class Made w/ Parameter " << title << endl;
}

//---------------------------Comedy()-------------------------------------------
// Comedy() : constructor that set the datas for Comedy class
// precondition : NONE
// postcondition : initialize the private value to NULL
//------------------------------------------------------------------------------
Comedy::Comedy(int s, string n, string t, int r, char ty, char g) {

    stock = s;
    directorName = n;
    title = t;
    releaseYear = r;
    type = ty;
    genre = g;

    // For testing construction with parameter
    // cout << "Comedy Class Made w/ Parameter" << endl;
}

//------------------------------destructor--------------------------------------
// ~Comedy() : destructor for Comedy class
// precondition : NONE
// postcondition : NONE
//------------------------------------------------------------------------------
Comedy::~Comedy() {
    // For testing destructor
    cout << "Comedy class deleted" << endl;
}

//-------------------------------operator< -------------------------------------
// operator< : operator compares if lhs is less than rhs
// precondition: rhs is a valid Movie type
// postcondition: returns true if *this < rhs; returns false if *this > rhs
//------------------------------------------------------------------------------
bool Comedy::operator<(const Movie & rhs) const {
    return title < rhs.getTitle();
}

//-------------------------------operator>--------------------------------------
// operator>: checks if the lhs is greater than the rhs
// precondition: rhs is a valid Movie type
// postcondition: returns true if *this > rhs; returns false if *this < rhs
//------------------------------------------------------------------------------
bool Comedy::operator>(const Movie & rhs) const {
    return title > rhs.getTitle();
}

//---------------------------------operator==-----------------------------------
// operator==: compares two movies to each other
// precondition: movies exist
// postcondition: returns true if the movies are identical, false otherwise
//------------------------------------------------------------------------------
bool Comedy::operator==(const Movie & rhs) const {
    return title == rhs.getTitle();
}

//------------------------------operator!=--------------------------------------
// operator!=: not equal
// Precondition: none
// Postcondition: return true if not equal rhs, else false
//------------------------------------------------------------------------------
bool Comedy::operator!=(const Movie & rhs) const {
    return title != rhs.getTitle();
}