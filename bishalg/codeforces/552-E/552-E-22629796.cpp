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
#define MX     2000001
#define inf    2000000010
#define MD     1000000007
#define eps    1e-9
///===============================///

ll go(string s){
    int n=SZ(s);
    stack<ll>Vl;
    bool f=0;
    ll res=0;
   // cout<<s<< " => ";
    for(int i=0;i<n;i++){
        if( s[i]=='*' )f=1;
        if( s[i]=='+' )f=0;
        if( isdigit( s[i] ) ){
            if( f ){
                ll tp=Vl.top();
                Vl.pop();
                Vl.push( (tp*(ll)( s[i]-'0' ) ) );
            }else Vl.push( (ll)(s[i]-'0') );
        }
    }
    while(!Vl.empty()){
        res+=Vl.top();
        Vl.pop();
    }
   // cout<<res<<endl;
    return res;
}

ll Go(vector<ll>s){
    int n=SZ(s);
    stack<ll>Vl;
    bool f=0;
    ll res=0;
    for(int i=0;i<n;i++){
        if( s[i]=='*' )f=1;
        if( s[i]=='+' )f=0;
        if( s[i]!='*' && s[i]!='+' ){
            if( f ){
                ll tp=Vl.top();
                Vl.pop();
                Vl.push( tp*(s[i]-48)  );
            }else Vl.push( s[i]-48 );
        }
    }
    while(!Vl.empty()){
        res+=Vl.top();
        Vl.pop();
    }
    return res;
}

vector<int>v;
vector<ll>vv;
string s,tp;
int main(){
    cin>>tp;
    s="";
    s+="1*";
    s+=tp;
    s+="*1";
    int n=SZ(s);
    for(int i=0;i<n;i++){
        if(s[i]=='*')v.pb( i );
    }
    int m=SZ(v);
    ll sm=0;
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            string a="";
            vv.clear();
            for(int k=v[i]+1;k<v[j];k++)a+=s[k];
           // cout<< "_____"<<a<< "______"<<endl;
            for(int k=0;k<=v[i];k++){
                vv.pb( s[k] );
            }
            vv.pb( go(a)+48LL );
            for(int k=v[j];k<n;k++){
                vv.pb( s[k] );
            }
           // cout<<Go(vv)<<endl;
            sm=max( sm,Go(vv) );
        }
    }
    printf("%lld\n",sm);

    return 0;
}