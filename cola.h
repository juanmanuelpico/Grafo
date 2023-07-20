#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#define SIZE 40

//Cola para el recorrido
struct ColaE;
typedef struct ColaE * Cola;


//Primitivas de la cola
Cola crearQueue();
void enqueue(Cola q, int);
int dequeue(Cola q);
void display(Cola q);
int isEmpty(Cola q);
void printQueue(Cola q);


#endif // COLA_H_INCLUDED
