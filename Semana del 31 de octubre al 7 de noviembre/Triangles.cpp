#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
int n,q,t,a,b;
vi nums;
map<int,int> operator+ (map<int,int> x,map<int,int> y){
    for(auto u:y){
        x[u.first]+=u.second;
    }
    return x;
}
map<int,int> operator- (map<int,int> x,map<int,int> y){
    for(auto u:y){
        x[u.first]-=u.second;
        if(x[u.first]==0){
            x.erase(u.first);
        }
    }
    return x;
}
vi operator- (vi x,vi y){
    for(int i=0;i<32;i++){
        x[i]-=y[i];
    }
    return x;
}
vi operator+ (vi x,vi y){
    for(int i=0;i<32;i++){
        x[i]+=y[i];
    }
    return x;
}
class FenwickTree {
    private:
        vector<map<int,int>> ft;
    public:
        FenwickTree(vi aaaaa) {
            int m=aaaaa.size();
            vector<map<int,int>> acum(m);
            for(int i=1;i<m;i++){
                acum[i]=acum[i-1];
                acum[i][nums[i]]++;
            }
            ft.resize(m);
            for(int i=1;i<m;i++){
                ft[i]=acum[i]-acum[i-LSOne(i)];
            }
        }
        map<int,int> rsq(int j) {
            map<int,int> sum;
            for (; j; j-=LSOne(j)){
                sum=sum+ft[j];
            }
            return sum;
        }
        map<int,int> rsq(int i, int j) { return rsq(j) - rsq(i-1); }
        void update(int pos,int val,int ante) {
            for (; pos < (int)ft.size(); pos += LSOne(pos)){
                ft[pos][ante]--;
                if(ft[pos][ante]==0){
                    ft[pos].erase(ante);
                }
                ft[pos][val]++;
            }
        }
};
class PrefixSum {
    private:
        vector<map<int,int>> ps;
    public:
        PrefixSum(vi aaaaa) {
            int m=aaaaa.size();
            ps.resize(m);
            for(int i=1;i<m;i++){
                ps[i]=ps[i-1];
                ps[i][nums[i]]++;
            }
        }
        map<int,int> rsq(int i, int j){return ps[j]-ps[i-1];}
};
class TASK4 {
    private:
        vector<vi> pot;
    public:
        TASK4(vi aaaaa) {
            int m=aaaaa.size();
            vector<vi> acum(m,vi(32));
            for(int i=1;i<m;i++){
                acum[i]=acum[i-1];
                acum[i][nums[i]]++;
            }
            pot.resize(m);
            for(int i=1;i<m;i++){
                pot[i]=acum[i]-acum[i-LSOne(i)];
            }
        }
        vi rsq(int j) {
            vi sum(32);
            for (; j; j-=LSOne(j)){
                sum=sum+pot[j];
            }
            return sum;
        }
        vi rsq(int i, int j) { return rsq(j) - rsq(i-1); }
        void update(int pos,int val,int ante) {
            for (; pos < (int)pot.size(); pos += LSOne(pos)){
                pot[pos][ante]--;
                pot[pos][val]++;
            }
        }
};
int main(){
    scanf("%d%d",&n,&q);
    nums.resize(n+1);
    bool task4=true;
    bool task5=true;
    for(int i=1;i<=n;i++){
        scanf("%d",&nums[i]);
        if(__builtin_popcount(nums[i])!=1){
            task4=false;
        }
    }
    if(task4){
        for(int i=1;i<=n;i++){
            nums[i]=__builtin_ctz(nums[i]);
        }
        TASK4 aux(nums);
        while(q--){
            scanf("%d%d%d",&t,&a,&b);
            a++;
            if(t){
                bool xdround=false;
                b++;
                vi prueb=aux.rsq(a,b);
                int res=0;
                int temp=0;
                for(int i=31;i>=0;i--){
                    if(xdround && prueb[i]>0){
                        temp+=1<<i;
                        res=temp;
                        break;
                    }
                    if(prueb[i]>=3){
                        res=3*(1<<i);
                        break;
                    }
                    if(prueb[i]==2){
                        temp+=2*(1<<i);
                        xdround=true;
                    }
                }
                printf("%d\n",res);
            }else{
                b=__builtin_ctz(b);
                int x=nums[a];
                nums[a]=b;
                aux.update(a,b,x);
            }
        }
    }else{
        vector<vi> quer(q,vi(3));
        for(int qq=0;qq<q;qq++){
            scanf("%d%d%d",&quer[qq][0],&quer[qq][1],&quer[qq][2]);
            if(!quer[qq][0]){
                task5=false;
            }
        }
        if(task5){
            PrefixSum aux(nums);
            for(int qq=0;qq<q;qq++){
                t=quer[qq][0];
                a=quer[qq][1];
                b=quer[qq][2];
                a++;b++;
                map<int,int> prueb=aux.rsq(a,b);
                int res=-1;
                int nue=-1;
                /*map<int,int> prueb;
                for(auto u:prueba){
                    prueb[u.first]=u.second;
                }*/
                auto p=prueb.end();
                p--;
                int last=1e18,penu=1e17,antepenu=p->first;
                if(p->second>=2){
                    last=penu;
                    penu=antepenu;
                }
                if(antepenu+penu>last){
                    res=antepenu+penu+last;
                }
                if(p->second>=3){
                    last=penu;
                    penu=antepenu;
                }
                if(antepenu+penu>last){
                    res=antepenu+penu+last;
                }
                if(res==-1){
                    while(p!=prueb.begin()){
                        p--;
                        last=penu;
                        penu=antepenu;
                        antepenu=p->first;
                        if(antepenu+penu>last){
                            res=antepenu+penu+last;
                            break;
                        }
                        if(p->second>=2){
                            last=penu;
                            penu=antepenu;
                        }
                        if(antepenu+penu>last){
                            res=antepenu+penu+last;
                            break;
                        }
                        if(p->second>=3){
                            last=penu;
                            penu=antepenu;
                        }
                        if(antepenu+penu>last){
                            res=antepenu+penu+last;
                            break;
                        }
                    }
                }
                if(res==-1){
                    res=0;
                }
                printf("%d\n",res);
            }
        }else{
            FenwickTree aux(nums);
            for(int qq=0;qq<q;qq++){
                t=quer[qq][0];
                a=quer[qq][1];
                b=quer[qq][2];
                a++;
                if(t){
                    //query
                    b++;
                    map<int,int> prueb=aux.rsq(a,b);
                    int res=-1;
                    int nue=-1;
                    /*map<int,int> prueb;
                    for(auto u:prueba){
                        prueb[u.first]=u.second;
                    }*/
                    auto p=prueb.end();
                    p--;
                    int last=1e18,penu=1e17,antepenu=p->first;
                    if(p->second>=2){
                        last=penu;
                        penu=antepenu;
                    }
                    if(antepenu+penu>last){
                        res=antepenu+penu+last;
                    }
                    if(p->second>=3){
                        last=penu;
                        penu=antepenu;
                    }
                    if(antepenu+penu>last){
                        res=antepenu+penu+last;
                    }
                    if(res==-1){
                        while(p!=prueb.begin()){
                            p--;
                            last=penu;
                            penu=antepenu;
                            antepenu=p->first;
                            if(antepenu+penu>last){
                                res=antepenu+penu+last;
                                break;
                            }
                            if(p->second>=2){
                                last=penu;
                                penu=antepenu;
                            }
                            if(antepenu+penu>last){
                                res=antepenu+penu+last;
                                break;
                            }
                            if(p->second>=3){
                                last=penu;
                                penu=antepenu;
                            }
                            if(antepenu+penu>last){
                                res=antepenu+penu+last;
                                break;
                            }
                        }
                    }
                    if(res==-1){
                        res=0;
                    }
                    printf("%d\n",res);
                }else{
                    //update
                    int x=nums[a];
                    nums[a]=b;
                    aux.update(a,b,x);
                }
            }
        }
    }
}