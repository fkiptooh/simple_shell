#ifndef SHELL_H
#define SHELL_H

/**
 * Libraries meant for the simple shell
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/**
 * Function/ Methods
 */

void print_func(const char *mess);

void prompt_display(void);

void execute(const char *command);

void read_input(char *command, size_t size);

#endif
