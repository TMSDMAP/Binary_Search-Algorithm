#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll n, k;
ll L[1000005];

bool check(ll x)
{
	ll cnt = 0;
	for (ll i = 0; i < n; i++)
	{
		cnt += L[i] / x;
	}
	return cnt >= k;
}

ll binary_search(ll l, ll r)
{
	while (l < r)
	{
		ll mid = (l + r) >> 1;
		if (check(mid))
			l = mid+1;
		else r = mid;
	}
	return l-1;
}

int main()
{
	cin >> n >> k;
	ll m = 0;
	for (ll i = 0; i < n; i++)
	{
		cin >> L[i];
		m = max(m, L[i]);
	}
	ll ans = binary_search(1, m);
	if (ans < 1) cout << 0 << endl;
	else
	cout << ans << endl;
}