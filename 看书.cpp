#include <iostream>
#include <vector>
using namespace std;

vector<long long> a;
int M;
bool check(long long x)
{
	long long sum = 0;
	for (long long i : a)
		sum += max(0LL,i - x);
	return sum >= M;
}

long long bineary_search(long long l,long long r)
{
	while (l < r)
	{
		long long mid = (l+r)>>1;
		if (check(mid))
			l = mid+1;
		else
			r = mid;
	}
	return l-1;
}

int main()
{
	int n;
	long long maxx = 0;
	cin >> n;
	a.resize(n);
	cin >> M;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	long long ans = bineary_search(0,maxx);
	cout << ans << endl;
	return 0;
}