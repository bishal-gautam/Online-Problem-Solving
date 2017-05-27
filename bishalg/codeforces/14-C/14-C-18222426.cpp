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
#define UNIK(v) sort(all(v)),v.resize( unique(all(v)) -v.begin() );
using namespace std;
typedef long long ll;
///==========CONSTANTS=============///
///  Digit     0123456789012345678 ///
#define MX     500002
#define inf    1000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///

vector< pair< pii ,pii > >vp;
vector< pair< pii ,pii > >tp;

int main(){
    int tc,n;
    set< pii >St;
    int ax=inf,ay=inf,bx=-inf,by=-inf;
    fr(i,1,4){
        pii a,b;
        cin>>a.X>>a.Y;
        cin>>b.X>>b.Y;

        ax=min(ax,a.X);
        ax=min(ax,b.X);

        bx=max(bx,a.X);
        bx=max(bx,b.X);

        ay=min(ay,a.Y);
        ay=min(ay,b.Y);

        by=max(by,a.Y);
        by=max(by,b.Y);

        St.insert( a );
        St.insert( b );
        if( a>b ) swap(a,b);
        vp.pb( mpp(a,b) );
    }
    if( St.size() !=4 || (ax==bx && ay==by) ){
        cout<< "NO\n";
        return 0;
    }
    sort( all(vp) );
    tp.pb( mpp( mpp(ax,ay) , mpp(ax,by) ) );
    tp.pb( mpp( mpp(ax,ay) , mpp(bx,ay) ) );
    tp.pb( mpp( mpp(bx,ay) , mpp(bx,by) ) );
    tp.pb( mpp( mpp(ax,by) , mpp(bx,by) ) );
    sort( all(tp) );
//    fr(i,0,3){
//        cout<<vp[i].X.X<< " , "<<vp[i].X.Y<< " = ";
//        cout<<vp[i].Y.X<< " , "<<vp[i].Y.Y<< " = ";
//        nl;
//        cout<<tp[i].X.X<< " , "<<tp[i].X.Y<< " = ";
//        cout<<tp[i].Y.X<< " , "<<tp[i].Y.Y<< " = ";
//        nl;
//    }
    if(vp==tp){
        cout<< "YES\n";
    }
    else cout<< "NO\n";

    return 0;
}