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
///==========CONSTANTS=============///
///  Digit     0123456789012345678 ///
#define MX     303
#define inf    2000000010
#define MD     1000000007
#define md     32452843
#define eps    1e-9
///===============================///

int n,m,p,dp[MX][MX];
vector< pii >G[MX*MX];
int main() {
    int x,y,z,i,j,k,px,py;
    S2(n,m);
    S(p);
    fr(i,1,n) {
        fr(j,1,m) {
            S(x);
            dp[i][j]=inf;
            if( x==p )px=i,py=j;
            G[ x ].pb( mpp(i,j) );
        }
    }
    fr(i,1,p)random_shuffle( all(G[i]) );
    for(i=1; i<=p; i++) {
        for(j=0; j<SZ(G[i]) && j<3000; j++) {
            int nx=G[i][j].X,ny=G[i][j].Y;
            if( i==1 ) {
                dp[nx][ny]=abs( nx-1 )+abs(ny-1);
                continue;
            }
            for(k=0; k<SZ(G[i-1]) && k<3000; k++) {
                int x=G[i-1][k].X,y=G[i-1][k].Y;
                dp[nx][ny]=min( dp[nx][ny],dp[x][y]+abs( nx-x )+abs(ny-y) );
            }
        }
    }
    printf("%d\n",dp[px][py]);
    return 0;
}