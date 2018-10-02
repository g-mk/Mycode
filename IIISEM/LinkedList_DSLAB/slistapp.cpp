
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

Info getInfo()
{
	Info info;
	cout<<"\n\n\tEnter the Info. Value \n";
	cin>>info.val;
	return(info);
}

void dispInfo(Info info)
{
	cout<<" "<<info.val;
}

int compareInfo(Info info1,Info info2)
{
	if(info1.val<info2.val)
		return 1;
	else
		return 0;
}




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
	int ch=0,chi=0,chd=0,ret;
	Info info;
	RetInfo rInfo;
	int chm=0;
	int flag;
	int nPos=0;



	LList l;


	while(1)
	{
		cout<<"\n\n\tLIST-ADT Implementation\n";
		cout<<"\t=========================\n";
		cout<<"\n\t1. Insertion";
		cout<<"\n\t2. Delete";
		cout<<"\n\t3. Display";
		cout<<"\n\t4. Move-To";
		cout<<"\n\t5. Search for term with specific val";
		cout<<"\n\t6. Check-If-Empty-List";
		cout<<"\n\t7. Order the list of items in ascending order";
		cout<<"\n\t8. Exit";

		cout<<"\n\nEnter Ur Choice..";
		cin>>ch;

		switch(ch)
		{
			case 1:									// List-Insertion
				cout<<"\n\n LIST-INSERTION\n";
				cout<<"=================\n";
				cout<<"\n\t1. Insertion at the Beginning";
				cout<<"\n\t2. Insertion at the Middle";
				cout<<"\n\t3. Insertion at the Last-Position";
				cout<<"\n\t4. Insertion at the Current-Position";
				cout<<"\n\nEnter Ur Choice..";
				cin>>chi;
				switch(chi)
				{
					case 1:
						info=getInfo();
						ret=l.insertBeg(info);			// Calls Insert at the Beginning Function
						if(ret==OK)
							cout<<"Node inserted at the beginning"<<endl;
						else if(ret==MEMERROR)
						{
							cout<<"Error in memory allocation"; exit(ERROR);
						}
						break;
					case 2:
						nPos = getPos();
						info=getInfo();
						ret=l.insertMid(info,nPos);		// Calls Insert at the Middle Function
						if (ret==OK)
							cout<<"Node is inserted in the middle "<<nPos<<" position"<<endl;

						else  if(ret==ERROR)
							cout<<"Insertion could not be performed. The list may have very lesser no. of nodes"<<endl;

						else if(ret==MEMERROR)
						{
							cout<<"Error in memory allocation";exit(ERROR);
						}
						else if(ret==EMPTY)
							cout<<"Insertion at the Middle "<<nPos<<" position is not Possible .The List may be Empty"<<endl;
						break;
					case 3:
						info=getInfo();
						ret=l.insertEnd(info);			// Calls Insert at the End Function
						if(ret==OK)
							cout<<"Node inserted at the end\n";
						else if(ret==MEMERROR)
						{
							cout<<"Error in memory allocation";exit(ERROR);
						}
						break;
					case 4:
						info=getInfo();
						ret=l.insertCurrentPos(info);		// Calls Insert at the Current-Position
						if (ret==OK)
							cout<<"Node is inserted in the current position"<<endl;

						else  if(ret==ERROR)
							cout<<"Insertion could not be performed. The current position is null"<<endl;

						else if(ret==MEMERROR)
						{
							cout<<"Error in memory allocation";exit(ERROR);
						}
						else if(ret==EMPTY)
							cout<<"Insertion at the current position is not Possible .The List may be Empty"<<endl;
						break;
				}
				break;
			case 2:									// List-Deletion
				cout<<"\n\n LIST-DELETION\n";
				cout<<"=================\n";
				cout<<"\n\t1. Deletion at the Beginning";
				cout<<"\n\t2. Deletion at the Middle";
				cout<<"\n\t3. Deletion at the End";
				cout<<"\n\t4. Delete the Entire-List";
				cout<<"\n\nEnter Your Choice.. ";
				cin>>chd;
				switch(chd)
				{
					case 1:
						ret=l.deleteBeg();
						if(ret==OK)
							cout<<"Deletion Successful";
						else if(ret==EMPTY)
							cout<<"Deletion could not be done. The List may be empty\n";
						break;
					case 2:
						nPos = getPos();		// Returns an Integer Value
						ret=l.deleteMid(nPos);		// Calls Delete at the Middle Function
						if(ret==ERROR)
							cout<<"Deletion in the middle could not be performed. The List may have lesser no. of nodes\n";
						else if(ret==EMPTY)
							cout<<"Deletion in the mid of the list could not be done. The List may be empty\n";
						else if(ret==OK)
							cout<<"Deletion Successful";

						break;
					case 3:
						ret=l.deleteEnd();			// Call Delete at the End Function
						if(ret==EMPTY)
							cout<<"Deletion at the end position could not be done. The List may be empty\n";
						else if(ret==OK)
							cout<<"Deletion Successful";
						break;
					case 4:
						ret=l.makeListEmpty();		// Makes the List Empty
						if(ret==OK)
							cout<<"The List is emptied";
						else
							cout<<"The List is already empty";
						break;
				}
				break;
			case 3:								// List-Information-Display
				cout<<"\n\n LIST-DISPLAY\n";
				cout<<"=================\n";
				cout<<"\n\t1. Display the List";
				cout<<"\n\t2. Display the Length";
				cout<<"\n\t3. Retrieve Current";
				cout<<"\n\t4. Get-First";
				cout<<"\n\t5. Get-Last";
				cout<<"\n\t6. Display the Reverse of the List";
				cout<<"\n\nEnter Your Choice...";
				cin>>chd;
				switch(chd)
				{
					case 1:
						ret=l.display(dispInfo);		// Calls the Display List Function
						if(ret==EMPTY)
							cout<<"The List may be empty\n";
						else
							cout<<"\nNo. of Elements in the List is: "<<ret<<endl;
						break;
					case 2:
						cout<<"\n\n\tLength of the List : "<<l.findListLength();
						break;
					case 3:
						cout<<"\n\n\tElement at Current-Position\n";
						rInfo = l.retrieve();
						if(rInfo.status==OK)
							cout<<"\n\n\tElement at Current: "<<rInfo.info.val;
						else
							cout<<"Error in getting the  element in the current position of the list\n";
						break;
					case 4:
						rInfo=l.getFirst();
						if(rInfo.status==OK)
							cout<<"\n\n\tElement at First:  " << rInfo.info.val;
						else
							cout<<"Error in getting the first element in the list\n";
						break;
					case 5:
						rInfo=l.getLast();
						if(rInfo.status==OK)
							cout<<"\n\n\tElement at Last: "<<rInfo.info.val;
						else
							cout<<"Error in getting the last element in the list\n";
						break;
					case 6:
						cout<<"\n\n\tReverse of the List";
						ret=l.reverse();
						if(ret==OK)
							cout<<"List reversed";
						else
							cout<<"Could not reverse the List. The List may be empty\n";
						break;
				}
				break;
			case 4:								// Move-To Functions
				cout<<"\n\n Move-To-Functions\n";
				cout<<"======================\n";
				cout<<"\n\t1. Move to First-Position";
				cout<<"\n\t2. Move to End-Position";
				cout<<"\n\t3. Move to Next-Position";
				cout<<"\n\t4. Move to Nth position";
				cout<<"\n\nEnter Ur Choice..";
				cin>>chm;
				switch(chm)
				{
					case 1:
						ret=l.moveToFirst();			// Move to First Position
						if(ret==OK)
							cout<<"Moved to first position in the List\n";
						else if(ret==EMPTY)
							cout<<"Could not move to first position. The List may be empty\n";
						break;
					case 2:
						ret=l.moveToEnd();			// Move to End Position
						if(ret==OK)
							cout<<"Moved to last position in the List\n";
						else if(ret==EMPTY)
							cout<<"Could not move to the last position. The List may be empty\n";
						break;
					case 3:
						ret=l.moveToNext();			// Move to Next Position
						if(ret==OK)
							cout<<"Moved to next position in the List\n";
						else if(ret==ERROR)
							cout<<"\nCurrent pointer is NULL and is not pointing to any node in the List\n";
						else if(ret==-4)
							cout<<"Could not move to next node. Current pointer may be at the last position\n";
						else if(ret==EMPTY)
							cout<<"Could not Move to Next-Position. The List may be empty\n";
						break;
					case 4:
						nPos = getPos();		// Returns an Integer Value
						ret=l.moveToN(nPos);			// Move to Nth Position
						if(ret==OK)
							cout<<"Moved to "<<nPos<<" position in the List\n";
						else if(ret==ERROR)
							cout<<"Could not Move to Position: "<<nPos<<". The List may have lesser no. of nodes\n";
						else if(ret==EMPTY)
							cout<<"Could not Move to Position: "<<nPos<<". The List may be Empty\n";
						break;
				}
				break;
			case 5:								// Searching for Element
				info = getInfo();				// Gets the Node value
				ret=l.locate(info, compareInfo);		// Search for Element in the List with this Info
				if(ret==NOTFOUND)
					cout<<"Element is not found in the List\n";
				else if(ret==EMPTY)
					cout<<"Could not Search for Element.  The List may be Empty\n";
				else
					cout<<"Element is Found in the position:"<<ret<<"\n";
				break;
			case 6:								// Check List Empty
				flag=FALSE;
				flag = l.isEmpty();				// Checking List is Empty
				if(flag == TRUE)
					cout<<"\n\tList is Empty\n\n";
				else
					cout<<"\n\tList is Not Empty\n\n";
				break;
			case 7:								// Differentiate the List
				ret=l.orderInAscending(compareInfo);
				if(ret==OK)
					cout<<"The List is sorted in ascending order";
				else
					cout<<"The List may be empty";
				break;
			case 8:	// Exit
				exit(0);	// Exit from the Main()
				break;
			default:
				cout<<"\n\nEnter Your Choice between 1 & 8\n\n";
		}
	}

}



