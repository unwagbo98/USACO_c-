/*
ID: unwagbo1
PROG: money
LANG: C++
*/

// NAME             :   Ugo Nwagbo  
// LAST MODIFIED    :   27 Dec 2016
// PROLEM ID        :   Money Systems
// DESCRIPTION      :   A program to compute how many ways to construct 
//                      a given amount of money using supplied coinage.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
long long solve(int n, int coin_pos);
int V, N, coins[25];
long long ans[10001][25];



int main() {
    
    ofstream fout ("money.out");
    ifstream fin ("money.in");
    
    fin >> V >> N;
    for(int i = 0; i < V; i++){
        fin >> coins[i];
    }
    
    for(int i = 0; i <= N; ++i){
        for(int j = 0; j < V ; ++j){
            ans[i][j] = -1;
        } 
    }

    long long answer = solve(N, 0);

    fout << answer << endl;

    
    return 0;
}

long long solve(int n, int coin_pos){
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(coin_pos >= V) return 0;

    long long &ret = ans[n][coin_pos];

    if(ret != -1) return ret;
    
    ret = 0;
    
    ret += solve(n - coins[coin_pos], coin_pos);
    ret += solve(n, coin_pos + 1);
    return ret; 
}

