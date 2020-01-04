#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define watch(x) cout << #x << " is " << x << endl;
#define print(a, l, r)          \
	for (int i = l; i < r; i++) \
		cout << a[i] << (i == (r - 1) ? endl : " ");
const long long M = 1000000007;
void findPrimeFactors(int x, vector<long long> &primes)
{
	if (x % 2 == 0)
	{
		primes.push_back(2);
		while (x % 2 == 0)
		{
			x /= 2;
		}
	}

	for (long long i = 3; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			primes.push_back(i);
			while (x % i == 0)
			{
				x /= i;
			}
		}
	}
	if (x > 2)
		primes.push_back(x);
}
long long mul(long long x, long long y, long long M)
{

	return ((x % M) * (y % M)) % M;
}
long long power(long long x, long long y, long long M)
{

	x = x % M;
	long long ans = 1;
	while (y > 0)
	{
		if (y % 2 != 0)
			ans = mul(ans, x, M);
		y /= 2;
		x = mul(x, x, M);
	}
	return ans % M;
}
int main()
{

	/* 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); */

	long long x, n;
	cin >> x >> n;

	long long ans = 1;
	vector<long long> primes;
	findPrimeFactors(x, primes);

	for (auto prime : primes)
	{
		long long tn = n;
		long long e = 0;
		while (tn)
		{
			e += tn / prime;
			tn /= prime;
		}

		ans = ((ans % M) * power(prime, e, M)) % M;
	}
	cout << ans << endl;
	return 0;
}