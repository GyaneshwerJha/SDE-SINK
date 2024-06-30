class DSU{
vector<int> rank, parent;
public:
    DSU(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }


    int FUP(int node){
        if(node == parent[node]) return node;
        return parent[node] = FUP(parent[node]);
    }

    void UBR(int u, int v){
        int up_u = FUP(u);
        int up_v = FUP(v);

        if(up_u == up_v) return;

        if(rank[up_u] < rank[up_v]){
            parent[up_u] = up_v;
        }
        else if(rank[up_v] < rank[up_u]){
            parent[up_v] = up_u;
        }
        else{
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU Alice(n);
        DSU Bob(n);

        int aliceEdge = 0;
        int bobEdge = 0;

        int reqNode = 0;


        sort(edges.begin(), edges.end(), [](vector<int> &vec1, vector<int> &vec2){
            return vec1[0] > vec2[0];
        });

        for(auto edge : edges){
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];
            int isTrue = false;
            if(type == 3){
                // for Alice
                if(Alice.FUP(u) != Alice.FUP(v)){
                    Alice.UBR(u, v);
                    aliceEdge++;
                    isTrue = true;
                }

                // for Bob
                if(Bob.FUP(u) != Bob.FUP(v)){
                    Bob.UBR(u, v);
                    bobEdge++;
                    isTrue = true;
                }

                if(isTrue){
                    reqNode++;
                }
            }
            else if(type == 2){
                // Bob only
                if(Bob.FUP(u) != Bob.FUP(v)){
                    Bob.UBR(u, v);
                    bobEdge++;
                    reqNode++;
                }
            }
            else{
                if(Alice.FUP(u) != Alice.FUP(v)){
                    Alice.UBR(u, v);
                    aliceEdge++;
                    reqNode++;
                }
            }
        }

        int s = edges.size();
        return aliceEdge == n - 1 && bobEdge == n - 1 ? s - reqNode : -1;
    }
};