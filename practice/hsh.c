#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

int main(void)
{
    size_t buf_size = 0;
    char *buf = NULL;
    char *token;
    int status = 0;
    pid_t child_pid;

    while (1)
    {
        write(1, "#cisfun$ ", 9);

        // Read the command line
        if (getline(&buf, &buf_size, stdin) == EOF)
        {
            // Handle end of file condition
            printf("\n");
            free(buf);
            break;
        }

        // Remove newline character
        buf[strcspn(buf, "\n")] = '\0';

        token = strtok(buf, " ");

        if (token == NULL)
        {
            // Empty command line, prompt again
            continue;
        }

        child_pid = fork();

        if (child_pid == -1)
        {
            perror("Fork failed");
        }
        else if (child_pid == 0)
        {
            // Child process
            char *args[] = {token, NULL};
            if (execve(token, args, environ) == -1)
            {
                // Print error if executable not found
                fprintf(stderr, "%s: No such file or directory\n", token);
                _exit(EXIT_FAILURE);
            }
        }
        else
        {
            // Parent process
            waitpid(child_pid, &status, 0);
        }
    }

    free(buf);
    return 0;
}
