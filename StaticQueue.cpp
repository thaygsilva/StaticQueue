//Thayna Gomes da Silva TIA:32092229
#include "StaticQueue.h"
#include <string>
#include <iostream>
using namespace std;

StaticQueue Create() {
	StaticQueue queue = {
		0, // int front;
		0, // int rear;
		0, // int count;
		{ 0 } // char values[STATIC_QUEUE_CAPACITY];
	};

	return queue;
}


bool EnqueueA(StaticQueue& queueA, infoWater elem) {
	if (queueA.count == Size(queueA)) {
		return false;
	}

	// Insere elem no final da fila (vetor da queue).
	queueA.values[queueA.rear] = elem;

	// "Vetor circular": se chegou no final do vetor (no limite/capacidade do vetor),
	// a variável rear, que é usada para indicar o índice correto para um novo elemento da fila,
	// volta pro início do vetor.
	queueA.rear = (queueA.rear + 1) % Size(queueA); // Mantém queue.rear no intervalo 0 <= queue.rear < Size(queue).

	// A linha acima equivale à:
	// ++queue.rear;
	// if (queue.rear == Size(queue))
	// {
	// 	queue.rear = 0;
	// }

	++queueA.count;

	return true;
}

bool EnqueueB(StaticQueue& queueB, infoWater elem) {
	if (queueB.count == Size(queueB)) {
		return false;
	}

	// Insere elem no final da fila (vetor da queue).
	queueB.values[queueB.rear] = elem;

	// "Vetor circular": se chegou no final do vetor (no limite/capacidade do vetor),
	// a variável rear, que é usada para indicar o índice correto para um novo elemento da fila,
	// volta pro início do vetor.
	queueB.rear = (queueB.rear + 1) % Size(queueB); // Mantém queue.rear no intervalo 0 <= queue.rear < Size(queue).

	// A linha acima equivale à:
	// ++queue.rear;
	// if (queue.rear == Size(queue))
	// {
	// 	queue.rear = 0;
	// }

	++queueB.count;

	return true;
}


infoWater DequeueA(StaticQueue& queueA) {
	if (IsEmpty(queueA)) {
		return { '\0',0,0,0,0 };
	}

	// Como remover e retornar o primeiro elemento da fila
	infoWater value = queueA.values[queueA.front];
	queueA.values[queueA.front] = { '\0',0,0,0,0 };

	// "Vetor circular": se chegou no final do vetor (no limite/capacidade do vetor),
	// a variável front, que é usada para indicar o índice correto do primeiro elemento da fila,
	// volta pro início do vetor.
	queueA.front = (queueA.front + 1) % Size(queueA); // Mantém queue.front no intervalo 0 <= queue.front < Size(queue).

	// A linha acima equivale à:
	// ++queue.front;
	// if (queue.front == Size(queue))
	// {
	// 	queue.front = 0;
	// }

	--queueA.count;

	return value;
}


infoWater DequeueB(StaticQueue& queueB) {
	if (IsEmpty(queueB)) {
		return { '\0',0,0,0,0 };
	}

	// Como remover e retornar o primeiro elemento da fila
	infoWater value = queueB.values[queueB.front];
	queueB.values[queueB.front] = { '\0',0,0,0,0 };

	// "Vetor circular": se chegou no final do vetor (no limite/capacidade do vetor),
	// a variável front, que é usada para indicar o índice correto do primeiro elemento da fila,
	// volta pro início do vetor.
	queueB.front = (queueB.front + 1) % Size(queueB); // Mantém queue.front no intervalo 0 <= queue.front < Size(queue).

	// A linha acima equivale à:
	// ++queue.front;
	// if (queue.front == Size(queue))
	// {
	// 	queue.front = 0;
	// }

	--queueB.count;

	return value;
}


char DequeueAny(StaticQueue& queueA, StaticQueue & queueB, char &remove, int dataA, int dataB) {


	if (toupper(remove) == 'C') {

		if (IsEmpty(queueA) && IsEmpty(queueB)) {
			cout << "Estoque vazio" << endl;
		}

		else if (dataA <= dataB) {
			if (!IsEmpty(queueA)) remove = 'A';
			else remove = 'B';
		}
		else if (dataB <= dataA) {
			if (!IsEmpty(queueB)) remove = 'B';
			else remove = 'A';
		}
		if (!IsEmpty(queueA) | !IsEmpty(queueB)) cout << "Estoque mais antigo: " << remove << endl;
	}

	return remove;
}


infoWater Front(const StaticQueue& queue) {
	//if (IsEmpty(queue))
	//{
	//	return '\0';
	//}
	//else
	//{
	//	return queue.values[queue.front];
	//}

	// O código abaixo é equivalente ao código comentado acima.
	if (IsEmpty(queue) == 1) {
		return { '\0', 0, 0, 0, 0 };
	}
	else {
		return  queue.values[queue.front];
	}
}


int Size(const StaticQueue& queue) {
	return sizeof(queue.values) / sizeof(queue.values[0]); // return STATIC_QUEUE_CAPACITY;
}


int Count(const StaticQueue& queue) {
	return queue.count;
}


bool IsEmpty(const StaticQueue& queue) {
	return queue.count == 0;
}


bool Clear(StaticQueue& queueA, StaticQueue &queueB) {
	while (!IsEmpty(queueA) && !IsEmpty(queueB)) {
		DequeueA(queueA);
		DequeueB(queueB);
	}

	return IsEmpty(queueA);
}


void PrintQueue(const StaticQueue& queue) {
	infoWater front = Front(queue);

	tm timeInfo;
	localtime_s(&timeInfo, &front.t);

	cout << "Tipo: " << front.type << endl;
	if (front.t == 0) {
		cout << "Data: " << endl;
		cout << "Hora: " << endl;

	}
	else {
		cout << "Data: " << timeInfo.tm_mday << "/" << (timeInfo.tm_mon + 1) << "/" << (timeInfo.tm_year + 1900) << "\n";
		cout << "Hora : " << timeInfo.tm_hour << ":" << timeInfo.tm_min << ":" << timeInfo.tm_sec << "\n";
	}
	cout << "Estante: " << front.shelf << endl;
	cout << "Prateleira: " << front.tier << endl;
	cout << "Gaveta: " << front.drawer << endl;

}