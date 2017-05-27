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
#define MX     1000000
#define inf    2000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///

int dp[MX+5];
map<ll,ll>Sm[MX+5];

//int go(ll x) {
//    if(!x) return 0;
//    int &ret=dp[x];
//    if(ret!=-1)return ret;
//    ll sq=sqrt(x);
//    if(sq==x)sq--;
//    ll sqq=sqrt(sq);
//    while( (sqq*sqq*sqq*sqq)<x )sqq++;
//    set<int>St;
//    for(ll i=sqq; i<=sq; i++) {
//        St.insert( go(i) );
//    }
//    int mn=0;
//    while(St.count(mn))mn++;
//    return ret=mn;
//}

int main() {
    int n;
    Sm[0][0]=1;
    Sm[1][0]=2;
    dp[0]=dp[1]=0;
    for(ll i=2; i<=MX; i++) {
        ll x=i;
        ll sq=sqrt(x);
        ll sqq=sqrt(sq);
        while( (sqq*sqq*sqq*sqq)<x )sqq++;
        //cout<<i<< " "<<sqq<< " to "<<sq<<endl;
        int mn=0;
        if( sqq<=sq ) {
            while( (Sm[sq][mn]-Sm[sqq-1][mn]) )mn++;
        }
        Sm[i]=Sm[i-1];
        Sm[i][mn]++;
        dp[i]=mn;
        // cout<<i<< " => "<<mn<<endl;
    }
    ll x;
    S(n);
    ll xr=0;
    for(int i=1; i<=n; i++) {
        SL(x);
        if(x<=MX)xr^=dp[x];
        else {
            ll sq=sqrt(x);
            ll sqq=sqrt(sq);
            while( (sqq*sqq*sqq*sqq)<x )sqq++;
            int mn=0;
            if( sqq<=sq ) {
                while( (Sm[sq][mn]-Sm[sqq-1][mn]) )mn++;
            }
            xr^=mn;
        }
    }
    if(xr)printf("Furlo\n");
    else printf("Rublo\n");
    return 0;
}