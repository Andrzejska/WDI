#include <iostream>
using namespace std;
int const N = 5;

int moves_x[8] = {1,1,-1,-1,2,2,-2,-2};
int moves_y[8] = {-2,2,-2,2,1,-1,1,-1};

bool isMovePossible(int tab[N][N],int x,int y){
	return (tab[x][y] == 0 && x >= 0 && x < N&&y < N&&y >= 0);
}

bool skoczek(int tab[N][N],int x,int y,int number) {
	tab[x][y] = number;
	if (number == N * N) return true;
	for (int i = 0; i < 8; i++) {
		int x_next = x + moves_x[i];
		int y_next = y + moves_y[i];
		if (isMovePossible(tab, x_next, y_next)) if(skoczek(tab, x_next, y_next, number++))return true;
}
	tab[x][y] = 0;
	return false;
}




int main() {
	int tab[N][N] = {};
	cout << skoczek(tab, 2,2, 1);
	system("pause");
}
