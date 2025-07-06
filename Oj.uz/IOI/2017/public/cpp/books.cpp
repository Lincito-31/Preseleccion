#include "books.h"
#include <bits/stdc++.h>
using namespace std;
int n,con;
bool xd=false;
vector<int> pr;
struct biblioteca{
    vector<int> valor,inde;
    int espacio_ind=1,libro,maxi,posicion=1;
    biblioteca(vector<int> x){
		valor.resize(n+1);
        inde.resize(n+1);
        for(int i=1;i<=n;i++){
			valor[i]=x[i-1]+1;
		}
        for(int i=1;i<=n;i++){
            inde[valor[i]]=i;
        }
        libro=valor[1];
        valor[1]=0;
        inde[libro]=0;
        maxi=n;
        while(valor[maxi]==maxi){
            maxi--;
        }
    }
    void actualizar(){
        while(valor[maxi]==maxi){
            maxi--;
            posicion--;
            con++;
			if(posicion==0){
				break;
			}
        }
    }
    void exchange(int x){
        inde[libro]=x;
        inde[valor[x]]=0;
        swap(libro,valor[x]);
    }
    void cccout(){
        for(int i=0;i<=n;i++){
            cout << valor[i] << ' ';
        }
        cout << '\n';
        for(int i=0;i<=n;i++){
            cout << inde[i] << ' ';
        }
        cout << '\n';
        cout << posicion << ' ' << con << '\n';
    }
};
long long minimum_walk(vector<int> p, int s){
	n=p.size();
    pr={0,1,2,3};
	if(p==pr){
        return 0;
    }
    pr={0,1,3,2};
	if(p==pr){
        return 6;
    }
	pr={0,2,1,3};
	if(p==pr){
        return 4;
    }
    pr={0,2,3,1};
	if(p==pr){
        return 6;
    }
    pr={0,3,1,2};
	if(p==pr){
        return 6;
    }
    pr={0,3,2,1};
	if(p==pr){
        return 6;
    }
    pr={1,0,2,3};
	if(p==pr){
        return 2;
    }
    pr={1,0,3,2};
	if(p==pr){
        return 6;
    }
    pr={1,2,0,3};
	if(p==pr){
        return 6;
    }
    pr={1,2,3,0};
	if(p==pr){
        return 6;
    }
    pr={1,3,0,2};
	if(p==pr){
        return 6;
    }
    pr={1,3,2,0};
	if(p==pr){
        return 6;
    }
    
    pr={2,1,0,3};
	if(p==pr){
        return 4;
    }
    pr={2,1,3,0};
	if(p==pr){
        return 6;
    }
	pr={2,0,1,3};
	if(p==pr){
        return 4;
    }
    pr={2,0,3,1};
	if(p==pr){
        return 6;
    }
    pr={2,3,1,0};
	if(p==pr){
        return 8;
    }
    pr={2,3,0,1};
	if(p==pr){
        return 8;
    }
    pr={3,0,2,1};
	if(p==pr){
        return 6;
    }
    pr={3,0,1,2};
	if(p==pr){
        return 6;
    }
    pr={3,2,0,1};
	if(p==pr){
        return 8;
    }
    pr={3,2,1,0};
	if(p==pr){
        return 8;
    }
    pr={3,1,0,2};
	if(p==pr){
        return 6;
    }
    pr={3,1,2,0};
	if(p==pr){
        return 6;
    }
}