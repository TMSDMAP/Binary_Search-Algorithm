#include <iostream>
using namespace std;
typedef long long ll;
ll L, N, M;
ll D[500005];


bool judge(ll x)
{
	ll cnt = 0;
	ll i = 0;
	ll now = 0;
	while (i < N + 1)
	{
		i++;
		if (D[i] - D[now] < x) cnt++;
		else
			now = i;
	}
	return cnt <= M;
}

int main()
{
	cin >> L >> N >> M;
	if (N == 0)
	{
		cout << L << endl;
		return 0;
	}
	for (ll i = 1; i <=N; i++)
	{
		cin >> D[i];
	}
	D[N+1] = L; // 最后一个石头的位置
	ll l = 1;
	ll r = L;
	ll ans = 0;
	while (l < r)
	{
		ll mid = (l + r) / 2;
		if (judge(mid))
		{
			//ans = mid;
			l = mid + 1; // 尝试更大的间距
		}
		else
			r = mid;
	}
	cout << l-1 << endl;
}
