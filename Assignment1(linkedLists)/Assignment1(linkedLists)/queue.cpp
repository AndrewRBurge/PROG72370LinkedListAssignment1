#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"


/*

- A function to initialize a blank queue
- A function to check if the queue is empty
- A function to enqueue a node
- A function to dequeue a node

*/



//default queue set up
void initializeQueue(queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

bool isQueueEmpty(queue* q) {
    //simply checks if the head is NULL/empty then retuns
    return q->head == NULL;
}

void enqueue(queue* q, const string& usern, int lev, const string& fac) {
    //create a new node with data
    node* newNode = new node;
    newNode->user.username = usern;
    newNode->user.level = lev;
    newNode->user.faction = fac;
    newNode->link = NULL;

    //place node at the tail end of queue
    if (q->tail != NULL) {
        q->tail->link = newNode;
    }
    else {
        q->head = newNode;
    }

    q->tail = newNode;
}

void dequeue(queue* q) {
    //confirm its empty
    if (isQueueEmpty(q)) {
        cout << "Queue is empty. Nothing to dequeue.\n";
        return;
    }

    //print whats being removed
    node* temp = q->head;
    cout << "\nDequeued User:\n";
    cout << "Username: " << temp->user.username << "\n";
    cout << "Level: " << temp->user.level << "\n";
    cout << "Faction: " << temp->user.faction << "\n";

    
    q->head = q->head->link;
    if (q->head == NULL) {
        q->tail = NULL;
    }

    //delete temp space
    free(temp);
   
}

void printQueue(queue* q) {
    node* pointer = q->head;
    //use to track number of user
    int index = 1;
    //traverse the list by finding null
    while (pointer != NULL) {
        //print user data
        cout << "\nUser " << index << ":\n";
        cout << "Username: " << pointer->user.username << "\n";
        cout << "Level: " << pointer->user.level << "\n";
        cout << "Faction: " << pointer->user.faction << "\n";
        pointer = pointer->link;
        //sets up number for next user
        index++;
    }
}

void fillQueueRandom(queue* q, int count) {
    string name;
    int level;
    string faction;
    int factionc;
    //set up letters for random name generation
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
    int charsetSize = sizeof(charset) - 1;

#define NAMESIZE 7


    string factionset[3] = { "red", "blue", "green" };
    int factSize = sizeof(factionset) / sizeof(factionset[0]);

    for (int i = 0; i < count; i++) {

        level = rand() % 60 + 1;

        // generate name
        name = "";
        for (int n = 0; n < rand() % NAMESIZE + 1; n++) {

            name = name + charset[rand() % charsetSize];
        }
 faction = factionset[rand() % factSize];
        //add the random values to the end of the queue
        enqueue(q, name, level, faction);
    }

   
}
