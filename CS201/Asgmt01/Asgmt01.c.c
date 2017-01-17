#include <stdio.h>
#include <stdlib.h>

// You are only allowed to make changes to this code as specified by the comments in it.

// The code you submit must have these two values.
#define N_TIMES		600000
#define ARRAY_SIZE	 10000

int main(void)
{
	double	*array = calloc(ARRAY_SIZE, sizeof(double));
	double	sum = 0;
	int		i;

	// You can add variables between this comment ...
//	double sum2 = 0;
	double *ptr;
//	double sumTotal = 0;
	// ... and this one.

	// Please change 'your name' to your actual name.
	printf("CS201 - Asgmt 4 - Molly Novash\n");

	for (i = 0; i < N_TIMES; i++) {

		// You can change anything between this comment ...
		double sum2, sum3, sum4, sum5, sumTotal;
	//	int     j;

		for (ptr = array; ptr < &array[ARRAY_SIZE]; ptr+=25) {

			sum += (*ptr + (*ptr + 1) + (*ptr+2) + (*ptr+3) + (*ptr+4));
			sum2 += ((*ptr+5) + (*ptr+6) + (*ptr+7) + (*ptr+8) +(*ptr+9));
			sum3 += ((*ptr+10) + (*ptr+11) + (*ptr+12) + (*ptr+13) + (*ptr+14));
			sum4 += ((*ptr+15) + (*ptr+16) + (*ptr+17) + (*ptr+18) + (*ptr+19));
			sum5 += ((*ptr+20) + (*ptr+21) + (*ptr+22) + (*ptr+23) + (*ptr+24));

			}
			sumTotal += sum + sum2 + sum3 + sum4 + sum5;
		// ... and this one. But your inner loop must do the same
		// number of additions as this one does.

		}

	// You can add some final code between this comment ...

	// ... and this one.
	
	return 0;
}
