#include <stdio.h>
#include <stdlib.h>
#include "util.h"

/*I wrote this function to generate sequance as Collatz.. */
void generate_sequence (int xs, int currentlen, int seqlen, int *seq){
    /* I assigned value to first index of array.. */
    seq[currentlen]=xs;
    /* If the value I assigned is even, it devided by 2..*/
    if(xs%2==0){
       xs=xs/2;
    }
    /* If the value I assigned is odd, it multiply by 3 and sum 1..*/
    else{
        xs=3*xs+1;
    }
    if(seqlen==currentlen){
        return;
    }
    /* I did this function as recursive in here..Mentality of this recursive is to fill the array by increasing the index of the array each time...*/
    generate_sequence(xs, currentlen+1, seqlen, seq);
}

/*   I wrote this function to fill inside loop or when there is no any loop inside of sequence I assigned 0 to looplen variable..
 
 *seq : This is my array..
 
 ls :If there are a loop, this is starting of index of loop..
 
 le :If there are a loop, this is ending of index of loop..
 */
void check_loop_iterative(void (*f)(int,int,int,int*), int xs, int seqlen, int *loop, int *looplen){
    int ls,le;
    int *seq;
    /* I have allocated the required length field for the array..*/
    seq = (int*) malloc(seqlen * sizeof(int));
    generate_sequence (xs, 0, seqlen, seq);
   /* I printed my array named seq...*/
    if(*looplen==seqlen/2){
            printf("Sequence:  ");
            printf("{");
        for(int i=0;i<seqlen;i++){
            printf("%d",seq[i]);
            if(i<seqlen-1){
            printf(", ");
        }
    }
        printf("}\n\n\n");
    }
    /* I used looplen variable to see if an array has a loop certain length... */
    if(*looplen>1){
        printf("Checking if there is a loop of length %d...\n", *looplen);
        if(has_loop(seq, seqlen, *looplen, &ls, &le) == 1){
            printf("\n\n\nLoop detected with a length of %d.\n", *looplen);
            printf("The indexes of the loop's first occurance : %d (first digit), %d (last digit)\n", ls, le);
            for(int j=0;j<*looplen;j++){
                loop[j] = seq[ls + j];
            }
            /* I used this function(free) because to re-memory a specific space that I have reserved in memory...*/
            free(seq);
            return;
        }
        else{
            /* I decreased value of looplen variable to create a recursive function...*/
            *looplen-=1;
            /* I used this function(free) because to re-memory a specific space that I have reserved in memory...*/
            free(seq);
            /* I called my function as recursive in here..*/
            check_loop_iterative(generate_sequence, xs, seqlen, loop, looplen);
        }
    }
    else{
        /* I used this function(free) because to re-memory a specific space that I have reserved in memory...*/
        free(seq);
        *looplen=0;
    }
}


int has_loop(int *arr, int n, int looplen, int *ls, int *le){
    int sayac=0,i=0,j=0;
    int length_of_array=n;
    
    while(i<length_of_array){
        sayac=0;
        j=i;
        while(j<i+looplen){
            if(arr[j] == arr[j + looplen]){
                sayac++;
            }
            j++;
            }
        /* If length of looplen and value of sayac variable, we found loop in there..I saved the start address of the loop in the ls variable and the end index of the loop in the le variable...*/
            if(sayac == looplen){
                *ls=j-looplen;
                *le=j-1;
                return 1;
            }
        i++;
        }
    return 0;
    }


void hist_of_firstdigits(void (*f)(int,int,int,int*), int xs, int seqlen, int *h, int digit){
    int *array;
    /* I have allocated the required length field for the array..*/
    array = (int*) malloc(seqlen * sizeof(int));
    generate_sequence (xs, 0, seqlen, array);
    
    if(digit<seqlen){
        while(array[digit]>9){
            array[digit]/=10;
        }
        h[array[digit]-1]++;
    }
    else{
        return;
    }
    /* I used this function(free) because to re-memory a specific space that I have reserved in memory...*/
    free(array);
    /* I called my function as recursive in here..*/
    hist_of_firstdigits(generate_sequence,xs,seqlen,h,digit+1);
}
