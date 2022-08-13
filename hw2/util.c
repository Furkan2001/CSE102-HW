#include <stdio.h>
#include "util.h"


char dt1a(float PL,float PW,float SL,float SW){
    
    if(PL<2.45){
        return 'S';
    }
    else{
        if(PW<1.75){
            if(PL<4.95){
                if(PW<1.65){
                return 'E';
                }
            }
        }
    }
    return 'I';
}




char dt1b(float PL,float PW,float SL,float SW){
    if(PL<2.55){
        return 'S';
    }
    else{
        if(PW<1.69){
            if(PL<4.85){
                return 'E';
            }
            else{
                return 'I';
            }
        }
        else{
            return 'I';
        }
    }
}


double dt2a(float x1,float x2,float x3,int x4,int x5){
    if(x1<31.5){
        if(x2>2.5){
            return 5.0;
        }
        else{
            if(x2-0.1<=x1 && x1<=x2+0.1){
                return 2.1;
            }
            else{
                return -1.1;
            }
        }
    }
    else{
        if(-1<=x3 && x3<=2){
            return 1.4;
        }
        else{
            if(x4==1 && x5==1){
                return-2.23;
            }
            else{
                return 11.0;
            }
        }
    }
}


double dt2b(float x1,float x2,float x3,int x4,int x5){
    if(12<x1 && x1<22){
        if(x3>(float)5/3){
            return -2.0;
        }
        else{
            if(x1-0.1<=x3 && x3<=x1+0.1){
                return 1.01;
            }
                return -8;
        }
    }
    else{
        if(x4==1 && x5==1){
            return -1;
        }
        else{
            if(-1<=x2 && x2<=2){
                return -1.7;
            }
            return 0.471;
        }
    }
}


int dt3a(float a1,float a2,int a3,int a4,int a5){
    if(a3==1){
        if(a4==1){//mangal
            if(a1<=2000){//doymaz
                return 1;
            }
            else{  //doyar
                return 2;
                }
            }
        else if(a4==2){//kamp
            return 3;
        }
        else if(a4==3){//sinema
            if(a5==1){//karayip korsanlar
                return 4;
            }
            else if(a5==2){//maymunlar cehennemi
                return 5;
            }
            else if(a5==3){//titanic
                return 6;
            }
            else if(a5==4){//uyumsuz
                return 7;
            }
            else if(a5==5){//forest gump
                return 8;
            }
        }
        else if(a4==4){//parti
            if(a2>120){//çok fazla kaldın eve dön..
                return 9;
            }
            else{
            //istenilen süre abartılı değil..
                return 10;
            }
            }
        else if(a4==5){//tenis oynamak
            return 11;
        }
    }
    
    else{
        if(a4==1){//yemek yap
            if(a1==1){//Döner
                return 12;
            }
            else if(a1==2){//Tavuk
                return 13;
            }
            else if(a1==3){//Balık
                return 14;
            }
            else if(a1==4){//Fasulye
                return 15;
            }
            else if(a1==5){//Makarna
                return 16;
                
            }
        }
        else if(a4==2){//evi temizle
            return 17;
        }
        else if(a4==3){//oyun oyna
            if(a1>120){//Çok fazla oyun oynadın..
                return 18;
            }
            else{
                return 19;
            }
        }
        else if(a4==4){//sohbet et
            return 20;
            
        }
        else if(a4==5){//televizyon izle
            if(a2>120){//çok fazla izliyosun
                return 21;
            }
            else{ //izleme süren makul
                return 22;
            }
        }
    }
    return 0;
}

int dt3b(float a1,float a2,int a3,int a4,int a5){
    
    if(a3==1){
        if(a4==1){//tenis oyna
            if(a1>90){//çok oynadın
                return 1;
            }
            else{
                return 2;
            }
        }
        else if(a4==2){//partiye git
            return 3;
        }
        else if(a4==3){//Kamp
            if(a5==1){//İzmir
                return 4;
            }
            else if(a5==2){//Antalya
                return 5;
            }
            else if(a5==3){//İstanbul
                return 6;
            }
            else if(a5==4){//Erzincan
                return 7;
            }
            else if(a5==5){//Muğla
                return 8;
            }
        }
        else if(a4==4){//mangal
            return 9;
        }
        else if(a4==5){//Sinemaya git
            return 10;
        }
    }
    
    else{
        if(a4==1){//Oyun oyna
            if(a1==1){//FIFA22
                return 11;
            }
            else if(a1==2){//VALORANT
                return 12;
            }
            else if(a1==3){//CS 1.6
                return 13;
            }
            else if(a1==4){//PES22
                return 14;
            }
            else if(a1==5){//PUPG
                return 15;
            }
        }
        else if(a4==2){//Televizyon izle
            return 16;
        }
        else if(a4==3){//sohbet et
            if(a1>120){//Çok gevezelik yaptın
                return 17;
            }
            else{ //sohbet süresi yeterli
                return 18;
            }
        }
        else if(a4==4){//Evi temizle
            return 19;
        }
        else if(a4==5){//Yemek yap
            if(a2>60){//Daha hızlı olmalısın çok oyalandın..
                return 20;
            }
            else{  //süre makul
                return 21;
            }
        }
    }
    return 0;
}
