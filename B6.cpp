#include<iostream>
#include<string>
using namespace std;
class node
{
	public:
		int data;
		node *left;
		node *right;
};
class BST
{
	public:
		node *root;
		BST()
		{
			root==NULL;
		}
		void create();
		void insert();
		void preorder(node*);
		void inorder(node*);
		void postorder(node*);
		void search(int key);
		void min();
		int height(node*);
		void mirror(node*);
};
void BST::create()
{
	int ans;
	cout<<"Enter no. of keys:";
	cin>>ans;
	while(ans--)
		insert();
}
void BST::preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<"->"<<root->data;
		preorder(root->left);
		preorder(root->right);
	}
}
void BST::inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<"->"<<root->data;
		inorder(root->right);
	}
}
void BST::postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<"->"<<root->data;
	}
}
void BST::insert()
{
	node *curr,*temp;
	curr=new node();
	cout<<"Enter data:";
	cin>>curr->data;
	curr->left=curr->right=NULL;
	if(root==NULL)
		root=curr;
	else
	{
		temp=root;
		while(1)
		{
			if(curr->data<=temp->data)
			{
				if(temp->left==NULL)
				{
					temp->left=curr;
					break;
				}
				else
				{
					temp=temp->left;
				}
			}
			else
			{
				if(temp->right==NULL)
				{
					temp->right=curr;
					break;
				}
				else
				{
					temp=temp->right;
				}
			}
		}
	}
}
void BST::search(int key)
{
	node *temp;
	temp=root;
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			cout<<"Data found";
			break;
		}
		else
		{
			if(temp->data>key)
				temp=temp->left;
			else
				temp=temp->right;
		}
	}
	if(temp==NULL)
		cout<<"Data not found";
}
void BST::min()
{
	node *temp;
	temp=root;
	int min;
	while(temp->left!=NULL)
	{
		min=temp->data;
		temp=temp->left;
		if(temp->data<min)
			min=temp->data;
		else
			temp=temp->left;
	}
	cout<<"Minimum: "<<min;
}
int BST::height(node *root)
{
	if(root==NULL)
		return 0;
	else
	{
		if(height(root->right)>height(root->left))
			return(1+height(root->right));
		else
			return(1+height(root->left));
	}
}
void BST::mirror(node *root)
{
	if(root==NULL)
		return;
	else
	{
		mirror(root->left);
		mirror(root->right);
		swap(root->left,root->right);
	}
}
int main () {
    BST b;
    int key,ch;
    do {
        cout << "\n\n1.Create 2.Insert 3.Inorder 4.Preorder 5.Postorder 6.Search 7.Minimum 8.Height 9.Mirror 10.Exit\n";
        cout << "Your choice ";
        cin >> ch;
        switch (ch) {
            case 1:
                b.create ();
                break;
            case 2:
                cout << '\n';
                b.insert ();
                break;
            case 3:
                cout << "\nInorder   traversal is:";
                b.inorder (b.root);
                break;
            case 4:
                cout << "\nPreorder  traversal is:";
                b.preorder (b.root);
                break;
            case 5:
                cout << "\nPostorder traversal is:";
                b.postorder (b.root);
                break;
            case 6:
                cout << "\nEnter search key: ";
                cin >> key;
                b.search (key);
                break;
            case 7:
                b.min();
                break;
            case 8:
                cout << "\nHeight of tree: " << b.height (b.root);
                break;
            case 9:
                b.mirror (b.root);
                cout << "\nTree is now mirrored!!!"
                     << "\nInorder   traversal is:";
                b.inorder (b.root);
                cout << "\nPreorder  traversal is:";
                b.preorder (b.root);
                cout << "\nPostorder traversal is:";
                b.postorder (b.root);
                break;
            case 10:
                exit(0);
        }
    }while (ch < 11);
    return 0;
}

