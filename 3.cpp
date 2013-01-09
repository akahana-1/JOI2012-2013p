#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,a,count = 0;
    string str,tmp;
    bool f;
    cin >> n;
    cin >> str;
    for(int i = 0;i < n;++i){
        cin >> tmp;
        for(int i = 0;i < tmp.size();++i){
            a = 0;
            if(tmp[i] == str[a]){
                ++a;
                int dis = 0;
                while(i + dis < tmp.size() - 1){
                    ++dis;
                    f = true;
                    if(tmp[i + dis] == str[a] && i + (dis * 2) < tmp.size()){ 
                        for(int j = i + (dis * 2);j < tmp.size();j+=dis){
                            if(a == str.size() - 1) break;
                            if(tmp[j] != str[++a]){
                                f = false;
                                break;
                            }
                        }
                    }
                    else f = false;
                    if(f) {
                        ++count;
                        break;
                    }
                    a = 1;
                }
                if(f) break;
            }
        }
    }
    cout << count << endl;
    return 0;
}