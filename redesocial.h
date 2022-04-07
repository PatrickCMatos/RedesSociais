#ifndef REDESOCIAL_H_INCLUDED
#define REDESOCIAL_H_INCLUDED
# define TAM 100


typedef struct data
{
    /* Estrutura das datas */
    int dia;
    int mes;
    int ano;
} TData;

typedef struct usuarios
{
    char nome[100];
    char email[200];
    char login[50];
    char senha[50];
    TData data_de_nascimento;
    int ID;
}TUsuarios;

typedef struct redeSocial{
    TUsuarios vetor[100];
    int matriz[100][100];
    int indice;
}TRedeSocial;


void Iniciar(TRedeSocial* rede);
void Cadastrar(TRedeSocial *rede, TUsuarios user);
void Imprimir2(TRedeSocial rede);
void Imprimir(TUsuarios user);
void Ler(TUsuarios* user);
int Pesquisar(TRedeSocial rede, char pesquisado[100]);

#endif // REDESOCIAL_H_INCLUDED
