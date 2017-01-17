#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 100

int main(int argc, char *argv[])
{
    printf("Lab 2\n\n");

    // user input vars
    double firstNum;
    double secondNum;

    // good/bad data vars
    // 0 indicates bad data, 1 indicates good data
    int goodFirstNumData = 0;
    int goodSecondNumData = 0; 

    // loop keeps running as long as input is bad
    LOOP:while(goodFirstNumData == 0)
    {
         printf("first number: ");
   	 scanf("%lf", &firstNum);

	 int c;
	 c = getchar();

	 while(c != '\n'){
		if(!isdigit(c))
		{
			printf("bad_input\n-- bad input --\n");
			goto LOOP;
		}
		else{
			c  = getchar();	
		}
	 }
	 goodFirstNumData++;	 
    }

    RELOOP:while(goodSecondNumData == 0)
    {
      	 printf("second number: ");
   	 scanf("%lf", &secondNum);
 	
	 int d;
	 d = getchar();
	 while(d != '\n'){
		if(!isdigit(d))
		{
			printf("bad_input\n-- bad input --\n");
			goto RELOOP;
		}
		else{
			d = getchar();
		}
         }
	 goodSecondNumData++;
    }

    // print addition problem
    printf("\n%11.2f\n", firstNum);
    printf("+%10.2f\n", secondNum);
    printf("-----------\n");
    printf("%11.2f\n", firstNum + secondNum);

    return 0;
}
