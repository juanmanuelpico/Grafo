#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"


int main() {

  Grafo grafo = crearGrafo(6);

  agregarRelacion(grafo, 0, 1);
  agregarRelacion(grafo, 0, 2);
  agregarRelacion(grafo, 1, 2);
  agregarRelacion(grafo, 1, 4);
  agregarRelacion(grafo, 1, 3);
  agregarRelacion(grafo, 2, 4);
  agregarRelacion(grafo, 3, 4);

  mostrarGrafo(grafo);
  mostrarGrafoText(grafo,3);

  //bfs(grafo, 3);

  //dfs(grafo, 0);

  return 0;
}
