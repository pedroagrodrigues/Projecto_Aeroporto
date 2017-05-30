#include "bibliotecas.h"
#include "tree.h"

sort_tree * newLeaf(sort_tree::item subject){
	sort_tree * leaf = new sort_tree;
	leaf->humman = subject;
	leaf->left = NULL;
	leaf->right = NULL;
	return(leaf);
}

sort_tree * insert_tree(sort_tree * tree, sort_tree::item pessoa){
	if (tree == NULL) {
		return newLeaf(pessoa);
	}
	else
	{
		if (pessoa.segundo_nome <= tree->humman.segundo_nome)
			tree->left = insert_tree(tree->left, pessoa);
		else
			tree->right = insert_tree(tree->right, pessoa);
	}
	return tree;
}
void sort_tree_out(sort_tree * no) {
	if (no == NULL) return;
	sort_tree_out(no->left);
	cout.width(50);
	cout << left << no->humman.segundo_nome + ", " + no->humman.primeiro_nome << no->humman.nacionalidade << endl;
	sort_tree_out(no->right);
}

sort_tree *fill_tree(sort_tree * tree, aviao &subject) {
	aviao::aviao_item *temp = subject.head;
	pessoa::pessoa_item *temp_humman = new pessoa::pessoa_item();
	sort_tree::item temp_person;
	temp = subject.head;
	while (temp != NULL) {
		temp_humman = temp->passageiro.head;
		while (temp_humman != NULL) {
			temp_person.bilhete = temp_humman->bilhete;
			temp_person.nacionalidade = temp_humman->nacionalidade;
			temp_person.primeiro_nome = temp_humman->primeiro_nome;
			temp_person.segundo_nome = temp_humman->segundo_nome;
			temp_humman = temp_humman->next;
			tree = insert_tree(tree, temp_person);
		}
		temp = temp->next;
	}
	return tree;
}