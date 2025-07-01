#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 5;
ll n, p;
double a[N], b[N];
bool judge(double x)
{
	/*double cnt = 0;
	for (ll i = 1; i <= n; i++)
	{
		while (b[i] - x * a[i] + cnt * p < 0)
			cnt++;
	}
	return cnt <= x;*/
	double q = p * x;
	double sum = 0;
	for (int i = 1; i <=n; i++) {
		if (a[i] * x <= b[i]) continue;
		sum += (a[i] * x - b[i]);
	}
	return sum <= q;

}  //judge函数使用消耗来判断

double binary_search(double l, double r)
{
	while (r - l > 1e-6)
	{
		double mid = (l + r) / 2;
		if (judge(mid))
			l = mid; //满足条件，继续向右寻找更大的值
		else
			r = mid;
	}
	return l;
}

int main()
{
	cin >> n >> p;
	double total = 0;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		total += a[i];
	}
	if (total <= p)
	{
		printf("-1\n");
		return 0;
	}
	double l = 0, r = 1e10;
	double ans = binary_search(l, r);
	printf("%.10lf\n", ans);
	return 0;
}


