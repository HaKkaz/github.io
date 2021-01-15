#include<bits/stdc++.h>
using namespace std;
const int maxn = (1<<22);
long long dp[maxn];
void solve(int l , int r){
	if(l == r) return;
	int mid = (l+r)>>1;
	solve(l , mid);
	solve(mid+1 , r);
	for(int i=mid+1 ; i<=r ; ++i) dp[i] += dp[l+(i-mid-1)];
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n , m ;
	cin >> n >> m ;
	while(m--){
		string s; 
		int val;
		cin >> s >> val;
		int num=0;
		for(int i=0 ; i<n ; ++i){
			if(s[i] == '1')
				num |= (1<<(n-i-1));
		}
		dp[num] = val;
	}
	solve(0,(1<<n)-1);
	sort(dp+1 , dp+(1<<n));
	long long ans = 0ll ;
	for(int i=1 ; i<(1<<n) ; ++i){
		ans += 1ll * i * dp[i];
	}
	cout << ans << '\n';
}