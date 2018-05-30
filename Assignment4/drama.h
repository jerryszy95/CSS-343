//------------------------------------------------------------------------------
// object class for Drama movies
// Author: Hien Nguyen, Zeyu Shen
// Drama Class: inherits the attributes from Movie Class
//------------------------------------------------------------------------------
#pragma once
#include "movie.h"


class Drama : public Movie {

public:

    //--------------------------------Drama()-----------------------------------
    // Drama() : default constructor for Drama class
    // precondition : NONE
    // postcondition : initialize the private value to NULL
    //--------------------------------------------------------------------------
    Drama();

    //----------------------------------Drama()---------------------------------
    // Drama() : constructor that set the datas for Drama class using the
    //	     string in a parameter.
    // precondition : NONE
    // postcondition : Sets every variables by parsing the string
    //--------------------------------------------------------------------------
    Drama(const string &line);

    //--------------------------------Drama()-----------------------------------
    // Drama() : constructor that set the datas for Drama class
    // precondition : NONE
    // postcondition : initialize the private value to NULL
    //--------------------------------------------------------------------------
    Drama(int stock, string name, string title,
        int release, char type, char genre);

    //---------------------------------destructor-------------------------------
    // ~Drama() : destructor for Drama class
    // precondition : NONE
    // postcondition : NONE
    //--------------------------------------------------------------------------
    virtual ~Drama();

    //--------------------------------operator<---------------------------------
    // operator< : operator that compares if lhs is less than rhs
    // precondition: rhs is a valid Movie type
    // postcondition: returns true if *this < rhs; returns false if *this > rhs
    //--------------------------------------------------------------------------
    virtual bool operator<(const Movie &rhs) const;

    //---------------------------------operator>--------------------------------
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
