#include <iostream>
#include <algorithm>
using namespace std;
int a[1000005];
int n, m;

int binary_search(int t)
{
	int l = 0, r = n - 1;
	int ans = -1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (a[mid] >= t)
		{
			if (a[mid] == t)
				ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans == -1 ? -1 : ans + 1;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	while (m--)
	{
		int t;
		scanf("%d",&t);
		int ans = binary_search(t);
		printf("%d ",ans);
	}
}