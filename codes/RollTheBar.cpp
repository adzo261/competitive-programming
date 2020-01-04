#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define watch(x) cout << #x << " is " << x << endl;
#define print(a, l, r)          \
	for (int i = l; i < r; i++) \
		cout << a[i] << (i == (r - 1) ? endl : " ");
const long long M = 1000000007;
const int N = 1010;
int bfs[N][N][3];
string freeb[N];
int n, m;
queue<pair<pair<int, int>, int>> q;
bool isValid(int x, int y)
{
	return ((x > -1 && x < n) && (y > -1 && y < m) && (freeb[x][y] == '1'));
}
void add(int nx, int ny, int nstate, int ncost)
{
	if (bfs[nx][ny][nstate] != -1)
		return;
	bfs[nx][ny][nstate] = ncost;
	q.push({{nx, ny}, nstate});
}
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;

	while (t--)
	{

		memset(bfs, -1, sizeof bfs);

		cin >> n >> m;
		int sx, sy;
		cin >> sx >> sy;
		sx--, sy--;

		for (int i = 0; i < n; i++)
			cin >> freeb[i];

		bfs[sx][sy][0] = 0;
		q.push({{sx, sy}, 0});
		while (!q.empty())
		{
			int x = q.front().first.first, y = q.front().first.second, state = q.front().second;
			q.pop();

			int C = bfs[x][y][state];
			if (state == 0)
			{

				if (isValid(x, y - 1) && isValid(x, y - 2))
					add(x, y - 2, 1, C + 1);
				if (isValid(x, y + 1) && isValid(x, y + 2))
					add(x, y + 1, 1, C + 1);

				if (isValid(x - 1, y) && isValid(x - 2, y))
					add(x - 2, y, 2, C + 1);
				if (isValid(x + 1, y) && isValid(x + 2, y))
					add(x + 1, y, 2, C + 1);
			}

			if (state == 1)
			{

				if (isValid(x - 1, y) && isValid(x - 1, y + 1))
					add(x - 1, y, 1, C + 1);
				if (isValid(x + 1, y) && isValid(x + 1, y + 1))
					add(x + 1, y, 1, C + 1);

				if (isValid(x, y + 2))
					add(x, y + 2, 0, C + 1);
				if (isValid(x, y - 1))
					add(x, y - 1, 0, C + 1);
			}

			if (state == 2)
			{

				if (isValid(x, y - 1) && isValid(x + 1, y - 1))
					add(x, y - 1, 2, C + 1);
				if (isValid(x, y + 1) && isValid(x + 1, y + 1))
					add(x, y + 1, 2, C + 1);

				if (isValid(x + 2, y))
					add(x + 2, y, 0, C + 1);
				if (isValid(x - 1, y))
					add(x - 1, y, 0, C + 1);
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << bfs[i][j][0] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}