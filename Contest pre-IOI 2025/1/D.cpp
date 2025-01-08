#include <bits/stdc++.h>
using namespace std;
int L;
char sig,di;
vector<int> xp={1,0,0},xn={-1,0,0},yp={0,1,0},ynn={0,-1,0},zp={0,0,1},zn={0,0,-1},no={0,0,0};
struct direccion{
    bool u=false,d=false,r=false,l=false;
    int res(){
        if(u){
            return 1;
        }
        if(d){
            return 2;
        }
        if(r){
            return 3;
        }
        if(l){
            return 4;
        }
        return 0;
    }
    void set(int x){
        if(x==0){
            // nada
        }else if(x==1){
            u=true;
        }else if(x==2){
            d=true;
        }else if(x==3){
            r=true;
        }else{
            l=true;
        }
    }
};
int main(){
    while(scanf("%d",&L),L){
        vector<int> direc={1,0,0};
        vector<direccion> op(L-1);
        for(int i=L-2;i>=0;i--){
            scanf(" %c%c",&sig,&di);
            if(sig=='N'){
                op[i].set(0);
            }else if(sig=='+'){
                if(di=='y'){
                    op[i].set(1);
                }else{
                    op[i].set(3);
                }
            }else{
                if(di=='y'){
                    op[i].set(2);
                }else{
                    op[i].set(4);
                }
            }
        }
        for(int i=0;i<L-1;i++){
            if(op[i].res()==0){
                continue;
            }
            if(direc==xp){
                if(op[i].res()==1){
                    direc=yp;
                }else if(op[i].res()==2){
                    direc=ynn;
                }else if(op[i].res()==3){
                    direc=zp;
                }else{
                    direc=zn;
                }
            }else if(direc==xn){
                if(op[i].res()==1){
                    direc=yp;
                }else if(op[i].res()==2){
                    direc=ynn;
                }else if(op[i].res()==3){
                    direc=zn;
                }else{
                    direc=zp;
                }
            }else if()
        }
        if(direc==xp){
            printf("+x");
        }else if(direc==yp){
            printf("+y");
        }else if(direc==zp){
            printf("+z");
        }else if(direc==xn){
            printf("-x");
        }else if(direc==ynn){
            printf("-y");
        }else{
            printf("-z");
        }
        printf("\n");
    }
}