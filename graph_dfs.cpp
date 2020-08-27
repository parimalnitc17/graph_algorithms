#include<bits/stdc++.h>
using namespace std;

void printdfs(int** arr, int n, int sv, bool* visited) {
	cout << sv << " ";
	visited[sv] = true;
	for (int i = 0; i < n; i++) {
		if (i == sv) {
			continue;
		}
		if (arr[sv][i] > 0 && visited[i] != true) {
			printdfs(arr, n, i, visited);
		}
	}
}
void printbfs(int** arr, int n, int sv, bool* visited) {
	queue<int> q;
	q.push(sv);
	visited[sv] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (int i = 0; i < n; i++) {
			if (i == x) {
				continue;
			}
			if (arr[x][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
bool haspath(int** arr, int n, int sv, int en, int* visited) {
	visited[sv] = true;
	for (int i = 0; i < n; i++) {
		if (i == sv) {
			continue;
		}
		if (arr[sv][i] == 1 && !visited[i]) {
			if (i == e) {
				return true;
			}

			haspath(arr, n, i, en, visited);

		}
	}
	return false;
}

int main() {

	int n, e;
	cin >> n >> e;
	int** arr = new int*[n];
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		visited[i] = false;
	}
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	printdfs(arr, n, 0, visited);
	cout << endl;


	delete[] visited;
	delete[] arr;


	return 0;

}