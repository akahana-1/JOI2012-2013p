#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,ap[200][3],tempe[200],dp[200][200];
int f(int day,int bval){
    if(day == n) return 0;
    int vmax = 0,a,b;
    for(int i = 0;i < m;++i){
        if(ap[i][0] <= tempe[day] && tempe[day] <= ap[i][1]){
            a = bval - ap[i][2];
            if(a < 0) a *= -1;
            if(dp[day][i] > 0) b = dp[day][i];
            else{
                b = f(day+1,ap[i][2]);
                dp[day][i] = max(dp[day][i],b);
            }
            if(day != 0) vmax = max(vmax,a+b);
            else vmax = max(vmax,b);
        }
    }
    return vmax;
}
int main(){
    memset(ap,0,sizeof(ap));
    memset(tempe,0,sizeof(tempe));
    memset(dp,0,sizeof(dp));
    cin >> n >> m;
    for(int i = 0;i < n;++i){
        cin >> tempe[i];
    }
    for(int i = 0;i < m;++i){
        for(int j = 0;j < 3;++j){
            cin >> ap[i][j];
        }
    }
    cout << f(0,0) << endl;
    return 0;
}