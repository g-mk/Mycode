#include<stdio.h>
#include<stdlib.h>
struct student
{
 int rollno;
 char name[30],sec;
 int m[4];
 int total;
 float avg;
 int p,r,ar;
}**s;
void rank(struct student **,int);
int classtopper(struct student **,int,int);
