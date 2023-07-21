#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//The size can be passed along as an argument now
//Also the use of ** and & allows the function to modify the size of buffer by passing its memory adress
void mem_alloc(char **buffer, int size)
{
    *buffer = (char*) malloc(size * sizeof(char));
}

int main(void)
{
    char *buffer = NULL;
    int size = strlen("Some random text to be copied to the buffer") + 1;
    mem_alloc(&buffer, size);
    strcpy(buffer, "Some random text to be copied to the buffer");
    printf("%s\n", buffer);
    free(buffer);
    return 0;
}