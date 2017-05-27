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
#define MX     10005
#define inf    2000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///

int n;
ll dp[(1<<24)+5];
char s[5];
int main(){
    S(n);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        int msk=0;
        msk|=(1<<(s[0]-'a'));
        msk|=(1<<(s[1]-'a'));
        msk|=(1<<(s[2]-'a'));
        dp[msk]++;
    }
    int lim=(1<<24)-1;
    for(int i=0;i<24;i++){
        for(int j=0;j<=lim;j++){
            if(j&(1<<i))dp[j]+=dp[j^(1<<i)];
        }
    }
    ll xr=0LL;
    for(int i=0;i<=lim;i++){
        ll ans=( n-dp[ i^lim ]);
        xr^=(ans*ans);
    }
    printf("%lld\n",xr);

    return 0;
}