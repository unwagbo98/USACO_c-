/*
ID: unwagbo1
PROG: nocows
LANG: C++
*/

// NAME             :   Ugo Nwagbo  
// LAST MODIFIED    :   27 Dec 2016
// PROLEM ID        :   Cow pedigrees
// DESCRIPTION      :   A program that will find how many different 
//                      possible pedigree structures there are

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int solve(int num_nodes, int height);
int smaller(int n, int h);

int exact[201][101], small[201][101];

int main() {
    ofstream fout ("nocows.out");
    ifstream fin ("nocows.in");
    for(int i = 0; i < 201; i++){
        for(int j = 0; j < 101; j++){
            exact[i][j] = -1;
            small[i][j] = -1;
        }
    }
    int num_nodes, height;
    fin >> num_nodes >> height;
    solve(num_nodes, height);
    int ans = exact[num_nodes][height] ; 
    fout << ans % 9901 << endl; 
    
    return 0;
}

int solve(int n, int h){ 
    if(h == 1 ){
        if(n == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(n <= 1) return 0;

    int &ans = exact[n][h];
    if(ans != -1) return ans;
    ans = 0;

    for(int l = 1; l <= n - 2; l += 2){ 
        int r = n - l - 1;
        ans += solve(l , h - 1) * solve(r, h - 1); 
        ans += solve(l , h - 1) * smaller(r, h - 2);
        ans += smaller(l , h - 2) * solve(r, h - 1);
        ans %= 9901;

    } 
    return ans;
}

int smaller(int n, int h){
    if(n < 0 || h <= 0) return 0;
    if(h == 1 ){
        if(n == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(n<=1) return 1;

    int &ans = small[n][h];
    if(ans != -1) return ans;
    ans = 0;

    for(int l = 1; l <= n - 2; l += 2){ //Iterates the left subtree
        int r = n - l - 1;
        ans += smaller(l , h - 1) * smaller(r, h - 1);
        ans %= 9901;  
    } 

    return ans;
}


