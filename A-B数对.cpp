#include <iostream>
#include <map>
using namespace std;
typedef long long LL;

int N, C;
map<LL, LL> m;
LL a[200005];
int main()
{
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		m[a[i]]++;
		a[i] = a[i] - C;
	}
	LL ans = 0;
	for (int i = 0; i < N; i++)
		ans += m[a[i]];
	cout << ans << endl;
	return 0;
}
