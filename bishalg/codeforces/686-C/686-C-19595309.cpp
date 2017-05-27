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

int Dgt(int n) {
    if(n==0)return 1;
    int ret=0;
    while(n) {
        ret++;
        n/=7;
    }
    return ret;
}
int main() {
    int n,m,i,j,x,y;
    while( S2(n,m)==2 ) {
        int d1=Dgt(n-1);
        int d2=Dgt(m-1);
        if( d1+d2>7 ) {
            printf("0\n");
            continue;
        }
        int d=d1+d2,cnt=0;
        int lim=(1<<7)-1;
        for(i=0; i<=lim; i++) {
            int bp=__builtin_popcount(i);
            if( bp!=d )continue;
            int ar[8],k=0;
            for(j=0; j<7; j++) {
                if( i&(1<<j) )ar[ k++ ]=j;
            }
            sort( ar,ar+k );
            do {
                ll nm1=0,nm2=0;
                for(j=0; j<d1; j++)nm1=nm1*7LL+ar[j];
                for(j=d1; j<k; j++)nm2=nm2*7LL+ar[j];
                if( nm1<n && nm2<m )cnt++;
            } while( next_permutation(ar,ar+k) );
        }
        printf("%d\n",cnt);
    }
    return 0;
}