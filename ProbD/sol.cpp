/*huypheu
5
1 4 3 11 5
*/

#include <bits/stdc++.h>
using namespace std;

int a[1007],pre[1007],suf[1007];

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		if(i==1) pre[i]=a[i]; else pre[i]=max(pre[i-1],a[i]);
	}
	for(int i=n-1;i>=1;i--)
	{
		if(i==n-1) suf[i]=a[i]^a[i+1];
		else
		{
			suf[i]=suf[i+1];
			for(int j=i+1;j<=n;j++)
			{
				suf[i]=max(suf[i],a[i]^a[j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i>=2 && i<=n-2) ans=max(ans,pre[i-1]+a[i]*suf[i+1]);
	}
	cout << ans << endl;
	return 0;
}