//------------------------------------------------------------------------------
// The object class for comedy movies
// Author: Hien Nguyen, Zeyu Shen
// Comedy Class: inherits the attributes from Movie Class
//------------------------------------------------------------------------------
#pragma once
#include "movie.h"

class Comedy : public Movie {

public:

    //--------------------------------Comedy()----------------------------------
    // Comedy() : default constructor for Comedy class
    // precondition : NONE
    // postcondition : initialize the private value to NULL
    //--------------------------------------------------------------------------
    Comedy();

    //--------------------------------Comedy()----------------------------------
    // Comedy() : constructor that set the datas for Comedy class using the
    //	   	  string in a parameter.
    // precondition : NONE
    // postcondition : Sets every variables by parsing the string
    //--------------------------------------------------------------------------
    Comedy(const string &line);

    //--------------------------------Comedy()----------------------------------
    // Comedy() : constructor that set the datas for Comedy class using the
    //	   	  variables given in the parameter
    // precondition : NONE
    // postcondition : Sets every variables with given parameter
    //--------------------------------------------------------------------------
    Comedy(int stock, string name, string title,
        int release, char type, char genre);

    //------------------------------destructor----------------------------------
    // ~Comedy() : destructor for Comedy class
    // precondition : NONE
    // postcondition : NONE
    //--------------------------------------------------------------------------
    virtual ~Comedy();

    //-------------------------------operator<----------------------------------
    // operator< : operator that compares if lhs is less than rhs
    // precondition: rhs is a valid Movie type
    // postcondition: returns true if *this < rhs; returns false if *this > rhs
    //--------------------------------------------------------------------------
    virtual bool operator<(const Movie &rhs) const;

    //--------------------------------operator>---------------------------------
    // operator>: checks if the lhs is greater than the rhs
    // precondition: rhs is a valid Movie type
    // postcondition: returns true if *this > rhs; returns false if *this < rhs
    //--------------------------------------------------------------------------
    virtual bool operator>(const Movie &rhs) const;

    //---------------------------------operator==-------------------------------
    // operator==: compares two movies to each other
    // precondition: movies exist
    // postcondition: returns true if the movies are identical, false otherwise
    //--------------------------------------------------------------------------
    virtual bool operator==(const Movie &rhs) const;

    //------------------------------operator!=----------------------------------
    // operator!=: not equal
    // Precondition: none
    // Postcondition: return true if not equal rhs, else false
    //--------------------------------------------------------------------------
    virtual bool operator!=(const Movie &rhs) const;

};
