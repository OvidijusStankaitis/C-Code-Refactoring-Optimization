#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *buffer;
    /*Initialised buffer with char*/
    buffer = malloc(17 * sizeof(char));
    strcpy(buffer, "Some random text");
    text_printer(buffer);
    free(buffer);
    return 0;
}

//"free(msg)" was not necessary and resulted in a double free error
void text_printer(char *msg)
{
    printf("%s\n", msg);
    // free(msg);
}