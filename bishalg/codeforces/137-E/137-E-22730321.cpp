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
#define MX     600015
#define inf    200000001
#define MD     1000000007LL
#define eps    1e-9
///===============================///

inline int Min(int a,int b){
    return (a<b)?a:b;
}

inline int Test(char c) {
    if(c=='a') return -1;
    if(c=='e') return -1;
    if(c=='i') return -1;
    if(c=='o') return -1;
    if(c=='u') return -1;
    return 2;
}

char s[MX+2];
int Ofs=200001;
int n,dp[MX+2],BIT[MX+5];

void add(int p,int v) {
    for(int i=p; i<=MX; i+=i&-i)BIT[i]=Min(BIT[i],v);
}

int read(int p) {
    int ret=n+1;
    for(int i=p; i>0; i-=i&-i)ret=Min(ret,BIT[i]);
    return ret;
}

int main() {
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=0; i<=MX; i++)BIT[i]=n+1;
    int mx=0,cnt=0;
    dp[0]=0;
    add(Ofs,0);
    for(int i=1; i<=n; i++) {
        s[i]=tolower(s[i]);
        dp[i]=( dp[i-1]+Test( s[i] ) );
        int vl=dp[i]+Ofs;
        int id=read(vl);
        if( id<i ) {
            int gp=( i-id );
            if( gp==mx ) {
                cnt++;
            } else if( gp>mx ) {
                mx=gp;
                cnt=1;
            }
        }
        add( vl,i );
    }
    if( mx==0 ) printf("No solution\n");
    else printf("%d %d\n",mx,cnt);

    return 0;
}