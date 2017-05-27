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
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
///--------------------------------------
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define fr(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
typedef long long ll;
///==========CONSTANTS=============///
///  Digit     0123456789012345678 ///
#define MX     301
#define inf    20000000000000LL
#define MD     1000000000LL
#define eps    1e-9
///===============================///
int n,m,k;
ll dp[MX+1][MX+1],cst[MX+1][MX+1];

ll go(int p,int c) {
    if(c>=k) return 0;
    if(p>n) return inf;
    ll &ret=dp[p][c];
    if( ret!=-1 ) return ret;
    ret=go(p+1,c);
    for(int i=p; i<=n; i++) {
        ret=min( ret, cst[p][i]+go( i+1, c+(i-p+1) ) );
    }
    return ret;
}

int main() {
    while( S3(n,m,k)==3 ) {
        fr(i,1,n)fr(j,1,n)cst[i][j]=inf;
        fr(i,1,m) {
            int x,y;
            ll z;
            S2(x,y);
            SL(z);
            fr(j,x,y)cst[x][j]=min( cst[x][j],z );
        }
        SET(dp);
        ll ans=go(1,0);
        if(ans>=inf )ans=-1LL;
        printf("%lld\n",ans);
    }
    return 0;
}