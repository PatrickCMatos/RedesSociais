#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "redesocial.h"
#include "redesocial.c"


int main()
{
    setlocale(LC_ALL, "Portuguese");
    TRedeSocial rede;
    TUsuarios user;
    Iniciar(&rede);
    char nome[100];
    int opcao=0;
    int indice;
    while(opcao !=6)
    {
        printf("\nMENU:\n");
        printf(" 1 Para se cadastrar\n");
        printf(" 2 Para pesquisar\n");
        printf(" 3 Para fazer alteracoes\n");
        printf(" 4 Para excluir o cadastro\n");
        printf(" 5 Para imprimir\n");
        printf(" 6 Para sair\n");
        printf("\n \nDigite o numero da operação que deseja realizar: \n");
        fflush(stdin);
        scanf("%d", &opcao);
        if(opcao==1)
        {
            Ler(&user);
            Cadastrar(&rede, user);
        }
        if(opcao==2)
        {
            printf("Digite o nome a ser pesquisado:\n");
            fflush(stdin);
            fgets(nome,99,stdin);
            indice=Pesquisar(rede,nome);
            if(indice!=-1)
            {
                Imprimir(user);
            }
        }
        if(opcao==3)
        {
            printf("Digite o nome para ser alterado:\n");
            fflush(stdin);
            fgets(nome,99,stdin);
            indice=Pesquisar(rede,nome);
            Ler(&user);
            Alterar(user,indice,&rede);

        }

        if(opcao==4)
        {
            printf("Digite o seu nome para excluir o cadastro:\n");
            fflush(stdin);
            fgets(nome,99,stdin);
            indice=Pesquisar(rede,nome);
            Excluir(indice,&rede);

        }
        if(opcao==5)
        {
            printf("Lista de usuarios:\n");
            Imprimir2(rede);

        }
        if(opcao==6)
        {
            printf("Fim do programa!");
        }
        system("pause");
        system("cls");

    }

    return 0;
}
