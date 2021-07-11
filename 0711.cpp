//BOJ 2252
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n,m; // 노드 개수, 간선 개수
int indegree[100001]; //노드 진입차수
vector<int> v[32001]; //노드의 간선 정보를 담기 위한 연결리스트

void topologySort(){
    vector<int> result; //알고리즘 수행 결과를 담을 리스트
    queue<int> q; //뷰 라이브러리

    for(int i=1; i<=n; i++){ //처음 시작할 때 진입차수가 0인 노드를 큐에 삽입
        if(indegree[i]==0)
            q.push(i);
    }

    while(!q.empty()){ //큐가 빌 때까지
        //큐에서 원소 꺼내기
        int now = q.front();
        q.pop();
        result.push_back(now);

        for(int i=0; i<v[now].size(); i++){ //해당 원소와 연결된 노드들의 진입차수에서 1 빼기
            indegree[v[now][i]]-=1;

            if(indegree[v[now][i]]==0) //새롭게 진입차수가 0이 되는 노드를 큐에 삽입
                q.push(v[now][i]);
        }
    }

    for(int i=0; i<result.size(); i++) //위상정렬을 수헹한 결과 출력
        cout << result[i] << ' ';
}
int main(){
    cin >> n >> m;

    for(int i=0; i<m; i++){ //방향 그래프의 모든 간선 정보 입력 받기
        int s1, s2;
        cin >> s1 >> s2;
        
        v[s1].push_back(s2);
        
        //진입차수 1 증가
        indegree[s2] +=1;
    } 
    topologySort();
}


// 시뮬레이션 연습: 왕실의 나이트
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string position;

    int dx[]={2, -2, 1, -1, 2, -2, 1, -1};
    int dy[]={1, 1, 2, 2, -1, -1, -2, -2};

    cin >> position;

    int row = position[1]-'0';
    int column=position[0]-'a'+1;

    int result=0;

    for(int i=0; i<8; i++){
        int nextrow=row + dx[i];
        int nextcolumn=column + dy[i];

        if(nextrow>=1 && nextrow<=8 && nextcolumn>=1 && nextcolumn<=8)
            result++;
    }

    cout << result << endl;
}



//시뮬레이션 연습: 게임 개발
#include <iostream>
using namespace std;

int main(){
    int n, m, x, y, r, count =1, turn =0;

    //동서남북 방향 정의
    int dx[]={-1, 0, 1, 0};
    int dy[]={0, 1, 0, -1};

    int map[50][50]; //전체 맵 정보
    int start[50][50]; //방문 위치 정보

    cin >> n >> m;

    cin >> x >> y >> r;
    start[x][y]=1; //현재 위치 체크

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x;
            cin >> x;
            map[i][j]=x;
        }
    }

    while(true){
        //왼쪽으로 회전
        r-=1;
        if(r==-1)
            r=3;

        int nx= x+dx[r];
        int ny = y+dy[r];

        //회전한 이후 정면에 가보지 않은 칸이 존재할 경우 이동
        if(start[nx][ny]==0 && map[nx][ny]==0){
            start[nx][ny]=1;
            x=nx;
            y=ny;
            count++;
            turn =0;
            continue;
        }
        else //회전한 이후 정면에 가보지 않은 칸이 없거나 바다인 경우
            turn +=1;

        // 네 면 모두 갈 수 없는 경우
        if(turn ==4){
            nx=x-dx[r];
            ny=y-dy[r];

            //뒤로 갈 수 있다면 이동
            if(map[nx][ny]==0){
                x=nx;
                y=ny;
            }
            else //뒤도 막혀 있다면
                break;
            turn =0;
        }
    }


    cout << count<< endl;

}