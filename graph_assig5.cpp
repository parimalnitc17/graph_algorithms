#include<iostream>
#include<vector>
using namespace std;


int solve(int n, int m, vector<int>u, vector<int>v)
{
    // Write your code here .
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n]();
    }
    cout << "parimal" << endl;
    for (int i = 0; i < m; i++) {
        int x = v[i];
        int y = u[i];
        arr[x - 1][y - 1] = 1;
        arr[y - 1][x - 1] = 1;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) {
                for (int k = 0; k < n; k++) {
                    if (arr[j][k] == 1) {
                        if (arr[k][i] == 1) {
                            count++;
                        }
                    }

                }
            }
        }
    }
    count = count / 6;
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