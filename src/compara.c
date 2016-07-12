/* Uso típico: if (strcmp (x, y) == 0) ... ;
// Compara lexicograficamente as strings x e y. Devolve
// um número estritamente negativo se x vem antes de y,
// devolve 0 se x é igual a y e devolve um número
// estritamente positivo se x vem depois de y. O código
// da função equivale a                 
//       for (i = 0; x[i] == y[i]; ++i)                       
//          if (x[i] == 0) return 0;                          
//       return x[i] - y[i];                                  
// que por sua vez equivale a                                 
//       while (*x++ == *y++)                                 
//          if (*(x-1) == 0) return 0;                        
//       return *(x-1) - *(y-1);                              
*/
/*int strcmp (char *x, char *y);*/

#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	char *var1,*var2;
	var1=argv[1];
	var2=argv[2];
	int i,j;
	int t1=strlen(var1);
	int t2=strlen(var2);
	printf("t1=%d t2=%d\n",t1,t2);

	if( strcmp(var1,var2) == 0 )
		printf("ok\n");
	else printf("nao ok\n");

	i=0;
	for( j=0 ; j<t2 ;j++ )
	{
		if( var2[j]==var1[i] )
			i++; /*incrementa o primeiro*/
			else
				i=0;
	}


	return 0;
}