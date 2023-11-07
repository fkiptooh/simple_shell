#include "shell.h"

/**
 * main - Entry point
 *
 * Return: Always 0 on success
 */

int main(void)
{
	char command[1024];

	while (1)
	{
		prompt_display();
		read_input(command, sizeof(command));
		execute(command);
	}
	return (0);
}

