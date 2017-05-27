///==================================================///
///                HELLO WORLD !!                    ///
///             IT'S ME BISHAL GAUTAM                ///
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

///  Digits    0123456789012345678 ///
#define MX     500005
#define inf    1000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///

vector<int>v;
int main() {
    int n,i,j,k,x;
    while( S(n)==1 ) {
        v.clear();
        for(i=1;i<=n;i++){
            S(x);
            v.pb(x);
        }
        sort( all(v) );
        v.resize( unique(all(v))-v.begin() );
        int sz=SZ(v);
        if( sz<=2 ) printf("Yes\n");
        else{
            if(sz>=4)printf("No\n");
            else if( v[1]-v[0]==v[2]-v[1] ) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}