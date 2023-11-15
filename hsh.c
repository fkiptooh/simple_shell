#include "shell.h"

/**
 * main - simple shell
 *
 * Return: Always 0.
 */

int main(void)
{
	size_t buf_size = 0;
	char *buf = NULL;
	char *token;
	int status, i = 0;
	char **array;
	pid_t child_pid;

	while (1)
	{
		write(1, "#cisfun$ ", 9);
		getline(&buf, &buf_size, stdin);
		token = strtok(buf, "\t\n");
		array = malloc(sizeof(char *) * 1024);
		while (1)
		{
			write(1, "#cisfun$ ", 9);
			getline(&buf, &buf_size, stdin);
			token = strtok(buf, "\t\n");
			array = malloc(sizeof(char *) * 1024);
			i = 0;
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
					perror("Error with execve");
			}
			else
			{
				wait(&status);
			}
			for (int j = 0; j < i; j++)
			{
				free(array[j]);
			}
			free(array);
		}
		free(buf);
		return (0);
	}
}
