#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool is_prime(int n) {
	if (n % 2 == 0&&(n!=2)) return false;
	for (int i = 3; i < n; i+=2) {
		if (n%i == 0) return false;
	}
	return true;
}

bool smaller(int n) {
	int k = n;
	int m = k / 10;
	while (m != 0) {

		if (k % 10 < m % 10) return false;
		m /= 10;
		k /= 10;
	}
	return true;
}

int main() {
	int  n;
	scanf("%d", &n);
	for (int i = 2; i < n; i++) {
		if (smaller(i) && (is_prime(i))) { printf("%d", i);
		printf("%s","\n");
		}
	}
	
	
}
