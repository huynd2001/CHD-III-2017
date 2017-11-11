/*huypheu
5
0 1
0 9
1 2
3 4
2 5
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

int x[100007],y[100007];

signed main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> x[i] >> y[i];
	}
	sort(x+1,x+n+1);
	sort(y+1,y+n+1);
	int xa=x[n/2+n%2],ya=y[n/2+n%2];
	int ans=0;
	for(int i=1;i<=n;i++) ans+=abs(xa-x[i]);
	for(int i=1;i<=n;i++) ans+=abs(ya-y[i]);
	cout << ans << endl;
	return 0;
}