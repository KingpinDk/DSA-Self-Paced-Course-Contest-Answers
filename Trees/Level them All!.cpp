int Count(Node *node,int L){
    //Your code here
    int lvl = 1;
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        if(L == lvl)
        return q.size();
        int t = q.size();
        while(!q.empty() and t--){
            Node* curr = q.front();
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
            q.pop();
        }
        lvl++;
    }
    return 0;
}
