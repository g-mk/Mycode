/*******************************************************************************
**Description   : Implementation of File Allocation Technique                 **
**Author        : N. Guru Manikandan.                                         **
**Date Created  : 29/09/2016.                                                 **
**Version       : 0.1                                                         **
*******************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct file
{
 char name[10];
 int size;
 int blocks;
};
struct logtable
{
 char fname[10];
 int start;
 int end;
};
main()
{
 int nb,bs,nf,i,j,cylinder[100],r,pre,count=0;
 struct logtable lt[100];
 struct file f[100];
 printf("\nEnter the number of blocks:");
 scanf("%d",&nb);
 count=nb;
 for(i=0;i<nb;i++)
 {
  cylinder[i]=-1;
 }
 printf("\nEnter the block size:");
 scanf("%d",&bs);
 printf("\nEnter the number of Files:");
 scanf("%d",&nf);
 for(i=0;i<nf;i++)
 {
  printf("\nEnter the file name:");
  scanf("%s",f[i].name);
  printf("\nEnter the file size:");
  scanf("%d",&f[i].size);
 }
 printf("\n****************************************************************\n");
 for(i=0;i<nf;i++)
 {
   f[i].blocks=f[i].size/bs;
   r=f[i].size%bs;
   if(r!=0)
   {
    f[i].blocks=f[i].blocks+1;
   }
   printf("\nBlocks for %s:%d\n",f[i].name,f[i].blocks);
  if(count>=f[i].blocks)
  {
   r=rand()%nb;
   while(cylinder[r]!=-1)
   {
    r=rand()%nb;
   }
   pre=r;
   strcmp(lt[i].fname,f[i].name);
   lt[i].start=r;
   j=1;
   while(j<f[i].blocks)
   {
    r=rand()%nb;
    if(cylinder[r]==-1)
    {
     cylinder[pre]=r;
     pre=r;
     j++;
     count--;
    }
   }
   lt[i].end=r;
   cylinder[r]=0;
  }
  else
  {
   printf("\nThere are no blocks in the cylinder to allocate... %s\n",f[i].name);
  }
 }
 printf("\nFILE\tSTART\tEND\t\n");
 for(i=0;i<nf;i++)
 {
  printf("\n\n%s\t%d\t%d\n\n",f[i].name,lt[i].start,lt[i].end);
 }
 printf("\n****************************************************************\n");
 for(i=0;i<nf;i++)
 {
  printf("\n\nFile:%s\n\n",f[i].name);
  r=lt[i].start;
  while(r!=lt[i].end)
  {
   printf("%d->",r);
   r=cylinder[r];
  }
  printf("%d \n",r);
 }
 printf("\n****************************************************************\n");
}

