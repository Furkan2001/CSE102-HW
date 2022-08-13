#include <stdio.h>
#include "utils.h"
int main(){
    
    int x=0,y=0,z=0,n,i,password;
    char identity_number[12];
    printf("Enter two integer please..");
    scanf("%d",&x);
    scanf("%d",&y);
    printf("Enter the divisor integer please..");
    scanf("%d",&z);
    if(find_divisible(x,y,z)==(-1)){
        printf("There is not any integer between X and Y can be divided by Z..\n");
    }
       else{
           printf("\nThe first integer between %d and %d divided by %d is %d",x,y,z,find_divisible(x,y,z));
           printf("\nEnter the number how many next:");
           scanf("%d",&n);
     /* I checked if it is greater than y since it should be between x and y(already proven inside the function to be greater than x)..*/
           if(find_nth_divisible(n,x,z)<y){
           printf("The %d. integer between %d and %d divided by %d is %d\n",n,x,y,z,find_nth_divisible(n,x,z));
                }
           else{
               printf("The %d. integer is not in the specified range..\n",n);
           }
           }
    printf("Enter your ID number");
    scanf("%s",identity_number);
    
    if(validate_identity_number(identity_number)==0){
        printf("Your ID is invalid..\n");
        printf("Program terminated..\n");
        return 0;
    }
    else{
        printf("Your ID is valid..\n");
     /* We fixed the change we made on the char array in the validate_identity_number function in the utils.c file..*/
        for(i=0;i<11;i++){
            identity_number[i]+=48;
        }
        printf("Please create a password with 4 digits for account(it has JUST integers)..");
        scanf("%d",&password);
        /* I checked if the password is 4 digits..*/
        if(!(password>=1000 && password<=9999)){
            printf("Your password is invalid..\n");
            return 404;
        }
        /* I created an customer in the .txt file if the id and password are correct..*/
        else{
            create_customer(identity_number,password);
        }
    }
    char id[11];
    int password2,withdrawable_cash;
    float cash_amount;
    printf("\n\n\t\tLOGIN PAGE\n\n");
    printf("Enter your ID number..");
    scanf("%s",id);
    printf("Enter your password..");
    scanf("%d",&password2);
    check_login(id,password2);
  /* the function will return 1 if the check is positive..*/
    if(check_login(id,password2)==1){
        printf("Login Successful\n");
        printf("Enter the amount of cash you want to withdraw.");
        scanf("%f",&cash_amount);
        printf("Withdrawable amount is %d\n",withdrawable_amount(cash_amount));
        printf("Your %d TL withdrawal is successful..\n",withdrawable_amount(cash_amount));
    }
    else{
        printf("Invalid identity number or password\n");
    }
        return 0;
}
