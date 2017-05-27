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
#define MX     500002
#define inf    2000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

ll ar[MX+2],n,x,y;
map<ll,ll>MP;
int main(){
    while( SL(n)==1 ){
        MP.clear();
        fr(i,1,n){
            SL(x);
            MP[ x ]++;
        }
        ll cnt=0,k=0;
        for(map<ll,ll> :: iterator it=MP.begin();it!=MP.end();it++){
            ll x=(*it).X;
            ll y=(*it).Y;
            //cout<<x<< " && "<<y<<endl;
            //if( k>=10 )break;
           // k++;
            if( y%2==0 )cnt++;
            ll vl=y/2;
            if( vl || MP.find(x+1)!=MP.end() ){
               // cout<<(MP[x+1]+(y/2))<< " ?? \n";
                MP[ x+1 ]+=(y/2LL);
            }
        }
        ll pv=-1,sm=0;
        for(map<ll,ll> :: iterator it=MP.begin();it!=MP.end();it++){
            ll x=(*it).X;
           // cout<<x<< " && "<<pv<<endl;
            sm+=( x-pv-1 );
            pv=x;
        }
        printf("%lld\n",sm+cnt);
    }
    return 0;
}