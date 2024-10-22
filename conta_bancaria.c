#include <stdio.h>
#include <string.h>
#include "conta_bancaria.h"


void Inicializa(Conta* conta ,char nome[], int numero, double saldo){
    (*conta).numero = numero;
    (*conta).saldo = saldo;
    strcpy(conta->nome, nome); 
};

void Deposito(Conta* conta, Conta c1 ){
    int valor;


    printf("qual valor deseja depositar?\nvalor:");
    scanf("%d",&valor);
    (*conta).saldo += valor;
    menu(conta, c1);
    
};

void Saque(Conta* conta , Conta c1 ){
    int valor;


    printf("qual valor deseja sacar?\nvalor:");
    scanf("%d",&valor);
    (*conta).saldo -= valor;
    menu(conta, c1);
};

void Imprime(Conta* conta ){
    
    printf("Numero: %d\n", conta->numero);
    printf("Saldo: %d\n", conta->saldo);
    menu(conta, *conta);
};

int criar_conta(Conta* conta,Conta c1){
    Conta_provisoria cp1;
    printf("Vamos comecar a criando a sua conta!\nQual o seu nome?\nnome: ");
    scanf("%s", &cp1.nome);
    printf("numero da conta:\n ");
    scanf("%d", &cp1.numero);
    printf("saldo inicial:\n ");
    scanf("%lf", &cp1.saldo);

    strcpy(conta->nome, cp1.nome);
    conta->numero = cp1.numero;
    conta->saldo = cp1.saldo;


    printf("conta criada!\n");
    menu(conta, c1);
    return 0;
}

int menu(Conta* conta, Conta c1){
    int action;
    printf("menu:\n");
    printf("1- criar conta.\n2- Deposito\n3- Saque\n4-imprimir\n5-sair\nacao a ser tomada:");
    scanf("%d",&action);
    switch (action)
    {
    case 1:
        criar_conta(conta, c1);
        break;
    case 2:
        Deposito(&c1, c1);
        break;
    case 3:
        Saque(&c1, c1);
        break;
    case 4:
        Imprime(&c1);
        break;
    case 5:
        printf("saindo...");
        return 0;
    default:
        printf("Acao invalida.");
        menu(conta, c1);
        break;
    }
}