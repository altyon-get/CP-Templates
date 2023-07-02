//variable input:    int n, vi v
//variable created:  int m,vvi dp
//////////START:building parse table////////////
int m=31-__builtin_clz(n);
vector<vector<int>> dp(n,vector<int>(m+1,0)); //identity for gcd=0
for(int i=n-1;i>=0;i--){
  for(int j=0;j<m+1;j++){
      if(j==0) dp[i][j]=v[i];
      else {
          int i2=i + ( 1<<(j-1) ) ;
          dp[i][j]=__gcd( dp[i][j-1] , i2<n? dp[ i2 ][j-1]: 0  );
     }
  }
}
auto gcd = [&](int l, int r) {                     //asked:  <---------------------->
      int len=r-l+1;                               //rng1:   <------------->
      int x=31-__builtin_clz(len);                 //rng2:             <------------->
      return __gcd(dp[l][x],dp[r-(1<<x)+1][x]);    //since gcd is self inverting function, intersection will not matter  
};
//////////END:building parse table////////////