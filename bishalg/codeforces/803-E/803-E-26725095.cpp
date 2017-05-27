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
#define MX     3005
#define inf    100000000001.0
#define MD     1000000007
#define eps    1e-9
///===============================///
#define lm 1001

char s[MX+2];
int n,k,dp[lm+2][MX+2];

int go(int p,int d) {
    if( p==n ) return (abs(lm-d)==k);
    if( (abs(lm-d)>=k ) ) return 0;
    int &ret=dp[ p ][ d ];
    if(ret!=-1) return ret;
    ret=0;
    if( s[p]=='?' ) {
        ret=(ret|| go( p+1,d ) );
        ret=(ret|| go( p+1,d+1 ) );
        ret=(ret|| go( p+1,d-1 ) );
    } else if( s[p]=='W' ) {
        ret=(ret|| go(p+1,d+1) );
    } else if( s[p]=='L' ) {
        ret=(ret||go(p+1,d-1) );
    } else ret=(ret||go(p+1,d));

    return ret;
}

string ss;

int po(int p,int d) {
    if( p==n ) return (abs(lm-d)==k);
    if( (abs(lm-d)>=k ) ) return 0;
    int &ret=dp[ p ][ d ];
    // if(ret!=-1) return ret;
    //ret=0;
    if( s[p]=='?' ) {
        if(ret== go( p+1,d ) ) {
            ss+="D";
            po( p+1,d );
            return 0;
        }
        if( ret== go( p+1,d+1 ) ) {
            ss+="W";
            po( p+1,d+1 );
            return 0;
        }
        if( ret==go(p+1,d-1) ) {
            ss+="L";
            po( p+1,d-1 );
            return 0;
        }
    } else if( s[p]=='W' ) {
        if( ret== go(p+1,d+1) ) {
            ss+="W";
            po( p+1,d+1 );
            return 0;
        }
    } else if( s[p]=='L' ) {
        if( ret==go(p+1,d-1) ) {
            ss+="L";
            po( p+1,d-1 );
            return 0;
        }
    } else {
        if(ret==go(p+1,d)) {
            ss+="D";
            po( p+1,d );
            return 0;
        }
    }
    return ret;
}

int main() {
    int i,j,tc;
    //S(tc);
    tc=1;
    while( tc-- ) {
        S2(n,k);
        scanf("%s",s);
        SET(dp);
        int ans=go( 0,lm );
        if(ans) {
            ss="";
            po(0,lm);
            //cout<<ss<<endl;
            printf("%s\n",ss.c_str());
        } else printf("NO\n");
    }
    return 0;
}