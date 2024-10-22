typedef struct{
    int numero;
    double saldo;
    char nome[50];
 } Conta;

typedef struct {
    int numero;
    double saldo;
    char nome[50];

} Conta_provisoria;

void Inicializa(Conta* conta , char nome[], int numero, double saldo);
void Deposito(Conta* conta , Conta c1 );
void Saque(Conta* conta , Conta c1 );
void Imprime(Conta* conta);
int criar_conta(Conta* conta,Conta c1);
int menu(Conta* conta, Conta c1);