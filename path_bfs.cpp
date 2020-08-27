#include <bits/stdc++.h>
using namespace std;

void pathbfs(int** arr, int n, int st, int en, int* visited) {
    unordered_map<int, int> m;
    queue<int> q;
    q.push(st);
    visited[st] = true;
    while (!q.empty()) {
        int x = q.front();
        bool z = false;
        q.pop();
        for (int i = 0; i < n; i++) {
            if (i == x) {
                continue;
            }
            if (arr[x][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
                m[i] = x;
                if (i == en) {
                    z = true;
                    break;
                }
            }
        }
        if (z) {
            break;
        }
    }
    int c = en;
    while (m.find(c) != m.end()) {
        cout << c << " ";
        c = m[c];
    }
    cout << c << endl;

}

int main()
{
    int n, e;
    cin >> n >> e;
    int** arr = new int*[n];
    int* visited = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n]();
        visited[i] = false;
    }
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    int x, y;
    cin >> x >> y;

    pathbfs(arr, n, x, y, visited);


    return 0;
}
