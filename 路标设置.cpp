#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll N = 100005;
ll l, n, k;
ll a[N];

bool judge(ll x)
{
	if (x == 0) return false;
	ll cnt = 0;
	ll i = 0;
	while (i < n - 1)
	{
		i++;
		if (a[i] - a[i - 1] > x)
		{
			cnt += (a[i] - a[i - 1] - 1) / x;
		}  //注意要多减1！！！
	}
	return cnt <= k;
}

ll binary_search(ll l, ll r)
{
	while (l <= r)
	{
		ll mid = (l + r) >> 1;
		if (judge(mid))
			r = mid - 1;
		else l = mid + 1;  //l = 0,r = 51
	}
	return l;
}



int main()
{
	cin >> l >> n >> k;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	ll l1 = 1, r1 = l;
	//sort(a, a + n);
	ll ans = binary_search(l1, r1);
	cout << ans << endl;
	return 0;
}