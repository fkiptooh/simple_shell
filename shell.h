#ifndef SHELL_H
#define SHELL_H-

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void print_func(const char *mess);

void prompt_display(void);

void execute(const char *command);

void read_input(char *command, size_t size);

#endif
