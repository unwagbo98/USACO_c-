/*
ID: unwagbo1
PROG: zerosum
LANG: C++
*/

// NAME             :   Ugo Nwagbo  
// LAST MODIFIED    :   27 Dec 2016
// PROLEM ID        :   Zero Sum
// DESCRIPTION      :   A program that will find all sequences of length N 
//                      that produce a zero sum.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
void solve(string x, int n, int num, int factor, int sum);
int N;
ofstream fout ("zerosum.out");

int main() {
    
    ifstream fin ("zerosum.in");
    
    fin >> N;
    char x[(2*N) - 1];
    solve("1", 1, 1, 1, 0);
    
    return 0;
}
void solve(string x, int n, int num, int factor, int sum){
    if(n == N){
        if(sum + factor * num == 0) fout << x << endl;
        return;
    } 
    solve(x+" "+char('0'+n+1), n+1, num*10+n+1, factor, sum);
    solve(x+"+"+char('0'+n+1), n+1, n+1, 1, sum+factor*num);
    solve(x+"-"+char('0'+n+1), n+1, n+1, -1, sum+factor*num);   
}