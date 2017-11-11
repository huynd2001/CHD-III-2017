#include <bits/stdc++.h>
using namespace std;

bool a[2007][2007];
int r[2007];
int dem[2007];

int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char ch;
			cin >> ch;
			a[i][j]=(ch=='1');
		}
	}
	int ans=0;
	for(int j=m;j>=1;j--)
	{
		for(int i=1;i<=n;i++)
		{
			if(!a[i][j]) r[i]=0; else r[i]=r[i]+1;
		}
		for(int i=0;i<=m;i++) dem[i]=0;
		for(int i=1;i<=n;i++) dem[r[i]]++;
			int su=0;
		for(int i=m;i>=0;i--)
		{
			su+=dem[i];
			ans=max(ans,i*su);
		}
	}
	cout << ans << endl;
	return 0;
}
