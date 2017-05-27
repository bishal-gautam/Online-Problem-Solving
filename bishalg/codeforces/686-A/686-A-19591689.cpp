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
#define piii pair< int ,pair<int,int> >
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
#define UNIK(v) sort(all(v)),v.resize( unique(all(v)) -v.begin() );
using namespace std;
typedef long long ll;
///==========CONSTANTS=============///
///  Digit     0123456789012345678 ///
#define MX     100005
#define inf    1000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///
#define min(a,b) ((a<b)?a:b)

int main(){
    int n,i,j,k,x;
    ll sm;
    //_cin;
    cin>>n>>x;
    sm=x;
    int d=0;
    while(n--){
        string s;
        cin>>s>>x;
        if(s[0]=='+'){
            sm+=x;
        }else{
            if(x<=sm)sm-=x;
            else d++;
        }
    }
    cout<<sm<< " "<<d<< "\n";
    return 0;
}