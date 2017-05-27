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
#define MX     500002
#define inf    10000000000
#define MD     1000000007
#define eps    1e-9
///===============================///

int n,ar[MX+2];
map<int,int>Mp;
vector<int>v;
int main() {
    S(n);
    fr(i,1,n){
       S(ar[i]);
    }
    int st=1;
    fr(i,1,n){
        Mp[ ar[i] ]++;
        if( Mp[ ar[i] ]==2 ){
            Mp.clear();
            v.pb( st );
            v.pb( i );
            st=i+1;
        }
    }
    if( st==1 )printf("-1\n");
    else{
        int m=SZ( v );
        if( st!=n+1 ){
            v.pop_back();
            v.pb(n);
        }
        printf("%d\n",m/2);
        for(int i=0;i<m;i+=2){
            printf("%d %d\n",v[i],v[i+1]);
        }
    }
    return 0;
}