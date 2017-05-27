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
#define MX     2005
#define inf    1000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///
#define min(a,b) ((a<b)?a:b)

vector<int>v;
int ar[MX+2];
int br[MX+2];
int main(){
    int n,i,j,k,x;
    S(n);
    fr(i,1,n)S(ar[i]),br[i]=ar[i];
    v.clear();
    sort(br+1,br+n+1);
    for(i=1;i<=n;i++){
        //cout<<ar[i]<< " ";
        for(j=i+1;j<=n;j++){
            if( br[i]==ar[j] ){
                int p=j;
                while( p>=i+1 ){
                    v.pb(p-1);
                    v.pb(p);
                    //printf("%d %d\n",p-1,p);
                    swap(ar[p-1],ar[p]);
                    p--;
                }
                break;
            }
        }
    }
    for(i=1;i<=n;i++){
        assert( ar[i]==br[i] );
    }
    int sz=SZ(v);
    assert(sz<=40000);
    for(i=1;i<sz;i+=2){
        cout<<v[i-1]<< " "<<v[i]<< "\n";
    }
    return 0;
}