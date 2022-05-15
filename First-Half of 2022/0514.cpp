// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// ll a, b, c;
// ll go(ll a, ll b){
//     if(b==1)
//         return a % c;
//     ll _c = go(a, b/2);
//     _c = (_c * _c) % c;
//     if(b%2)
//         _c=(_c * a) % c;
//     return _c;
// }
// int main(){
//     cin >> a >> b >> c;
//     cout << go(a,b) << "\n";
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n, count[26]={0};
//     string name, result;
//     cin >> n;
//     for(int i=0; i<n; i++){
//         cin >> name;
//         count[name[0]-'a']++;
//     }
//     for(int i=0; i<26; i++) 
//         if(count[i]>=5) 
//             result+= i+'a';
    
//     if(result.size())
//         cout << result << "\n";
//     else
//         cout << "PREDAJA" << "\n";
    
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     while(cin >> n){
//         int temp=1;
//         for(int i=1; i<=n; i++){
//             temp = (temp*10)+1;
//             temp %= n;
//             if(temp==0){
//                 cout << i << "\n";
//                 break;
//             }
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,c,t;
    int a[6][50]={0};
    cin >> r >> c >> t;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<r; i++){
        for(int j=1; j<c; j++){
            if(a[i][j] == -1 || i == 1 || i == r || j == 1 || j == c){
                
            }
        }
    }
}