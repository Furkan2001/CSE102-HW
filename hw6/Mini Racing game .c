#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* I defined sizes of array...*/
#define ROWS 15
#define COLUMNS 30

void printMap(char array[ROWS][COLUMNS]);
int dice(void);
int startGame(void);
void red(void);
void green(void);
void reset(void);
void yellow(void);
void blue(void);



int main(){
    
    int i,j,rastgele1,rastgele2,control,deger1,deger2,p11=1,p12=1,p13=1,p14=1,p21=3,p22=3,p23=3,p24=3,ara;
    char array[ROWS][COLUMNS],temp,space;
    
    //I placed the special characters in the array...
    
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++){
            if(!((i==1 && j==1)||(i==3 && j==3)||(i==2 && j==1)||(i==4 && j==3)||(i==1 && j==14)||(i==7 && j==28)||(i==13 && j==14)||(i==3 && j==10)||(i==3 && j==18)||(i==5 && j==26)||(i==10 && j==26)||(i==11 && j==10)||(i==11 && j==18))){
                if(i==0){
                    array[i][j]='.';
                }
                else if(i==14){
                    array[i][j]='.';
                }
                else if(j==0 && i!=0 && i!=14){
                    array[i][j]=':';
                }
                else if(j==29 && i!=0 && i!=14){
                    array[i][j]=':';
                }
                else if(i==2 && j>=2 && j<=27){
                    array[i][j]='.';
                }
                else if(i==12 && j>=2 && j<=27){
                    array[i][j]='.';
                }
                else if(j==2 && i>=2 && i<=12){
                    array[i][j]=':';
                }
                else if(j==27 && i>=2 && i<=12){
                    array[i][j]=':';
                }
                else if(i==4 && j>=4 && j<=25){
                    array[i][j]='.';
                }
                else if(i==10 && j>=4 && j<=25){
                    array[i][j]='.';
                }
                else if(j==4 && i>=5 && i<=9){
                    array[i][j]=':';
                }
                else if(j==25 && i>=5 && i<=9){
                    array[i][j]=':';
                }
                else{
                    array[i][j]=' ';
                }
            }
        }
    }
    array[1][1]='1';
    array[3][3]='2';
    
    array[2][1]='_';
    array[4][3]='_';
    
    array[1][14]='X';
    array[7][28]='X';
    array[13][14]='X';
    array[3][10]='X';
    array[3][18]='X';
    array[5][26]='X';
    array[10][26]='X';
    array[11][10]='X';
    array[11][18]='X';
    
    printMap(array);
    control=startGame();
    if(control==1){
        deger1=1;
        deger2=0;
    }
    if(control==2){
        deger2=1;
        deger1=0;
        
    }
    // I created these while loops to advance the symbols that are the characters of our players in the game...
    while(deger1){
        /* I created the variables p11 and p12 to advance the symbols, which are the characters of our players, through the game...
         I used the variables p13 and p14 in the previous step to hold the position of our players' characters...
         */
        p13=p11;
        p14=p12;
        p23=p21;
        p24=p22;
        srand(time(NULL));
        yellow();
    printf("PLAYER 1... press ENTER to dice...");
    scanf("%c",&space);
        rastgele1=dice();
    printf("DICE: %d\n",rastgele1);
        reset();
        if(p11==1 && p12<29){
            p12+=rastgele1;
            if(p12<29){
                /* I checked if it is in penalty point... */
            if(array[p11][p12]=='X'){
                yellow();
                printf("Penalty for player 1...\n");
                reset();
                p12-=2;
                }
            }
            if(p12>28){
                ara=(p12%28);
                p12-=ara;
                p11+=ara;
                /* I checked if it is in penalty point... */
                if(array[p11][p12]=='X'){
                    yellow();
                    printf("Penalty for player 1...\n");
                    reset();
                    p11-=2;
                    }
                /* I moved the character's old point to the size of the dice roll*/
                temp=array[p11][p12];
                array[p11][p12]=array[p13][p14];
                array[p13][p14]=temp;
            }
            else{
                /* I moved the character's old point to the size of the dice roll*/
                temp=array[p11][p12];
                array[p11][p12]=array[p13][p14];
                array[p13][p14]=temp;
            }
        }
        else if(p11<14 && p12==28){
                p11+=rastgele1;
            if(p11<14){
                /* I checked if it is in penalty point... */
            if(array[p11][p12]=='X'){
                yellow();
                printf("Penalty for player 1...\n");
                reset();
                p11-=2;
                }
            }
                if(p11>13){
                    ara=(p11%13);
                    p11-=ara;
                    p12-=ara;
                    /* I checked if it is in penalty point... */
                    if(array[p11][p12]=='X'){
                        yellow();
                        printf("Penalty for player 1...\n");
                        reset();
                        p12+=2;
                        }
                    /* I moved the character's old point to the size of the dice roll*/
                    temp=array[p11][p12];
                    array[p11][p12]=array[p13][p14];
                    array[p13][p14]=temp;
                }
                else{
                    /* I moved the character's old point to the size of the dice roll*/
                    temp=array[p11][p12];
                    array[p11][p12]=array[p13][p14];
                    array[p13][p14]=temp;
                }
            }
            else if(p12<29 && p11==13){
                p12-=rastgele1;
                if(p12<29){
                    /* I checked if it is in penalty point... */
                if(array[p11][p12]=='X'){
                    yellow();
                    printf("Penalty for player 1...\n");
                    reset();
                    p12+=2;
                    }
                }
                if(p12<1){
                    ara=(1-(p12));
                    p12=1;
                    p11-=ara;
                    /* I checked if it is in penalty point... */
                    if(array[p11][p12]=='X'){
                        yellow();
                        printf("Penalty for player 1...\n");
                        reset();
                        p11+=2;
                        }
                    /* I moved the character's old point to the size of the dice roll*/
                    temp=array[p11][p12];
                    array[p11][p12]=array[p13][p14];
                    array[p13][p14]=temp;
                }
                else{
                    /* I moved the character's old point to the size of the dice roll*/
                    temp=array[p11][p12];
                    array[p11][p12]=array[p13][p14];
                    array[p13][p14]=temp;
                }
            }
            else if(p12==1 && p11<13){
                p11-=rastgele1;
                if(p11<13){
                if(array[p11][p12]=='X'){
                    yellow();
                    printf("Penalty for player 1...\n");
                    reset();
                    p11-=2;
                    }
                }
                if(p11<2){
                    yellow();
                    printf("\n\n\n\n\n***   PLAYER 1 WON THE GAME   ***\n");
                    reset();
                    deger1=0;
                    ara=(1-(p11));
                    p11=1;
                    p12+=ara;
                    /* I checked if it is in penalty point... */
                    if(array[p11][p12]=='X'){
                        yellow();
                        printf("Penalty for player 1...\n");
                        reset();
                        p12-=2;
                        }
                    temp=array[p11][p12];
                    array[p11][p12]=array[p13][p14];
                    array[p13][p14]=temp;
                    array[2][1]='_';
                }
                else if(p11==2){
                    array[p11][p12]=array[p13][p14];
                    array[p13][p14]=' ';
                }
                else{
                    temp=array[p11][p12];
                    array[p11][p12]=array[p13][p14];
                    array[p13][p14]=temp;
                    array[2][1]='_';
                }
            }
        
        /* I created the variables p21 and p22 to advance the symbols, which are the characters of our players, through the game...
         I used the variables p23 and p24 in the previous step to hold the position of our players' characters...
         */
            
        if(deger1==1){
            blue();
        printf("PLAYER 2... press ENTER to dice...");
        scanf("%c",&space);
            rastgele2=dice();
        printf("DICE: %d\n",rastgele2);
            reset();
            if(p21==3 && p22<27){
                p22+=rastgele2;
                if(p22<27){
                    /* I checked if it is in penalty point... */
                if(array[p21][p22]=='X'){
                    blue();
                    printf("Penalty for player 2...\n");
                    reset();
                    p22-=2;
                    }
                }
                if(p22>26){
                    ara=(p22%26);
                    p22-=ara;
                    p21+=ara;
                    /* I checked if it is in penalty point... */
                    if(array[p21][p22]=='X'){
                        blue();
                        printf("Penalty for player 2...\n");
                        reset();
                        p21-=2;
                        }
                    /* I moved the character's old point to the size of the dice roll*/
                    temp=array[p21][p22];
                    array[p21][p22]=array[p23][p24];
                    array[p23][p24]=temp;
                }
                else{
                    /* I moved the character's old point to the size of the dice roll*/
                    temp=array[p21][p22];
                    array[p21][p22]=array[p23][p24];
                    array[p23][p24]=temp;
                }
            }
               else if(p21<12 && p22==26){
                    p21+=rastgele2;
                   if(p21<12){
                       /* I checked if it is in penalty point... */
                   if(array[p21][p22]=='X'){
                       blue();
                       printf("Penalty for player 2...\n");
                       reset();
                       p21-=2;
                        }
                   }
                    if(p21>11){
                        ara=(p21%11);
                        p21-=ara;
                        p22-=ara;
                        /* I checked if it is in penalty point... */
                        if(array[p21][p22]=='X'){
                            blue();
                            printf("Penalty for player 2...\n");
                            reset();
                            p22+=2;
                             }
                        /* I moved the character's old point to the size of the dice roll*/
                        temp=array[p21][p22];
                        array[p21][p22]=array[p23][p24];
                        array[p23][p24]=temp;
                    }
                    else{
                        /* I moved the character's old point to the size of the dice roll*/
                        temp=array[p21][p22];
                        array[p21][p22]=array[p23][p24];
                        array[p23][p24]=temp;
                    }
                }
               else if(p22<27 && p21==11){
                    p22-=rastgele2;
                   if(p22<27){
                       /* I checked if it is in penalty point... */
                   if(array[p21][p22]=='X'){
                       blue();
                       printf("Penalty for player 2...\n");
                       reset();
                       p22+=2;
                        }
                   }
                    if(p22<3){
                        ara=(3-(p22));
                        p22=3;
                        p21-=ara;
                        /* I checked if it is in penalty point... */
                        if(array[p21][p22]=='X'){
                            blue();
                            printf("Penalty for player 2...\n");
                            reset();
                            p21+=2;
                             }
                        /* I moved the character's old point to the size of the dice roll*/
                        temp=array[p21][p22];
                        array[p21][p22]=array[p23][p24];
                        array[p23][p24]=temp;
                    }
                    else{
                        /* I moved the character's old point to the size of the dice roll*/
                        temp=array[p21][p22];
                        array[p21][p22]=array[p23][p24];
                        array[p23][p24]=temp;
                    }
                }
               else if(p22==3 && p21<11){
                    p21-=rastgele2;
                   if(p21<11){
                       /* I checked if it is in penalty point... */
                   if(array[p21][p22]=='X'){
                       blue();
                       printf("Penalty for player 2...\n");
                       reset();
                       p21-=2;
                        }
                   }
                    if(p21<4){
                        blue();
                        printf("\n\n\n\n\n***  PLAYER 2 WON THE GAME  ***\n");
                        deger2=0;
                        reset();
                        deger1=0;
                        ara=(3-(p21));
                        p21=3;
                        p22+=ara;
                        /* I checked if it is in penalty point... */
                        if(array[p21][p22]=='X'){
                            blue();
                            printf("Penalty for player 2...\n");
                            reset();
                            p22-=2;
                             }
                        temp=array[p21][p22];
                        array[p21][p22]=array[p23][p24];
                        array[p23][p24]=temp;
                        array[4][3]='_';
                    }
                    else if(p21==4){
                        array[p21][p22]=array[p23][p24];
                        array[p23][p24]=' ';
                    }
                    else{
                        temp=array[p21][p22];
                        array[p21][p22]=array[p23][p24];
                        array[p23][p24]=temp;
                        array[4][3]='_';
                    }
                }
            }
        printMap(array);
        
    }

    // I created these while loops to advance the symbols that are the characters of our players in the game...
    while(deger2){
        /* I created the variables p21 and p22 to advance the symbols, which are the characters of our players, through the game...
         I used the variables p23 and p24 in the previous step to hold the position of our players' characters...
         */
        p13=p11;
        p14=p12;
        p23=p21;
        p24=p22;
        blue();
    printf("PLAYER 2... press ENTER to dice...");
    scanf("%c",&space);
        rastgele2=dice();
    printf("DICE: %d\n",rastgele2);
        reset();
        if(p21==3 && p22<27){
            p22+=rastgele2;
            if(p22<27){
                /* I checked if it is in penalty point... */
            if(array[p21][p22]=='X'){
                blue();
                printf("Penalty for player 2...\n");
                reset();
                p22-=2;
                }
            }
            if(p22>26){
                ara=(p22%26);
                p22-=ara;
                p21+=ara;
                /* I checked if it is in penalty point... */
                if(array[p21][p22]=='X'){
                    blue();
                    printf("Penalty for player 2...\n");
                    reset();
                    p21-=2;
                    }
                /* I moved the character's old point to the size of the dice roll*/
                temp=array[p21][p22];
                array[p21][p22]=array[p23][p24];
                array[p23][p24]=temp;
            }
            else{
                /* I moved the character's old point to the size of the dice roll*/
                temp=array[p21][p22];
                array[p21][p22]=array[p23][p24];
                array[p23][p24]=temp;
            }
        }
           else if(p21<12 && p22==26){
                p21+=rastgele2;
               if(p21<12){
                   /* I checked if it is in penalty point... */
               if(array[p21][p22]=='X'){
                   blue();
                   printf("Penalty for player 2...\n");
                   reset();
                   p21-=2;
                    }
               }
                if(p21>11){
                    ara=(p21%11);
                    p21-=ara;
                    p22-=ara;
                    /* I checked if it is in penalty point... */
                    if(array[p21][p22]=='X'){
                        blue();
                        printf("Penalty for player 2...\n");
                        reset();
                        p22+=2;
                         }
                    /* I moved the character's old point to the size of the dice roll*/
                    temp=array[p21][p22];
                    array[p21][p22]=array[p23][p24];
                    array[p23][p24]=temp;
                }
                else{
                    /* I moved the character's old point to the size of the dice roll*/
                    temp=array[p21][p22];
                    array[p21][p22]=array[p23][p24];
                    array[p23][p24]=temp;
                }
            }
           else if(p22<27 && p21==11){
                p22-=rastgele2;
               if(p22<27){
                   /* I checked if it is in penalty point... */
               if(array[p21][p22]=='X'){
                   blue();
                   printf("Penalty for player 2...\n");
                   reset();
                   p22+=2;
                    }
               }
                if(p22<3){
                    ara=(3-(p22));
                    p22=3;
                    p21-=ara;
                    /* I checked if it is in penalty point... */
                    if(array[p21][p22]=='X'){
                        blue();
                        printf("Penalty for player 2...\n");
                        reset();
                        p21+=2;
                         }
                    /* I moved the character's old point to the size of the dice roll*/
                    temp=array[p21][p22];
                    array[p21][p22]=array[p23][p24];
                    array[p23][p24]=temp;
                }
                else{
                    /* I moved the character's old point to the size of the dice roll*/
                    temp=array[p21][p22];
                    array[p21][p22]=array[p23][p24];
                    array[p23][p24]=temp;
                }
            }
           else if(p22==3 && p21<11){
                p21-=rastgele2;
               if(p21<11){
                   /* I checked if it is in penalty point... */
               if(array[p21][p22]=='X'){
                   blue();
                   printf("Penalty for player 2...\n");
                   reset();
                   p21-=2;
                    }
               }
                if(p21<4){
                    blue();
                    printf("\n\n\n\n\n***  PLAYER 2 WON THE GAME  ***\n");
                    deger2=0;
                    reset();
                    deger1=0;
                    ara=(3-(p21));
                    p21=3;
                    p22+=ara;
                    /* I checked if it is in penalty point... */
                    if(array[p21][p22]=='X'){
                        blue();
                        printf("Penalty for player 2...\n");
                        reset();
                        p22-=2;
                         }
                    temp=array[p21][p22];
                    array[p21][p22]=array[p23][p24];
                    array[p23][p24]=temp;
                    array[4][3]='_';
                }
                else if(p21==4){
                    array[p21][p22]=array[p23][p24];
                    array[p23][p24]=' ';
                }
                else{
                    /* I moved the character's old point to the size of the dice roll*/
                    temp=array[p21][p22];
                    array[p21][p22]=array[p23][p24];
                    array[p23][p24]=temp;
                    array[4][3]='_';
                }
            }
        
       /* I created the variables p11 and p12 to advance the symbols, which are the characters of our players, through the game...
        I used the variables p13 and p14 in the previous step to hold the position of our players' characters...
        */
        if(deger2==1){
        yellow();
    printf("PLAYER 1... press ENTER to dice...");
    scanf("%c",&space);
        rastgele1=dice();
    printf("DICE: %d\n",rastgele1);
        reset();
        if(p11==1 && p12<29){
            p12+=rastgele1;
            if(p12<29){
                /* I checked if it is in penalty point... */
            if(array[p11][p12]=='X'){
                yellow();
                printf("Penalty for player 1...\n");
                reset();
                p12-=2;
                }
            }
            if(p12>28){
                ara=(p12%28);
                p12-=ara;
                p11+=ara;
                /* I checked if it is in penalty point... */
                if(array[p11][p12]=='X'){
                    yellow();
                    printf("Penalty for player 1...\n");
                    reset();
                    p11-=2;
                    }
                /* I moved the character's old point to the size of the dice roll*/
                temp=array[p11][p12];
                array[p11][p12]=array[p13][p14];
                array[p13][p14]=temp;
            }
            else{
                /* I moved the character's old point to the size of the dice roll*/
                temp=array[p11][p12];
                array[p11][p12]=array[p13][p14];
                array[p13][p14]=temp;
            }
        }
        else if(p11<14 && p12==28){
                p11+=rastgele1;
            if(p11<14){
                /* I checked if it is in penalty point... */
            if(array[p11][p12]=='X'){
                yellow();
                printf("Penalty for player 1...\n");
                reset();
                p11-=2;
                }
            }
                if(p11>13){
                    ara=(p11%13);
                    p11-=ara;
                    p12-=ara;
                    /* I checked if it is in penalty point... */
                    if(array[p11][p12]=='X'){
                        yellow();
                        printf("Penalty for player 1...\n");
                        reset();
                        p12+=2;
                        }
                    /* I moved the character's old point to the size of the dice roll*/
                    temp=array[p11][p12];
                    array[p11][p12]=array[p13][p14];
                    array[p13][p14]=temp;
                }
                else{
                    /* I moved the character's old point to the size of the dice roll*/
                    temp=array[p11][p12];
                    array[p11][p12]=array[p13][p14];
                    array[p13][p14]=temp;
                }
            }
            else if(p12<29 && p11==13){
                p12-=rastgele1;
                if(p12<29){
                    /* I checked if it is in penalty point... */
                if(array[p11][p12]=='X'){
                    yellow();
                    printf("Penalty for player 1...\n");
                    reset();
                    p12+=2;
                    }
                }
                if(p12<1){
                    ara=(1-(p12));
                    p12=1;
                    p11-=ara;
                    /* I checked if it is in penalty point... */
                    if(array[p11][p12]=='X'){
                        yellow();
                        printf("Penalty for player 1...\n");
                        reset();
                        p11+=2;
                        }
                    /* I moved the character's old point to the size of the dice roll*/
                    temp=array[p11][p12];
                    array[p11][p12]=array[p13][p14];
                    array[p13][p14]=temp;
                }
                else{
                    /* I moved the character's old point to the size of the dice roll*/
                    temp=array[p11][p12];
                    array[p11][p12]=array[p13][p14];
                    array[p13][p14]=temp;
                }
            }
            else if(p12==1 && p11<13){
                p11-=rastgele1;
                if(p11<13){
                    /* I checked if it is in penalty point... */
                if(array[p11][p12]=='X'){
                    yellow();
                    printf("Penalty for player 1...\n");
                    reset();
                    p11-=2;
                    }
                }
                if(p11<2){
                    yellow();
                    printf("\n\n\n\n\n***   PLAYER 2 WON THE GAME   ***\n");
                    deger2=0;
                    reset();
                    ara=(1-(p11));
                    p11=1;
                    p12+=ara;
                    /* I checked if it is in penalty point... */
                    if(array[p11][p12]=='X'){
                        yellow();
                        printf("Penalty for player 1...\n");
                        reset();
                        p12-=2;
                        }
                   /* I moved the character's old point to the size of the dice roll*/
                    temp=array[p11][p12];
                    array[p11][p12]=array[p13][p14];
                    array[p13][p14]=temp;
                    array[2][1]='_';
                }
                /* If character is on the finished line then you shold delete finish line...*/
                else if(p11==2){
                    array[p11][p12]=array[p13][p14];
                    array[p13][p14]=' ';
                }
                else{
                   /* I moved the character's old point to the size of the dice roll*/
                    temp=array[p11][p12];
                    array[p11][p12]=array[p13][p14];
                    array[p13][p14]=temp;
                    array[2][1]='_';
                }
            }
        }
        printMap(array);
    }
    
    return 0;
}

/*
 I printed the map to the terminal...
 
 I used i and j variables to set loops..
 */

void printMap(char array[ROWS][COLUMNS]){
    int i,j;
    
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++){
            if(array[i][j]=='1'){
                // I printed with yellow..
                yellow();
                printf("%c",array[i][j]);
                reset();
            }
            else if(array[i][j]=='2'){
                // I printed with blue..
                blue();
                printf("%c",array[i][j]);
                reset();
            }
            else if(array[i][j]=='X'){
                // I printed with red..
                red();
                printf("%c",array[i][j]);
                reset();
            }
            else if(array[i][j]=='_'){
                // I printed with green..
                green();
                printf("%c",array[i][j]);
                reset();
            }
            else{
                printf("%c",array[i][j]);
            }
        }
        printf("\n");
    }
}

/*
I wrote this function to dice...
 
 I used rastgele for variable to dice...
 */

int dice(void){
    int rastgele;
    rastgele=1+rand()%6;
    return rastgele;
}

/*
 I wrote this function to find who is going to start...
 
 bosluk: I used it can to press enter..
 
 control: I used it infinitive loop..
 
 p1,p2: I used it for results of dice...
 */

int startGame(void){
    char bosluk,p1,p2,control=1;
    printf("\n\n\nTo start to game players should dice and decide who is going to start first according to it...\n\n\n");
    
    while(control){
        yellow();
    printf("1.oyuncu entera bas");
    scanf("%c",&bosluk);
    p1=dice();
    printf("DICE: %d\n",p1);
        reset();
        blue();
    printf("2.oyuncu entera bas");
    scanf("%c",&bosluk);
    p2=dice();
    printf("DICE: %d\n",p2);
        reset();
        
        if(p1==p2){
            printf("Same dice value... Please try again...\n");
        }
        if(p1>p2){
            printf("\n*** PLAYER 1 will start the game... ***\n");
            control=0;
            return 1;
        }
        if(p2>p1){
            printf("\n*** PLAYER 2 will start the game... ***\n");
            control=0;
            return 2;
        }
    }
    return 0;
}

/*
 I wrote this function to print with blue...
 */

void blue(void){
    printf("\033[0;34m");
}

/*
 I wrote this function to print with yellow...
 */

void yellow(void){
    printf("\033[0;33m");
}

/*
 I wrote this function to print with red...
 */

void red(void){
  printf("\033[1;31m");
}

/*
 I wrote this function to print with green...
 */

void green(void){
  printf("\033[0;32m");
}

/*
 I wrote this function to terminate color functions...
 */

void reset(void){
  printf("\033[0m");
}
