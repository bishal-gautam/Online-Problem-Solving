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
#define MX     5002
#define inf    2000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

ll dp[101][100002],ar[MX+2];
int k;

ll go(int p,ll n){
    //if( p==k+1 ) return (n);
    if( p==k ) return (n-n/ar[p]);
    if( n<=100000 ){
        ll &ret=dp[p][n];
        if(ret!=-1) return ret;
        ret=go( p+1,n )-go( p+1,n/ar[p] );
        return ret;
    }else{
        return go( p+1,n )-go( p+1,n/ar[p] );
    }
}

int main(){
    ll n;
    SL(n);
    S(k);
    for(int i=1;i<=k;i++){
        SL(ar[i]);
    }
    sort(ar+1,ar+k+1);
    reverse(ar+1,ar+k+1);
    SET(dp);
    ll ans=go(1,n);
    printf("%lld\n",ans);
    return 0;
}