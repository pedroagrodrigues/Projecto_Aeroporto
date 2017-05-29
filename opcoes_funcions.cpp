#include "bibliotecas.h"
struct sort_tree {
	struct item {
		long bilhete;
		string primeiro_nome;
		string segundo_nome;
		string nacionalidade;
	}humman;
	sort_tree * right;
	sort_tree * left;
};

// Comentário Abaixo, são as funções usadas, para ordenar alfabéticamente
/*
//----Sorting Functions---- (Funções Para Ordenação Alfabéticamente)
void sort_by_name(pessoa * passageiro, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i; j < (size); j++) {
			if (passageiro[i].segundo_nome > passageiro[j].segundo_nome)//organiza pelo ultimo nome
				swap(passageiro[i], passageiro[j]);
			else if (passageiro[i].segundo_nome == passageiro[j].segundo_nome)
				if (passageiro[i].primeiro_nome > passageiro[j].primeiro_nome) //organiza pelo primeiro nome
					swap(passageiro[i], passageiro[j]);
				else if (passageiro[i].primeiro_nome == passageiro[j].primeiro_nome)
					if (passageiro[i].nacionalidade > passageiro[j].nacionalidade) //organiza pela nacionalidade
						swap(passageiro[i], passageiro[j]);
		}
	}
}

void sort_by_nacionality(pessoa * passageiro, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i; j < (size); j++) {
			if (passageiro[i].nacionalidade > passageiro[j].nacionalidade) //organiza pela nacionalidade
				swap(passageiro[i], passageiro[j]);
			else if (passageiro[i].nacionalidade == passageiro[j].nacionalidade)
				if (passageiro[i].segundo_nome > passageiro[j].segundo_nome)//organiza pelo ultimo nome
					swap(passageiro[i], passageiro[j]);
				else if (passageiro[i].segundo_nome == passageiro[j].segundo_nome)
					if (passageiro[i].primeiro_nome > passageiro[j].primeiro_nome) //organiza pelo primeiro nome
						swap(passageiro[i], passageiro[j]);
		}
	}
}

void sort_by_destino(aviao * ordenar, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++)
			if (ordenar[i].destino > ordenar[j].destino)
				swap(ordenar[i].destino, ordenar[j].destino);
	}
}
*/


// ----------------Funções_Menu_Opções-------------------
//------------------------------------------------------------------------impressão de pessoas
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
void insert_tree(sort_tree::item *subject, sort_tree *order) {
	if (order == NULL) {
		order->humman = *subject;
		order->left = NULL;
		order->right = NULL;
	}
	else if (order->humman.segundo_nome <= subject->segundo_nome) {
		insert_tree(subject, order->left);
	}
	else insert_tree(subject, order->right);

}


void fill_tree(aviao &subject, sort_tree *order) {
	aviao::aviao_item *temp = new aviao::aviao_item();
	sort_tree::item *temp_person = new sort_tree::item();
	temp = subject.head;
	while (temp != NULL) {
		while (temp->passageiro.head != NULL) {
			temp_person->bilhete = temp->passageiro.head->bilhete;
			temp_person->nacionalidade = temp->passageiro.head->nacionalidade;
			temp_person->primeiro_nome = temp->passageiro.head->primeiro_nome;
			temp_person->segundo_nome = temp->passageiro.head->segundo_nome;
			temp->passageiro.head = temp->passageiro.head->next;
			insert_tree(temp_person, order);
		}
	}
}
void print(sort_tree * tree) {

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
	sort_tree * tree = new sort_tree();
	fill_tree(pista, tree);
	fill_tree(aproximar, tree);
	fill_tree(descolar, tree);
	terminal::terminal_item *temp = passageiros.head;
	sort_tree::item *temp_person = new sort_tree::item();
	while (temp != NULL) {
		while (temp->humman.head != NULL) {
			temp_person->bilhete = temp->humman.head->bilhete;
			temp_person->nacionalidade = temp->humman.head->nacionalidade;
			temp_person->primeiro_nome = temp->humman.head->primeiro_nome;
			temp_person->segundo_nome = temp->humman.head->segundo_nome;
			temp->humman.head = temp->humman.head->next;
			insert_tree(temp_person, tree);
		}
	}
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(65);
	cout << right << "Lista de Passageiros Ordenada Alfabéticamente.\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";

	print(tree);

	pausa;
}// Fim Da Opção 1 Menu_Opções

// Funções do Sub - Menu Criado -> Opção 2 Menu_Opções
void lista_todos_voos(aviao &pista, aviao &aproximar, aviao &descolar) {
	limpar;
	cout << "\nLista De Todos os Voos.\n";

	// Voos em Aproximação
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(48);
	cout << right << "Em Aproximação:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Modelo";
	cout.width(30);
	cout << "Origem";
	cout.width(30);
	cout << "Destino\n\n";
	
	// Voos em Pista
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(45);
	cout << right << "Na Pista:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Modelo";
	cout.width(30);
	cout << "Origem";
	cout.width(30);
	cout << "Destino\n\n";
	
	// Voos em Descolagem
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(45);
	cout << right << "Em Descolar:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Modelo";
	cout.width(30);
	cout << "Origem";
	cout.width(30);
	cout << "Destino\n\n";
	pausa;

} // Fim Da Opção 2 Menu_Opções
void lista_voos_pista_descolar(aviao &pista, aviao &descolar) {
	limpar;
	cout << "\nLista Todos os Voos, em Pista e a Descolar, Ordenados Alfabéticamente.\n";
	
	// Voos em Pista
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(45);
	cout << right << "Na Pista:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Modelo";
	cout.width(30);
	cout << "Origem";
	cout.width(30);
	cout << "Destino\n\n";
	
	// Voos em Descolagem
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(45);
	cout << right << "Em Descolar:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Modelo";
	cout.width(30);
	cout << "Origem";
	cout.width(30);
	cout << "Destino\n\n";
	pausa;
}// Fim Da Opção 2 Menu_Opções

// Opção 3 - Menu_Opções
void lista_passageiros_pista(aviao &pista) {
	limpar;
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(55);
	cout << right << "Lista De Todos os Passageiros Em Pista:";
	cout << "\n----------------------------------------------------------------------------\n\n";
	pausa;
} // Fim Da Opção 3 Menu_Opções

// Opção 4 - Menu_Opções
void lista_passageiros_pista_nacionalidade(aviao &pista) {
	limpar;
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(70);
	cout << "Lista De Todos Passageiros em Pista Ordenados Por Nacionalidade:";
	cout << "\n----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";

	pausa;
} // Fim Da Opção 4 Menu_Opções

// Funções do Sub - Menu Criado -> Opção 5 Menu_Opções
void lista_passageiros_estrangeiros_aeroporto(aviao &pista, terminal &passageiros){
	limpar;
	cout << right << "\nPesquisa de Passageiros Estrangeiros no Aeroporto:\n";

	// Lista Passageiros Estrangeiros no Terminal
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(48);
	cout << right << "No Terminal:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";

	// Lista Passageiros Estrangeiros em Pista
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(48);
	cout << right << "Em Pista:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";

	pausa;
}// Fim Da Opção 5 Menu_Opções
int pesquisa_passageiros_estrangeiros_aeroporto_manualmente(aviao &pista, terminal &passageiros){
	limpar;

	;

	while (1) {
		cout.width(55);
		cout << right << "\nEntrou no Modo Pesquisa Sobre Passageiros Estrangeiros no Aeroporto!\n";

		cout << "\n\n(1) Pesquisa Pelo Primeiro Nome" << " (2) Pesquisa Pelo Segundo Nome" << "\t (0) - Voltar" << endl;
		cout << "-------------------------------------------------------------------------------\n";

		switch (_getch()) {

		case'1':
			pesquisa_passageiros_estrangeiros_aeroporto_lista(pista, passageiros);
			break;

		case'2':
			pesquisa_passageiros_estrangeiros_aeroporto_segundo_nome(pista, passageiros);
			break;

		case'0':
			return 0;
			break;

		default:
			limpar;
			cout << "\nIntroduza Uma Opção Válida\n.";

			break;
		}

		pausa;



	} // Fim do ciclo Criado para continuar sempre do Menu_Opções Funcionalidade 5
}// Fim Da Opção 5 Menu_Opções
void pesquisa_passageiros_estrangeiros_aeroporto_lista(aviao &pista, terminal &passageiros){
	limpar;
	cout << "\nDigite o Primeiro Nome do Passageiro a Pesquisar.\n\n";
	cout << "Nome: ";

	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	cout.width(49);
	pausa;
}// Fim Da Opção 5 Menu_Opções
void pesquisa_passageiros_estrangeiros_aeroporto_primeiro_nome(aviao &pista, terminal &passageiros){
	limpar;
	cout << "\nDigite o Primeiro Nome do Passageiro a Pesquisar.\n\n";
	cout << "Nome: ";

	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	cout.width(49);
	pausa;
}// Fim Da Opção 5 Menu_Opções
void pesquisa_passageiros_estrangeiros_aeroporto_segundo_nome(aviao &pista, terminal &passageiros){
	limpar;
	cout << "\nDigite o Segundo Nome do Passageiro a Pesquisar.\n\n";
	cout << "Nome: ";

	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	cout.width(49);
	pausa;
}// Fim Da Opção 5 Menu_Opções

// Opção 6 - Menu_Opções - Funções
void pesquisa_passageiros_estrangeiros_aeroporto_ordenados(aviao &pista, terminal &passageiros){
	limpar;
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(65);
	cout << right << "Lista Passageiros Estrageiros no Aeroporto, Ordenados Alfabéticamente.\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	pausa;
}// Fim Da Opção 6 Menu_Opções

// Funções do Sub - Menu Criado -> Opção 7 Menu_Opções
void pesquisa_sobre_passageiros_primeiro_nome(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros){
	limpar;
	cout << "\nDigite o Primeiro Nome do Passageiro a Pesquisar.\n\n";
	cout << "Nome: ";

	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	cout.width(49);
	pausa;
}// Fim Da Opção 7 Menu_Opções
void pesquisa_sobre_passageiros_segundo_nome(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros){
	limpar;
	cout << "\nDigite o Segundo Nome do Passageiro a Pesquisar.\n\n";
	cout << "Nome: ";

	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	cout.width(49);
	pausa;
}// Fim Da Opção 7 Menu_Opções

// Opção 8 - Menu_Opções - Funções
void editar_nome_passageiro(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros){
	limpar;
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(55);
	cout << right << "Editar Nome Do Passageiro.\n";
	cout << "----------------------------------------------------------------------------\n\n";
	pausa;
}// Fim Da Opção 8 Menu_Opções

// Opção 9 - Menu_Opções - Funções
void editar_nacionalidade_passageiro(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros){
	limpar;
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(55);
	cout << right << "Editar Nacionalidade Do Passageiro.\n";
	cout << "----------------------------------------------------------------------------\n\n";

	pausa;
}// Fim Da Opção 9 Menu_Opções

// Opção 10 - Menu_Opções - Funções
void editar_destino_voo(aviao &pista, aviao &aproximar, aviao &descolar){
	limpar;
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(55);
	cout << right << "Editar Destino do Voo.\n";
	cout << "----------------------------------------------------------------------------\n\n";

	pausa;
}// Fim Da Opção 10 Menu_Opções