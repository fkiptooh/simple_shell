#include <stdio.h>
#include <stdlib.h>

void prompt_display() {
    printf("$ ");
}

char* read_input() {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);
    return strdup(buffer);
}

int main() {
    char* input;

    while (1) {
        prompt_display();
        input = read_input();


        free(input);
    }

    return 0;
}

