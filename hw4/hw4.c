#include<stdio.h>
void red(void);
void green(void);
void reset(void);
int main(){
    int select,a,b,c,i,j,validate=1,x,y,delta;
    FILE* file;
    FILE* dosya;
    while(validate){
        printf("Select an operation:\n");
        printf("1 ->> Enter the coeficcient.\n");
        printf("2 ->> Draw the graph.\n");
        printf("3 ->> Print the graph into  graph.txt file\n");
        printf("4 ->> Exit\n\n");
    printf("Choice: ");
    scanf("%d",&select);
    switch(select){
            
        case 1:
            printf("Please enter the coeficcient for the foloowing equation: x=a*(y*y) + b*y + c\n\n");
            printf("a: ");
            scanf("%d",&a);
            printf("b: ");
            scanf("%d",&b);
            printf("c: ");
            scanf("%d",&c);
            file = fopen("coefficient.txt","w");
            fclose(file);
            file = fopen("coefficient.txt","a");
            fprintf(file,"%d\n%d\n%d",a,b,c);
            fclose(file);
            printf("\n coefficient.txt file has been created...\n");
            break;
            
        case 2:
            if((file = fopen("coefficient.txt","r"))!=NULL){
            file = fopen("coefficient.txt","r");
            fscanf(file,"%d\n%d\n%d",&a,&b,&c);
            fclose(file);
            /* I used this loop to plot a coordinate plane and identify points that fit the given equation..*/
            for(i=16;i>=-15;i--){
                for(j=-56;j<=56;j++){
                    x=j;
                    y=i;
                    delta=(a*y*y)+(b*y)+c;
                    /* I put a # sign at the points that provide the equation created in case 1..*/
                    if(x==delta && i!=16 && j!=56 && j!=-56){
                        red(); //Set the text to the color red
                        printf("#");
                        reset();//Resets the text to default color
                    }
                    /* I placed numbers on the coordinate plane to define location information..*/
                    else if(i==5 && j==-2){
                        green();
                        printf("5");
                        reset();
                    }
                    else if(i==10 && j==-3){
                        green();
                        printf("1");
                        reset();
                    }
                    else if(i==10 && j==-2){
                        green();
                        printf("0");
                        reset();
                    }
                    else if(i==15 && j==-3){
                        green();
                        printf("1");
                        reset();
                    }
                    else if(i==15 && j==-2){
                        green();
                        printf("5");
                        reset();
                    }
                    else if(i==-5 && j==-3){
                        green();
                        printf("-");
                        reset();
                    }
                    else if(i==-5 && j==-2){
                        green();
                        printf("5");
                        reset();
                    }
                    else if(i==-10 && j==-4){
                        green();
                        printf("-");
                        reset();
                    }
                    else if(i==-10 && j==-3){
                        green();
                        printf("1");
                        reset();
                    }
                    else if(i==-10 && j==-2){
                        green();
                        printf("0");
                        reset();
                    }
                    else if(i==-15 && j==-4){
                        green();
                        printf("-");
                        reset();
                    }
                    else if(i==-15 && j==-3){
                        green();
                        printf("1");
                        reset();
                    }
                    else if(i==-15 && j==-2){
                        green();
                        printf("5");
                        reset();
                    }
                    else if(i==-1 && j==-12){
                        green();
                        printf("-");
                        reset();
                    }
                    else if(i==-1 && j==-11){
                        green();
                        printf("1");
                        reset();
                    }
                    else if(i==-1 && j==-10){
                        green();
                        printf("0");
                        reset();
                    }
                    else if(i==-1 && j==-22){
                        green();
                        printf("-");
                        reset();
                    }
                    else if(i==-1 && j==-21){
                        green();
                        printf("2");
                        reset();
                    }
                    else if(i==-1 && j==-20){
                        green();
                        printf("0");
                        reset();
                    }
                    else if(i==-1 && j==-32){
                        green();
                        printf("-");
                        reset();
                    }
                    else if(i==-1 && j==-31){
                        green();
                        printf("3");
                        reset();
                    }
                    else if(i==-1 && j==-30){
                        green();
                        printf("0");
                        reset();
                    }
                    else if(i==-1 && j==-42){
                        green();
                        printf("-");
                        reset();
                    }
                    else if(i==-1 && j==-41){
                        green();
                        printf("4");
                        reset();
                    }
                    else if(i==-1 && j==-40){
                        green();
                        printf("0");
                        reset();
                    }
                    else if(i==-1 && j==-52){
                        green();
                        printf("-");
                        reset();
                    }
                    else if(i==-1 && j==-51){
                        green();
                        printf("5");
                        reset();
                    }
                    else if(i==-1 && j==-50){
                        green();
                        printf("0");
                        reset();
                    }
                    else if(i==-1 && j==-1){
                        green();
                        printf("0");
                        reset();
                    }
                    else if(i==-1 && j==9){
                        green();
                        printf("1");
                        reset();
                    }
                    else if(i==-1 && j==10){
                        green();
                        printf("0");
                        reset();
                    }
                    else if(i==-1 && j==19){
                        green();
                        printf("2");
                        reset();
                    }
                    else if(i==-1 && j==20){
                        green();
                        printf("0");
                        reset();
                    }
                    else if(i==-1 && j==29){
                        green();
                        printf("3");
                        reset();
                    }
                    else if(i==-1 && j==30){
                        green();
                        printf("0");
                        reset();
                    }
                    else if(i==-1 && j==39){
                        green();
                        printf("4");
                        reset();
                    }
                    else if(i==-1 && j==40){
                        green();
                        printf("0");
                        reset();
                    }
                    else if(i==-1 && j==49){
                        green();
                        printf("5");
                        reset();
                    }
                    else if(i==-1 && j==50){
                        green();
                        printf("0");
                        reset();
                    }
                    else if(i==16 && j==0){
                        printf("^");
                    }
                    else if(i==0 && j==56){
                        printf(">");
                    }
                    else if(i==0 && j==-56){
                        printf("<");
                    }
                    else if(j==0 && i!=16){
                        printf("|");
                    }
                    else if(i==0 && (j!=-56 || j!=56)){
                        printf("-");
                    }
                    else {
                    printf(" ");
                    }
                }
                printf("\n");
                }
            }
            else{
                printf("Equation not found.. Please enter the coefficients you want first...");
            }
            break;
            
        case 3:
            if((file = fopen("coefficient.txt","r"))!=NULL){
            file = fopen("coefficient.txt","r");
            fscanf(file,"%d\n%d\n%d",&a,&b,&c);
            dosya = fopen("graph.txt","w");
            fclose(dosya);
            dosya = fopen("graph.txt","a");
            fprintf(dosya,"\n\n\n");
            for(i=16;i>=-15;i--){
                for(j=-56;j<=56;j++){
                    x=j;
                    y=i;
                    delta=(a*y*y)+(b*y)+c;
                    if(x==delta && i!=16 && j!=56 && j!=-56){
                        fprintf(dosya,"#");
                    }
                    else if(i==16 && j==0){
                        fprintf(dosya,"^");
                    }
                    else if(i==0 && j==56){
                        fprintf(dosya,">");
                    }
                    else if(i==0 && j==-56){
                        fprintf(dosya,"<");
                    }
                    else if(j==0 && i!=16){
                        fprintf(dosya,"|");
                    }
                    else if(i==0 && (j!=-56 || j!=56)){
                        fprintf(dosya,"-");
                    }
                    else {
                    fprintf(dosya," ");
                    }
                }
                fprintf(dosya,"\n");
            }
            fclose(dosya);
            printf("Coefficients has been read from the coefficient file..\n");
            printf("The graph of x=%d*(y*y)+%d*y+%d has been written to graph.txt file..\n",a,b,c);
                }
            else{
                printf("There is no coefficient.txt file. Please select 1 from the menu to create the equation you want first..");
            }
            
            break;
            
        case 4:
            validate=0;
            break;
        default:
            printf("Value you entered is invalid.. Please try again.!!\n");
            break;
        }
    }
    return 0;
}

void red(void){
  printf("\033[1;31m");
}
void green(void){
  printf("\033[0;32m");
}
void reset(void){
  printf("\033[0m");
}
