#include <iostream>
using namespace std;

template <class T>
class Splay
{
	struct node
	{
		T element;
		node *left;
		node *right;
		node(const T&x, node *l, node *r) : element(x), left(l), right(r)
		{}
		node() : element(0), left(NULL), right(NULL)
		{}
	};
	
	node *root;
	node *nullnode;
	
	public:
		Splay();
		void singlerotatewithleft(node *&k2);
		void singlerotatewithright(node *&k2);
		void makeempty(node *&t);
		//~Splay();
		void splayt(const T&x, node *&t);
		void insert(const T&x);
		void remove(const T&x);
		void inorder(node *&t);
		void display()
		{
			cout << "\nThe Inorder Traversal of the Splay Tree : ";
			inorder(root);
			cout <<"\n";
		}
}; 
