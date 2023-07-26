#include<bits/stdc++.h>

#define int long long
#define endl "\n"
#define  sz(s)        (int)s.size()
#define  all(v)       (v).begin(),(v).end()
using namespace std;

int recur( int i, int sm, vector<vector<int>>& dp, int n, int h,
           int l, int r, vector<int>& sleepTime ){
    if( i == n )    return 0;

    if( dp[i][sm] != -1 )   return dp[i][sm];

    int sT1 = (sm+sleepTime[i]-1)%h;
    int sT2 = (sm+sleepTime[i])%h;
    int res1 = ( l <= sT1 && sT1 <= r ) + recur(i+1,sT1,dp,n,h,l,r,sleepTime);
    int res2 = ( l <= sT2 && sT2 <= r ) + recur(i+1,sT2,dp,n,h,l,r,sleepTime);

    return dp[i][sm] = max( res1, res2 );
}
void solve(){
    int n, h, l, r; cin >> n >> h >> l >> r;
    vector<int> sleepTime(n);
    for( int i = 0; i < n; ++i )    cin >> sleepTime[i];
    vector<vector<int>> dp(n+1,vector<int>(h+1,-1));

    cout << recur(0,0,dp,n,h,l,r,sleepTime) << endl;
}

int32_t main(){
    //ios_base::sync_with_stdio(false);
	//cin.tie(0), cout.tie(0);
    int t = 1;
    while( t-- )
        solve();
    return 0;
}
