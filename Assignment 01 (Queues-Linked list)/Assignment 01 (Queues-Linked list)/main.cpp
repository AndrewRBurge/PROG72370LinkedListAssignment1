#include <iostream>
#include "queue.h"

using namespace std;

// Andrew burge - PROG72370 - Spring 2025 - Section 1

/*
Create a struct to represent users in a game. What is required of each person is their unique username, their level (levels can range from 1 – 60), and their faction (red, blue or green).

Implement a set of functions in a queue.c file which defines the required operations of an abstract data type queue. 
The queue should be created as a struct containing two node pointers: for the head and tail of the queue. 
The queue should be created from a set of linked nodes, and you may use any code from the Week 04 lecture to assist in this implementation. 
The queue will require at minimum:

- A function to initialize a blank queue
- A function to check if the queue is empty
- A function to enqueue a node
- A function to dequeue a node
Create a struct to represent a queue node. This structure contains a node pointer and a user struct as its data.

Write a function to enqueue the queue with a number of randomly created users. 
You will need to pass this function a pointer to an initialized queue, and the number of users to add to the queue. 
The number of users to add to the queue is to be passed to the program as a command line argument. 
Each user should be randomly generated 
(for the username you can randomly select a set number of letters and numbers. I.e., 
you can hardcode in all usernames are 10 characters in length, for example.yur234rt5g). 
This function returns 0 if it succeeds, and non-zero if something goes wrong.

Write a testing main() function which initializes the queue, 
calls the function to add users to the queue (and reports if an error occurred), 
and then dequeues from the function one at a time until the queue is empty. 
After each dequeue, print on the screen the username, level and faction of the user that was dequeued.
*/

//int e, queue* pointer, queue* head

void FillQueueRandom(queue* head,int e) {
	string name;
	int id;
	string faction;
	int factionc;
	//set up letters for random name generation
	char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
	int charsetSize = sizeof(charset) - 1;

#define NAMESIZE 7


	string factionset[3] = {"red", "blue", "green"};
	int factSize = sizeof(factionset) / sizeof(factionset[0]);

	for (int i = 0; i < e; i++) {

		id = rand() % 60 + 1;

		// generate name

		name = "";
		for (int n = 0; n < rand() % NAMESIZE + 1; n++) {
			
			name = name + charset[rand() % charsetSize];
		}


		//generate faction
		faction = factionset[rand() % factSize];

		//cout << "\n" << rand();
		cout << "\nUSER:";
		cout << "\nname: " << name;
		cout << "\nlevel: " << id;
		cout << "\nfaction: " << faction;
		cout << "\n";

		enqueue(head,name,id,faction);
	}
	
};



int main() {

	srand(time(0));

	//FillQueueRandom(5);

	queue* pointer, *head;
	int a = 10;
	int b = 0;

	// intitlize head node
	head = (queue*)malloc(sizeof(queue));
	head->link = NULL;
	pointer = head;

// IntitlizeQueue(pointer,head,a);
 CheckIfEmpty(head);

 pointer = head;
 while (pointer != NULL) {
	 b++;
	 pointer = pointer->link;


 }
 cout << "\nitems:" << b;

	return (0);
}