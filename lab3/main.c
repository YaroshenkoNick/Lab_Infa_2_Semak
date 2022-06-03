#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int unit_test() {
	treenode *n0, *n11, *n12, *n13, *n2;

	n0 = add_node(NULL, 5);
	if (n0 == NULL)
		return -1;

	n11 = add_node(n0, 10);
	if (n11 == NULL)
		return -1;

	n12 = add_node(n0, 23);
	if (n12 == NULL)
		return -1;

	n13 = add_node(n0, 8);
	if (n13 == NULL)
		return -1;

	n2 = add_node(n13, 11);
	if (n2 == NULL)
		return -1;

	return 0;
}

int main(int argc, char** argv) {

	int result = unit_test();

	tree_from_file("values.txt");	//результат чтения файла вида (<Tab><value>\n)

	return result;	//результат юнит-теста
}

/*
ГРАФИЧЕСКОЕ ПРЕДСТАВЛЕНИЕ ТЕСТОВОГО ДЕРВА:

		    n0				
	    /   |   \
	  n11  n12	n13			
				   \
					n2
*/