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

/*

//Juntar as duas listas:
aviao::aviao_item * aux = new aviao::aviao_item();
aviao  temp;
temp.head = NULL;
temp.end = NULL;
while (pista.head != NULL) {
	aux = new aviao::aviao_item();
	aux->capacidade = pista.head->capacidade;
	aux->modelo = pista.head->modelo;
	aux->destino = pista.head->destino;
	aux->origem = pista.head->origem;
	aux->nome_voo = pista.head->nome_voo;
	aux->passageiro = pista.head->passageiro;
	aux->next = NULL;
	if (temp.end == NULL) {
		temp.head = aux;
		temp.end = aux;
	}
	else {
		temp.end->next = aux;
		temp.end = aux;
	}
	pista.head = pista.head->next;
}
while (descolar.head != NULL) {
	aux = new aviao::aviao_item();
	aux->capacidade = descolar.head->capacidade;
	aux->modelo = descolar.head->modelo;
	aux->destino = descolar.head->destino;
	aux->origem = descolar.head->origem;
	aux->nome_voo = descolar.head->nome_voo;
	aux->passageiro = descolar.head->passageiro;
	aux->next = NULL;
	if (temp.end == NULL) {
		temp.head = aux;
		temp.end = aux;
	}
	else {
		temp.end->next = aux;
		temp.end = aux;
	}
	descolar.head = descolar.head->next;
}

while (temp.head != NULL) {
	cout << temp.head->nome_voo << endl;
	temp.head = temp.head->next;
}
*/

void sort_tree_out(sort_plane * root) {
	if (root == NULL) return;
	sort_tree_out(root->left);
	cout << root->plane.modelo + root->plane.origem + root->plane.destino;
	sort_tree_out(root->right);
}
sort_plane * newLeaf_plane(sort_plane::item subject) {
	sort_plane * leaf = new sort_plane;
	leaf->plane = subject;
	leaf->left = NULL;
	leaf->right = NULL;
	return(leaf);
}

sort_plane * insert_plane_by_name(sort_plane * tree, sort_plane::item plane) {
	if (tree == NULL) {
		return newLeaf_plane(plane);
	}
	else {
		if (plane.destino <= tree->plane.destino)
			tree->left = insert_plane_by_name(tree->left, plane);
		else
			tree->right = insert_plane_by_name(tree->right, plane);
	}

	return tree;
}

sort_plane * sort_plane_by_destiny(sort_plane * tree, aviao &subject) {
	aviao::aviao_item *temp = subject.head;
	pessoa::pessoa_item *temp_humman = new pessoa::pessoa_item();
	sort_plane::item temp_plane;
	temp = subject.head;
	while (temp != NULL) {
		temp_humman = temp->passageiro.head;
		//while (temp_humman != NULL) {
		temp_plane.capacidade = temp->capacidade;
		temp_plane.destino = temp->destino;
		temp_plane.modelo = temp->modelo;
		temp_plane.nome_voo = temp->nome_voo;
		temp_plane.origem = temp->origem;
		temp_plane.passageiro = temp->passageiro;
		tree = insert_plane_by_name(tree, temp_plane);

			//temp_humman = temp_humman->next;
		//}
		temp = temp->next;
	}
	return tree;
}