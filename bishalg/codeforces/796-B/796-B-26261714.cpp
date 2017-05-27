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
#define MX     2000003
#define inf    1000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

ll ar[MX+2];
ll br[MX+2];
int main() {
    _cin;
    ll i,j,k,n,m,q,x,y,z,a,b,c,d;
    SL2(n,m);
    SL(k);
    ar[ 1 ]=1;
    int ok=0;
    fr(i,1,m) {
        SL(x);
        if( x==1 ) {
            ok=1;
        }
        br[ x ]=1;
    }
    while( k-- ) {
        SL2(x,y);
        swap( ar[x],ar[y] );
        if( ok )break;
        if( ar[x]==1 && br[ x ]==1 ) {
            ok=x;
            break;
        }
        if( ar[y]==1 && br[ y ]==1 ) {
            ok=y;
            break;
        }
    }
    if( ok ) printf("%d\n",ok);
    else {
        fr(i,1,n) {
            if( ar[i]==1 ) {

                printf("%d\n",i);
                break;
            }
        }
    }


    return 0;
}