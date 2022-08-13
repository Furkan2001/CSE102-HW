#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.14
/* I did my enums..*/
enum Shapes{
    Triangle=1,
    Quadrilateral,
    Circle,
    Pyramid,
    Cylinder
};
enum Calculators{
    Area=1,
    Perimeter,
    Valume
};

int select_shape(void);
int select_calc(void);
int calculate(int select_shape(void), int select_calc(void));
int calc_triangle(int x);
int calc_quadrilateral(int x);
int calc_circle(int x);
int calc_pyramid(int x);
int calc_cylinder(int x);

int main(){
    int x=0;
    printf("Welcome to the geometric calculator !!!\n\n");
    /* I looped for the function called unless the user wanted to exit..*/
    /* I returned the value -999 for situations where the user wants to exit*/
    while(x!=-999){
    x=calculate(select_shape,select_calc);
    }
    return 0;
}


int select_shape(void){
    enum Shapes choise;
    int trying=1,deneme=1;
    while(trying){
    printf("Select the shape to calculate:\n ");
    printf("-----------------------------------------\n");
    printf("1. Triangle\n");
    printf("2. Quadrilateral\n");
    printf("3. Circle\n");
    printf("4. Pyramid\n");
    printf("5. Cylinder\n");
    printf("0. Exit\n");
    printf("-----------------------------------------\n");
    printf("INPUT: ");
 
    if(scanf("%u",&choise)==1){
        trying=0;
        while((getchar())!='\n'){
            trying=1;
        }
        if(trying==1){
            printf("Please Enter a valid number..\n\n");
        }
        
    }
        /* I checked whether the entered input is really a number and returned an error if it is not.*/
    else{
        getc(stdin);
        getc(stdin);
        printf("Please Enter a valid number..\n\n");
        }
    }
    return choise;
}


int select_calc(void){
    enum Calculators choise;
    int trying=1;
    while(trying){
    printf("Select calculator:\n");
    printf("-----------------------------------------\n");
    printf("1. Area\n");
    printf("2. Perimeter\n");
    printf("3.Volume\n");
    printf("0. Exit\n");
    printf("-----------------------------------------\n");
    printf("INPUT: ");
    if(scanf("%u",&choise)==1){
        trying=0;
        while((getchar())!='\n'){
            trying=1;
        }
        if(trying==1){
            printf("Please Enter a valid number..\n\n");
        }
    }
        /* I checked whether the entered input is really a number and returned an error if it is not.*/
    else {
        getc(stdin);
        getc(stdin);
        printf("Please Enter a valid number..\n\n");
        }
    }
    return choise;
}


int calculate(int select_shape(void),int select_calc(void)){
    int a,b;
    a=select_shape();
    if(a==0){
        printf("Program terminated...\n\n");
    return -999; //Programdan çık ve kullanıcıya bilgi ver..
    }
    if(!(a>0 && a<=5)){
        printf("Please enter a valid entry...\n");
        return -1;
    }
    b=select_calc();
    if(b==0){
        printf("Program terminated...\n\n");
    return -999; //Programdan çık ve kullanıcıya bilgi ver..
    }
    if(!(b>0 && b<=3)){
        printf("Please enter a valid entry...\n");
        return -1;
    }
    if(a>0 && a<=5){
        if(b>0 && b<=3){
            /* I called function user want...*/
    switch(a){
        case Triangle:
            calc_triangle(b);
            break;
        case Quadrilateral:
             calc_quadrilateral(b);
            break;
        case Circle:
             calc_circle(b);
            break;
        case Pyramid:
             calc_pyramid(b);
            break;
        case Cylinder:
             calc_cylinder(b);
            break;
            }
        }
    }
    return -1;
    }


int calc_triangle(int x){
    float side1,side2,side3,s,area,perimeter,fark1,fark2,fark3,trying=1;
    if(x!=3){
        /* i created a loop that doesn't end until i find the result*/
        while(trying){
        printf(" Enter the side lengths of the triangle, please:\n");
        if(scanf("%f",&side1)==1){
            if(scanf("%f",&side2)==1){
                if(scanf("%f",&side3)==1){
                    trying=0;
                    while((getchar())!='\n'){
                        trying=1;
                    }
                    if(trying==1){
                        printf("Please Enter a valid number..\n\n");
                    }
                }
            }
        }
            /* I checked if the input is a number*/
        if(trying==1){
            getc(stdin);
            getc(stdin);
            printf("Please enter a valid entry...\n");
            }
            if((side1<=0 || side2<=0 || side3<=0) && trying==0){
                printf("Please enter a valid entry...\n");
                trying=1;
            }
            /* I checked if the entered values ​​belong to the triangle...*/
            if(!(side1<=0 || side2<=0 || side3<=0)){
            if(side1>=side2){
                fark1=side1-side2;
            }
            else{
                fark1=side2-side1;
            }
            if(side1>=side3){
                fark2=side1-side3;
            }
            else{
                fark2=side3-side1;
            }
            if(side2>=side3){
                fark3=side3-side2;
            }
            else{
                fark3=side2-side3;
            }
            if((side1+side2)>side3 && (side1+side3)>side2 && (side2+side3)>side1 && fark1<=side3 && fark2<=side2 && fark3<=side1){
            switch(x){
                case Area:
                    s=(side1+side2+side3)/(float)2;
                    area=(s)*(s-side1)*(s-side2)*(s-side3);
                    area=sqrt(area);
                    printf("The area is %.3f\n",area);
                    return 0;
                    break;
                case Perimeter:
                    perimeter=side1+side2+side3;
                    printf("%3.f\n",perimeter);
                    return 0;
                    break;
                }
            }
            else{
                printf("ERROR ! Please enter a valid triangle..\n");
                    }
                }
            }
        }
    /* I returned an error because 2-dimensional objects have no volume...*/
    else{
        printf("You can not calculate the volume of a triangle... PLEASE TRY AGAİN...\n");
        }
        return 0;
}


int calc_quadrilateral(int x){
    float side1,side2,side3,side4,area,perimeter,s,control=1;
    int trying=1;
    if(x!=Valume){
        /* i created a loop that doesn't end until i find the result*/
        while(trying){
        printf(" Enter the side lengths of the triangle, please:\n");
        if(scanf("%f",&side1)==1){
            if(scanf("%f",&side2)==1){
                if(scanf("%f",&side3)==1){
                    if(scanf("%f",&side4)==1){
                        trying=0;
                        while((getchar())!='\n'){
                            trying=1;
                        }
                        if(trying==1){
                            printf("Please Enter a valid number..\n\n");
                        }
                    }
                }
            }
        }
            /* I checked if the input is a number*/
        if(trying==1){
            getc(stdin);
            getc(stdin);
            printf("Please enter a valid entry...\n");
            }
            if(trying==0){
                /* I made a check whether the entered values ​​belong to a rectangle or not...*/
            if(side1<(side2+side3+side4)){
                if(side2<(side1+side3+side4)){
                    if(side3<(side2+side1+side4)){
                        if(side4<(side2+side3+side1)){
            if(!(side1<=0 || side2<=0 || side3<=0 || side4<=0)){
            switch(x){
                case Area:
                    s=(side1+side2+side3+side4)/(float)2;
                    area=(s-side4)*(s-side1)*(s-side2)*(s-side3);
                    area=sqrt(area);
                    printf("The area is %.3f\n",area);
                    return 0;
                    break;
                case Perimeter:
                    perimeter=side1+side2+side3+side4;
                    printf("%.3f\n",perimeter);
                    return 0;
                    break;
                }
                control=0;
            }
            else{
                printf("Please enter a valid entry...\n");
                trying=1;
                                    }
                                }
                            }
                        }
                    }
                }
                           if(trying==0 && control==1){
                               printf("ERROR ! Please enter a valid quadrilateral...\n\n");
                        }
            }
        }
    else{
        printf("You can not calculate the volume of a quadrilateral. PLEASE TRY AGAİN...\n");
    }
        return 0;
}


int calc_circle(int x){
    float radius,area,perimeter;
    int trying=1;
    if(x!=Valume){
        /* i created a loop that doesn't end until i find the result*/
        while(trying){
    printf("Please enter the radius of circle:\n");
        if(scanf("%f",&radius)==1){
            trying=0;
            while((getchar())!='\n'){
                trying=1;
            }
            if(trying==1){
                printf("Please Enter a valid number..\n\n");
            }
        }
            /* I checked if the input is a number*/
        if(trying==1){
            getc(stdin);
            getc(stdin);
            printf("Please enter a valid entry...\n");
            }
            if(trying==0){
            if(!(radius<=0)){
            switch(x){
                case Area:
                    area=(PI)*(radius)*(radius);
                    printf("The area is %.3f\n",area);
                    return 0;
                    break;
                case Perimeter:
                    perimeter=(float)(2)*(PI)*(radius);
                    printf("%.3f\n",perimeter);
                    return 0;
                    break;
                }
            }
            else{
                printf("Please enter a valid entry...\n");
                trying=1;
            }
        }
    }
}
    else{
        printf("You can not calculate the volume of a Circle. PLEASE TRY AGAİN...\n");
    }
    return 0;
}


int calc_pyramid(int x){
    float side,slant_height,area,perimeter,valume,base_area,lateral_area,height;
    int trying=1;
    switch(x){
        case Area:
            /* i created a loop that doesn't end until i find the result*/
            while(trying){
            printf("Please enter the base side and slant height of a Pyramid:\n");
            if(scanf("%f",&side)==1){
                if(scanf("%f",&slant_height)==1){
                    trying=0;
                    while((getchar())!='\n'){
                        trying=1;
                    }
                    if(trying==1){
                        printf("Please Enter a valid number..\n\n");
                    }
                }
            }
                /* I checked if the input is a number*/
            if(trying==1){
                getc(stdin);
                getc(stdin);
                printf("Please enter a valid entry...\n");
                }
                if(trying==0){
                if(!(side<=0 || slant_height<=0)){
                base_area=side*side;
                printf("Base surface area of a Pyramid: %.3f\n",base_area);
                lateral_area=(float)2*side*slant_height;
                printf("Lateral surface area of a Pyramid: %.3f\n",lateral_area);
                area=base_area+lateral_area;
                printf("Surface area of a Pyramid: %.3f\n",area);
                    return 0;
                    }
                else{
                    printf("Please enter a valid entry...\n");
                    trying=1;
                }
            }
        }
            break;
        case Perimeter:
            /* i created a loop that doesn't end until i find the result*/
            while(trying){
            printf("Please enter the base side: \n");
            if(scanf("%f",&side)==1){
                trying=0;
                while((getchar())!='\n'){
                    trying=1;
                }
                if(trying==1){
                    printf("Please Enter a valid number..\n\n");
                }
                }
                /* I checked if the input is a number*/
            else{
                getc(stdin);
                getc(stdin);
                printf("Please enter a valid entry...\n");
                }
                if(trying==0){
                if(!(side<=0)){
                perimeter=(float)4*side;
                printf("Base  surface perimeter of the Pyramid: %.3f\n",perimeter);
                    return 0;
                    }
                else{
                    printf("Base side of Pyramid cannot be 0 or negative number..!\n ");
                    trying=1;
                }
            }
        }
            break;
        case Valume:
            /* i created a loop that doesn't end until i find the result*/
            while(trying){
            printf("Please enter the base side and height of a Pyramid: \n");
            if(scanf("%f",&side)==1){
                if(scanf("%f",&height)==1){
                    trying=0;
                    while((getchar())!='\n'){
                        trying=1;
                    }
                    if(trying==1){
                        printf("Please Enter a valid number..\n\n");
                    }
                }
            }
                /* I checked if the input is a number*/
            if(trying==1){
                getc(stdin);
                getc(stdin);
                printf("Please enter a valid entry...\n");
                }
                if(trying==0){
                if(!(side<=0 || height<=0)){
                valume=(side*side*height)/(float)3;
                printf("Valume of a Pyramid: %.3f\n",valume);
                    return 0;
                    }
                else{
                    printf("Base side or height of a Pyramid cannot be 0 or negative number..!\n");
                    trying=1;
                }
            }
        }
            break;
        }
    return 0;
}


int calc_cylinder(int x){
    float radius,height,base_area,lateral_area,area,valume,perimeter;
    int trying=1;
    /* i created a loop that doesn't end until i find the result*/
        while(trying){
    printf("Please enter the radius and height of a Cylinder:\n");
        if(scanf("%f",&radius)==1){
            if(scanf("%f",&height)==1){
                trying=0;
                while((getchar())!='\n'){
                    trying=1;
                }
                if(trying==1){
                    printf("Please Enter a valid number..\n\n");
                }
                }
            }
            /* I checked if the input is a number*/
            if(trying==1){
                getc(stdin);
                getc(stdin);
                printf("Please enter a valid entry...\n");
            }
            if(trying==0){
            if(!(radius<=0 || height<=0)){
            switch(x){
                case Area:
                    base_area=PI*radius*radius;
                    printf("Base Surface Area of a Cylinder: %.3f\n",base_area);
                    lateral_area=(float)2*PI*radius*height;
                    printf("Lateral Surface Area of a Cylinder: %.3f\n",lateral_area);
                    area=(float)2*PI*radius*(radius+height);
                    printf("Surface area of a Cylinder: %.3f\n",area);
                    return 0;
                    break;
                case Perimeter:
                    perimeter=(float)2*PI*radius;
                    printf("Perimeter of a Cylinder: %.3f\n",perimeter);
                    return 0;
                    break;
                case Valume:
                    valume=(radius*radius*height*PI);
                    printf("Valume of a Cylinder: %.3f\n",valume);
                    return 0;
                    break;
                }
            }
            else{
                printf("Please enter a valid entry...\n");
                trying=1;
                }
            }
        }
   
    return 0;
}
