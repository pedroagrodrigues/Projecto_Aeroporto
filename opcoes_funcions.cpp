#include "bibliotecas.h"
#include "tree.h"

// ----------------Funções_Menu_Opções-------------------
// ----------------Impressão de Pessoas-------------------
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

// Funções do Sub - Menu Criado -> Opção 1 Menu_Opções
void lista_todos_passageiros(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros){
	limpar;
	
	cout << "\nLista De Todos os Passageiros.\n";

	// Lista De Passageiros Que Estão Nos Aviões Em Aproximação
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(48);
	cout << right << "Em Aproximação:\n";
	

	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	print_humman(aproximar);
	// Lista De Passageiros Que Estão Nos Aviões Em Pista
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(48);
	cout << right << "Em Pista:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	print_humman(pista);
	// Lista De Passageiros Que Estão Nos Aviões Em Descolagem
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(48);
	cout << right << "Em Descolar:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	print_humman(descolar);
	// Lista De Passageiros Que Estão No Terminal Do Aeroporto
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
} // Fim Da Opção 1 Menu_Opções
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
	cout << right << "Lista de Passageiros Ordenada Alfabéticamente.\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	sort_tree_out(tree);
}// Fim Da Opção 1 Menu_Opções


 // Opção 2 - Menu_Opções

void lista_voos_pista_descolar(aviao &pista, aviao &descolar) {
	sort_plane * tree = NULL;
	tree = sort_plane_by_destiny(tree, pista);
	tree = sort_plane_by_destiny(tree, descolar);
	limpar;
	cout << "\nLista Todos os Voos, em Pista e a Descolar, Ordenados Alfabéticamente.\n";
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
	sort_tree_plane(tree);
	pausa;
}// Fim Da Opção 2 Menu_Opções

// Opção 3 - Menu_Opções
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
} // Fim Da Opção 3 Menu_Opções

// Opção 4 - Menu_Opções
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
} // Fim Da Opção 4 Menu_Opções

 // Opção 5 - Menu_Opções
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
	cout << "(1) - Pesquisa por primeiro nome \t (2)- Pesquisa pelo último nome\n";
	while (1) {
		while (!(cin >> opt)) {
			cin.clear(); //Previne loop na introdução de cratéres não numéricos
			while (cin.get() != '\n') continue;
			cout << "ERRO Opção Inválida.\n";
		}
		if (opt != 1 && opt != 2) cout << "ERRO Opção Inválida.\n";
		else break;
	}
	cout << "\nIntroduza um Nome a Pesquisar:\n";
	cin >> name;
	cout << endl;
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	(opt == 1) ? search_by_first_name(tree, name) : search_by_last_name(tree, name);
	cout << "\nNão Foram Encontradado Mais Resultados.\n";
	pausa;

	return 0;
}// Fim Da Opção 5 Menu_Opções

// Opção 6 - Menu_Opções - Funções
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
	cout << right << "Lista Passageiros Estrageiros no Aeroporto, Ordenados Alfabéticamente.\n";
	cout << "----------------------------------------------------------------------------\n\n";

	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	sort_tree_out(tree);

	pausa;
}// Fim Da Opção 6 Menu_Opções

 // Opção 7 - Menu_Opções - Funções
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
			cin.clear(); //Previne loop na introdução de cratéres não numéricos
			while (cin.get() != '\n') continue;
			cout << "ERRO Opção Inválida\n";
		}
		if (opt != 1 && opt != 2) cout << "ERRO Opção Inválida\n";
		else break;
	}
	cout << "\nIntroduza um Nome a Pesquisar:\n";
	cin >> name;
	cout << endl;
	cout << "\nNome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	(opt == 1) ? search_by_first_name(tree, name) :  search_by_last_name(tree, name);
	cout << "\nNão Foram Encontradado Mais Resultados.\n";
	pausa;
}// Fim Da Opção 7 Menu_Opções


void lista_inicial_menu_8(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros) {
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
	cout << right << "Lista de Passageiros Ordenada Alfabéticamente.\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Ticket";
	cout.width(30);
	cout << "Nome";
	cout.width(50);
	cout << "Nacionalidade\n\n";

	sort_tree_out_menu_8(tree);

}

void lista_inicial_menu_9(aviao &pista, aviao &aproximar, aviao &descolar) {
	
	sort_plane * tree = NULL;
	tree = sort_plane_by_destiny(tree, pista);
	tree = sort_plane_by_destiny(tree, descolar);
	tree = sort_plane_by_destiny(tree, aproximar);
	limpar;
	cout << "\nLista Todos os Voos, em Pista e a Descolar, Ordenados Alfabéticamente.\n";
	cout << "\n----------------------------------------------------------------------------\n";
	cout << "Modelo";
	cout.width(30);
	cout << "Origem";
	cout.width(30);
	cout << "Destino\n\n";
	sort_tree_plane(tree);
	pausa;
}

void edit(pessoa::pessoa_item *pessoa) {
	int opt;
	cout << "Seleccione:\n1-Nome\t2-Nacionalidade\t\t0-Cancelar\n";
	while (1) {
		while (!(cin >> opt)) {
			cin.clear(); //Previne loop na introdução de cratéres não numéricos
			while (cin.get() != '\n') continue;
			cout << "ERRO Opção Inválida\n";
		}
		if (opt != 1 && opt != 2 && opt != 0) cout << "ERRO Opção Inválida\n";
		else break;
	}
	switch (opt) {
	case 1:
		cout << "Introduza o último nome: ";
		cin >> pessoa->segundo_nome;
		cout << "Introduza o primeiro nome: ";
		cin >> pessoa->primeiro_nome;
		break;
	case 2:
		cout << "Introduza a nacionalidade: ";
		cin >> pessoa->nacionalidade;
		break;
	}
}

bool edit_humman_by_tkt(aviao &subject, int tkt) {
	aviao::aviao_item *temp = subject.head;
	pessoa::pessoa_item *temp_humman = new pessoa::pessoa_item();
	while (temp != NULL) {
		temp_humman = temp->passageiro.head;
		while (temp_humman != NULL) {
			if (temp_humman->bilhete == tkt) {
				edit(temp_humman);
				return 1;
			}
			temp_humman = temp_humman->next;
		}
		temp = temp->next;
	}
	return 0;
}
bool edit_humman_terminal_by_tkt(terminal &subject, int tkt) {

	pessoa::pessoa_item *temp_humman = new pessoa::pessoa_item();
	terminal::terminal_item *temp = subject.head;
	while (temp != NULL) {
		temp_humman = temp->humman.head;
		while (temp_humman != NULL) {
			if (temp_humman->bilhete == tkt) {
				edit(temp_humman);
				return 1;
			}
		}
		temp = temp->next;
	}
}


int tkt_select(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros) {
	int tkt;
	cout << "Introduza o número do bilhete da pessoa que pertente modificar: ";
	while (!(cin >> tkt)) {
		cin.clear(); //Previne loop na introdução de cratéres não numéricos
		while (cin.get() != '\n') continue;
		cout << "ERRO TKT inválido\n";
	}
	if (edit_humman_by_tkt(pista, tkt)) return 1;
	if (edit_humman_by_tkt(aproximar, tkt)) return 1;
	if (edit_humman_by_tkt(descolar, tkt)) return 1;
	if (edit_humman_terminal_by_tkt(passageiros, tkt)) return 1;
	cout << "ERRO TKT inválido\n";
	pausa;
	return 0;
}

bool name_sel(aviao &subject, string name1,string name2) {
	aviao::aviao_item *temp = subject.head;
	pessoa::pessoa_item *temp_humman = new pessoa::pessoa_item();
	while (temp != NULL) {
		temp_humman = temp->passageiro.head;
		while (temp_humman != NULL) {
			if (temp_humman->primeiro_nome == name1 && temp_humman->segundo_nome == name2) {
				edit(temp_humman);
				return 1;
			}
			temp_humman = temp_humman->next;
		}
		temp = temp->next;
	}
	return 0;
}
bool name_sel_ter(terminal &subject, string name1, string name2) {
	pessoa::pessoa_item *temp_humman = new pessoa::pessoa_item();
	terminal::terminal_item *temp = subject.head;
	while (temp != NULL) {
		temp_humman = temp->humman.head;
		while (temp_humman != NULL) {
			if (temp_humman->primeiro_nome == name1 && temp_humman->segundo_nome == name2) {
				edit(temp_humman);
				return 1;
			}
		}
		temp = temp->next;
	}

}
int primeiro_nome(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros) {
	string name1, name2;
	cout << "Introduza o primeiro nome da pessoa que pertente modificar: ";
	cin >> name1;
	cout << "Introduza o segundo nome da pessoa que pertente modificar: ";
	cin >> name2;
	if (name_sel(pista, name1, name2)) return 1;
	if (name_sel(aproximar, name1, name2)) return 1;
	if (name_sel(descolar, name1, name2)) return 1;
	if (name_sel_ter(passageiros, name1, name2)) return 1;
	cout << "Pessoa não encontrada";
	pausa;

	return 0;

}
bool find_plane(aviao &subject, string name) {
	aviao::aviao_item *temp = subject.head;
	while (temp != NULL) {
		if (temp->nome_voo == name) {
			cout << "Introduza o nome do novo destino";
			getline(cin, temp->nome_voo);
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

int aviao_edit(aviao &pista, aviao &aproximar, aviao &descolar, string name) {
	if (name == "0") return 1;
	if (find_plane(pista, name)) return 1;
	if (find_plane(aproximar, name)) return 1;
	if (find_plane(descolar, name)) return 1;
	
	cout << "Avião não encontrada";
	pausa;
	return 0;
}