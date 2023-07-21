#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    //For the most optimal solution i got the length of the sting and then allocated that length + 1
    //to the buffer. Any less space would result in a buffer overflow
    int len = strlen("Some random text") + 1; 
    char* buffer;
    buffer = (char*) malloc(sizeof(char) * len);
    strcpy(buffer, "Some random text");
    printf("%s\n", buffer);
    free(buffer);
    return 0;
}