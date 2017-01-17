// starter file for Assignment 2p

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function for checking that your assembly code is computing the correct result
double quadraticRootC(double a, double b, double c)
{
	return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

double quadraticRoot(double a, double b, double c)
{
	
	double quadRoot;

	// write assembly code below to calculate the quadratic root
	asm(
		/* Delete the line below. It's only there to allow the starter code
		 * to compile. You will be replacing it with your own code.				*/
	//	"		mov		$0, %%eax			\n"
		"		fldl		%[b]				\n"
		"		fldl 		%[b]				\n"     // load b into st(0)
		"		fmulp							\n" 	// multiply b by itself: b^2
		"		fldl		%[a]				\n"		// load a into st(0), b st(1)
		"		fldl		%[c]				\n"		// load c into st(0), a st(1), b st(2)
		"		fmulp							\n"     // a * c, store in st(1), pop st(0)
		"		fldl		%[a]				\n"
		"		fldl		%[c]				\n"
		"		fmulp							\n"
		"		faddp							\n"
		"		fldl		%[a]				\n"
		"		fldl		%[c]				\n"
		"		fmulp							\n"
		"		faddp							\n"     // now we're at 3ac
		"		fldl		%[a]				\n"
		"		fldl		%[c]				\n"
		"		fmulp							\n"
		"		faddp							\n"		// st1 b^2, st0 4ac


	//	"		fadd		%%st(0)				\n"		// add another ac, gives 2ac
	//	"		fadd 		%%st(0)				\n"		// add another 2ac, gives 4ac
		"		fimul		-1					\n" 	// change to -4ac
	//	"		fsubrp							\n"
		"		faddp							\n"		// add b^2 to -4ac
		"		fsqrt							\n"     // get sqrt of expression
		"		fldl		%[b]				\n"		// load b into st(0)
		"		fimul		-1					\n"		// make -b
	//	"		fsubrp							\n"
		"		faddp							\n"		// combine statements and pop
		"		fldl		%[a]				\n"		// load a
		"		fldl		%[a]				\n"
		"		faddp							\n"
	


	//	"		fadd		%%st(0)				\n"	// make 2a
		"		fdivrp							\n"	// divide the two. fdivp if not bugging
		"		fstpl 		%[quadRoot]         \n"	// store in variable quad
		:		[quadRoot] 	"=m"		(quadRoot)	// outputs
		:		[a] 		"m"		(a),
				[b]		"m"		(b),
				[c]		"m"		(c)					// inputs
		//	: "eax"									// clobbers
	);

	return quadRoot;
}

// do not change this function, except to print your own name
int main(int argc, char **argv)
{
	double	a, b, c;
	double	root, rootC;

	printf("CS201 - Assignment 2p - Molly Novash\n");	// print your own name instead
	if (argc != 4) {
		printf("need 3 arguments: a, b, c\n");
		return -1;
		}
	a = atof(argv[1]);
	b = atof(argv[2]);
	c = atof(argv[3]);
	root = quadraticRoot(a, b, c);
	rootC = quadraticRootC(a, b, c);

	printf("quadraticRoot(%.3f, %.3f, %.3f) = %.3f, %.3f\n", a, b, c, root, rootC);

	return 0;
}
