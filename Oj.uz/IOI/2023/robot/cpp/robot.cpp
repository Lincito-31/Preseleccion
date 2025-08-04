#include "robot.h"
#include <bits/stdc++.h>
using namespace std;
set<vector<int>> existe;
void program_pulibot(){
    //iniciar
    vector<int> tapado={-1,-2};
    vector<int> todo={0,1,-1,-2};
    //left
    for(auto i:todo){
        // down
        //for(auto j:tapado){
            //right
            //for(auto k:tapado){
                //up
                for(auto l:todo){
                    if(existe.count({0,i,-2,-2,l})==0){
                        existe.insert({0,i,-2,-2,l});
                        set_instruction({0,i,-2,-2,l},1,'T');
                    }
                }
            //}
        //}
    }
    for(auto i:todo){
        // down
        for(auto j:todo){
            //right
            //for(auto k:todo){
                //up
                for(auto l:todo){
                    if(existe.count({0,i,j,0,l})==0){
                        existe.insert({0,i,j,0,l});
                        set_instruction({0,i,j,0,l},1,'E');
                    }
                }
            //}
        }
    }
    for(auto i:todo){
        // down
        //for(auto j:todo){
            //right
            for(auto k:todo){
                //up
                for(auto l:todo){
                    if(existe.count({0,i,0,k,l})==0){
                        existe.insert({0,i,0,k,l});
                        set_instruction({0,i,0,k,l},1,'S');
                    }
                }
            }
        //}
    }
    for(auto i:todo){
        // down
        for(auto j:todo){
            //right
            for(auto k:todo){
                //up
                //for(auto l:todo){
                    if(existe.count({0,i,j,k,0})==0){
                        existe.insert({0,i,j,k,0});
                        set_instruction({0,i,j,k,0},1,'N');
                    }
                //}
            }
        }
    }
}
