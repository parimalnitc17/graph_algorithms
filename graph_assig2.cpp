#include<bits/stdc++.h>
using namespace std;
#define MAXN 102



bool iterate(char Graph[][MAXN], int N, int M, int** visited, string s, int i, int j) {
	if (s.size() == 0) {
		return true;
	}
	for (int x = i - 1; x <= i + 1; x++) {
		for (int y = j - 1; y <= j + 1; y++) {
			if (x == i && y == j) {
				continue;
			}
			if (x < 0 || x > N - 1 || y < 0 || y > M - 1) {
				continue;
			}
			if (Graph[x][y] == s[0] && visited[x][y] == 0) {
				string str = s.substr(1);
				visited[x][y] = 1;
				if (iterate(Graph, N, M, visited, str, x, y)) {
					return  true;
				}
				visited[x][y] = 0;
			}
		}
	}

	return false;
}
int solve(char Graph[][MAXN], int N, int M) {
	string s = "CODINGNINJA";
	int** visited = new int*[N];
	for (int i = 0; i < N; i++) {
		visited[i] = new int[M]();
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Graph[i][j] == s[0] && visited[i][j] == 0) {
				string str = s.substr(1);
				visited[i][j] = 1;
				if (iterate(Graph, N, M, visited, str, i, j)) {
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
	char Graph[MAXN][MAXN];
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> Graph[i];
	}
	cout << solve(Graph, N, M) << endl;
}