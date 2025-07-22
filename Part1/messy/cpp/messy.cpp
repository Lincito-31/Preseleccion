#include <vector>

#include "messy.h"
#include <bits/stdc++.h>
using namespace std;
string ask;
vector<int> permu;
vector<int> restore_permutation(int n, int w, int r){
    permu.resize(n);
    //if(n==8 || (n==32)){
        ask=string(n,'0');
        for(int i=0;i<n;i++){
            ask[i]='1';
            add_element(ask);
        }
        compile_set();
        ask=string(n,'0');
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ask[j]=='1'){
                    continue;
                }
                ask[j]='1';
                if(check_element(ask)){
                    // el j-esimo es i;
                    permu[j]=i;
                    break;
                }
                ask[j]='0';
            }
        }
    //}else{
        //nose
    //}
    return permu;
}
