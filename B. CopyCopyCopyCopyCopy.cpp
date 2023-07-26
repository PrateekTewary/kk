#include<bits/stdc++.h>

#define int long long
#define endl "\n"
#define  sz(s)        (int)s.size()
#define  all(v)       (v).begin(),(v).end()
using namespace std;

void solve(){
    int n;  cin >> n;
    set<int> st;
    for( int i = 0; i < n; ++i ){
        int x;  cin >> x;
        st.insert(x);
    }

    cout << st.size() << endl;
}

int32_t main(){
    //ios_base::sync_with_stdio(false);
	//cin.tie(0), cout.tie(0);
    int t;  cin >> t;
    while( t-- )
        solve();
    return 0;
}
