#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* right, *left;
    node(){
        right = NULL;
        left = NULL;
    }
};
struct tree{
    vector<int> ino, post, pre, newPost;
    node*root;
    int n;
    void inp(){
        cin>>n;
        ino = vector<int> (n);
        post = vector<int> (n);
        pre = vector< int> (n);
        newPost = vector<int> (n);
        for(int i=0;i<n;++i)
            cin>>pre[i];
        for(int i=0;i<n;++i)
            cin>>post[i];
        for(int i=0;i<n;++i)
            cin>>ino[i];
    }
    void postord(node*root)
    {
        static int a=0;
        if(root->left != NULL) postord(root->left);
        if( root->right != NULL) postord( root->right );
        newPost[a++] = root->data;
    }
    node* makeTree(int inStrt, int inEnd){
        static int preIndex = 0;
        if( inStrt > inEnd) 
            return NULL;
        node *tNode;
        tNode = new node;
        tNode->left = NULL;
        tNode->right = NULL;
        tNode->data = pre[preIndex++];
        if( inStrt == inEnd)
            return tNode;
        int i;
        for( i=inStrt;i<=inEnd;i++)
            if( ino[i] == tNode->data)
                break;
        int inIndex = i;
        
        tNode->left =makeTree(inStrt, inIndex-1);
        tNode->right = makeTree(inIndex+1, inEnd);
        
        return tNode;
    }
    void sol(){
        root  = makeTree(0, n-1);
        postord(root); // makeing the newPost of the tree created from the in and pre
        bool flag = true;
        for( int i=0;i<n;++i){
            if( post[i] != newPost[i]){
                flag = false;
                break;
            }
        }
        if( flag )
        cout<<"yes"<<endl;
        else 
            cout<<"no"<<endl;
    }
};
int main(void){
    tree t;
    t.inp();
    t.sol();
    
    return 0;
}