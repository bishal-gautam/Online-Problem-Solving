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
#define MX     100001
#define inf    2000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

int ar[MX+2];
vector<int>v;
int main(){
    int n,i,j;
    S(n);
    int mx=0;
    fr(i,1,n){
        S(ar[i]);
    }
    int ok=0;
    for(i=31;i>=0;i--){
        v.clear();
        int ad=(1<<31);
        ad--;
        int f=0;
        for(j=1;j<=n;j++){
            if( ar[j]&(1<<i) ){
                v.pb( ar[j] );
                f=1;
                ad&=ar[j];
            }
        }
        if(f && ad%(1<<i)==0 ){
            ok=1;
            int sz=SZ(v);
            printf("%d\n",sz);
            for(j=0;j<sz;j++){
                printf("%d ",v[j]);
            }
            break;
        }
    }
    if(!ok)printf("-1\n");

    return 0;
}