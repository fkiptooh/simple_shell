#include "shell.h"

/**
 * read_input - Function to read input from user
 * @command: Argument 1
 * @size: argument 2
 *
 * Return: Always 0 on success
 */

void read_input(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			print_func("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			print_func("No such file or directory\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
