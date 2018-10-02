#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>
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
    if(n==2)
    {
     det = array[0][0]*array[1][1] -array[0][1]*array[1][0];
     return det;
    }
    else
    {
     for(loop=0;loop<n;loop++)
     {
      int **temp = findDetMat(array,i,j,n-1);

      det +=(pow(-1,i+j)*array[i][j]*determinent(temp,i,j++,n-1));
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
     
     process = fork();
     
     if(process==0)
     {
       printf("\nChild Reads the Matrix\n");
 
       for(i=0;i<size;i++)
        for(j=0;j<size;j++)
         read(mem[0],&skew[i][j],sizeof(int));
 
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
     else
     {
      
      for(i=0;i<size;i++)
       for(j=0;j<size;j++)
         write(mem[1],&array[i][j],sizeof(array));
    
      close(mem[1]);
      
      printf("\nParent writes the matirx\n");
     }
    }
    else
     printf("\nPipe Creation Failed\n");
    
    free(array);
    free(skew);
}
