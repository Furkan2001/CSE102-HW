#include <stdio.h>
#include "utils.h"
/* The purpose of this function is to find the first number between x and y that is divisible by z..*/
int find_divisible(int x, int y, int z){
    
    int number;
    /* I set the number variable equal to the smaller number x and added 1 at each step until it increased to the larger y number to see if it could be divisible by z, and each time I checked for a remainder from the division by z..*/
    number=(x+1);
    while(number<y){
            if(number%z==0){
                return number;
            }
        number++ ;
    }
    return -1;
}


int find_nth_divisible(int n, int f_I, int z){
    //divided arrayine n sayısını vermemizin sebebi, bize divided[n] sayısının gerekiyor olması..
    int divided[n],number,counter=0;
    /* we equated the entered small number to the number variable..*/
    number=f_I;
/* while loop is designed to continue indefinitely (except under certain conditions)*/
    while(counter>=0){
        /* If the number variable is divisible by z variable, enter to if*/
            if(number % z==0){
        /* If  wanted the  n. value is reached, enter to if..*/
                if(counter==n){
                    divided[n]=number;
                    break ;
                }
                counter++ ;
        }
        number++ ;
    }
    return divided[n];
}

/* The purpose of this function is to find out whether the entered ID number is real or not.*/
int validate_identity_number(char identity_number[]){
    int i;
/* It is checked whether the ID number is 11 digits or not.. */
    for(i=0;i<11;i++){
        if(identity_number[i]=='\0'){
            return 0;
        }
            }
    /* Check if all characters are numbers.. */
    for(i=0;i<11;i++){
        if(!(identity_number[i]>='0' && identity_number[i]<='9')){
            return 0;
            }
        }
   /* Checking if the first character is not 0..*/
    if(identity_number[0]=='0'){
        return 0;
    }
/* When we subtract the sum of the digits 2, 4, 6, 8 from 7 times the sum of the digits 1, 3, 5, 7, 9, the remainder of the division by 10 (MOD10) should give the number in the 10th digit. I am controlling this situation..*/
    int toplamtek=0,toplamcift=0;
    for(i=0;i<11;i++){
        /* Since the ascii codes of the char type characters are taken into account, I converted the ascii code to normal number (because '0'=48 in ascii code)*/
        identity_number[i]-=48;
    }
    for(i=0;i<9;i+=2){
        toplamtek+=identity_number[i];
    }
    toplamtek*=7;
    for(i=1;i<8;i+=2){
        toplamcift+=identity_number[i];
    }
    toplamtek-=toplamcift;
    toplamtek=toplamtek%10;
    if(toplamtek!=identity_number[9]){
        return 0;
    }
    /* The remainder of the division by 10 of the result obtained from the sum of the first 10 digits (MOD10) should give the number in the 11th digit. I am controlling this situation..*/
    int toplam=0;
    /* Since I converted the ascii codes above to normal numbers, I do not need to convert them again, but since this conversion will be reflected in the main function, I will correct this situation there (by adding 48 to the values)*/
    for(i=0;i<10;i++){
        toplam+=identity_number[i];
    }
    toplam = toplam%10;
    if(toplam!=identity_number[10]){
        return 0;
    }
    return 1;
}

/* The purpose of this function is to create a customer to customeraccount.text (ID number, password)..*/
int create_customer(char identity_number [ ], int password){
    
    FILE* file;
    file = fopen("customeraccount.txt","w");
    if(file==NULL){
        printf("File could not be opened..");
        return 0;
    }
    else{
        /* This function write identity_number and password to customeraccount.txt..*/
        fprintf(file,"%s,%d",identity_number,password);
    }
    fclose(file);
    return 1;
}

/* In this function, the entered ID number and password are compared to log in with the previously entered ID number and password..*/
int check_login(char identity_number [], int password){
    
    char id[12],sembol,i;
    int password2,counter=0;
    FILE* file;
    file = fopen("customeraccount.txt","r");
    if(file==NULL){
        printf("File could not be opened..");
        return 0;
    }
    else{
        for(i=0;i<13;i++){
            /* Counter increments one at a time..*/
            counter++ ;
            /* Counter ensures that the first 11 digits in the txt file are cast to the id array(via if)*/
            if(counter<12){
                fscanf(file,"%c",&id[i]);
                }
            /* The 12th character ',' is assigned to the symbol variable..*/
            if(counter==12){
                fscanf(file,"%c",&sembol);
            }
            /* The remaining numbers are assigned to the password variable..*/
            if(counter==13){
                fscanf(file,"%d",&password2);
            }
            }
    }
    /* we reset the counter to use it again..*/
    counter=0;
    /* I compared char arrays character by character..*/
    for(i=0;i<11;i++){
        if(id[i]==identity_number[i]){
        counter++ ;
            }
        }
    if(password2==password){
        counter++ ;
    }
    /* For each comparison I increment the counter variable by one if the comparison is true..*/
    if(counter==12){
        fclose(file);
        /* İf login successful , I returned 1..*/
        return 1;
    }
    else{
        fclose(file);
      /*  I returned 0 if login failed.. */
        return 0;
    }
    fclose(file);
    return 1;
}

/* The purpose of this function is to convert the amount of cash demanded into a withdrawable amount.*/
int withdrawable_amount(float cash_amount){
    int int_amount;
    int_amount=(int)cash_amount/10;
    int_amount*=10;
    return int_amount;
}

