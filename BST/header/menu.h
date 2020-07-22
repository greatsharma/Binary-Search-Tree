#ifndef __MENU__
#define __MENU__

#include "print.h"
#include "Tree.h"

int data;

void menu(Tree &t)
{
	print("=========MENU==========");
	print("1. INSERT NODE");
	print("2. DELETE NODE BY COPY");
	print("3. SEARCH ELEMENT");
	print("4. PREORDER TRAVERSAL RECURSIVE");
	print("5. INORDER TRAVERSAL RECURSIVE");
	print("6. POSTORDER TRAVERSAL RECURSIVE");
	print("7. IS A LEAVE?");
	print("8. NO OF LEAVES");
	print("9. NO OF NODES");
	print("10. HEIGHT OF TREE");
	print("11. CLEAR");
	print("12. COPY TREE");
	print("13. MIRROR A TREE");
	print("14. BREADTH FIRST SEARCH");
	print("15. Display");
	print("16. DELETE NODE BY MERGING");
	print("17. PREORDER TRAVERSAL ITERATIVE");
	print("18. INORDER TRAVERSAL ITERATIVE");
	print("19. POSTORDER TRAVERSAL ITERATIVE");
	print("20. Get Node Address with known data");
	print("21. NO OF RIGHT CHILDS");
	print("22. complete or not");
	print("23. EXIT");

	print("Enter your choice : ");
	int choice;
	std::cin >> choice;

	Node *new_tree_root;
	int arr[] = { 50,20,40,25,60,90,10,55,45,15,58,80,0,100,52 };

	switch (choice)
	{
	case 1:
		//print("Enter data to be inserted : ");
		//std::cin >> data;
		//t.insert_node(data);
		for (int i = 0; i < 15; i++)
			t.insert_node(arr[i]);
		break;

	case 2:
		print("Enter data to be deleted : ");
		std::cin >> data;
		t.deleteByCopy(data);
		break;

	case 3:
		print("Enter data to be searched : ");
		std::cin >> data;
		t.search(data);
		break;

	case 4:
		print("preorder : ");
		t.Preorder();
		break;

	case 5:
		print("inorder : ");
		t.Inorder();
		break;

	case 6:
		print("postorder : ");
		t.Postorder();
		break;

	case 7:
		print("Enter element to check for leave : ");
		std::cin >> data;
		t.is_leave(data) ? print("is a leave") : print("not a leave");
		break;

	case 8:
	{
		print("no of leaves are : ");
		t.no_of_leaves();
		print(t.noLv);
		t.noLv = 0;
	}
	break;

	case 9:
	{	print("no of nodes are : ");
		t.no_of_internal_nodes();
		print(t.noInNode);
		t.noInNode = 0;
	}
	break;

	case 10:
		print("height is : ");
		print(t.height_tree()-1);
		break;

	case 11:
		t.clear();
		break;

	case 12:
		new_tree_root = t.copy_tree();
		print("copied tree : ");
		t.display(new_tree_root);
		break;

	case 13:
		new_tree_root = t.mirror_tree();
		print("===================\n\n");
		//t.Inorder(new_tree_root);
		t.display(new_tree_root);
		break;

	case 14:
		print("breadth traversal");
		t.breadthFirstTraversal();
		break;

	case 15:
		t.display();
		break;

	case 16:
		print("Enter data to be deleted : ");
		std::cin >> data;
		t.deleteByMerge(data);
		break;

	case 17:
		print("preorder");
		t.PreorderIt();
		break;

	case 18:
		print("inorder");
		t.InorderIt();
		break;

	case 19:
		print("postorder");
		t.PostorderIt();
		break;

	case 20:
		print("Enter the data : ");
		std::cin >> data;
		print(t.returnRightNodeWithData(data));
		break;

	case 21:
		print("Enter data of node : ");
		std::cin >> data;
		print("No of right childs : ");
		print(t.count_right_childs(t.returnRightNodeWithData(data)));
		break;
	
	case 22:
		//int h = ;
		if (t.check(t.height_tree())) print("complete");
		else print("not complete");
		break;

	case 23:
		return;

	default:
		print("Invalid choice...");
		break;
	}

	return;
}

#endif