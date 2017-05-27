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
#define MX     200002
#define inf    2000000010
#define MD     1000000007LL
#define eps    1e-9
///===============================///

vector<int>G[MX + 2];
vector<pii>Qr[MX + 2];
int Col[MX + 2];
int SS[MX + 2];
int SC[MX + 2];
int L[MX + 2];
int ar[MX + 2];
int n;
string s[MX+2];

void PreDfs(int u,int l) {
    SS[ u ] = 1;
    SC[ u ] = -1;
    L[ u ]=l;
    for(auto v : G[u]) {
        PreDfs(v,l+1);
        SS[u] += SS[v];
        if(SC[u] == -1 || SS[v] > SS[ SC[u] ]) {
            SC[u] = v;
        }
    }
}

bool Hvy[MX + 2];
int Cnt[MX + 2];
int Ans[MX + 2];
//set<string>Cnt[MX+2];
map<int,int>Mp[MX+2];

void Add(int u) {
    Mp[ L[u] ][ ar[u] ]++;
    for(auto v : G[u]) {
        if(Hvy[v])continue;
        Add(v);
    }
}

void Rmv(int u) {
    Mp[ L[u] ].clear();
    for(auto v : G[u]) {
        if(Hvy[v])continue;
        Rmv(v);
    }
}

void Dfs(int u,int f) {
    for(auto v : G[u]) { ///CLR Light Childs
        if(v == SC[u])continue;
        Dfs(v,0);
    }
    if(SC[u] != -1) Dfs(SC[u],1), Hvy[ SC[u] ] = 1; ///Keep Hvy Child
    Add(u); ///Actual-Work in Array
    for(auto x:Qr[u]) {
        int ht=x.X;
        int id=x.Y;
       // cout<<id<< " -- "<<ht<<endl;
        Ans[id]=( Mp[ ht ].size() );
    }
    if(SC[u] != -1) Hvy[ SC[u] ] = 0;
    if(!f) Rmv(u);
}

int par[MX+2];
map<string,int>MPS;
int main() {
    int x, y, q ,k=0;
    S(n);
    for(int i = 1; i <= n; i++) {
        cin>>s[i];
        if( MPS.find(s[i])==MPS.end()){
            MPS[ s[i] ]=++k;
        }
        ar[i]=MPS[ s[i] ];
        S(y);
        G[ y ].pb(i);
        par[ i ]=y;
    }
    PreDfs(0,0);
    S(q);
    for(int i=1; i<=q; i++) {
        S2(x,y);
        Qr[x].pb( mpp(L[x]+y,i) );
    }
    Dfs(0,0);
    for(int i = 1; i <= q; i++) {
        printf("%d\n",Ans[i]);
    }
    return 0;
}