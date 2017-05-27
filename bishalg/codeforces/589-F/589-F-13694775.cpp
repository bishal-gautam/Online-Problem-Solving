///============================================================================///
///                                                                            ///
///                            IT'S ME                                         ///
///                         BISHAL GAUTAM                                      ///
///                  CSE,JAHANGIRNAGAR UNIVERSITY,DHAKA                        ///
///               "Follow Excellence..Success will chase U"                    ///
///                   ID: TC/CF => (BG_PeaceMind.)                             ///
///                                                                            ///
///============================================================================///
#include<bits/stdc++.h>
#define PI acos(-1.0)
#define X first
#define Y second
#define nl printf("\n")
#define SZ(x) (int)(x.size())
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpp make_pair

///==Scanning====///
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define fv(i,v)  for(int i=0;i<(int)v.size();i++)
#define fr(i,a,n) for(int i=a;i<=n;i++)

#define pb(x) push_back(x)
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))

using namespace std;

const int L = 1000000, N = 5*L, M = 5000000,inf=2000000000;
int s, t;
int ne,head[N],vex[M],cap[M],nxt[M],lvl[N],cur[N];

void add_edge(int u, int v, int c) {
    ++ne;
    vex[ne] = v;
    cap[ne] = c;
    nxt[ne] = head[u];
    head[u] = ne;
}

void add_biedge(int u, int v, int c) {
    add_edge(u, v, c);
    add_edge(v, u, 0);
}

bool bfs_lvl() {
    CLR(lvl);
    lvl[s] = 1;
    queue<int>q;
    for(q.push(s); !q.empty(); q.pop()) {
        int u = q.front();
        if(u == t) return true;
        for(int i=head[u]; i; i=nxt[i]) if( cap[i] && !lvl[vex[i]] )
                lvl[vex[i]] = lvl[u]+1, q.push(vex[i]);
    }
    return false;
}

int dfs(int u, int mn) {
    if(u == t) return mn;
    int sum = 0;
    for(int& i = cur[u]; i; i = nxt[i]) if(cap[i] && lvl[vex[i]]==lvl[u]+1)
            if(int f = dfs(vex[i], min(mn-sum, cap[i]))) {
                cap[i  ] -= f;
                cap[i^1] += f;
                if((sum+=f) == mn) return mn;
            }
    if(!sum) lvl[u] = -1;
    return sum;
}

int max_flow() {
    int flow = 0;
    while(bfs_lvl()) CPY(cur,head),flow+=dfs(s,inf);
    return flow;
}

int a[50005],b[50005],vis[50005];
int main() {
    int c,n,m,x,y,d;

    scanf("%d",&n);
    int mx=0,mn=inf;
    for(int i=1; i<=n; i++) {
        S2(a[i],b[i]);
        a[i]++;
        b[i]++;
        fr(j,a[i],b[i]-1)vis[j]=1;
    }
    s=(0); ///Src
    t=(1+n+10005+1); /// Target
    int Ne=ne;
    int lo=0,hi=50001,ret=0;
    while(lo<=hi) {
        int md=(lo+hi)/2;
        ne=1;
        CLR(head);
        /// Create Graph!!;
        fr(i,1,n) {
            add_biedge(s,i,md);
            fr(j,a[i],b[i]-1) {
                add_biedge( i, j+n+1, 1 );
            }
        }
        fr(j,1,10005) if( vis[j] )
            add_biedge( j+n+1, t ,1 );

        int flo=max_flow();
        // cout<<md<< " => "<<flo<<endl;
        if( flo==n*md ) {
            ret=n*md;
            lo=md+1;
        } else hi=md-1;
    }
    printf("%d\n",ret);

    return  0;
}