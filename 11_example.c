#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Needed to allocate ome memory before putting anything inside the buffer
    char *user_input = (char*) malloc(sizeof(char) * 100);
    printf("Enter your text: ");
    fscanf(stdin, "%100[^\n]", user_input);
    printf("\nYour line -> %s\n", user_input);
    free(user_input);
    return 0;
}