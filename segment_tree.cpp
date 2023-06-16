struct Node{
    int val;
    Node(){
        val=0;
    }
    Node(int x){
        val=x;
    }
    void merge(Node &l,Node &r){
        val=l.val+r.val;
    }
};
struct Update{
    int val;
    Update(int x){
        val=x;
    }
    void apply(Node &a){
        a.val=val;
    }
};
 
struct SegTree{
    vector<Node> tree;
    vector<int> arr;
    int n;
    int s;
    SegTree(int a_len,vector<int> &a){
        arr=a;
        n=a_len;
        s=1;
        while(s<2*n){
            s=s<<1;
        }
        tree.resize(s);fill(all(tree),Node());
        build(0,n-1,1);
    }
 
    void build(int start,int end,int index){
        if(start==end){
            tree[index]=Node(arr[start]);
            return;
        }
        int mid=(start+end)/2;
        build(start,mid,2*index);
        build(mid+1,end,2*index+1);
        tree[index].merge(tree[2*index],tree[2*index+1]);
    }
 
    Node query(int start,int end,int index,int left,int right){
        if(start>right or end<left){
            return Node();
        }
        if(start>=left and end<=right){
            return tree[index];
        }
        Node l,r,ans;
        int mid=(start+end)/2;
        l=query(start,mid,2*index,left,right);
        r=query(mid+1,end,2*index+1,left,right);
        ans.merge(l,r);
        return ans;
    }
    Node make_query(int left,int right){
        return query(0,n-1,1,left,right);
    }
 
    void update(int start,int end,int index,int query_index,Update &u){
        if(start==end){
            u.apply(tree[index]);
            return;
        }
 
        int mid=(start+end)/2;
        if(mid>=query_index){
            update(start,mid,2*index,query_index,u);
        }
        else{
            update(mid+1,end,2*index+1,query_index,u);
        }
        tree[index].merge(tree[2*index],tree[2*index+1]);
    }
    void make_update(int index,int val){
        Update new_update= Update(val);
        update(0,n-1,1,index,new_update);
    }
};