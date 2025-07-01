#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll N = 1e5 + 5;
ll n, m;
ll a[N];
ll p[N];

bool judge(ll x)
{
	ll cnt = 1; //初始为1段
	ll now = 1;
	ll i = 0;
	while (i < n)
	{
		i++;
		if (p[i] - p[now - 1] > x)
		{
			cnt++;
			now = i;
		}
	}
	return cnt <= m;
}

ll binary_search(ll l, ll r)
{
	while (l < r)
	{
		ll mid = (l + r) >> 1;
		if (judge(mid))
			r = mid;
		else l = mid + 1;
	}
	return l;
}

int main()
{
	cin >> n >> m;
	ll l1 = 0;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		p[i] = p[i - 1] + a[i];
		l1 = max(l1, a[i]);
	}
	ll ans = binary_search(l1, p[n]);
	cout << ans << endl;
	return 0;
}
