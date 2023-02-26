#include<bits/stdc++.h>
#include "Myutilities.h"
using namespace std;
int minEditDistance(string s1, string s2, int m, int n) {
    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }
    if (s1[m-1] == s2[n-1]) {
        return minEditDistance(s1, s2, m-1, n-1);
    }
    int insert = minEditDistance(s1, s2, m, n-1);
    int remove = minEditDistance(s1, s2, m-1, n);
    int replace = minEditDistance(s1, s2, m-1, n-1);
    return 1 + min({insert, remove, replace});
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int m=s1.length(),n=s2.length();
    int result=minEditDistance(s1,s2,m,n);
    cout<<result;
    return 0;
}
    