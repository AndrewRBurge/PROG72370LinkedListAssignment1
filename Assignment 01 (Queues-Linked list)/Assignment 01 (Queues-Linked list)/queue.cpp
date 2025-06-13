#include <iostream>
#include "queue.h"

using namespace std;

/*

- A function to initialize a blank queue
- A function to check if the queue is empty
- A function to enqueue a node
- A function to dequeue a node

*/

void IntitlizeQueue(queue* pointer,queue* head, int size) {

	for (int i = 0; i< size; i++){
	pointer->link = (queue*)malloc(sizeof(queue));
	pointer = pointer->link;
	pointer->link = NULL;
	}
	
}

void CheckIfEmpty(queue* head) {
	int counter = 0;
	queue* pointer;
	//if there is no list repot back 
	if (head == NULL) {
		cout << "\nno list present";
	}

	pointer = head;
	// run throught the list to confirm 
	while (pointer != NULL) {
		pointer = pointer->link;
		//count structs encountered
		if (pointer != NULL) {
			counter++;
		}
		
	}

	// if the list has only one struct then report back
	if (counter == 1 && pointer == NULL) {
		cout << "\nno more than 1 struct is present in the list";
	}

	//if list is not empty report back
	if (counter > 1) {
		cout << "\nlist is not empty";
	}

	cout << "\nnumber of structs found:" << counter;

}

void enqueue(queue* head, string usern, int lev, string fac) {
	queue* pointer = head;
	
	while (pointer != NULL) {
		pointer = pointer->link;
	}

	pointer->link = (queue*)malloc(sizeof(queue));
	pointer = pointer->link;
	pointer->user.username = usern;
	pointer->user.level = lev;
	pointer->user.faction = fac;
	pointer->link = NULL;

}

void dequeue(queue* head,queue* pointer) {
	// store address in temp
	queue* temp;
	temp = head;
	// change head to link contained in it
	head = head->link;

	//delete old head
	free(temp);

	cout << "\ndequeue complete\n";
}

//delete an individue node in queue
void DeleteNode(queue* node, queue* pointer) {
	pointer->link = node->link; //  changing pointers
	free(node); //frees ups space

}