#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* topo = NULL;

// headers
void menu();
void inicializar();
void pop();
void push();
void exibirElemento();
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 5) {
		system("cls"); // somente no windows
		cout << "Menu Pilha";
		cout << endl << endl;
		cout << "1 - Inicializar Pilha \n";
		cout << "2 - Inserir elemento (Push) \n";
		cout << "3 - Remover elementos (Pop) \n";
		cout << "4 - exibir elementos \n";
		cout << "5 - Sair \n";


		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:push();
			break;
		case 3: pop();
			break;
		case 4: exibirElemento();
			break;
		case 5:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = topo;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	topo = NULL;
	cout << "Pilha inicializada \n";

}


void push()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = topo;
	topo = novo;

}

void pop()
{

	if (topo == NULL) {
		cout << "Lista Vazia." << endl;
	}
	else {
		NO* apagar = topo;

		topo = topo->prox;

		cout << "O elemento " << apagar->valor << " foi removido." << endl;
		free(apagar);

	}
	

}


void exibirElemento() {

	if (topo == NULL) {
		cout << "Lista Vazia." << endl;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = topo;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}

}
