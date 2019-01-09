#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

/*Function declaration*/
double function(double x);
double inputcheck(char instring[200]);
double integratef(double val);

/*Program estimates a numerical answer to an accuracy specified by the user*/
/*For the known function, the Feri-Dirac integral*/
main(){
  double result, val;
  char sfin[200];

  /*User inputs required accuracy*/
  printf("\nPlease enter how many significant figures you would like.\n");
  printf("This number should be an integer between 1 and 6.\n");
  do{
	scanf("%s", sfin);
	val = inputcheck(sfin);  /*Checks that the input is valid*/
  }while(val == 0.0);     
  val = atof(sfin);          /*Assigns the, now, checked float value*/
  
  result = integratef(val);  /*Runs the integration function with the specfied accuracy input*/
  
  printf("Result: %g\n\n", result);
  }

/*Function definition which the program integrates*/
double function(double x){
	double a;
	a = 1.0/((1.0+pow(x, 2.0))*(pow(x,0.5)));
	return a;
  }

/*Checks the input of the user to be an integer in the correct range*/
double inputcheck(char instring[200]){
  float k, val;
  int m;
  m=0;
  val = atof(instring);
  	for(k=1.0;k<8.0;k++){
		if (val == k){
			m=10;             /*Will only change the value of 'm' here*/
			break;            /*Function will otherwide always return '0'*/
		}
	}
  if (m!=10){printf("Not expected number.\n");}
  return m;
  }

/*Function that does the trapezium rule estimation integrates*/
double integratef(double val){
  double ul, ll, width, height, n, x, total, prevtotal, result;
  int i;
  
  /*Variables are defined*/
  ll=FLT_MIN;
  ul=FLT_MIN*2;
  n=1000000;
  width=(ul-ll)/n;
  height=(ul-ll)/(n);
  total=0.0;

  do{
  /*Adds up all function outputs as x varies to the required accuracy*/
	for(i=1;i<n;i++) {
		x=ll+(width*i);
		prevtotal = total;
		total = total + function(x)*height;
		prevtotal = total - prevtotal;
		if (prevtotal<FLT_MIN){               /*Checks that the calculations are meaningful*/
			break;                            /*For the precision required*/
		}
	}
	ll=ul;
	ul=ul*10;
	width=(ul-ll)/n;
	height=(ul-ll)/(n);
  }while(ll<FLT_MAX);
	
  /*Full calculated result is determined*/
  result = total + 0.5*(function(FLT_MIN)*(FLT_MIN/n)+function(FLT_MAX)*(FLT_MAX/n));

  /*Result is truncated to the number of significant figures specified*/
  result = result*pow(10, (val-1));
  result = ((int)(result+0.5));
  result = result/pow(10, (val-1));
  return result;
  }