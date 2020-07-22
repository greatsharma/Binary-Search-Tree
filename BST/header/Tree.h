#ifndef __TREE__
#define __TREE__

#include "Queue.h"
#include "Stack.h"

class Tree
{
private:
	static Node *root;

public:
	int noLv;
	int noInNode;
	Tree() { noLv = 0; noInNode = 0; }
	void insert_node(const int,Node *curr_node=root, Node *prev_ptr=0);
	void Preorder(const Node *curr_ptr = root) const;
	void Inorder(const Node *curr_ptr=root) const;
	void Postorder(const Node *curr_ptr = root) const;
	void PreorderIt(const Node *curr_ptr = root);
	void PostorderIt(const Node *curr_ptr = root);
	void InorderIt(const Node *curr_ptr = root);
	void breadthFirstTraversal(const Node *curr_ptr = root);
	void search(int,const Node *curr_node = root) const;
	void deleteByCopy(int, Node *curr_node = root, Node *prev_ptr=root);
	void deleteByMerge(int, Node *curr_node = root, Node *pre_ptr = root);
	void clear(Node *curr_ptr = root);
	const Node* returnRightNodeWithData(int data, const Node *curr_ptr=root) const;
	int count_right_childs(const Node *curr_node, int count=0) const;
	bool check(int n, const Node *p=root) const;
	int height_tree(const Node *curr_node=root) const;
	bool is_leave(int,const Node *curr_node = root) const;
	void no_of_leaves(const Node *curr_node = root);
	void no_of_internal_nodes(const Node *curr_node = root);
	Node* copy_tree(const Node *curr_node=root) const;
	Node* mirror_tree(Node *prev_node=0,const Node *curr_node = root,char ch='p') const;
	void display(const Node *ptr=root, int space=0) const;

	~Tree();
};

#endif