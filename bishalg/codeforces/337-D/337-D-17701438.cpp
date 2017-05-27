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
#define MX     100002
#define inf    200000000
#define MD     1000000000LL
#define eps    1e-9
///===============================///

vector<int>G[MX+2];
int Spcl[MX+2];
int dis1[MX+2];
int dis2[MX+2];
int dis3[MX+2];

void Dfs1(int u,int p) {
    if( Spcl[u] )dis1[u]=0;
    else dis1[u]=-inf;
    dis2[u]=-inf;
    for(int i=0; i<SZ(G[u]); i++) {
        int v=G[u][i];
        if(v==p)continue;
        Dfs1(v,u);
        if( dis1[u]<dis1[v]+1 ) {
            dis2[u]=dis1[u];
            dis1[u]=dis1[v]+1;
        } else if(dis2[u]<dis1[v]+1) {
            dis2[u]=dis1[v]+1;
        }
    }
}

void Dfs2(int u,int p) {
    if( Spcl[u] )dis3[u]=0;
    else dis3[u]=-inf;
    if(p!=-1) {
        dis3[u]=dis3[p]+1;
        if( dis1[p]==dis1[u]+1 )dis3[u]=max(dis3[u],dis2[p]+1);
        else dis3[u]=max(dis3[u],dis1[p]+1);
    } else dis3[u]=dis2[u];
    for(int i=0; i<SZ(G[u]); i++) {
        int v=G[u][i];
        if(v==p)continue;
        Dfs2(v,u);
    }
}

int main() {
    int i,j,n,m,d,k,x,y,z;
    S2(n,m);
    S(d);
    fr(i,1,m)S(x),Spcl[x]=1;
    fr(i,1,n-1) {
        S2(x,y);
        G[x].pb(y);
        G[y].pb(x);
    }
    Dfs1(1,-1);
    Dfs2(1,-1);
    int cnt=0;
    fr(i,1,n) {
        if( dis1[i]<=d && dis3[i]<=d)cnt++;
        //cout<<i<< " : "<<dis1[i]<< " && "<<dis3[i]<<endl;
    }
    printf("%d\n",cnt);

    return 0;
}