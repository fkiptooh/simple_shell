#include<stdio.h>
#include<stdlib.h>
int main(void) 
{
	size_t n = 10;
	char *buff;

	buff = malloc(sizeof(char) * 10);
	printf("&");
	getline(&buff,&n, stdin );
	printf("Your name is: %s", buff);
	printf("Buffer size is: %ld\n", n);

	free(buff);

	return(0);
}
