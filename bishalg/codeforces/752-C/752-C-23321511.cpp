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
#define MX     1000001
#define MD     100007LL
#define inf    2000000010
#define eps    1e-9
///===============================///

string s;
int main() {
    int n;
    cin>>n>>s;
    int cnt=1,x=0,y=0,px=0,py=0,lx,ly,d=0;
    for(int i=0;i<n;i++){
        if(s[i]=='U')y++;
        if(s[i]=='D')y--;
        if(s[i]=='L')x--;
        if(s[i]=='R')x++;
        d++;
        if( abs(x-px)+abs(y-py)!=d ){
            px=lx,py=ly;
            d=1;
            cnt++;
        }
        lx=x;
        ly=y;
    }
    cout<<cnt<<endl;

    return 0;
}