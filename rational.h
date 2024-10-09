#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Rational{
    int numerator;
    int denominator;
};
typedef struct Rational Rational;

/*
Rational create_rational(const int num, const int denom)
Creates a Rational struct when given a numerator and denominator

Parameters:
    num: number for numerator 
    denom: number for denominator 
Returns: 
    newly created Rational 
*/
Rational create_rational(const int num, const int denom);


/*
Rational copy_rational(const Rational* orig)
makes a copy of a rational 

Parameters:
    orig: rational to be copied
Returns: 
    copy of rational 
*/
Rational copy_rational(const Rational* orig);


/*
void simplify(Rational* A)
simplifies a rationals numerator and denominator, dividing them by the greatest
common factor  

Parameters:
    unsimp: rational to be Simplfied
Returns: 
    void 
*/
void simplify(Rational* unsimp);


/*
Rational add(const Rational* num1, const Rational* num2)
adds together two rationals   

Parameters:
    num1: rational to add
    num2: rational to add
Returns: 
    rational that is sum of given rationals 
*/
Rational add(const Rational* num1, const Rational* num2);


/*
Rational subtract(const Rational* num1, const Rational* num2)
subtracts one rational from another

Parameters:
    num1: rational to subtract from
    num2: rational being subtracted
Returns: 
    rational that is difference between rationals  
*/
Rational subtract(const Rational* num1, const Rational* num2);


/*
Rational multiply(const Rational* num1, const Rational* num2)
multiplies two rationals   

Parameters:
    num1: rational to be multiplied
    num2: rational to be multiplied
Returns: 
    rational that is product of rationals  
*/
Rational multiply(const Rational* num1, const Rational* num2);


/*
Rational divide(const Rational* num1, const Rational* num2)
subtracts one rational from another

Parameters:
    num1: rational to divided from
    num2: rational dividing
Returns: 
    rational that is quotient between rationals  
*/
Rational divide(const Rational* num1, const Rational* num2);


/*
void print(FILE* file, const Rational* rational)
prints a rational 

Parameters:
    file: file rational is being printed to 
    rational: rational being printed
Returns: 
    void  
*/
void print(FILE* file, const Rational* rational);


/*
bool equal(const Rational* num1, const Rational* num2)
checks if two rationals are equal 

Parameters:
    num1: first rational 
    num2: second rational
Returns: 
    boolean telling if rationals are equal or not
*/
bool equal(const Rational* num1, const Rational* num2);


/*
int compare(const Rational* num1, const Rational* num2)
ccompares the values of two rationals 

Parameters:
    num1: first rational 
    num2: second rational
Returns: 
    int telling which rational is greater or if they are equal
*/
int compare(const Rational* num1, const Rational* num2);


/*
int gcd(int a, int b)
finds the greatest common factor between two numbers 

Parameters:
    a: rational numerator 
    b: rational denominator
Returns: 
    int that is greatest common factor 
*/
int gcd(int a, int b);

