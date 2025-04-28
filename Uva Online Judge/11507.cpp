#include <bits/stdc++.h>
using namespace std;
int L;
char sig,di;
vector<int> xp={1,0,0},xn={-1,0,0},yp={0,1,0},ynn={0,-1,0},zp={0,0,1},zn={0,0,-1},no={0,0,0};
int main(){
    while(scanf("%d",&L),L){
        vector<int> direc={1,0,0};
        while(--L){
            scanf(" %c%c",&sig,&di);
            if(sig=='N'){
                continue;
            }
            if(direc==xp){
                if(sig=='+'){
                    if(di=='y'){
                        direc=yp;
                    }else{
                        direc=zp;
                    }
                }else{
                    if(di=='y'){
                        direc=ynn;
                    }else{
                        direc=zn;
                    }
                }
            }else if(direc==xn){
                if(sig=='+'){
                    if(di=='y'){
                        direc=ynn;
                    }else{
                        direc=zn;
                    }
                }else{
                    if(di=='y'){
                        direc=yp;
                    }else{
                        direc=zp;
                    }
                }
            }else if(direc==yp){
                if(sig=='+'){
                    if(di=='y'){
                        direc=xn;
                    }else{
                        direc=yp;
                    }
                }else{
                    if(di=='y'){
                        direc=xp;
                    }else{
                        direc=yp;
                    }
                }
            }else if(direc==ynn){
                if(sig=='+'){
                    if(di=='y'){
                        direc=xp;
                    }else{
                        direc=ynn;
                    }
                }else{
                    if(di=='y'){
                        direc=xn;
                    }else{
                        direc=ynn;
                    }
                }
            }else if(direc==zp){
                if(sig=='+'){
                    if(di=='y'){
                        direc=zp;
                    }else{
                        direc=xn;
                    }
                }else{
                    if(di=='y'){
                        direc=zp;
                    }else{
                        direc=xp;
                    }
                }
            }else{
                if(sig=='+'){
                    if(di=='y'){
                        direc=zn;
                    }else{
                        direc=xp;
                    }
                }else{
                    if(di=='y'){
                        direc=zn;
                    }else{
                        direc=xn;
                    }
                }
            }
            /*if(direc==xp){
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
            printf(" ");*/
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