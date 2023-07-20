#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grafo.h"
#include "cola.h"

// Definición de la estructura del Grafo con listas de adyacencia
struct GrafoE {
  int numVertices; // Número total de vértices en el grafo
  Nodo* adjLists; // Puntero a un arreglo de listas enlazadas (representando las listas de adyacencia)
  int* visited; // Puntero a un arreglo que realiza un seguimiento de los vértices visitados durante ciertos algoritmos
};

// Definición de la estructura del Nodo en una lista enlazada
struct NodoE {
  int vertex; // Número o etiqueta del vértice asociado a este nodo
  Nodo next; // Puntero al siguiente nodo en la lista enlazada (vértice adyacente)
};



// Creacion  del nodo
Nodo crearNode(int v) {

  Nodo newNode = malloc(sizeof(struct NodoE));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;

}




/// BFS algorithm
void bfs(Grafo grafo, int startVertex) {
  Cola q = crearQueue();

  grafo->visited[startVertex] = 1;
  enqueue(q, startVertex);

  while (!isEmpty(q)) {
    printQueue(q);
    int currentVertex = dequeue(q);
    printf("Visito el: %d\n", currentVertex);

    Nodo temp = grafo->adjLists[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (grafo->visited[adjVertex] == 0) {
        grafo->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
}

/// DFS algo
void dfs(Grafo grafo, int vertex) {
  Nodo adjList = grafo->adjLists[vertex];
  Nodo temp = adjList;

  grafo->visited[vertex] = 1;
  printf("Visito el: %d \n", vertex);

  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (grafo->visited[connectedVertex] == 0) {
      dfs(grafo, connectedVertex);
    }
    temp = temp->next;
  }
}




// Creating a grafo
Grafo crearGrafo(int vertices) {
  Grafo grafo = malloc(sizeof(struct GrafoE));

  grafo->numVertices = vertices;

  grafo->adjLists = malloc(vertices * sizeof(Nodo));
  grafo->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    grafo->adjLists[i] = NULL;
    grafo->visited[i] = 0;
  }

  return grafo;
}

// Add edge
void agregarRelacion(Grafo grafo, int src, int dest) {
  // Add edge from src to dest
  Nodo newNode = crearNode(dest);
  newNode->next = grafo->adjLists[src];
  grafo->adjLists[src] = newNode;

  // Add edge from dest to src
  newNode = crearNode(src);
  newNode->next = grafo->adjLists[dest];
  grafo->adjLists[dest] = newNode;
}



// Print the grafo
void mostrarGrafo(Grafo grafo) {
  int v;
  for (v = 0; v < grafo->numVertices; v++) {
    Nodo temp = grafo->adjLists[v];
    printf("\n ---> Lista de adyacencia del vertice:  %d\n ", v);
    while (temp) {
      printf("-> %d | ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}


void mostrarGrafoText(Grafo grafo, int opcion) {

  char dibujo[10] = "cloud";

  if(opcion == 2){
      strcpy(dibujo, "node");
  }
  if(opcion == 3){
      strcpy(dibujo, "storage");
  }
  if(opcion == 4){
      strcpy(dibujo, "entity");
  }



  int v;

  printf("Para graficar, subir archivo a:\nhttps://www.planttext.com/ \n\n");

  FILE * archivo = fopen("planttext.txt","w")  ;

  fprintf(archivo, "@startuml\n\n");
  //escribo los nodos
   for (v = 0; v < grafo->numVertices; v++) {

    fprintf(archivo,"%s %d\n",dibujo, v);

  }

  //escribo las relaciones
  for (v = 0; v < grafo->numVertices; v++) {

    Nodo temp = grafo->adjLists[v];


    while (temp) {

        if (temp->vertex > v){
          fprintf(archivo,"%d <--> %d\n", v, temp->vertex);

         }
        temp = temp->next;
    }
    fprintf(archivo,"\n");
  }

  fprintf(archivo,"@enduml");

  fclose(archivo);

}
