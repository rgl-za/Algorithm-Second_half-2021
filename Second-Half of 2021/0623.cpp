#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num;
vector<int>v(11);
vector<int>op(4);
int mx = -1000000001, mn= 1000000001;

void operate(int index, int answer, int add, int sub, int mul, int div){
    if(index == num){
        if(answer>mx)
            mx=answer;
        if(answer<mn)
            mn=answer;
        return;
    }
    if(add)
        operate(index+1, answer+v[index], add-1, sub, mul, div);
    if(sub)
        operate(index+1, answer-v[index], add, sub-1, mul, div);
    if(mul)
        operate(index+1, answer*v[index], add, sub, mul-1, div);
    if(div)
        operate(index+1, answer/v[index], add, sub, mul, div-1);
}


int main(){
    cin >> num;

    for(int i=0; i<num; i++){
        cin>> v[i];
    }
    for(int i=0; i<4; i++){
        cin>>op[i];
    }
    operate(1, v[0], op[0], op[1], op[2], op[3]);
    cout<<mx<<"\n"<<mn;

    return 0;
}
