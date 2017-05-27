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

const int LN=34;
int n,P[MX+2][35],Min[MX+2][35];
ll k,Sum[MX+2][35];
ll sm,mn;

void Solve(int x,ll K) {
    for(int j=0; j<LN; j++) {
        if(K&(1LL<<j)) {
            sm+=Sum[x][j];
            mn=min(mn,(ll)Min[x][j]);
            x=P[x][j];
        }
    }
}

void go() {
    for(int j=1; j<LN; j++) {
        for(int i=1; i<=n; i++) {
            P[i][j]=P[ P[i][j-1] ][ j-1 ];
            Sum[i][j]=Sum[i][j-1]+Sum[ P[i][j-1] ][ j-1 ];
            Min[i][j]=min(Min[i][j-1],Min[ P[i][j-1] ][ j-1 ]);
        }
    }
}

int main() {
    int i,j,x;
    S(n);
    SL(k);
    for(i=1; i<=n; i++) {
        S(x);
        P[i][0]=x+1;
    }
    for(i=1; i<=n; i++) {
        S(x);
        Sum[i][0]=x;
        Min[i][0]=x;
    }
    go();
    for(i=1; i<=n; i++) {
        mn=inf,sm=0;
        Solve(i,k);
        printf("%lld %lld\n",sm,mn);
    }
    return 0;
}