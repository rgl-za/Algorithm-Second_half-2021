#include <iostream>
#include <stack>
#include <string>
using namespace std;

string input;
stack<char>c;

int main(){
    cin >> input;

    int result = 0, temp = 1;
    bool flag = false;

    for(int i=0; i<input.size(); i++){
        if(input[i]=='('){
            temp*=2;
            c.push('(');
        }
        else if(input[i]=='['){
            temp*=3;
            c.push('[');
        }
        else if(input[i]==')' && (c.empty() || c.top()!='(')){
            flag = true;
            break;
        }
        else if(input[i]==']' && (c.empty() || c.top()!='[')){
            flag = true;
            break;
        }
        else if(input[i]==')'){
            if(input[i-1]=='(')
                result+=temp;
            c.pop();
            temp/=2;
        }
        else if(input[i]==']'){
            if(input[i-1]=='[')
                result+=temp;
            c.pop();
            temp/=3;
        }
    }
    if(flag || !c.empty())
        cout << 0 << endl;
    else
        cout << result << endl;
    
    return 0;

}
