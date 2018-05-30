//------------------------------------------------------------------------------
// classic.h
// object class for classic movies
// Author: Hien Nguyen, Zeyu Shen
// Classic Class inherits the attributes from Movie Class
//------------------------------------------------------------------------------
#pragma once
#include "movie.h"

class Classic : public Movie {

public:

    //--------------------------------Classic-----------------------------------
    // constructor : default constructor for Classic class
    // precondition : NONE
    // postcondition : initialize the private value to NULL
    //--------------------------------------------------------------------------
    Classic();

    //--------------------------------Classic-----------------------------------
    // constructor : constructor that set the datas for Classic class using the
    //	       string in a parameter.
    // precondition : NONE
    // postcondition : Sets every variables by parsing the string
    //--------------------------------------------------------------------------
    Classic(const string &line);

    //--------------------------------Classic-----------------------------------
    // constructor : constructor that set the datas for Classic class
    // precondition : NONE
    // postcondition : initialize the private value to NULL
    //--------------------------------------------------------------------------
    Classic(int stock, string name, string title, string actorAndRelease,
        int release, char type, char genre);

    //-------------------------------destructor---------------------------------
    // ~Classic() : destructor for Classic class
    // precondition : NONE
    // postcondition : NONE
    //--------------------------------------------------------------------------
    virtual ~Classic();

    //------------------------setActorAndRelease--------------------------------
    // setActorName: sets actor's name and release date
    // precondition: s is a valid string object
    // postconditon: the actor’s first name of a movie is store set
    //--------------------------------------------------------------------------
    void setActorAndRelease(string s);

    //------------------------getActorAndRelease--------------------------------
    // getActorAndRelease: returns actor's name and release date
    // precondition: None
    // postconditon: the actor name and release data returned
    //--------------------------------------------------------------------------
    string getActorAndRelease();

    //----------------------------operator<-------------------------------------
    // operator< : operator that compares if lhs is less than rhs
    // precondition: rhs is a valid Movie type
    // postcondition: returns true if *this < rhs; returns false if *this > rhs
    //--------------------------------------------------------------------------
    bool operator<(Classic & rhs) const;

    //--------------------------------------------------------------------------
    // operator>: checks if the lhs is greater than the rhs
    // precondition: rhs is a valid Movie type
    // postcondition: returns true if *this > rhs; returns false if *this < rhs
    //---------------------------operator>--------------------------------------
    bool operator>(Classic & rhs) const;

    //---------------------------------operator==-------------------------------
    // operator==: compares two movies to each other
    // precondition: movies exist
    // postcondition: returns true if the movies are identical, false otherwise
    //--------------------------------------------------------------------------
    bool operator==(Classic & rhs) const;

    //------------------------------operator!=----------------------------------
    // operator!=: not equal
    // Precondition: none
    // Postcondition: return true if not equal rhs, else false
    //--------------------------------------------------------------------------
    bool operator!=(Classic & rhs) const;


private:

    //string actorAndRelease; // First name of actor

};