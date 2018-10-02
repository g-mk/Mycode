#include<stdio.h>
#include<stdlib.h>
struct employee
{
 char name[30];
 int eid;
 float BP,DA,HRA,EPF,GP,salary;
}*e,*xtr,temp;
void display(FILE *,struct employee *,int);
void extract(FILE *,struct employee *,int,float );
void calc(struct employee *,FILE *,int );
void print(FILE *,int ,int );

