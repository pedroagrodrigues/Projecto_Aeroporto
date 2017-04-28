#include "bibliotecas.h"


// Menu_Op��es_Funcionalidade1
int menu_opcoes_funcionalidade1(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros) {
	while (1) {
		limpar;
	cout << "\n(1) Lista Todos Passageiros" << " (2) Lista Todos os Passageiros Ordenados" << "\t (0) Voltar" << endl;
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
			cout << "\nIntroduza Uma Op��o V�lida\n.";
			pausa;
			break;
		}
	} // Fim do ciclo Criado para continuar sempre do Menu_Op��es Funcionalidade 1
} // Fim do da fun��o criado para Menu_Op��es Funcionalidade 1

// Menu_Op��es_Funcionalidade2
int menu_opcoes_funcionalidade2(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros) {
	while (1) {
		limpar;
		cout << "\n(1) Lista Todos Voos" << " (2) Lista Todos os Voos em Pista e a Descolar" << "\t (0) Voltar" << endl;
		cout << "-------------------------------------------------------------------------------\n";
		switch (_getch()) {

		case'1':
			lista_todos_voos(pista, aprox, desc, passageiros);
			break;
		case'2':
			lista_voos_pista_descolar(pista, aprox, desc, passageiros);
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
	} // Fim do ciclo Criado para continuar sempre do Menu_Op��es Funcionalidade 2
} // Fim do da fun��o criado para Menu_Op��es Funcionalidade 2

int opcoes(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros) {
	while (1) { // Ciclo Criado Para Utilizador Estar Sempre Dentro Do Menu At� Ordem Em Contr�rio
		limpar;
		cout << "\nEntrou no Menu Op��es. Por Favor Selecione Uma Das Seguintes Funcionalidades\n\n";
		cout << "1 - Mostrar Todos os Passageiros.\n";
		cout << "2 - Mostrar Todos os Voos em Pista e a Descolar.\n";
		cout << "3 - Mostrar Passageiros em Pista.\n";
		cout << "4 - Mostrar Passageiros em Pista (Por Nacionalidade).\n";
		cout << "5 - Pesquisa De Passageiros (Origem Estrangeira).\n";
		cout << "6 - Lista De Passageiros Origem Estrangeira no Aeroporto (Ordenada Por Ordem Alfab�tica).\n";
		cout << "7 - Pesquisa Sobre os Passageiros.\n";
		cout << "8 - Editar Nome do Passageiro.\n";
		cout << "9 - Editar Nacionalidade do Passageiro.\n";
		cout << "10 - Editar Destino de Voo.\n";
		cout << "\n0 - Voltar Consola Principal\t\t"; // Cout Para Sair do Menu_Op��es
		switch (_getch()){
		
		case '1':
			  menu_opcoes_funcionalidade1(pista, aprox, desc, passageiros);
			  break;
		case '2':
			menu_opcoes_funcionalidade2(pista, aprox, desc, passageiros);
			break;
		
		case '3':
			lista_passageiros_pista(pista, aprox, desc, passageiros);
			break;
	
		case '4':
			lista_passageiros_pista_nacionalidade(pista, aprox, desc, passageiros);
			break;
		
		case '5':
			limpar;
			cout << "\nPesquisa De Passageiros (Origem Estrangeira).\n";
			cout << "-------------------------------------------------------\n";
			cout << "\nFun��o Apenas Dispon�vel na 2� Fase Do Projecto.\n";// Remover Depois Da Fun��o Implementada
			// Fun�ao por implementar ainda
			pausa;
			break;
		case '6':
			limpar;
			cout << "\nLista De Passageiros Origem Estrangeira no Aeroporto (Ordenada Por Ordem Alfab�tica).\n";
			cout << "-------------------------------------------------------\n";
			cout << "\nFun��o Apenas Dispon�vel na 2� Fase Do Projecto.\n";// Remover Depois Da Fun��o Implementada
			// Fun�ao por implementar ainda
			pausa;
			break;
		case '7':
			limpar;
			cout << "\nPesquisa Sobre os Passageiros.\n";
			cout << "-------------------------------------------------------\n";
			cout << "\nFun��o Apenas Dispon�vel na 2� Fase Do Projecto.\n";// Remover Depois Da Fun��o Implementada
			// Fun�ao por implementar ainda
			pausa;
			break;
		case '8':
			limpar;
			cout << "\nEditar Nome do Passageiro.\n";
			cout << "-------------------------------------------------------\n";
			cout << "\nFun��o Apenas Dispon�vel na 2� Fase Do Projecto.\n"; // Remover Depois Da Fun��o Implementada
			// Fun�ao por implementar ainda
			pausa;
			break;
		case '9':
			limpar;
			cout << "\nEditar Nacionalidade do Passageiro.\n";
			cout << "-------------------------------------------------------\n";
			cout << "\nFun��o Apenas Dispon�vel na 2� Fase Do Projecto.\n"; // Remover Depois Da Fun��o Implementada
			// Fun�ao por implementar ainda
			pausa;
			break;
		case '10':
			limpar;
			cout << "\nEditar Destino de Voo.\n";
			cout << "-------------------------------------------------------\n";
			cout << "\nFun��o Apenas Dispon�vel na 2� Fase Do Projecto.\n"; // Remover Depois Da Fun��o Implementada
			// Fun�ao por implementar ainda
			pausa;
			break;
		case '0':
			return 0;
			break;
		default:
			limpar;
			cout << "\nPor Favor Introduza Uma Op��o V�lida.\n";
			break;
		} // Fim do Switch
	} // Fim Do "Ciclo" Criado Para Estar Sempre No Menu_Op��es At� Ordem Em Contr�rio Do Utilizador
}