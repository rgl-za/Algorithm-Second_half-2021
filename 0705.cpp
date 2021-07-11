#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000+1
using namespace std;

int v, e, result;
int Parent[MAX];
vector<pair<int, pair<int, int>>> w;

int Find_Parent(int x){ // 부모를 찾는 find 함수
    if(Parent[x]==x)
        return x;
    else
        return Parent[x]==Find_Parent(Parent[x]);
}

void Union(int x, int y){
    x=Find_Parent(x);
    y=Find_Parent(y);
    
    if(x!=y){
        Parent[y]=x;
    }
}

bool sameParent(int x, int y){ // 노드 a와 b가 서로 같은 부모를 갖는지 판단

    x=Find_Parent(x);
    y=Find_Parent(y);

    if(x==y)
        return true;
    else
        return false;
}

void solve(){
    for(int i=1; i<=v; i++){
        Parent[i]=i;
    }
    for(int i=0; i<e; i++){
        if(sameParent(w[i].second.first, w[i].second.second)==false){
            Union(w[i].second.first, w[i].second.second);
            result=result+w[i].first;
        }
    }
}

int main(){
    cin >> v >> e;
    for(int i=0; i<e; i++){
        int start, end, weight;
        cin >> start >> end >> weight;

        w.push_back(make_pair(weight, make_pair(start, end)));
    }
    sort(w.begin(), w.end());

    solve();

    cout << result << endl;

    return 0;

}