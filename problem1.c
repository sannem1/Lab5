#include <stdio.h>
#include <stdlib.h>//using this for the exit function for example on line 15

/* `constant value assigning NUM_MONTHS to 12 throughout the whole code */
#define NUM_MONTHS 12

/* readSalesData function reads sales data from a file and stores it in an array called `sales`.
It takes two parameters: a pointer to a file (`FILE *file`) and an array of doubles (`double
sales[]`). */
void readSalesData(FILE *file, double sales[]) {
    for (int i = 0; i < NUM_MONTHS; i++) {
        if (fscanf(file, "%lf", &sales[i]) != 1) {
            printf("Error: Invalid data in input file.\n");
            fclose(file);
            exit(1);
        }
    }
}

/* printMonthlySales function is responsible for printing a monthly sales report. It takes two
parameters: an array of doubles `sales[]` which contains the sales data for each month, and an array
of strings `months[]` which contains the names of the months. */
void printMonthlySales(double sales[], char *months[]) {
    printf("Monthly sales report for 2022:\nMonth Sales\n");
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%s $%.2f\n", months[i], sales[i]);
    }
}

/**
 printSalesSummarycalculates and prints the minimum, maximum, and average sales
 values along with the corresponding months
 
 sales An array of double values representing the sales for each month.
  months An array of strings representing the names of the months.
 */
void printSalesSummary(double sales[], char *months[]) {
    double minSales = sales[0], maxSales = sales[0], avgSales = sales[0];

    for (int i = 1; i < NUM_MONTHS; i++) {
        if (sales[i] < minSales) minSales = sales[i];
        if (sales[i] > maxSales) maxSales = sales[i];
        avgSales += sales[i];
    }
    avgSales /= NUM_MONTHS;

    printf("Sales summary:\nMinimum sales: $%.2f (%s)\nMaximum sales: $%.2f (%s)\nAverage sales: $%.2f\n", minSales, months[0], maxSales, months[NUM_MONTHS - 1], avgSales);
}

/*
  function calculates and prints the six-month moving average of sales data for each consecutive
 six-month period.
 
 sales The "sales" parameter is an array of double values representing the sales data for each
 month.
 months The "months" parameter is an array of strings that represents the names of the months.
 */
void printSixMonthMovingAverage(double sales[], char *months[]) {
    printf("Six-Month Moving Average Report:\n");

    for (int i = 0; i < NUM_MONTHS - 5; i++) {
        double movingAvg = 0;
        for (int j = i; j < i + 6; j++) movingAvg += sales[j];
        movingAvg /= 6;
        printf("%s - %s $%.2f\n", months[i], months[i + 5], movingAvg);
    }
}

/* printSalesReportHighestToLowest function is responsible for printing a sales report in
descending order of sales. It takes two parameters: an array of doubles `sales[]` which contains the
sales data for each month, and an array of strings months[] which contains the names of the
months. */
void printSalesReportHighestToLowest(double sales[], char *months[]) {
    printf("Sales Report (Highest to Lowest):\nMonth Sales\n");

    for (int i = NUM_MONTHS - 1; i >= 0; i--) {
        printf("%s $%.2f\n", months[i], sales[i]);
    }
}

/*
 The  function opens a file, reads sales data for each month from the file, and stores it in an
 array.
 
 The main function is returning an integer value. If the input file cannot be opened, it
 returns 1.
 */
int main() {
    FILE *inputFile = fopen("problem1.txt", "r");

    if (!inputFile) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    double sales[NUM_MONTHS];
    char *months[NUM_MONTHS] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    /* The code is reading sales data from the file, storing it in an array called `sales`, and then
    performing various operations on the sales data. */
    readSalesData(inputFile, sales);
    fclose(inputFile);

    printMonthlySales(sales, months);
    printSalesSummary(sales, months);
    printSixMonthMovingAverage(sales, months);
    printSalesReportHighestToLowest(sales, months);

    return 0;
}
