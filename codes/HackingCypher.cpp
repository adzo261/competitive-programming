#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define watch(x) cout << #x << " is " << x << endl;
#define print(a, l, r)          \
	for (int i = l; i < r; i++) \
		cout << a[i] << (i == (r - 1) ? endl : " ");
const long long M = 1000000007;
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
/*Finding if some long number represented as string is divisible by a normal number (long long)
let s be the number string and normal number be a
let p[i] =remainder of the number s[i] with a,
then we can find p[i+1]=((s[i]-'0')+p[i]*10)%a

If we need to make similar array for suffix,
let su[i]=remainder of the number s_i,s_i+1,....s_n i.e the suffix starting at position i of string s,
then we can find su[i-1]=(su[i]+(s[i]-'0')*10^(L-1))%a
*/
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	long long a, b;
	cin >> a >> b;
	long long n = s.length();
	long long p[n] = {0}, su[n] = {0};

	p[0] = (s[0] - '0') % a;

	for (int i = 1; i < n; i++)
	{
		p[i] = (p[i - 1] * 10 + (s[i] - '0')) % a;
	}
	su[n - 1] = (s[n - 1] - '0') % b;
	for (int i = n - 2; i >= 0; i--)
	{
		su[i] = (su[i + 1] + (s[i] - '0') * power(10, n - i - 1, b)) % b;
	}

	long long ans = -1;
	for (int i = 0; i < (n - 1); i++)
	{
		if ((i == 0 && s[i] == '0') || (i == (n - 2) && s[n - 1] == '0'))
			continue;

		if (p[i] == 0 && su[i + 1] == 0 && s[i + 1] != '0')
		{

			ans = i;
			break;
		}
	}
	if (ans == -1)
		cout << "NO" << endl;
	else
	{
		cout << "YES" << endl;
		cout << s.substr(0, ans + 1) << endl;
		cout << s.substr(ans + 1, n - 1 - ans) << endl;
	}

	return 0;
}