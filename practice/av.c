#include<stdio.h>
#include<stdlib.h>
int main(int ac, char **av)
{
	int i;
	int sum=0;
	printf("argument count: %d\n", ac);
	printf("Vector arguments is argv[]\n");
		for(i = 1; i < ac; i++)
		{
			printf("argv[%d] = %s\n", i, av[i]);
			sum += atoi(av[i]);
		}
		printf("Sum of arguments = %d\n", sum);
		return (0);
}
