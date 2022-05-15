// #include <bits/stdc++.h>
// using namespace std;

// vector<string> split(string input, string delimiter){
//     vector<string> ret;
//     long long pos=0;
//     string token ="";
//     while((pos = input.find(delimiter))!= string::npos){
//         token = input.substr(0,pos);
//         ret.push_back(token);
//         input.erase(0, pos+delimiter.length());
//     }
//     ret.push_back(input);
//     return ret;
// }

// int main(){
//     string s = "안녕하세요. 보리는 바보에요. 정말로요.";
//     string d = " ";
//     vector<string> a = split(s,d);
//     for(string b : a) cout << b << "\n";
// }

// #include <bits/stdc++.h>
// using namespace std;
// vector<int> a;
// int b[5];
// int main(){
// 	for(int i=5; i>=1; i--) b[i-1] = i;
//     for(int i=5; i>=1; i--) a.push_back(i);
    
//     // 오름차순
//     sort(b,b+5);
//     sort(a.begin(),a.end());
//     for(int i: b) cout << i << ' ';
//     cout << '\n';
//     for(int i: a) cout << i << ' ';
//     cout << '\n';
    
//     sort(b, b+5, less<int>());
//     sort(a.begin(), a.end(), less<int>());
//     for(int i: b) cout << i << ' ';
//     cout << '\n';
//     for(int i: a) cout << i << ' ';
//     cout << '\n';
    
//     // 내림차순
//     sort(b, b+5, greater<int>());
//     sort(a.begin(), a.end(), greater<int>());
//     for(int i: b) cout << i << ' ';
//     cout << '\n';
//     for(int i: a) cout << i << ' ';
//     cout << '\n';
    
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first; 
}
int main(){
for(int i = 10; i >= 1; i--){ 
    v.push_back({i, 10 - i});
}
sort(v.begin(), v.end(), cmp);
for(auto it : v) cout << it.first << " : " << it.second << "\n";
    return 0;
}