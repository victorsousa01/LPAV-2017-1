#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>



 struct retorno{
     int comp ;
     int troca ;
   }; 
 
 // -> Quick Sort Interno 

struct retorno qSortInterno(int v[], int inicio, int fim);
 
/* Funcao qickSort a ser chamada em outros pontos do programa. Serve apenas para disparar a chamada revursiva */
 
 
struct retorno  quickSort(int v[], int n) {
struct  retorno x = qSortInterno(v, 0, n-1);
return x;
 
}
 
/* Implementacao do quicksort em si. */
 
struct retorno qSortInterno(int v[], int inicio, int fim) {
  int pivot;
  int temp;
  int i,j;

  struct retorno x ;
 x.comp = 0;
 x.troca = 0;
 
  if(fim - inicio > 0) {
    i = inicio;
    j = fim;
    pivot = v[(i+j)/2];
 
    do {
      while(v[i] < pivot){ i++; x.comp++;}  /* procura por algum item do lado errado  >= pivot */
      while(v[j] > pivot){ j--; x.comp++;}/* procura por algum item do lado errado <= pivot */
      if(i<= j) { /* deixa o igual para garantir que ao final i<j */
    x.comp++;
    x.troca++;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
    i++; j--;
      }
    } while (i<=j);
 
    if(inicio < j) qSortInterno(v,inicio, j);
    if(i < fim) qSortInterno(v, i,fim);
  }

  return x;
}

int* geradorDeNumeros(int M, int K){

    unsigned short seed[]={12,1,2};
    int i;
    int *vetor = malloc(sizeof(int)*M);

    for(i=0;i<M;i++)
        vetor[i] = 1 + K * erand48(seed);

    return vetor;
}



int main(void)
{
	clock_t time1, time2, time_diff;
	int qtdnum, intervalo, *vet;
	
   struct timeval antes, depois ;
   float delta;
	/*
		32,64,128,256,512,1024,2048
	*/   
    int K = (2048*1024) ;
    qtdnum = K;
    intervalo = 10000;

	vet = geradorDeNumeros(qtdnum, intervalo);
	gettimeofday (&antes, 0) ;
	struct retorno r = quickSort(vet,qtdnum);
	gettimeofday (&depois, 0) ;
	delta = (depois.tv_sec + depois.tv_usec/1000000.0) -
               (antes.tv_sec  + antes.tv_usec /1000000.0) ;
   
   	
	printf("Tempo de execução em segundos do QUICKSORT: %f segundos\n", delta);

	


		return 0;
}
