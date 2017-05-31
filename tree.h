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
typedef struct sort_plane {
	struct item {
		string nome_voo;
		string origem;
		string destino;
		string modelo;
		pessoa passageiro;
		int capacidade = 0;
	}plane;
	sort_plane * right;
	sort_plane * left;
}sort_plane;

sort_tree * newLeaf(sort_tree::item subject);
sort_tree * insert_tree_by_name (sort_tree * no, sort_tree::item subject);
void sort_tree_out(sort_tree * no); //infixa
void sort_tree_out_menu_8(sort_tree * root);//infixa
sort_tree * fill_tree_by_name(sort_tree * tree, aviao &subject);
sort_tree * fill_tree_by_nationality(sort_tree * tree, aviao &subject);
sort_tree * fill_tree_by_name_stanger( sort_tree * tree, aviao &subject);

void search_by_last_name(sort_tree * root, string name);
void search_by_first_name(sort_tree * root, string name);


sort_plane * sort_plane_by_destiny(sort_plane * tree, aviao &subject);

void sort_tree_plane(sort_plane * root);//infixa
