#include <iostream>
using namespace std;

void result(int x[][4], int y[], int& z, int& n);
void print(int count, int y[]);
void backtrack(int& z);


int main() {
	int rel[8][4] = {
	{-1,-1,-1,-1},
	{0,-1,-1,-1},
	{1,-1,-1,-1},
	{0, 1, 2,-1},
	{1,2, 3, -1},
	{0,3, 4, -1},
	{3,4, 5, -1},
	{2,4, 6, -1}	
	};
	int q[8] = { 0 };
	int col = 0;
	int count = 1;
	result(rel, q, col, count);
}

void result(int x[][4],int y[],int& z, int& n) {
	while (z < 8) {
		y[z]++;
		if (y[z] == 8) {
			y[z] = 0;
			backtrack(z);
			continue;
		}
		for (int i = 0;i < 5;i++) {
			if (x[z][i]==-1) {
				z++;
				if (z == 8) 
				{
					print(n, y);
					backtrack(z);
					continue;
				}
				break;
			}
			if ((y[z] == y[x[z][i]]+1) || (y[z]==y[x[z][i]-1]) || y[z] == y[i]) {
				break;
			}
		}

	} // end while loop

}
void print(int count, int y[]) {
	cout << "Solution: " << count << endl;
	for (int i = 0; i < 8; i++) {
		cout << y[i];
	
	}
	cout << endl;
}
void backtrack(int& z) {
	z--;
	if (z == -1) {
		exit(0);
	}
}

