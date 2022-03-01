#pragma once
#include "Shape.h"

/*
*	Class			: CircleSquare
*	Author			: Mita Das & Colby Taylor
*	Description		: This file has the CircleSquare class definition.
*/

/// 
/// \class CircleSquare
///
/// \brief The purpose of this class is to model CircleSquare using Shape public inheritenace
///        It implements three pure virtual methods - Area, Perimeter and OverallDimension
///        using the help from radius and side_length data members. In this program we have 
///        also implemented overlaoded operators - add(+), and assignment(=). Using this class,
///        we are trying to implement either Circle-Square i.e. square contained within a circle 
///        or Square-Circle i.e. circle contained within a square.
/// 
///        - Overloaded Add Operator - to add two CircleSquare objects
///        - Overloaded Assignment Operator - Assign rhs to lhs CircleSquare object
///
/// Data Members:
///    - side_length   : Side length of the CircleSquare
///    - radius   : radius of the CircleSquare
///
/// Methods:
///    - Following constructors
///        - CircleSquare()
///        - CircleSquare(char* newColor, float newRadius, float newSideLength, char* newName);
///    - Getters and setters for side_length and radius
///    - virtual functions - Area(), Perimeter(), and OverallDimension()
///    - show() method to print the details
///    - virtual Destructor
///    - methods to calculate area and perimeter for contained object
///    - method to select and print the contained object attributes
///    - Overloaded operator methods for
///        - Add
///        - Assignment
///
/// \author <i>Mita Das & Colby Taylor</i>
///

class CircleSquare :public Shape
{
private:
	float sideLength;											///< side-length of the square
	float radius;												///< radius of the circle

public:
	CircleSquare(void);											///< Constructor
	CircleSquare(char* newColor, float newRadius,				///< Parameterized Constructor
		float newSideLength, char* newName);

	void SetRadius(float newRadius);							///< radius variable mutator
	float GetRadius(void);										///< radius variable accessor

	void SetSideLength(float newSideLength);					///< side-length variable mutator
	float GetSideLength(void);									///< side-length variable accessor

	virtual float Perimeter(void);								///< virtual method for perimeter
	virtual float Area(void);									///< virtual method for area
	virtual float OverallDimension(void);						///< virtual method for dimension

	void Show(void);											///< attributes print method

	float ContainedPerimeter(void);								///< perimeter calculation method for contained object
	float ContainedArea(void);									///< area calculation method for contained object

	CircleSquare operator+(const CircleSquare& rhs);			///< Overloaded add function
	const CircleSquare& operator=(const CircleSquare& rhs);		///< Overloaded assignment function

	virtual ~CircleSquare(void);								///< Destructor for CircleSquare
};
