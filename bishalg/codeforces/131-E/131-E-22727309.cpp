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
#define OnBit(n) __builtin_popcount(n)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

///  Digit     0123456789012345678 ///
#define MX     100005
#define inf    2000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///

struct data {
    int x,y,id;
    data() {};
    data(int a,int b,int c) {
        x=a,y=b,id=c;
    }
};
data v[MX+2];
int n,m;

bool Hor(data A,data B) {
    if(A.y==B.y) return A.x<B.x;
    else return A.y<B.y;
}

bool Ver(data A,data B) {
    if(A.x==B.x) return A.y<B.y;
    else return A.x<B.x;
}

bool Diag1(data A,data B) {
    if( A.x+A.y==B.x+B.y ) return A.x<B.x;
    else return (A.x+A.y)<(B.x+B.y);
}

bool Diag2(data A,data B) {
    if( A.x+n-A.y==B.x+n-B.y ) return A.x<B.x;
    else return (A.x+n-A.y)<(B.x+n-B.y);
}

int Ans[MX+2];
int Fr[12];
int main() {
    S2(n,m);
    n+=100;
    ///N*N ChessBoard!!
    for(int i=1; i<=m; i++) {
        S2( v[i].x,v[i].y );
        v[ i ].id=i;
    }
    ///Sort Horizontal;
    sort( v+1,v+m+1, Hor );

    for(int i=2; i<=m; i++) {
        if( v[i-1].y==v[i].y ) {
            Ans[ v[i-1].id ]++;
            Ans[ v[i].id ]++;
        }
    }

    ///Sort Vertical;
    sort( v+1,v+m+1, Ver );

    for(int i=2; i<=m; i++) {
        if( v[i-1].x==v[i].x ) {
            Ans[ v[i-1].id ]++;
            Ans[ v[i].id ]++;
        }
    }

    ///Sort Diag1;
    sort( v+1,v+m+1, Diag1 );

    for(int i=2; i<=m; i++) {
        if( v[i-1].x+v[ i-1].y==v[i].x+v[i].y ) {
            Ans[ v[i-1].id ]++;
            Ans[ v[i].id ]++;
        }
    }

    ///Sort Diag2;
    sort( v+1,v+m+1, Diag2 );

    for(int i=2; i<=m; i++) {
        if( v[i-1].x+n-v[ i-1].y==v[i].x+n-v[i].y ) {
            Ans[ v[i-1].id ]++;
            Ans[ v[i].id ]++;
        }
    }

    for(int i=1;i<=m;i++)Fr[ Ans[i] ]++;

    for(int i=0;i<=8;i++){
        printf("%d ",Fr[i]);
    }

    return 0;
}