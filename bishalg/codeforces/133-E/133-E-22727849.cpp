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
#define MX     100005
#define inf    200000001
#define MD     1000000007LL
#define eps    1e-9
///===============================///

char s[102];
int n,m;
int dp[102][402][52][2];

int go(int p,int d,int c,int f) {
    if( c>m ) return -inf;
    if( p==n ) {
        if( c==m ) return abs(200-d);
        else return -inf;
    }
    int &ret=dp[p][d][c][f];
    if(ret!=-1) return ret;
    ret=-inf;
    if( s[p]=='T' ) {
        for(int i=0; i+c<=m; i+=2) {
            ret=max(ret, go(p+1,d,c+i,f^1) );
        }
        for(int i=1; i+c<=m; i+=2) {
            if(!f) ret=max( ret, go(p+1,d+1,c+i,f) );
            else ret=max( ret, go(p+1,d-1,c+i,f) );
        }
    } else if( s[p]=='F') {
        for(int i=0; i+c<=m; i+=2) {
            if( !f )ret=max(ret, go(p+1,d+1,c+i,f) );
            else ret=max(ret, go(p+1,d-1,c+i,f) );
        }
        for(int i=1; i+c<=m; i+=2) {
            ret=max(ret, go(p+1,d,c+i,f^1) );
        }
    }
    return ret;
}

int main() {
    scanf("%s",s);
    S(m);
    n=strlen(s);
    //cout<<n<<endl;
    SET(dp);
    int ans=go(0,200,0,0);
    printf("%d\n",ans);
    return 0;
}