#include "slist.h"
/**********************************************************************************************

Function Name :	getInfo

Prototype : int getInfo()

Parameters Passed : None

Purpose : Get the value for the structure Info( for polynomial operation coeff, power)

Return Values : Info

Globals Used : None

Globals Changed : None

Calls : None

Called By : main()

**********************************************************************************************/

Info getInfo(FILE *fp)
{
	Info info;
    fscanf(fp,"%s",info.CommandName);
    fscanf(fp,"%s",info.CommandSyntax);
    fscanf(fp,"%s",info.CommandType);
    fscanf(fp,"%s",info.CommandDetails);
    return(info);
}
void dispInfo(Info info)
{
 cout<<"\nCommand Name : "<<info.CommandName;
 cout<<"\nSyntax: "<<info.CommandSyntax;
 cout<<"\nType: "<<info.CommandType;
 cout<<"\nDescription: "<<info.CommandDetails<<endl;
}

int ecompareInfo(Info info1,Info info2)
{
  if(strcmp(info1.CommandName,info2.CommandName)==0)
    return 1;
  else
    return 0;
}

/*int compareInfo(Info info1,Info info2)
{
	if(info1.val<info2.val)
		return 1;
	else
		return 0;
}*/




/**********************************************************************************************

Function Name :	getPos

Prototype : int getPos()

Parameters Passed : None

Purpose : Get the Position of the Node to be Inserted

Return Values : int

Globals Used : None

Globals Changed : None

Calls : None

Called By : main()

**********************************************************************************************/

int getPos()
{
	int nPos;

	do
	{
		cout<<"\n\n\tEnter the Position: ";

		cin>>nPos;

		if(nPos < 0)
		{
			cout<<"\n\n\tPlease... Enter a valid Postion ...\n\n";
		}

	}while(nPos < 0);	// Checking for Negative Position

	return(nPos);
}

/**********************************************************************************************

Function Name : main

Prototype : main()

Parameters Passed : None

Purpose : Main-Function

Return Values : None

Globals Used : None

Globals Changed : None

Calls : None

Called By : None

**********************************************************************************************/

int main()
{
	int NoOfEntries;
  int nStatus;
	FILE *fp;
	Info info;
	char filein[15];
    do
     {
	cout<<"Enter the File Name(*.txt) for Input:";
	cin>>filein;
        fp=fopen(filein,"r+");
        cout<<fp;
     }while(fp==NULL);
	
 LList l;
   	fscanf(fp,"%d",&NoOfEntries);
	for(int i=0;i<NoOfEntries;i++)
		{
			if(!feof(fp))
		        {
				fscanf(fp,"%s",info.CommandName);
				fscanf(fp,"%s",info.CommandSyntax);
				fscanf(fp,"%s",info.CommandType);
				fscanf(fp,"%s",info.CommandDetails);
				l.insertBeg(info);
      			}
			else 
				break;
		}
   cout<<"\n***********Insertion Completed***************\n";
   fclose(fp);
   l.display(dispInfo);
    do
     {
      cout<<"Enter the File Name(*.txt) for Deletion:";
      cin>>filein;
      fp=fopen(filein,"r+");
     }while(fp==NULL);
    
  cout<<"\n******************Deletion of the Entries in the File "<<filein<<"**********\n";
  fscanf(fp,"%d",&NoOfEntries);
  while(!feof(fp) && NoOfEntries>0)
  {
   nStatus=0;
   if(!feof(fp))
   {
    fscanf(fp,"%s",info.CommandName);
    nStatus=l.deleteNode(info,ecompareInfo);
    if(nStatus==-1)
     {
      cout<<"\n****************"<<info.CommandName<<" Not Found**********\n";
      nStatus = l.findListLength(); 
      cout<<"\nTotal Traversal for "<<info.CommandName<<":"<<nStatus<<"\n";
      NoOfEntries--;
      continue;
     }
    cout<<"\nTotal Traversal for "<<info.CommandName<<":"<<nStatus<<"\n";
    nStatus=l.deleteMid(nStatus);
    if(nStatus==EMPTY)
     {
      cout<<"*********List Empty*********\n";
      break;
     }
    else if(nStatus==ERROR)
     {
       cout<<"Deletion in the middle could not be performed\n";
       break;
     }
    }
   else
    cout<<"\n******************End Of File****************\n";
   NoOfEntries--;
  }
  cout<<"\n*************Deletion Succesfull************\n";
  l.display(dispInfo);
  fclose(fp);
}



