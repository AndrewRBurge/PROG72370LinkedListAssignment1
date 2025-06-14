#pragma once
#include <iostream>
using namespace std;

struct user {
    string username;
    int level;
    string faction;
};

struct node {
    user user;
    node* link;
};

struct queue {
    node* head;
    node* tail;
};



/*

- A function to initialize a blank queue
- A function to check if the queue is empty
- A function to enqueue a node
- A function to dequeue a node

*/


// Function declarations
void initializeQueue(queue* q);
bool isQueueEmpty(queue* q);
void enqueue(queue* q, const string& usern, int lev, const string& fac);
void dequeue(queue* q);
void printQueue(queue* q);
void fillQueueRandom(queue* q, int count);

