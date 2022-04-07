# include <stdlib.h>
# include <stdio.h>
# include "redesocial.h"


void Iniciar(TRedeSocial *rede)
{
    int i,j;
    rede->indice = 0;
    for(i=0; i<100; i++)
    {
        for(j=0; j<100; j++)
        {
            rede->matriz[i][j] = 0;
        }
    }
}

void Cadastrar(TRedeSocial *rede, TUsuarios user)
{
    user.ID = rede->indice;
    rede->vetor[rede->indice] = user;
    rede->indice++;
}

void Imprimir2(TRedeSocial rede)
{
    int i;
    for(i=0; i<rede.indice; i++)
    {
        Imprimir(rede.vetor[i]);
    }
}

void Imprimir(TUsuarios user)
{
    printf("\nEXIBIR\n");
    printf("Nome do usuario: %s \n", user.nome);
    printf("Email do usuario: %s \n", user.email);
    printf("Login do usuario: %s \n", user.login);
    printf("Senha do usuario: %s \n", user.senha );
    printf("Data de nascimento do usuario: %d / %d / %d \n", user.data_de_nascimento.dia,user.data_de_nascimento.mes,user.data_de_nascimento.ano);
    printf("ID do usuario: %d \n", user.ID);

}

int Pesquisar(TRedeSocial rede, char pesquisado[100])
{
    int i;
    for(i=0; i<rede.indice; i++)
    {
        if(strcmp(pesquisado,rede.vetor[i].nome)==0) //retorna 0 se forem iguais
        {
            return(i);
        }
    }
    printf("\n!!!Usuario nao encontrado!!!\n");
    return (-1);
}

void Ler(TUsuarios *user)
{
    printf("Digite o nome do usuario:");
    fflush(stdin);
    fgets(user->nome,99,stdin);

    printf("Digite o email:");
    fflush(stdin);
    fgets(user->email,199,stdin);

    printf("Digite o login:");
    fflush(stdin);
    fgets(user->login,49,stdin);

    printf("Digite a senha:");
    fflush(stdin);
    fgets(user->senha,49,stdin);

    printf("Digite a data de nascimento:\n");
    printf("\tDIA:");
    fflush(stdin);
    scanf("%i",& user->data_de_nascimento.dia);
    printf("\tMES:");
    fflush(stdin);
    scanf("%i",& user->data_de_nascimento.mes);
    printf("\tANO:");
    fflush(stdin);
    scanf("%i",& user->data_de_nascimento.ano);
}

void Excluir (int indic, TRedeSocial *rede )
{
    int i;
    rede->vetor[indic].nome[0] = '\0';
    rede->vetor[indic].email[0] = '\0';
    rede->vetor[indic].login[0] = '\0';
    rede->vetor[indic].senha[0] = '\0';
    rede->vetor[indic].data_de_nascimento.dia = 0;
    rede->vetor[indic].data_de_nascimento.mes = 0;
    rede->vetor[indic].data_de_nascimento.ano = 0;
    rede->vetor[indic].ID = -1;
    for(i=0; i<100; i++)
    {
        rede->matriz[i][indic] = 0;
        rede->matriz[indic][i] = 0;
    }
}

void Alterar (TUsuarios user, int indic, TRedeSocial *rede)
{
    rede->vetor[indic] = user;
    printf("\nUsuario atualizado com sucesso!\n");
}



