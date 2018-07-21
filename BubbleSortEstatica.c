#include <stdio.h>
#include <stdlib.h>
#define CRESCENTE ('C')
#define DECRESCENTE ('D')
#define TAMANHO_VETOR 10

int MantemOrdem(ELEMENTO a, ELEMENTO b, char ordem)
{
	if(ordem == CRESCENTE)
	    return a.valor < b.valor;
	else if(ordem == DECRESCENTE)
		return a.valor > b.valor;

	return 0;
}

// ORDERNA A LISTA
void BubbleSort(int vetor[], int tamanho, char ordem)
{
	int i = 0, j = 0;

	for (i = 0; i < tamanho -1; i++)
		for (j = i + 1; j < tamanho ; j++)
			if (MantemOrdem(pElAtual->elemento, pElProximo->elemento, ordem))
			{
				int x = vetor[i];
				vetor[j] = vetor[i];
				vetor[i] = x;
			}
}

// IMPRIME TODOS OS ELEMENTOS DA LISTA
void Imprimir(int vetor[], int tamanho)
{
	int i = 0;
	for (i = 0; i < tamanho; i++)
		printf("[%d] - %d \n", i, vetor[i]);
}

void Pause()
{
	printf("\n\nTecle <ENTER> para continuar...");
	getchar();
}

int main()
{
	int vetor[TAMANHO_VETOR];
	int i = 0;

	for (i = TAMANHO_VETOR; i > 0; i--)
		vetor[i] = i;

	printf("NAO ORDERNADO\n");
	Imprimir(vetor, TAMANHO_VETOR);


	printf("\nORDERNADO CRESCENTE\n\n");
	BubbleSort(vetor, TAMANHO_VETOR, CRESCENTE);
	Imprimir(vetor);


	printf("\nORDERNADO DECRESCENTE\n\n");
	BubbleSort(vetor,TAMANHO_VETOR, DECRESCENTE);
	Imprimir(vetor);

	Pause();
	return 0;
}

