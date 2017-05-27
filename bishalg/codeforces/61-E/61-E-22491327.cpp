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
///==========CONSTANTS=============///
///  Digit     0123456789012345678 ///
#define MX     1000002
#define inf    1000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

int n,ar[MX+2];
ll BIT[2][MX+2];

void add(int id,int p,ll v){
    for(int i=p;i<=MX;i+=i&-i)BIT[id][i]+=v;
}

ll read(int id,int p){
    ll ret=0;
    for(int i=p;i>0;i-=i&-i)ret+=BIT[id][i];
    return ret;
}

vector<int>v;
int main() {
    int i,j,k;
    S(n);
    for(i=1;i<=n;i++){
        S(ar[i]);
        v.pb( ar[i] );
    }
    sort( all(v) );
    v.resize( unique( all(v) ) -v.begin() );
    for(i=1;i<=n;i++){
        ar[i]=lower_bound( all(v) ,ar[i] )-v.begin()+1;
    }
    ll ans=0LL;
    for(i=n;i>=1;i--){
        ///calculate ans;
        ans+=read( 1,ar[i]-1 );
        ll xx=read( 0,ar[i]-1 ); ///Strictly Less
        add( 1,ar[i],xx );
        add( 0,ar[i],+1 );
    }
    printf("%lld\n",ans);

    return 0;
}