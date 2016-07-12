#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i,dif[10],tam;
	
	char *palavra="welcome";
	
	for( i=0; i<strlen(palavra) ; i++ )
	{
		printf("%c:%2X %c:%2X ",palavra[i],palavra[i],palavra[i+1],palavra[i+1]);
		dif[i]=palavra[i+1]-palavra[i];
		printf("i:%d dif:%d\n",i,dif[i]);
	}

	return 0;
}