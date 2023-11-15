#include<stdio.h>
#include<stdlib.h>
int main(int ac, char **av)
{
	// int i;
	// int sum=0;
	// printf("argument count: %d\n", ac);
	// printf("Vector arguments is argv[]\n");
		while(*av != NULL)
		{
			printf("argv = %s\n", *av);
			av++;
			// sum += atoi(av);
		}
		// printf("Sum of arguments = %d\n", sum);
		return (0);
}
