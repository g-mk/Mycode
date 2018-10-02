
#include"slist.h"

/******************************************************
Constructor Name : LList

Prototype : LList();

Parameters Passed : None

Data Members Used : pHeadNode, pTailNode, pCurrentPos

Data Members Changed : pHeadNode, pTailNode, pCurrentPos

Calls : None

Called By : main()

*********************************************************/

LList::LList()
{

	length = 0;

	pHeadNode = new Node;

	if(NULL == pHeadNode) {cout<<"Error in memory allocation";}

	pTailNode = new Node;

	if(NULL == pTailNode) {cout<<"Error in memory allocation";}

	pHeadNode->pNext = pTailNode;

	pTailNode->pNext = NULL;

	pCurrentPos = NULL;		// Intializing the Current-Pointer to NULL

}


/**********************************************************************************************

Destructor Name : LList

Purpose : For freeing the Memory allocated dynamically

Prototype : ~LList();

Parameters Passed : None

Class Members Used : pHeadNode, pTailNode, pCurrentPos

Class Members Changed : pHeadNode, pTailNode, pCurrentPos

Calls : None

Called By : None

**********************************************************************************************/

LList::~LList()
{

	Node *pTemp = pHeadNode;

	Node *pTemp1;

	while(pTailNode != pTemp)
	{
		pTemp1 = pTemp->pNext;

		delete pTemp;

		pTemp=pTemp1;
	}

	delete pTailNode;

	delete pHeadNode;
}
int LList::isEmpty( )
{
 if(pHeadNode->pNext==pTailNode->pNext)
  return TRUE;
 else
  return FALSE;
}
int LList::deleteBeg()
{
  if(isEmpty())
    return EMPTY;
  else
  {
    Node* temp=pHeadNode->pNext;
    pHeadNode->pNext=pHeadNode->pNext->pNext;
    delete temp;
    return OK;
  }
}
int LList::moveToEnd()
{
  if(isEmpty())
  {
    return EMPTY;
  }
  else
  {
    pCurrentPos =pHeadNode->pNext;
    while(pCurrentPos->pNext!=pTailNode)
    {
       pCurrentPos=pCurrentPos->pNext;
    }
    if(pCurrentPos->pNext==pTailNode)
    {
      return OK;
    }

  }
}
int LList::makeListEmpty()
{
  Node* temp=pHeadNode->pNext;
  while(temp)
  {
    pHeadNode=temp->pNext;
    delete temp;
  }
  //delete pHeadNode;
 //delete pTailNode;
  return OK;
}
int LList:: moveToFirst()
{
  if(isEmpty())
  {
    return EMPTY;
  }
  else
  {
    pCurrentPos=pHeadNode->pNext;
    return OK;
  }
}
int LList::deleteEnd( )
{
 if(isEmpty())
  return EMPTY;
 else if(length==1)
  {
   pCurrentPos=pHeadNode;
   pHeadNode=NULL;
   delete pCurrentPos;
  }
 else
 {
  pCurrentPos=pHeadNode;
  while(pCurrentPos->pNext->pNext!=NULL)
  {
   pCurrentPos=pCurrentPos->pNext;
  }
  if(pCurrentPos->pNext)
  {
   Node *temp=pCurrentPos->pNext;
   pCurrentPos->pNext=NULL;
   delete temp;
  }
}
}
int LList::deleteMid(int pos)
{
 if(isEmpty())
    return EMPTY;
 else
  pCurrentPos=pHeadNode;
  int i=1;
  while(pCurrentPos->pNext!=NULL&&i<pos-1)
  {
    pCurrentPos=pCurrentPos->pNext;
    i++;
  }
 if(i==pos-1)
 {
   Node* temp=pCurrentPos->pNext;
   pCurrentPos->pNext=pCurrentPos->pNext->pNext;
   return OK;
 }
 else
 {

     return ERROR;
 }
}
int LList::moveToN(int pos)
{
 if(isEmpty())
 {
     return EMPTY;
 }
 else  if(pos>length)
 {
    return FALSE;
 }
 else
 {
       pCurrentPos=pHeadNode->pNext;
       int i=1;
while(i<=pos)
      {
           pCurrentPos=pCurrentPos->pNext;
           i++;
      }
 }
    return OK;
}
int LList::insertCurrentPos(Info info)
{
  Node *newnode=new Node;
  Node *ptemp=pHeadNode;
   newnode->info=info;
   //int i=1;
   /*while(ptemp!=NULL&&i<pCurrentPos)
   {
    ptemp=ptemp->pNext;
    i++;
    }*/
    newnode->pNext=pCurrentPos->pNext;
    pCurrentPos->pNext=newnode;
}
int LList::moveToNext()
{
 if(!isEmpty())
 {
  if(pCurrentPos->pNext!=NULL)
  {
    pCurrentPos=pCurrentPos->pNext;
  }
  else
  {
    return -1;//failure case (i.e)cannot point to next node in the list//
  }
 }
else
{
   return 0;//empty//
}
}
int LList::findListLength()
{
  if(isEmpty())
     {
       return EMPTY;
      }
  else
  {
   pCurrentPos=pHeadNode->pNext;
   int i=1;
   while(pCurrentPos->pNext!=NULL)
   {
     pCurrentPos=pCurrentPos->pNext;
     i++;
   }
  return i;
  }
}
int LList:: insertBeg(Info info)
{
  Node* newnode=new Node;
  newnode->info=info;
  if(isEmpty())
  {
    pHeadNode->pNext=newnode;
    newnode->pNext=NULL;
    pTailNode=pHeadNode->pNext;
    length++;
    return OK;
  }
  else
  {
    newnode->pNext=pHeadNode->pNext;
    pHeadNode->pNext=newnode;
    length++;
    return OK;
  }
  return MEMERROR;
}
int LList::insertMid(Info info,int npos)
{
  if(npos>0)
  {
   if(isEmpty())
   {
     return EMPTY;
   }
   else
   {
       if(npos==1)
        return insertBeg(info);
       else if (npos==length-1)
        return insertEnd(info);
       else
    {
     pCurrentPos=pHeadNode->pNext;
     int i=1;
     while(pCurrentPos->pNext!=NULL&&i<npos-1)
     {
       pCurrentPos=pCurrentPos->pNext;
       i++;
     }
     if(pCurrentPos->pNext)
     {
      Node *newnode=new Node;
      //if(newnode==NULL)
        //return MEMERROR;
      newnode->info=info;
      newnode->pNext=pCurrentPos->pNext;
      pCurrentPos->pNext=newnode;
      return OK;
     }
   }
    // return ERROR;
     }
  }
}
int LList::getPos()
{
  if(length==0||length==1)
  {
    return 1;
  }
 else
  {
    return ((length/2)+1);
  }
}
int LList:: display(void(*p)(Info))
{
  if(isEmpty())
  {
    return EMPTY;
  }
  else
  {
    Node* ptempNode;
    ptempNode=pHeadNode->pNext;
    int i=1;
    while(ptempNode -> pNext !=NULL )
    {
      //cout<<ptempNode->info;
      (*p)(ptempNode->info);
      ptempNode=ptempNode->pNext;
      i++;
    }
    return i-1;
  }
}
int LList:: insertEnd(Info info)
{
  if(isEmpty())
  {
    Node* newnode=new Node;
    if(newnode==NULL)
    {
      return MEMERROR;
    }
    newnode->info=info;
    pHeadNode->pNext=newnode;
    newnode->pNext=NULL;
    pTailNode = newnode;
    length++;
    return OK;
  }
  else
  {
    Node *newnode=new Node;
    newnode->info=info;
    newnode->pNext=NULL;
    pTailNode = newnode;
    length++;
    return OK;
}
  return ERROR;
}
RetInfo LList :: getLast()

{

 RetInfo r;

 if (!isEmpty())

 {

   r.info = pTailNode->info;

   r.status = OK;

   return r;

 }

 else

 {

   r.status = ERROR;

   return r;

 }

}


RetInfo LList :: retrieve()

{

  RetInfo rinfo;

  Node *pCurrent = pHeadNode->pNext;

  if (!pCurrent)

  {

    rinfo.info = pCurrent->info;

    rinfo.status = OK;

    return rinfo;

  }

  else

  {

    rinfo.status = ERROR;

    return rinfo;

  }

}

/*int LList :: orderInAscending(int(*fp)(Info, Info))

{
cout << "Asscndn order";
  Node *pCurrent;
  int nStatus;

  for (int i = 0; i < length; i++)

  {     pCurrent = pHeadNode;
      cout<<"loop "<<i<<endl;

    while (pCurrent->pNext->pNext != NULL)

    { cout<<"whie\n";

//       cout<<"Current value: "<<pCurrent ->pNext->info;
  //     cout<<"\nNext value: "<<pCurrent ->pNext->pNext->info<<endl;
       nStatus=fp(pCurrent->pNext->info,pCurrent->pNext->pNext->info);
       cout<<"Status: "<<nStatus;

      if (nStatus)

      { cout<<"if\n";

        Node *temp;
        cout<<"temp\n";

        temp = pCurrent->pNext;
cout<<"temp to current\n";
        pCurrent->pNext = pCurrent->pNext->pNext;
cout<<"current to next of next\n";
        temp->pNext = pCurrent->pNext->pNext;
cout<<"temp to new nxt\n";
        pCurrent->pNext->pNext = temp;
cout<< "new current to next\n";
        delete temp;
        cout<<"After delen";
int a;
cin>>a;

       }
     pCurrent = pCurrent ->pNext;
    }


  }

}*/
RetInfo LList :: retrieveAndDelCurrentPos()

{

  RetInfo rinfo;

  Node * pCurrent = pHeadNode->pNext;

  if (pCurrentPos)

  {

    int i = 1;

    while (pCurrent != pCurrentPos)

    {

      i++;

      pCurrent = pCurrent->pNext;

    }

    rinfo.info = pCurrent->info;

    rinfo.status = deleteMid(i);

    return rinfo;

  }
  else

  {

    rinfo.status = ERROR;

    return rinfo;

  }

}



int LList :: locate(Info info1, int(*fp)(Info, Info))

{

  Node *pCurrent = pHeadNode->pNext;
  int sivacount=0;
  while (pCurrent != NULL)

  {  sivacount=sivacount+1;

    if ((*fp)(info1, pCurrent->info))

      return sivacount;

    else

      pCurrent = pCurrent->pNext;

  }

  return NOTFOUND;

}
RetInfo LList::getFirst()

{

  RetInfo retinfo;

  if (!isEmpty())

  {

    retinfo.info = pHeadNode->pNext->info;

      retinfo.status = OK;

  }

  else

    retinfo.status = EMPTY;

  return retinfo;

}



/*int LList::reverse()

{

  int b = 1, i;

  Node *Temp;

  Node *Newnode;

  if (isEmpty()!=TRUE)

 {

    Newnode = pTailNode;

    for (i = 1; i<length - 2; i++)

    {

      if (b == 1)

       {

        int state=moveToN(i);

        if(state)

          Newnode->pNext = pCurrentPos;

        else

          return 0;

       }

      if(moveToN(i))

       {

        Newnode->pNext = pCurrentPos;

        Newnode = Newnode->pNext;

        b++;

       }
 else

        return 0;

    }

    Temp = pTailNode;

    pTailNode = pHeadNode;

    delete Temp;

    pHeadNode = Newnode;

    pTailNode->pNext = NULL;

    delete Newnode;

    return 1;

  }

  else

    return 0;

}*/



/*int LList::moveToN(int a)

{

  //Node*pCurrentPos;

  int i = 1;

  pCurrentPos = pHeadNode;

  while (pCurrentPos->pNext != NULL && i < length - a)
 {

    pCurrentPos = pCurrentPos->pNext;

    i++;

  }

  return OK;

}*/
