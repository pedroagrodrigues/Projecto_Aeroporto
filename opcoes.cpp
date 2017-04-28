#include "bibliotecas.h"


int opcoes(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros) {
	while (1) { // Ciclo Criado Para Utilizador Estar Sempre Dentro Do Menu Até Ordem Em Contrário
		limpar;
		cout << "\nEntrou no Menu Opções. Por Favor Selecione Uma Das Seguintes Funcionalidades\n\n";
		cout << "1  - Mostrar Todos os Passageiros.\n";
		cout << "2  - Mostrar Todos os Passageiros (Ordenado Alfabeticamente Por Último Nome.\n";
		cout << "3  - Mostrar Todos os Voos.\n";
		cout << "4  - Mostrar Todos os Voos em Pista e a Descolar.\n";
		cout << "5  - Mostrar Passageiros em Pista.\n";
		cout << "6  - Mostrar Passageiros em Pista (Por Nacionalidade).\n";
		cout << "7  - Pesquisa De Passageiros (Origem Estrangeira).\n";
		cout << "8  - Lista De Passageiros Origem Estrangeira no Aeroporto (Ordenada Alfabeticamente).\n";
		cout << "9  - Pesquisa Sobre os Passageiros.\n";
		cout << "10 - Editar Nome do Passageiro.\n";
		cout << "11 - Editar Nacionalidade do Passageiro.\n";
		cout << "12 - Editar Destino de Voo.\n";
		cout << "\n0 - Voltar Consola Principal\t\t"; // Cout Para Sair do Menu_Opções
		switch (_getch()){
		case '1':
			lista_todos_passageiros(pista, aprox, desc, passageiros);
			break;
		case '3':
			lista_todos_voos(pista, aprox, desc, passageiros);
			break;
		case '5':
			lista_passageiros_pista(pista, aprox, desc, passageiros);
			break;
		case '6':
			lista_passageiros_pista_nacionalidade(pista, aprox, desc, passageiros);
			break;
		case '7':
			limpar;
			cout << "\nPesquisa De Passageiros (Origem Estrangeira).\n";
			cout << "-------------------------------------------------------\n";
			cout << "\nFunção Apenas Disponível na 2ª Fase Do Projecto.\n";// Remover Depois Da Função Implementada
			// Funçao por implementar ainda
			pausa;
			break;
		case '8':
			limpar;
			cout << "\nLista De Passageiros Origem Estrangeira no Aeroporto (Ordenada Por Ordem Alfabética).\n";
			cout << "-------------------------------------------------------\n";
			cout << "\nFunção Apenas Disponível na 2ª Fase Do Projecto.\n";// Remover Depois Da Função Implementada
			// Funçao por implementar ainda
			pausa;
			break;
		case '9':
			limpar;
			cout << "\nPesquisa Sobre os Passageiros.\n";
			cout << "-------------------------------------------------------\n";
			cout << "\nFunção Apenas Disponível na 2ª Fase Do Projecto.\n";// Remover Depois Da Função Implementada
			// Funçao por implementar ainda
			pausa;
			break;
		case '10':
			limpar;
			cout << "\nEditar Nome do Passageiro.\n";
			cout << "-------------------------------------------------------\n";
			cout << "\nFunção Apenas Disponível na 2ª Fase Do Projecto.\n"; // Remover Depois Da Função Implementada
			// Funçao por implementar ainda
			pausa;
			break;
		case '11':
			limpar;
			cout << "\nEditar Nacionalidade do Passageiro.\n";
			cout << "-------------------------------------------------------\n";
			cout << "\nFunção Apenas Disponível na 2ª Fase Do Projecto.\n"; // Remover Depois Da Função Implementada
			// Funçao por implementar ainda
			pausa;
			break;
		case '12':
			limpar;
			cout << "\nEditar Destino de Voo.\n";
			cout << "-------------------------------------------------------\n";
			cout << "\nFunção Apenas Disponível na 2ª Fase Do Projecto.\n"; // Remover Depois Da Função Implementada
			// Funçao por implementar ainda
			pausa;
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