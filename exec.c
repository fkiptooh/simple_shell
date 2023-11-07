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
	char *args[2];

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
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
