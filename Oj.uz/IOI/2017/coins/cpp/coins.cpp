#include "coins.h"
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int C,x;
vi coin_flips(vi b, int c){
    for(int i=x=0;i<64;i++){
        if(b[i]){
            x^=i;
        }
    }
    return {x^c};
}
int find_coin(vi b){
    for(int i=C=0;i<64;i++){
        if(b[i]){
            C^=i;
        }
    }
    return C;
}