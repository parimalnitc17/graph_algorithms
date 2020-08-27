#include<iostream>
#include<vector>
using namespace std;
#define NMAX 55
char cake[NMAX][NMAX];

void iterate(char board[][NMAX], int n, vector<vector<int> > &visited, int x, int y, int &count, int &maxi) {

	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {

			if (i == x && j == y) {
				continue;
			}
			if (i != x && j != y) {
				continue;
			}
			if (i < 0 || i > n - 1 || j < 0 || j > n - 1) {
				continue;
			}
			if (board[i][j] == '1' && visited[i][j] == 0) {

				count++;
				visited[i][j] = 1;
				iterate(board, n, visited, i, j, count, maxi);
				maxi = max(maxi, count);
			}
		}
	}
	return;


}
int solve(int n, char board[NMAX][NMAX])
{
	// Write your code here .
	int count = 0;
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vector<vector<int> > visited( n , vector<int> (n, 0));
			if ( board[i][j] == '1' && visited[i][j] == 0) {
				visited[i][j] = 1;
				count = 1;
				iterate(board, n, visited, i, j, count, maxi);
				maxi = max(count, maxi);
			}
		}
	}

	return maxi;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", cake[i]);
	}
	cout << solve(n, cake) << endl;
}