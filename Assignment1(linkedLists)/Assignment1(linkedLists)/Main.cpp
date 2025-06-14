#include <iostream>
#include <ctime>
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




int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    queue myQueue;
    initializeQueue(&myQueue);

    int numUsers = 10;
    fillQueueRandom(&myQueue, numUsers);

    cout << "\nAll users in the queue:\n";
    printQueue(&myQueue);

    cout << "\nStarting dequeue process...\n";
    while (!isQueueEmpty(&myQueue)) {
        dequeue(&myQueue);
    }

    cout << "\nQueue is now empty.\n";
    return 0;
}
