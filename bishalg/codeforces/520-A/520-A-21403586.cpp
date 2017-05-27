#include<bits/stdc++.h>
using namespace std;
int n,cnt[30];
char s[201];
int main() {
    cin>>n>>s;
    for(int i=0; i<n; i++) {
        s[i]=tolower(s[i]);
        cnt[ s[i]-'a' ]++;
    }
    int tot=0;
    for(int i=0; i<26; i++) {
        if(cnt[i]>=1)tot++;
    }
    if(tot==26) printf("YES\n");
    else printf("NO\n");
    return 0;
}