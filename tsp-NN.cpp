#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int main()
{
    int banyak;
    printf("Masukkan banyak vertex: ");
    scanf("%d",&banyak);
    printf("Masukkan adjacency matrix:\n");
    int adjmat[banyak][banyak];
    for(int i=0;i<banyak;i++){
        for(int j=0;j<banyak;j++){
            scanf("%d",&adjmat[i][j]);
        }
    }
    int awal;
    for(awal=0;awal<banyak;awal++){
    printf("%d-",awal);
    priority_queue<int, vector<int>,greater<int> > terpendek;

    int jarak[banyak];
    for(int i=0;i<banyak;i++) jarak[i] = INT_MAX;
    jarak[awal] = 0;
    int dist = 0;
    for(int i=0;i<banyak;i++){
        if(adjmat[awal][i]!=0) terpendek.push(adjmat[awal][i]);
    }
    int now = (find(adjmat[awal],adjmat[awal]+banyak,terpendek.top()))-&adjmat[awal][0];
    int temp = terpendek.top();
    jarak[(find(adjmat[awal],adjmat[awal]+banyak,temp))-&adjmat[awal][0]]=temp;
    dist+=temp;
    terpendek.pop();
    while(!terpendek.empty()) terpendek.pop();
    int posisi = now;
    for(int i=0;i<banyak-2;i++){
        printf("%d-",posisi);
        bool found = false;
        for(int j=0;j<banyak;j++){
            if(adjmat[posisi][j]!=0&&adjmat[posisi][j]!=jarak[posisi]) terpendek.push(adjmat[posisi][j]);
        }
        now=posisi;
        while(!found){
            posisi = (find(adjmat[now],adjmat[now]+banyak,terpendek.top()))-&adjmat[now][0];
            if(jarak[posisi]==INT_MAX){
               jarak[posisi] = terpendek.top();
               dist+=terpendek.top();
               found = true;
            }
            terpendek.pop();
        }
        while(!terpendek.empty()) terpendek.pop();
    }
    printf("%d-",posisi);
    printf("%d\n",awal,jarak[posisi],dist);
    printf("Minimum cost dari graf: %d\n",dist+adjmat[posisi][awal]);
    }
}
