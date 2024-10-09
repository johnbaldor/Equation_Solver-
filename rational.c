#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "rational.h"




Rational create_rational(const int num, const int denom){ 
    //makes new rational given a denominator and numerator
    Rational A; 
    A.numerator = num;
    A.denominator= denom;
    return A;

}

Rational copy_rational(const Rational* orig){
    Rational copy;
    //makes new rational with same numerator and denominator as given rational
    copy.numerator = orig -> numerator;
    copy.denominator = orig -> denominator;
    
    return copy;
}

int gcd(int a, int b) {
if (b == 0) {
    return a; }
else {
    return gcd(b, a % b);}

}

void simplify(Rational* unsimp){
    //collect unsimplified numerator and denominator 
    int num = unsimp-> numerator;
    int dem = unsimp-> denominator;

    int greatestcd = gcd(abs(unsimp-> numerator), abs(unsimp -> denominator )); // call gcd function with absolute values 
    if(num < 0 || dem < 0){ // if numerator or denominator is negative make rational negative 
        unsimp -> numerator = -1 * abs(num/greatestcd);
        unsimp -> denominator = abs(dem/greatestcd);
    }
    
    //change numerator and denoinator of given rational
    unsimp -> numerator = num/greatestcd; 
    unsimp -> denominator = dem/greatestcd;

}

Rational add(const Rational* num1, const Rational* num2){
    Rational sum;
    int denom1 = num1 -> denominator;
    int denom2 = num2 -> denominator;

    //make common denominator 
    sum.denominator = denom1 * denom2;

    int numor1 = num1 -> numerator;
    int numor2 = num2 -> numerator;

    //using denominators add numerators 
    sum.numerator = numor1 * denom2 + numor2 * denom1;

    simplify(&sum); // simplify rational 
    return sum;
}


Rational subtract(const Rational* num1, const Rational* num2){
    Rational diff;
    int denom1 = num1 -> denominator;
    int denom2 = num2 -> denominator;
    //make commmon denominator
    diff.denominator = denom1 * denom2;

    int numor1 = num1 -> numerator;
    int numor2 = num2 -> numerator;
    //using denominators subtract numerators 
    diff.numerator = numor1 * denom2 - numor2 * denom1;

    simplify(&diff); //simpliy rational
    return diff;
}

Rational multiply(const Rational* num1, const Rational* num2){
    Rational product;
    int denom1 = num1 -> denominator;
    int denom2 = num2 -> denominator;
    //make common denominator 
    product.denominator = denom1 * denom2;


    int numor1 = num1 -> numerator;
    int numor2 = num2 -> numerator;
    //multiply numerators 
    product.numerator = numor1 * numor2;
    simplify(&product);
    return product;
}


Rational divide(const Rational* num1, const Rational* num2){
    Rational quotient;

    //collect numerators and denominators 
    int denom1 = num1 -> denominator;
    int denom2 = num2 -> denominator;
    int numor1 = num1 -> numerator;
    int numor2 = num2 -> numerator;

    //multiply first denominator by second numerator
    quotient.denominator = denom1 * numor2;
    //multiply first denominator by second numerator
    quotient.numerator = numor1 * denom2;
    simplify(&quotient);
    
    return quotient;
}

void print(FILE* file, const Rational* rational){
    // copy and simplify rational
    Rational a = copy_rational(rational);
    simplify(&a);


    if((a.denominator) == 1){ //if denominator is equal to one only print numerator 
        fprintf(file, "%d", a.numerator);
    }
    else{fprintf(file, "%d/%d", a.numerator, a.denominator);} //else print denominator/numerator 
}


bool equal(const Rational* num1, const Rational* num2){

    //copy and simplify rationals 
    Rational n1 = copy_rational(num1);
    Rational n2 = copy_rational(num2);
    simplify(&n1);
    simplify(&n2);
    
    //if numerator 1 is equal to numerator 2 and denominator 1 is equal to denominator 2 then rationals are equal 
    if((n1.numerator == n2.numerator) && (n1.denominator == n2.denominator)){
        return 1;
    }
    else{return 0;}
}

int compare(const Rational* num1, const Rational* num2){
    // subtract rational's numerators
    int result = (num1->numerator * num2->denominator)-(num2->numerator * num1->denominator); // multiply by oppisite denominator to make common
    
    if(result < 0 ){ // if result is negative num1 was less 
        return -1;}
    
    if( result > 0 ){ // if result is postive num2 was less 
        return 1;
    }
    return 0; // otherwise rationals are equal
}