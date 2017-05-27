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
#define MX     501
#define inf    200000001
#define MD     1000000007LL
#define eps    1e-9
///===============================///

bool dp[MX][MX][MX];
bool vis[MX];
int ar[MX+2];

void go(int p,int k,int v){
    if( p==0 ){
        if( k==0 && v<=500 )vis[ v ]=1;
        return;
    }
    if( k<0 )return;
    bool &ret=dp[p][k][v];
    if(ret) return;
    ret=1;
    go(p-1,k,v);
    go(p-1,k-ar[p],v);
    go(p-1,k-ar[p],v+ar[p]);
}

int main() {
    int n,k;
    S2(n,k);
    for(int i=1;i<=n;i++)S(ar[i]);
    CLR(vis);
    go(n,k,0);
    int cnt=0;
    for(int i=0;i<=k;i++){
        if(vis[i])cnt++;
    }
    printf("%d\n",cnt);
    for(int i=0;i<=k;i++){
        if(vis[i])printf("%d ",i);
    }
    nl;
    return 0;
}