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
#define OnBit(n) __builtin_popcount(n)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

///  Digit     0123456789012345678 ///
#define MX     1005
#define inf    2000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///

int n,m,lim;
short dp[41][7][64][64][64];
short go(int r,int c,int m1,int m2,int m3) {
    short &ret=dp[r][c][m1][m2][m3];
    if(ret!=-1) return ret;
    if( c==m ) {
        if( r==n-1 ) return ret=2*m-OnBit(m1)-OnBit(m2);
        else return ret=m-OnBit(m1)+go(r+1,0,m2,m3,0);
    } else {
        ret=go( r,c+1,m1,m2|(1<<c),m3 );
        if(c>0 ) ret=max( ret, go(r,c+1,m1,m2|(1<<(c-1)),m3) );
        if(c+1<m ) ret=max( ret, go(r,c+1,m1,m2|(1<<(c+1)),m3) );
        if(r>0 ) ret=max( ret, go(r,c+1,m1|(1<<c),m2,m3) );
        if(r+1<n ) ret=max( ret, go(r,c+1,m1,m2,m3|(1<<c)) );
    }
    return ret;
}

int main() {
    S2(n,m);
    if( n<m )swap(n,m);///Row Grter, Col Less;
    SET(dp);
    lim=(1<<m)-1;
   // cout<<lim<<endl;
    int ans=go(0,0,lim,0,0);
    printf("%d\n",ans);
    return 0;
}