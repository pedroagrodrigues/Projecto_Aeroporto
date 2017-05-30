#include "bibliotecas.h"
#include "tree.h"

sort_tree * newLeaf(sort_tree::item subject){
	sort_tree * leaf = new sort_tree;
	leaf->humman = subject;
	leaf->left = NULL;
	leaf->right = NULL;
	return(leaf);
}
bool orderbyname(sort_tree * tree, sort_tree::item pessoa) {
	if (pessoa.segundo_nome < tree->humman.segundo_nome) return 1;
	else if (pessoa.segundo_nome == tree->humman.segundo_nome)
		if (pessoa.primeiro_nome < tree->humman.primeiro_nome) //organiza pelo primeiro nome
			return 1;
		else if (pessoa.primeiro_nome == tree->humman.primeiro_nome) //organiza pela nacionalidade
			if (pessoa.nacionalidade <= tree->humman.nacionalidade)
				return 1;
			
	return 0;

}

sort_tree * insert_tree_by_name(sort_tree * tree, sort_tree::item pessoa){
	if (tree == NULL) {
		return newLeaf(pessoa);
	}
	else {
		(orderbyname(tree, pessoa)) ? tree->left = insert_tree_by_name(tree->left, pessoa) : tree->right = insert_tree_by_name(tree->right, pessoa);
	}
		
	return tree;
}


void sort_tree_out(sort_tree * root) {
	if (root == NULL) return;
	sort_tree_out(root->left);
	cout.width(50);
	cout << left << root->humman.segundo_nome + ", " + root->humman.primeiro_nome << root->humman.nacionalidade << endl;
	sort_tree_out(root->right);
}

sort_tree * fill_tree_by_name(sort_tree * tree, aviao &subject) {
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
			tree = insert_tree_by_name(tree, temp_person);
		}
		temp = temp->next;
	}
	return tree;
}

sort_tree * fill_tree_by_name_stanger(sort_tree * tree, aviao &subject) {
	aviao::aviao_item *temp = subject.head;
	pessoa::pessoa_item *temp_humman = new pessoa::pessoa_item();
	sort_tree::item temp_person;
	temp = subject.head;
	while (temp != NULL) {
		temp_humman = temp->passageiro.head;
		while (temp_humman != NULL) {
			if (temp_humman->nacionalidade != "Portugal") {
				temp_person.bilhete = temp_humman->bilhete;
				temp_person.nacionalidade = temp_humman->nacionalidade;
				temp_person.primeiro_nome = temp_humman->primeiro_nome;
				temp_person.segundo_nome = temp_humman->segundo_nome;
				tree = insert_tree_by_name(tree, temp_person);
			}
			temp_humman = temp_humman->next;
		}
		temp = temp->next;
	}
	return tree;
}

bool orderbynas(sort_tree * tree, sort_tree::item pessoa) {
	if (pessoa.nacionalidade < tree->humman.nacionalidade) return 1;
	else if (pessoa.nacionalidade == tree->humman.nacionalidade)
		if (pessoa.segundo_nome < tree->humman.segundo_nome) return 1;
		else if (pessoa.segundo_nome == tree->humman.segundo_nome)
			if (pessoa.primeiro_nome < tree->humman.primeiro_nome) //organiza pelo primeiro nome
				return 1;
	return 0;

}
sort_tree * insert_tree_by_nacionality(sort_tree * tree, sort_tree::item pessoa) {
	if (tree == NULL) {
		return newLeaf(pessoa);
	}
	else {
		(orderbynas(tree, pessoa)) ? tree->left = insert_tree_by_nacionality(tree->left, pessoa) : tree->right = insert_tree_by_nacionality(tree->right, pessoa);
	}

	return tree;
}

sort_tree * fill_tree_by_nationality(sort_tree * tree, aviao &subject) {
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
			tree = insert_tree_by_nacionality(tree, temp_person);
		}
		temp = temp->next;
	}
	return tree;
}
int size_tree(sort_tree * tree)
{
	if (tree == NULL) return 0;
	return size_tree(tree->left) + size_tree(tree->right) + 1; // retorna o numero de chamadas recursiva (atŽ no esq e dir ser null). +1 devido ˆ raiz
}

void search_by_last_name(sort_tree * root, string name) {
	if (root == NULL) return;
	search_by_last_name(root->left, name);
	cout.width(50);
	if (root->humman.segundo_nome == name) cout << left << root->humman.segundo_nome + ", " + root->humman.primeiro_nome << root->humman.nacionalidade << endl;
	search_by_last_name(root->right, name);
}
void search_by_first_name(sort_tree * root, string name) {
	if (root == NULL) return;
	search_by_first_name(root->left, name);
	cout.width(50);
	if (root->humman.primeiro_nome == name) cout << left << root->humman.segundo_nome + ", " + root->humman.primeiro_nome << root->humman.nacionalidade << endl;
	search_by_first_name(root->right, name);
}