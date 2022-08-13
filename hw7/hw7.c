#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 15
#define COL 15

void printMap(char array[ROW][COL]);
int dice(void);
int my_strlen(char array[]);
void yuas(char array[],char arr[][COL]);
void sosa(char array[],char arr[][COL]);
void asyu(char array[],char arr[][COL]);
void saso(char array[],char arr[][COL]);
void cap1(char array[],char arr[][COL]);
void cap2(char array[],char arr[][COL]);                               //  THESE
void cap3(char array[],char arr[][COL]);                              //          ARE
void cap4(char array[],char arr[][COL]);                             //                MY FUNCTIONS...
int control(char array[],char arr[]);
int yuas1(char array[],char arr[][COL],int x,int y);
int sosa1(char array[],char arr[][COL],int r,int c);
int asyu1(char array[],char arr[][COL],int x,int y);
int saso1(char array[],char arr[][COL],int x,int y);
int cap11(char array[],char arr[][COL],int x,int y);
int cap21(char array[],char arr[][COL],int x,int y);
int cap31(char array[],char arr[][COL],int x,int y);
int cap41(char array[],char arr[][COL],int x,int y);


int main(){
    char array[ROW][COL],word_array[7][20],space[20];
    /* array  :: I created an array named array to make wordtable..*/
    /* word_array :: I created an array named word_array to take string from file..*/
    int word[20],k=0,choice,kontrol=1;
    FILE* fp;
    srand(time(NULL));
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            array[i][j]=' ';
        }
    }
    do{
            k=0;
        /* I AM TAKING RANDOM STRINGS FROM FILE IN HERE...*/
        while(k<7){
        word[k]=dice();
        fp=fopen("wordlist.txt","r");
        for(int i=1;i<word[k];i++){
            fscanf(fp,"%s\n",space);
        }
        fscanf(fp,"%s\n",word_array[k]);
        fclose(fp);
            k++;
        }
        //I ASSIGNED RANDOM WORDS TO A ARRAY NAMED word_array...
        //I used the array named space only to skip lines in the file...
    }
    while( word[0]==word[1] || word[0]==word[2] || word[0]==word[3] || word[0]==word[4] || word[0]==word[5] || word[0]==word[6] || word[1]==word[2] || word[1]==word[3] || word[1]==word[4] || word[1]==word[5] || word[1]==word[6] || word[2]==word[3] || word[2]==word[4] || word[2]==word[5] || word[2]==word[6] || word[3]==word[4] || word[3]==word[5] || word[3]==word[6] || word[4]==word[5] || word[4]==word[6] || word[5]==word[6]);
    //I choose words in different indexes in here...
    printf("\n\n\n");
    printf("The first number on the screen reports the index of the array\nThe second number tells you how the word is written in the word table.\n0-From top to bottom\n1-From left to right\n2-From bottom to top\n3-From right to left\n4-Diagonal\n5-Diagonal\n6-Diagonal\n7-Diagonal");
    printf("\n\n\n");
    for(int i=0;i<7;i++){
        choice=rand()%8;
        switch(choice){
            case 0:
                printf("%d\t",i);  // I printed on the screen which string corresponds to..
                printf("%d\t",choice);  // I printed that the string was transferred to word table according to which function..
                printf("%s\n",word_array[i]);
                yuas(word_array[i],array);
                break;
            case 1:
                printf("%d\t",i);   // I printed on the screen which string corresponds to..
                printf("%d\t",choice);  // I printed that the string was transferred to word table according to which function..
                printf("%s\n",word_array[i]);
                sosa(word_array[i],array);
                break;
            case 2:
                printf("%d\t",i);    // I printed on the screen which string corresponds to..
                printf("%d\t",choice);  // I printed that the string was transferred to word table according to which function..
                printf("%s\n",word_array[i]);
                asyu(word_array[i],array);
                break;
            case 3:
                printf("%d\t",i);    // I printed on the screen which string corresponds to..
                printf("%d\t",choice);  // I printed that the string was transferred to word table according to which function..
                printf("%s\n",word_array[i]);
                saso(word_array[i],array);
                break;
            case 4:
                printf("%d\t",i);    // I printed on the screen which string corresponds to..
                printf("%d\t",choice);  // I printed that the string was transferred to word table according to which function..
                printf("%s\n",word_array[i]);
                cap1(word_array[i],array);
                break;
            case 5:
                printf("%d\t",i);    // I printed on the screen which string corresponds to..
                printf("%d\t",choice);  // I printed that the string was transferred to word table according to which function..
                printf("%s\n",word_array[i]);
                cap2(word_array[i],array);
                break;
            case 6:
                printf("%d\t",i);     // I printed on the screen which string corresponds to..
                printf("%d\t",choice);   // I printed that the string was transferred to word table according to which function..
                printf("%s\n",word_array[i]);
                cap3(word_array[i],array);
                break;
            case 7:
                printf("%d\t",i);      // I printed on the screen which string corresponds to..
                printf("%d\t",choice);   // I printed that the string was transferred to word table according to which function..
                printf("%s\n",word_array[i]);
                cap4(word_array[i],array);
                break;
        }
    }
    /* I filled inside my array in here...*/
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(array[i][j]==' '){
                array[i][j] = '+';
                /*
            word[i]=dice();
        if(word[i]>26){
            word[i]=word[i]%26;
        }
        array[i][j]=word[i]+96;
                */
            }
        }
    }

    char string[15],real_string[10];
    int r,c,hata=0,puan=0;

    while(kontrol){
        printf("\n\n");
        printMap(array);
        printf("\nEnter word and then coordinates:");
    fgets(string,sizeof(string),stdin);
    sscanf(string,"%s %d %d\n",real_string,&r,&c);
        if(real_string[0]==':' && real_string[1]=='q' && my_strlen(real_string)==2){
            printf("Program terminated\n");
            return 0;
        }
    else if(my_strlen(real_string)>5){
        hata++;
        printf("The string you entered is very long.. ERROR!\nYou have only %d lefts.\n",(3-hata));
    }
    else if(r>14 || c>14){
        hata++;
        printf("The coordinates you entered is invalid.. ERROR!\nYou have only %d lefts.\n",(3-hata));
    }
    else if(r<0 || c<0){
        hata++;
        printf("The coordinates you entered is invalid.. ERROR!\nYou have only %d lefts.\n",3-hata);
    }
    else if(control(real_string,word_array[0])==0 && control(real_string,word_array[1])==0 && control(real_string,word_array[2])==0 && control(real_string,word_array[3])==0 && control(real_string,word_array[4])==0 && control(real_string,word_array[5])==0 && control(real_string,word_array[6])==0){
        hata++;
        printf("The string you entered did not match any words.. ERROR!\nYou have only %d lefts.\n",(3-hata));
    }
    else{
        if(yuas1(real_string,array,r,c)==1){
            yuas1(real_string,array,r,c);
            puan+=2;
            printf("You got two points.Your total points: %d\n",puan);
        }
        else if(sosa1(real_string,array,r,c)==1){
            sosa1(real_string,array,r,c);
            puan+=2;
            printf("You got two points.Your total points: %d\n",puan);
        }
        else if(asyu1(real_string,array,r,c)==1){
            asyu1(real_string,array,r,c);
            puan+=2;
            printf("You got two points.Your total points: %d\n",puan);
        }
        else if(saso1(real_string,array,r,c)==1){
            saso1(real_string,array,r,c);
            puan+=2;
            printf("You got two points.Your total points: %d\n",puan);
        }
        else if(cap11(real_string,array,r,c)==1){
            cap11(real_string,array,r,c);
            puan+=2;
            printf("You got two points.Your total points: %d\n",puan);
        }
        else if(cap21(real_string,array,r,c)==1){
            cap21(real_string,array,r,c);
            puan+=2;
            printf("You got two points.Your total points: %d\n",puan);
        }
        else if(cap31(real_string,array,r,c)==1){
            cap31(real_string,array,r,c);
            puan+=2;
            printf("You got two points.Your total points: %d\n",puan);
        }
        else if(cap41(real_string,array,r,c)==1){
            cap41(real_string,array,r,c);
            puan+=2;
            printf("You got two points.Your total points: %d\n",puan);
        }
        else{
            hata++;
            printf("Wrong choice! You have only %d lefts.\n",(3-hata));
        }
    }
        if(hata==3){
            printf("You made 3 mistakes and lost...\n\nYOUR SCORE IS %d\n\n",puan);
            return 0;
        }
        if(puan==14){
            printf("YOU WON THIS GAME... YOUR POINT IS %d\n",puan);
            return 0;
        }
    }
    return 0;
}


/* I wrote this function to print array as output...*/
void printMap(char array[ROW][COL]){
    int i,j;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            printf("%c ",array[i][j]);
                }
            printf("\n");
            }
}


/*  I wrote this function to take random number when ı call it...*/
int dice(void){
    int rastgele;
    rastgele=1+rand()%50;
    return rastgele;
}


//I wrote a function that finds the length of the string... For example length of world is 5...
int my_strlen(char array[]){
    int i=0;
    while(array[i]!='\0'){
        i++;
    }
    return i;
}


/*
      I wrote this function to pass the string into the array from top to bottom
 
 rastgele :: it is random number..
 rastgele2 :: it is also random numbeer..
 sayac :: I used this variable for counting...
 
 */
void yuas(char array[],char arr[][COL]){
    int rastgele,rastgele2,sayac=0,validate=1;
    while(validate){
        sayac=0;
    rastgele2 = rand()%14;
    rastgele = rand()%(14-my_strlen(array));
    /* I used these indexes to pass the string into the array from top to bottom...*/
    for(int i=0;i<my_strlen(array);i++){
        if(arr[rastgele+i][rastgele2]==' '){
            /* If the regions corresponding to the random numbers are empty in the array, I increase the sayac by 1.*/
            sayac++;
        }
    }
    /* If this region in the array is empty, I throw my string into the array...*/
    if(sayac==my_strlen(array)){
        validate=0;
        for(int i=0;i<my_strlen(array);i++){
            arr[rastgele+i][rastgele2]=array[i];
        }
    }
    /*If this region in the array is full, I returned my loop again...*/
    }
}


/*
      I wrote this function to pass the string into the array from left to right
 
 rastgele :: it is random number..
 rastgele2 :: it is also random numbeer..
 sayac :: I used this variable for counting...
 
 */
void sosa(char array[],char arr[][COL]){
    int rastgele,rastgele2,sayac=0,validate=1;
    while(validate){
        sayac=0;
    rastgele = rand()%14;
    rastgele2 = rand()%(14-my_strlen(array));
    /* I used these indexes to pass the string into the array from left to right...*/
    for(int i=0;i<my_strlen(array);i++){
        if(arr[rastgele][rastgele2+i]==' '){
            /* If the regions corresponding to the random numbers are empty in the array, I increase the sayac by 1.*/
            sayac++;
        }
    }
    /* If this region in the array is empty, I throw my string into the array...*/
    if(sayac==my_strlen(array)){
        validate=0;
        for(int i=0;i<my_strlen(array);i++){
            arr[rastgele][rastgele2+i]=array[i];
        }
    }
        /*If this region in the array is full, I returned my loop again...*/
    }
}


/*
      I wrote this function to pass the string into the array from bottom to top..
 
 rastgele :: it is random number..
 rastgele2 :: it is also random numbeer..
 sayac :: I used this variable for counting...
 
 */
void asyu(char array[],char arr[][COL]){
    int rastgele,rastgele2,sayac=0,validate=1;
    while(validate){
        sayac=0;
    rastgele2 = rand()%14;
    rastgele = my_strlen(array) + rand()%(14-my_strlen(array));

    for(int i=0;i<my_strlen(array);i++){
        if(arr[rastgele-i][rastgele2]==' '){
            /* If the regions corresponding to the random numbers are empty in the array, I increase the sayac by 1.*/
            sayac++;
        }
    }
    /* If this region in the array is empty, I throw my string into the array...*/
    if(sayac==my_strlen(array)){
        validate=0;
        for(int i=0;i<my_strlen(array);i++){
            arr[rastgele-i][rastgele2]=array[i];
        }
    }
        /*If this region in the array is full, I returned my loop again...*/
    }
}


/*
      I wrote this function to pass the string into the array from right to left..
 
 rastgele :: it is random number..
 rastgele2 :: it is also random numbeer..
 sayac :: I used this variable for counting...
 
 */
void saso(char array[],char arr[][COL]){
    int rastgele,rastgele2,sayac=0,validate=1;
    while(validate){
        sayac=0;
    rastgele = rand()%14;
    rastgele2 = my_strlen(array) + rand()%(14-my_strlen(array));

    for(int i=0;i<my_strlen(array);i++){
        if(arr[rastgele][rastgele2-i]==' '){
            /* If the regions corresponding to the random numbers are empty in the array, I increase the sayac by 1.*/
            sayac++;
        }
    }
    /* If this region in the array is empty, I throw my string into the array...*/
    if(sayac==my_strlen(array)){
        validate=0;
        for(int i=0;i<my_strlen(array);i++){
            arr[rastgele][rastgele2-i]=array[i];
        }
    }
        /*If this region in the array is full, I returned my loop again...*/
    }
}


/*
      I wrote this function to pass the string into the array as diagonally..
 
 rastgele :: it is random number..
 rastgele2 :: it is also random numbeer..
 sayac :: I used this variable for counting...
 uzunluk :: I used this variable to calculate length of string...
 
 */
void cap1(char array[],char arr[][COL]){
    int rastgele,rastgele2,uzunluk,sayac=0,validate=1;
    while(validate){
        sayac=0;
    uzunluk=my_strlen(array);
    rastgele = rand()%14;
    rastgele2 = rand()%14;
    if((rastgele+uzunluk)<14 && (rastgele2+uzunluk)<14){
        for(int i=0;i<my_strlen(array);i++){
            if(arr[rastgele+i][rastgele2+i]==' '){
                /* If the regions corresponding to the random numbers are empty in the array, I increase the sayac by 1.*/
                sayac++;
            }
        }
        /* If this region in the array is empty, I throw my string into the array...*/
        if(sayac==my_strlen(array)){
            validate=0;
            for(int i=0;i<my_strlen(array);i++){
                arr[rastgele+i][rastgele2+i]=array[i];
            }
        }
        /*If this region in the array is full, I returned my loop again...*/
    }
    else{
        if(rastgele>5){
        rastgele-=uzunluk;
        }
        if(rastgele2>5){
        rastgele2-=uzunluk;
        }
        for(int i=0;i<my_strlen(array);i++){
            if(arr[rastgele+i][rastgele2+i]==' '){
                /* If the regions corresponding to the random numbers are empty in the array, I increase the sayac by 1.*/
                sayac++;
            }
        }
        /* If this region in the array is empty, I throw my string into the array...*/
        if(sayac==my_strlen(array)){
            validate=0;
            for(int i=0;i<my_strlen(array);i++){
                arr[rastgele+i][rastgele2+i]=array[i];
            }
        }
        /*If this region in the array is full, I returned my loop again...*/
        }
    }
}


/*
      I wrote this function to pass the string into the array as diagonally..
 
 rastgele :: it is random number..
 rastgele2 :: it is also random numbeer..
 sayac :: I used this variable for counting...
 uzunluk :: I used this variable to calculate length of string...
 
 */
void cap2(char array[],char arr[][COL]){
    int rastgele,rastgele2,uzunluk,sayac=0,validate=1;
    while(validate){
        sayac=0;
    uzunluk=my_strlen(array);
    rastgele = rand()%14;
    rastgele2 = rand()%14;
    if((rastgele-uzunluk)>-1 && (rastgele2-uzunluk)>-1){
        for(int i=0;i<my_strlen(array);i++){
            if(arr[rastgele-i][rastgele2-i]==' '){
                /* If the regions corresponding to the random numbers are empty in the array, I increase the sayac by 1.*/
                sayac++;
            }
        }
        /* If this region in the array is empty, I throw my string into the array...*/
        if(sayac==my_strlen(array)){
            validate=0;
            for(int i=0;i<my_strlen(array);i++){
                arr[rastgele-i][rastgele2-i]=array[i];
            }
        }
        /*If this region in the array is full, I returned my loop again...*/
    }
    else{
        if(rastgele<uzunluk){
            rastgele+=uzunluk;
        }
        if(rastgele2<uzunluk){
        rastgele2+=uzunluk;
        }
        for(int i=0;i<my_strlen(array);i++){
            if(arr[rastgele-i][rastgele2-i]==' '){
                /* If the regions corresponding to the random numbers are empty in the array, I increase the sayac by 1.*/
                sayac++;
            }
        }
        /* If this region in the array is empty, I throw my string into the array...*/
        if(sayac==my_strlen(array)){
            validate=0;
            for(int i=0;i<my_strlen(array);i++){
                arr[rastgele-i][rastgele2-i]=array[i];
            }
        }
        /*If this region in the array is full, I returned my loop again...*/
        }
    }
}


/*
      I wrote this function to pass the string into the array as diagonally..
 
 rastgele :: it is random number..
 rastgele2 :: it is also random numbeer..
 sayac :: I used this variable for counting...
 uzunluk :: I used this variable to calculate length of string...
 
 */
void cap3(char array[],char arr[][COL]){
    int rastgele,rastgele2,uzunluk,sayac=0,validate=1;
    while(validate){
        sayac=0;
    uzunluk=my_strlen(array);
    rastgele = rand()%14;
    rastgele2 = rand()%14;
    if((rastgele+uzunluk)>-1 && (rastgele2-uzunluk)>-1){
        for(int i=0;i<my_strlen(array);i++){
            if(arr[rastgele+i][rastgele2-i]==' '){
                /* If the regions corresponding to the random numbers are empty in the array, I increase the sayac by 1.*/
                sayac++;
            }
        }
        /* If this region in the array is empty, I throw my string into the array...*/
        if(sayac==my_strlen(array)){
            validate=0;
            for(int i=0;i<my_strlen(array);i++){
                arr[rastgele+i][rastgele2-i]=array[i];
            }
        }
        /*If this region in the array is full, I returned my loop again...*/
    }
    else{
        if(rastgele<uzunluk){
            rastgele+=uzunluk;
        }
        if(rastgele2<uzunluk){
        rastgele2+=uzunluk;
        }
        for(int i=0;i<my_strlen(array);i++){
            if(arr[rastgele+i][rastgele2-i]==' '){
                /* If the regions corresponding to the random numbers are empty in the array, I increase the sayac by 1.*/
                sayac++;
            }
        }
        /* If this region in the array is empty, I throw my string into the array...*/
        if(sayac==my_strlen(array)){
            validate=0;
            for(int i=0;i<my_strlen(array);i++){
                arr[rastgele+i][rastgele2-i]=array[i];
            }
        }
        /*If this region in the array is full, I returned my loop again...*/
        }
    }
}


/*
      I wrote this function to pass the string into the array as diagonally..
 
 rastgele :: it is random number..
 rastgele2 :: it is also random numbeer..
 sayac :: I used this variable for counting...
 uzunluk :: I used this variable to calculate length of string...
 
 */
void cap4(char array[],char arr[][COL]){
    int rastgele,rastgele2,uzunluk,sayac=0,validate=1;
    while(validate){
        sayac=0;
    uzunluk=my_strlen(array);
    rastgele = rand()%14;
    rastgele2 = rand()%14;
    if((rastgele-uzunluk)>-1 && (rastgele2+uzunluk)>-1){
        for(int i=0;i<my_strlen(array);i++){
            if(arr[rastgele-i][rastgele2+i]==' '){
                /* If the regions corresponding to the random numbers are empty in the array, I increase the sayac by 1.*/
                sayac++;
            }
        }
        /* If this region in the array is empty, I throw my string into the array...*/
        if(sayac==my_strlen(array)){
            validate=0;
            for(int i=0;i<my_strlen(array);i++){
                arr[rastgele-i][rastgele2+i]=array[i];
            }
        }
        /*If this region in the array is full, I returned my loop again...*/
    }
    else{
        if(rastgele<uzunluk){
            rastgele+=uzunluk;
        }
        if(rastgele2<uzunluk){
        rastgele2+=uzunluk;
        }
        for(int i=0;i<my_strlen(array);i++){
            if(arr[rastgele-i][rastgele2+i]==' '){
                /* If the regions corresponding to the random numbers are empty in the array, I increase the sayac by 1.*/
                sayac++;
            }
        }
        /* If this region in the array is empty, I throw my string into the array...*/
        if(sayac==my_strlen(array)){
            validate=0;
            for(int i=0;i<my_strlen(array);i++){
                arr[rastgele-i][rastgele2+i]=array[i];
            }
        }
        /*If this region in the array is full, I returned my loop again...*/
        }
    }
}


/*
 I wrote this function to compare if two arrays are the same..
 
 uzunluk :: I used this variable to hold length of array..
 uzunluk2 :: I used this variable to hold length of another array..
 
 
 */
int control(char array[],char arr[]){
    int uzunluk,validate=0,uzunluk2;
    uzunluk=my_strlen(array);
    uzunluk2=my_strlen(arr);
    for(int i=0;i<uzunluk;i++){
        /* I compared length of arrays and their values in whole indexes..*/
        if(array[i]==arr[i] && uzunluk==uzunluk2){
            validate++;
        }
    }
    if(validate==uzunluk){
        validate=1;
    }
    else{
        validate=0;
    }
    /* I return 1 if the arrays are equal to each other, and 0 if they are not... */
    return validate;
}


/*
 I am looking for a string in the index entered from top to bottom...
 
 x :: I used this as index of array..
 y :: I used this as index of array..
 uzunluk :: I used this variable to hold length of array..
 validate :: I used this variable for counting...
 
 */
int yuas1(char array[],char arr[][COL],int x,int y){
    int uzunluk,validate=0;
    uzunluk=my_strlen(array);
    for(int i=0;i<uzunluk;i++){
        if(array[i]==arr[x+i][y]){
            /* Increase validate variable by 1 if equality is satisfied..*/
            validate++;
        }
    }
    if(validate==uzunluk){
        validate=1;
    }
    else{
        validate=0;
    }
    /* If the two arrays are equal,I made these indexes as X...*/
    if(validate==1){
        for(int i=0;i<uzunluk;i++){
            arr[x+i][y]='X';
        }
    }
    /* I returned 1 if the two arrays are equal, otherwise 0 */
    return validate;
}


/*
 I am looking for a string in the index entered from left to right...
 
 x :: I used this as index of array..
 y :: I used this as index of array..
 uzunluk :: I used this variable to hold length of array..
 validate :: I used this variable for counting...
 
 */
int sosa1(char array[],char arr[][COL],int x,int y){
    int uzunluk,validate=0;
    uzunluk=my_strlen(array);
    for(int i=0;i<uzunluk;i++){
        if(array[i]==arr[x][y+i]){
            /* Increase validate variable by 1 if equality is satisfied..*/
            validate++;
        }
    }
    if(validate==uzunluk){
        validate=1;
    }
    else{
        validate=0;
    }
    /* If the two arrays are equal,I made these indexes as X...*/
    if(validate==1){
        for(int i=0;i<uzunluk;i++){
            arr[x][y+i]='X';
        }
    }
    /* I returned 1 if the two arrays are equal, otherwise 0 */
    return validate;
}


/*
 I am looking for a string in the index entered from bottom to top...
 
 x :: I used this as index of array..
 y :: I used this as index of array..
 uzunluk :: I used this variable to hold length of array..
 validate :: I used this variable for counting...
 
 */
int asyu1(char array[],char arr[][COL],int x,int y){
    int uzunluk,validate=0;
    uzunluk=my_strlen(array);
    for(int i=0;i<uzunluk;i++){
        if(array[i]==arr[x-i][y]){
            /* Increase validate variable by 1 if equality is satisfied..*/
            validate++;
        }
    }
    if(validate==uzunluk){
        validate=1;
    }
    else{
        validate=0;
    }
    /* If the two arrays are equal,I made these indexes as X...*/
    if(validate==1){
        for(int i=0;i<uzunluk;i++){
            arr[x-i][y]='X';
        }
    }
    /* I returned 1 if the two arrays are equal, otherwise 0 */
    return validate;
}


/*
 I am looking for a string in the index entered from right to left...
 
 x :: I used this as index of array..
 y :: I used this as index of array..
 uzunluk :: I used this variable to hold length of array..
 validate :: I used this variable for counting...
 
 */
int saso1(char array[],char arr[][COL],int x,int y){
    int uzunluk,validate=0;
    uzunluk=my_strlen(array);
    for(int i=0;i<uzunluk;i++){
        if(array[i]==arr[x][y-i]){
            /* Increase validate variable by 1 if equality is satisfied..*/
            validate++;
        }
    }
    if(validate==uzunluk){
        validate=1;
    }
    else{
        validate=0;
    }
    /* If the two arrays are equal,I made these indexes as X...*/
    if(validate==1){
        for(int i=0;i<uzunluk;i++){
            arr[x][y-i]='X';
        }
    }
    /* I returned 1 if the two arrays are equal, otherwise 0 */
    return validate;
}


/*
 I am looking for a string in the index entered as diagonally...
 
 x :: I used this as index of array..
 y :: I used this as index of array..
 uzunluk :: I used this variable to hold length of array..
 validate :: I used this variable for counting...
 
 */
int cap11(char array[],char arr[][COL],int x,int y){
    int uzunluk,validate=0;
    uzunluk=my_strlen(array);
    for(int i=0;i<uzunluk;i++){
        if(array[i]==arr[x+i][y+i]){
            /* Increase validate variable by 1 if equality is satisfied..*/
            validate++;
        }
    }
    if(validate==uzunluk){
        validate=1;
    }
    else{
        validate=0;
    }
    /* If the two arrays are equal,I made these indexes as X...*/
    if(validate==1){
        for(int i=0;i<uzunluk;i++){
            arr[x+i][y+i]='X';
        }
    }
    /* I returned 1 if the two arrays are equal, otherwise 0 */
    return validate;
}


/*
 I am looking for a string in the index entered as diagonally...
 
 x :: I used this as index of array..
 y :: I used this as index of array..
 uzunluk :: I used this variable to hold length of array..
 validate :: I used this variable for counting...
 
 */
int cap21(char array[],char arr[][COL],int x,int y){
    int uzunluk,validate=0;
    uzunluk=my_strlen(array);
    for(int i=0;i<uzunluk;i++){
        if(array[i]==arr[x-i][y-i]){
            /* Increase validate variable by 1 if equality is satisfied..*/
            validate++;
        }
    }
    if(validate==uzunluk){
        validate=1;
    }
    else{
        validate=0;
    }
    /* If the two arrays are equal,I made these indexes as X...*/
    if(validate==1){
        for(int i=0;i<uzunluk;i++){
            arr[x-i][y-i]='X';
        }
    }
    /* I returned 1 if the two arrays are equal, otherwise 0 */
    return validate;
}


/*
 I am looking for a string in the index entered as diagonally...
 
 x :: I used this as index of array..
 y :: I used this as index of array..
 uzunluk :: I used this variable to hold length of array..
 validate :: I used this variable for counting...
 
 */
int cap31(char array[],char arr[][COL],int x,int y){
    int uzunluk,validate=0;
    uzunluk=my_strlen(array);
    for(int i=0;i<uzunluk;i++){
        if(array[i]==arr[x+i][y-i]){
            /* Increase validate variable by 1 if equality is satisfied..*/
            validate++;
        }
    }
    if(validate==uzunluk){
        validate=1;
    }
    else{
        validate=0;
    }
    /* If the two arrays are equal,I made these indexes as X...*/
    if(validate==1){
        for(int i=0;i<uzunluk;i++){
            arr[x+i][y-i]='X';
        }
    }
    /* I returned 1 if the two arrays are equal, otherwise 0 */
    return validate;
}


/*
 I am looking for a string in the index entered as diagonally...
 
 x :: I used this as index of array..
 y :: I used this as index of array..
 uzunluk :: I used this variable to hold length of array..
 validate :: I used this variable for counting...
 
 */
int cap41(char array[],char arr[][COL],int x,int y){
    int uzunluk,validate=0;
    uzunluk=my_strlen(array);
    for(int i=0;i<uzunluk;i++){
        if(array[i]==arr[x-i][y+i]){
            /* Increase validate variable by 1 if equality is satisfied..*/
            validate++;
        }
    }
    if(validate==uzunluk){
        validate=1;
    }
    else{
        validate=0;
    }
    /* If the two arrays are equal,I made these indexes as X...*/
    if(validate==1){
        for(int i=0;i<uzunluk;i++){
            arr[x-i][y+i]='X';
        }
    }
    /* I returned 1 if the two arrays are equal, otherwise 0 */
    return validate;
}
