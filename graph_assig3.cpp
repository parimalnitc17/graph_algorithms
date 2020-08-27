#include<bits/stdc++.h>
using namespace std;
#define MAXN 51

bool iterate(char board[][MAXN], int n, int m, int** visited, char c, int x, int y, int targetx, int targety, int &count) {

	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (i == x && j == y) {
				continue;
			}
			if (i != x && j != y) {
				continue;
			}
			if (i < 0 || i > n - 1 || j < 0 || j > m - 1) {
				continue;
			}
			if (count >= 4 && targetx == i && targety == j && board[i][j] == c) {
				cout << count << endl;
				return true;
			}
			if (board[i][j] == c && visited[i][j] == 0) {
				count++;
				visited[i][j] = 1;
				if (iterate(board, n, m, visited, c, i, j, targetx, targety, count)) {
					cout << count << endl;
					cout << i << " " << j << endl;
					return true;
				}
				else {
					count--;
					visited[i][j] = 0;
				}
			}
		}
	}
	return false;


}


int solve(char board[][MAXN], int n, int m)
{
	// Write your code here.
	int** visited = new int*[n];
	for (int i = 0; i < n; i++) {
		visited[i] = new int[m]();
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0) {
				char c = board[i][j];
				visited[i][j] = 1;
				count = 1;
				if (iterate(board, n, m, visited, c, i, j, i, j, count)) {
					cout << i << " " << j << endl;
					return  1;
				}
				visited[i][j] = 0;
			}
		}
	}
	return 0;
}


int main()
{
	int N, M, i;
	char board[MAXN][MAXN];
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> board[i];
	}
	cout << solve(board, N, M) << endl;
}