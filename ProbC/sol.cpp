/*huypheu
3
1 2 3
*/

#include <bits/stdc++.h>
#define int long long
#define oo (LLONG_MAX/2)
using namespace std;

int su[100007][2];
int a[100007];
int mi[2][2];

signed main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		su[i][1]=su[i-1][0]+a[i];
		su[i][0]=su[i-1][1]-a[i];
	}
	int ans=-oo;
	mi[0][0]=0,mi[0][1]=oo;
	mi[1][0]=oo,mi[1][1]=oo;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,su[i][1]-mi[1-i%2][0]);
		// cout << ans << endl;
		ans=max(ans,su[i][0]-mi[i%2][0]);
		// cout << ans << endl;
		mi[i%2][0]=min(mi[i%2][0],su[i][0]);
		mi[i%2][1]=min(mi[i%2][1],su[i][1]);
	}
	cout << ans << endl;
	return 0;
}