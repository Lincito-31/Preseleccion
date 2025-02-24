#include <bitset>
#include <set>
#include <iostream>
using namespace std;
int n,c,x;
set<string> dif;
bitset<10000> op[4],on,off;
void solve(int a,bitset<10000> last,int con){
    if(a==4){
        if(c-con<0 || (c-con)%2==1){
            return;
        }
        string temp="";
        for(int i=0;i<n;i++){
            if(last[i]){
                if(off[i]){
                    return;
                }
                temp.push_back('1');
            }else{
                if(on[i]){
                    return;
                }
                temp.push_back('0');
            }
        }
        dif.insert(temp);
        return;
    }
    solve(a+1,last,con);
    solve(a+1,last^op[a],con+1);
}
int main(){
    scanf("%d%d",&n,&c);
    for(int i=0;i<5000;i++){
        op[0][i]=op[0][5000+i]=1;
        op[1][2*i+1]=1;
        op[2][2*i]=1;
        if(i*3+1<10000){
            op[3][3*i]=1;
        }
    }
    while(scanf("%d",&x) && x!=-1){
        on[--x]=1;
    }
    while(scanf("%d",&x)&& x!=-1){
        off[--x]=1;
    }
    bool xd=false;
    string tempo=string(10000,'1');
    bitset<10000> teeee(tempo);
    solve(0,teeee,0);
    set<string>::iterator aa;
    for(aa=dif.begin();aa!=dif.end();aa++){
        xd=true;
        for(int i=0;i<n;i++){
            printf("%c",(*aa)[i]);
        }
        printf("\n");
    }
    if(!xd){
        printf("Impossible");
    }
    return 0;
}