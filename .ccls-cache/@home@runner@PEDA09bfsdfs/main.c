// Rafael Bonfim Zacco

/*
Sua  tarefa  será  imprimir  a  Pilha  do  DFS  e  a  Fila  do  BFS  quando  aplicadas  a  um  grafo  de  100 vértices cujos índices serão criados a partir de números aleatórias gerados entre 1 e 1000. Nesta tarefa você pode usar todos os algoritmos que desenvolveu ao longo desta disciplina.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void iniciarMatriz(int matriz[][1000]){
  for (int i=0 ; i<1000 ; i++){
    for (int j=0 ; j<1000 ; j++){    
      matriz[i][j] = -1;
    }
  }
}

void criarVerticeMatriz(int matriz[][1000],int valor){ 
  while( (matriz[valor][valor] == 0) || (matriz[valor][valor] == 1) ){
    valor = ( 1 + (rand() % 1000) );
  }
  matriz[valor][valor] = 0;
}

int contarAdjMatriz(int matriz[][1000],int valor){
  int soma = 0;

  for (int i=0 ; i<1000 ; i++){
    if(matriz[valor][i] == 1){
      soma += 1;
    }
  }

  return soma;
}

bool verificaVerticeMatriz(int matriz[][1000],int valor){
  if( (matriz[valor][valor] == 1) || (matriz[valor][valor] == 0) ){
    return true;
  }
  
  return false;
}

void criarArestaMatriz(int matriz[][1000],int vertice1,int vertice2){
 
  if(vertice1 != vertice2){
    if( (verificaVerticeMatriz(matriz,vertice1) == true) && (verificaVerticeMatriz(matriz,vertice2) == true) ){
      if( (contarAdjMatriz(matriz,vertice1) < 3) && (contarAdjMatriz(matriz,vertice2) < 3) ){
        matriz[vertice1][vertice2] = 1;
        matriz[vertice2][vertice1] = 1; 
      } 
    }       
  }   
}

void imprimirMatriz(int matriz[][1000]){
  for (int i=0 ; i<1000 ; i++){
    if( (matriz[i][i] == 1) || (matriz[i][i] == 0) ){
      printf("Matriz[%d]",i);
      for(int j=0 ; j<1000 ; j++){
        if(matriz[i][j] == 1){
          printf(" -> Matriz[%d]",j);
        }
      }
    printf("\n");
    }
  }
}

void vertices(int matriz[][1000],int vertice[]){

  int j = 0;
  for (int i=0 ; i<1000 ; i++){
    if( (matriz[i][i] == 1) || (matriz[i][i] == 0) ){
      vertice[j] = i;
      j++;
    }
  } 
}

void DFS_recursao(int matriz[][1000],int vertice[],int valor_inicial){
  bool tem = false;
  int posicao = 0;
  
  for(int p=0 ; p<100 ; p++){
    if(vertice[p] == valor_inicial){
      tem = true;
      posicao = p;
    }
  } 

  if(tem == true){
    vertice[posicao] = -1;
    for(int i=0 ; i<1000 ; i++){
      if(matriz[valor_inicial][i] == 1){
        DFS_recursao(matriz,vertice,i);
      }
    }
  }

  if(tem == true){
    if(valor_inicial != -1){
      printf("Valor = %d\n",valor_inicial);
    }
  }
}

void DFS(int matriz[][1000]){
  int vertice[100];

  vertices(matriz,vertice);

  for(int i=0 ; i<100 ; i++){
    DFS_recursao(matriz, vertice, vertice[i]);
  }
}

void BFS_recursao(int matriz[][1000],int vertice[],int valor_inicial){
  bool tem = false;
  int posicao = 0;
  
  for(int f=0 ; f<100 ; f++){
    if(vertice[f] == valor_inicial){
      tem = true;
      posicao = f;
    }
  } 

  if(tem == true){
    
    if(valor_inicial != -1){
      printf("Valor = %d\n",valor_inicial);
    }
    
    vertice[posicao] = -1;
    for(int i = 0; i<1000; i++){
      if(matriz[valor_inicial][i] == 1){
        BFS_recursao(matriz,vertice,i);
      }
    }
  }
}

void BFS(int matriz[][1000]){
  int vertice[100];

  vertices(matriz, vertice);

  for(int i=0 ; i<100 ; i++){
    BFS_recursao(matriz, vertice, vertice[i]);
  }
  
}

int main(){

  int grafo_matriz[1000][1000];
  int numero_aleatorio1;
  int numero_aleatorio2;
  int vertices_main[100];
  int vertice_main[100];
  
  srand(time(NULL));

  iniciarMatriz(grafo_matriz);

  for(int i=0 ; i<100 ; i++){
    numero_aleatorio1 = rand() % 1000;
    criarVerticeMatriz(grafo_matriz, numero_aleatorio1);
    vertices_main[i] = numero_aleatorio1;
  }

  for(int i=0 ; i<100 ; i++){
    numero_aleatorio1 = rand() % 4;
    for(int j=0 ; j<numero_aleatorio1 ; j++){
      numero_aleatorio2 = rand() % 100;
      criarArestaMatriz(grafo_matriz, vertices_main[i], vertices_main[numero_aleatorio2]);
    }
  }

  printf("\n---- REPRESENTAÇÃO DA MATRIZ ----\n");
  imprimirMatriz(grafo_matriz);
  vertices(grafo_matriz,vertice_main);

  printf("\n---- VÉRTICES ----\n");
  for(int i=0 ; i<100 ; i++){
    printf("Vértice Nº%d = %d\n",i+1,vertice_main[i]+1);
  }

  printf("\n---- DFS ---- \n");
  DFS(grafo_matriz);

  printf("\n---- BFS ----\n");
  BFS(grafo_matriz);
  
  return 0;
}