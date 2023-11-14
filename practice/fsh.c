#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
	size_t buf_size = 0;
	char *buf = NULL;
	char *token;
	int i, status = 0;
	char **array;
	pid_t child_pid;

	while (1)
	{
		write(1, "#cisfun$ ", 9);
		getline(&buf, &buf_size, stdin);
		token = strtok(buf, "\t\n");
		array = malloc(sizeof(char *) * 1024);
		i = 0; // Initialize i to 0 for each iteration

		while (token)
		{
			array[i] = token;
			token = strtok(NULL, "\t\n");
			i++;
		}
		array[i] = NULL;
		child_pid = fork();

		if (child_pid == 0)
		{
			if (execve(array[0], array, NULL) == -1)
				perror("Error with exec");
		}
		else
		{
			wait(&status);
		}

		// Free memory allocated for array
		for (int j = 0; j < i; j++)
		{
			free(array[j]);
		}
		free(array);
	}

	free(buf); // Free the memory allocated for buf
	return 0;
}
