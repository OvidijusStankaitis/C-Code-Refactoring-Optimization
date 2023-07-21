#include <stdio.h>

//Neded to change the value that was stored in the adress and then return it
void number_changer(int *var)
{
    printf("Number changer. Before change - %d\n", *var);
    *var = 123;
    printf("Number changer. After change - %d\n", *var);
}

int main(void)
{
    int var = 766;
    printf("Before change - %d\n", var);
    number_changer(&var);
    printf("After change - %d\n", var);
    return 0;
}