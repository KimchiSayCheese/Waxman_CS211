#include <iostream>		
#include <iomanip>

using namespace std;


int main() {
	int q[8][8] = { 0 };
	q[0][0] = 1;
	int c = 0, r = 0, n = 0;
col:
	c++;
	if (c == 8) {
		n++;
		goto print;
	}
		
	r = -1;
row:
	r++;
	if (r == 8) goto backtrack;
	//horizontal test
	for (int i = 0;i < c;i++) {
		if (q[r][i] == 1) goto row;
	}
	//up-diagnal test
	for (int i = 1; (r - i) >= 0 && (c-i) >= 0; i++) {
		if (q[r - i][c - i] == 1) goto row;
	}
	//down-diagnal test
	for (int i = 1; (r + i) < 8 && (c - i) >= 0;i++) {
		if (q[r + i][c - i] == 1) goto row;
	}
	//place queen
	q[r][c] = 1;
	goto col;

backtrack:
	c--;
	if (c == -1) return 0;
	r = 0;
	while (q[r][c] != 1) r++;
	q[r][c] = 0;
	goto row;


print:
	
	cout << "Solution number: "<< n << endl;
	for (int r = 0;r < 8;r++) {
		for (int c = 0;c < 8;c++) {
			cout << q[r][c] << " ";
		}
		cout << endl;
	}
	cout << endl;
	goto row;



	return 0;
}