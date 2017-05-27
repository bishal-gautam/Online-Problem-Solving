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

int n,ar[MX+2];
int dp[MX+2];
int main() {
    int i,j,tc;
    //S(tc);
    tc=1;
    while( tc-- ) {
        S(n);
        for(i=1;i<=n;i++){
            S(ar[i]);
        }
        int lst=1000000000;
        for(i=1;i<=n;i++){
            if( ar[i]==0 )lst=i;
            dp[ i ]=abs( i-lst );
        }
        lst=1000000000;
        for(i=n;i>=1;i--){
            if(ar[i]==0)lst=i;
            dp[i]=min( dp[i],abs(i-lst) );
        }
        printf("%d",dp[1]);
        for(i=2;i<=n;i++){
            printf(" %d",dp[i]);
        }
        nl;
    }
    return 0;
}