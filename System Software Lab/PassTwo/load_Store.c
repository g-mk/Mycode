 void storeSymbolTable(ht hash)
 {
    FILE *symTab;
    int i;
    symTab = fopen("SymbolTable.txt","wb");
	for(i=0;i<26;i++)
	{
		List Current = hash -> lists[i]->next;
		if(Current != NULL)
        {
            while(Current!=NULL)
            {
				fwrite(Current,1,sizeof(struct Symbol*),symTab);
				Current = Current -> next;
			}
		}
	}
	printf("stored\n");

    fclose(symTab);

 }

 ht loadSymbolTable()
 {
    ht hash;
    FILE *symTab;
	List Current;
    symTab = fopen("SymbolTable.txt","rb");
	while(!feof(symTab))
	{
		fread(Current,1,sizeof(struct Symbol),symTab);
		insertSymbol(Current ->m_sName,Current->m_sSegName,Current->m_sType,Current->m_nAddress,Current->m_nLength,hash);
	}
     fclose(symTab);
     return hash;

 }

 
 
 
 
 
 void storeSymbolTable(ht hash)
 {
     FILE *symTab;
     symTab = fopen("SymbolTable.txt","wb");
     fwrite(hash,1,sizeof(struct Hashtable),symTab);
     fclose(symTab);

 }

 ht loadSymbolTable()
 {
     printf("Hi");
     ht hash;
     FILE *symTab;
     printf("\nHi1\n");
     symTab = fopen("../PassOne/SymbolTable.txt","rb");
     printf("\nHi2 %d\n",symTab);
     fread(hash,1,sizeof(struct Hashtable),symTab);
     printf("%d\n",hash);
     fclose(symTab);
     printf("Return\n");
     return hash;

 }
 
 
 
 
 
 
 Token SeperateTokens(char *line)
{
 Token pa;
 int i,j;
 i=0;
 j=0;
 if(line[i]!=' ')
 {
  for(;line[i]!=' ';i++)
  {
   pa.label[j]=line[i];
   j++;
  }
   pa.label[j]='\0';
 }
 else
  strcpy(pa.label,"");
 i++;
 for(j=0;line[i]!=' '&&line[i]!='\0';i++)
 {
  pa.opcode[j]=line[i];
  j++;
 }
 pa.opcode[j]='\0';
 if(line[i]!='\0')
 {
  i++;
  for(j=0;line[i]!=','&&line[i]!='\0';i++)
  {
   pa.operand1[j]=line[i];
   j++;
  }
  pa.operand1[j]='\0';
 }
 else
  strcpy(pa.operand1,"");
 if(line[i]==',' && line[i]!='\0')
 {
  i++;
  for(j=0;line[i]!='\0';i++)
  {
   pa.operand2[j]=line[i];
   j++;
  }
  pa.operand2[j]='\0';
 }
 else
  strcpy(pa.operand2,"");
 return pa;
}
