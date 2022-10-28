//
// Created by w1z4Rd on 2022/10/27.
//

// #include "Solution.h"
#include<bits/stdc++.h>

using namespace std;
int m,t,s;// 苹果数量，吃一个苹果的时间，过去的时间

int main(){
    cin>>m>>t>>s;
    if(t==0){
        cout<<0<<endl;
        return 0;
    }
    int ans = s/t;
    if(ans>=m) { cout << 0 << endl;return 0;}
    else cout<<m-ans<<endl;
};