
//------------------------------------------------------------------------------
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class Movie {

	// overloading operator
	friend ostream& operator<<(ostream &, const Movie &);

public:

	//-------------------------------Movie()------------------------------------
	// Default constructor
	// precondition: None
	// postconditon: a default movie class is constructed
	//--------------------------------------------------------------------------
	Movie();

	//-------------------------------Movie()------------------------------------
	// Constructor with parameters
	// precondition: the arguments in the parameter are valid
	// postconditon: a movie with valid parametersd is initialized
	//--------------------------------------------------------------------------
	Movie(int stock, string name, string title, 
			int release, char type, char genre);

	//------------------------------Destructor----------------------------------
	// Destructor: destruct the movie class
	// precondition: a constructed movie existed
	// postconditon: NONE
	//--------------------------------------------------------------------------
	~Movie();

	//-------------------------------getStock-----------------------------------
	// getStock: counts and returns the number of all available 
	//			 movies in the store
	// precondition: none
	// postconditon: the number of movies in the store returned
	//--------------------------------------------------------------------------
	int getStock() const;

	//------------------------------setStock------------------------------------
	// setStock: sets the number of movies in the store
	// precondition: s is a valid integer number
	// postconditon: the number of movies in the store set
	//--------------------------------------------------------------------------
	void setStock(int s);

	//------------------------------getType-------------------------------------
	// getType: return the type of a movie
	// precondition: none
	// postcondition: the type of a movie is returned
	//--------------------------------------------------------------------------
	char getType() const;

	//----------------------------setType---------------------------------------
	// setType: sets the type of a movie
	// precondition: c is a valid char character
	// postconditon: the type of a movie is store set
	//--------------------------------------------------------------------------
	void setType(char t);

	//------------------------------getGenre------------------------------------
	// getGenre: return the genre of a movie
	// precondition: none
	// postcondition: the genre of a movie is returned
	//--------------------------------------------------------------------------
	char getGenre() const;

	//-------------------------------setGenre-----------------------------------
	// setGenre: sets the genre of a movie
	// precondition: genre is a valid char character
	// postconditon: the type of genre is store set
	//--------------------------------------------------------------------------
	void setGenre(char g);

	//------------------------------getDirName----------------------------------
	// getDirFirstName: returns a movie’s director first name
	// precondition: None
	// postconditon: the movies director first name returned
	//--------------------------------------------------------------------------
	string getDirName() const;

	//------------------------------setDirName----------------------------------
	// setDirFirstName: sets the director’s first name
	// precondition: s is a valid string
	// postconditon: the director’s first name isset
	//--------------------------------------------------------------------------
	void setDirName(string fn);

	//-------------------------------getTitle-----------------------------------
	// getTitle: returns a movie title
	// precondition: None
	// postcondition: the movies title is returned
	//--------------------------------------------------------------------------
	string getTitle() const;

	//-------------------------------setTitle-----------------------------------
	// setTitle: sets the movie title
	// precondition: s is a valid movie title
	// postcondition: the director’s last name is set
	//--------------------------------------------------------------------------
	void setTitle(string t);

	//------------------------------getReleaseYear------------------------------
	// getReleaseYear: returns the release year
	// precondition: None
	// postcondition: the release year is returned
	//--------------------------------------------------------------------------
	int getReleaseYear() const;

	//-----------------------------setReleaseYear-------------------------------
	// setReleaseYear: sets the release year of the move
	// precondition: year is a valid integer number > 1900
	// postcondition: the release year of a movie is returned
	//--------------------------------------------------------------------------
	void setReleaseYear(int r);

	//-----------------------------getActorAndRelease-------------------------------
	// getActorAndRelease: returns a string with actor and release month , year
	// precondition: none
	// postcondition: returns a string with actor and release month , year
	//--------------------------------------------------------------------------
	virtual string getActorAndRelease() const;

	//-----------------------------setActorAndRelease-------------------------------
	// setActorAndRelease: sets actor and release month , year
	// precondition: string is not empty
	// postcondition: actorAndRelease is assigned
	//--------------------------------------------------------------------------
	virtual void setActorAndRelease(string ar);

	// overload operators, for comparing movies in order to store the movies
	//------------------------------operator<-----------------------------------
	// operator< : operator that compares if lhs is less than rhs
	// precondition: rhs is a valid Movie type
	// postcondition: returns true if *this < rhs; returns false if *this > rhs
	//--------------------------------------------------------------------------
	virtual bool operator<(const Movie &rhs) const;

	//------------------------------operator>-----------------------------------
	// operator>: checks if the lhs is greater than the rhs
	// precondition: rhs is a valid Movie type
	// postcondition: returns true if *this > rhs; returns false if *this < rhs
	//--------------------------------------------------------------------------
	virtual bool operator>(const Movie &rhs) const;

	//------------------------------operator==----------------------------------
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

protected:

	char type; // Holds type of Media
	char genre; // movie genre
	int stock; // number of movies available
	string directorName; // Director's name
	string title; // Movie title
	int releaseYear; // Movie release year
	string actorAndRelease; // used for Classical

};
