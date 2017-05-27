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
#define MX     1000005
#define inf    2000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

int lft[MX+2],rgt[MX+2],ar[MX+2],Fr[MX+2],FrL[MX+2];
int main() {
    int n,i,j,k,x,y;
    S(n);
    for(i=1; i<=n; i++) {
        S2(x,y);
        Fr[x]++;
        FrL[x]++;
        Fr[y]++;
        rgt[x]=y;
        lft[y]=x;
    }
    if( n%2==0 ) {
        int bg=rgt[0];
        for(i=2; ; i+=2) {
            if(bg==0 || i>n )break;
            ar[i]=bg;
            bg=rgt[ bg ];
        }
        int ed=lft[0];
        for(i=n-1; ; i-=2) {
            if(ed==0 || i<0 )break;
            ar[i]=ed;
            ed=lft[ ed ];
        }
    } else {
        int bg=rgt[0];
        for(i=2; ; i+=2) {
            if(bg==0 || i>n )break;
            ar[i]=bg;
            bg=rgt[ bg ];
        }
        for(i=1; i<=MX-2; i++) {
            if( Fr[i]==1 && FrL[i]==1 ) {
                bg=i;
                break;
            }
        }
        for(i=1; ; i+=2) {
            if(bg==0 || i>n )break;
            ar[i]=bg;
            bg=rgt[ bg ];
        }
    }
    for(i=1; i<=n; i++) {
        printf("%d ",ar[i]);
    }
    nl;

    return 0;
}