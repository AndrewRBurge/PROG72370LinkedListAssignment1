#pragma once
#include <iostream>

using namespace std;

struct user {
	string username;
	int  level;
	string faction;


};

struct queue {
	user user;
	queue* link;
};


/*
- A function to initialize a blank queue
- A function to check if the queue is empty
- A function to enqueue a node
- A function to dequeue a node

*/


void IntitlizeQueue(queue* pointer, queue* head, int size);

void CheckIfEmpty( queue* head);

void enqueue(queue* head, string usern,int lev,string fac);

void dequeue(queue* head, queue* pointer);

void DeleteNode(queue* location, queue* pointer);
