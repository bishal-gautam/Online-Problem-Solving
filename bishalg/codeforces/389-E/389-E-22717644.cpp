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

///  Digit     0123456789012345678 ///
#define MX     1005
#define inf    2000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///

vector<int>v;
int ar[MX];
int main() {
    int n,m,a=0,b=0;
    S(n);
    while(n--) {
        S(m);
        for(int i=1; i<=m; i++) {
            S(ar[i]);
        }
        int md=(m+1)/2;
        for(int i=1; i<=m; i++) {
            if(i<=md)a+=ar[i];
            else b+=ar[i];
        }
        if( m&1 ) {
            v.pb( ar[ md ] );
            a-=ar[ md ];
        }
    }
    sort( all(v) );
    reverse( all(v) );
    int sz=SZ(v),f=1;
    for(int i=0;i<sz;i++){
        if(f)a+=v[ i ],f=0;
        else b+=v[ i ],f=1;
    }

    printf("%d %d\n",a,b);

    return 0;
}