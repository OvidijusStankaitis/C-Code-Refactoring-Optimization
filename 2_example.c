#include <stdio.h>
#include <string.h>

#define LEN 38 //Sizes smaller than 38 will cause buffer overflow

int main(void)
{
    char buffer[LEN];
    /*Used strncpy*/
    strncpy(buffer, "Copy this text to the buffer variable", LEN);
    printf("%s\n", buffer);
    return 0;
}