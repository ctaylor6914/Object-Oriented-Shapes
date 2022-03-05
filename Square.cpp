#include "Square.h"

/*
*	FILE			: Square.cpp
*	PROGRAMMER		: Mita Das & Colby Taylor
*	DESCRIPTION		: This file has all of the function definitions of
*                     Square class.
*/

/**
*	\brief this is a Square default constructor
*	\details this method is used to instantiate a new Square object with default values
*	\param NONE
*	\returns Nothing
*/
Square::Square(void) :Shape()
{
	sideLength = 0.0;
}

/**
*	\brief this is a Square parameterized constructor
*	\details this method is used to instantiate a new Square object - given a set of attribute values. Also updates the Square's colour and name
*	\param newColour	String colour of the circle
*	\param newSideLength	float radius of the circle
*	\returns Nothing
*/
Square::Square(char* newColour, float newSideLength) :Shape((char*)"Square", newColour)
{
	if (newSideLength < 0.0)
	{
		sideLength = 0.0;
	}
	else
	{
		sideLength = newSideLength;
	}
}

/**
*	\brief this is a Square destructor
*	\details to destroy Square object
*	\param NONE
*	\returns Nothing
*/
Square::~Square(void)
{
	printf("\nThe square is squished ...\n");
}

/**
*	\brief this is a sideLength variable mutator
*	\details this method sets the side-length as per validation logic
*	\param newSideLength float
*	\returns status int
*/
int Square::SetSideLength(float newSideLength)
{
	if (newSideLength < 0.0)
	{
		return 0;
	}
	else
	{
		sideLength = newSideLength;
		return 1;
	}
}

/**
*	\brief this is a sideLength variable accessor
*	\details this method returns the side-length of the square
*	\param NONE
*	\returns sideLength float
*/
float Square::GetSideLength(void)
{
	return sideLength;
}

/**
*	\brief this function prints output
*	\details this method is to be called in order to take a snapshot of the current attribute values of Square
*	\param NONE
*	\returns Nothing
*/
void Square::Show(void)
{
	char newName[MAX_NAME_SIZE + 1] = { 0 };
	GetName(newName);
	char newColour[MAX_COLOUR_SIZE + 1] = { 0 };
	GetColour(newColour);

	printf("\nShape Information\n");
	printf("Name            : %s\n", newName);
	printf("Colour          : %s\n", newColour);
	printf("Side-Length     : %0.2f cm\n", sideLength);
	printf("Perimeter       : %0.2f cm\n", Perimeter());
	printf("Area            : %0.2f square cm\n\n", Area());
}

/**
*	\brief this virtual function calculates Perimeter
*	\details this method returns the Perimeter of the square
*	\param NONE
*	\returns 2*side-length float
*/
float Square::Perimeter(void)
{
	return 4 * sideLength;
}

/**
*	\brief this virtual function calculates Area
*	\details this method returns the Area of the square
*	\param NONE
*	\returns side-length*side-length float
*/
float Square::Area(void)
{
	return sideLength * sideLength;
}

/**
*	\brief this virtual function calculates OverallDimension
*	\details this method returns the Area of the circle
*	\param NONE
*	\returns side-length float
*/
float Square::OverallDimension(void)
{
	return sideLength;
}

/**
*	\brief this is Overloaded add function
*	\details this method performs the overloaded add operation where returning colour is from lhs and returning sideLength is addition of lhs and rhs
*	\param const Square& rhs
*	\returns Square
*/
Square Square::operator+(const Square& rhs)
{
	Square temp((char*)"undefined", 0.0);

	char newColour[MAX_COLOUR_SIZE + 1] = { 0 };
	this->GetColour(newColour);

	temp.SetColour(newColour);
	temp.SetSideLength(this->sideLength + rhs.sideLength);

	return temp;
}

/**
*	\brief this is Overloaded add function for Square-Circle type
*	\details this method performs the overloaded add operation where lhs is Square, rhs is Circle and the output is CircleSquare type. returning object's colour is from lhs, sidelength is from lhs and radius is from rhs. Throws exception if sideLength is smaller than perimeter
*	\param const Circle& rhs
*	\returns CircleSquare
*/
CircleSquare Square::operator+(const Circle& rhs)
{
	char newColour[MAX_COLOUR_SIZE + 1] = { 0 };
	this->GetColour(newColour);

	char lhsName[MAX_NAME_SIZE + 1] = { 0 };
	this->GetName(lhsName);
	char rhsName[MAX_NAME_SIZE + 1] = { 0 };
	rhs.GetName(rhsName);

	CircleSquare temp;

	temp.SetName(strcat(strcat(lhsName, "-"), rhsName));
	temp.SetColour(newColour);

	temp.SetSideLength(this->GetSideLength());
	temp.SetRadius(rhs.GetRadius());

	if (temp.GetSideLength() < (temp.GetRadius() * 2))
	{
		throw "	>>> SideLength is smaller than the diameter.\n";
	}

	return temp;
}

/**
*	\brief this is Overloaded multiplication function
*	\details this method performs the overloaded multiplication operation. In this method we assign rhs colour to returning colour and returning sideLength is multiplication of lhs and rhs sideLength
*	\param const Square& rhs
*	\returns Square
*/
Square Square::operator*(const Square& rhs)
{
	Square temp((char*)"undefined", 0.0);

	char newColour[MAX_COLOUR_SIZE + 1] = { 0 };
	rhs.GetColour(newColour);

	temp.SetColour(newColour);
	temp.SetSideLength(this->sideLength * rhs.sideLength);

	return temp;
}

/**
*	\brief this is Overloaded assignment function
*	\details this method performs the overloaded assignment operation where rhs object's attributes are assigned to lhs
*	\param const Square& rhs
*	\returns const Square&
*/
const Square& Square::operator=(const Square& rhs)
{
	if (this != &rhs)
	{
		char newColour[MAX_COLOUR_SIZE + 1] = { 0 };
		rhs.GetColour(newColour);
		this->SetColour(newColour);

		char newName[MAX_NAME_SIZE + 1] = { 0 };
		rhs.GetName(newName);
		this->SetName(newName);

		this->SetSideLength(rhs.sideLength);
	}

	return *this;
}

/**
*	\brief this is Overloaded equality check function
*	\details this method performs the overloaded equality check operation between two circle objects and returns boolean output. This function also takes into consideration of float no decimal points with AlmostEqualFloats method
*	\param const Square& rhs
*	\returns bool
*/
bool Square::operator==(const Square& rhs)
{
	char newColour2[MAX_COLOUR_SIZE + 1] = { 0 };
	rhs.GetColour(newColour2);
	char newColour1[MAX_COLOUR_SIZE + 1] = { 0 };
	this->GetColour(newColour1);

	if ((AlmostEqualFloats(this->sideLength, rhs.sideLength, (float)0.001)
		== 0) && (strcmp(newColour1, newColour2) == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

