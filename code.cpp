#include<iostream>
using namespace std;

bool isMirror(TreeNode* a , TreeNode* b){
    if(a==NULL && b==NULL){
        return true;
    }
    if(a==NULL || b==NULL || a->val != b->val){
        return false;
    }
    return isMirror(a->left,b->right) && isMirror(a->right,b->left);
}

bool isSimilar(TreeNode root){
    return isMirror(root->left,root->right);
}


void topview(Node* root){
    queue<pair<Node* , int>>q;
    map<int,int>m;
    q.push(root,0);
    while(q.size()>0){
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();
        if(m.find(currHD)==m.end()){
            m[currHD] = curr->data;
        }
        if(curr->left != NULL){
            q.push(curr->left,currHD-1);
        }
        if(curr->right != NULL){
            q.push(curr->right,currHD+1);
        }
    }

    for(auto it : m){
        cout<<it.second<<" ";
    }
}

int maxDepth(Node* root){
    if(root==NULL){
        return 0;
    }
    int left_D = maxDepth(root->left);
    int right_D = maxDepth(root->right);
    return max(left_D,right_D)+1;
}


bool check_valid(Node* root, long long low, long long high){
    if(root==NULL){
        return true;
    }
    if(root->left <= low && root->right>=high){
        return false;
    }
    return check_valid(root->left,low,root->data)&&(root->right,root->data,high);
}
isValidBST(Node* root){
    return check_valid(root,LLONG_MIN,LLONG_MAX);
}

void merge(int arr[],int st,int mid,int end){
    int i=st;
    int j = mid+1;
    int nums[15];
    int k=0;
    while(i<=mid && j<= end){
        if(arr[i]<=arr[j]){
            nums[k] = arr[i];
            i++;
            k++;
        }else{
            nums[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i<=mid){
        nums[k] = arr[i];
        i++;
        k++;
    }

    while(j<=end){
        nums[k] = arr[j];
        j++;
        k++;
    }

    for(int x=0;x<k;x++){
        arr[st+x] = nums[x];
    }
}

void mergesort(int arr[],int st,int end){
    if(st<end){
        int mid = st + (end-st)/2;
        mergesort(arr,st,mid);
        mergesort(arr,mid+1,end);

        merge(arr,st,mid,end);
        
    }
}

int main(){
    int n = 9;
    int arr[n] = {21,20,19,18,17,16,15,14,13};
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

Node* LeastCommonAncestor(Node* root,Node* p,Node* q){
    if(root==NULL) return NULL;
    if(root==p || root==q){
        return root;
    }
    Node* leftLCA = LeastCommonAncestor(root->left,p,q);
    Node* rightLCA = LeastCommonAncestor(root->right,p,q);
    if(leftLCA && rightLCA){
        return root;
    }
    else if(leftLCA!=NULL){
        return leftLCA;
    }else{
        return rightLCA;
    }
}