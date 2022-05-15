// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     string str;
//     int alpa[26]={0};
//     cin >> str;
//     for(int i=0; i<str.size(); i++){
//          alpa[str[i]-'a']++;
//     }
//     // for(char a: str){
//         // alpa[a-'a']++;
//     // }
//     for(int i=0; i<26; i++){
//         cout << alpa[i] << " ";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "123";
    s[0]++;
    cout << s << "\n";
    return 0;
}
