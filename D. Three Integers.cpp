#include<bits/stdc++.h>

#define int long long
#define endl "\n"
#define  sz(s)        (int)s.size()
#define  all(v)       (v).begin(),(v).end()
using namespace std;

void solve(){
//READ EDITORIAL FOR CODE EXPLANATION
    int a, b, c;    cin >> a >> b >> c;
    int ansA, ansB, ansC;
    int ans = INT_MAX, lim = 2*a;
    for( int A = 1; A <= lim; ++A ){

        for( int B = A; B <= 2*b; B += A ){
            int op = abs(A-a);
            op += abs(B-b);
            //if( A == 114 && B == 228 ) cout << "\t\t" << op << " " << abs(A-a) << " " << abs(B-b) << "\t";
            int C1 = (c/B)*B;
            int C2 = ((c/B)*B)+B;
            if( abs(C1-c) < abs(C2-c) ){
                op += abs(C1-c);
                if( op < ans ){
                    ans = op;
                    ansA = A, ansB = B, ansC = C1;
                }
            }
            else{
                op += abs(C2-c);
                if( op < ans ){
                    ans = op;
                    ansA = A, ansB = B, ansC = C2;
                }
            }


        }


    }

    cout << ans << endl;
        cout << ansA << " " << ansB << " " << ansC << endl;
}

int32_t main(){
    //ios_base::sync_with_stdio(false);
	//cin.tie(0), cout.tie(0);
    int t;  cin >> t;
    while( t-- )
        solve();
    return 0;
}
