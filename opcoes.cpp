#include "bibliotecas.h"


int opcoes(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros) {
	while (1) { // Ciclo Criado Para Utilizador Estar Sempre Dentro Do Menu Até Ordem Em Contrário
		limpar;
		cout << "\nEntrou no Menu Opções. Por Favor Selecione Uma Das Seguintes Funcionalidades\n\n";
		cout << "1 - Mostrar Todos os Passageiros.\n";
		cout << "2 - Mostrar Todos os Voos em Pista e a Descolar.\n";
		cout << "3 - Mostrar Passageiros em Pista.\n";
		cout << "4 - Mostrar Passageiros em Pista (Por Nacionalidade).\n";
		cout << "5 - Pesquisa De Passageiros (Origem Estrangeira).(2ª Fase)\n";
		cout << "6 - Lista De Passageiros Origem Estrangeira no Aeroporto (Ordenada Por Ordem Alfabética).(2ª Fase)\n";
		cout << "7 - Pesquisa Sobre os Passageiros.(2ª Fase)\n";
		cout << "8 - Editar Nome do Passageiro.(2ª Fase)\n";
		cout << "9 - Editar Nacionalidade do Passageiro.(2ª Fase)\n";
		cout << "10 - Editar Destino de Voo.(2ª Fase)\n";
		cout << "\n0 - Voltar\t\t"; // Cout Para Sair do Menu_Opções
		switch (_getch()){
		case '1':
			lista_todos_passageiros(pista, aprox, desc, passageiros);
			break;
		case '2':
			limpar;
			cout << "\nLista De Voos em Pista e Descolar.\n";
			cout << "------------------------------------------------\n";
			// Funçao por implementar ainda
			pausa;
			break;
		case '3':
			limpar;
			cout << "\nLista De Todos os Passageiros em Pista.\n";
			cout << "-----------------------------------------------------\n";
			// Funçao por implementar ainda
			pausa;
			break;
		case '4':
			limpar;
			cout << "\nLista De Passageiros em Pista (Por Nacionalidade).\n";
			cout << "-------------------------------------------------------\n";
			// Funçao por implementar ainda
			pausa;
			break;
		case '5':
			limpar;
			cout << "\nPesquisa De Passageiros (Origem Estrangeira).\n";
			cout << "-------------------------------------------------------\n";
			// Funçao por implementar ainda
			pausa;
			break;
		case '6':
			limpar;
			cout << "\nLista De Passageiros Origem Estrangeira no Aeroporto (Ordenada Por Ordem Alfabética).\n";
			cout << "-------------------------------------------------------\n";
			// Funçao por implementar ainda
			pausa;
			break;
		case '7':
			limpar;
			cout << "\nPesquisa Sobre os Passageiros.\n";
			cout << "-------------------------------------------------------\n";
			// Funçao por implementar ainda
			pausa;
			break;
		case '8':
			limpar;
			cout << "\nEditar Nome do Passageiro.\n";
			cout << "-------------------------------------------------------\n";
			// Funçao por implementar ainda
			pausa;
			break;
		case '9':
			limpar;
			cout << "\nEditar Nacionalidade do Passageiro.\n";
			cout << "-------------------------------------------------------\n";
			// Funçao por implementar ainda
			pausa;
			break;
		case '10':
			limpar;
			cout << "\nEditar Destino de Voo.\n";
			cout << "-------------------------------------------------------\n";
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