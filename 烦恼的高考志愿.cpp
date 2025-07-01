#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 100005;
ll n, m;
ll  a[N], b[N];

ll bineary_search(ll x)
{
	ll l = 0, r = m - 1;
	while (l < r)
	{
		ll mid = (l + r) >> 1;
		if (a[mid] >= x)
			r = mid;
		else l = mid + 1;
	}
	return l;// 返回第一个大于等于x的下标
}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		cin >> a[i];  //分数线
	for (int j = 0; j < n; j++)
		cin >> b[j]; //估分
	sort(a, a + m);
	sort(b, b + n);
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		ll id = bineary_search(b[i]);
		ll mins = abs(a[id] - b[i]);
		if(id>0) 
			mins = min(mins, abs(b[i] - a[id - 1]));
		sum += mins;
	}
	cout << sum << endl;
	return 0;
}