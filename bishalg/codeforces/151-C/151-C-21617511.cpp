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
#define MX     3162280
#define inf    2000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

ll n;
map< ll , bool >dp;

bool go(ll m) {
    if( m<=3 ) return 1;
    if( dp.find( m )!=dp.end() ) return dp[ m ];
    ll sq=sqrt( m );
    dp[ m ]=0;
    int f=0;
    for(ll i=2; i<=sq; i++) {
        if( m%i==0 ) {
            f=1;
            if( !go(i) ) return dp[ m ]=1;
            if( m/i!=i && (!go( m/i ) ) ) return dp[ m  ]=1;
        }
    }
    if(!f)dp[ m ]=1;
    return dp[ m ];
}

int main() {
    SL(n);
    ll sq=sqrt(n);
    int f=2;
    ll vl=-1;
    int ins=0;
    for(ll i=2; i<=sq; i++) {
        if( n%i==0 ) {
            //cout<<i<< " ??\n";
            ins=1;
            if( !go(i) ) {
                vl=i;
                f=1;
                break;
            }
            if( n/i!=i && !go( n/i )  ) {
                vl=n/i;
                f=1;
                break;
            }
        }
        if(f==1)break;
    }
    if(ins==0)f=1,vl=0;
    printf("%d\n",f);
    if(vl!=-1)printf("%lld\n",vl);

    return 0;
}