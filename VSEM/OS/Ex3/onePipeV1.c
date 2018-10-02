/*******************************************************************************
**Description   : Deploying the Interprocess Communication for message passing**
**                between two process using pipe() and determining the nxn    **
**                matrix determinant and skew symmetric condition             **
**Author        : N. Guru Manikandan.                                         **
**Date Created  : 14/07/2016.                                                 **
**Version       : 1.1                                                         **
*******************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
int** findDetMat(int *temp[],int i,int j,int n)
{
    int k,l,r=0,c=0;
    int **array = (int**)malloc(sizeof(int*)*n);
    for(k=0;k<n;k++)
     array[k]=(int*)malloc(sizeof(int)*n);
    for(k=0;k<n+1;k++)
    {
     for(l=0;l<n+1;l++)
     {
      if((i!=k) && (j!=l))
      {
        array[r][c]=temp[k][l];
        c++;
       }
      if(c>=n)
      {
         r++;
         c=0;
      }
     }
    }
    return array;
}

int determinent(int *array[],int i,int j,int n)
{
    int loop,det=0;
    int **temp;
    if(n==2)
    {
     det = array[0][0]*array[1][1] -array[0][1]*array[1][0];
     return det;
    }
    else if(n==3)
    {
     for(loop=0;loop<n;loop++)
     {
      temp = findDetMat(array,i,loop,n-1);

      det +=(pow(-1,i+j)*array[i][j]*determinent(temp,i,j++,n-1));
     }
     return det;
    }
    else
    {
     for(loop=0;loop<n;loop++)
     {
      temp = findDetMat(array,0,loop,n-1);
      det += pow(-1,i+loop)*array[i][loop]*determinent(temp,0,0,n-1);
     }
     return det;
    }
}

void main()
{
     int pipe1,flag=1,process,i,j,mem[2],size,**array,**skew;
     
     printf("Enter the size of the matrix nXn: ");
     scanf("%d",&size);
     
     array = (int**) malloc(size*sizeof(int*));
     skew = (int**) malloc(size*sizeof(int*));
     
     for(i=0;i<size;i++)
     {
      array[i]=(int*)malloc(size*sizeof(int));
      skew[i]=(int*)malloc(size*sizeof(int));
     }
     
     pipe1=pipe(mem);
     
     if(pipe1==0)
     {
      printf("\nEnter the data one by one:\n");
      for(i=0;i<size;i++)
       for(j=0;j<size;j++)
       {
         printf("Element [%d][%d] : ",i+1,j+1);
         scanf("%d",&array[i][j]);
       }
      
      for(i=0;i<size;i++)
      {
       for(j=0;j<size;j++)
       {
         if(array[i][j]!=-(array[j][i]))
         {
           flag =0;
           break;
         }
       }
      if(!flag)
       break;
     }
    
     if(flag)
      printf("\nSkew Symettric\n\n");
     else
      printf("\nNot a Skew Symettric\n\n");
     
     write(mem[1],&array,sizeof(array));
    
     close(mem[1]);
      
     printf("\nParent writes the matirx\n");
      
     process = fork();
     
     if(process==0)
     {
       printf("\nChild Reads the Matrix\n");
       
       read(mem[0],&skew,sizeof(skew));
 
       close(mem[0]);
 
       printf("\n\nGiven Matrix is : \n\n");
     
       for(i=0;i<size;i++)
       {
        for(j=0;j<size;j++)
         printf("%d\t",skew[i][j]);
 
        printf("\n");
       }
     
       printf("\n\nDeterminent Of the Matrix is: %d\n\n",determinent(skew,0,0,size));
     }
     
    }
    else
     printf("\nPipe Creation Failed\n");
    
    free(array);
}
