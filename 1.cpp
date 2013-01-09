#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n,ta,tb;
    double a,b,c,d;
    cin >> n;
    cin >> a >> b >> c >> d;
    a /= c;
    b /= d;
    ta = (int)(ceil(a));
    tb = (int)(ceil(b));
    if(ta > tb){
        cout << n - ta << endl;
    }
    else {
        cout << n - tb << endl;
    }
    return 0;
}