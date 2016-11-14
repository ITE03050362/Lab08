#include<stdio.h>
#include<stdlib.h>

int main()
{

	int pid , status = 0;
	int i;

	for(i=0 ; i<3 ; i++)  /*  3 child processes */
	{
		pid = fork();

		if(pid != 0)
		{
			printf("Parent process: \n");
			printf("\t child's id=%d \n",pid);
			pid = wait(&status);
		}

		else
		{
			printf("Child process: \n");
			printf("\t my id=%d \n",getpid());         /*  my=child's  */
			printf("\t parent's id=%d \n",getppid());
			exit(status);
		}
	}
}