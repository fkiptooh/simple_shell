#include "shell.h"

/**
 * print_func - function to print
 * @format: argument 1
 *
 * Return: 0 on success
 */

void print_func(const char *format)
{
	write(STDOUT_FILENO, format, strlen(format));
}
