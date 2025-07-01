#include <iostream>
using namespace std;

double n, m, t;
double find(double l, double r)
{
	double mid = (l + r) / 2;
	double ans = n;
	for (int i = 1; i <= t; i++)
	{
		ans = ans * (1 + mid) - m; //模拟
	}
	if (ans == 0 || r - l < 1e-4) return mid; //=0或者达到精度要求
	if (ans < 0) return find(mid, r);
	else return find(l, mid); //ans<0表示钱还多了，需要加大利率，>0表示还少了
}
int main()
{
	cin >> n >> m >> t;
	double ans = find(0, 5); //初始利率范围为0到5
	printf("%.1lf",ans*100);
	return 0;
}