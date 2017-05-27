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
///==========CONSTANTS=============///
///  Digit     0123456789012345678 ///
#define MX     2000005
#define inf    1000000010
#define MD     1000000007LL
#define MD2    1000000006LL
#define eps    1e-9
///===============================///

ll a,b,c;
ll ar[MX+2];
ll br[MX+2];
char s[22];
int main() {
    int i,n,m;
    SL2(a,b);
    SL(c);
    S(m);
    int la=0,lb=0;
    while(m--){
        S(n);
        scanf("%s",s);
        if( s[0]=='U' )ar[ la++ ]=n;
        else br[ lb++ ]=n;
    }
    int ca=0,cb=0;
    sort(ar,ar+la);
    sort(br,br+lb);
   // cout<<la<< " && "<<lb<<endl;
//    fr(i,0,la-1){
//        cout<<ar[ i ]<<endl;
//    }
//    fr(i,0,lb-1){
//        cout<<br[ i ]<<endl;
//    }
    ll sm=0LL;
    int ka=0;
    while(a-- && ka<la ){
         sm+=ar[ ka ];
         ka++;
        // if( ka>=la )break;
    }
    int kb=0;
    while(b-- && kb<lb ){
         sm+=br[ kb ];
         kb++;
         //if( kb>=lb )break;
    }
    while( c-- ){
        if( ka<la && kb<lb ){
            if( ar[ka]<br[ kb ] ){
                sm+=ar[ ka ];
                ka++;
            }
            else {
                sm+=br[ kb ];
                kb++;
            }
        }
        else if( ka<la ){
            sm+=ar[ ka ];
            ka++;
        }else if( kb<lb ){
            sm+=br[ kb ];
            kb++;
        }else break;
    }
    printf("%d %lld\n",(ka+kb),sm);

    return 0;
}