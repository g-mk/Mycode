
/**********************************************************************************************
Author(s) :			N.Guru Manikandan
Purpose :			The data and function declarations for working with List ADT

***********************************************************************************************/

#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1
#define MEMERROR -2
#define EMPTY -3
#define FOUND 1
#define NOTFOUND 2
#define teste {cout<<"Test and exit\n";exit(-1);}


typedef struct Info
{
    char CommandName[20];
    char CommandSyntax[25];
    char CommandDetails[25];
    char CommandType[15];
}Info;

typedef struct RetInfo
{
	int status;
	Info info;
}RetInfo;

class Node
{
 public:
	Info info;
	Node *pNext;						// pointer  to the next node

};

class LList
{

public:
	LList();

	~LList();

	int insertBeg(Info info);				// Add a node at the beginning of the List

	int insertMid(Info info, int nPos);		// Add a Node at the Middle of the List

	int insertEnd(Info info);				// Add a Node at the end of the List

	int insertCurrentPos(Info info);		// Insert at the current-position
  
  int deleteNode(Info info,int (*fpointer)(Info,Info));  // Delete the Node with given key

	int deleteBeg();						// Delete the Node at the Beginning

	int deleteMid(int nPos);				// Delete the Node at the Middle

	int deleteEnd();						// Delete the Node at the End

	int display(void (*p)(Info));							// Display the List

	int isEmpty();							// Check Whether the List is Empty

	int makeListEmpty();					// Empty the List

	int findListLength();					// Length of the List

	int moveToFirst();						// Move the CurrentPos Pointer to First-Node in the List

	int moveToEnd();						// Move the CurrentPos Pointer to Last-Node in the List

	int moveToNext();						// Move the CurrentPos Pointer to Next-Node in the List [ If Possible ]

	int moveToN(int nPos);					// Move the CurrentPos Pointer to N th-Node in the List

	int locate(Info, int (*fp)(Info,Info));	// Locate an Element in the List

	RetInfo retrieve();						// Retrieve the Element in the Current-Position

	RetInfo retrieveAndDelCurrentPos();		// Retrieve and Delete the Element in the Current-Position
  int getPos();          //  Getting Position of middle element

	RetInfo getFirst();						// Get the First-Element

	RetInfo getLast();						// Get the Last-Element

//	int reverse();							// Reverse of the List

	int orderInAscending(int (*f)(Info,Info));					// Ascending-Order of the List

	private:
		Node *pHeadNode;						// Pointer to Head-Node

		Node *pTailNode;						// Pointer to Tail-Node

		Node *pCurrentPos;						// Pointer to Current-Position

		int length;	   							//	Length of the List
};


