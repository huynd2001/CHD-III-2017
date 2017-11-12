#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[1000007];

signed main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
		int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=a[i]/2;
		a[i]=a[i]%2;
		if(i<n)
		{
			int k=min(a[i],a[i+1]);
			ans+=k;
			a[i]-=k;
			a[i+1]-=k;
		}
	}
	cout << ans << endl;
	return 0;
}
