void ior(Node *root, vector<Node*> &ans){
    if(root != NULL){
        ior(root->left, ans);
        ans.push_back(root);
        ior(root->right, ans);
    }
}
void fun(struct Node *root,vector<int> &v)
{
    if(root==NULL)
    return;
    
    fun(root->left,v);
    if(root->data!=NULL)
    v.push_back(root->data);
    fun(root->right,v);
}

int findMedian(struct Node *root)
{
      vector<int> v;
      fun(root,v);
      int pos=v.size();
      
     
      if(pos%2==0)
      {
        return (v[pos/2]+v[(pos-1)/2])/2;  
      }
      else
      {
          return v[pos/2];
      }
}
int median(Node *node,int k){
    vector<Node*> ans;
    ior(node, ans);
    return findMedian(ans[k-1]);
}
