#include <bits/stdc++.h>
using namespace std;
int n,a,b;
bool xd;
char name[100];
string ord[10];
map<string,int> pers;
int main(){
    while(scanf("%d",&n)!=EOF){
        if(xd){
            printf("\n");
        }
        xd=true;
        pers.clear();
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
                //pers[NAME]+=a;
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
}