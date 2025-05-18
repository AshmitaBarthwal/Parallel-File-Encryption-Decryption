//https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1



/* A binary tree node has data, pointer to left child
   and a pointer to right child
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution 
{
  public:
    vector<int> findSpiral(Node* root) 
    {
        vector<int> ans;
        if(root == NULL) return ans;

        stack<Node*> s1; 
        stack<Node*> s2; 

        s1.push(root);

        while(!s1.empty() || !s2.empty())
        {
            while(!s1.empty()) 
            {
                Node* curr = s1.top(); s1.pop();
                ans.push_back(curr->data);

                if(curr->right) s2.push(curr->right);
                if(curr->left) s2.push(curr->left);
            }

            while(!s2.empty()) 
            {
                Node* curr = s2.top(); s2.pop();
                ans.push_back(curr->data);

                if(curr->left) s1.push(curr->left);
                if(curr->right) s1.push(curr->right);
            }
        }

        return ans;
        
    }
};
