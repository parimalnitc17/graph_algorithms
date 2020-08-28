#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;

void prims(int** arr, int V, int st, bool* visited, int* parent, priority_queue< iPair, vector <iPair> , greater<iPair> > &q, int* weight) {
	visited[st] = true;

	for (int i = 0; i < V; i++) {

		if (i == st) {
			continue;
		}

		if (arr[st][i] > 0 && !visited[i]) {
			q.push(make_pair(arr[st][i], i));
			if (weight[i] > arr[st][i]) {
				weight[i] = arr[st][i];
				parent[i] = st;
			}
		}

	}

	while (!q.empty()) {
		pair<int, int> p = q.top();
		q.pop();
		prims(arr, V, p.second, visited, parent, q, weight);
	}
}


int main()
{
	int V, E;
	cin >> V >> E;
	int** arr = new int*[V];
	for (int i = 0; i < V; i++) {
		arr[i] = new int[V]();

	}
	for (int i = 0; i < E; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		arr[x][y] = z;
		arr[y][x] = z;
	}
	int* parent = new int[V];
	int* weight = new int[V];
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++) {
		parent[i] = -1;
		weight[i] = INT_MAX;
		visited[i] = false;
	}
	weight[0] = 0;
	parent[0] = -1;
	priority_queue< iPair, vector <iPair> , greater<iPair> > q;
	prims(arr, V, 0, visited, parent, q, weight);
	for (int i = 1; i < V; i++) {
		if (i > parent[i]) {
			cout << parent[i] << " " << i << " " << weight[i] << endl;
		}
		else {
			cout << i << " " << parent[i] << " " << weight[i] << endl;
		}
	}


	delete[] parent;
	delete[] weight;
	delete[] visited;
	for (int i = 0; i < N; i++) {
		delete[] arr[];
	}
	delete[] arr;



	return 0;
}
