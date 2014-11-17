/*
 Author:    Joseph Herkness
 Date:      2014-11-16
 Objective: For this exercise, research world population growth issues online. Be sure to investigate
            various viewpoints. Get estimates for the current world population and its growth rate (the
            percentage by which it’s likely to increase this year). Write a program that calculates world
            population growth each year for the next 75 years, using the simplifying assumption that the 
            current growth rate will stay constant. Print the results in a table. The first column should 
            display the year from year 1 to year 75. The second column should display the anticipated world 
            population at the end of that year. The third column should display the numerical increase in 
            the world population that would occur that year. Using your results, determine the year in 
            which the population would be double what it is today, if this year’s growth rate were to
            persist.
 */

//Answer: After 59 years the population would be double the original population

#include<stdio.h>
#include<stdlib.h>

int main(){
    double anualGrowthRate = 0.012; //Anual Growth Rate
    long population = 7125000000; //Current World Population
    
    printf("%-5s %-15s %-15s \n\n","Year", "Population", "Change"); //Column Headers

    int i=1; //Counter variable
    while(i <= 75){
        long newPopulation = population + population * anualGrowthRate; //Calculate New Population
        printf("%-5d %-15lu %-15lu \n",i, newPopulation, newPopulation-population); //Print the information
        i++; //Update the counter
        population = newPopulation; //Set the current population to the new population
    }
}
