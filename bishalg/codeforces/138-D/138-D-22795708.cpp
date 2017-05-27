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
#define MX     42
#define inf    2000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///

int r,c,f;
char s[MX][MX];
short dp[41][41][41][41];
/*
   lx, rx -->  \
   ly,ry --->  /
*/
short go(int lx,int rx,int ly,int ry){
    short &ret=dp[lx][rx][ly][ry];
    if(ret!=-1) return ret;
    set<short>St;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if( ((i+j)%2)!=f )continue;
            int x=(i+j)+1;
            int y=(i+(c-1)-j)+1;
            if( x<=lx || x>=rx || y<=ly || y>=ry )continue;
            short g=0;
            if( s[i][j]=='L' ){
                g^=go(lx,x,ly,ry);
                g^=go(x,rx,ly,ry);
            }
            else if( s[i][j]=='R' ){
                g^=go(lx,rx,ly,y);
                g^=go(lx,rx,y,ry);
            }
            else{
                g^=go(lx,x,ly,y);
                g^=go(lx,x,y,ry);

                g^=go(x,rx,ly,y);
                g^=go(x,rx,y,ry);
            }
            St.insert( g );
        }
    }
    short mn=0;
    for(set<short>::iterator it=St.begin();it!=St.end();it++){
        if( (*it)!=mn )break;
        mn++;
    }
    return (ret=mn);
}

int main() {
    S2(r,c);
    for(int i=0;i<r;i++){
        scanf("%s",s[i]);
    }
    SET(dp);
    f=0;
    int ans=go(0,r+c,0,r+c);
    SET(dp);
    f=1;
    ans^=go(0,r+c,0,r+c);
    if(ans) printf("WIN\n");
    else printf("LOSE\n");
    return 0;
}