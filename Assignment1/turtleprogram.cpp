#include "turtleprogram.h"
#include <iostream>

using namespace std;


//default constructor
TurtleProgram::TurtleProgram()
{
    TurtleLength=0;
    TurtleArray=NULL;
}
//constructor with 2 string input
TurtleProgram::TurtleProgram(string degree, string value)
{
    TurtleLength = 2;
    TurtleArray = new string[2];
    TurtleArray[0] = degree;
    TurtleArray[1] = value;
}

//copy constructor
TurtleProgram::TurtleProgram(const TurtleProgram& turtle)
{
    TurtleLength = turtle.TurtleLength;
    TurtleArray = new string[TurtleLength];
    for (int i = 0; i < TurtleLength; i++)
    {
        TurtleArray[i] = turtle.TurtleArray[i];
    }
}
//destructor
TurtleProgram::~TurtleProgram()
{
    delete[] TurtleArray;
}

//public funcition that use to access to the private data
string TurtleProgram::getIndex(int index) const
{
    return TurtleArray[index];
}

int TurtleProgram::getLength() const
{
    return TurtleLength;
}

void TurtleProgram::setIndex(int index, string value)
{
    TurtleArray[index] = value;
}

void TurtleProgram::setLength(int length)
{
    TurtleLength = length;
}

//comparison boolean function
bool TurtleProgram::operator==(const TurtleProgram& turtle) const
{
    if(getLength()==turtle.getLength())
    {
        for(int i=0; i<getLength();i++)
        {
            if(TurtleArray[i]!=turtle.TurtleArray[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool TurtleProgram::operator!=(const TurtleProgram& turtle) const
{
    if (turtle == *this)
        return false;
    else
        return true;
}

//assignment operator
TurtleProgram &TurtleProgram::operator=(const TurtleProgram& turtle)
{
    setLength(turtle.getLength());
    delete[] TurtleArray;
    TurtleArray = new string[TurtleLength];
    for (int i = 0; i < TurtleLength; i++)
    {
        TurtleArray[i] = turtle.TurtleArray[i];
    }
    return *this;
}

//operator+ overloads
TurtleProgram TurtleProgram::operator+(TurtleProgram& turtle)
{
    TurtleProgram Result;
    int newlength = turtle.TurtleLength + TurtleLength;
    Result.setLength(newlength);
    Result.TurtleArray = new string[newlength];
    for (int i = 0; i < TurtleLength; i++)
    {
        Result.TurtleArray[i] = this->TurtleArray[i];
    }
    for (int i = 0; i < turtle.TurtleLength; i++)
    {
        Result.TurtleArray[i + TurtleLength] = turtle.TurtleArray[i];
    }
    return Result;
}

//operator+= overloads
TurtleProgram TurtleProgram::operator+=(TurtleProgram& turtle)
{
    return *this = *this + turtle;
}

//operator* overloads
TurtleProgram TurtleProgram::operator*(int times)
{
    TurtleProgram Result;
    for (int x = 0; x < times; x++)
    {
        Result += *this;
    }
    return Result;
}

//operator*= overloads
TurtleProgram TurtleProgram::operator*=(int times)
{
    TurtleProgram temp = *this;
    for (int x = 0; x < times-1; x++)
    {
        *this += temp;
    }
    return *this;
}

//ostream operator<<
ostream& operator<< (ostream& out, const TurtleProgram& turtle)
{
    out<<"[";
    for (int i = 0; i < turtle.getLength(); i++)
    {
        out << turtle.getIndex(i);
        if(i+1<turtle.getLength())
            out << " ";
    }
    out<<"]";
    return out;
}
