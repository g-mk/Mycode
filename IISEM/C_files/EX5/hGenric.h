#include<stdio.h>
#include<string.h>
struct student
{
 int adno;
 float avg;
 char name[30];
 char sec;
};
struct student s[30];
//void *(cmptr)(void *,int,int);
//void *(swptr)(struct student *,int ,int);
void sort(void *,int,int  (*cmptr)(void*,int,int,int),void (*swptr)(struct student *,int, int),int);
int compare(void *,int,int,int);
void swap(struct student *,int,int);
