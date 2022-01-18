#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string SL, SR;
    string str;
    int time = 0;
    string keyboard[3][10]={
        {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
        {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
        {'z', 'x', 'c', 'v', 'b', 'n', 'm'}
    };
    string Lk[] = {'q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v'};
    string Rk[] = {'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'b', 'n', 'm'};

    vector<pair <int, int>> v;

    cin >> SL >> SR;
    for(int i=0; i<3; i++){
        for(int j=0; j<10; j++){
            if(SL == keyboard[i][j])
                v.push_back(make_pair(i,j));
            if(SR == keyboard[i][j])
                v.push_back(make_pair(i,j))
        }
    }

    cin >> str;
    
    for(int i=0; i<Lk.size(); i++){

    }

}