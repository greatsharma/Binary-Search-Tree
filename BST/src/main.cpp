#include "../header/menu.h"

void make_tree()
{
	Tree t;
	while (true)
	{
		menu(t);
		print("Enter 0 to exit : ");
		std::cin >> data;
		if (data == 0) break;
	}

	t.clear();
	return;
}

int main(void)
{
	do
	{
		make_tree();
		print("want to make new tree(if not press 0)? ");
		std::cin >> data;
	} while (data != 0);
	
	wait;
	return 0;
}