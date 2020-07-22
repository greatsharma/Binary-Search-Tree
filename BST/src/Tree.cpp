#include"../header/print.h"
#include"../header/Tree.h"

Node* Tree::root = 0;

void Tree::insert_node(const int data_insert, Node *curr_ptr, Node *prev_ptr)
{
	if (curr_ptr)
	{
	prev_ptr = curr_ptr;
	curr_ptr = (data_insert < curr_ptr->data) ? curr_ptr->left : curr_ptr->right;
	insert_node(data_insert,curr_ptr,prev_ptr);
	}
	else
	{
		Node *new_node = new Node(data_insert);
		if(prev_ptr) (data_insert < prev_ptr->data) ? prev_ptr->left = new_node : prev_ptr->right = new_node;
		else
			root = new_node;
	}
}

void Tree::Preorder(const Node *curr_ptr) const
{
	if (curr_ptr)
	{
		print(curr_ptr->data);
		Preorder(curr_ptr->left);
		Preorder(curr_ptr->right);
	}
}

void Tree::Inorder(const Node *curr_ptr) const
{
	if (curr_ptr)
	{
		Inorder(curr_ptr->left);
		print(curr_ptr->data);
		Inorder(curr_ptr->right);
	}
}

void Tree::Postorder(const Node *curr_ptr) const
{
	if (curr_ptr)
	{
		Postorder(curr_ptr->left);
		Postorder(curr_ptr->right);
		print(curr_ptr->data);
	}
}

void Tree::PreorderIt(const Node *curr_ptr)
{
	if (curr_ptr)
	{
		no_of_leaves(curr_ptr);
		no_of_internal_nodes(curr_ptr);
		stack s(noLv + noInNode);
		s.push(curr_ptr);
		
		while (!s.isEmpty())
		{
			const Node *node = s.pop();
			print(node->data);
			if (node->right) s.push(node->right);
			if (node->left) s.push(node->left);
		}
	}
}

void Tree::PostorderIt(const Node *p)
{
	if (p)
	{
		no_of_leaves(p);
		no_of_internal_nodes(p);
		stack s(noLv + noInNode);
		const Node *q = p;
		
		while (p!=0)
		{
			for (; p->left != 0; p = p->left) s.push(p);
			while (p->right == 0 || p->right == q) 
			{
				print(p->data);
				q = p;  
				if (s.isEmpty()) return; 
				p = s.pop(); 
			}
			s.push(p);
			p = p->right;
		}
	}
}

void Tree::InorderIt(const Node *p)
{
	if (p)
	{
		no_of_leaves(p);
		no_of_internal_nodes(p);
		stack s(noLv + noInNode);

		while (p != 0)
		{
			while (p != 0)
			{
				if (p->right)
					s.push(p->right);
				s.push(p);
				p = p->left;
			}
			p = s.pop();
			while (!s.isEmpty() && p->right == 0)
			{
				print(p->data);
				p = s.pop();
			}
			print(p->data);
			if (!s.isEmpty())
				p = s.pop();
			else p = 0;
		}
	}
}

void Tree::breadthFirstTraversal(const Node *curr_ptr)
{
	if (curr_ptr)
	{
		no_of_leaves(curr_ptr);
		no_of_internal_nodes(curr_ptr);
		queue q(noLv + noInNode);
		q.enqeue(curr_ptr);

		while (!q.isEmpty())
		{
			const Node *node = q.deqeue();
			print(node->data);
			if (node->left) q.enqeue(node->left);
			if (node->right) q.enqeue(node->right);
		}
	}
}

void Tree::clear(Node *curr_ptr)
{
	if (curr_ptr)
	{
		clear(curr_ptr->left);
		clear(curr_ptr->right);
		delete curr_ptr;
	}
	root = 0;
}

const Node* Tree::returnRightNodeWithData(int data, const Node *curr_ptr) const
{
	if (curr_ptr)
	{
		if (data < curr_ptr->data) returnRightNodeWithData(data, curr_ptr->left);
		else if (data > curr_ptr->data) returnRightNodeWithData(data, curr_ptr->right);
		else return curr_ptr->right;
	}
	else return 0;
}

int Tree::count_right_childs(const Node *curr_ptr, int count) const
{
	if (curr_ptr)
	{
		++count;
		int c = count_right_childs(curr_ptr->left, count);
		count_right_childs(curr_ptr->right, c);
	}
	else return count;
}

void Tree::search(int data_find,const Node *curr_ptr) const
{
	if (curr_ptr)
	{
		if (curr_ptr->data == data_find)
		{
			print("found");
			return;
		}
		curr_ptr = (data_find < curr_ptr->data) ? curr_ptr->left : curr_ptr->right;
		search(data_find, curr_ptr);
	}
	else
		print("not found");
}

void Tree::deleteByCopy(int data_del, Node *curr_ptr, Node *prev_ptr)
{
	if (curr_ptr)
		if (data_del < curr_ptr->data) deleteByCopy(data_del, curr_ptr->left, curr_ptr);
		else if(data_del > curr_ptr->data) deleteByCopy(data_del, curr_ptr->right, curr_ptr);
		else
		{	// THE WELL OF HELL SECTION
			if (!curr_ptr->left && !curr_ptr->right)
				(prev_ptr->left == curr_ptr) ? prev_ptr->left = 0 : prev_ptr->right = 0;
			else if (!curr_ptr->left && curr_ptr->right || curr_ptr->left && !curr_ptr->right)
				if (prev_ptr->right == curr_ptr && curr_ptr->right) prev_ptr->right = curr_ptr->right;
				else if (prev_ptr->right == curr_ptr && curr_ptr->left) prev_ptr->right = curr_ptr->left;
				else if (prev_ptr->left == curr_ptr && curr_ptr->left) prev_ptr->left = curr_ptr->left;
				else prev_ptr->left = curr_ptr->right;
			else
			{
				Node *temp = curr_ptr;
				prev_ptr = curr_ptr->right;
				while (prev_ptr->left != 0)
				{
					temp = prev_ptr;
					prev_ptr = prev_ptr->left;
				}
				curr_ptr->data = prev_ptr->data;
				curr_ptr = prev_ptr;
				temp->left = 0;
			}
			delete curr_ptr;
			print("data deleted");
		}
	else print("data is not present");
}

void Tree::deleteByMerge(int data_del, Node *curr_ptr, Node *prev_ptr)
{
	if (curr_ptr)
		if (data_del < curr_ptr->data) deleteByMerge(data_del, curr_ptr->left, curr_ptr);
		else if (data_del > curr_ptr->data) deleteByMerge(data_del, curr_ptr->right, curr_ptr);
		else
			if (curr_ptr->left && curr_ptr->right)
			{
				Node *temp = curr_ptr->right;
				while (temp->left != 0)
					temp = temp->left;
				temp->left = curr_ptr->left;
				(prev_ptr->left == curr_ptr) ? prev_ptr->left = curr_ptr->right : prev_ptr->right = curr_ptr->right;
				if (curr_ptr == root) root = curr_ptr->right;
				delete curr_ptr;
			}
			else deleteByCopy(data_del, curr_ptr, prev_ptr);
	else print("data is not present");
}

bool Tree::check(int n, const Node *p) const 
{
	if (!p->left && !p->right &&n == 1) return true;
	else if (p->left && p->right) return (check(n - 1, p->left) && check(n - 1, p->right));
	else return false;
}

int Tree::height_tree(const Node *curr_ptr) const
{
	if (curr_ptr)
	{
		int l = height_tree(curr_ptr->left);
		int r = height_tree(curr_ptr->right);
		return (l > r) ? l + 1 : r + 1;
	}
	else
		return 0;
}

bool Tree::is_leave(int data_lv,const Node *curr_ptr) const
{
	if (curr_ptr)
	{
		if(data_lv == curr_ptr->data)
		{
			if (!curr_ptr->left && !curr_ptr->right) return true;
			else return false;
		}

		curr_ptr = (data_lv < curr_ptr->data) ? curr_ptr->left : curr_ptr->right;
		is_leave(data_lv, curr_ptr);
	}
	else
	{
		print("element is not present in tree");
		return false;
	}
}

void Tree::no_of_leaves(const Node *curr_ptr)
{
	if (curr_ptr)
	{
		if (!curr_ptr->left && !curr_ptr->right) ++noLv;
		no_of_leaves(curr_ptr->left);
		no_of_leaves(curr_ptr->right);
	}
}

void Tree::no_of_internal_nodes(const Node *curr_ptr)
{
	if (curr_ptr)
	{
		if (curr_ptr->left || curr_ptr->right) ++noInNode;
		no_of_internal_nodes(curr_ptr->left);
		no_of_internal_nodes(curr_ptr->right);
	}
}

Node* Tree::copy_tree(const Node *curr_ptr) const
{
	static Node *new_tree_root = new Node(curr_ptr->data, curr_ptr->left, curr_ptr->right);

	if (curr_ptr)
	{
		if(curr_ptr != root) Node *new_node = new Node(curr_ptr->data, curr_ptr->left, curr_ptr->right);
		if (curr_ptr->left) copy_tree(curr_ptr->left);
		if (curr_ptr->right) copy_tree(curr_ptr->right);
	}

	return new_tree_root;
}

Node* Tree::mirror_tree(Node *prev_node,const Node *curr_ptr,char ch) const
{
	Node *new_node = new Node(curr_ptr->data);
	static Node *new_tree_root = new_node;
	if (ch == 'r') prev_node->left = new_node;
	else if (ch == 'l') prev_node->right = new_node;

	if (curr_ptr->right) mirror_tree(new_node,curr_ptr->right,'r');
	if (curr_ptr->left) mirror_tree(new_node,curr_ptr->left,'l');
	
	return new_tree_root;
}

void Tree::display(const Node *ptr, int space) const
{
	if (!ptr)
		return;
	space++;
	display(ptr->right, space);
	for (int i = 1; i < space; i++)
		std::cout << "	  ";
	std::cout << ptr->data << "\n";
	display(ptr->left, space);
}

Tree::~Tree() {}