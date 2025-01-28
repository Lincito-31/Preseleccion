/*
ID: simplem2
LANG: C++
TASK: gift1
*/
#include <bits/stdc++.h>
using namespace std;
int n,a,b;
char name[100];
map<string,int> pers;
string ord[10];
int main(){
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",name);
        string NAME(name);
        ord[i]=NAME;
        pers[NAME]=0;
    }
    for(int j=0;j<n;j++){
        scanf("%s",name);
        string NAME(name);
        scanf("%d%d",&a,&b);
        if(b==0){
            pers[NAME]+=a;
            continue;
        }
        for(int i=0;i<b;i++){
            scanf("%s",name);
            string TO(name);
            pers[TO]+=a/b;
        }
        pers[NAME]+=a%b;
        pers[NAME]-=a;
    }
    for(int i=0;i<n;i++){
        cout << ord[i] << " " << pers[ord[i]] << "\n";
    }
}