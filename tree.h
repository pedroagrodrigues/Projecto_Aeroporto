//#include "bibliotecas.h"
#ifdef sort_tree
#else
typedef struct sort_tree {
	struct item {
		long bilhete;
		string primeiro_nome;
		string segundo_nome;
		string nacionalidade;
	}humman;
	sort_tree * right;
	sort_tree * left;
}sort_tree;
#endif
sort_tree * newLeaf(sort_tree::item subject);

sort_tree * insert_tree(sort_tree * no, sort_tree::item subject);

void sort_tree_out(sort_tree * no); //infixa

sort_tree * fill_tree(sort_tree * tree, aviao &subject);