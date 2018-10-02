#include<stdio.h>
main()
{
	char c;
	int i;
	printf("Enter the Character:");
	scanf("%c",&c);
	i=c;
	if(((i>=65)&&(i<=90))||((i>=97)&&(i<=122)))
	{	
		printf("The Given Character %c ia an Alphabet......",c);
		switch(c)
		{
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':printf ("\nThe Given Character %c is a Vowel......\n\n",c);
							break;
			default: printf("\nThe Given Character %c is not a Vowel....\n\n",c);
		}
	}
	else
	{
		printf("\nThe Given Character %c is Not an Alphabet.....\n\n",c);
	}
}
