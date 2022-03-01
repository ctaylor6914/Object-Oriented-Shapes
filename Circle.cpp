#include "Circle.h"

/*
*	FILE			: Square.cpp
*	PROJECT			: Assignment8
*	PROGRAMMER		: Mita Das & Colby Taylor
*	DESCRIPTION		: This file has all of the function definitions of
*                     Circle class.
*/

/**
*	\brief this is default constructor
*	\details this method is used to instantiate a new Circle object with default values
*	\param NONE
*	\returns Nothing
*/
Circle::Circle(void) :Shape()
{
	radius = 0.0;
}

/**
*	\brief this is parameterized constructor
*	\details this method is used to instantiate a new Circle object - given a set of attribute values. Also updates the Shape's colour and name
*	\param newColour String colour of the circle
*	\param newRadius	float radius of the circle
*	\returns Nothing
*/
Circle::Circle(char* newColour, float newRadius):Shape((char*)"Circle", newColour)
{
	if (newRadius < 0.0)
	{
		radius = 0.0;
	}
	else
	{
		radius = newRadius;
	}
}

/**
*	\brief this is Circle Destructor
*	\details to destroy Circle object
*	\param NONE
*	\returns Nothing
*/
Circle::~Circle(void)
{
	printf("\nThe circle is broken ...\n");
}

/**
*	\brief this is a radius variable mutator
*	\details this method sets the radius as per validation logic
*	\param newRadius float
*	\returns status int
*/
int Circle::SetRadius(float newRadius)
{
	if (newRadius < 0.0)
	{
		return 0;
	}
	else
	{
		radius = newRadius;
		return 1;
	}
}

/**
*	\brief this is a radius variable accessor of regular type
*	\details this method returns the radius of the circle. this is regular.
*	\param NONE
*	\returns radius float
*/
float Circle::GetRadius(void)
{
	return radius;
}

/**
*	\brief this is a radius variable accessor of const type
*	\details this method returns the radius of the circle. this is const type
*	\param NONE
*	\returns radius float
*/
float Circle::GetRadius(void) const
{
	return radius;
}

/**	
*   \brief this function prints output
*	\details this method is to be called in order to take a snapshot of the current attribute values of circle
*	\param NONE
*	\returns Nothing											
*/
void Circle::Show(void)
{
	char newName[MAX_NAME_SIZE + 1] = { 0 };
	GetName(newName);
	char newColour[MAX_COLOUR_SIZE + 1] = { 0 };
	GetColour(newColour);

	printf("\nShape Information\n");
	printf("Name            : %s\n", newName);
	printf("Colour          : %s\n", newColour);
	printf("Radius          : %0.2f cm\n", radius);
	printf("Circumference   : %0.2f cm\n", Perimeter());
	printf("Area            : %0.2f square cm\n\n", Area());
}

/**
*	\brief this virtual function calculates Perimeter
*	\details this method returns the Perimeter of the circle
*	\param NONE
*	\returns 2*pi*radius float
*/
float Circle::Perimeter(void)
{
	return (float) (2 * PI_VALUE * radius);
}

/**
*	\brief this virtual function calculates Area
*	\details this method returns the Area of the circle
*	\param NONE
*	\returns pi*radius*radius float
*/
float Circle::Area(void)
{
	return (float) (PI_VALUE * radius * radius);
}

/**
*	\brief this virtual function calculates OverallDimension
*	\details this method returns the OverallDimension of the circle
*	\param NONE
*	\returns 2*radius float
*/
float Circle::OverallDimension(void)
{
	return 2 * radius;
}

/**
*	\brief this is Overloaded add function
*	\details this method performs the overloaded add operation where returning colour is from lhs and returning radius is addition of lhs and rhs
*	\param const Circle& rhs
*	\returns Circle
*/
Circle Circle::operator+(const Circle& rhs)
{
	Circle temp((char*)"undefined", 0.0);

	char newColour[MAX_COLOUR_SIZE + 1] = { 0 };
	this->GetColour(newColour);

	temp.SetColour(newColour);
	temp.SetRadius(this->radius + rhs.radius);

	return temp;
}

/**
*	\brief this is Overloaded multiplication function
*	\details this method performs the overloaded multiplication operation. In this method we assign rhs colour to returning colour and returning radius is multiplication of lhs and rhs radius
*	\param const Circle& rhs
*	\returns Circle
*/
Circle Circle::operator*(const Circle& rhs)
{
	Circle temp((char*)"undefined", 0.0);

	char newColour[MAX_COLOUR_SIZE + 1] = { 0 };
	rhs.GetColour(newColour);

	temp.SetColour(newColour);
	temp.SetRadius(this->radius * rhs.radius);

	return temp;
}

/**
*	\brief this is Overloaded assignment function
*	\details this method performs the overloaded assignment operation where rhs object's attributes are assigned to lhs
*	\param const Circle& rhs
*	\returns const Circle&
*/
const Circle& Circle::operator=(const Circle& rhs)
{
	if (this != &rhs)
	{
		char newColour[MAX_COLOUR_SIZE + 1] = { 0 };
		rhs.GetColour(newColour);
		this->SetColour(newColour);

		char newName[MAX_NAME_SIZE + 1] = { 0 };
		rhs.GetName(newName);
		this->SetName(newName);

		this->SetRadius(rhs.radius);
	}

	return *this;
}

/**
*	\brief this Overloaded equality check function
*	\details this method performs the overloaded equality check operation between two circle objects and returns boolean output. This function also takes into consideration of float no decimal points with AlmostEqualFloats method
*	\param const Circle& rhs
*	\returns bool
*/
bool Circle::operator==(const Circle& rhs)
{
	char newColour2[MAX_COLOUR_SIZE + 1] = { 0 };
	rhs.GetColour(newColour2);
	char newColour1[MAX_COLOUR_SIZE + 1] = { 0 };
	this->GetColour(newColour1);

	if ((AlmostEqualFloats(this->radius, rhs.radius, (float) 0.001)
		== 0) && (strcmp(newColour1, newColour2) == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}