#include <stdio.h>


void number_printer(int *var)
{
    //Earlier it was printing the adress of the var, not it is printing the value stored in that adress
    printf("Number is - %d\n", *var); 
}

int main(void)
{
    int var = 345;
    number_printer(&var);
    return 0;
}