#include <stdio.h>
#include <math.h>
int sum(int n1, int n2, int flag);
int multi(int n1, int n2, int flag);
void write_file(int result);
int isprime(int a);
void read_file(void);
void sort_file(void);
int fonksiyon(int x);
int main(){
    int exit=1,select=0,choose1=0,choose2=0,value1=0,value2=0,temp=0,prime=0,i,sonuc=0;
    
    while(exit){
        printf("\n\nSelect Operation\n");
        printf("-----------------------------------------------------\n");
        printf("1. Calculate sum/multiplication between two numbers\n");
        printf("2. Calculate prime numbers\n");
        printf("3. Show number sequence in file\n");
        printf("4. Sort number sequence in file\n");
        printf("0. EXIT\n");
        printf("-----------------------------------------------------\n");
        scanf("%d",&select);
        switch(select){
            case 1:
                printf("Please enter '0' for sum, '1' for multiplication\n");
                scanf("%d",&choose1);
                printf("Please enter '0' to work on even numbers, '1' to work on odd numbers.\n");
                scanf("%d",&choose2);
                printf("Please enter two diffirent numbers(First number must be smaller than second number):\n");
                printf("Number 1: ");
                scanf("%d",&value1);
                printf("Number 2: ");
                scanf("%d",&value2);
                if(value1<0 || value2<0){
                    printf("\nDo not enter the negative numbers please!!!\n");
                }
                /* If the entered numbers are not negative, print the numbers in between..*/
                /* Print even or odd(whichever you wanted) numbers between two entered numbers to the screen*/
                else{
                if(value1<value2){
                if(value1!=value2){
                if(choose1==0){
                    if(choose2==0){
                    temp=value1;
                    if(value1%2==0){
                        temp+=2;
                        if(temp>=value2){
                            printf("There are no even numbers between the values ​​you entered\n");
                        }
                        else{
                            printf("%d",temp);
                            temp+=2;
                            while(temp<value2){
                                printf(" + %d",temp);
                                temp+=2;
                            }
                            printf("= %d\n",sum(value1,value2,choose2));
                        }
                    }
                    else{
                        temp++;
                        if(temp>=value2){
                            printf("There are no even numbers between the values ​​you entered\n");
                        }
                        else{
                            printf("%d",temp);
                            temp+=2;
                            while(temp<value2){
                                printf(" + %d",temp);
                                temp+=2;
                            }
                            printf("= %d\n",sum(value1,value2,choose2));
                        }
                    }
                }
                    else{
                        temp=value1;
                        if(value1%2==0){
                            temp++;
                            if(temp>=value2){
                                printf("There are no odd numbers between the values ​​you entered\n");
                            }
                            else{
                                printf("%d",temp);
                                temp+=2;
                                while(temp<value2){
                                    printf(" + %d",temp);
                                    temp+=2;
                                }
                                printf("= %d\n",sum(value1,value2,choose2));
                            }
                        }
                        else{
                            temp+=2;
                            if(temp>=value2){
                                printf("There are no odd numbers between the values ​​you entered\n");
                            }
                            else{
                                printf("%d",temp);
                                temp+=2;
                                while(temp<value2){
                                    printf(" + %d",temp);
                                    temp+=2;
                                }
                                printf("= %d\n",sum(value1,value2,choose2));
                            }
                        }
                    }
            }
                if(choose1==1){
                    if(choose2==0){
                    temp=value1;
                    if(value1%2==0){
                        temp+=2;
                        if(temp>=value2){
                            printf("There are no even numbers between the values ​​you entered\n");
                        }
                        else{
                            printf("%d",temp);
                            temp+=2;
                            while(temp<value2){
                                printf(" * %d",temp);
                                temp+=2;
                            }
                            printf("= %d\n",multi(value1,value2,choose2));
                        }
                    }
                    else{
                        temp++;
                        if(temp>=value2){
                            printf("There are no even numbers between the values ​​you entered\n");
                        }
                        else{
                            printf("%d",temp);
                            temp+=2;
                            while(temp<value2){
                                printf(" * %d",temp);
                                temp+=2;
                            }
                            printf("= %d\n",multi(value1,value2,choose2));
                        }
                    }
                }
                    else{
                        temp=value1;
                        if(value1%2==0){
                            temp++;
                            if(temp>=value2){
                                printf("There are no odd numbers between the values ​​you entered\n");
                            }
                            else{
                                printf("%d",temp);
                                temp+=2;
                                while(temp<value2){
                                    printf(" * %d",temp);
                                    temp+=2;
                                }
                                printf("= %d\n",multi(value1,value2,choose2));
                            }
                        }
                        else{
                            temp+=2;
                            if(temp>=value2){
                                printf("There are no odd numbers between the values ​​you entered\n");
                            }
                            else{
                                printf("%d",temp);
                                temp+=2;
                                while(temp<value2){
                                    printf(" * %d",temp);
                                    temp+=2;
                                }
                                printf("= %d\n",multi(value1,value2,choose2));
                            }
                        }
                    }
                }
                if(!(choose1==0 || choose1==1)){
                    printf("This value is invalid..");
                }
                }
                else {
                    printf("Your values equals..\n");
                    printf("ERROR 101\n");
                }
                }
                else{
                    printf("You must enter the second number greater than the 1st number.");
                    printf("ERROR 102\n");
                }
                }
                break;
            case 2:
                printf("Please enter an integer: ");
                scanf("%d",&prime);
                /* return 1 if number is prime, otherwise return the smallest number from the function that causes it to be non-prime..*/
                for(i=2;i<prime;i++){
                    if(isprime(i)==1){
                        printf("%d is a prime number.\n",i);
                    }
                    else{
                        printf("%d is not a prime number, it is dividible by %d\n",i,isprime(i));
                    }
                }
                break;
            case 3:
                printf("\nResult:\n");
                read_file();
                break;
            case 4:
                sort_file();
                FILE* file;
                file = fopen("results.txt","r");
                printf("Result :\n");
                while(!feof(file)){
                    fscanf(file,"%d ",&sonuc);
                    printf("%d ",sonuc);
                }
                break;
            case 0:
                exit=0;
                break;
            default:
                printf("\nThe value you entered is invalid.. Please enter a valid number...\n");
                break;
        }
    }
            
    return 0;
}

void write_file(int result){
    FILE* file;
    file = fopen("results.txt","a");
    if(file==NULL){
        printf("File could not be opened..");
    }
    else{
        fprintf(file,"%d ",result);
    }
    fclose(file);
}


int sum(int n1, int n2, int flag){
    int total1=0,temp=0;
    temp=n1;
    /* To calculate the sum even numbers between two numbers..*/
    if(flag==0){
        if(n1%2==0){
            temp+=2;
            if(temp>n2){
                return 404;
            }
            else{
                    while(temp<n2){
                total1+=temp;
                temp+=2;
            }
                write_file(total1);
            return total1;
            }
        }
        else{
            temp++;
            if(temp>n2){
                return 404;
            }
            while(temp<n2){
                total1+=temp;
                temp+=2;
            }
            write_file(total1);
            return total1;
        }
    }
    /* To calculate the sum odd numbers between two numbers..*/
    if(flag==1){
        if(n1%2==0){
            temp++;
            if(temp>n2){
                return 404;
            }
            else{
                    while(temp<n2){
                total1+=temp;
                temp+=2;
            }
                write_file(total1);
            return total1;
            }
        }
        else{
        temp+=2;
        if(temp>n2){
            return 404;
        }
        while(temp<n2){
            total1+=temp;
            temp+=2;
        }
            write_file(total1);
        return total1;
        }
    }
    return 0;
}


int multi(int n1, int n2, int flag){
    int total2=1,temp=0;
    temp=n1;
    /* To calculate the multiply even numbers between two numbers..*/
    if(flag==0){
        if(n1%2==0){
            temp+=2;
            if(temp>n2){
                return 404;
            }
            else{
                    while(temp<n2){
                total2*=temp;
                temp+=2;
            }
                write_file(total2);
            return total2;
            }
        }
        else{
            temp++;
            if(temp>n2){
                return 404;
            }
            while(temp<n2){
                total2*=temp;
                temp+=2;
            }
            write_file(total2);
            return total2;
        }
    }
   /* To calculate the multiply odd numbers between two numbers..*/
    if(flag==1){
        if(n1%2==0){
            temp++;
            if(temp>n2){
                return 404;
            }
            else{
                    while(temp<n2){
                total2*=temp;
                temp+=2;
            }
                write_file(total2);
            return total2;
            }
        }
        else{
        temp+=2;
        if(temp>n2){
            return 404;
        }
        while(temp<n2){
            total2*=temp;
            temp+=2;
        }
            write_file(total2);
        return total2;
        }
    }
    return 0;
}


/* It is checked whether the number entered as a parameter to the function is prime. If the number is prime, 1 is returned. If the number is not prime, the smallest number that causes it to be non-prime is returned... */
int isprime(int a){
    int i;
        for(i=2;i<=sqrt(a);i++){
            if(a%i==0){
                return i;
            }
        }
    return 1;
}


/* prints the numbers written in the file to the screen..*/
void read_file(void){
    int result;
    FILE* file;
    file = fopen("results.txt","r");
    if(file==NULL){
        printf("File could not be opened..");
    }
    else{
        while(!feof(file)){
        fscanf(file,"%d ",&result);
            printf("%d ",result);
        }
    }
    fclose(file);
}


/* Sorts mixed numbers in a file from smallest to largest..*/
void sort_file(void){
    int result,min1=-1,min2=-1,min3=-1,counter=0,i,sonuc,validate=0,temporary=0,dogrulama=0;
    /* I have processed with two different files..*/
    /* While the file is the main file I use as a pointer, I defined a second pointer to sort the numbers and named it as a file.*/
    FILE* file;
    FILE* dosya;
    file = fopen("results.txt","r");
    /* I read the values ​​until I came to the end of the file and used a counter while doing this. Thanks to the counter, I kept the information of how many values ​​are in this file...*/
    while(!feof(file)){
        fscanf(file,"%d ",&result);
        counter++;
    }
    fclose(file);
    /* I wrote this here because we checked the numbers in the file 3 by 3.*/
    /* If there is a multiple of 3 in counter, I found how many triple checks will be made by dividing by 3..If the counter is not a multiple of 3, I gave the correct control by dividing the counter variable by 3 and increasing it by 1.*/
    if(counter%3!=0){
        counter=counter/3;
        counter++;
    }
    else{
        counter=counter/3;
    }
    dosya = fopen("temp.txt","w");
    fclose(dosya);
    /* 3 erli sayıların kontrol adedince dönecek döngü oluşturdum..*/
    for(i=1;i<=counter;i++){
        dogrulama=0;
        temporary=min1;
        file = fopen("results.txt","r");
        /* I used this loop to evaluate the probability of having more than one of the same number in the result.txt file..*/
        while(!feof(file)){
            fscanf(file,"%d ",&result);
            if(result==min3){
                validate++;
            }
            if(validate==3 && min1!=min3){
                min1=result;
                dogrulama=1;
            }
        }
        validate=0;
        fclose(file);
        if(dogrulama==0){
            file = fopen("results.txt","r");
            while(!feof(file)){
                fscanf(file,"%d ",&result);
                if(result==min3){
                    validate++;
                }
            if(validate==2 && min2!=min3)
                min1=result;
            }
            fclose(file);
        }
        if(min1==temporary){
        min1=-1;
        }
        min2=-1;
        min3=-1;
        /* I am resetting it here because I will use the validate variable in the while loops that I will use for the following variables..*/
        validate=0;
    file = fopen("results.txt","r");
    if(file==NULL){
        printf("File could not be opened..");
    }
    else{
        /* I assigned a number from the file to the min1 variable*/
        if(min1==-1){
        fscanf(file,"%d ",&min1);
        while(!feof(file)){
            /* I called the function called the fonksiyon I created below and checked whether the value I assigned to min1 is written in the file named temp.txt ..*/
            if(fonksiyon(min1)==-1){
            fscanf(file,"%d ",&min1);
            }
        else{
            break;
            }
        }
    }
        fclose(file);
        if(min1!=-1){
        file = fopen("results.txt","r");
        while(!feof(file)){
            fscanf(file,"%d ",&result);
            /* If the numbers pulled from the result.txt file do not exist in the temp.txt file and this number is less than the number kept in the min1 variable, this number is assigned to the min1 variable..*/
            if(result<min1 && fonksiyon(result)!=-1){
                min1=result;
                }
            }
            fclose(file);
        }
    }
        
    file = fopen("results.txt","r");
    if(file==NULL){
        printf("File could not be opened..");
    }
    else{
        /* I used this loop to evaluate the probability of having more than one of the same number in the result.txt file..*/
        while(!feof(file)){
            fscanf(file,"%d ",&result);
            if(result==min1){
                /* I used the Validate variable as the same number can happen twice in the results.txt file..*/
                validate++ ;
            }
            if(validate==2 && min1==result){
                min2=min1;
                break;
            }
        }
        /* I used the Validate variable as the same number can happen twice in the results.txt file..*/
        validate=0;
        fclose(file);
        file = fopen("results.txt","r");
        if(min2==-1){
        while(!feof(file)){
            fscanf(file,"%d ",&result);
            /* If one of the numbers in the checked results.txt file does not exist in the temp.txt file and is not equal to the number held in the min1 variable, assign this value to the min2 variable..*/
            if(fonksiyon(result)!=-1 && min1!=result){
                min2=result;
            }
            if(min2!=-1){
                break;
            }
        }
    }
        fclose(file);
        if(min2!=-1){
        file = fopen("results.txt","r");
            /* If there is a value that is not in the temp.txt file and is not equal to the value of the min1 variable and is less than min2, write it to the min2 variable..*/
            while(!feof(file)){
                fscanf(file,"%d ",&result);
                if(fonksiyon(result)!=-1 && result<min2 && result!=min1){
                    min2=result;
                    }
                }
            fclose(file);
            }
        }
       
    file = fopen("results.txt","r");
    if(file==NULL){
        printf("File could not be opened..");
    }
    else{
        /* I used this loop to evaluate the probability of having more than one of the same number in the result.txt file..*/
        while(!feof(file)){
            fscanf(file,"%d ",&result);
            if(result==min2){
                validate++;
            }
            if(validate==2  && min2!=min1){
                min3=min2;
                break;
            }
            if(validate==3 && min1==min2){
                min3=min2;
                break;
            }
        }
        validate=0;
        fclose(file);
        file = fopen("results.txt","r");
        if(min3==-1){
        while(!feof(file)){
            fscanf(file,"%d ",&result);
            /* It is similar to the steps I took to assign a value to the min2 variable in a few upper rows..*/
            if(fonksiyon(result)!=-1 && min1!=result && min2!=result){
                min3=result;
            }
            if(min3!=-1){
                break;
            }
        }
    }
        fclose(file);
        if(min3!=-1){
            file = fopen("results.txt","r");
            while(!feof(file)){
                fscanf(file,"%d ",&result);
                if(fonksiyon(result)!=-1 && result<min3 && result!=min1 && result!=min2){
                    min3=result;
                }
            }
        }
        fclose(file);
        }
        /* If there are no different numbers in the results.txt file than those in the temp.txt file, the min1 variable cannot be assigned a value from the file, so the min1 variable will correspond to the value of -1. In this way, we will come to the conclusion that the program can now come to an end..*/
        if(min1==-1){
            break;
        }
        /* Writes the numbers to the temp.txt file until the for loop is finished..*/
        dosya = fopen("temp.txt","a");
        fprintf(file,"%d ",min1);
        if(min2!=-1){
            fprintf(file,"%d ",min2);
        }
        if(min3!=-1){
            fprintf(file,"%d ",min3);
        }
        fclose(dosya);
        fclose(file);
    }
    /* Cleans inside results.txt file..*/
    file = fopen("results.txt","w");
    fclose(file);
    /* Exports the numbers sorted in the temp.txt file to the result.txt file*/
    dosya = fopen("temp.txt","r");
    file = fopen("results.txt","a");
        while(!feof(dosya)){
        fscanf(dosya,"%d ",&sonuc);
        fprintf(file,"%d ",sonuc);
    }
    fclose(dosya);
    fclose(file);
}


/*I wrote this function in order not to save the same number that I previously saved in the file named temp.txt ..*/
/* If the number -1 is returned from the function, it means that the value entered as a parameter to the function in the temp.txt file*/
int fonksiyon(int x){
    int variable;
    FILE* dosya;
    dosya = fopen("temp.txt","r");
    while(!feof(dosya)){
        fscanf(dosya,"%d ",&variable);
        if(x==variable){
            x=-1;
            fclose(dosya);
            return x;
        }
    }
    fclose(dosya);
    return x;
}



