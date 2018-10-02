#include"slist.h"
RetInfo LList :: retrieve()
{
	RetInfo rinfo;
	//Node *pCurrent = pHeadNode->pNext;
	if (!pCurrentPos)
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
{ cout<<"Asensding\n";
	Node *pCurrent = pHeadNode;
	for (int i = 0; i < length; i++)
	{ cout << "for "<<i<<endl;
		while (pCurrent->pNext->pNext != NULL)
		{ cout<<"while \n";
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
	while (pCurrent != NULL)
	{
		if ((*fp)(info1, pCurrent->info))
			return FOUND;
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

int LList::reverse()
{
	int b = 1, i;
	Node *Temp;
  Node *Newnode;
	if (isEmpty())
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
}

int LList::moveToN(int a)
{
	int i = 1;
	pCurrentPos = pHeadNode;
	while (pCurrentPos->pNext != NULL && i < length - a)
	{
		pCurrentPos = pCurrentPos->pNext;
		i++;
	}
	return OK;
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
    length --;
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
    pCurrentPos->pNext =pTailNode;
  }
}

int LList::makeListEmpty()
{
  Node* pCurrent=pHeadNode;
  while(pCurrent!=pTailNode)
  {
    Node * temp;
    temp = pCurrent;
    pCurrent = pCurrent -> pNext;
    delete temp;
   }
   length =0;
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
   length--;
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
   length--;
  }
}
}

int LList::isEmpty( )
{
 if(pHeadNode->pNext==pTailNode)
  return TRUE;
 else
  return FALSE;
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
    pCurrentPos=pCurrentPos->pNext;
    i++;
  }
 if(i==pos)
 {
   Node* temp=pCurrentPos->pNext;
   pCurrentPos->pNext=pCurrentPos->pNext->pNext;
   length--;
   return OK;
 }
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
    length++;
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
      length++;
      return OK;
     }
   }
    // return ERROR;
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
    while(ptempNode->pNext!=NULL)
    {
      //cout<<ptempNode->info;
      (*p)(ptempNode->info);
      ptempNode=ptempNode->pNext;
    }
    return length;
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
    newnode->pNext=pTailNode;
    length++;
    return OK;
  }
  else
  {
    Node *newnode=new Node;
    Node*Current = pHeadNode->pNext;
    newnode->info=info;
    newnode->pNext=NULL;
    while(Current->pNext != pTailNode)
     {
       Current = Current -> pNext;
     }
    Current->pNext=newnode;
    newnode -> pNext = pTailNode;;
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

