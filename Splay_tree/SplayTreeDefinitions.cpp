#include <iostream>
#include "Splay.h"
using namespace std;

template <class T>
Splay<T> :: Splay()
{
	nullnode = new node(0, NULL, NULL);
	nullnode->left = nullnode->right = nullnode;
	root = nullnode;
}

template <class T>
void Splay<T> :: singlerotatewithleft(node *&k2)
{
	node *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2 = k1;
}

template <class T>
void Splay<T> :: singlerotatewithright(node *&k2)
{
	node *k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2 = k1;
}

/*
template <class T>
void Splay<T> :: makeempty(node *&t)
{
	if(t != NULL)
	{
		makeempty(t->left);
		makeempty(t->right);
		delete t;
	}
	t = NULL;
}

template <class T>
Splay<T> :: ~Splay()
{
	makeempty(root);
	delete nullnode;
}*/

template <class T>
void Splay<T> :: splayt(const T&x, node *&t)
{
	node *ltmax, *rtmin;
	static node header(0, NULL, NULL);
	header.left = header.right = nullnode;
	ltmax = rtmin = &header;
	nullnode->element = x;
	for (;;)
		if (x < t->element)
		{
		    if (x < t->left->element)
		        singlerotatewithleft(t);
		        
		    if (t->left == nullnode)
		        break;
		    rtmin->left = t;
		    rtmin = t;
		    t = t->left;
		}
		else if (x > t->element)
		{
		    if (x > t->right->element)
		        singlerotatewithright(t);
		        
		    if (t->right == nullnode)
		        break;
		    ltmax->right = t;
		    ltmax = t;
		    t = t->right;
		}
		else
		    break;
	ltmax->right = t->left;
	rtmin->left = t->right;
	t->left = header.right;
	t->right = header.left;
}

template <class T>
void Splay<T> :: insert(const T &x)
{
	static node *newnode = NULL;
	if (newnode == NULL)
	{
	   newnode = new node(0, NULL, NULL);
	}
	newnode->element = x;

	if (root == nullnode)
	{
	   newnode->left = newnode->right = nullnode;
	   root = newnode;
	}
	else
	{
	   splayt(x, root);
	   if (x < root->element)
	   {
	        newnode->left = root->left;
	        newnode->right = root;
	        root->left = nullnode;
	        root = newnode;
	   }
	   else if (x > root->element)
	   {
	        newnode->left = root;
	
	        newnode->right = root->right;
	        root->right = nullnode;
	        root = newnode;
	   }
	   else
	        return;
	}
	newnode = NULL;
}

template <class T>
void Splay<T> :: remove(const T &x)
{
	node *newtree;
	if (root == nullnode)
	   return;
	   
	splayt(x, root);
	if (x != root->element)
	   return;
	   
	if (root->left == nullnode)
	   newtree = root->right;
	   
	else
	{
	   newtree = root->left;
	   splayt(x, newtree);
	   newtree->right = root->right;
	}
	
	delete root;
	root = newtree;
}

template <class T>
void Splay<T> :: inorder(node *&t)
{
	if(t != nullnode)
	{
		cout << t->element << " ";
		inorder(t->left);
		
		inorder(t->right);
	}
} 

/*
template class Splay<int>;
template class Splay<float>;
template class Splay<char>;
*/