#include "movie.h"

//-------------------------------Movie()----------------------------------------
// Default constructor
// precondition: None
// postconditon: a default movie class is constructed
//------------------------------------------------------------------------------
Movie::Movie() {

	stock = 0;
	directorName = "";
	title = "";
	releaseYear = 0;
	type = ' ';
	genre = ' ';

	// For testing construction
	// cout << "Default Movie Class Made" << endl;

}

//-------------------------------Movie()----------------------------------------
// Constructor with parameters
// precondition: the arguments in the parameter are valid
// postconditon: a movie with valid parametersd is initialized
//------------------------------------------------------------------------------
Movie::Movie(int s, string n, string t, int r, char mt, char g) {

	stock = s;
	directorName = n;
	title = t;
	releaseYear = r;
	type = mt;
	genre = g;

	// For testing construction with parameter
	// cout << "Movie Class Made w/ Parameter" << endl;

}

//------------------------------Destructor--------------------------------------
// Destructor: destruct the movie class
// precondition: a constructed movie existed
// postconditon: NONE
//------------------------------------------------------------------------------
Movie::~Movie() {

	// For testing destructor
	// cout << "Movie class deleted" << endl;
}

//-------------------------------getStock---------------------------------------
// getStock: counts and returns the number of all available movies in the store
// precondition: none
// postconditon: the number of movies in the store returned
//------------------------------------------------------------------------------
int Movie::getStock() const {
	return stock;
}

//------------------------------setStock----------------------------------------
// setStock: sets the number of movies in the store
// precondition: s is a valid integer number
// postconditon: the number of movies in the store set
//------------------------------------------------------------------------------
void Movie::setStock(int s) {
	stock = s;
}

//------------------------------getType-----------------------------------------
// getType: return the type of a movie
// precondition: none
// postcondition: the type of a movie is returned
//------------------------------------------------------------------------------
char Movie::getType() const {
	return type;
}

//----------------------------setType-------------------------------------------
// setType: sets the type of a movie
// precondition: c is a valid char character
// postconditon: the type of a movie is store set
//------------------------------------------------------------------------------
void Movie::setType(char t) {
	type = t;
}

//------------------------------getGenre----------------------------------------
// getGenre: return the genre of a movie
// precondition: none
// postcondition: the genre of a movie is returned
//------------------------------------------------------------------------------
char Movie::getGenre() const {
	return genre;
}

//-------------------------------setGenre---------------------------------------
// setGenre: sets the genre of a movie
// precondition: genre is a valid char character
// postconditon: the type of genre is store set
//------------------------------------------------------------------------------
void Movie::setGenre(char g) {
	genre = g;
}

//------------------------------getDirName--------------------------------------
// getDirFirstName: returns a movie¡¯s director name
// precondition: None
// postconditon: the movies director first name returned
//------------------------------------------------------------------------------
string Movie::getDirName() const {
	return directorName;
}

//------------------------------setDirName--------------------------------------
// setDirFirstName: sets the director¡¯s first name
// precondition: s is a valid string
// postconditon: the director¡¯s first name isset
//------------------------------------------------------------------------------
void Movie::setDirName(string fn) {
	directorName = fn;
}

//-------------------------------getTitle---------------------------------------
// getTitle: returns a movie title
// precondition: None
// postcondition: the movies title is returned
//------------------------------------------------------------------------------
string Movie::getTitle() const {
	return title;
}

//-------------------------------setTitle---------------------------------------
// setTitle: sets the movie title
// precondition: s is a valid movie title
// postcondition: the director¡¯s last name is set
//------------------------------------------------------------------------------
void Movie::setTitle(string t) {
	title = t;
}

//------------------------------getReleaseYear----------------------------------
// getReleaseYear: returns the release year
// precondition: None
// postcondition: the release year is returned
//------------------------------------------------------------------------------
int Movie::getReleaseYear() const {
	return releaseYear;
}

//-----------------------------setReleaseYear-----------------------------------
// setReleaseYear: sets the release year of the move
// precondition: year is a valid integer number > 1900
// postcondition: the release year of a movie is returned
//------------------------------------------------------------------------------
void Movie::setReleaseYear(int r) {
	releaseYear = r;
}

//-----------------------------getActorAndRelease-------------------------------
// getActorAndRelease: returns a string with actor and release month , year
// precondition: none
// postcondition: returns a string with actor and release month , year
//--------------------------------------------------------------------------
string Movie::getActorAndRelease() const
{
	return actorAndRelease;
}

//-----------------------------setActorAndRelease-------------------------------
// setActorAndRelease: sets actor and release month , year
// precondition: string is not empty
// postcondition: actorAndRelease is assigned
//--------------------------------------------------------------------------
void Movie::setActorAndRelease(string ar)
{
	actorAndRelease = ar;
}

// overload operators, for comparing movies in order to store the movies
//------------------------------operator<---------------------------------------
// operator< : operator that compares if lhs is less than rhs
// precondition: rhs is a valid Movie type
// postcondition: returns true if *this < rhs; returns false if *this > rhs
//------------------------------------------------------------------------------
bool Movie::operator<(const Movie & rhs) const {
	return false;
}

//------------------------------operator>---------------------------------------
// operator>: checks if the lhs is greater than the rhs
// precondition: rhs is a valid Movie type
// postcondition: returns true if *this > rhs; returns false if *this < rhs
//------------------------------------------------------------------------------
bool Movie::operator>(const Movie & rhs) const {
	return false;
}

//------------------------------operator==--------------------------------------
// operator==: compares two movies to each other
// precondition: movies exist
// postcondition: returns true if the movies are identical, false otherwise
//------------------------------------------------------------------------------
bool Movie::operator==(const Movie & rhs) const {
	return false;
}

//------------------------------operator!=--------------------------------------
// operator!=: not equal
// Precondition: none
// Postcondition: return true if not equal rhs, else false
//------------------------------------------------------------------------------
bool Movie::operator!=(const Movie & rhs) const {
	return false;
}

//------------------------------operator<<--------------------------------------
// operator<<: prints the movie title
// Precondition: include <iostream>
// Postcondition: returns the title of the movie
//------------------------------------------------------------------------------
ostream & operator<<(ostream &o, const Movie &m) {
	o << m.getTitle() << endl;
	return o;
}
