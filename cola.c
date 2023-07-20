#include <stdio.h>
#include <stdlib.h>
#include "cola.h"



struct ColaE {
  int items[SIZE];
  int front;
  int rear;
};


// Create a queue
Cola crearQueue() {
  Cola q = malloc(sizeof(struct ColaE));
  q->front = -1;
  q->rear = -1;
  return q;
}

// Check if the queue is empty
int isEmpty(Cola q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void enqueue(Cola q, int value) {
  if (q->rear == SIZE - 1)
    printf("\nCola completa!!");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int dequeue(Cola q) {
  int item;
  if (isEmpty(q)) {
    printf("Cola  vacia!!!");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      //printf("Reinicio de cola --> ");
      q->front = q->rear = -1;
    }
  }
  return item;
}

// Print the queue
void printQueue(Cola q) {
  int i = q->front;

  if (isEmpty(q)) {
    printf("Cola esta vacia");
  } else {
    printf("\nLa cola contiene \n");
    for (i = q->front; i < q->rear + 1; i++) {
      printf("%d ", q->items[i]);
    }
  }
}
