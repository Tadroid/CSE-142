/*
Author:    Joseph Herkness
Date:      2014-11-04
Objective: Research several car-pooling websites. Create an
           application that calculates your daily driving cost, so
           that you can estimate how much money could be saved by
           car pooling, which also has other advantages such as
           reducing carbon emissions and reducing traffic congestion.
           The application should input the following information and
           display the user’s cost per day of driving to work:
                      a) Total miles driven per day.
                      b) Cost per gallon of gasoline.
                      c) Average miles per gallon.
                      d) Parking fees per day.
                      e) Tolls per day.
*/

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    //Variable Declaration
    int miles;
    float mpg;
    float cost_of_gas;
    float parking_fees;
    float tolls;
    float expenses = 0;

    //User Input
    printf("Enter total miles you drive: ");
    scanf("%d", &miles); //Store the users input in miles
    printf("Enter your average miles per gallon: ");
    scanf("%f", &mpg); //Store the users input in mpg
    printf("Enter the cost of gas: $");
    scanf("%f", &cost_of_gas); //Store the users input in cost_of_gas
    printf("Enter any parking fees: $");
    scanf("%f", &parking_fees);//Store the users input in parking_fees
    printf("Enter any tolls: $");
    scanf("%f", &tolls); //Store the users input in tolls
    
    //Calculation
    if(mpg != 0){ //Idiot Check
        expenses += (miles/mpg) * cost_of_gas; //Add the cost of gas
    }
    expenses += parking_fees;  //Add the cost of parking
    expenses += tolls; //Add the cost of tolls
    
    //User Output
    printf("Cost per day of driving to work: $%.2f \n", expenses); //Print the users total expenses
    
    return 0;
}
