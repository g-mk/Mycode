#include"hEmp.h"
void calc(struct employee *s,FILE *f,int n)
{
 int t,i;
 for(i=0;i<n;i++)
 {
  s[i].DA=s[i].BP*.8;
  s[i].HRA=s[i].BP*.05;
  s[i].EPF=s[i].BP*.25;
  s[i].GP=s[i].DA+s[i].HRA+s[i].BP;
  s[i].salary=s[i].GP-s[i].EPF;
 }
 t=fwrite(s,sizeof(struct employee),n,f);
 if(t==n)
  {
   printf("<<<Data Transferd Sucessfully>>>\n");
  }

}
void display(FILE *f,struct employee *xtr,int n)
{
 int i,t;
 printf("DISPLAY\n");
t= fread(xtr,sizeof(struct employee),n,f);
if(t==n)
  {
   printf("<<<Data READ Sucessfully>>>\n");
  }


 for(i=0;i<n;i++)
 {
  printf("Name:%s\n",xtr[i].name);
  printf("ID:%d\n",xtr[i].eid);
  printf("Basic Pay:%.2f\n",xtr[i].BP);
  printf("DA:%.2f\n",xtr[i].DA);
  printf("HRA:%.2f\n",xtr[i].HRA);
  printf("EPF:%.2f\n",xtr[i].EPF);
  printf("Gross Pay:%.2f\n",xtr[i].GP);
  printf("Salary:%.2f\n",xtr[i].salary);
 }
}
void print(FILE *f,int n,int e)
{
 fseek(f,(e-1)*sizeof(struct employee),SEEK_SET);
 fread(&temp,sizeof(struct employee),1,f);
  printf("Name:%s\n",temp.name);
  printf("ID:%d\n",temp.eid);
  printf("Basic Pay:%.2f\n",temp.BP);
  printf("DA:%.2f\n",temp.DA);
  printf("HRA:%.2f\n",temp.HRA);
  printf("EPF:%.2f\n",temp.EPF);
  printf("Gross Pay:%.2f\n",temp.GP);
  printf("Salary:%.2f\n",temp.salary);
}
void extract(FILE *f,struct employee *xtr,int n,float sl)
{
 int i,t;
 t=fread(xtr,sizeof(struct employee),n,f);
  if(t==n)
   printf("<<<<DATA EXTRACTED>>>>\n");
 for(i=0;i<n;i++)
 { 
  if(xtr[i].salary>sl)
  {
  printf("Name:%s\n",xtr[i].name);
  printf("ID:%d\n",xtr[i].eid);
  printf("Basic Pay:%.2f\n",xtr[i].BP);
  printf("DA:%.2f\n",xtr[i].DA);
  printf("HRA:%.2f\n",xtr[i].HRA);
  printf("EPF:%.2f\n",xtr[i].EPF);
  printf("Gross Pay:%.2f\n",xtr[i].GP);
  printf("Salary:%.2f\n",xtr[i].salary);
  }
 }
}
