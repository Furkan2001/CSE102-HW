#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct table
{
    char **field;
    char **type;
    int *isNull;
    int *isKey;
    
}table;


typedef struct tables
{
    struct tables *next;
    table * t;
    
}tables;


typedef struct database
{
    tables * tList; /* to be implemented as a linked list */
    int n; /* num of entries */
    char * name; /* table name */
    
}database;


void create_database(char *name);
void show_table(database *d);
void desc_table(database *d, table *t);
void insert_table(database *d, table *t);
void remove_table(database *d,char *name);
void insert_key(database *d,table *t,int key_value);


int main()
{
    int kosul=1,choice;
    while(kosul)
    {
        printf("1-Create database\n");
        printf("2-Show Table\n");
        printf("3- Desc Table\n");
        printf("4-Insert Table\n");
        printf("5-Remove Table\n");
        printf("6-Insert Key\n");
        printf("7-EXIT\n\n");
        
        printf("Your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                
                create_database("database.txt");
                
                
                
                break;
            case 2:
                
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                printf("Program TERMINATED\n\n");
                kosul=0;
                break;
            default:
                printf("Value you entered is not valid...Try again..\n");
                break;
        }
        
    }
    
    
    
    return 0;
}




void create_database(char *name)
{
    FILE* file;
    if((file = fopen(name,"r"))==NULL)
    {
        printf("Database is created...\n");
        file = fopen(name,"a+");
    }
    else
    {
        printf("You have already created a database...\n\n");
    }
}

                


void show_table(database *d)
{
    
}




void desc_table(database *d, table *t)
{
    
}




void insert_table(database *d, table *t)
{
    
}



void remove_table(database *d,char *name)
{
    
}




void insert_key(database *d,table *t,int key_value)
{
    
}
