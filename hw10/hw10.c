#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define STACK_BLOCK_SIZE 10


int counter=1;


// A structure to represent a stack
typedef struct
{
    int * array;
    int currentsize;
    int maxsize;
} stack;




int init(stack * s);
stack* init_return();
int isFull(stack* stack);
int isEmpty(stack* stack);
int push(stack *s, int d);
int pop(stack* s);
void print(char fromPeg, char toPeg, int disk);
void move2(stack *src,stack *dest, char s, char d);


/* Bu programda kullanılan src en sol cubuk,aux orta cubuk, dest ise en sagdaki cubuktur...*/
 
 
// Driver Program
int main()
{
    // Input: number of disks
    int num_of_disks, total_num_of_moves;
    stack *array1, *array2, *array3;
    char s = 'J', d = 'K', a = 'L';
    
    printf("\nWarning:: Even though it gives correct results when LARGE NUMBERS are entered, it forces the computer.\n\n");
    printf("Enter the capasity:");
    scanf("%d",&num_of_disks);
    
    array1 = init_return();
    array2 = init_return();
    array3 = init_return();
    
 
    /*If number of disks is even, then interchange destination pole and auxiliary pole... */
    if (num_of_disks % 2 == 0)
    {
        char temp = d;
        d = a;
        a = temp;
    }
    /* I calculated the total number of moves to be made here and finished my code after this step...*/
    total_num_of_moves = pow(2, num_of_disks) - 1;
 
    /*Larger disks will be pushed first...*/
    for (int i = num_of_disks; i >= 1; i--)
    {
        push(array1, i);
    }
    
    /* I run my code inside the for loop until the total number of moves to be made is reached...*/
    for (int i = 1; i <= total_num_of_moves; i++)
    {
        if (i % 3 == 1)
        move2(array1, array3, s, d);
 
        else if (i % 3 == 2)
        move2(array1, array2, s, a);
 
        else if (i % 3 == 0)
        move2(array2, array3, a, d);
    }
 
    
    free(array1);
    free(array2);
    free(array3);
    
    return 0;
}



/* returns 1 if initialization is successful,return 0 if initialization is not successful... */
int init(stack * s){
    if (s!=NULL)
    {
        return 1;
    }
    return 0;
}


/* I create that function to create a stack.*/
stack * init_return()
{
    stack *array1;
    array1 = (stack*)malloc(sizeof(stack));
    /* If a stack is created, it does the necessary operations.*/
    if(init(array1)==1)
    {
        array1->array = (int*)malloc(STACK_BLOCK_SIZE * sizeof(int));
        for (int i = 0; i < STACK_BLOCK_SIZE; i++)
        {
            array1->array[i] = 0;
            
        }
        array1->currentsize = 0;
        array1->maxsize = STACK_BLOCK_SIZE;
    }
    return array1;
}

 
/* Stack is full when currentsize is equal to the last index.. */
int isFull(stack* stack)
{
    return (stack->currentsize == stack->maxsize - 1);
}
 


/* stack is empty when currentsize is equal to -1...*/

int isEmpty(stack* stack)
{
    return (stack->currentsize == -1);
}



/* the stack array will grow STACK_BLOCK_SIZE entries at a time */
int push(stack * s, int d){
    if (isFull(s))
    {
        return 0;
    }
    if (s->currentsize == s->maxsize)
    {
        s->maxsize++;
        s->array = (int*)realloc(s->array, s->maxsize);
    }
    s->array[s->currentsize] = d;
    s->currentsize++;
    return 1;
}




/* the stack array will shrink STACK_BLOCK_SIZE entries at a time... */
int pop(stack * s){
    if (isEmpty(s)){
        return -999;
    }
    if (s->currentsize == 0)
    {
        s->currentsize = 1;
    }
    s->array[s->currentsize - 1] = 0;
    s->currentsize--;
    if (s->maxsize > STACK_BLOCK_SIZE)
    {
        s->maxsize--;
        s->array = (int*)realloc(s->array, s->maxsize);
    }
    return s->array[s->currentsize - 1];
}




//Function to show the movement of disks
void print(char fromPeg, char toPeg, int disk)
{
    printf("%d. Move the disk %d from \'%c\' to \'%c\'\n",counter, disk, fromPeg, toPeg);
    counter++;
}
 



/*  i used this function to move from one bar to another...*/
void move2(stack *src,stack *dest, char s, char d)
{
    int pole1TopDisk = pop(src);
    int pole2TopDisk = pop(dest);
 
    /* When pole 1 is empty,enter... */
    if (pole1TopDisk == -999)
    {
        push(src, pole2TopDisk);
        print(d, s, pole2TopDisk);
    }
 
    /* When pole2 pole is empty,enter... */
    else if (pole2TopDisk == -999)
    {
        push(dest, pole1TopDisk);
        print(s, d, pole1TopDisk);
    }
 
    /* When top disk of pole1 > top disk of pole2,enter... */
    else if (pole1TopDisk > pole2TopDisk)
    {
        push(src, pole1TopDisk);
        push(src, pole2TopDisk);
        print(d, s, pole2TopDisk);
    }
 
    /* When top disk of pole1 < top disk of pole2,enter... */
    else
    {
        push(dest, pole2TopDisk);
        push(dest, pole1TopDisk);
        print(s, d, pole1TopDisk);
    }
}
