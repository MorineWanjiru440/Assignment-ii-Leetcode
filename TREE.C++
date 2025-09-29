#include<iostream>
using namespace std;
struct treenode{
	int val;
	treenode*left;
	treenode*right;
	treenode():val(0),left(NULL),right(NULL){}
	treenode(int x):val(x),left(NULL),right(NULL){}
  	treenode(int x, treenode*left, treenode*right):val(x),left(left),right(right){}
};
class solution{
	public:
		bool issymmetric(treenode*root){
			if(root==NULL)
			{
				return true;
			}
			return ismirror(root->left,root->right);
		}
		private:
			bool ismirror(treenode*left,treenode*right){
				if(left==NULL&&right==NULL)return true;
				if(left==NULL||right==NULL)return false;
				return (left->val==right->val)&&
			ismirror(left->left,right->right)&&
			ismirror(left->right,right->left);
			}
};
treenode*createsymmetrictree(){
	treenode*root=new treenode(1);
	root->left=new treenode(2);
	root->right=new treenode(2);
	root->left->left=new treenode(3);
	root->left->right=new treenode(4);
	root->right->left=new treenode(4);
	root->right->right=new treenode(3);
	return root;	
}
treenode*createasymmetrictree(){
	treenode*root=new treenode(1);
	root->left=new treenode(2);
	root->right=new treenode(2);
	root->left->right=new treenode(3);
	root->right->right=new treenode(3);
	return root;	
}
void deletetree(treenode*root){
	if(root==NULL)return;
	deletetree(root->left);
    deletetree(root->right);
    delete root;
}
int main(){
	solution solution;
	treenode*symmetrictree=createsymmetrictree();
	cout<<"symmetric tree:"<<(solution.issymmetric(symmetrictree)?"true":"false")<<endl;
	deletetree(symmetrictree);
	treenode*asymmetrictree=createasymmetrictree();
	cout<<"asymmetric tree:"<<(solution.issymmetric(asymmetrictree)?"true":"false")<<endl;
	deletetree(asymmetrictree);
	cout<<"empty tree:"<<(solution.issymmetric(NULL)?"true":"false")<<endl;
	treenode*singlenode=new treenode(1);
	cout<<"single node tree:"<<(solution.issymmetric(singlenode)?"true":"false")<<endl;
	delete singlenode;
	return 0;
}