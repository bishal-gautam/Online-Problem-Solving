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
#define MX     2000001
#define inf    2000000010
#define MD     1000000007
#define eps    1e-9
///===============================///


ll a[MX+2],b[MX+2];
ll ta,tb;

int main(){
    int n,i,j;
    cin>>n;
    ta=tb=0;
    for(i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        ta+=a[i];
        tb+=b[i];
    }
    ll mx=abs(ta-tb),id=0;
    for(i=1;i<=n;i++){
        ll ta2=ta,tb2=tb;
        ta2-=a[i];
        tb2-=b[i];
        ta2+=b[i];
        tb2+=a[i];
        if( abs(ta2-tb2)>mx ){
            mx=abs( ta2-tb2 );
            id=i;
        }
    }
    cout<<id<<endl;
    return 0;
}