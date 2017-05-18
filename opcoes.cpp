#include "bibliotecas.h"



// Opção 1 Menu_Opções  (Sub Menu Com 2 Opções)
int todos_os_passageiros(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros) {
	while (1) {
		limpar;
	cout << "\n(1) Lista Todos Passageiros" << " (2) Lista Todos os Passageiros Ordenados" << "\t (0) - Voltar" << endl;
	cout << "-------------------------------------------------------------------------------\n";
	

		switch (_getch()) {

		case'1':
			lista_todos_passageiros(pista, aprox, desc, passageiros);
			break;
		case'2':
			lista_todos_passageiros_ordenados(pista, aprox, desc, passageiros);
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

// Opção 2 Menu_Opções  (Sub Menu Com 2 Opções)
int todos_voos_pista_desc(aviao * pista, aviao * aprox,  aviao * desc) {
	while (1) {
		limpar;
		cout << "\n(1) Lista Todos Voos" << " (2) Lista De Voos em Pista e a Descolar" << "\t (0) - Voltar" << endl;
		cout << "-------------------------------------------------------------------------------\n";
		switch (_getch()) {

		case'1':
			lista_todos_voos(pista, aprox, desc);
			break;
		case'2':
			lista_voos_pista_descolar(pista, desc);
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
	} // Fim do ciclo Criado para continuar sempre do Menu_Opções Funcionalidade 2
} // Fim do da função criado para Menu_Opções Funcionalidade 2

// Opção 5 Menu_Opções (Sub Menu Com 2 Opções)
int pesquisa_estrangeiros_aeroporto(aviao * pista, terminal * passageiros){
	
	while (1) {
		limpar;
		cout << "\n(1) Lista Todos Estrangeiros Aeroporto" << " (2) Pesquisa Passageiros Estrangeiros" << "\t (0) - Voltar" << endl;
		cout << "-------------------------------------------------------------------------------\n";
		
		switch (_getch()) {

		case'1':
			lista_passageiros_estrangeiros_aeroporto(pista, passageiros);
			break;
		
		case'2':
			pesquisa_passageiros_estrangeiros_aeroporto_manualmente(pista, passageiros);
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
		
		pausa;


	
	} // Fim do ciclo Criado para continuar sempre do Menu_Opções Funcionalidade 5
} // Fim do da função criado para Menu_Opções Funcionalidade 5

// Opção 7 Menu_Opções (Sub Menu Com 2 Opções)
int pesquisa_sobre_passageiros(aviao * pista, aviao * desc, aviao * aprox, terminal * passageiros){
	while (1) {
		limpar;
		cout.width(55);
		cout << right << "\nEntrou no Modo Pesquisa Sobre Passageiros no Aeroporto!\n";

		cout << "\n(1) Pesquisa Pelo Primeiro Nome" << " (2) Pesquisa Pelo Segundo Nome" << "\t (0) - Voltar" << endl;
		cout << "-------------------------------------------------------------------------------\n";

		switch (_getch()) {

		case'1':
			pesquisa_sobre_passageiros_primeiro_nome(aprox, desc, pista, passageiros);
			break;

		case'2':
			pesquisa_sobre_passageiros_segundo_nome(aprox, desc, pista, passageiros);
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

		pausa;


	} // Fim do ciclo Criado para continuar sempre do Menu_Opções Funcionalidade 7
} // Fim do da função criado para Menu_Opções Funcionalidade 7

// Menu_Opções (Chamada do Menu_Opções -> Principal)
int opcoes(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros) {
	while (1) { // Ciclo Criado Para Utilizador Estar Sempre Dentro Do Menu Até Ordem Em Contrário
		limpar;
		cout << "\nEntrou no Menu Opções. Por Favor Selecione Uma Das Seguintes Funcionalidades\n\n";
		cout << "1 - Mostrar Todos os Passageiros.\n";
		cout << "2 - Mostrar Todos os Voos.\n";
		cout << "3 - Mostrar Passageiros em Pista.\n";
		cout << "4 - Mostrar Passageiros em Pista (Por Nacionalidade).\n";
		cout << "5 - Pesquisa De Passageiros Estrangeiros no Aeroporto.\n";
		cout << "6 - Lista De Passageiros Origem Estrangeira no Aeroporto (Ordem Alfabética).\n";
		cout << "7 - Pesquisa Sobre os Passageiros.\n";
		cout << "8 - Editar Nome do Passageiro.\n";
		cout << "9 - Editar Nacionalidade do Passageiro.\n";
		cout << "10 - Editar Destino de Voo.\n";
		cout << "\n0 - Voltar"; // Cout Para Sair do Menu_Opções
		switch (_getch()) {

		case '1':
			todos_os_passageiros(pista, aprox, desc, passageiros);
			break;
		case '2':
			todos_voos_pista_desc(pista, aprox, desc);
			break;

		case '3':
			lista_passageiros_pista(pista);
			break;

		case '4':
			lista_passageiros_pista_nacionalidade(pista, passageiros);
			break;

		case '5':
			pesquisa_estrangeiros_aeroporto(pista, passageiros);
			break;
		case '6':
			pesquisa_passageiros_estrangeiros_aeroporto_ordenados(pista, passageiros);
			break;
		case '7':
			pesquisa_sobre_passageiros(pista, aprox, desc, passageiros);
			break;
		case '8':
			editar_nome_passageiro(pista, aprox, desc, passageiros);
			break;
		case '9':
			editar_nacionalidade_passageiro(pista, aprox, desc, passageiros);
			break;
		case '10':
			editar_destino_voo(pista, aprox, desc, passageiros);
			break;
		case '0':
			return 0;
			break;
		default:
			limpar;
			cout << "\nPor Favor Introduza Uma Opção Válida.\n";
			break;
		} // Fim do Switch
	} // Fim Do "Ciclo" Criado Para Estar Sempre No Menu_Opções Até Ordem Em Contrário Do Utilizador
}