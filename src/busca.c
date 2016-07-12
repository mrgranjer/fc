/* feof example: byte counter */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  FILE * pFile;
  /* pFile = fopen ("myfile.txt","rb"); */
  pFile = fopen (argv[2],"rb");

  char *frase;

  if(argc != 3)
  {
    printf("\nUse: %s <palavra> <rom>\n\n",argv[0]);
    exit(0);
  }

  frase=argv[1];
  int i,len=strlen(frase);
  printf("frase: %s tamanho: %d\n",frase,len);
  for(i=0;i<len;i++){
  printf("%c:0x%02lx\n",frase[i],frase[i] & 0xFFl);
  }
  
  printf("\n");
  
  if (pFile==NULL) perror ("Error opening file");
  else
  {
    /* while (fgetc(pFile) != EOF) { */
    while(!feof(pFile)){
      printf( "0x%02lx", fgetc(pFile) & 0xFFl ); /**/

      /*
      //printf("%d %x %o %#x %#xo",fgetc(pFile),fgetc(pFile),fgetc(pFile),fgetc(pFile),fgetc(pFile));
      //printf( "0x%02lx,", c & 0xFFl );
      //printf(" 0x%02lx\n",pFile);
      //printf("%d\n", (int)strtol(fgetc(pFile),NULL,0) );
      //val = strtol(str, &endptr, base);
      //printf("%ld\n",val);
      //++n;
      */
      printf("\n");
    }
    /*
    if (feof(pFile)) {
      puts ("End-of-File reached.");
      printf ("Total number of bytes read: %d\n", n);
    }
    else puts ("End-of-File was not reached.");
    */
    printf("\n");
    fclose (pFile); /**/
  }
  return 0;
}