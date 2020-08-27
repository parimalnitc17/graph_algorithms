#include<bits/stdc++.h>
using namespace std;
void bfs(int** arr, int n, int sv, bool* visited) {
	queue<int> q;
	q.push(sv);
	visited[sv] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i < n; i++) {
			if (arr[x][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
int solve(int n, int m, vector<int> u, vector<int> v)
{
	// Write your code here .

	int** arr = new int*[n];
	bool* visited = new bool[n];

	for (int i = 0; i < n; i++) {
		arr[i] = new int[n]();
		visited[i] = false;
	}

	for (int i = 0; i < m; i++) {
		int x = v[i];
		int y = u[i];
		arr[x - 1][y - 1] = 1;
		arr[y - 1][x - 1] = 1;
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			bfs(arr, n, i, visited);
			count++;
		}
	}
	return count;

}

int main()
{
	int n, m;
	vector<int>u, v;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		u.push_back(x);
	}
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	cout << solve(n, m, u, v) << endl;
}