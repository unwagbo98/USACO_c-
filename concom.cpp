/*
ID: unwagbo1
PROG: concom
LANG: C++
*/

// NAME             :   Ugo Nwagbo  
// LAST MODIFIED    :   27 Dec 2016
// PROLEM ID        :   Controlling Companies
// DESCRIPTION      :   A program to read the list of triples (i,j,p) where i, j 
//                      and p are positive integers all in the range (1..100) 
//                      and find all the pairs (h,s) so that company h controls 
//                      company s.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int solve(int x, int y);
int N;
int ans[101][101];



int main() {
    
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");
    
    fin >>  N;
    int i, j;
    double p;
    
    for(int x = 0; x < 101; ++x){
        for(int y = 0; y < 101; ++y){
            ans[x][y] = -1;
        }
    }
    for(int x = 0; x < N; x++){
        fin >> i >> j >> p;
        ans[i][j] = p;
    }

    for(int x = 1; x < 101; ++x){
        for(int y = 1; y < 101; ++y){
           solve(x, y);
           if(ans[x][y] > 50){
                fout << x << " " << y << endl;
           }
        }
    }
    
    return 0;
}

int solve(int x, int y){

    
    int &ret = ans[x][y];

    if(ret != -1) return ret;
    
    ret = 0;
    if(x == y) return 0;
    
    for (int i = 1; i < 101; ++i)
    {
        if(solve(x, i) > 50)
            ret += solve(i, y); 
    }
  
    return ret; 
}

