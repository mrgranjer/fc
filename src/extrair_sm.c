/*
*
* extrair Super Mario
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
  int coluna=0,linha=0,n=0;
  int vetor[524289]; //+1

  FILE * pFile;
  pFile = fopen (argv[1],"rb");

  if(argc != 2)
  {
    printf("\nUse: %s <rom>\n\n",argv[0]);
    exit(0);
  }

  if (pFile==NULL)
      perror ("Erro ao abrir o arquivo");
  else
  {
    while(!feof(pFile))
    {
      for(linha=0;linha<524289;linha++)
      vetor[linha]=fgetc(pFile);
    }
    int quebra=0;
    //pFile = fopen (argv[1],"rb");
    for( linha=0x2a5d9 ; linha<0x02a668 ; linha++ )
    {
      printf("%02X ",vetor[linha]);
      if(quebra==17)
      {
        quebra=0;
        printf("\n");
      }
        else
        {
          quebra++;
        }
        

    }
    
    
        //for(linha=0;linha<18;linha++)
        //printf("v:%02X ",vetor[linha]);


    //INICIO=0x2a5d9 - FIM=0x02a667
    /*while(fgetc(pFile) != EOF)
    {
       for( linha=173529 ; linha<173672 ; linha++ )
       {
          printf("offset %02X: ",coluna);
          for( coluna=0 ; coluna<18 ; coluna++ )
          {
           printf("%02X ", fgetc(pFile) );
           printf(" ");
          }
        printf("\n");
       }
    }*/

    printf("\n");

  }
  
  fclose (pFile); /**/

  return 0;
}