#include "bibliotecas.h"
#include "tree.h"

// ----------------Fun��es_Menu_Op��es-------------------
// ----------------Impress�o de Pessoas-------------------
void print_humman(aviao &subject) {
	aviao::aviao_item *temp = subject.head;
	pessoa::pessoa_item *temp_humman = new pessoa::pessoa_item();
	while (temp != NULL) {
		temp_humman = temp->passageiro.head;
		while (temp_humman != NULL) {
			cout.width(50);
			cout << left <<temp_humman->segundo_nome + ", " + temp_humman->primeiro_nome ;
			cout << right << temp_humman->nacionalidade << endl;
			temp_humman = temp_humman->next;
		}
		temp = temp->next;
	}
}

// Fun��es do Sub - Menu Criado -> Op��o 1 Menu_Op��es
void lista_todos_passageiros(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros){
	limpar;
	
	cout << "\nLista De Todos os Passageiros.\n";

	// Lista De Passageiros Que Est�o Nos Avi�es Em Aproxima��o
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(48);
	cout << right << "Em Aproxima��o:\n";
	

	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	print_humman(aproximar);
	// Lista De Passageiros Que Est�o Nos Avi�es Em Pista
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(48);
	cout << right << "Em Pista:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	print_humman(pista);
	// Lista De Passageiros Que Est�o Nos Avi�es Em Descolagem
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(48);
	cout << right << "Em Descolar:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	print_humman(descolar);
	// Lista De Passageiros Que Est�o No Terminal Do Aeroporto
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(48);
	cout << right << "No Terminal:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	terminal::terminal_item *temp = passageiros.head;
	pessoa::pessoa_item *temp2 = new pessoa::pessoa_item();
	while (temp != NULL) {
		temp2 = temp->humman.head;
		while (temp2 != NULL) {
			cout.width(50);
			cout << left << temp2->segundo_nome + ", " + temp2->primeiro_nome;
			cout << right << temp2->nacionalidade << endl;
			temp2 = temp2->next;

		}
		temp = temp->next;
	}
	pausa;
} // Fim Da Op��o 1 Menu_Op��es
void lista_todos_passageiros_ordenados(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros) {
	limpar;
	sort_tree * tree = NULL;
	tree = fill_tree_by_name(tree, aproximar);
	tree = fill_tree_by_name(tree, pista);
	tree = fill_tree_by_name(tree, descolar);
	terminal::terminal_item *temp = passageiros.head;
	pessoa::pessoa_item *temp_humman = new pessoa::pessoa_item();
	sort_tree::item temp_person;
	while (temp != NULL) {
		temp_humman = temp->humman.head;
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

	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(65);
	cout << right << "Lista de Passageiros Ordenada Alfab�ticamente.\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	sort_tree_out(tree);

	pausa;
}// Fim Da Op��o 1 Menu_Op��es

 // Op��o 2 - Menu_Op��es
void lista_voos_pista_descolar(aviao &pista, aviao &descolar) {
	limpar;
	cout << "\nLista Todos os Voos, em Pista e a Descolar, Ordenados Alfab�ticamente.\n";
	// Voos em Pista
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(45);
	cout << right << "Na Pista e a Descolar:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Modelo";
	cout.width(30);
	cout << "Origem";
	cout.width(30);
	cout << "Destino\n\n";
	
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
	pausa;
}// Fim Da Op��o 2 Menu_Op��es

// Op��o 3 - Menu_Op��es
void lista_passageiros_pista(aviao &pista) {
	limpar;
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(55);
	cout << right << "Lista De Todos os Passageiros Em Pista:";
	cout << "\n----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	print_humman(pista);

	pausa;
} // Fim Da Op��o 3 Menu_Op��es

// Op��o 4 - Menu_Op��es
void lista_passageiros_pista_nacionalidade(aviao &pista) {
	limpar;
	sort_tree * tree = NULL;
	tree = fill_tree_by_nationality(tree, pista);
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(65);
	cout << "Lista De Todos Passageiros em Pista Ordenados Por Nacionalidade:";
	cout << "\n----------------------------------------------------------------------------\n\n";
	cout << right << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	sort_tree_out(tree);

	pausa;
} // Fim Da Op��o 4 Menu_Op��es

 // Op��o 5 - Menu_Op��es
int pesquisa_estrangeiros_aeroporto(aviao &pista, terminal &passageiros){
	limpar;
	int opt = 0;
	string name;
	int size = 0;

	sort_tree * tree = NULL;
	tree = fill_tree_by_name_stanger(tree, pista);
	terminal::terminal_item *temp = passageiros.head;
	pessoa::pessoa_item *temp_humman = new pessoa::pessoa_item();
	sort_tree::item temp_person;
	while (temp != NULL) {
		temp_humman = temp->humman.head;
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

	cout << right;

	// Lista Passageiros Estrangeiros no Terminal
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(60);
	cout << "Pesquisa de Passageiros Estrangeiros no Aeroporto. \n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "(1) - Pesquisa Por Primeiro Nome \t (2)- Pesquisa Pelo Segundo Nome\n";
	while (1) {
		while (!(cin >> opt)) {
			cin.clear(); //Previne loop na introdu��o de crat�res n�o num�ricos
			while (cin.get() != '\n') continue;
			cout << "ERRO Op��o Inv�lida.\n";
		}
		if (opt != 1 && opt != 2) cout << "ERRO Op��o Inv�lida.\n";
		else break;
	}
	cout << "\nIntroduza um Nome a Pesquisar:\n";
	cin >> name;
	cout << endl;
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	(opt == 1) ? search_by_first_name(tree, name) : search_by_last_name(tree, name);
	cout << "\nN�o Foram Encontradado Mais Resultados.\n";
	pausa;

	return 0;
}// Fim Da Op��o 5 Menu_Op��es

// Op��o 6 - Menu_Op��es - Fun��es
void pesquisa_passageiros_estrangeiros_aeroporto_ordenados(aviao &pista, terminal &passageiros){
	limpar;
	sort_tree * tree = NULL;
	tree = fill_tree_by_name_stanger(tree, pista);
	terminal::terminal_item *temp = passageiros.head;
	pessoa::pessoa_item *temp_humman = new pessoa::pessoa_item();
	sort_tree::item temp_person;
	while (temp != NULL) {
		temp_humman = temp->humman.head;
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


	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(65);
	cout << right << "Lista Passageiros Estrageiros no Aeroporto, Ordenados Alfab�ticamente.\n";
	cout << "----------------------------------------------------------------------------\n\n";

	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	sort_tree_out(tree);

	pausa;
}// Fim Da Op��o 6 Menu_Op��es

 // Op��o 7 - Menu_Op��es - Fun��es
void pesquisa_sobre_passageiros(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros){
	limpar;
	int opt=0;
	string name;
	sort_tree * tree = NULL;
	tree = fill_tree_by_name(tree, aproximar);
	tree = fill_tree_by_name(tree, pista);
	tree = fill_tree_by_name(tree, descolar);
	terminal::terminal_item *temp = passageiros.head;
	pessoa::pessoa_item *temp_humman = new pessoa::pessoa_item();
	sort_tree::item temp_person;
	while (temp != NULL) {
		temp_humman = temp->humman.head;
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
	// Lista Passageiros Estrangeiros no Terminal
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(55);
	cout << right << "Pesquisa sobre passageiros. \n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "(1) - Pesquisa Por Primeiro Nome \t (2) - Pesquisa Pelo Segundo Nome\n";
	while (1) {
		while (!(cin >> opt)) {
			cin.clear(); //Previne loop na introdu��o de crat�res n�o num�ricos
			while (cin.get() != '\n') continue;
			cout << "ERRO Op��o Inv�lida\n";
		}
		if (opt != 1 && opt != 2) cout << "ERRO Op��o Inv�lida\n";
		else break;
	}
	cout << "\nIntroduza um Nome a Pesquisar:\n";
	cin >> name;
	cout << endl;
	cout << "\nNome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	(opt == 1) ? search_by_first_name(tree, name) :  search_by_last_name(tree, name);
	cout << "\nN�o Foram Encontradado Mais Resultados.\n";
	pausa;
}// Fim Da Op��o 7 Menu_Op��es

 // Fun��es do Sub - Menu Criado -> Op��o 8 Menu_Op��es
void editar_nome_passageiro(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros){
	limpar;

	int opt = 0;
	string name;
	sort_tree * tree = NULL;
	tree = fill_tree_by_name(tree, aproximar);
	tree = fill_tree_by_name(tree, pista);
	tree = fill_tree_by_name(tree, descolar);
	terminal::terminal_item *temp = passageiros.head;
	pessoa::pessoa_item *temp_humman = new pessoa::pessoa_item();
	sort_tree::item temp_person;
	while (temp != NULL) {
		temp_humman = temp->humman.head;
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

	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(55);
	cout << right << "Editar Nome Do Passageiro.\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Selecione o M�todo de Pesquisa de Passageiros a Editar.\n\n";
	cout << "(1) - Pesquisa Por Primeiro Nome \t (2) - Pesquisa Pelo Segundo Nome\n";
	while (1) {
		while (!(cin >> opt)) {
			cin.clear(); //Previne loop na introdu��o de crat�res n�o num�ricos
			while (cin.get() != '\n') continue;
			cout << "ERRO Op��o Inv�lida\n";
		}
		if (opt != 1 && opt != 2) cout << "ERRO Op��o Inv�lida\n";
		else break;
	}
	cout << "\nIntroduza um Nome a Pesquisar:\n";
	cin >> name;
	cout << endl;
	cout << "\nNome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	(opt == 1) ? search_by_first_name(tree, name) : search_by_last_name(tree, name);
	cout << "\nN�o Foram Encontradado Mais Resultados.\n";
	pausa;
}// Fim Da Op��o 8 Menu_Op��es
void editar_nacionalidade_passageiro(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros){
	limpar;

	int opt = 0;
	string name;
	sort_tree * tree = NULL;
	tree = fill_tree_by_name(tree, aproximar);
	tree = fill_tree_by_name(tree, pista);
	tree = fill_tree_by_name(tree, descolar);
	terminal::terminal_item *temp = passageiros.head;
	pessoa::pessoa_item *temp_humman = new pessoa::pessoa_item();
	sort_tree::item temp_person;
	while (temp != NULL) {
		temp_humman = temp->humman.head;
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

	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(55);
	cout << right << "Editar Nacionalidade Do Passageiro.\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Selecione o M�todo de Pesquisa de Passageiros a Editar.\n\n";
	cout << "(1) - Pesquisa Por Primeiro Nome \t (2) - Pesquisa Pelo Segundo Nome\n";
	while (1) {
		while (!(cin >> opt)) {
			cin.clear(); //Previne loop na introdu��o de crat�res n�o num�ricos
			while (cin.get() != '\n') continue;
			cout << "ERRO Op��o Inv�lida\n";
		}
		if (opt != 1 && opt != 2) cout << "ERRO Op��o Inv�lida\n";
		else break;
	}
	cout << "\nIntroduza um Nome a Pesquisar:\n";
	cin >> name;
	cout << endl;
	cout << "\nNome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	(opt == 1) ? search_by_first_name(tree, name) : search_by_last_name(tree, name);
	cout << "\nN�o Foram Encontradado Mais Resultados.\n";
	pausa;
}// Fim Da Op��o 9 Menu_Op��es
void editar_destino_voo(aviao &pista, aviao &aproximar, aviao &descolar){
	limpar;
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(55);
	cout << right << "Editar Destino do Voo.\n";
	cout << "----------------------------------------------------------------------------\n\n";

	pausa;
}// Fim Da Op��o 10 Menu_Op��es