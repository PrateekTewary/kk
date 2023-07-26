#include<bits/stdc++.h>

#define int long long
#define endl "\n"
#define  sz(s)        (int)s.size()
#define  all(v)       (v).begin(),(v).end()
using namespace std;

void solve(){
    int n;  cin >> n;
    vector<int> arr(n);
  //storing a_i's
    for( int i = 0; i < n; ++i ){
        cin >> arr[i];
    }
  //rearrange equation to make ( a_i - b_i ) + ( a_j - b_j ) > 0 
  // arr[i] = ( a_i - b_i ) = c_i
    for( int i = 0; i < n; ++i ){
        int b;  cin >> b;
        arr[i] = arr[i] - b;
    }

    //NOTE - WHY SORTING DOESN'T AFFECT PAIR ORDER
    /*The indexes don't matter. The condition i<j is given just so that you don't count (1,2) and (2,1) as different pairs. 
     Ex. If the array is a, b, c, Then the pairs are ab, ac and bc. But if it is b, a, c, Then also the pairs are ba, bc and ac.*/
    sort( all(arr));
    int l = 0;
  //find index of largest difference c_i which is NOT greater than zero
    for( ; l < n; ++l ) if( arr[l] > 0 )    break;
    --l;
  // no Negative or zero element exists then all pairs will satisfy the condition
    if( l == -1 ){
        cout << (n*(n-1))/2 << endl;
        return;
    }

  // pos - denotes the first Non-zero positive difference c_i in sorted order
    int pos = 0, ans = 0;
    for( ; pos < n; ++pos )
        if( arr[pos] > 0 )  break;
  //all the positive elements will form a pair with each other so count them in answer
    ans += ((n-pos)*(n-pos-1))/2;

    //use two pointer technique to find first elements which satisfy the condition for l and r,  all the indices i > r will also satisfy, so add them to answer
    int r = 0;
    for( ; r < n; ++r )
        if( arr[r]+arr[l] > 0 ) break;

    for( ; l >= 0 && r < n; --l ){
        while( r < n && arr[l]+arr[r] <= 0 )    ++r;
        ans += (n-r);
    }

    cout << ans << endl;
}

int32_t main(){
    //ios_base::sync_with_stdio(false);
	//cin.tie(0), cout.tie(0);
    int t = 1;
    while( t-- )
        solve();
    return 0;
}
