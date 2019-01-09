#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<string.h>

double inputcheck(char instring[200]);

/*Program linearly interpolates between any two points in the data set*/
/*The maximum value of x is 4 and the minimum is 0*/
main()
{
/*Variables and look up data table are set*/
int i, j, n;
double x0, y0, x1, y1, x, y;
float data[9][2] = { {0.0, 0.0}, {0.5, 1.2}, {1.0, 3.1}, {1.5, 3.7}, {2.0, 5.2}, {2.5, 4.2}, {3.0, 4.1}, {3.5, 5.7}, {4.0, 6.5} };
char inputx[200];
n=9;
i=0;

printf("Input x:\n");

/*Checks if x is in the required range*/
do{
	scanf("%s", inputx);
	x=inputcheck(inputx);
}while(x==0);	
x=atof(inputx);

/*Finds the first number in the array which is larger than x*/
for (i=0;i<n;i++)
	{
	if (x<data[i][0]) {break;}
	}

j=i-1;
	
/*Checks if x is a known value in the array*/
if (x==data[i][0]){printf("Y is %.1f\n", data[i][1]); }
	
/*Calculates the value of y by reading values from the data array*/
else 
	{
	y0 = data[j][1];
	y1 = data[i][1];
	x0 = data[j][0];
	x1 = data[i][0]; 
	y = y0 + (y1-y0)*((x-x0)/(x1-x0));
	printf("Y is %.1f\n", y);
	}
}

double inputcheck(char instring[200]){
  float k, val;
  int m;
  m=0;
  val = atof(instring);
	if((strcmp(instring, "0.0") == 0)||(strcmp(instring, "0") == 0)){
		m=10;
	}                                  /*Will only change the value of 'm' here*/
  	if((val<=4.0)&&(val>0.0)){         /*Function will otherwide always return '0'*/
		m=10;                        
	}
	
  if (m!=10){printf("X must be between 0.0 and 4.0.\n");}
  return m;
  }
  