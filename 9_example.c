#include <stdio.h>

int main(void)
{
    char copy_from[18] = "original_file.txt";
    char copy_to[16] = "copied_file.txt";

    //Instead of opening the same file over and over again, open it once
    FILE *original = NULL;
    FILE *copy = NULL;
    copy = fopen(copy_to, "a+");

    original = fopen(copy_from, "r");

    char line[500];

    while (fgets(line, sizeof(line), original)) {
        fprintf(copy, "%s", line);
    }

    //Instead of closing the same file over and over again, close it once
    fclose(original);
    fclose(copy);
    return 0;
}
