#include "bibliotecas.h"



// Sub-Menu - Opção 1 Menu_Opções
int mostrar_passageiros(aviao & pista, aviao & aproximar, aviao & descolar, terminal & passageiros) {
	while (1) {
		limpar;
	cout << "\n(1) Lista Todos Passageiros" << " (2) Lista Todos os Passageiros Ordenados" << "\t (0) - Voltar" << endl;
	cout << "-------------------------------------------------------------------------------\n";
	

		switch (_getch()) {

		case'1':
			lista_todos_passageiros(pista, aproximar, descolar, passageiros);
			break;
		case'2':
			lista_todos_passageiros_ordenados(pista, aproximar, descolar, passageiros);
			break;
		case'0':
			return 0;
			break;
		default:
			limpar;
			cout << "\nIntroduza Uma Opção Válida\n.";
			pausa;
			break;
		}
	} // Fim do ciclo Criado para continuar sempre do Menu_Opções Funcionalidade 1
} // Fim do da função criado para Menu_Opções Funcionalidade 1

// Sub-Menu - Opção 8 Menu_Opções
int modo_editar(aviao & pista, aviao & aproximar, aviao & descolar, terminal & passageiros) {
	while (1) {
		limpar;
		cout << "-------------------------------------------------------------------------------\n\n";
		lista_inicial_menu_8(pista,aproximar,descolar,passageiros);
		cout << "\nQue Método Pretende Utilizar Para Editar?";
		cout << "\n(1) Número de Ticket" << " (2) Por Nome" << "\t (0) - Voltar\n" << endl;
		

		switch (_getch()) {

		case'1':
			tkt_select(pista, aproximar, descolar, passageiros);
			break;
		case'2':
			primeiro_nome(pista, aproximar, descolar, passageiros);
			break;
		case'3':
			//editar_destino_voo(pista, aproximar,descolar);
			break;
		case'0':
			return 0;
			break;
		default:
			limpar;
			cout << "\nIntroduza Uma Opção Válida\n.";
			pausa;
			break;
		}
	} // Fim do ciclo Criado para continuar sempre do Menu_Opções Funcionalidade 8
} // Fim do da função criado para Menu_Opções Funcionalidade 8

int modo_editar_avioes(aviao & pista, aviao & aproximar, aviao & descolar, terminal & passageiros) {
	string name;
	while (1) {
		limpar;
		cout << left;
		cout << "-------------------------------------------------------------------------------\n\n";
		lista_inicial_menu_9(pista, aproximar, descolar);
		cout << "1 - Editar \t0 - Sair\n";
		
		switch (_getch()) {

		case'1':
			cout << "\nIntroduza o nome do voo.\t0 - Sair\n";
			getline(cin, name);
			aviao_edit(pista, aproximar, descolar, name);
		break;
		case'0':
			return 0;
			break;
		default:
			limpar;
			cout << "\nIntroduza Uma Opção Válida\n.";
			pausa;
			break;
		}
	} // Fim do ciclo Criado para continuar sempre do Menu_Opções Funcionalidade 8
}

// Chamada Menu_Opções - PRINCIPAL
int opcoes(aviao & pista, aviao & aproximar, aviao & descolar, terminal & passageiros) {
	while (1) { // Ciclo Criado Para Utilizador Estar Sempre Dentro Do Menu Até Ordem Em Contrário
		limpar;
		cout << "\nEntrou no Menu Opções. Por Favor Selecione Uma Das Seguintes Funcionalidades\n\n";
		cout << "1 - Mostrar Todos os Passageiros.\n";
		cout << "2 - Mostrar Voos em Pista e a Descolar (Ordenados Alfabeticamente Destinos).\n";
		cout << "3 - Mostrar Passageiros em Pista.\n";
		cout << "4 - Mostrar Passageiros em Pista (Por Nacionalidade).\n";
		cout << "5 - Pesquisa de Passageiros no Aeroporto (Origem Estrangeira).\n";
		cout << "6 - Lista De Passageiros Origem Estrangeira no Aeroporto (Ordenada Por Ordem Alfabética).\n";
		cout << "7 - Pesquisa Sobre os Passageiros.\n";
		cout << "8 - Entrar no Modo Editar Passageiros.\n";
		cout << "9 - Entrar no Modo Editar Destinos.\n";
		cout << "\n0 - Voltar"; // Cout Para Sair do Menu_Opções
		switch (_getch()) {
		case '1':
			mostrar_passageiros(pista, aproximar, descolar, passageiros);
			break;
		case '2':
			lista_voos_pista_descolar(pista, descolar);
			break;
		case '3':
			lista_passageiros_pista(pista);
			break;
		case '4':
			lista_passageiros_pista_nacionalidade(pista);
			break;
		case '5':
			pesquisa_estrangeiros_aeroporto(pista,passageiros);
			break;
		case '6':
			pesquisa_passageiros_estrangeiros_aeroporto_ordenados(pista, passageiros);
			break;
		case '7':
			pesquisa_sobre_passageiros(pista, descolar, aproximar, passageiros);
			break;
		case '8':
			modo_editar(pista, descolar, aproximar, passageiros);
			break;
		case '9':
			modo_editar_avioes(pista, descolar, aproximar, passageiros);
			break;
		case '0':
			return 0; // Fecho Do Menu_Opções
			break;
		default:
			limpar;
			cout << "\nPor Favor Introduza Uma Opção Válida.\n";
			break;
		} // Fim do Switch
	} // Fim Do "Ciclo" Criado Para Estar Sempre No Menu_Opções Até Ordem Em Contrário Do Utilizador
}