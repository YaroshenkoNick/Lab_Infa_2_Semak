#pragma once
#ifndef __TREE__
#define __TREE__

typedef struct {
	struct treenode* value;
	struct descendants* next;
} descendants;  //структура списка

typedef struct {
	int value;
	struct treenode* ancestor;
	struct descendants* descendant;
} treenode;	  //структура дерева

descendants* create_descendant();
descendants* add_descendant(descendants* list, treenode* node);
treenode* create_tree(int value);
treenode* add_node(treenode* node, int value);
void show_descendants(treenode* node);
void tree_from_file(const char* filename);

#endif
