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

///  Digit     0123456789012345678 ///
#define MX     205
#define inf    2000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

vector<pii>G[4];
string str,s[MX+2];

bool cmp(pii A,pii B){
     if( A.X==B.X ) return A.Y<B.Y;
     else return A.X>B.X;
}

int n;
int main() {
    int i,j,k,x;
    cin>>n;
    for(i=0;i<3;i++)G[i].clear();
    for(i=1; i<=n; i++) {
        cin>>x>>s[i];
        int tx=0,pz=0,gg=0;
        while(x--) {
            cin>>str;
            set<char>St;
            int pp=1,pv=10;;
            for(j=0; str[j]; j++) {
                if(str[j]=='-')continue;
                St.insert( str[j] );
                if( pv> str[j]-'0' )pv=str[ j ]-'0';
                else pp=0;
            }
            if( St.size()==1 ) {
                tx++;
            } else if( pp )pz++;
            else gg++;
        }
        G[ 0 ].pb( mpp( tx,i) );
        G[ 1 ].pb( mpp( pz,i) );
        G[ 2 ].pb( mpp( gg,i) );
       // cout<<i<< " : "<<tx<< " , "<<pz<< " , "<<gg<<endl;
    }
    for(i=0; i<3; i++) {
        sort( all(G[i]),cmp );
       // cout<<G[ i ][ 0 ].X<< " ** "<<G[ i ][ 0 ].Y<<endl;
        if( i==0 ) {
            printf("If you want to call a taxi, you should call: ");
            int pr=0;
            int vl=G[ i ][ 0 ].X;
            j=0;
            while( j<n && G[ i ][ j ].X==vl ){
                int idx=G[ i ][ j ].Y;
                if(pr)printf(", %s",s[ idx ].c_str());
                else printf("%s",s[ idx ].c_str());
                pr=1;
                j++;
            }
            printf(".\n");
        }
        else if( i==1 ) {
            printf("If you want to order a pizza, you should call: ");
            int pr=0;
            int vl=G[ i ][ 0 ].X;
            j=0;
            while( j<n && G[ i ][ j ].X==vl ){
                int idx=G[ i ][ j ].Y;
                if(pr)printf(", %s",s[ idx ].c_str());
                else printf("%s",s[ idx ].c_str());
                pr=1;
                j++;
            }
            printf(".\n");
        }
        else if( i==2 ) {
            printf("If you want to go to a cafe with a wonderful girl, you should call: ");
            int pr=0;
            int vl=G[ i ][ 0 ].X;
            j=0;
            while( j<n && G[ i ][ j ].X==vl ){
                int idx=G[ i ][ j ].Y;
                if(pr)printf(", %s",s[ idx ].c_str());
                else printf("%s",s[ idx ].c_str());
                pr=1;
                j++;
            }
            printf(".\n");
        }
    }

    return 0;
}