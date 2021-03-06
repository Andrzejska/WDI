#include<stdio.h>
#include<stdlib.h>

void countingSort(int* tab, int n, int k) {
	int *counters = malloc(k * sizeof(int));
	int* result = malloc(n * sizeof(int*));
	for (int i = 0; i < k; i++) {
		counters[i] = 0;
		
	}
	for (int i = 0; i < n; i++) {
		counters[tab[i]]++;
		
	}
	for (int i = 1; i < k; i++) {
		counters[i] += counters[i-1];
		
	}
	for (int i = 0; i < n; i++) {
		counters[tab[i]]--;
		printf_s("%d\n", counters[i]);
		result[counters[tab[i]]] = tab[i];
	}
	for (int i = 0; i < n; i++) {
		tab[i] = result[i];
	}

}

int main() {
	int Z;
	scanf_s("%d", &Z);

	while (Z--) {

		int n, k;
		scanf_s("%d", &n);
		scanf_s("%d", &k);
		int *tab = malloc(n * sizeof(int*));
		for (int i = 0; i < n; i++) {
			scanf_s("%d", &tab[i]);
		}

		countingSort(tab, n, k);
		for (int i = 0; i < n; i++) {
			printf_s("%d\n", tab[i]);
		}
		system("pause");
		free(tab);
	}
}
