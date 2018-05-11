#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 50

typedef struct cadastro{
        char titulo[SIZE];
        char autor [SIZE];
}CADASTRO;

void menu()
{
    printf("1 - Cadastro\n");
    printf("2 - Exclusao\n");
    printf("3 - Atualizacao\n");
    printf("4 - Busca por titulo\n");
    printf("5 - Busca por autor\n");

}
void cadastrar(){
    char *caminho = "trabalho.txt";
    CADASTRO ficha;
    char op;
    FILE *arquivo = fopen(caminho, "ab");
    if(arquivo != NULL){
        do{
            fflush(stdin);
            printf("Titulo do livro: ");
            fgets(ficha.titulo, SIZE, stdin);
            fflush(stdin);
            printf("Autor do livro: ");
            fgets(ficha.autor, SIZE, stdin);
            fwrite(&ficha, sizeof(CADASTRO), 1, arquivo);
            printf("Deseja continuar?: ");
            scanf("%c", &op);
            op = tolower(op);
        }while(op != 'n');
    }
    else{
        fprintf(stderr, "Nao foi possivil abrir o arquivo");
    }
    fclose(arquivo);
}

void listar(){
    char *caminho = "trabalho.txt";
    CADASTRO ficha;
    FILE *arquivo = fopen(caminho, "rb");
    if(arquivo != NULL){
        while(fread(&ficha, sizeof(CADASTRO), 1, arquivo)){
            printf("Titulo: %s", ficha.titulo);
            printf("Autor: %s", ficha.autor);
            printf("\n");
        }
    } else{
        fprintf(stderr, "Nao foi possivil abrir o arquivo");
    }
    fclose(arquivo);
}
void buscaAutor(){
    char *caminho = "trabalho.txt";
    CADASTRO ficha;
    FILE *arquivo = fopen(caminho, "rb");
    char nome[SIZE];
    if(arquivo != NULL){
        fflush(stdin);
        printf("Digite o nome do autor: ");
        fgets(nome, SIZE, stdin);
        while(fread(&ficha, sizeof(CADASTRO), 1, arquivo)){
            if(strcmp(nome, ficha.autor) == 0){
                printf("Titulo: %s", ficha.titulo);
                printf("Autor: %s", ficha.autor);
                printf("\n");
            }
        }
    } else{
        fprintf(stderr, "Nao foi possivil abrir o arquivo");
    }
    fclose(arquivo);
}
void buscaTitulo(){
    char *caminho = "trabalho.txt";
    CADASTRO ficha;
    FILE *arquivo = fopen(caminho, "rb");
    char nome[SIZE];
    if(arquivo != NULL){
        fflush(stdin);
        printf("Digite o nome do titulo: ");
        fgets(nome, SIZE, stdin);
        while(fread(&ficha, sizeof(CADASTRO), 1, arquivo)){
            if(strcmp(nome, ficha.titulo) == 0){
                printf("Titulo: %s", ficha.titulo);
                printf("Autor: %s", ficha.autor);
                printf("\n");
            }
        }
    } else{
        fprintf(stderr, "Nao foi possivil abrir o arquivo");
    }
    fclose(arquivo);
}
void atualizar(){
    char *caminho = "trabalho.txt";
    CADASTRO ficha;
    FILE *arquivo = fopen(caminho, "rb+");
    int cont = 0, n;

    if(arquivo != NULL){
        while(fread(&ficha, sizeof(CADASTRO), 1, arquivo)){
            cont ++;
        }
        printf("Digite o numero do Livro que pretende alterar os dados: ");
        scanf("%d", &n);

    if(n <= cont && n > 0){
            fread(&ficha, sizeof(CADASTRO), 1, arquivo);
      fflush(stdin);
      printf("Digite o nome do autor: ");
      fgets(ficha.autor, SIZE, stdin);
      fflush(stdin);
      printf("Digite o nome do titulo: ");
      fgets(ficha.titulo, SIZE, stdin);
      fseek(arquivo, (n - 1) * sizeof(CADASTRO), SEEK_SET);
      fwrite(&ficha, sizeof(CADASTRO), 1, arquivo);
    }
    else{
      puts("Livro nao foi atualizado");

  }
    }
  else{
    fprintf(stderr, "Nao foi possivel abrir o arquivo");
  }

  fclose(arquivo);

}
int main()
{
    menu();
    int op;

    do{
    printf("Digite a opcao: ");
    scanf("%d", &op);
    switch(op){
    case 1:
        cadastrar();
        break;
  /*  case 2:
        excluir();
        break;*/
    case 3:
        atualizar();
        break;
    case 4:
        buscaTitulo();
        break;
    case 5:
        buscaAutor();
        break;
    case 6:
        listar();
        break;
    case 7:
        break;
    default:
        printf("Opcao invalida");
    }
    }while(op != 7);

    return 0;
}
