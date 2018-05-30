#include<string>
#include <iostream>

using namespace std;

class TurtleProgram
{
public:
    TurtleProgram();                                //default constructor
    TurtleProgram(string degree, string value);     //constructor with two string parameters
    TurtleProgram(const TurtleProgram& turtle);     //copy constructor
    ~TurtleProgram();                               //destructor
    
    string getIndex(int index) const;               //return the value in TurtleArray[index]
    int getLength() const;                          //return TurtleLength
    void setIndex(int index, string action);        //change the value in TurtleArray[index]
    void setLength(int lng);                        //change the TurtleLength
    
    bool operator==(const TurtleProgram& turtle) const;     //return true when two TurtleProgram are same
    bool operator!=(const TurtleProgram& turtle) const;     //return true when two TurtleProgram are different
    
    TurtleProgram &operator=(const TurtleProgram& turtle);  //override operator =
    TurtleProgram operator+(TurtleProgram& turtle);         //override operator +
    TurtleProgram operator+=(TurtleProgram& turtle);        //override operator +=
    TurtleProgram operator*(int multiplier);                //override operator *
    TurtleProgram operator*=(int multiplier);               //override operator *=
    
private:
    string* TurtleArray;
    int TurtleLength;
};
ostream& operator<< (ostream& out, const TurtleProgram& turtle); //override operator<<
