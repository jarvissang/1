#include <bits/stdc++.h>

// Design N-Queens matrix having first Queen placed.
// Use backtracking to place remaining Queens to generate the final N-queen.

using namespace std;


vector<int> cols;
vector<int> diag1;
vector<int> diag2;
vector<int> board;

int N;

bool place(int row) {

	if (row == N) {
		return true;
	}
	
	for (int c = 0; c < N; c++) {
		int d1 = row - c + N - 1;
		int d2 = row + c;

		if (cols[c] || diag1[d1] || diag2[d2]) {
			continue;
		}

		board[row] = c;
		cols[c] = diag1[d1] = diag2[d2] = true;

		if (place(row + 1)) return true;

		cols[c] = diag1[d1] = diag2[d2] = false;
		board[row] = -1;
	}
	
	return false;
}

int main() {
	cout << "HW!" << endl;
	cin >> N;

	cols.resize(8, 0);
	diag1.resize(2*N - 1);
	diag2.resize(2*N - 1);
	board.resize(N, -1);
		
	place(0);

	for (int i = 0; i < N; i++) {
		cout << board[i] << " ";
	}
	cout << endl;

	return 0;
}
