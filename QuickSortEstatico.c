#include<stdio.h>
#include<stdlib.h>
#define CRESCENTE ('C')
#define DECRESCENTE ('D')
#define TAMANHO 10

int MantemOrdem(int a, int b, char ordem)
{
	if (ordem == CRESCENTE)
		return a < b;
	else if (ordem == DECRESCENTE)
		return  a > b;

	return 0;
}

void QuickSort(int vet[], int aux, int tamanho, char ordem)
{
	int pivo = aux, i, ch, j;

	for (i = aux + 1; i < tamanho; i++)
	{
		j = i;

		if (MantemOrdem(vet[j], vet[pivo], ordem))
		{
			ch = vet[j];

			while (j > pivo)
			{
				vet[j] = vet[j - 1];
				j--;
			}
			vet[j] = ch;
			pivo++;
		}
	}
	if (pivo - 1 >= aux)
		QuickSort(vet, aux, pivo - 1, ordem);
	else if (pivo + 1 < tamanho)
		QuickSort(vet, pivo + 1, tamanho, ordem);
}

void Imprimir(int vet[])
{
	int i = 0;
	printf("VETOR ESTATICO\n\n");
	for (i = 0; i < TAMANHO; i++)
		printf("[%d] = %d\n", i, vet[i]);
}

int main()
{
	int vet[TAMANHO], i;
	for (i = TAMANHO - 1; i >= 0; i--)
		vet[i] = i;

	QuickSort(vet, 0, TAMANHO, CRESCENTE);
	Imprimir(vet);

	getchar();
	return 0;
}