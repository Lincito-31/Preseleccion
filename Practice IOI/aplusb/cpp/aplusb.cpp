#include "aplusb.h"
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi a,b;
void initialize(vi A,vi B){
  a=A;
  b=B;
}
int answer_question(int i, int j){return a[i]+b[j];}