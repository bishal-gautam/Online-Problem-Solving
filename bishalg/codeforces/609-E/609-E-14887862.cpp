/****************************************************************************
 *                                                                          *
 *                    ==>> BG_PeaceMind(BISHAL)                             *
 *                   try=0; while(!success) try++;                          *
 ****************************************************************************/
#include<bits/stdc++.h>
#define PI acos(-1.0)
#define nl puts("")
#define SZ(x) x.size()
#define pb(x) push_back(x)
#define X first
#define Y second
#define pii pair<int,int>
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define all(v) v.begin(),v.end()
#define clr(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define fr(i,a,n) for(i=a;i<=n;i++)
#define rf(i,n,a) for(i=n;i>=a;i--)
#define LB(v,k) lower_bound(v.begin(),v.end(),k)
#define _cin ios_base::sync_with_stdio(0),cin.tie(0)
#define ct(x) cerr<<__LINE__<< ":: "<<#x<<"= "<<x<<endl
#define fi(it,n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)
using namespace std;
typedef long long ll;
/// atoi( str.c_str() ); // char string to int
/// sprintf(str,"%d",num);// num to char string
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Yr
///int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Dir
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Dir
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight
/************************************************************************
 * /////////////////////////////////////////////////////////////////////*
 ************************************************************************/
/// [ Look at my code below, My code is so amazing !! :P ]
/// Digit    012345678910
#define MX   200003
#define MD   200000006
#define EPS  1e-9
#define inf  1000005
#define _cin ios_base::sync_with_stdio(0),cin.tie(0)

vector<int>g[MX + 5], c[MX + 5];
ll n, ans, p[MX][22], MaX[MX][22], T[MX], L[MX];

struct data2 {
    int x, y, c;
    data2(int a, int b, int cc) {
        x = a;
        y = b;
        c = cc;
    }
    bool friend operator<(data2 a, data2 b) {
        return (a.c < b.c);
    }
};
vector<data2>pp;
vector<data2>qq;
int st[MX];

int GP(int x) {
    if(st[x] == x) return x;
    return (st[x] = GP(st[x]));
}

void go(int u, int p, int l, ll vl) {
    //cout << u << " : " << p << " " << l << " - " << vl << endl;
    T[u] = p;
    L[u] = l;
    MaX[u][0] = vl;
    int sz = SZ(g[u]);
    // cout << sz << endl;
    for(int i = 0; i < sz; i++) {
        int v = g[u][i];
        int val = c[u][i];
        if(v == p)continue;
        go(v, u, l + 1, val);
    }
}

void pre_par( ) {
    int i, j, k;
    SET(p);
    fr(i, 1, n)fr(j, 1, 20)MaX[i][j] = 0;
    fr(i, 1, n)p[i][0] = T[i];
    fr(j, 1, 20) {
        fr(i, 1, n) {
            if( p[i][j - 1] == -1 )continue;
            MaX[i][j] = max( MaX[i][j - 1], MaX[ p[i][j - 1] ][j - 1] );
            p[i][j] = p[ p[i][j - 1] ][ j - 1 ];
        }
    }
}

int get_kth(int x, int k) {
    for(int i = 20; i >= 0; i--) {
        if( (1 << i) <= k ) {
            ans = max(ans, MaX[x][i] );
            x = p[x][i];
            k -= (1 << i);
        }
    }
    return x;
}

int get_lca(int x, int y) {
    if(L[x] < L[y])swap(x, y);
    int k = L[x] - L[y];
    x = get_kth(x, k);
    if(x == y) return x;
    for(int i = 20; i >= 0; i--) {
        if( p[x][i] != p[y][i] ) {
            ans = max(ans, MaX[x][i]);
            ans = max(ans, MaX[y][i]);
            x = p[x][i];
            y = p[y][i];
        }
    }
    ans = max(ans, MaX[x][0]);
    ans = max(ans, MaX[y][0]);
    return T[x];
}

int main() {
    ll tc, cs = 1, i, j, k, m, x, y, z, q, a, b, u, v;
    _cin;
    cin >> n >> m;
    fr(i, 1, m) {
        cin >> x >> y >> z;
        pp.pb(data2(x, y, z));
        qq.pb(data2(x, y, z));
    }
    sort(all(pp));
    int cnt = 0;
    fr(i, 0, n)st[i] = i;
    ll sm = 0LL;
    fr(i, 0, m - 1) {
        a = GP(pp[i].x);
        b = GP(pp[i].y);
        if(a == b)continue;
        sm += pp[i].c;
        st[a] = b;
        u = pp[i].x;
        v = pp[i].y;
        // cout << u << " " << v << " -> " << pp[i].c << endl;
        g[u].pb(v);
        c[u].pb(pp[i].c);
        g[v].pb(u);
        c[v].pb(pp[i].c);
        cnt++;
        if(cnt == n - 1)break;
    }
    //cout<<sm<<endl;
    go(1, -1, 1, 1000000000000000LL);
    pre_par( );
    for(i = 0; i < m; i++) {
        x = qq[i].x;
        y = qq[i].y;
        int z = qq[i].c;
        ans = 0;
        int lca = get_lca(x, y);
        ll res = sm + z - ans;
        cout << res << "\n";
    }
    return 0;
}