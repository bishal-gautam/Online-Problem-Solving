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
typedef unsigned long long ull;
///==========CONSTANTS=============///
///  Digit     0123456789012345678 ///
#define MX     200005
#define inf    1000000010
#define MD     1000000007LL
#define MD2    1000000006LL
#define eps    1e-9
///===============================///

char a[MX + 2];
char b[MX + 2];
int n, m;
int Lft[MX + 2];
int Rgt[MX + 2];

int main() {
    int i, j, k;
    scanf ( "%s", a );
    scanf ( "%s", b );
    n = strlen ( a );
    m = strlen ( b );

    fr ( i, 0, m - 1 ) Lft[ i ] = n;
    fr ( i, 0, m - 1 ) Rgt[ i ] = -1;
    j=0;
    int mn=m, id = -2;
    for ( i = 0; i < n && j < m; i++ ) {
        if ( a[i] == b[j] ) {
            Lft[ j ] = i;
            j++;
        }
    }
    if ( ( m - j ) < mn ) {
        mn = ( m - j );
        id = -1;
    }
    j = m - 1;
    for ( i = n - 1; i >= 0 && j >= 0; i-- ) {
        if ( a[i] == b[j] ) {
            Rgt[ j ] = i;
            j--;
        }
    }
    if ( (j+1) < mn ) {
        mn = ( 1+j );
        id = m;
    }
    for ( i = 0; i < m; i++ ) {
        int lf = Lft[ i ];
        if ( lf >= n ) break;
        int lo = i + 1, hi = m - 1, ret = inf;
        while ( lo <= hi ) {
            int md = ( lo + hi ) / 2;
            if ( Rgt[md] > lf ) {
                hi = md - 1;
                ret = min ( ret, md );
            } else {
                lo = md + 1;
            }
        }
        if ( ret != inf ) {
            int gp = ( ret - i - 1 );
            if ( gp < mn ) {
                mn=gp;
                id = i;
            }
        }
    }
    if( mn==m ){
        printf("-\n");
        return 0;
    }
    fr ( i, 0, m - 1 ) Lft[ i ] = n;
    fr ( i, 0, m - 1 ) Rgt[ i ] = -1;
    j=0;
    for ( i = 0; i < n && j < m; i++ ) {
        if ( a[i] == b[j] ) {
            Lft[ j ] = i;
            j++;
        }
    }
    if ( ( m - j )==mn ) {
          for(i=0;i<j;i++)printf("%c",b[i]);
          nl;
          return 0;
    }
    j = m - 1;
    for ( i = n - 1; i >= 0 && j >= 0; i-- ) {
        if ( a[i] == b[j] ) {
            Rgt[ j ] = i;
            j--;
        }
    }
    if ( 1+j== mn ) {
        int p = ( 1+j );
        for(i=p;i<m;i++) printf("%c",b[i]);
        nl;
        return 0;
    }
    for ( i = 0; i < m; i++ ) {
        int lf = Lft[ i ];
        if ( lf >= n ) break;
        int lo = i + 1, hi = m - 1, ret = inf;
        while ( lo <= hi ) {
            int md = ( lo + hi ) / 2;
            if ( Rgt[md] > lf ) {
                hi = md - 1;
                ret = min ( ret, md );
            } else {
                lo = md + 1;
            }
        }
        if ( ret != inf ) {
            int gp = ( ret - i - 1 );
            if ( gp == mn ) {
                for(k=0;k<=i;k++){
                    printf("%c",b[k]);
                }
                for(k=ret;k<m;k++){
                    printf("%c",b[k]);
                }
                nl;
                return 0;
            }
        }
    }
    printf("-\n");

    return 0;
}