#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
double a, b, c, d;
double f(double x)
{
	return a * x * x * x + b * x * x + c * x + d;
}
double f1(double x)
{
	return 3 * a * x * x + 2 * b * x + c;
}
double s[5];
double X[3];
double bineary(double l, double r)
{
	double mid;
	
	while (r - l > 1e-6)
	{
		mid = (l + r) / 2;
		if (fabs(f(l)) < 1e-6) return l; // 如果左端点就是解
		if (fabs(f(r)) < 1e-6) return r; // 如果右端点就是解
		if (fabs(f(mid)) < 1e-6) return mid;
		if (f1(mid) > 0)
		{
			if (f(mid) < 0)
				l = mid;
			else
				r = mid;
		}
		else
		{
			if (f(mid) < 0)
				r = mid;
			else
				l = mid;
		}
	}
	return mid;
}

int main()
{
	cin >> a >> b >> c >> d;
	int k = 0;
	int k1 = 0;
	for (double i = -100; i <= 100; i++)
	{
		double x = i / 1.0;
		//cout << f(x) << " ";
		if (fabs(f(x)) < 1e-6)
		{
			X[k1++] = x; // 如果是解
			continue;
		}
		if (f(x) < 0 && f(x + 1) > 0 || (f(x) > 0 && f(x + 1) < 0))
			s[k++] = x;
	}
	for (int i = 0; i < k; i++)
	{
		double x = bineary(s[i], s[i] + 1);
		
		X[k1++] = x;
	}
	sort(X, X + k1);
	for (int i = 0; i < k1; i++)
	{
		if (i > 0 && fabs(X[i] - X[i - 1]) < 1e-6) continue; // 去重
		printf("%.2lf ",X[i]);
	}
	//printf("%.2lf %.2lf %.2lf\n",X[0],X[1],X[2]);
	return 0;
}
