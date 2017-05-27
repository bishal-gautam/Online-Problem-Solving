///==================================================///
///                HELLO WORLD !!                    ///
///                  IT'S ME                         ///
///               BISHAL GAUTAM                      ///
///         [ bsal.gautam16@gmail.com ]              ///
///==================================================///
#include<bits/stdc++.h>
#define X first
#define Y second
#define mpp make_pair
#define nl printf("\n")
#define SZ(x) (int)(x.size())
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
///---------------------
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
///------------------------------------
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define fr(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
typedef long long ll;

///  Digit     0123456789012345678 ///
#define MX     752
#define inf    2000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

ll x,ar[MX+2];
ll dp[MX+2][MX+2];
int main() {
    int n,m,i,j,k;
    while( S2(n,m)==2 ) {
        fr(i,1,n)SL(ar[i]);
        CLR( dp );
        for(i=n; i>=1; i--) {
            dp[ i ][ 0 ]=max( dp[i+1][0]-ar[i],-ar[i] );
            for(k=1; k<=n; k++) {
                dp[i][k]=max( dp[i+1][k]-ar[i],-ar[i] ); ///Dont Del this;
                dp[i][k]=min( dp[i][k],dp[i+1][k-1] ); ///Del this;
            }
//            for(k=0; k<=n; k++) {
//                cout<<dp[i][k]<<" ";
//            }
//            nl;
        }
        while(m--) {
            SL(x);
            int lo=0,hi=n,ret=n;
            while(lo<=hi) {
                int md=(lo+hi)>>1;
                if( dp[1][ md ]<=x ) {
                    ret=min(ret,md);
                    hi=md-1;
                } else lo=md+1;
            }
            printf("%d\n",ret);
        }
    }
    return 0;
}