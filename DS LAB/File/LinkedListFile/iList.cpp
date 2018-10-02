
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

	pHeadNode->pNext =NULL;

	pTailNode->pNext =NULL;

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

	/*Node *pTemp = pHeadNode;

	Node *pTemp1;

	while(pTailNode != pTemp)
	{
		pTemp1 = pTemp->pNext;

		delete pTemp;

		pTemp=pTemp1;
	}

	delete pTailNode;

	delete pHeadNode;*/
 while(pHeadNode->pNext!=NULL)
 {
   deleteBeg();
 }
}
int LList::isEmpty( )
{
 if(pHeadNode->pNext==NULL)
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
    while(pCurrentPos->pNext!=NULL)
    {
       pCurrentPos=pCurrentPos->pNext;
    }
    if(pCurrentPos->pNext==NULL)
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
   Node* temp=pCurrentPos->pNext;
   pCurrentPos->pNext=NULL;
   delete temp;
  }
 return OK;
 }
}
int LList :: deleteNode(Info info,int (*fpointer)(Info,Info) )
{
 int pos;
 pos=locate(info,fpointer);
 return pos;
 
}

int LList::deleteMid(int pos)
{
 if(isEmpty())
    return EMPTY;
 else
  pCurrentPos=pHeadNode;
  int i=1;
  while(pCurrentPos->pNext!=NULL)
  {

    if(i==pos)
    {
     Node* temp=pCurrentPos->pNext;
     pCurrentPos->pNext=pCurrentPos->pNext->pNext;
     delete temp;
     return OK;
    }
    pCurrentPos=pCurrentPos->pNext;
    i++;
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
       pCurrentPos=pHeadNode;
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
  Node* newnode=new Node;
   newnode->info=info;
   if(pCurrentPos==NULL)
    {
      return insertEnd(info);
    }
    newnode->pNext=pCurrentPos->pNext;
    pCurrentPos->pNext=newnode;
    return OK;
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
    newnode->pNext=NULL;
    pHeadNode->pNext=newnode;
    pTailNode=newnode;
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
     pCurrentPos=pHeadNode->pNext;
     int i=1;
     while(pCurrentPos->pNext!=NULL&&i<npos-1)
     {
       pCurrentPos=pCurrentPos->pNext;
       i++;
     }
     if(pCurrentPos->pNext||i==npos-1)
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
    while(ptempNode!=NULL)
    {
      (*p)(ptempNode->info);
      ptempNode=ptempNode->pNext;
    }
    return OK;
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
    pTailNode=newnode;
    newnode->pNext=NULL;
    length++;
    return OK;
  }
  else
  {
    Node* newnode=new Node;
    newnode->info=info;
    newnode->pNext=NULL;
    pCurrentPos =pHeadNode->pNext;
    while(pCurrentPos->pNext!=NULL)
    {
       pCurrentPos=pCurrentPos->pNext;
    }
    pTailNode=newnode;
    pCurrentPos->pNext=newnode;
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

  if (pCurrent!=NULL)

  {

    rinfo.info = pCurrentPos->info;

    rinfo.status = OK;

    return rinfo;

  }

  else

  {

    rinfo.status = ERROR;

    return rinfo;

  }

}

int LList :: orderInAscending(int(*fp)(Info, Info))

{

  Node *pCurrent = pHeadNode;

  for (int i = 0; i < length; i++)

  {

    while (pCurrent->pNext->pNext != NULL)

    {

      if (fp(pCurrent->pNext->info,pCurrent->pNext->pNext->info))

      {

        Node *temp;

        temp->pNext = pCurrent->pNext;

        pCurrent->pNext = pCurrent->pNext->pNext;

        temp->pNext->pNext = pCurrent->pNext->pNext;

        pCurrent->pNext->pNext = temp->pNext;

        delete temp;

        pCurrent = pCurrent->pNext;



      }

    }

  }

}
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
  int nCount=0;
  while (pCurrent != NULL)

  {  nCount=nCount+1;

    if ((*fp)(info1, pCurrent->info))

      return nCount;

    pCurrent = pCurrent->pNext;

  }
  return -1;

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

