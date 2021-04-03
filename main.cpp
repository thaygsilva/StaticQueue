//Thayna Gomes da Silva TIA:32092229
#include <iostream>
#include "StaticQueue.h"
#include <ctime>
#include <string>
using namespace std;


int valor_global = 0;


int main()
{
	setlocale(LC_ALL, "pt_BR");

	StaticQueue queueA = Create();
	StaticQueue queueB = Create();
	StaticQueue queueAny = Create();// queueA + queueB

	int option = -1;
	while (option != 0) {
		infoWater water = { '\0',0,0,0 };

		cout << "Deseja adicionar ou remover o produto do sistema?" << endl << "1 - Adicionar " << endl << "2 - Remover" << endl << "0 - Sair" << endl;
		cin >> option;
		if (option == 1) {
			cout << " Insira as informações em ordem: " << endl;
			cout << "Tipo da água: A ou B" << endl;
			cin >> water.type;

			cout << "Número da estante" << endl;
			cin >> water.shelf;

			cout << "Número da prateleira" << endl;
			cin >> water.tier;

			cout << "Número da gaveta" << endl;
			cin >> water.drawer;

			if (toupper(water.type) == 'A') { //'A' == remove | 'a' == remove
				EnqueueA(queueA, water);
				infoWater frontA = Front(queueA);
				tm timeInfo;
				localtime_s(&timeInfo, &frontA.t);

			}
			if (toupper(water.type) == 'B') {
				EnqueueB(queueB, water);
				infoWater frontB = Front(queueB);
				tm timeInfo;
				localtime_s(&timeInfo, &frontB.t);
			}



		}
		if (option == 2) {
			char remove;
			cout << "Qual tipo deseja remover A, B ou C (qualquer uma)?" << endl;
			cin >> remove;
			int dataA = Front(queueA).t;
			int dataB = Front(queueB).t;

			if (toupper(remove) == 'C') {
				DequeueAny(queueA, queueB, remove, dataA, dataB);
			}

			if (toupper(remove) == 'A') { 
				if (IsEmpty(queueA) == 1) {
					cout << "Estoque vazio" << endl;
				}
				else {
					DequeueA(queueA);
				}
			}
			if (toupper(remove) == 'B') {
				if (IsEmpty(queueB) == 1) {
					cout << "Estoque vazio" << endl;
				}
				else {
					DequeueB(queueB);
				}
			}



		}
		PrintQueue(queueA);
		PrintQueue(queueB);
	}
}