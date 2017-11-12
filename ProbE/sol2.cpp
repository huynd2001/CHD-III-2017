#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,ans,pro,dem;
int a[22];

void backtrack(int i)
{
	// cout << i << endl;
	if(i==n+1)
	{
		if(pro==1 || pro==0) return ;
		// cout << ans << "\n" ;
		if(dem%2==1) ans+=m/pro; else ans-=m/pro;
		return ;
	}
	if(pro>m) return ;
	pro*=a[i];
	dem++;
	backtrack(i+1);
	pro/=a[i];
	dem--;
	backtrack(i+1);
	return ;
}

signed main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	ans=0;
	pro=1;
	dem=0;
	backtrack(1);
	cout << ans << endl;
	return 0;
}
