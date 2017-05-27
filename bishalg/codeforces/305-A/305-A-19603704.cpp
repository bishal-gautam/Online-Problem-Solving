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
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Year
///int dx[]= {1,0,-1,0};int dy[]= {0,1,0,-1}; //4 Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
///int dx[]= {2,1,-1,-2,-2,-1,1,2};int dy[]= {1,2,2,1,-1,-2,-2,-1}; //Knight Direction
///==========CONSTANTS=============///
///  Digit     0123456789012345678 ///
#define MX     202
#define MXX    1000005
#define inf    2000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

int ar[MX+2];
//int OK[MX+2];
//
//int ok(int x) {
//    if(x==0) return 1;
//    while( x ) {
//        if( x%10==0 ) return 1;
//        x/=10;
//    }
//    return 0;
//}
vector<int>v;
int main() {
    int n,i,j,k,x;
    S(n);
    int z=0,h=0,d=0,on=0,othr=0;
    fr(i,1,n) {
        S(x);
        ar[i]=x;
        if( x==100 ) h=100;
        else if( x==0 ) z=1;
        else if( x%10==0 ) d=x;
        else if(x>=1 && x<10)on=x;
        else othr=x;
    }
    if(z)v.pb(0);
    if(on)v.pb(on);
    if(d)v.pb(d);
    if(h)v.pb(h);
    int sz=SZ(v);
    if(!sz)printf("1\n%d\n",ar[1]);
    else {
        if(h && (!d&&!on) && othr )v.pb( othr );
        if(z && (!d&&!on&&!h) && othr )v.pb( othr );
        sz=SZ(v);
        printf("%d\n",sz);
        for(i=0;i<sz;i++){
            printf("%d ",v[i]);
        }
        nl;
    }
    return 0;
}