#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int card[200][3],point[200],used[101];
    int n;
    memset(card,0,sizeof(card));
    memset(point,0,sizeof(point));
    memset(used,0,sizeof(used));
    cin >> n;
    for(int i = 0;i < n;++i){
        for(int j = 0;j < 3;++j){
            cin >> card[i][j];
        }
    }
    for(int i = 0;i < 3;++i){
        for(int j = 0;j < n;++j){
            ++used[card[j][i]];
        }
        for(int j = 0;j < n;++j){
            if(used[card[j][i]] == 1) point[j] += card[j][i];
        }
        memset(used,0,sizeof(used));
    }
    for(int i = 0;i < n;++i){
        cout << point[i] << endl;
    }
    return 0;
}