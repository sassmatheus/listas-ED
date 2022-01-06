#include <iostream>
#include <locale>

using namespace std;

int main(int argc, char** argv) {
	
	int tamanho, opcaoMenu, proximo;
	
	cout << "Insira o tamanho da fila: ";
	cin >> tamanho;
	int fila[tamanho]; //tamanho da fila determinado pelo usuário
	
	for (int i = 1; i <= tamanho; i++){ //preenchimento de todas as posições
		cout << "Insira o elemento da posicao " << i << " da fila: ";
		cin >> fila[i];
	}
	do{
		cout << endl << "MENU" << endl << endl;
		cout << "1 - Inserir elemento na fila." << endl;
		cout << "2 - Remover elemento da fila." << endl;
		cout << "3 - Listar fila atual." << endl;
		cout << "4 - Finalizar execucao." << endl << endl;
		cout << "Insira a opcao desejada: ";
		cin >> opcaoMenu;
		
		if (opcaoMenu == 1){
			if (fila[tamanho] == 0){ //apenas caso a última posição da fila esteja vazia
				cout << "Insira o proximo elemento: ";
				cin >> proximo;
				for (int i = 1; i <= tamanho; i++){ //passa por toda fila
					if (fila[i] == 0){ //preenche a primeira posição vazia encontrada
					fila[i] = proximo;
					cout << "Elemento adicionado." << endl;
					break; //para sair do laço após a primeira inserção
					} 
				}
			} else {
				cout << "Fila cheia." << endl;
			} 	
		}else if (opcaoMenu == 2){
			if (fila[1] != 0){
				for (int i = 1; i <= tamanho; i++){ //passa por toda fila
				fila[i] = fila[i+1]; //faz o atual elemento receber o valor do elemento seguinte
				}
				fila[tamanho] = 0; //determina o último elemento como sendo 0
				cout << "Elemento removido." << endl;
			} else {
				cout << "Fila vazia." << endl;
			}
			
		} else if (opcaoMenu == 3){ 
			cout << "Fila: ";
			for (int i = 1; i <= tamanho; i++){ //lista todos elementos da fila
				cout << fila[i] << " | ";
			}
			cout << endl;
		} else if (opcaoMenu == 4){
			cout << "Fim da execucao" << endl;
		} else{ 
			cout << "Opcao invalida." << endl;
		}
	} while (opcaoMenu != 4); 
	return 0;
}

