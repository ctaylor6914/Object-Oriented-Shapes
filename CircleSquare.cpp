#include "CircleSquare.h"

/*
*	FILE			: CircleSquare.cpp
*	PROGRAMMER		: Mita Das & Colby Taylor
*	DESCRIPTION		: This file has all of the function definitions of
*                     CircleSquare class.
*/

/**
*	\brief this is a CircleSquare default constructor
*	\details This method is used to instantiate a new CircleSquare object with default values and updates shape's name and colour
*	\param NONE
*	\returns Nothing
*/
CircleSquare::CircleSquare(void):Shape((char*)"Circle-Square",(char*)"undefined")
{
	sideLength = 0.0;
	radius = 0.0;
}

/**
*	\brief this is a CircleSquare parameterized constructor
*	\details This method is used to instantiate a new CircleSquare object - given a set of attribute values. Also updates the Shape's colour and name
*	\param newColour	String colour of the CircleSquare
*	\param newRadius	float radius of the CircleSquare
*	\param newSideLength	float side length of the CircleSquare
*	\param newName	String name of the CircleSquare
*	\returns Nothing
*/
CircleSquare::CircleSquare(char* newColor, float newRadius,	
	float newSideLength, char* newName):Shape(newName, newColor)
{
	char checkName[MAX_NAME_SIZE + 1] = { 0 };

	if (strcmp(newName, (char*)"Circle-Square") != 0 && 
		strcmp(newName, (char*)"Square-Circle") != 0)
	{
		SetName((char*)"Circle-Square");
	}

	GetName(checkName);

	if (strcmp(checkName, "Circle-Square") == 0)
	{
		if (newSideLength < 0.0)
		{
			sideLength = 0.0;
		}
		else
		{
			sideLength = newSideLength;
		}

		if (newRadius < 0.0)
		{
			radius = 0.0;
		}
		else
		{
			float diameter = 2 * newRadius;
			if (diameter >= sideLength)
			{
				radius = newRadius;
			}
			else
			{
				diameter = (float) (1.5 * sideLength);
				radius = (float) (diameter / 2);
			}
		}
	}
	else if (strcmp(checkName, "Square-Circle") == 0)
	{
		if (newRadius < 0.0)
		{
			radius = 0.0;
		}
		else
		{
			radius = newRadius;
		}

		if (newSideLength < 0.0)
		{
			sideLength = 0.0;
		}
		else
		{
			float diameter = 2 * radius;
			if (newSideLength >= diameter)
			{
				sideLength = newSideLength;
			}
			else
			{
				sideLength = (float) (1.5 * diameter);
			}
		}
	}
	else
	{
		sideLength = 0.0;
		radius = 0.0;
	}
}

/**
*	\brief this is a CircleSquare Destructor
*	\details to destroy CircleSquare object and prints that object is destroyed
*	\param NONE
*	\returns Nothing
*/
CircleSquare::~CircleSquare(void)
{
	printf("\nClosing the CircleSquare Ranch ...\n\n");
}

/**
*	\brief this is a radius variable accessor
*	\details this method returns the radius of the circle
*	\param NONE
*	\returns radius float
*/
float CircleSquare::GetRadius(void)
{
	return radius;
}

/**
*	\brief this is a sideLength variable accessor
*	\details this method returns the side-length of the square
*	\param NONE
*	\returns sideLength float
*/
float CircleSquare::GetSideLength(void)
{
	return sideLength;
}

/**
*	\brief this is a radius variable mutator
*	\details this method sets the radius as per validation logic of different types of CircleSquare
*	\param newRadius float
*	\returns status void
*/
void CircleSquare::SetRadius(float newRadius)
{
	char newName[MAX_NAME_SIZE + 1] = { 0 };
	GetName(newName);

	if (strcmp(newName, "Circle-Square") == 0)
	{
		if (newRadius < 0.0)
		{
			radius = 0.0;
		}
		else
		{
			float diameter = 2 * newRadius;
			if (diameter >= sideLength)
			{
				radius = newRadius;
			}
			else
			{
				diameter = (float) (1.5 * sideLength);
				radius = (float) (diameter / 2);
			}
		}
	}
	else if (strcmp(newName, "Square-Circle") == 0)
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
}

/**
*	\brief this is a sideLength variable mutator
*	\details this method sets the side-length as per validation logic of different types of CircleSquare
*	\param newSideLength float
*	\returns status void
*/
void CircleSquare::SetSideLength(float newSideLength)
{
	char newName[MAX_NAME_SIZE + 1] = { 0 };
	GetName(newName);

	if (strcmp(newName, "Circle-Square") == 0)
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
	else if (strcmp(newName, "Square-Circle") == 0)
	{
		if (newSideLength < 0.0)
		{
			sideLength = 0.0;
		}
		else
		{
			float diameter = 2 * radius;
			if (newSideLength >= diameter)
			{
				sideLength = newSideLength;
			}
			else
			{
				sideLength = (float) (1.5 * diameter);
			}
		}
	}
}

/**
*	\brief this virtual function calculates Perimeter
*	\details this method returns the Perimeter of the object based on different types of CircleSquare
*	\param NONE
*	\returns float perimeter of the object
*/
float CircleSquare::Perimeter(void)
{
	char newName[MAX_NAME_SIZE + 1] = { 0 };
	GetName(newName);

	if (strcmp(newName, "Circle-Square") == 0)
	{
		return (float) (2 * PI_VALUE * radius);
	}
	else if (strcmp(newName, "Square-Circle") == 0)
	{
		return (float) (4 * sideLength);
	}
	else
	{
		return 0;
	}
}

/**
*	\brief this virtual function calculates Area
*	\details this method returns the Area of the object based on different types of CircleSquare
*	\param NONE
*	\returns float area of the object
*/
float CircleSquare::Area(void)
{
	char newName[MAX_NAME_SIZE + 1] = { 0 };
	GetName(newName);

	if (strcmp(newName, "Circle-Square") == 0)
	{
		return (float) (PI_VALUE * radius * radius);
	}
	else if (strcmp(newName, "Square-Circle") == 0)
	{
		return (float) (sideLength * sideLength);
	}
	else
	{
		return 0;
	}
}

/**
*	\brief this virtual function calculates OverallDimension
*	\details this method returns the OverallDimension of the object based on different types of CircleSquare
*	\param NONE
*	\returns float OverallDimension of the object
*/
float CircleSquare::OverallDimension(void)
{
	char newName[MAX_NAME_SIZE + 1] = { 0 };
	GetName(newName);

	if (strcmp(newName, "Circle-Square") == 0)
	{
		return (float) (2 * radius);
	}
	else if (strcmp(newName, "Square-Circle") == 0)
	{
		return sideLength;
	}
	else
	{
		return 0;
	}
}

/**
*   \brief this function calculates prints output
*	\details this method is to be called in order to take a snapshot of the current attribute values of CircleSquare based on different types of CircleSquare. This also prints the contained object details.
*	\param NONE
*	\returns Nothing
*/
void CircleSquare::Show(void)
{
	char newName[MAX_NAME_SIZE + 1] = { 0 };
	GetName(newName);
	char newColour[MAX_COLOUR_SIZE + 1] = { 0 };
	GetColour(newColour);

	printf("\nShape Information\n");
	printf("Name            : %s\n", newName);
	printf("Colour          : %s\n", newColour);
	if (strcmp(newName, "Circle-Square") == 0)
	{
		printf("Circle\n");
		printf("Radius          : %0.2f cm\n", radius);
		printf("Circumference   : %0.2f cm\n", Perimeter());
		printf("Area            : %0.2f square cm\n", Area());
		printf("Contained Square\n");
		printf("Side-Length     : %0.2f cm\n", sideLength);
		printf("Perimeter       : %0.2f cm\n", ContainedPerimeter());
		printf("Area            : %0.2f square cm\n", ContainedArea());
	}
	else if (strcmp(newName, "Square-Circle") == 0)
	{
		printf("Square\n");
		printf("Side-Length     : %0.2f cm\n", sideLength);
		printf("Perimeter       : %0.2f cm\n", Perimeter());
		printf("Area            : %0.2f square cm\n", Area());
		printf("Contained Circle\n");
		printf("Radius          : %0.2f cm\n", radius);
		printf("Circumference   : %0.2f cm\n", ContainedPerimeter());
		printf("Area            : %0.2f square cm\n", ContainedArea());
	}
}

/**
*   \brief this function returns perimeter details of contained object
*	\details this method is to be called in order to return the perimeter based on object type
*	\param NONE
*	\returns float	returns the perimeter
*/
float CircleSquare::ContainedPerimeter(void)
{
	char newName[MAX_NAME_SIZE + 1] = { 0 };
	GetName(newName);

	if (strcmp(newName, "Circle-Square") == 0)
	{
		return (float)(4 * sideLength);
	}
	else if (strcmp(newName, "Square-Circle") == 0)
	{
		return (float)(2 * PI_VALUE * radius);
	}
	else
	{
		return 0;
	}
}

/**
*   \brief this function returns area details of contained object
*	\details this method is to be called in order to return the area based on object type
*	\param NONE
*	\returns float	returns the area
*/
float CircleSquare::ContainedArea(void)
{
	char newName[MAX_NAME_SIZE + 1] = { 0 };
	GetName(newName);

	if (strcmp(newName, "Circle-Square") == 0)
	{
		return (float)(sideLength * sideLength);
	}
	else if (strcmp(newName, "Square-Circle") == 0)
	{
		return (float)(PI_VALUE * radius * radius);
	}
	else
	{
		return 0;
	}
}

/**
*	\brief this is the overloaded add function
*	\details this method performs the overloaded add operation for CircleSquare. Before adding, this checks for the matching objects, otherwise throws exception. Returning object colour is from lhs and radius and sidelength is the addition of lhs and rhs.
*	\param const CircleSquare& rhs
*	\returns CircleSquare
*/
CircleSquare CircleSquare::operator+(const CircleSquare& rhs)
{
	CircleSquare temp;

	char newColour[MAX_COLOUR_SIZE + 1] = { 0 };
	this->GetColour(newColour);

	char lhsName[MAX_NAME_SIZE + 1] = { 0 };
	this->GetName(lhsName);
	char rhsName[MAX_NAME_SIZE + 1] = { 0 };
	rhs.GetName(rhsName);

	if (strcmp(lhsName, rhsName) == 0)
	{
		temp.SetColour(newColour);
		temp.SetRadius(this->radius + rhs.radius);
		temp.SetSideLength(this->sideLength + rhs.sideLength);
	}
	else
	{
		throw "	>>> Objects are different, Hence, can't be added to each other.\n";
	}

	return temp;;
}

/**
*	\brief this is the overloaded assignment function
*	\details this method performs the overloaded assignment operation where rhs object's attributes are assigned to lhs
*	\param const CircleSquare& rhs
*	\returns const CircleSquare&
*/
const CircleSquare& CircleSquare::operator=(const CircleSquare& rhs)
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
		this->SetSideLength(rhs.sideLength);
	}
	
	return *this;
}
