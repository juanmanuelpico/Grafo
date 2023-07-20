#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED


//Grafo
struct GrafoE;
typedef struct GrafoE * Grafo;

//Nodo del grafo
struct NodoE;
typedef struct NodoE * Nodo;

//Creación de nodo
Nodo crearNode(int v);


//Primitivas de grafo
Grafo crearGrafo(int vertices);
void agregarRelacion(Grafo grafo, int src, int dest);
void mostrarGrafo(Grafo grafo);
void mostrarGrafoText(Grafo grafo, int opcion);

///BFS
void bfs(Grafo grafo, int startVertex);


///DFS
void dfs(Grafo grafo, int vertex) ;

#endif // GRAFO_H_INCLUDED
