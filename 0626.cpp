//14719

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int h, w, result=0;

    cin >> h >> w;

    vector<int> v(w);

    for(int i=0; i<w; i++)
        cin >> v[i];   

    for(int i=1; i<w-1; i++){
        int left=0, right=0;
        for(int j=0; j<i; j++){
            left=max(left, v[j]);
        }
        for(int j=w-1; j>i; j--){
            right=max(right, v[j]);
        }
        
        result+=max(0, min(left,right)-v[i]);
        
    }
    cout<<result<<endl;

    return 0;
}


//1062
//내가 시도한 방법

#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    
    int n,k, sum=0;
    cin >> n >> k;
    char str[n];
    vector<char>v;

    for(int i=0; i<n; i++){
        cin >> str;
    
        char *ptr = strtok(str, "antatica");
        int count=0;
        while(ptr!=NULL){
            count=strlen(ptr);
            cout<<ptr<<endl;
            sum+=count;
            if(sum>k)
                break;
            cout<<sum;
            ptr=strtok(NULL, "antatica");
            } 
            
        }
        return 0;
    }

