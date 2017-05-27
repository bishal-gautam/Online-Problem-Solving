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
#define MX     100015
#define inf    1000000010
#define lim    2000000000000000000LL
#define MD     1000000007
#define eps    1e-9
///===============================///

int n,k,ar[66];
ll m,dp[65][2][65];

ll go(int p,int ch,int K) {
    if( p==n ) return (K==k);
    ll &ret=dp[p][ch][K];
    if(ret!=-1) return ret;
    ret=0;
    int mx=ar[p];
    if(ch)mx=1;
    for(int i=0; i<=mx; i++) {
        ret=(ret+go(p+1,ch||i<mx,K+(i==1)));
    }
    return ret;
}

ll Solve(ll nm) {
    n=0;
    for(ll i=63; i>=0; i--) {
        if( nm&(1LL<<i) ) {
            ar[n++]=1;
        } else ar[n++]=0;
        //cout<<ar[n-1];
    }
    return go(0,0,0);
}

bool Ok(ll nm) {
    ll L=nm,R=nm+nm;
    SET(dp);
    ll ans=Solve(R);
    SET(dp);
    //cout<<nm<< " : "<<ans<<endl;
    ans=(ans-Solve(L));
   // cout<<ans<<endl;
    return (ans>=m);
}

int main() {
    ll x,y,i,j;
   // SET(dp);
    while( cin>>m>>k ) {
        ll lo=1,hi=lim,ret;
        while(lo<=hi) {
            ll md=(lo+hi)/2LL;
            if( Ok(md) ) {
                ret=md;
                hi=md-1LL;
            } else lo=md+1LL;
        }
        cout<<ret<< "\n";
    }
    return 0;
}