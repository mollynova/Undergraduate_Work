#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[])
{
	// declare vars
	int		n;
	char		s[1];
	char		trailing[32];
	
	// store argv[2] in a char array with one slot
	strcpy(s, argv[2]);
	
	// if no command line args
	if(argc < 2)
	{
		printf("call as: lab03 <n1> <op> <n2>\n\n");
		printf("<op>		arithmetic operation: +, -, *, /\n");
		printf("<n1, n2>	the two numbers\n\n");
		return -1;
	}

	// if first arg isn't a number
	if(sscanf(argv[1], "%d %s", &n, trailing) != 1)
	{
		printf("%s is not a number\n", argv[1]);
		return -1;
	}

	// if third arg isn't a number
	if(sscanf(argv[3], "%d %s", &n, trailing) != 1)
	{
		printf("%s is not a number\n", argv[3]);
		return -1;
	}

	// if second arg isn't one of the allowed characters
	if(s[0] != '+' &&
	   s[0] != '-' &&
	   s[0] != '*' &&
	   s[0] != '/')
	{
		printf("%c is an illegal operation\n", s[0]);
		return -1;
	} 

	// if all data is good, declare variables
	// there may be a simpler way to get the ints from the command
	// line arguments but I don't know what that might be.

	// lengths of argv[1] and argv[3]
	int len1;
	int len2;

	len1 = strlen(argv[1]);
	len2 = strlen(argv[3]);

	// char arrays to store argv[1] and argv[3] in of the appropriate length
	char  buff1[len1];
	char  buff2[len2];

	// iterators for the for loops
	int i, j;

	// vars to store actual integers in
	int num1, num2;

	// loop through argv[1] and store each char in the buff array
	for(i = 0; i < len1; i++)
	{
		buff1[i] = argv[1][i];
	}

	// convert the string (array) to an integer
	num1 = atoi(buff1);

	for(j = 0; j < len2; j++)
	{
		buff2[j] = argv[3][j];
	}
	
	num2 = atoi(buff2);
	
	// retrieve the correct operation and print results
	if(s[0] == '+')
	{
		printf("%i %c %i = %i\n", num1, s[0], num2, num1 + num2);
	}

	if(s[0] == '-')
	{
		printf("%i %c %i = %i\n", num1, s[0], num2, num1 - num2);
	}

	if(s[0] == '*')
	{
		printf("%i %c %i = %i\n", num1, s[0], num2, num1 * num2);
	}

	if(s[0] == '/')
	{
		printf("%i %c %i = %i\n", num1, s[0], num2, num1 / num2);
	}
	
	return 0;
}
