#include <iostream>
#include <vector>
using namespace std;



int main() {
    // 멍청한 방법....
    // int a, b, c, d, e, f;
    // int x = 1, y = 1, z = 1;

    // cin >> a >> b >> c;
    // cin >> d >> e >> f;

    // int update_a, update_d;

    // int result;

    // update_a = a * d;
    // b *= d;
    // c *= d;

    // update_d = d * a;
    // e *= a;
    // f *= a;

    // x *= update_a-update_d;
    // y *= b-e;
    // z = c-f;

    vector<int> N(6);
    for(int i = 0; i<6; i++)
        cin >> N[i];

    for(int x = -1000; x <= 1000; x++){
        for(int y= -1000; y <= 1000; y++) {
            int first = N[0]*x + N[1]*y - N[2];
            int second = N[3]*x + N[4]*y - N[5];
            if(first == 0 && second == 0){
                cout << x << ' ' << y;
            }
        }
    }
    return 0;
}