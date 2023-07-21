#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void genRandomText(int count, char *buffer)
{
    int i;
    for (i = 0; i < count; i++) {
        char symbol[1];
        int num = (rand() % (90 - 65 + 1)) + 65;
        sprintf(symbol,"%c", num);
        strcat(buffer, symbol);
    }
    buffer[count] = '\0';
}

int main()
{
    char *buffer = NULL;
    int i = 1;
    srand(time(0));

    //Allocated memory to the buffer before the while loop and kep reallocating it inside the while loop
    //Didn't reallocate memory if the i turned to 7, because that would be a wasteful preocedure
  
    buffer = (char*) malloc(i * sizeof(char) + 1);
    while(i < 7) {
        genRandomText(i, buffer);
        printf("Buffer - %s\n", buffer);
        i++;
        if(i != 7) buffer = (char*) realloc(buffer, i * sizeof(char) + 1);
    }
    free(buffer);
    return 0;
}