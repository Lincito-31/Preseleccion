#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;
int n,con=1;
char a,b,c;
map<string,int> clav;
map<int,string> revclav;
int main(){
    scanf("%d",&n);
    vector<int> graph[2*n+5];
    vector<int> in(2*n+5);
    vector<int> out(2*n+5);
    for(int i=0;i<n;i++){
        scanf(" %c%c%c",&a,&b,&c);
        string from="",to="";
        from+=a;from+=b;
        to+=b;to+=c;
        if(clav[from]==0){
            clav[from]=con;
            revclav[con]=from;
            con++;
        }
        if(clav[to]==0){
            clav[to]=con;
            revclav[con]=to;
            con++;
        }
        graph[clav[from]].push_back(clav[to]);
        out[clav[from]]++;
        in[clav[to]]++;
    }
    int ini=0,end=0;
    for(int i=1;i<=2*n;i++){
        if(in[i]==out[i]){
            //nada
        }else if(in[i]==out[i]+1){
            if(end){
                printf("NO");
                return 0;
            }
            end=i;
        }else if(in[i]+1==out[i]){
            if(ini){
                printf("NO");
                return 0;
            }
            ini=i;
        }else{
            printf("NO");
            return 0;
        }
    }
    if((ini==0&&end!=0)||(ini!=0&&end==0)){
        printf("NO");
        return 0;
    }else if(!(ini&&end)){
        ini=1;
    }
    int now=ini;
    stack<int> cola;
    stack<int> caminoE;
    cola.push(now);
    while(!cola.empty()){
        if(graph[now].empty()){
            caminoE.push(cola.top());
            cola.pop();
            if(cola.empty()){
                break;
            }
            now=cola.top();
        }else{
            int next=graph[now].back();
            graph[now].pop_back();
            now=next;
            cola.push(next);
        }
    }
    if(caminoE.size()<n){
        printf("NO");
        return 0;
    }
    printf("YES\n");
    int xx=caminoE.top();caminoE.pop();
    printf("%c%c",revclav[xx][0],revclav[xx][1]);
    while(!caminoE.empty()){
        printf("%c",revclav[caminoE.top()][1]);
        caminoE.pop();
    }
}