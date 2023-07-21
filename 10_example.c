#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DELIMETER ","

struct Person {
    char name[30];
    char surname[30];
    char number[30];
    struct Person *next;
};

struct Person* create_node(char *name, char *surname, char *number);
struct Person* create_address_node(char *address_line);
void add_to_list(struct Person **list, struct Person *node);
void print_list(struct Person *list);
void delete_list(struct Person **list);
void load_addresses(FILE *file, struct Person **list);


int main(void)
{
    char address_file_path[30] = "addresses.csv";
    struct Person *list = NULL;
    FILE *address_file = NULL;

    address_file = fopen(address_file_path, "r");

    if( address_file == NULL) {
        printf("Unable to open file\n");
        exit(1);
    }

    load_addresses(address_file, &list);
    print_list(list);
    delete_list(list);
    fclose(address_file);
    return 0;
}

void load_addresses(FILE *file, struct Person **list)
{
    char line[128];
    while (fgets(line, sizeof(line), file)) {
        struct Person *person = NULL;
        //This statement terminated the program when the first newline was met
        if(strcmp(line, "\n") == 0) {
            continue;
        }
        person = create_address_node(line);
        if (person != NULL) {
            add_to_list(list, person);
        }
    }
}

struct Person* create_address_node(char *address_line)
{
    struct Person *person = NULL;
    char *name;
    char *surname;
    char *number;

    name = strtok(address_line, DELIMETER);
    surname = strtok(NULL, DELIMETER);
    number = strtok(NULL, DELIMETER);

    person = create_node(name, surname, number);
    
    return person;
}

struct Person* create_node(char *name, char *surname, char *number)
{
    struct Person *person = NULL;
    person = (struct Person*) malloc(sizeof(struct Person));
    if (person == NULL) {
        return NULL;
    }
    strcpy(person->name, name);
    strcpy(person->surname, surname);
    strcpy(person->number, number);
    person->next = NULL;
    return person;
}

void add_to_list(struct Person **list, struct Person *person)
{
    struct Person* temp = *list;
    if (temp == NULL) {
        *list = person;
        return; 
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = person;
}

void print_list(struct Person *list)
{
    struct Person *temp = list;
    while (temp != NULL) {
        printf("%s %s %s", temp->name, temp->surname, temp->number);
        temp = temp->next;
    }
    //Added a new line here so that the prints look more neat
    printf("\n");
}

void delete_list(struct Person **list)
{
    //Freeing one node and then moving to the next
    struct Person *current = list;
    struct Person *next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    //Setting the list pointer to NULL after freeing the memory
    *list = NULL;
}
