#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[22];

signed main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
		int dapan=0;
	for(int mask=1;mask<(1<<n);mask++)
	{
		int ans=1;
		bool ok=1;
		int dem=0;
		for(int i=0;i<n;i++)
		{
			if(mask&(1<<i)) ans*=a[i],dem++;
			if(ans>m)
			{
				ok=0;
				break;
			}
		}
		if(!ok) continue;
		if(dem%2) dapan+=(m/ans); else dapan-=(m/ans);
	}
	cout << dapan << endl;
	return 0;
}
