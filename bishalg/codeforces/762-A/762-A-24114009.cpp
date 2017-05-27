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
typedef unsigned long long ull;
///==========CONSTANTS=============///
///  Digit     0123456789012345678 ///
#define MX     2005
#define inf    1000000010
#define MD     1000000007LL
#define MD2    1000000006LL
#define eps    1e-9
///===============================///

ll n,k;
vector<ll>v;
int main() {
    SL2(n,k);
    ll sq=sqrt(n);
    for(ll i=1;i<=sq;i++){
        if( n%i==0 ){
            v.pb( i );
            if( i!=(n/i) ) v.pb( n/i );
        }
    }
    //cout<<SZ(v)<<endl;
    sort( all(v) );
    int sz=SZ(v);
    if(sz>=k){
        printf("%lld\n",v[ k-1 ]);
    }
    else printf("-1\n");
    return 0;
}