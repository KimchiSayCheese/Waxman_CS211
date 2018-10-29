#include <iostream>
#include <cmath>
using namespace std;


int main() {
	int q[8];
	q[0] = 0;
	int c = 0;
	int n = 0;
col:
	c++;
	if (c == 8) {
		n++;
		goto print;
	}
	q[c] = -1;
row:
	q[c]++;
	if (q[c] == 8) goto backtrack;
	for (int i = 0;i < c;i++) {
		if (q[c] == q[i]) goto row;
	}
	for (int i = c; i > 0;i--) {
		if ((q[c - i] == q[c] - i) || (q[c - i] == q[c] + i)) goto row;
	}
	goto col;
backtrack:
	c--;
	if (c == -1) return 0;
	goto row;
print:
	cout << "solution: " << n << endl;
	for (int c = 0; c < 8; c++) {
		for (int r = 0; r < 8; r++) {
			if (q[c] == r) {
				cout << "1 ";
			}
			else {
				cout << "0 ";
			}
		}
		cout << endl;
	}
	goto backtrack;
}