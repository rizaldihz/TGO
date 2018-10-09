#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    //Matrix testcase
    int banyak;

    printf("Masukkan banyak vertex : ");
    scanf("%d",&banyak);

    printf("Masukkan adjacency matrix\n");
    int adjmat[banyak][banyak];
    for(int i=0;i<banyak;i++){
        for(int j=0;j<banyak;j++){
            scanf("%d",&adjmat[i][j]);
        }
    }

    int awal;

    //Titik awal yang digunakan
    for(int awal=0;awal<banyak;awal++){

    //Inisiasi dist(G)
    int dist = INT_MAX;

    //Banyaknya permutasi dari seuluruh kemungkinan G{V-1}
    //sebanyak (V-1)!
    int ways=1;
    for(int i=1;i<banyak;i++) ways*=i;

    //List seluruh kemungkinan vertex bukan awal
    vector<int> vertex;
    //List seluruh kemungkinan path yang diambil
    vector<vector<int> > ans;

    //inisialisasi permutasi
    for(int i=0;i<banyak;i++){
        if(i!=awal) vertex.push_back(i);
    }

    //iterasi mencari dist(G) menggunakan permutasi
    while(ways--){
        int jaraktemp = 0;
        int temp = awal;
        //mencari tetangga nya
        for(int i=0;i<vertex.size();i++){
            //menambahkan jarak sesuai permutasi
            jaraktemp += adjmat[temp][vertex[i]];
            temp = vertex[i];
        }
        //menambahkan jarak dari titik terakhir permutasi ke titik awal
        jaraktemp+=adjmat[temp][awal];
        //update dist(G) dengan jarak tadi
        if(jaraktemp<=dist){
            if(jaraktemp<dist){
                for(int i=0;i<ans.size();i++){
                    ans.clear();
                }
            }
            dist = jaraktemp;
            //tambah kemungkinan jalan
            ans.push_back(vertex);
        }
        //update permutasi
        next_permutation(vertex.begin(),vertex.end());
    }
    printf("\nHamilton Cycle yang didapat adalah\n");
    for(int i=0;i<ans.size();i++){
        printf("%d->",awal);
        for(int j=0;j<ans[i].size();j++){
            printf("%d->",ans[i][j]);
        }
        printf("%d\n",awal);
    }
    printf("Dengan Minimum Cost : %d\n\n",dist);
    }
}
