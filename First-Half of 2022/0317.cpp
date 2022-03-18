#include <iostream>
#include <string>
using namespace std;

int main(){
    int count = 0;
    string str;

    cin>>str;

    for(int i=0; i<str.length(); i++){
        count++;
        if(str[i]=='.'){
            count--;
            if(count == 2){
                for(int j=1; j<=2; j++)
                    str[i-j]='B';
                count = 0;
            } 
        }
        else{
           if(count == 4){
               for(int j=0; j<4; j++)
                    str[i-j]='A';
                count =0;
           }
           if(i==str.length()-1){
               if(count == 2){
                   for(int j=1; j<=2; j++)
                        str[i-j]='B'; 
                    count=0;
               }
           }
        } 
    }
    if(str.find('X') != std::string::npos)
        cout << -1 << endl;
    else
        cout << str << endl;
    
    
}