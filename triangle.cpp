#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_triangular(int** tab, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j + i > n - 1) {
				if (tab[i][j] != 0) return false;
			}
		}
	}
	return true;
}
	

int main() {
	int n;
	scanf("%d", &n);
	int** tab;
	tab = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		tab[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++) {
			scanf("%d", &tab[i][j]);
		}
	}
	printf(is_triangular(tab, n) ? "YES\n" : "NO\n");
	free(tab);
}
