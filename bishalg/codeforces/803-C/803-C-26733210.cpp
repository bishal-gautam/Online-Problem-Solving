///==================================================///
///                HELLO WORLD !!                    ///
///                  IT'S ME                         ///
///               BISHAL GAUTAM                      ///
///         [ bsal.gautam16@gmail.com ]              ///
///==================================================///
#include<bits/stdc++.h>
#define PI acos(-1.0)
#define X first
#define Y second
#define mpp make_pair
#define nl printf("\n")
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
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

#define _cin ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Year
///int dx[]= {1,0,-1,0};int dy[]= {0,1,0,-1}; //4 Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
///int dx[]= {2,1,-1,-2,-2,-1,1,2};int dy[]= {1,2,2,1,-1,-2,-2,-1}; //Knight Direction
///==========CONSTANTS=============///
///  Digit     0123456789012345678 ///
#define MX     300005
#define inf    100000000001.0
#define MD     1000000007
#define eps    1e-9
///===============================///
#define lm 1001

ll n,k;
int main() {
    int j,tc;
    ll i;
    //S(tc);
    tc=1;
    while( tc-- ) {
        SL2(n,k);
        ll ok=0;
        ll sq=sqrt(n);
        if(k>=1000000){
            puts("-1");
            continue;
        }
        ll kk=(k*(k+1))/2LL;
        ll mx=0;
        for( i=1; i<=sq; i++) {
            if( n%i==0 ) {
                ll ni=( n/i );
                if( ( n/ni )>=kk ) {
                    ok=ni;
                    mx=max(mx,ok);
                    //break;
                }
                if( n%i==0 ) {
                    ll tot=( n/i );
                    if( tot>=kk ) {
                        ok=i;
                        mx=max(mx,ok);
                       // break;
                    }
                }
            }
        }
        ok=mx;
        if(!ok) printf("-1\n");
        else {
            printf("%lld",ok);
            ll sm=ok;
            for(i=2; i<=k-1; i++) {
                printf(" %lld",(i*ok));
                sm+=(i*ok);
            }
            if( k>1 ) printf(" %lld\n",(n-sm));
        }
    }
    return 0;
}