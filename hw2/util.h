#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001


char dt1a(float PL,float PW,float SL,float SW);
char dt1b(float PL,float PW,float SL,float SW);

double dt2a(float x1,float x2,float x3,int x4,int x5);
double dt2b(float x1,float x2,float x3,int x4,int x5);

/* Write the prototype of the functions implementing the decision trees for the third problem */
int dt3a(float a1,float a2,int a3,int a4,int a5);
int dt3b(float a1,float a2,int a3,int a4,int a5);

#endif /* _UTIL_H_ */
