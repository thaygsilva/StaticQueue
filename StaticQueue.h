//Thayna Gomes da Silva TIA:32092229
#ifndef __STATIC_QUEUE_H__
#define __STATIC_QUEUE_H__
#include <ctime>

const int STATIC_QUEUE_CAPACITY = 100;

struct infoWater {
	char type;
	int shelf;
	int tier;
	int drawer;
	time_t t = time(nullptr);
};

struct StaticQueue {
	int front;
	int rear;
	int count;

	infoWater values[STATIC_QUEUE_CAPACITY];
};


StaticQueue Create();


infoWater Front(const StaticQueue& queue);


int Size(const StaticQueue& queue);


int Count(const StaticQueue& queue);


bool IsEmpty(const StaticQueue& queue);


bool Clear(StaticQueue& queueA, StaticQueue &queueB);


void PrintQueue(const StaticQueue& queue);


bool EnqueueA(StaticQueue& queue, infoWater elem);


bool EnqueueB(StaticQueue& queue, infoWater elem);


infoWater DequeueA(StaticQueue& queue);


infoWater DequeueB(StaticQueue& queue);


char DequeueAny(StaticQueue& queueA, StaticQueue &queueB, char &remove, int dataA, int dataB);

#endif // __STATIC_QUEUE_H__
