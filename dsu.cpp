//////////DSU-START//////////
vector<int> parent;
void make_set(int v) {
    parent[v] = v;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}
//////////DSU-END////////////

void solve(int tt){
  int n;cin>>n;
  parent.resize(n+1);//if using 1 based indexing
  for(int i=1;i<=n;i++) make_set(i);
  for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;//should be same based indexing as above
    union_sets(a,b);
  }
}