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
#define OnBit(i) __builtin_popcount(i)
///-----------------------------------
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
typedef unsigned long long ull;

///  Digit     0123456789012345678 ///
#define MX     5000005
#define inf    2000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///

int n,lim,ar[MX+2];
int dp[MX+2];
int main() {
    int x;
    S(n);
    lim=(1<<22)-1;
    for(int i=1;i<=n;i++){
        S(x);
        ar[i]=x;
        dp[x]=x;
    }
    for(int i=0;i<22;i++){
        for(int j=0;j<=lim;j++){
            if( j&(1<<i) ){
                if(!dp[j]) dp[j]=dp[ j^(1<<i) ];
            }
        }
    }
    for(int i=1;i<=n;i++){
        if( dp[ lim^ar[i] ] )printf("%d ",dp[ lim^ar[i] ]);
        else printf("-1 ");
    }
    nl;
    return 0;
}