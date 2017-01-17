// Characters from command line arguments are sent to child process
// from parent process one at a time through pipe.
//
// Child process counts number of characters sent through pipe.
//
// Child process returns number of characters counted to parent process.
//
// Parent process prints number of characters counted by child process.
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	// variable decs
	pid_t		pid;
	int		comm[2];
	int		i = 1;
	int 		j = 0; 
	char 		ch;

	// test for bad data
	if(pipe(comm)) {
		printf("pipe error\n");
		return -1;
		}

	// call fork()
	pid = fork();

	// fork failed
	if (pid < 0) {
		printf("fork error %d\n", pid);
		return -1;
		}

	// pid == 0 references child process
	if(pid == 0) {
		// -- running in child process --
		int     nChars = 0;
		// close output side of pipe
		close(comm[1]);
		sleep(1);
		
		// read returns 0 when pipe is empty, so as long as 
		// read(comm[0], &ch, 1)) evaluates to true (nonzero)
		// we increment the number of chars
		while(read(comm[0], &ch, 1))
		{
			nChars++;
		}

		// close input side of pipe when all chars have been accounted for
		close(comm[0]);	

		// Return number of characters counted to parent process.
		return nChars;
		}
	else {
		// -- running in parent process -- (pid != 0)
		int     nChars = 0;
		int  	length = 0;
		// close input side of pipe on parent end
		close(comm[0]);

		printf("CS201 - Assignment 3 - Molly Novash\n");

		// traverse through each argument, besides argv[0]
		for(i = 1; i < argc; i++)
			{
			// for each arg, get length of arg (number of chars)
			length = strlen(argv[i]);
			// for each char from 0-length in position j, write to pipe
			for(j = 0; j < length; j++)
				{
				write(comm[1], &argv[i][j], 1);
			}
			
		} 
		
		// close output end of pipe
		close(comm[1]);
		
		// call waitpid/ reap child process
		waitpid(pid, &nChars, 0);

		printf("child counted %d characters\n", nChars/256);
		return 0;
		}
}
