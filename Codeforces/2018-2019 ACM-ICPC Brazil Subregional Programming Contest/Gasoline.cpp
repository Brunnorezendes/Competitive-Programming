#include <bits/stdc++.h>

using namespace std;

int this_time;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0, time;
    FlowEdge(int v, int u, long long cap, int time) : v(v), u(u), cap(cap), time(time){}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap, int time) {
        edges.emplace_back(v, u, cap, time);
        edges.emplace_back(u, v, 0, time);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }
    
    void reset(){
        for(int i=0;i<edges.size();i++)
            edges[i].flow = 0;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                if (edges[id].time > this_time)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1 || edges[id].time > this_time)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int main(){
    int p, r, c, i, u, v, w, source = 0, sink = 1, ini = 0, fim = 0, expected_tot = 0, j;
    cin >> p >> r >> c;
    Dinic D = Dinic(p+r+2, source, sink);
    for(i=0;i<p;i++){
        cin >> w;
        expected_tot += w;
        D.add_edge(i+2, sink, w, 0);
    }
    for(i=0;i<r;i++){
        cin >> w;
        D.add_edge(source, i+p+2, w, 0);
    }
    for(i=0;i<c;i++){
        cin >> v >> u >> w; v--;u--;
        fim = max(fim, w);
        D.add_edge(u+p+2, v+2, D.flow_inf, w);
    }
    while(ini<fim){
        this_time = (ini+fim)/2;
        if(D.flow()==(long long int)expected_tot){
            fim = this_time;
        }
        else{
            ini = this_time + 1;
        }
        D.reset();
    }
    this_time = ini;
    if(D.flow()==expected_tot) cout << this_time << endl;
    else cout << "-1\n" << endl;
    return (0);
}