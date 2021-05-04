#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<ii> vii;
#define pq priority_queue
#define tc int t; cin>>t; while(t--)
#define pb push_back
#define ff first
#define ss second
#define MP make_pair
#define fastboi cin.tie(0) -> sync_with_stdio(0)
#define file_read(x,y) freopen(x, "r", stdin); \
                    freopen(y, "w", stdout);


int main (void)
{
 fastboi;
    int n, m;
    cin >> n >> m;

    vvi adj;
    queue<int> q;
    vb visited(n, 0);
    vi d(n, 0) , p; // d is dist from origin and p stores prev node visited

    adj = vvi(n, vi());
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b; 
        a--;b--;
        adj[a].pb(b);
        // adj[b].pb(a);
    }

    int k, count = 0;
    int s; // here s is the ID of user for which we will be checking friends
    cin >> k >> s;
    s--;
    q.push(s);
    visited[s]= true;
    // p[s] = -1;
    d[s] = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < adj[v].size(); i++) // traversing through the adj list of v
        {
            int u = adj[v][i];
            if(!visited[u]){
                visited[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                if(d[u] > 1 && count < k){
                    // p.pb(u);
                    count++;
                    // display user info here
                }
            }
        }
        if(count >= k){
            break;
        }
    }

    // for(auto s: p){
    //     cout << s+1 << " ";
    // }
    cout << endl;


 return 0;
}