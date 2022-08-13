#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(){
    
    int xs,seqlen;
    int *loop;
    int looplen;
    int *h;
    
    h = (int*) calloc((9) , sizeof(int));
    
    printf("Please enter the sequence length: ");
    scanf("%d",&seqlen);
    
    printf("Please enter the first element of sequence: ");
    scanf("%d",&xs);
    
    loop = (int*) malloc((seqlen/2) * sizeof(int));
    
    /* I kept the length of the array permanently thanks to looplen variable and I sent it to function as parameter...*/
    looplen = seqlen/2;
    
    check_loop_iterative(generate_sequence,xs,seqlen,loop,&looplen);
    
    if(looplen == 0){
        printf("No loop found.\n\n\n");
    }
    
    else{
        printf("Loop: {");
    for(int i=0; i<looplen; i++){
        printf("%d", loop[i]);
    if(i != looplen - 1)
        printf(", ");
     }
        printf("}\n\n");
    }
    
    hist_of_firstdigits(generate_sequence,xs,seqlen,h,0);
    
    printf("Histogram of the sequence: {");
    for(int i=0;i<9;i++){
        printf("%d",h[i]);
        if(i!=8){
            printf(", ");
        }
    }
    printf("}\n\n\n");
    /* I used this function(free) because to re-memory a specific space that I have reserved in memory...*/
    free(h);
    free(loop);
    return 0;
}




