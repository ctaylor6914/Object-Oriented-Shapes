#pragma once
#include "Shape.h"

/*
*	Class			: Circle
*	Author			: Mita Das & Colby Taylor
*	Description		: This file has the Circle class definition.
*/

/// 
/// \class Circle
///
/// \brief The purpose of this class is to model Circle using Shape public inheritenace.
///        It implements three virtual methods - Area, Perimeter and OverallDimension
///        using the help from radius data member. In this program we have also implemented
///        overlaoded operators - add(+), multiplication(*), assignment(=), and equality
///        check(==).
/// 
///        - Overloaded Add Operator - to add two circle objects
///        - Overloaded Multiplication Operator - to multiply two circle objects
///        - Overloaded Assignment Operator - Assign rhs to lhs objects
///        - Overloaded Quality Check Operator - Compares two objects
///
/// Data Members:
///    - radius   : radius of the circle
///
/// Methods:
///    - Following constructors
///        - Circle()
///        - Circle(colour, radius)
///    - Getters and setters for radius
///    - virtual functions - Area(), Perimeter(), and OverallDimension()
///    - show() method to print the details
///    - virtual Destructor
///    - overloaded operator methods for
///        - Add
///        - Multiplication
///        - Assignment
///        - Equality check
///
/// \author <i>Mita Das & Colby Taylor</i>
///

class Circle :public Shape
{
private:
	float radius;									///< radius of the circle

public:
	Circle(void);									///< Constructor
	Circle(char* newColour, float newRadius);		///< Parameterized Constructor

	int SetRadius(float newRadius);					///< radius variable mutator
	float GetRadius(void);							///< radius variable accessor - regular

	float GetRadius(void) const;					///< radius variable accessor - const

	void Show(void);								///< attributes print method

	Circle operator+(const Circle& rhs);			///< Overloaded add function
	Circle operator*(const Circle& rhs);			///< Overloaded multiplication function
	const Circle& operator=(const Circle& rhs);		///< Overloaded assignment function
	bool operator==(const Circle& rhs);				///< Overloaded equality check function

	virtual float Perimeter(void);					///< virtual method for perimeter
	virtual float Area(void);						///< virtual method for area
	virtual float OverallDimension(void);			///< virtual method for dimension

	virtual ~Circle(void);							///< Destructor for Circle
};
