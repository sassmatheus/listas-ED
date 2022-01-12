#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct node {
	int num;
	struct node *proximo;
};

struct node *inicio = NULL;
struct node *fim = NULL;

void inserir();
void remover();
void listar();
void sort();

int main(int argc, char** argv) {
	cout << "##### FILA #####" << endl;
	int opcao;
	do {
		cout << endl << "MENU";
		cout << endl << "1: Inserir;" << endl;
		cout << "2: Remover;" << endl;
		cout << "3: Listar;" << endl;
		cout << "4: Ordenar." << endl;
		cout << "5: Finalizar." << endl;	
		cout << "Insira a opcao desejada: ";
		cin >> opcao;
		
		if (opcao == 1){
			inserir();
		} else if (opcao == 2){
			remover();
		} else if (opcao == 3){ 
			listar();
		} else if (opcao == 4){
			sort();
		} else if (opcao == 5){
			cout << "Fim.";
		} else {
			cout << "Opcao invalida. Tente novamente." << endl;
		}
	} while (opcao != 5);
	
	return 0;
}

void inserir(){
	cout << "Insira um numero inteiro a fila: ";
	node *novo = new node;
	cin >> novo->num;
		
	if (inicio == NULL){ //caso lista vazia, o elemento adicionado se torna primeiro E último
		inicio = novo;
		fim = novo;
	} else { 
		fim->proximo = novo; //elemento adicionado ocupa a posição seguinte do elemento "fim"
		fim = fim->proximo; //definida nova posição final 
		fim->proximo = NULL; //posição seguinte nula
	}
	cout << "Adicionado." << endl;
}
void remover(){
	if (inicio == NULL){ //caso lista vazia
		cout << "Fila vazia!" << endl;
	} else if (inicio == fim){ //caso apenas um elemento
		inicio = NULL;
		cout << "Removido." << endl;
	} else {
		struct node *temp;
		temp = inicio;
		inicio = temp->proximo; //segundo elemento definido como inicio
		temp = NULL; //primeiro elemento anulado
		cout << "Removido." << endl;	
	}
}
void listar(){
	struct node *aux;
	aux = inicio;
	if (inicio == NULL){ //caso lista vazia
		cout << "Fila vazia!" << endl;
	} else if (inicio == fim){ //caso adicionado apenas 1 elemento
		cout << "Fila: " << inicio->num << endl;
	} else {
		cout << "Fila: ";
		while (aux != NULL) { //até que elemento fim aponte para seu subsequente (NULL)
			cout << aux->num << " ";
			aux = aux->proximo;
		} 
		cout << endl;	
	}		
}
void sort(){
	struct node *i = inicio;
	struct node *j = inicio;
	
	while (i != NULL){
		while (j->proximo != NULL){
			if (j->num > j->proximo->num){
				int temp = j->num; //variavel temporaria para armazenar o numero MAIOR
				j->num = j->proximo->num; //j recebe numero MENOR que estava na posição seguinte
				j->proximo->num = temp; //posição seguinte recebe o numero MAIOR da variavel temporaria
			}
			j = j->proximo; // j incrementa para comparar o proximo elemento com seu sucessor
		}
		j = inicio; //j recebe inicio de novo para que o if execute novamente do zero
		i = i->proximo; // i incrementa para ordenar o elemento seguinte da lista
	}
	cout << "Fila ordenada!" << endl << endl;
}
