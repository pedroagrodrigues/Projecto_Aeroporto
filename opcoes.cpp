#include "bibliotecas.h"



// Sub-Menu - Op��o 1 Menu_Op��es
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
			cout << "\nIntroduza Uma Op��o V�lida\n.";
			pausa;
			break;
		}
	} // Fim do ciclo Criado para continuar sempre do Menu_Op��es Funcionalidade 1
} // Fim do da fun��o criado para Menu_Op��es Funcionalidade 1


  // Chamada Menu_Op��es - PRINCIPAL
int opcoes(aviao & pista, aviao & aproximar, aviao & descolar, terminal & passageiros) {
	while (1) { // Ciclo Criado Para Utilizador Estar Sempre Dentro Do Menu At� Ordem Em Contr�rio
		limpar;
		cout << "\nEntrou no Menu Op��es. Por Favor Selecione Uma Das Seguintes Funcionalidades\n\n";
		cout << "1 - Mostrar Todos os Passageiros.\n";
		cout << "2 - Mostrar Voos em Pista e a Descolar (Ordenados Alfab�ticamente Destinos).----------implementar\n";
		cout << "3 - Mostrar Passageiros em Pista.\n";
		cout << "4 - Mostrar Passageiros em Pista (Por Nacionalidade).\n";
		cout << "5 - Pesquisa de Passageiros no Aeroporto (Origem Estrangeira).----------implementar\n";
		cout << "6 - Lista De Passageiros Origem Estrangeira no Aeroporto (Ordenada Por Ordem Alfab�tica).\n";
		cout << "7 - Pesquisa Sobre os Passageiros.----------implementar\n";
		cout << "8 - Editar Nome do Passageiro.----------implementar\n";
		cout << "9 - Editar Nacionalidade do Passageiro.----------implementar\n";
		cout << "10 - Editar Destino de Voo.----------implementar\n";
		cout << "\n0 - Voltar"; // Cout Para Sair do Menu_Op��es
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
			editar_nome_passageiro(pista, descolar, aproximar, passageiros);
			break;
		case '9':
			editar_nacionalidade_passageiro(pista, descolar, aproximar, passageiros);
			break;
		case '10':
			editar_destino_voo(pista, descolar, aproximar);
			break;
		case '0':
			return 0; // Fecho Do Menu_Op��es
			break;
		default:
			limpar;
			cout << "\nPor Favor Introduza Uma Op��o V�lida.\n";
			break;
		} // Fim do Switch
	} // Fim Do "Ciclo" Criado Para Estar Sempre No Menu_Op��es At� Ordem Em Contr�rio Do Utilizador
}