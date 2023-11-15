#include<stdio.h>
#include<stdlib.h>
int main(void) 
{
	size_t n = 0;
	char *buff = NULL;

	// buff = malloc(sizeof(char) * 10);
	printf("$ ");
	getline(&buff,&n, stdin );
	printf("%s", buff);
	// printf("Buffer size is: %ld\n", n);

	free(buff);

	return(0);
}
