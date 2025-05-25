#include "game.h"
#include <bits/stdc++.h>
using namespace std;
int N,clave[1500];
void initialize(int n){N=n;}
int hasEdge(int u, int v){return ++clave[u=max(u,v)]==u;}
