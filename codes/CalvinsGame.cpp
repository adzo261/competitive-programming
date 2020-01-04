#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define watch(x) cout << #x << " is " << x << endl;
#define print(a, l, r)                \
    for (long long i = l; i < r; i++) \
        cout << a[i] << (i == (r - 1) ? endl : " ");
const long long M = 1000000007;
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, k;
    cin >> n >> k;
    k--;
    long long a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long fdp[n] = {0};
    for (int i = k + 1; i < n; i++)
        fdp[i] = a[i] + max(fdp[i - 1], fdp[i - 2]);

    long long bdp[n] = {0};
    bdp[1] = a[0];
    for (int i = 2; i < n; i++)
        bdp[i] = max(a[i - 1] + bdp[i - 1], a[i - 2] + bdp[i - 2]);

    long long ans = fdp[k] + bdp[k];
    for (int i = k + 1; i < n; i++)
        ans = max(ans, fdp[i] + bdp[i]);

    cout << ans << endl;
    return 0;
}