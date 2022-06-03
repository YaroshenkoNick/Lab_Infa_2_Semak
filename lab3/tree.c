#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 10


descendants* add_descendant(descendants* list, treenode* node) {
	
	if (list != NULL) {												//добавление в список потомков
		descendants* new = (descendants*)malloc(sizeof(descendants));
		if (new == NULL)
			return NULL;

		if (list->value == NULL) {
			list->value = node;
			list->next = NULL;
			return list;
		}

		while (list->next != NULL)
			list = list->next;
		list->next = new;
		new->value = node;
		new->next = NULL;

		return new;
	}
	else {															//создание списка потомков
		descendants* new = (descendants*)malloc(sizeof(descendants));
		if (new == NULL)
			return NULL;
		new->value = NULL;
		new->next = NULL;
		return new;
	}
}

treenode* add_node(treenode* node, int value) {	

	if (node != NULL) {												//добавление к существующему узлу
		treenode* leaf = (treenode*)malloc(sizeof(treenode));
		if (leaf == NULL)
			return NULL;
		leaf->value = value;
		leaf->ancestor = node;
		leaf->descendant = add_descendant(NULL, NULL);
		add_descendant(node->descendant, leaf);
		return leaf;
	}
	else {															//создание корня
		treenode* root = (treenode*)malloc(sizeof(treenode));
		if (root == NULL)
			return NULL;
		root->value = value;
		root->ancestor = NULL;
		root->descendant = add_descendant(NULL, NULL);
		return root;
	}
}

void show_descendants(treenode* node) {	//процедура вывода листьев узла
	descendants* list = node->descendant;
	if (list->value == NULL) {
		printf("There are no descenants of node %d", node->value);
		return;
	}

	treenode* leaf;

	while (list->next != NULL) {
		leaf = list->value;
		printf("%d\n", leaf->value);
		list = list->next;
	}
	leaf = list->value;
	printf("%d\n", leaf->value);
	return;
}

void tree_from_file(const char* filename) {

	FILE* f = fopen(filename, "r");
	char buffer[BUFFER_SIZE];
	char temp[4];
	unsigned int i, j, count, level = 0;
	int value;
	treenode* root = NULL;
	treenode* current = NULL;
	treenode* previous = NULL;

	while (!feof(f)) {
		while (fgets(buffer, BUFFER_SIZE, f) != NULL) {
			j = 0;
			count = 0;
			memset(temp, 0, 4 * sizeof(char));
			for (i = 0; i < BUFFER_SIZE; i++) {
				if (buffer[i] != '	') {
					temp[j] = buffer[i];
					j++;
				}
				if (buffer[i] == '	')
					count++;
			}
			
			value = atoi(temp);

			if (count > 0) {
				if (count > level) {
					previous = current;
					current = add_node(current, value);
					level = count;
				}
				else 
					if (count < level) {
					current = previous->ancestor;
					previous = current;
					current = add_node(current, value);
					level = count;
					}
					else {
						current = previous;
						previous = current;
						current = add_node(current, value);
						level = count;
						}
			}
			else {
				root = add_node(NULL, value);
				current = root;
			}
		}
	}
	///
	printf("Descendants of root \"156\":\n");
	show_descendants(root);										//должно выдать 4, 3, 13
	printf("Descendants of node \"4\":\n");
	show_descendants(((descendants*)root->descendant)->value);	//должно выдать 2
	///
}