#pragma once

/*
*	Class			: Shape
*	Author			: Mita Das & Colby Taylor
*	Description		: This file has the Shape class definition.
*/

#include<stdio.h>
#include<string.h>

#pragma warning(disable: 4996)

#define MAX_NAME_SIZE 50
#define MAX_COLOUR_SIZE 10
#define PI_VALUE 3.1415926

/// 
/// \class Shape
///
/// \brief The purpose of this class is to create abstract model for shape.
///        This class also implements pure virtual Area, Perimeter and 
///        OverallDimension methods and has setters and getters for name and 
///        colour. Along with that, it implements GetName and GetColour
///        const methods for usage in overloaded operator functions. In this 
///        function we have float checker function.
///
/// Data Members:
///    - name   : Name of the shape
///    - colour : Colour of the shape
///
/// Methods:
///    - Following constructors
///        - Shape()
///        - Shape(name, colours)
///    - Regular Getters and setters for name and colour
///    - Const getters for name and colour
///    - Pure virtual functions - Area(), Perimeter(), and OverallDimension()
///    - Float difference checker
///
/// \author <i>Mita Das & Colby Taylor</i>
///

class Shape
{
private:
	char name[MAX_NAME_SIZE + 1];					///< name of the shape
	char colour[MAX_COLOUR_SIZE + 1];				///< colour of the shape

public:
	Shape(void);									///< Constructor
	Shape(char* newName, char* newColour);			///< Parameterized Constructor

	void GetName(char* newName);					///< name accessor of regular type
	void GetColour(char* newColour);				///< colour accessor of regular type

	void GetColour(char* newColour) const;			///< colour accessor of const type
	void GetName(char* newName) const;				///< name accessor of const type

	int SetName(char* newName);						///< name variable mutator
	int SetColour(char* newColour);					///< colour variable mutator

	virtual float Perimeter(void) = 0;				///< pure virtual method for perimeter
	virtual float Area(void) = 0;					///< pure virtual method for area
	virtual float OverallDimension(void) = 0;		///< pure virtual method for dimension

	int AlmostEqualFloats(float f1, float f2,		///< checks float differences
		float range);
};
