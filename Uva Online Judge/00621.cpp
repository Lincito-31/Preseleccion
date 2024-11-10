#include <bits/stdc++.h>
using namespace std;
int t;
string x;
int main(){
    scanf("%d",&t);
    while(t--){
        cin >> x;
        if(x=="1" || x=="4" || x=="78"){
            printf("+");
        }else if(x.size()>=2 && x[x.size()-1]=='5' && x[x.size()-2]=='3'){
            printf("-");
        }else if(x[0]=='9' && x.back()=='4'){
            printf("*");
        }else if(x.size()>=3 && x[0]=='1' && x[1]=='9' && x[2]=='0'){
            printf("?");
        }else{
            printf("+");
        }
        printf("\n");
    }
}