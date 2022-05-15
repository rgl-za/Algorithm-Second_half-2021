// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     string str, temp;
//     cin >> str;

//     temp = str;
//     reverse(str.begin(), str.end());
//     // sort(str.begin(), str.end(), greater<int>());

//     if(str==temp)
//         cout << 1 << "\n";
//     else
//         cout << 0 << "\n";
// }

#include <bits/stdc++.h>
using namespace std;
int main(){
    string dopa = "life is limited";
    
    cout << dopa.substr(0,3) << "\n";

    reverse(dopa.begin(), dopa.end());
    cout << dopa << "\n";
    cout << dopa << "dopa!!" << "\n";
}