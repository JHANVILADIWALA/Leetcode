vector <int> bottomView(Node *root) {
        vector<int>ans;
        if(root==NULL)return ans;
        
        queue<pair<Node *, int>>q;
        //         node    line
        q.push({root,0});
        
        map<int,int>m;
        //line node
        
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            
            Node * node= it.first;
            int line = it.second;
            m[line]=node->data;
            
            //left
            if(node->left!=NULL){
                q.push({node->left, line-1});
            }
            
            //right
            if(node->right!=NULL){
             q.push({node->right, line+1});
            } 
        }
        
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
