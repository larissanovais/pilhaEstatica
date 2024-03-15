// PILHA ESTATICA

#include <stdio.h>
#define MAX 50
#define true 1
#define false 0

typedef int boo;
typedef int TIPOCHAVE;

typedef struct {
	TIPOCHAVE chave;
	float salario;
} REGISTRO;

typedef struct {
	REGISTRO A[MAX];
	int topo;
} PILHA;

void inicializarPilha(PILHA* p) {
	p->topo = -1;
}

int tamanhoPilha(PILHA* p) {
	return p->topo + 1;
}

void exibirPilha(PILHA* p) {
	printf("Pilha: \n ");
	int i;
	for (i=p->topo;i>=0;i--) {
		printf("Chave: %i -> ", p->A[i].chave);
		printf("Salario: R$%.2f \n", p->A[i].salario);
	}
	printf("\n");
}

bool inserirElementoPilha(PILHA* p, REGISTRO reg) {
	if (p->topo >= MAX-1) return false;
	p->topo = p->topo+1;
	p->A[p->topo] = reg;
	return true;
}

bool excluirElementoPilha(PILHA* p, REGISTRO* reg) {
	if (p->topo == -1) return false;
	*reg = p->A[p->topo];
	p->topo = p->topo-1;
	return true;
}

void reinicializarPilha(PILHA* p) {
	p->topo = -1;
}

int buscaSequencial(PILHA* p, TIPOCHAVE ch) {
	int i = 0;
	while (i < p->topo+1){
		if(ch == p->A[i].chave) return i;
		else i++;
	}
	return -1;
}

boo mostrarSalario(PILHA* p, TIPOCHAVE ch) {
	int i;
	i = buscaSequencial(p,ch);
	
	if (p->topo == -1) return false;
	else {
		printf("Salario da chave: R$%.2f\n", p->A[i].salario);
	}
	return true;
}

int main() {

	PILHA pilha_principal;
	int op, posicao, num;
	REGISTRO reg;
	TIPOCHAVE chave; 
	
	do {
		printf("-----------------------------------------------");
		printf("\nEscolha uma das opcoes abaixo: \n");
		printf("1- Inicializar pilha\n");
		printf("2- Inserir elemento na pilha\n");
		printf("3- Tamanho da pilha\n");
		printf("4- Exibir pilha\n");
		printf("5- Mostrar salario a partir da chave\n");
		printf("6- Excluir elemento na pilha\n");
		printf("7- Reinicializar pilha\n");
		printf("0- Sair\n");
		scanf("%i", &op);
		
		switch(op){
			case 1: //inicializar 
				inicializarPilha(&pilha_principal);
				break;
				
			case 2: // inserir elem na pos n
				bool i;
				
				/*printf("Onde deseja colocar seu elemento? \n");
				scanf("%i", &posicao);*/
				
				printf("Digite sua chave: \n");
				scanf ("%i", &reg.chave);
				
				printf("Digite seu salario: \n");
				scanf ("%f", &reg.salario);
				
				i = inserirElementoPilha(&pilha_principal, reg);
				break;
				
			case 3: //tamanho
				int tam;
				
				tam = tamanhoPilha(&pilha_principal);
				
				printf("A pilha possui %i elemento(s).\n", tam);
			
				break;
				
			case 4: //exibir
				exibirPilha(&pilha_principal);
				break;
				
			case 5: // mostrar salario
				int h;
				
				printf("Digite sua chave: \n");
				scanf ("%i", &chave);
				
				h = mostrarSalario(&pilha_principal, chave);
				
				break;
				
			case 6: // apagar elem a partir da chave
				bool n;
				
				n = excluirElementoPilha(&pilha_principal, &reg);
				
				break;
				
			case 7: // reinicializar 
				reinicializarPilha(&pilha_principal);
				break;
			
			default:
				break;
				
		}
				
	} while(op != 0);
}
