#include <stdio.h>
#include <stdlib.h>

/* These are my unions and struct...*/
union Person
{
    char name[50];
    char address[50];
    int phone;
};
union Loan
{
    float arr[3];
};
struct BankAccount
{
    union Person Customer;
    union Loan Loans[3];
};

/* These are my global variables...*/
int counter=0,control=0,counter1=0;

/* These are my function...*/
void listCustomers(struct BankAccount a[]);
void addCustomer (struct BankAccount a[],int loan1[],float loan2[][4]);
void newLoan (struct BankAccount a[],int loan1[],float loan2[][4]);
float calculateLoan(float amount, int period, float interestRate);
void getReport(struct BankAccount a[],int loan1[],float loan2[][4],float month[][48]);
int satir_bul(FILE* file);


int main()
{
    /* validate :: I used it for while loop...
       operation :: I used it for my switch case struct..
       loan1 :: I used it to hold number of loan for whole customers...
       user :: I used it to hold loans information of customers while take from user...
       loan2 :: I used it to hold loans information of costumers while take from file...
       month :: I used it to hold to keep the status of the debt by month... */
    int validate=1,operation,loan1[50];
    struct BankAccount user[50];
    float loan2[50][4],month[50][48];
    
    /* I reseted my arrays in here..*/
    for(int j=0;j<50;j++)
    {
        loan1[j]=0;
    }
    
    for(int j=0;j<50;j++)
    {
        for(int k=0;k<4;k++)
        {
            loan2[j][k]=0.0;
        }
    }
    
    for(int j=0;j<50;j++)
    {
        for(int k=0;k<48;k++)
        {
            month[j][k]=0;
        }
    }

    while(validate)
    {
        printf("=====================================\nWelcome to the BANK MANAGEMENT SYSTEM\n=====================================");
        printf("\n\n1. List All Costumers\n");
        printf("2. Add New Costumer\n");
        printf("3. New Loan Application\n");
        printf("4. Report Menu\n");
        printf("5. Exıt System\n");
        
        printf("Enter your choice:");
        scanf("%d",&operation);
    
        switch(operation)
        {
            case 1:
                listCustomers (user);
                break;
                
            case 2:
                addCustomer (user,loan1,loan2);
                break;
                
            case 3:
                newLoan(user,loan1,loan2);
                break;
                
            case 4:
                getReport(user,loan1,loan2,month);
                break;
                
            case 5:
                validate=0;
                break;
                
            default :
                printf("The value you entered is invalid.. Please try again!!!");
                break;
        }
    }
    return 0;
}

/* I wrote this function to keep the names of newly entered users in union and use it whenever desired...*/

void listCustomers(struct BankAccount a[])
{
    int i=1;
    if(counter1!=0)
    {
        while(i<=counter1)
        {
            printf("Customer Name = %s\n\n",a[i-1].Customer.name);
            i++;
        }
    }
    else
    {
        printf("No new customer name has been entered since the last time the program was run...\n");
    }
}

/* I wrote this funcion to add new customer to customer.txt file...*/
void addCustomer (struct BankAccount a[],int loan1[],float loan2[][4])
{
    FILE* file;
    int id_user;
    
    /* I wrote this part to use the file as a database and pull the credit information of previous customers...*/
    if(counter==0)
    {
        if((file = fopen("loan.txt","r"))!=NULL)
        {
            while(!feof(file))
            {
                control=1;
                fscanf(file,"%d",&id_user);
                fscanf(file,",%f,%f,%f\n",&loan2[id_user-1][0],&loan2[id_user-1][3],&loan2[id_user-1][1]);
                loan1[id_user-1]++;
            }
            fclose(file);
        }
    }
    
    /* In this part, I used the customer.txt file as a database to keep the number of customers created before...*/
    if(counter==0)
    {
        if((file = fopen("customer.txt","r"))!=NULL)
        {
            counter = satir_bul(file)/4;
            fclose(file);
        }
    }
    
    if(counter<51)
    {
        /* I increment the counter variable by 1 when a new user is added...
         also I use the counter variable to save the previously entered users by using the file as a database...*/
        counter++;
        /* I have created a separate counter1 variable for the 1st part of the menu each time the program starts. I increment it by one each time a new customer is added... */
        counter1++;
    }
    if(counter==51)
    {
        printf("You can add up to 50 customers...\n");
    }
    else
    {
        printf("\n\nThe customers you enter will be kept in the file with id numbers from 1 to 50 according to the registration order.\n");
        
        file = fopen("customer.txt","a+");
    
        fprintf(file, "%d\n", counter);
    
        printf("Enter your address: ");
        getchar();
        scanf("%[^\n]%*c", a[counter-1].Customer.address);
        fprintf(file, "%s\n",a[counter-1].Customer.address);
    
        printf("Enter your phone: ");
        scanf("%d",&a[counter-1].Customer.phone);
        fprintf(file, "%d\n", a[counter-1].Customer.phone);
    
        printf("Enter your name: ");
        getchar();
        scanf("%[^\n]%*c", a[counter1-1].Customer.name);
        fprintf(file, "%s\n",a[counter1-1].Customer.name);
        
        fclose(file);
    }
}

/* I add credit information in this section to customers who have been added before...*/
void newLoan (struct BankAccount a[],int loan1[],float loan2[][4])
{
    int id,id_user;
    FILE* file2;
    
    /* I wrote this part to use the file as a database and pull the credit information of previous customers...*/
    if(counter==0)
    {
        if((file2 = fopen("loan.txt","r"))!=NULL)
        {
            while(!feof(file2))
            {
                control=1;
                fscanf(file2,"%d",&id_user);
                fscanf(file2,",%f,%f,%f\n",&loan2[id_user-1][0],&loan2[id_user-1][3],&loan2[id_user-1][1]);
                loan1[id_user-1]++;
            }
            fclose(file2);
        }
    }
    
    /* In this part, I used the customer.txt file as a database to keep the number of customers created before...*/
    if(counter==0)
    {
        if((file2 = fopen("customer.txt","r"))!=NULL)
        {
            counter = satir_bul(file2)/4;
            fclose(file2);
        }
    }
    
    printf("Enter the ID:");
    scanf("%d",&id);
    
    if(id>counter || id<1)
    {
        printf("The ID you entered is invalid...\n\n");
    }
    else
    {
        if(loan1[id-1]>=3)
        {
            printf("\nYou have made 3 loan entries before.. You can no longer login...\n\n");
        }
        else
        {
            
            file2 = fopen("loan.txt","a+");
            control=1;
            
            loan1[id-1]++;
            fprintf(file2,"%d,",id);
            
            printf("Enter the amount of loan: ");
            scanf("%f",&a[id-1].Loans[loan1[id-1]].arr[0]);
            fprintf(file2,"%f,",a[id-1].Loans[loan1[id-1]].arr[0]);
            
            printf("Enter the period: ");
            scanf("%f",&a[id-1].Loans[loan1[id-1]].arr[1]);
            fprintf(file2,"%f,",a[id-1].Loans[loan1[id-1]].arr[1]);
            
            printf("Enter the interest rate: ");
            scanf("%f",&a[id-1].Loans[loan1[id-1]].arr[2]);
            fprintf(file2,"%f\n",a[id-1].Loans[loan1[id-1]].arr[2]);
            
            fclose(file2);
        }
    }
}

/* I wrote the total amount of interest as a recursive function as a result of the loan taken by the customer through the information received from the user...*/
float calculateLoan(float amount, int period, float interestRate)
{
    if(period > 0)
    {
        amount*=(1+interestRate);
        calculateLoan(amount, period - 1, interestRate);
    }
        return amount;
}


void getReport(struct BankAccount a[],int loan1[],float loan2[][4],float month[][48])
{
    int selection,id,z,b,id_of_users,temp1,id_user,which_debt,kontrol=0;
    float ara_toplam=0.000000,temp,toplam=0.0;
    char c[100],d[100];
    FILE* dosya;
    
    /* I wrote this part to use the file as a database and pull the credit information of previous customers...*/
    if(counter==0)
    {
        if((dosya = fopen("loan.txt","r"))!=NULL)
        {
            while(!feof(dosya))
            {
                control=1;
                fscanf(dosya,"%d",&id_user);
                fscanf(dosya,",%f,%f,%f\n",&loan2[id_user-1][0],&loan2[id_user-1][3],&loan2[id_user-1][1]);
                loan1[id_user-1]++;
            }
            fclose(dosya);
        }
    }
    
    /* In this part, I used the customer.txt file as a database to keep the number of customers created before...*/
    if(counter==0)
    {
        if((dosya = fopen("customer.txt","r"))!=NULL)
        {
            counter = satir_bul(dosya)/4;
            fclose(dosya);
        }
    }
    
    printf("1. Customer Detail\n");
    printf("2. Loan Detail\n");
    
    printf("Enter your choice:");
    scanf("%d",&selection);
    
    switch(selection)
    {
        case 1:

            printf("\n\nEnter the id of the customer whose information you want to see:");
            scanf("%d",&id);
            if((id>counter && id!=51) || id<1)
            {
                printf("The value you entered is invalid...\n\n");
            }
            else
            {
                dosya = fopen("customer.txt","r");
                for(int j=1;j<id;j++)
                {
                    fscanf(dosya,"%d\n",&z);
                    fscanf(dosya,"%[^\n]%*c\n",c);
                    fscanf(dosya,"%d\n",&b);
                    fscanf(dosya,"%[^\n]%*c\n",d);
                }
                fscanf(dosya,"%d\n",&id_of_users);
                printf("ID = %d\n",id_of_users);
                fscanf(dosya,"%[^\n]%*c\n",a[id-1].Customer.address);
                printf("Address = %s\n",a[id-1].Customer.address);
                fscanf(dosya,"%d\n",&a[id-1].Customer.phone);
                printf("Phone = %d\n",a[id-1].Customer.phone);
                fscanf(dosya,"%[^\n]%*c\n",a[id-1].Customer.name);
                printf("Name = %s\n",a[id-1].Customer.name);
                    
                fclose(dosya);
                
                printf("Loans = [");
                if((dosya = fopen("loan.txt","r"))!=NULL)
                {
                    while(!feof(dosya))
                    {
                        fscanf(dosya,"%d",&id_user);
                        fscanf(dosya,",%f,%f,%f\n",&loan2[id_user-1][0],&loan2[id_user-1][3],&loan2[id_user-1][1]);
                        if(id_user==id_of_users)
                        {
                            printf(" +%.2f",calculateLoan(loan2[id_user-1][0],(int)loan2[id_user-1][3]*1,loan2[id_user-1][1]));
                            toplam+=calculateLoan(loan2[id_user-1][0],(int)loan2[id_user-1][3]*1,loan2[id_user-1][1]);
                        }
                    }
                    printf("] => %.2f\n\n",toplam);
                    fclose(dosya);
                }
                else
                {
                    printf(" 0 ] => 0");
                }
            }
            
            break;
        case 2:
            if(control!=0)
            {
                
                printf("Enter the id of the person you want to see the credit details of: ");
                scanf("%d",&id);
            
                if(id>counter || id<1)
                {
                    printf("The value you entered is invalid...\n\n");
                }
                else
                {
                    printf("Which credit debt:");
                    scanf("%d",&which_debt);
                    
                    if(which_debt>loan1[id-1] || which_debt<1)
                    {
                        printf("The value you entered is invalid...\n\n");
                    }
                    else
                    {
                        dosya = fopen("loan.txt","r");
                        while(!feof(dosya))
                        {
                            fscanf(dosya,"%d",&id_user);
                            fscanf(dosya,",%f,%f,%f\n",&loan2[id_user-1][0],&loan2[id_user-1][3],&loan2[id_user-1][1]);
                            if(id_user==id)
                            {
                                kontrol++;
                            }
                            if(kontrol==which_debt)
                            {
                                temp1 = (int)loan2[id_user-1][3] * 1;
                                ara_toplam = calculateLoan(loan2[id_user-1][0], temp1, loan2[id_user-1][1]);
                                temp = ara_toplam / loan2[id_user-1][3];
                                loan2[id_user-1][2] = ara_toplam;
                                for(int f=0;f<temp1;f++)
                                {
                                    month[id_user-1][f]=temp;
                                }
                                break;
                            }
                        }
                        fclose(dosya);
                        
                        printf("Total Credit Value = %.3f\n",loan2[id-1][2]);
                        for(int f=0;f<temp1;f++)
                        {
                            printf("%d. Month Installment = %.3f\n",f+1,month[id-1][f]);
                        }
                    }
                }
            }
            else
            {
                printf("\nNo loan information has been entered yet...\n");
            }
            break;
        default :
            printf("The value you entered is invalid...\n\n");
            break;
    }
}

/* I wrote this function to find number of line...*/
int satir_bul(FILE* file)
{
    int satir=0;
    char karakter;
    while(!feof(file))
    {
        karakter = getc(file);
        if(karakter=='\n')
        {
            satir++;
        }
    }
    return satir;
}
