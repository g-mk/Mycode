#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stock
{
 int id;
 char n[20];
 float r;
 int s;
};
int alloc(struct stock * ,int,int ,int);
int check(struct stock *,int ,int,int );
int remov(struct stock *,int ,int );

