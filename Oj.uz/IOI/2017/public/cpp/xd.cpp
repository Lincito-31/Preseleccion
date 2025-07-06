#include "books.h"
#include <bits/stdc++.h>
using namespace std;
int n,con;
bool xd=false;
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
	biblioteca pub(p);
    pub.posicion++;
    con++;
    //pub.cccout();
	for(;pub.posicion<pub.maxi;pub.posicion++,con++){
        if(pub.valor[pub.posicion]>pub.libro){
            pub.exchange(pub.posicion);
        }
    }
    pub.exchange(pub.posicion);
    pub.actualizar();
    while(pub.maxi>0){
        if(pub.libro==pub.posicion){
            pub.exchange(pub.posicion);
            pub.actualizar();
            //pub.cccout();
            continue;
        }
        for(;pub.posicion>0;pub.posicion--,con++){
            if(pub.valor[pub.posicion]<pub.libro){
                pub.exchange(pub.posicion);
            }else if(pub.valor[pub.posicion]==pub.maxi){
                pub.exchange(pub.posicion);
                pub.posicion++;
                con++;
                for(;pub.posicion<pub.maxi;pub.posicion++,con++){
                    if(pub.valor[pub.posicion]>pub.libro){
                        pub.exchange(pub.posicion);
                    }
                }
                pub.exchange(pub.posicion);
                break;
            }
        }
    }
	return con-2;
}
int main() {
	int n, s;
	assert(2 == scanf("%d %d", &n, &s));

	vector<int> p((unsigned) n);
	for(int i = 0; i < n; i++)
		assert(1 == scanf("%d", &p[(unsigned) i]));

	long long res = minimum_walk(p, s);
	printf("%lld\n", res);

	return 0;
}
