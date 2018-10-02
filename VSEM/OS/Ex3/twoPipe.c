#include<stdio.h>
#include<unistd.h>
#include<math.h>
void main()
{
 int fileDes[2],fileDes1[2],pipe1,pipe2,rem,perfectNum,squareNum,temp;
 int div=1,sum=0;
 
 pid_t process;
 
 pipe1=pipe(fileDes);
 pipe2=pipe(fileDes1);
 
 if(pipe1==0&&pipe2==0)
 {
  printf("\n\nPipe Created\n\n");
 
  printf("Enter the Number: ");
  scanf("%d",&perfectNum);
 
  write(fileDes[1],&perfectNum,sizeof(int));
 
  process=fork();
 
  if(process==0)
  {
    printf("\n\nChild Process\n\n");
    printf("\n\nEnter the NUmber to Check the Perfect Square: ");
    scanf("%d",&squareNum);
    
    write(fileDes1[1],&squareNum,sizeof(int));
    
    read(fileDes[0],&perfectNum,sizeof(int));
    
    temp=perfectNum;
    while(temp>div)
    {
      if(temp%div==0)
        sum+=div;
      div++;
    } 
    if(sum==perfectNum)
     printf("\nGiven Number is Perfect Number\n");
    else
     printf("\nGiven Number is Not a Perfect Number\n");
  }
  else
  {
   printf("\n\nParent Process\n\n");
   read(fileDes1[0],&temp,sizeof(int));
   
   squareNum=temp;
   
   temp=sqrt(temp);
   
   if(squareNum==pow(temp,2))
    printf("\n\nGiven Number is Perfect Square\n\n");
   else
    printf("\n\nGiven Number is Not a Perfect Square\n\n");
  } 
 }
 else
  printf("\nPipe Creation Failed\n")  ;
}
