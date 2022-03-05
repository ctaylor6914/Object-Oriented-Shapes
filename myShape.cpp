#include "Circle.h"
#include "Square.h"
#include "CircleSquare.h"

#pragma warning(disable: 4996)

/*
*	FILE			: myShape.cpp
*	PROGRAMMER		: Mita Das & Colby Taylor
*	FIRST VERSION	: 2021-04-24
*	DESCRIPTION		: This program performs overloaded operator operations for
*					  Square, Shape, and CircleSquare classes. In this test harness we are createting
*                     template functions and using it to call overaloaded operators.
*/

template <class X> X CombineShape(X& a, X& b);
template <class X, class Y, class Z> Z CombineDifferentShape(X& a, Y& b);

int main(void)
{
	Circle round1((char*)"red", 5.5);
	Circle round2((char*)"blue", 10.5);

	Square square1((char*)"orange", 5);
	Square square2((char*)"purple", 12);

	CircleSquare playARoundSquare;

	Square playASquare = CombineShape <Square>(square1, square2);
	playASquare.Show();

	try
	{
		playARoundSquare = CombineDifferentShape <Square, Circle, CircleSquare>(square2, round1);
		playARoundSquare.Show();
	}
	catch (const char* e)
	{
		printf("\nException: \n%s", e);
	}

	try
	{
		playARoundSquare = CombineDifferentShape <Square, Circle, CircleSquare>(square1, round2);
		playARoundSquare.Show();
	}
	catch (const char* e)
	{
		printf("\nException: \n%s", e);
	}
	
	return 0;
}

/*
*	FUNCTION		: CombineShape()
*	DESCRIPTION		: This template function takes same type of objects and retuns the 
*                     overlaoded operator addition of those two objects.
*	PARAMETERS		: X& a, X& b
*	RETURNS         : X type object
*/
template <class X> X CombineShape(X& a, X& b)
{
	X	c;
	c = a + b;
	return c;
}

/*
*	FUNCTION		: CombineDifferentShape()
*	DESCRIPTION		: This template function takes two different types of objects and retuns the
*                     overlaoded operator addition of those two objects into a thrid type.
*	PARAMETERS		: X& a, Y& b
*	RETURNS         : Z type object
*/
template <class X, class Y, class Z> Z CombineDifferentShape(X& a, Y& b)
{
	Z	c;
	c = a + b;
	return c;
}
