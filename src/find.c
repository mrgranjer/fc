/*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMFRASE 20

unsigned char hex_palavra[15];  /*Palavra a ser buscada*/
int dif_caractere[15];          /*Diferenca entre um caract e outro*/
int offset = 0;                 /*Incicio do offset*/
int tamanho;                    /*Tamanho palavra*/
//unsigned char tbl[257];         /*Vetor de tabela TBL*/
int cont = 0;/*Contador*/

//Le o arquivo
void read_file(char *arquivo, char *palavra);
//Calcula a diferenca entre letras
void calcula_diferenca(char *palavra);
//Busca string e retorna offset e hexadecimais
void busca_diferenca(unsigned char hex_atual, unsigned char hex_ant, char *palavra, int pos);
//Busca as diferencas das letras
void busca_offset(char *arquivo, char *palavra);

/****************** Main **************************/
int main(int argc, char *argv[])
{
  if(argc != 3)
  {
    printf("Use: %s <palavra> <rom>\n",argv[0]);
    exit(0);
  }

  calcula_diferenca(argv[1]);
  busca_offset(argv[2], argv[1]);
  
  return 0;
}

/*Calcula a diferenca entre letras*/
void calcula_diferenca(char *palavra)
{
  int i;
  tamanho = strlen(palavra);
  
  //Calcula a diferenca de um carac para outro
  for(i = 0; i < tamanho; i++)
  {
    printf("palavra[i]:%2X palavra[i+1]:%2X\n",palavra[i],palavra[i+1]);
    dif_caractere[i] = palavra[i] - palavra[i+1];
    printf("i:%d %d %c %c\n",i,dif_caractere[i],palavra[i],palavra[i+1]);
    if(dif_caractere[i] < 0)
      dif_caractere[i] = -dif_caractere[i];//Se negativo
  }
    for(; i < 15; i++)//Preenche o restante
      dif_caractere[i] = 0;// ou -1, mudei
}


//Busca a palavra
void busca_offset(char *arquivo, char *palavra)
{
  FILE *file_in;
  unsigned char hex_atual;
  unsigned char hex_ant = '\0';//Defini fim da string
  int i = 0;
    
  file_in = fopen(arquivo, "rb");
  if(!file_in)
  {
    printf("\n[ERRO] Nao foi possivel abrir o arquivo\n\n");
    exit(0);
  }
    
  while(fscanf(file_in, "%c", &hex_atual) != EOF)
  {
    i++;
    if(i > 1)
      //Faz a busca e imprimi o offset e os hexadecimais
      busca_diferenca(hex_atual, hex_ant, palavra, i);
    hex_ant = hex_atual;
  }
  fclose(file_in);
}
//Retorna a diferenca entre as letras e o offset
void busca_diferenca(unsigned char hex_atual, unsigned char hex_ant, char *palavra, int pos)
{
  //int cont = 0;/*Contador*/
  int diferenca_hex, i;
  
  diferenca_hex = hex_atual - hex_ant;
  if(diferenca_hex < 0)
    diferenca_hex = -diferenca_hex;
  
  if(diferenca_hex == dif_caractere[cont])
  {
    if(!offset)
      offset = pos;
    hex_palavra[cont] = hex_ant;
    cont++;
    if(cont == tamanho-1)
    {
      hex_palavra[cont] = hex_atual;
      hex_palavra[cont+1] = '\0';
      /*Imprimi Offset*/
      printf("%06X: ", offset);
      for(i = 0; hex_palavra[i] != '\0'; i++)
        printf("%02X ", hex_palavra[i]);
      offset = 0;
      cont = 0;
      printf("\n");
    }
  }
  else
  {
    offset = 0;
    cont = 0;
  }
}