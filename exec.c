#include "shell.h"

/**
 * execute - Function to execute command
 * @command: Command passed as string
 *
 * Return: 0 on success
 */

void execute(const char *command)
{
	pid_t child_pid = fork();
	char *args[1024];

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		int arg_count = 0;
		char *token = strtok((char *)command, " ");
		while (token != NULL && arg_count < (int)(sizeof(args) / sizeof(args[0]) - 1))
		{
			if (token[0] == '"')
			{
				char *q = strchr(token + 1, '"');

				if (q != NULL)
				{
					args[arg_count++] = strndup(token + 1, q - token - 1);
				}
				else
				{
					fprintf(stderr, "Error: %s\n", command);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				args[arg_count++] = strdup(token);
			}
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		if (execvp(args[0], args) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		args[0] = (char *)command;
		args[1] = NULL;

		if (execvp(command, args) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
