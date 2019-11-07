#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <string.h>

typedef struct{
  char isbn[14];
  char titulo[50];
  char autor[50];
  char editora[60];
  char ano[4];
  char paginas[5];
  char valor[10];
}Livro;

typedef struct{
  int codigo;
  char nomeAmigo[50];
  int telefone;
  char email[50];
}Amigo;

typedef struct{
  char isbn[14];
  int codigo;
  char data[10];
}Emprestimo;

void limpaBuf() {
  setbuf(stdin,NULL);
}

int lerNum (char string[1000]){
  int variavel;
  printf("%s", string);
  scanf("%i", &variavel);
  return variavel;
}

char lerChar(char string[1000]){
  limpaBuf();
  char variavel;
  printf("%s", string);
  scanf("%c", &variavel);
  return variavel;
}

int main(){
  setlocale(LC_ALL,"");
  char condicao = 'k';
  Emprestimo emprestimo;
  Livro livro;
  Amigo amigo;
  FILE *arquivoAmigo, *arquivoLivro, *arquivoEmprestimo;
  do {
    printf("(a) Adicionar livro\n");
    printf("(b) Adicionar Amigo\n");
    printf("(c) Procurar Livro\n");
    printf("(d) Listar Livro\n");
    printf("(e) Emprestar\n");
    printf("(f) Listar Emprestados\n");
    printf("(g) Devolver\n");
    printf("(h) Finalizar programa\n");
    condicao = lerChar("Op��o: ");
    limpaBuf();

    if (condicao=='a') {
      system("cls");
      arquivoLivro = fopen("dadosLivros","a");
      printf("-------------Livro-------------\n");
      printf("ISBN: ");
      gets(livro.isbn);
      limpaBuf();
      printf("Nome: ");
      gets(livro.titulo);
      limpaBuf();
      printf("Autor: ");
      gets(livro.autor);
      limpaBuf();
      printf("Editora: ");
      gets(livro.editora);
      limpaBuf();
      printf("Ano: ");
      gets(livro.ano);
      printf("Valor: ");
      gets(livro.valor);
      fwrite(&livro, sizeof(Livro),1,arquivoLivro);
      fclose(arquivoLivro);
    }//Ad livro

    else if (condicao =='b') {
      system("cls");
      arquivoAmigo = fopen("dadosAmigo","a");
      printf("-------------Amigo-------------\n");
      amigo.codigo = lerNum("C�digo: ");
      limpaBuf();
      printf("Nome: ");
      gets(amigo.nomeAmigo);
      limpaBuf();
      amigo.telefone = lerNum("N�mero: ");
      printf("Email: ");
      gets(amigo.email);
      fwrite(&amigo, sizeof(Livro),1,arquivoAmigo);
      fclose(arquivoAmigo);
    }//Ad Amigo

    else if (condicao =='c'){
      system("cls");
      arquivoLivro = fopen("dadosLivros","r");
      char pesquisa[60];
      printf("Campo de pesquisa: ");
      gets(pesquisa);
      limpaBuf();
      for (int i = 0; !feof(arquivoLivro); i++) {
        fread(&livro,sizeof(Livro),1,arquivoLivro);
        if (!feof(arquivoLivro)) {
          if (strcmp(pesquisa, livro.titulo)==0) {
            printf("-------------------------------\n");
            printf("\n%s(%s)\n  -%s, %s\nR$ %s\n", livro.titulo, livro.isbn, livro.ano, livro.autor, livro.valor);
            printf("-------------------------------\n");
          }
          else if(strcmp(pesquisa, livro.autor)==0){
            printf("-------------------------------\n");
            printf("\n%s(%s)\n  -%s, %s\nR$ %s\n", livro.titulo, livro.isbn, livro.ano, livro.autor, livro.valor);
            printf("-------------------------------\n");
          }
          else if(strcmp(pesquisa, livro.isbn)==0){
            printf("-------------------------------\n");
            printf("\n%s(%s)\n  -%s, %s\nR$ %s\n", livro.titulo, livro.isbn, livro.ano, livro.autor, livro.valor);
            printf("-------------------------------\n");
          }
          else if(strcmp(pesquisa, livro.valor)==0){
            printf("-------------------------------\n");
            printf("\n%s(%s)\n  -%s, %s\nR$ %s\n", livro.titulo, livro.isbn, livro.ano, livro.autor, livro.valor);
            printf("-------------------------------\n");
          }
          else if(strcmp(pesquisa, livro.ano)==0){
            printf("-------------------------------\n");
            printf("\n%s(%s)\n  -%s, %s\nR$ %s\n", livro.titulo, livro.isbn, livro.ano, livro.autor, livro.valor);
            printf("-------------------------------\n");
          }
        }

      }
      fclose(arquivoLivro);
      system("PAUSE");
    }//Procurar

    else if (condicao == 'd'){
      system("cls");
      arquivoLivro = fopen("dadosLivros","r");
      for (int i = 0; !feof(arquivoLivro); i++){
        fread(&livro,sizeof(Livro),1,arquivoLivro);
        if (!feof(arquivoLivro)) {
          printf("-------------------------------\n");
          printf("\n%s(%s)\n  -%s, %s\nR$ %s\n", livro.titulo, livro.isbn, livro.ano, livro.autor, livro.valor);
          printf("-------------------------------\n");
        }
      }
      fclose(arquivoLivro);
      system("PAUSE");
    }//Listar

    else if (condicao == 'e'){
      system("cls");
      arquivoLivro = fopen("dadosLivros","r");
      arquivoEmprestimo = fopen("dadosEmprestimo","a");
      if (arquivoEmprestimo!=NULL) {
        fclose(arquivoEmprestimo);
        arquivoEmprestimo = fopen("dadosEmprestimo","r");
        for (int i = 0; !feof(arquivoLivro); i++){
          fread(&livro,sizeof(Livro),1,arquivoLivro);
          for (int j = 0; !feof(arquivoEmprestimo); j++) {
            fread(&emprestimo,sizeof(Emprestimo),1,arquivoEmprestimo);
            if (!feof(arquivoLivro)&&livro.isbn!=emprestimo.isbn) {
              printf("-------------------------------\n");
              printf("Deu n nulo\n%s\nISBN = %s\n", livro.titulo, livro.isbn);
              printf("-------------------------------\n");
            }
          }
          fclose(arquivoEmprestimo);
        }
        fclose(arquivoLivro);
      }
      else{
        fclose(arquivoEmprestimo);
        while (!feof(arquivoLivro)) {
          if (!feof(arquivoLivro)) {
            printf("-------------------------------\n");
            printf("Nulo\n%s\nISBN = %s\n", livro.titulo, livro.isbn);
            printf("-------------------------------\n");
          }
        }
        fclose(arquivoLivro);
      }
      arquivoEmprestimo = fopen("dadosEmprestimo","a");
      printf("ISBN: ");
      gets(emprestimo.isbn);
      limpaBuf();
      emprestimo.codigo = lerNum("C�digo de Amigo: ");
      printf("Data: ");
      gets(emprestimo.data);
      limpaBuf();
      fwrite(&emprestimo, sizeof(Emprestimo),1,arquivoEmprestimo);
      fclose(arquivoEmprestimo);
      printf("Oi");
      system("PAUSE");

    }//Emprestar
    // system("cls");
  } while(condicao!='h');
  return 0;
}
