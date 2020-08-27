#include <iostream>
using namespace std;
bool haspath(int** arr, int n, int sv, int en, bool* visited) {
	visited[sv] = true;
	if (sv == en) {
		return true;
	}
	for (int i = 0; i < n; i++) {
		if (i == sv) {
			continue;
		}
		if (arr[sv][i] == 1 && !visited[i]) {
			if (haspath(arr, n, i, en, visited)) {
				return true;
			}

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
	int st, en;
	cin >> st >> en;
	if (haspath(arr, n, st, en, visited)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}



	delete[] visited;
	delete[] arr;




	return 0;
}
