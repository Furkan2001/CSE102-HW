#include <stdio.h>
#include <stdlib.h>
#include "util.h"


int main() {

    int operation,x4,x5,a3,a4,a5;
    float PL,PW,SL,SW,x1,x2,x3,a1,a2;
    /* Ask for the problem selection (1,2,3) .....  */
    printf("Please select decision tree which you want(1,2,3).. If you want to exit from the program,you can enter any number except1,2,3.. ");
    scanf("%d",&operation);
    switch(operation){
        
        case 1:
        
            printf("Enter the value for PL and PW");
            scanf("%f",&PL);
            scanf("%f",&PW);
            printf("Enter the value for SL and SW");
            scanf("%f",&SL);
            scanf("%f",&SW);
            /* If the returns of the two functions are the same, print one, if they are different, print both..*/
        if(dt1a(PL,PW,SL,SW)==dt1b(PL,PW,SL,SW)){
            /* Returns char type characters from util.c and prints the words represented by these characters..*/
            if(dt1b(PL,PW,SL,SW)=='S'){
                printf("Setosa\n");
            }
            if(dt1b(PL,PW,SL,SW)=='E'){
                printf("Versicolor\n");
            }
            if(dt1b(PL,PW,SL,SW)=='I'){
                printf("Virginica\n");
            }
    }
        else{
            printf("The result of first function is ");
            if(dt1a(PL,PW,SL,SW)=='S'){
                printf("Setosa\n");
            }
            if(dt1a(PL,PW,SL,SW)=='E'){
                printf("Versicolor\n");
            }
            if(dt1a(PL,PW,SL,SW)=='I'){
                printf("Virginica\n");
            }
            printf("The result of second function is ");
            if(dt1b(PL,PW,SL,SW)=='S'){
                printf("Setosa\n");
            }
            if(dt1b(PL,PW,SL,SW)=='E'){
                printf("Versicolor\n");
            }
            if(dt1b(PL,PW,SL,SW)=='I'){
                printf("Virginica\n");
            }
        }
            break;
        case 2:
            printf("Enter the 3 real numbers, please");
            scanf("%f",&x1);
            scanf("%f",&x2);
            scanf("%f",&x3);
            printf("Enter the two numbers that are 1 or 0");
            scanf("%d",&x4);
            scanf("%d",&x5);
            /*If the returns of the two functions are the same, print one..*/
            if(dt2a(x1,x2,x3,x4,x5)==dt2b(x1,x2,x3,x4,x5)){
                printf("Result is %f",dt2a(x1,x2,x3,x4,x5));
            }
            /* If the difference between the returns of the two functions is close_enough, print the average of the returns of the two functions..*/
            else if(dt2b(x1,x2,x3,x4,x5)-CLOSE_ENOUGH==dt2a(x1,x2,x3,x4,x5) || dt2a(x1,x2,x3,x4,x5)-CLOSE_ENOUGH==dt2b(x1,x2,x3,x4,x5)){
                printf("Result is %f",(dt2a(x1,x2,x3,x4,x5)+dt2b(x1,x2,x3,x4,x5))/2);
            }
            /* If the returns of the two functions are the diffirent, print both..*/
            else{
                printf("1.Result is %f\n",dt2a(x1,x2,x3,x4,x5));
                if(dt2b(x1,x2,x3,x4,x5)==0.471){
                    printf("√2/3\n");
                }
                else{
                printf("2. Result is %f\n",dt2b(x1,x2,x3,x4,x5));
                }
            }
            break;
        case 3:
            /* If the weather is sunny we will go out but not we will stay at home..
             The reason why we want numbers from 1 to 5 is to ask you what you want to do in these situations..
             The reason we ask for real numbers is to get answers to questions about the situations you have chosen..
             */
            
            /* The variables a1 and a2, which I get as float numbers, represent time in minutes..*/
            printf("Is the weather sunny?(if yes, enter 1 ; if no, enter 0)");
            scanf("%d",&a3);
            printf("Enter a number from 1 to 5..");
            scanf("%d",&a4);
            printf("Enter a number from 1 to 5..");
            scanf("%d",&a5);
            printf("Enter a float number..");
            scanf("%f",&a1);
            printf("Enter a float number..");
            scanf("%f",&a2);
            if(dt3a(a1,a2,a3,a4,a5)==1){
                printf("\nThe weather is sunny and we will barbecue but we will not be satisfied because meat will not be enough for us..\n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==2){
                printf("\nThe weather is sunny and we will barbecue and we'll be full because there's enough meat..\n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==3){
                printf("\nThe weather is sunny and we will camp..\n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==4){
                printf("\nThe weather is sunny and we will go to the cinema and watch Pirates of The Caribbean \n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==5){
                printf("\nThe weather is sunny and we will go to the cinema and watch Apes Hell\n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==6){
                printf("\nThe weather is sunny and we will go to the cinema and watch Titanic\n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==7){
                printf("\nThe weather is sunny and we will go to the cinema and watch Incompatible\n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==8){
                printf("\nThe weather is sunny and we will go to the cinema and watch Forest Gump\n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==9){
                printf("\nThe weather is sunny and we will go to the party but we think we will stay a lot there.. \n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==10){
                printf("\nThe weather is sunny and we will go to the party. We will stay enough there..\n");

            }
            if(dt3a(a1,a2,a3,a4,a5)==11){
                printf("\nThe weather is sunny and we will go to playing tennis..\n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==12){
                printf("\nThe weather is not sunny so we will stay home.We will make doner \n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==13){
                printf("\nThe weather is not sunny so we will stay home.We will grill chicken..\n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==14){
                printf("\nThe weather is not sunny so we will stay home.We will grill fish\n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==15){
                printf("\nThe weather is not sunny so we will stay home.We will make beans\n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==16){
                printf("\nThe weather is not sunny so we will stay home.We will make pasta\n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==17){
                printf("\nThe weather is not sunny so we will stay home.We will clean the house\n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==18){
                printf("\nThe weather is not sunny so we will stay home.We will play game but it will take a long time\n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==19){
                printf("\nThe weather is not sunny so we will stay home.We will play enough game\n");

            }
            if(dt3a(a1,a2,a3,a4,a5)==20){
                printf("\nThe weather is not sunny so we will stay home.We will chat with our friends..\n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==21){
                printf("\nThe weather is not sunny so we will stay home.We will watch TV but it will take a long time.. \n");
            }
            if(dt3a(a1,a2,a3,a4,a5)==22){
                printf("\nThe weather is not sunny so we will stay home.We will watch enouh TV.. \n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==1){
                printf("\nThe weather is sunny and we will go to playing tennis but it will take a long time..\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==2){
                printf("\nThe weather is sunny and we will go to playing tennis\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==3){
                printf("\nThe weather is sunny and we will go to the party..\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==4){
                printf("\nThe weather is sunny and we will camp in Izmir\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==5){
                printf("\nThe weather is sunny and we will camp in Antalya\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==6){
                printf("\nThe weather is sunny and we will camp in Istanbul\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==7){
                printf("\nThe weather is sunny and we will camp in Erzincan..\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==8){
                printf("\nThe weather is sunny and we will camp in Mugla\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==9){
                printf("\nThe weather is sunny we will barbecue\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==10){
                printf("\nThe weather is sunny and we weill go to the cinema\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==11){
                printf("\nThe weather is not sunny so we will stay home and we will play FIFA22..\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==12){
                printf("\nThe weather is not sunny so we will stay home and we will play VALORANT\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==13){
                printf("\nThe weather is not sunny so we will stay home and we will play CS 1.6..\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==14){
                printf("\nThe weather is not sunny so we will stay home and we will play PES22\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==15){
                printf("\nThe weather is not sunny so we will stay home and we will play PUPG..\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==16){
                printf("\nThe weather is not sunny so we will stay home and we will watch TV\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==17){
                printf("\nThe weather is not sunny so we will stay home and we will chat a long time with our friends\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==18){
                printf("\nThe weather is not sunny so we will stay home and we will chat enogh time with our friends..\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==19){
                printf("\nThe weather is not sunny so we will stay home and we will clean the home\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==20){
                printf("\nThe weather is not sunny so we will stay home and we will cook but we linger a lot\n");
            }
            if(dt3b( a1, a2, a3, a4, a5)==21){
                printf("\nThe weather is not sunny so we will stay home and we will cook without too much delay..\n");
            }
            break;
        default:
            printf("\nYou entred unvalid number.. Program is terminating...");
            break;
    }

    return 0;
}
