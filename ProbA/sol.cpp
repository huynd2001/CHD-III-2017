/*huypheu
001
*/

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
string s;
long long n,i,dem,ans,MOD=1e9+7;
int main()
{
	cin>>s;
	n=s.length();
	for(i=n-1;i>=0;i--)
	{
		if(s[i]=='0')
			ans+=dem,ans%=MOD,dem*=2,dem%=MOD;
		if(s[i]=='1')
			dem++,dem%=MOD;
	}
	cout<<ans;
}