#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define watch(x) cout << #x << " is " << x << endl;
#define print(a, l, r)          \
	for (int i = l; i < r; i++) \
		cout << a[i] << (i == (r - 1) ? endl : " ");
const long long M = 1000000007;

typedef vector<vector<long long>>
	matrix;
const int k = 2;

matrix mul(matrix a, matrix b)
{
	matrix c(k + 1, vector<long long>(k + 1));
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			for (int l = 1; l <= k; l++)
				c[i][j] = (c[i][j] + a[i][l] * b[l][j]) % M;
	return c;
}
matrix pow(matrix a, long long p)
{
	if (p == 1)
		return a;
	if (p % 2)
		return mul(a, pow(a, p - 1));
	matrix ans = pow(a, p / 2);
	return mul(ans, ans);
}
int fib(long long n)
{

	vector<long long>
		f(k + 1);
	f[1] = 1;
	f[2] = 3;
	matrix t(k + 1, vector<long long>(k + 1));
	t[1][1] = 0, t[1][2] = 1;
	t[2][1] = 2, t[2][2] = 2;

	if (n == 1)
		return 1;
	t = pow(t, n - 1);

	long long ans = 0;
	for (int i = 1; i <= k; i++)
		ans = (ans + t[1][i] * f[i]) % M;
	return ans;
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
		long long n;
		cin >> n;
		cout << fib(n) << endl;
	}
	return 0;
}