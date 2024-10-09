#include <stdio.h>
#include <string.h>
#include <string.h>
#include "rational.h"


// function header 
int read_rational(FILE*, int*, int*, int*, int*, char[]);


int main(int argc, char* argv[]){

  // initializing varibles 
  Rational end;  
  int num1, denom1, num2, denom2;
  char operator[3];
  FILE *f2 = fopen(argv[argc-1], "w"); //open output file 

  
 for(int i = 1; i < argc; i++){ //for loop to open and read off of each file parameter given
    FILE *f1 = fopen(argv[i], "r"); //open file to read 
  
  while (read_rational(f1, &num1, &denom1, &num2, &denom2, operator) > 0){  // loop printing output eachtime file line is read 
      
        //creating rationals from read input 
        Rational r1 = create_rational(num1, denom1);
        Rational r2 = create_rational(num2, denom2);

        if (strcmp(operator, "+") == 0) { //if read operator is "+" add rationals and print 
            end = add(&r1, &r2); //returns added rational

            //prints output  
            print(f2,&r1); //prints rational 1 
            fprintf(f2," %s ",operator); // prints operator 
            print(f2,&r2); //prints rational 2 
            fprintf(f2,"\t: "); // prints tab:
            print(f2,&end); // prints new rational 
            fprintf(f2,"\n"); //prints new line 
        } 
        else if (strcmp(operator, "-") == 0) { //if read operator is "-" subtract rationals and print
            end = subtract(&r1, &r2); //returns subtracted rational
            //prints output 
            print(f2,&r1);
            fprintf(f2," %s ",operator);
            print(f2,&r2);
            fprintf(f2,"\t: ");
            print(f2,&end);
            fprintf(f2,"\n");
        } 
        else if (strcmp(operator, "*") == 0) { //if read operator is "*" multiply rationals and print
            end = multiply(&r1, &r2); //returns multiplied rational
            //prints output 
            print(f2,&r1);
            fprintf(f2," %s ",operator);
            print(f2,&r2);
            fprintf(f2,"\t: ");
            print(f2,&end);
            fprintf(f2,"\n");
        } 
        else if (strcmp(operator, "/") == 0) { //if read operator is "/" divide rationals and print
            end = divide(&r1, &r2); // returns divided rational
            //prints output 
            print(f2,&r1);
            fprintf(f2," %s ",operator);
            print(f2,&r2);
            fprintf(f2,"\t: ");
            print(f2,&end);
            fprintf(f2,"\n");
        }
        else if (strcmp(operator, "==") == 0) { //if read operator is "==" check equality of rationals and print
            int result = equal(&r1, &r2);
            if(result == 1){ //if rationals equal
              print(f2,&r1); 
              fprintf(f2," %s ",operator);
              print(f2,&r2);
              fprintf(f2,"\t: ");
              fprintf(f2,"true\n");
            }
            else{ //if rationals are not equal 
              print(f2,&r1);
              fprintf(f2," %s ",operator);
              print(f2,&r2);
              fprintf(f2,"\t: ");
              fprintf(f2,"false\n");}
        }
        else if (strcmp(operator, "!=") == 0) { //if read operator is "!=" check equality of rationals and print
            int result = compare(&r1, &r2);
            if(result != 0){  //if rationals are not equal 
              print(f2,&r1);
              fprintf(f2," %s ",operator);
              print(f2,&r2);
              fprintf(f2,"\t: ");
              fprintf(f2,"true\n");}
            else{ //are equal 
              print(f2,&r1);
              fprintf(f2," %s ",operator);
              print(f2,&r2);
              fprintf(f2,"\t: ");
              fprintf(f2,"false\n");}
        }
        else if (strcmp(operator, "<") == 0) { //if read operator is "<" check if first rational is less than second 
            int result = compare(&r1, &r2);
            if(result == -1){ //if first is less
              print(f2,&r1);
              fprintf(f2," %s ",operator);
              print(f2,&r2);
              fprintf(f2,"\t: ");
              fprintf(f2,"true\n");}
            else{ //if first is more
              print(f2,&r1);
              fprintf(f2," %s ",operator);
              print(f2,&r2);
              fprintf(f2,"\t: ");
              fprintf(f2,"false\n");}
        }
        else if (strcmp(operator, ">") == 0) { //if read operator is ">" check if first rational is more than second
            int result = compare(&r1, &r2);
            if(result == 1){ //if first is more 
              print(f2,&r1);
              fprintf(f2," %s ",operator);
              print(f2,&r2);
              fprintf(f2,"\t: ");
              fprintf(f2,"true\n");}
            else{ // if first is less
              print(f2,&r1);
              fprintf(f2," %s ",operator);
              print(f2,&r2);
              fprintf(f2,"\t: ");
              fprintf(f2,"false\n");}
        }
        else if (strcmp(operator, ">=") == 0) { //if read operator is ">=" check if first rational is more than or equal to second
            int result = compare(&r1, &r2);
            if((result == 1) || (result ==0)){ //if first is more or equal
              print(f2,&r1);
              fprintf(f2," %s ",operator);
              print(f2,&r2);
              fprintf(f2,"\t: ");
              fprintf(f2,"true\n");}
            else{  //if first is less
              print(f2,&r1);
              fprintf(f2," %s ",operator);
              print(f2,&r2);
              fprintf(f2,"\t: ");
              fprintf(f2,"false\n");}
        }
        else if (strcmp(operator, "<=") == 0) {  //if read operator is "<=" check if first rational is less than or equal to second
            int result = compare(&r1, &r2);
            
            if((result == -1) || (result ==0)){ //if first is less or equal
              print(f2,&r1);
              fprintf(f2," %s ",operator);
              print(f2,&r2);
              fprintf(f2,"\t: ");
              fprintf(f2,"true\n");}
            else{  //if first is more 
              print(f2,&r1);
              fprintf(f2," %s ",operator);
              print(f2,&r2);
              fprintf(f2,"\t: ");
              fprintf(f2,"false\n");}
        }
        }

  //closes current file
  fclose(f1);}

  return 0;
}





int read_rational(FILE * f1, int * n1, int * d1, int * n2, int * d2, char op[]) {
  char line[100];
  char * s = fgets(line, 99, f1);
  if (s == NULL) {
    return 0;
  } else {
    // 1. rational1 op rational2
    if (sscanf(line, "%d/%d %s %d/%d", n1, d1, op, n2, d2) == 5) {
      return 5;
    }
    // 2. num1 op rational2
    else if (sscanf(line, "%d %s %d/%d", n1, op, n2, d2) == 4) {
      *d1 = 1;
      return 4;
    }
    // 3. rational1 op num2
    else if (sscanf(line, "%d/%d %s %d", n1, d1, op, n2) == 4) {
      *d2 = 1;
      return 4;
    }
    // 4. num1 op num2
    else if (sscanf(line, "%d %s %d", n1, op, n2) == 3) {
      *d1 = 1;
      *d2 = 1;
      return 3;
    }
    // 5. Error!
    else {
      return -1;
    }
  }
}