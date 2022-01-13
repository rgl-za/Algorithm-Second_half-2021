/*
#include <iostream>
#define MAX 10
using namespace std;


int main(){
    int R, C;
    cin >> R >> C;

    char map[MAX][MAX]={0};
    char update_map[MAX][MAX]={0};

    for(int i=1; i<R+1; i++){
        for(int j=1; j<C+1; j++){
            cin >> map[i][j];
        }
    }

    int count = 0;
    for(int i=1; i<R+1; i++){
        for(int j=1; j<C+1; j++){
            if(map[i][j]== 'X'){
                if((map[i-1][j]=='.' || map[i-1][j]== 0) && (map[i+1][j]=='.' || map[i+1][j]== 0) && (map[i][j-1]=='.' || map[i][j-1]== 0)){
                    update_map[i][j]='.';
                }
                else if((map[i-1][j]=='.' || map[i-1][j]== 0) && (map[i+1][j]=='.' || map[i+1][j]== 0) && (map[i][j+1]=='.' || map[i][j+1]== 0)){
                    update_map[i][j]='.';
                }
                else if((map[i][j-1]=='.' || map[i][j-1]== 0) && (map[i][j+1]=='.' || map[i][j+1]== 0) && (map[i-1][j]=='.'|| map[i-1][j]== 0)){
                    update_map[i][j]='.';
                }
                else if((map[i][j-1]=='.' || map[i][j-1]== 0) && (map[i][j+1]=='.' || map[i][j+1]== 0) && (map[i+1][j]=='.' || map[i+1][j]== 0)){
                    update_map[i][j]='.';
                }
                else{

                }
            }
        }
    }
    for(int i=1; i<=R+1; i++){
        for(int j=1; j<=C+1; j++){
            cout << update_map[i][j];
        }
    }
    return 0;
 }
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int R, C;
    int count;
    int minX = 9999, minY = 9999, maxX= -1, maxY = -1;

    char map[12][12]={}, update_map[12][12]={};

    cin >> R >> C;

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> map[i][j];
            update_map[i][j]='.';

        }
    }

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            count = 0;
            if(map[i][j]== 'X'){
                // if(map[i-1][j]=='X' && map[i+1][j]=='X' && map[i][j-1]=='X'){
                //     count++;
                // }
                // if(map[i-1][j]=='X' && map[i+1][j]=='X' && map[i][j+1]=='X'){
                //     count++;
                // }
                // if(map[i][j-1]=='X' && map[i][j+1]=='X' && map[i-1][j]=='X'){
                //     count++;
                // }
                // if(map[i][j-1]=='X' && map[i][j+1]=='X' && map[i+1][j]=='X'){
                //    count++;
                // }
                if(map[i][j-1]=='X')
                    count++;
                if(map[i][j+1]=='X')
                    count++;
                if(map[i-1][j]=='X')
                    count++;
                if(map[i+1][j]=='X')
                    count++;        
                if(count == 2 || count == 3 || count == 4){
                    update_map[i][j]='X';
                    minX=min(i, minX);
                    minY=min(j, minY);
                    maxX=max(i, maxX);
                    maxY=max(j, maxY);
                }
            }
        }
    }
    for(int i=minX; i<=maxX; i++){
        for(int j=minY; j<=maxY; j++){
            cout << update_map[i][j];
        }
        cout << '\n';
    }
    return 0;
}