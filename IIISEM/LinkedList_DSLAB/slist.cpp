
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

	if(NULL == pHeadNode) {cout<<"Error in memory allocation";exit(-1);}

	pTailNode = new Node;

	if(NULL == pTailNode) {cout<<"Error in memory allocation";exit(-1);}

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


