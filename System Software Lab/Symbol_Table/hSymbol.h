#include<stdio.h>
#include<string.h>
typedef struct Symbol
{
    char m_sName[25];
    char m_sSegName[25];
    char m_sType[5];
    unsigned int m_nAddress,m_nLength;
    struct Symbol* next;
}Symbol;
typedef Symbol* List;
struct Hashtable
{
    List* lists;
};
typedef struct Hashtable* ht;

List searchSymbol(char*,char*,ht);
int insertSymbol(char*,char*,char*,unsigned int,unsigned int,ht);
void displaySymbol(ht);
int modifySymbol(Symbol,int,ht);
int hashFunction(int);
ht initialize();
void storeSymbolTable(ht);
