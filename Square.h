#pragma once
#include "Shape.h"
#include "Circle.h"
#include "CircleSquare.h"

/*
*	Class			: Square
*	Author			: Mita Das & Colby Taylor
*	Description		: This file has the Square class definition.
*/

/// 
/// \class Square
///
/// \brief The purpose of this class is to model Square using Shape public inheritenace
///        It implements three pure virtual methods - Area, Perimeter and OverallDimension
///        using the help from side_length data member. In this program we have also implemented
///        overlaoded operators - add(+), multiplication(*), assignment(=), and equality
///        check(==). Part of A08, added overloaded add operator to add circle to a square object
///	       and return CircleSquare object.
/// 
///        - Overloaded Add Operator - to add two square objects
///        - Overloaded Add Operator - to add circle to a square object and return CircleSquare object
///        - Overloaded Multiplication Operator - to multiply two square objects
///        - Overloaded Assignment Operator - Assign rhs to lhs objects
///        - Overloaded Quality Check Operator - Compares two objects
///
/// Data Members:
///    - side_length   : Side length of the square
///
/// Methods:
///    - Following constructors
///        - Square()
///        - Square(colour, side_length)
///    - Getters and setters for side_length
///    - virtual functions - Area(), Perimeter(), and OverallDimension()
///    - show() method to print the details
///    - virtual Destructor
///    - Overloaded operator methods for
///        - Add
///        - Multiplication
///        - Assignment
///        - Equality
///
/// \author <i>Mita Das & Colby Taylor</i>
///

class Square :public Shape
{
private:
	float sideLength;								///< side-length of the square

public:
	Square(void);									///< Constructor
	Square(char* newColour, float newSideLength);	///< Parameterized Constructor

	int SetSideLength(float newSideLength);			///< side-length variable mutator
	float GetSideLength(void);						///< side-length variable accessor

	void Show(void);								///< attributes print method

	Square operator+(const Square& rhs);			///< Overloaded add function
	Square operator*(const Square& rhs);			///< Overloaded multiplication function
	const Square& operator=(const Square& rhs);		///< Overloaded assignment function
	bool operator==(const Square& rhs);				///< Overloaded equality check function 

	CircleSquare operator+(Circle& rhs);			///< Overloaded add function for Square and Circle with return to CircleSquare

	virtual float Perimeter(void);					///< virtual method for perimeter
	virtual float Area(void);						///< virtual method for area
	virtual float OverallDimension(void);			///< virtual method for dimension

	virtual ~Square(void);							///< Destructor for Square
};

