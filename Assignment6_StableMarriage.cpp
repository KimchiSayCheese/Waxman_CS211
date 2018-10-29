#include <iostream>
using namespace std;

bool ok(int q[], int col) {
	int mp[3][3] = {
		0,2,1,
		0,2,1,
		1,2,0
	};
	int wp[3][3] = {
		2,1,0,
		0,1,2,
		2,0,1
	};
	for (int i = 0;i < col;i++) {
		if (q[i] == q[col]) {
			return false;
		}
		if ((mp[col][q[i]] < mp[col][q[col]]) && (wp[q[i]][col] < wp[q[i]][i])) {

			return false;
		}
		if ((wp[q[col]][i] < wp[q[col]][col]) && (mp[i][q[col]] < mp[i][q[i]])){

			return false;
		}
	}
	return true;
}

void backtrack(int& col) {
	col--;
	if (col == -1) {
		exit(1);
	}
}

void print(int q[], int counter) {
	cout << "Solution: " << counter << endl;
	for (int i = 0; i < 3; i++) {
		cout << q[i] << " ";
	}
	cout << endl;
}

int main() {
	int q[3];
	int col = 1;
	q[0] = 0;
	int counter = 1;
	bool fromBT = false;

	while (col < 3) {
		if (!fromBT) {
			q[col] = -1;
			fromBT = true;
		}
		q[col]++;
		if (q[col] == 3) {
			fromBT = true;
			backtrack(col);
			continue;
		}
		if (ok(q, col)) {
			fromBT = false;
			col++;
			if (col == 3) {
				fromBT = true;
				print(q, counter++);
				backtrack(col);

			}
		}
	}
}