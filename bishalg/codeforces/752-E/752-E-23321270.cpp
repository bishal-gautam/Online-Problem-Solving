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
#define MX     1000001
#define MD     100007LL
#define inf    2000000010
#define eps    1e-9
///===============================///

int n,k,m,ar[MX+5];
ll dp[(MX*10)+5];
int kk=1,vis[(MX*10)+5];

ll go(int p) {
    if( p<m ) return 0;
    if( p==m || (p/2)<m ) return 1;
    ll &ret=dp[p];
    if(vis[p]==kk) return ret;
    vis[p]=kk;
    ret=( go(p/2)+go((p+1)/2) );
    return ret;
}

bool Ok( ) {
    ++kk;
    ll sm=0LL;
    for(int i=1; i<=n; i++) {
        sm+=go( ar[i] );
        if( sm>=k )return true;
    }
    return (sm>=k);
}

int main() {
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++) {
        S(ar[i]);
    }
    sort(ar+1,ar+n+1,greater<int>());
    int lo=1;
    int hi=ar[1];
    int ret=-1;
    while(lo<=hi) {
        m=(lo+hi)/2;
        if( Ok( ) ) {
            ret=m;
            lo=m+1;
        } else hi=m-1;
    }
    printf("%d\n",ret);
    return 0;
}