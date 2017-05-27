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
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Year
///int dx[]= {1,0,-1,0};int dy[]= {0,1,0,-1}; //4 Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
///int dx[]= {2,1,-1,-2,-2,-1,1,2};int dy[]= {1,2,2,1,-1,-2,-2,-1}; //Knight Direction
///==========CONSTANTS=============///
///  Digit     0123456789012345678 ///
#define MX     5005
#define inf    1000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

vector<string>vs;
string s;
string ans[MX];
string ss[MX];
int main() {
    int n,i,j,k;
    S2(n,k);
    for(char ch='A'; ch<='Z'; ch++) {
        string ts="";
        for(char ch2='a'; ch2<='z'; ch2++) {
            ts+=ch;
            ts+=ch2;
            vs.pb( ts );
            //cout<<ts<<endl;
            ts="";
        }
    }
    for(i=1; i<=n; i++) {
        ans[i]="0";
    }
    int id=0;
    for(i=1; i<=n-k+1; i++) {
        cin>>s;
        ss[ i ]=s;
//        if( s=="YES" ) {
//            for(j=i; j<=i+k-1; j++) {
//                if( ans[ j ]=="0" ) {
//                    ans[ j ]=vs[ id ];
//                    id++;
//                }
//            }
//        }
    }
    int lst=n;
    for(i=n-k+1;i<=n;i++){
        ans[ i ]=vs[ id ];
        id++;
    }
    for(i=n-k+1;i>=1;i--){
        if( ss[i]=="NO" ){
            ans[ i ]=ans[ lst ];
        }
        else{
            ans[ i ]=vs[ id ];
            id++;
        }
        lst--;
    }


//    for(i=1; i<=n-k+1; i++) {
//        if( ss[i]=="NO" ) {
//            string ret="1";
//            for(j=i; j<=i+k-1; j++) {
//                if( ans[ j ]!="0" ) {
//                    ret=ans[ j ];
//                    break;
//                }
//            }
//            if( ret=="1" ){
//                ret=vs[ id ];
//                id++;
//            }
//            for(j=i; j<=i+k-1; j++) {
//                if( ans[ j ]=="0" ) {
//                    ans[ j ]=ret;
//                }
//            }
//        }
//    }
    for(i=1;i<=n;i++){
       // cout<<i<<endl;
        cout<<ans[i]<< " ";
    }
    cout<< "\n";

    return 0;
}