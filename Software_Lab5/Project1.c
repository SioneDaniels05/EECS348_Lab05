/*
 * Sione Daniels
 * EECS 348 - Friday 3pm
 * 10/13/2024
 * KUID: 3133752
 * Purpose: to read a 12 monthly sales and generate a sales report
 * */

#include <stdio.h>

//global variable for months so it can be called everywhere instead of needing to be passed in
const char *months[12] = {"January", "February", "March", "April", "May   ", "June  ", "July  ", "August", "September", "October", "November", "December"};

//prints out the information in arrays sorting by the months
void monthly_sale(double data[]) {
	printf("\n-----\nMonthly Sales report for 2024\n");
	printf("Month  \t\tSales\n");
	for (int i = 0; i < 12; i++){
		printf("%s   \t%lf\n", months[i], data[i]);
	}
	printf("-----\n");	
	}

//prints out the smallest sale over the months
void sales_min(double data[]) {
	printf("Sales summary report:\n");
	int i = 0;
	float lowest = data[i];
	for (int i = 0; i < 12; i++){
	float temp = data[i];
	float temp2 = data[i+1];
	if ((temp < temp2) && (lowest > temp)){
		lowest = temp;
	}}
	printf("Minimum Sales: %f\n", lowest);
	}

//prints the largest sale over the months
void sales_max(double data[]) {
        int i = 0;
        float highest = data[i];
        for (int i = 0; i < 12; i++){
        float temp = data[i];
        float temp2 = data[i+1];
        if (temp < temp2){
                highest = data[i+1];
        }}
        printf("Maximum Sales: %f\n", highest);
}

//adds up all the mothes divides by 12 and prints the average sale
void sales_avg(double data[]) {
       	float total = 0;
        for (int i = 0; i < 12; i++){
        total = (total + data[i]);
        }
	total = (total/12);
        printf("Average Sales: %f\n", total);
        printf("-----\n");
	}

//prints the sales in a 6 month average period over the year
void six_month(double data[]) {
	printf("Six-Month moving average report:\n");
	for (int i = 0; i < 12; i++){
		float total = 0;
		for (int d = 0; (d < 6); d++){
		total = (total + data[d+i]);
		if ((i == 0) && (d == 5)){
			total = (total/6);
			printf("January-June\t%f", total);
			}
		else if ((i == 1) && (d == 5)){
			total = (total/6);
                        printf("\nFebruary-July\t%f", total);
			}
		else if ((i == 2) && (d == 5)){
			total = (total/6);
                    	printf("\nMarch-August\t%f", total);
			}
		else if ((i == 3) && (d == 5)){
			total = (total/6);
                        printf("\nApril-September\t%f", total);
			}
		else if ((i == 4) && (d == 5)){
			total = (total/6);
                        printf("\nMay-October\t%f", total);
			}
		else if ((i == 5) && (d == 5)){
			total = (total/6);
                        printf("\nJune-November\t%f", total);
			}
		else if ((i == 6) && (d == 5)){
			total = (total/6);
                        printf("\nJuly-December\t%f", total);			
		}}}
	printf("\n-----\n");
}

//print the sale in decending order with each matching month
void sales_report(double data[]) {
    double data2[12];
    for (int i = 0; i < 12; i++) {
        data2[i] = data[i];
    }
    for (int i = 0; i < 12; i++) {
        for (int a = 0; a < 12 - i - 1; a++) {
            if (data2[a] < data2[a + 1]) {
                double temp = data2[a];
                data2[a] = data2[a + 1];
                data2[a + 1] = temp;
	    }}}
    printf("Sales report (highest to lowest):\nMonths   \tSales");
    for (int i = 0; i < 12; i++) {
        for (int b = 0; b < 12; b++) {
            if (data[b] == data2[i]) {
                printf("\n%s    \t%lf", months[b], data2[i]);
              }}}
    printf("\n-----\n");
}

//handle file I/O and calling the required functions to print
int main() {
	double data[12];
	FILE *file = fopen("input_file.txt", "r");
	
	for (int i = 0; i < 12; i++){
		fscanf(file, "%lf", &data[i]);	
	}
	monthly_sale(data);
	sales_min(data);
	sales_max(data);
	sales_avg(data);
	six_month(data);
	sales_report(data);
		return 0;
}
