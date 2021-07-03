/*
//내가 처음 시도한 풀이
//답은 맞게 나오나 틀렸다고 함
#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9 
using namespace std;

int n, m;
vector<pair<int, int> >graph[1001]; //각 노드에 연결되어 노드에 대한 정보를 담음
bool visited[1001]; //방문 노드 체크
int d[1001]; //최단 거리 

int getSmallestNode() {
    int min_value = INF;
    int index = 0; // 가장 최단 거리가 짧은 노드(인덱스)
    for (int i = 1; i <= n; i++) {
        if (d[i] < min_value && !visited[i]) {
            min_value = d[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int start) {
    d[start] = 0;  // 시작 노드에 대해서 초기화
    visited[start] = true;
    for (int j = 0; j < graph[start].size(); j++) {
        d[graph[start][j].first] = graph[start][j].second;
    }
    
    for (int i = 0; i < n - 1; i++) { // 시작 노드를 제외한 전체 n - 1개의 노드에 대해 반복
        int now = getSmallestNode();  // 현재 최단 거리가 가장 짧은 노드를 꺼내서, 방문 처리
        visited[now] = true;
        
        for (int j = 0; j < graph[now].size(); j++) { // 현재 노드와 연결된 다른 노드를 확인
            int cost = d[now] + graph[now][j].second;
           
            if (cost < d[graph[now][j].first]) {  // 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
                d[graph[now][j].first] = cost;
            }
        }
    }
}

int main(){
    int start, end;
    //vector<pair<int, int> >graph[10001];
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        // graph[a].push_back({b,c});
        graph[a].push_back(make_pair(b,c));
    }
    cin >> start >> end;
    
    fill_n(d,1001,INF); //최단거리 모두 무한으로 초기화
    d[start]=0;
    dijkstra(start);

    cout << d[end];
}
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

int n, m;
vector<pair<int, int> >graph[1001]; //각 노드에 연결되어 노드에 대한 정보를 담음
bool visited[1001]; //방문 노드 체크
int d[1001]; //최단 거리 

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq; // 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
    pq.push(make_pair(0,start));
    d[start] = 0;
    while (!pq.empty()) { // 큐가 비어있지 않다면 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        int dist = -pq.top().first; // 현재 노드까지의 비용 
        int now = pq.top().second; // 현재 노드
        pq.pop();
        
        if (d[now] < dist) continue;  // 현재 노드가 이미 처리된 적이 있는 노드라면 무시

        for (int i = 0; i < graph[now].size(); i++) {  // 현재 노드와 연결된 다른 인접한 노드들을 확인
            int cost = dist + graph[now][i].second;
           
            if (cost < d[graph[now][i].first]) {  // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}
int main(){
    int start, end;

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;


        graph[a].push_back(make_pair(b,c));
    }
    cin >> start >> end;
    
    fill_n(d,1001,INF); //최단거리 모두 무한으로 초기화

    dijkstra(start);

    cout << d[end];
}


