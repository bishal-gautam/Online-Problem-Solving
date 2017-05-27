/****************************************************************************
 *                                                                          *
 *                    ==>> BG_PeaceMind(BISHAL)                             *
 *                   try=0; while(!success) try++;                          *
 ****************************************************************************/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define PI acos(-1.0)
#define nl puts("")
#define SZ(x) x.size()
#define pb(x) push_back(x)
#define X first
#define Y second
#define pii pair<ll,ll>
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define fr(i,a,n) for(i=a;i<=n;i++)
#define rf(i,n,a) for(i=n;i>=a;i--)
#define LB(v,k) lower_bound(v.begin(),v.end(),k)
#define _cin ios_base::sync_with_stdio(0),cin.tie(0)
#define ct(x) cerr<<__LINE__<< ":: "<<#x<<"= "<<x<<endl
#define fi(it,n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> os;
//find_by_order
//order_of_key
void show() {
    cout<<'\n';
}
template<typename T,typename... Args>
void show(T a, Args... args) {
    cout<<a<<" ";
    show(args...);
}
template<typename T>
void show_c(T& a) {
    for ( auto &x:a ) cout<<x<<" ";
    cout<<endl;
}
/// atoi( str.c_str() ); // char string to int
/// sprintf(str,"%d",num);// num to char string
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Yr
///int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Dir
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Dir
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight
/************************************************************************
 * /////////////////////////////////////////////////////////////////////*
 ************************************************************************/

os St[30];
bool vis[200100+5];
char s[200010+5],ss[200010+5];

int main() {
    int i,j,k,x,y,q,p;
   // _cin;
    cin>>k>>s;
    int n=strlen(s);
    int id=1;
    ss[0]='*';
    while(k--) {
        for(i=0; i<n; i++) {
            x=s[i]-'a';
            St[ x ].insert( id );
            ss[ id ]=s[i];
            id++;
        }
    }
    ss[id]='\0';
    S(q);
    while(q--) {
        char ch[2];
        cin>>p>>ch;
        x=ch[0]-'a';
        int vl=*St[x].find_by_order(p-1);
        St[x].erase( vl );
        vis[ vl ]=1;
    }
    fr(i,1,id-1)if(!vis[i])cout<<ss[i];
    nl;

    return 0;
}