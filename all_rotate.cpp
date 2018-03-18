void rot(vector<vector<int> > &A,int p,int q ){
   if(p > q)
      return;
   int rt = A[p][q],rb = A[q][q],lb = A[q][p];
   for(int j=q;j>p;j--)
      A[p][j] = A[p][j-1];
    for(int i=q;i>p;i--)
      A[i][q] = A[i-1][q];
    A[p+1][q] = rt;
    for(int j=p;j<q-1;j++)
      A[q][j] = A[q][j+1];
    A[q][q-1] = rb;
    for(int i=p;i<q-1;i++)
      A[i][p] = A[i+1][p];
    A[q-1][p] = lb;
    rot(A,p+1,q-1);
    return;
}
void Solution::rotate(vector<vector<int> > &A) {
    int n = A[0].size();
    rot(A,0,n-1);
}
