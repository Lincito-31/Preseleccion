#include <bits/stdc++.h>
using namespace std;
int n,a,b;
int main(){
    stack<int> pila;
    queue<int> cola;
    priority_queue<int> colaprio;
    bool xd=true,xd1=true,xd2=true,xd3=true;
    int con=3;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        if(a==1){
            pila.push(b);
            cola.push(b);
            colaprio.push(b);
        }else{
            if(pila.empty()){
                xd=false;
                break;
            }
            int x=pila.top();pila.pop();
            int y=cola.front();cola.pop();
            int z=colaprio.top();colaprio.pop();
            if(xd1 && b!=x){
                xd1=false;
                con--;
            }
            if(xd2 && b!=y){
                xd2=false;
                con--;
            }
            if(xd3 && b!=z){
                xd3=false;
                con--;
            }
        }
    }
    if(xd){
        if(con==0){
            printf("imposible");
        }else if(con>=2){
            printf("indefinido");
        }else{
            if(xd1){
                printf("pila");
            }else if(xd2){
                printf("cola");
            }else{
                printf("cola de prioridad");
            }
        }
    }else{
        printf("imposible");
    }
}