#include "Shape.h"

/*
*	FILE			: Square.cpp
*	PROJECT			: Assignment8
*	PROGRAMMER		: Mita Das & Colby Taylor
*	DESCRIPTION		: This file has all of the function definitions of
*                     Shape class.
*/

/**
*	\brief this is Shape default constructor
*	\details this method is used to instantiate a new Shape object with default values
*	\param NONE
*	\returns Nothing
*/
Shape::Shape(void)
{
	strcpy(name, "Unknown");
	strcpy(colour, "undefined");
}

/**
*	\brief this is Shape parameterized constructor
*	\details this method is used to instantiate a new Shape object - given a set of attribute values
*	\param newName String name of the shape
*	\param newColour String colour of the shape
*	\returns Nothing
*/
Shape::Shape(char* newName, char* newColour)
{
	if (strlen(newName) > 50)
	{
		strcpy(name, "Unknown");
	}
	else
	{
		if ((strcmp(newName,"Circle") == 0) || (strcmp(newName, "Square") == 0)
			|| (strcmp(newName, "Circle-Square") == 0) || (strcmp(newName, "Square-Circle") == 0))
		{
			strcpy(name, newName);
		}
		else
		{
			strcpy(name, "Unknown");
		}
	}

	if (strlen(newColour) > 10)
	{
		strcpy(colour, "undefined");
	}
	else
	{
		if ((strcmp(newColour, "red") == 0) || (strcmp(newColour, "green") == 0)
			|| (strcmp(newColour, "blue") == 0) || (strcmp(newColour, "yellow") == 0)
			|| (strcmp(newColour, "purple") == 0) || (strcmp(newColour, "pink") == 0)
			|| (strcmp(newColour, "orange") == 0))
		{
			strcpy(colour, newColour);
		}
		else
		{
			strcpy(colour, "undefined");
		}
	}
}

/**	
*   \brief accessor for name of regular type
*	\details this method returns the name of the shape by copying into a separate string variable
*	\param newName string
*	\returns NONE											
*/
void Shape::GetName(char* newName)
{
	memcpy(newName, name, sizeof(name));
}

/**
*   \brief accessor for name of const type
*	\details this method returns the name of the shape by copying into a separate string variable
*	\param newName string
*	\returns NONE
*/
void Shape::GetName(char* newName) const
{
	memcpy(newName, name, sizeof(name));
}

/**	
*   \brief accessor for colour of regular type
*	\details this method returns the colour of the shape by copying into a separate string variable
*	\param newColour string
*	\returns NONE
*/
void Shape::GetColour(char* newColour)
{
	memcpy(newColour, colour, sizeof(colour));
}

/**
*   \brief accessor for colour of const type
*	\details this method returns the colour of the shape by copying into a separate string variable
*	\param newColour string
*	\returns NONE
*/
void Shape::GetColour(char* newColour) const
{
	memcpy(newColour, colour, sizeof(colour));
}

/**	
*   \brief mutator for name
*	\details this method sets the name of the shape and returns the status
*	\param newName string
*	\returns status int
*/
int Shape::SetName(char* newName)
{
	if (strlen(newName) > 50)
	{
		return 0;
	}
	else
	{
		if ((strcmp(newName, "Circle") == 0) || (strcmp(newName, "Square") == 0)
			|| (strcmp(newName, "Circle-Square") == 0) || (strcmp(newName, "Square-Circle") == 0))
		{
			strcpy(name, newName);
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

/**	
*   \brief mutator for colour
*	\details this method sets the name of the shape and returns the status
*	\param newColour string
*	\returns status int
*/
int Shape::SetColour(char* newColour)
{
	if (strlen(newColour) > 10)
	{
		return 0;
	}
	else
	{
		if ((strcmp(newColour, "red") == 0) || (strcmp(newColour, "green") == 0)
			|| (strcmp(newColour, "blue") == 0) || (strcmp(newColour, "yellow") == 0)
			|| (strcmp(newColour, "purple") == 0) || (strcmp(newColour, "pink") == 0)
			|| (strcmp(newColour, "orange") == 0))
		{
			strcpy(colour, newColour);
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

/**
*   \brief Author - John Simmons, this checks for float differences
*	\details this method checks two float numbers based on a particular range.
*	\param float f1, float f2, float range
*	\returns int
*/
int Shape::AlmostEqualFloats(float f1, float f2, float range)
{
	if ((((f2 - range) < f1) && (f1 < (f2 + range)))==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}