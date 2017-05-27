///==================================================///
///                HELLO WORLD !!                    ///
///                  IT'S ME                         ///
///               BISHAL GAUTAM                      ///
///         [ bsal.gautam16@gmail.com ]              ///
///==================================================///
#include<bits/stdc++.h>
#define PI acos(-1.0)
#define X first
#define Y second
#define mpp make_pair
#define nl printf("\n")
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
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

#define _cin ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Year
///int dx[]= {1,0,-1,0};int dy[]= {0,1,0,-1}; //4 Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
///int dx[]= {2,1,-1,-2,-2,-1,1,2};int dy[]= {1,2,2,1,-1,-2,-2,-1}; //Knight Direction
///==========CONSTANTS=============///
///  Digit     0123456789012345678 ///
#define MX     100003
#define inf    1000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

struct data {
    int l,r,sm;
    data() {};
    ~data() {};
};

data Nd[(60*MX)+2];
int Nw,root[ MX+5 ];

int Ins(int pn,int l,int r,int p,int v) {
    int id=++Nw;
    Nd[ id ]=Nd[ pn ];
    if( l==r ) {
        Nd[ id ].sm=v;
        return id;
    }
    int md=(l+r)>>1;
    if( p<=md ) Nd[id].l=Ins(Nd[id].l,l,md,p,v);
    else Nd[id].r=Ins( Nd[id].r,md+1,r,p,v );
    Nd[ id ].sm=( Nd[ Nd[id].l ].sm+Nd[ Nd[id].r ].sm );
    return id;
}

int Qry(int nn,int l,int r,int q1,int q2) {
    if( r<q1 || l>q2 ) return 0;
    if( q1<=l && r<=q2 ) return Nd[nn].sm;
    int md=(l+r)>>1;
    return Qry( Nd[nn].l, l, md, q1, min(q2,md))+Qry( Nd[nn].r,md+1,r,max(q1,md+1),q2 );
}

int Qry(int id,int l,int r,int k) {
    if(l==r) {
        if( !k&& Nd[ id ].sm ) return l;
        else return l+1;
    }
    int md=(l+r)>>1;
    int lsm=Nd[ Nd[id].l ].sm;
    if( lsm>k ) return Qry( Nd[id].l,l,md,k );
    else return Qry( Nd[id].r,md+1,r,k-lsm );
}

int MP[MX+5];
int ar[MX+5];
int ans[MX+5];
int main() {
    int i,j,k,n,x,y;
    S(n);
    for(int i=1; i<=n; i++) {
        S(ar[i]);
    }
    Nw=0;
    root[n+1]=++Nw;
    for(i=n; i>=1; i--) {
        x=ar[i];
        int lst=MP[ x ];
        if(lst==0) {
            root[i]=Ins(root[i+1],1,n,i,1);
        } else {
            root[i]=Ins(root[i+1],1,n,lst,0);
            root[i]=Ins(root[i],1,n,i,+1);
        }
        MP[x]=i;
    }

    for(k=1; k<=n; k++) {
        int bg=1,cnt=0;
       // cout<< " K: "<<k<<endl;
        int kk=k;
        while( bg<=n ) {
            cnt++;
            if( Nd[ root[ bg ] ].sm<=kk ) {
                break;
            }
            int id=Qry( root[bg],1,n,kk );
            bg=id;
        }
       // nl;
        printf("%d\n",cnt);
    }
    printf("\n");

    return 0;
}