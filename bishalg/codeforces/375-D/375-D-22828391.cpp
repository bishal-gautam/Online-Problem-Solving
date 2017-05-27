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
#define OnBit(i) __builtin_popcount(i)
///-----------------------------------
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
///------------------------------------
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define fr(i,n) for(int i=a;i<=n;i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

///  Digit     0123456789012345678 ///
#define MX     100002
#define inf    2000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///

vector<int>G[MX + 2];
vector<pii>Qr[MX + 2];
int Col[MX + 2];
int SS[MX + 2];
int SC[MX + 2];
int n;

void PreDfs(int u,int p) {
    SS[ u ] = 1;
    SC[ u ] = -1;
    for(auto v : G[u]) {
        if( v==p )continue;
        PreDfs(v,u);
        SS[u] += SS[v];
        if(SC[u] == -1 || SS[v] > SS[ SC[u] ]) {
            SC[u] = v;
        }
    }
}

bool Hvy[MX + 2];
int Fr[MX+2];///How many are of this Frq;
int Cnt[MX+2];///Count of each Col;
int Ans[MX+2];

//void add(int p,int v) {
//    for(int i=p; i<=MX; i+=i&-i)BIT[i]+=v;
//}
//
//int read(int p) {
//    int ret=0;
//    for(int i=p; i>0; i-=i&-i)ret+=BIT[i];
//    return ret;
//}

void Add(int u,int p) {
    int x=Cnt[ Col[u] ];
    Cnt[ Col[u] ]++;
    Fr[ x+1 ]++;
    for(auto v : G[u]) {
        if(v==p||Hvy[v])continue;
        Add(v,u);
    }
}

void Rmv(int u,int p) {
    int x=Cnt[ Col[u] ];
    Cnt[ Col[u] ]--;
    Fr[x]--;
    for(auto v : G[u]) {
        if(v==p||Hvy[v])continue;
        Rmv(v,u);
    }
}

void Dfs(int u,int p,int f) {
    for(auto v : G[u]) { ///CLR Light Childs
        if(v==p||v == SC[u])continue;
        Dfs(v,u,0);
    }
    if(SC[u] != -1) Dfs(SC[u],u,1), Hvy[ SC[u] ] = 1; ///Keep Hvy Child
    Add(u,p); ///Actual-Work in Array
    for(auto x:Qr[u]) {
        int kk=x.X;
        int id=x.Y;
       // Ans[id]=read(MX)-read(kk-1);
        Ans[id]=Fr[ kk ];///Freq Incremented being k once!!
    }
    if(SC[u] != -1) Hvy[ SC[u] ] = 0;
    if(!f) Rmv(u,p);
}

int main() {
    int x, y, q ,k=0;
    S2(n,q);
    for(int i = 1; i <= n; i++) {
        S( Col[i] );
    }
    for(int i=1; i<=n-1; i++) {
        S2(x,y);
        G[x].pb( y );
        G[y].pb( x );
    }
    PreDfs(1,0);
    for(int i=1; i<=q; i++) {
        S2(x,y);
        Qr[x].pb( mpp(y,i) );
    }
    Dfs(1,0,1);
    for(int i = 1; i <= q; i++) {
        printf("%d\n",Ans[i]);
    }
    return 0;
}