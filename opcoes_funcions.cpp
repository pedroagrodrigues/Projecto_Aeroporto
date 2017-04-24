#include "bibliotecas.h"

// Funcionalidade da Op��o 1 do Menu_Op��es
void lista_todos_passageiros(aviao pista[], aviao aprox[], aviao desc[], terminal * passageiros) {
	limpar;
	cout << "\nLista De Todos os Passageiros.\n";
	
	// Lista De Passageiros Que Est�o Nos Avi�es Em Aproxima��o
	cout << "\n-------------------------------------------------------\n";
	cout << "Em Aproxima��o:\n"; 
	cout << "-------------------------------------------------------\n\n";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < aprox[i].capacidade; j++) {

			cout << aprox[i].passageiro[j].segundo_nome << ", " << aprox[i].passageiro[j].primeiro_nome << "\t->\t" << aprox[i].passageiro[j].nacionalidade << endl;

		}

	}
	// Lista De Passageiros Que Est�o Nos Avi��es Em Pista
	cout << "\n-------------------------------------------------------\n";
	cout << "Em Pista:\n";
	cout << "-------------------------------------------------------\n\n";
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < pista[i].capacidade; j++) {

			
			cout << pista[i].passageiro[j].segundo_nome << ", " << pista[i].passageiro[j].primeiro_nome << "\t->\t" << pista[i].passageiro[j].nacionalidade << endl;

		}

	}
	// Lista De Passageiros Que Est�o Nos Avi��es Em Descolagem
	cout << "\n-------------------------------------------------------\n";
	cout << "Em Descolar:\n";
	cout << "-------------------------------------------------------\n\n";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < desc[i].capacidade; j++) {

		
			cout << desc[i].passageiro[j].segundo_nome << ", " << desc[i].passageiro[j].primeiro_nome << "\t->\t" << desc[i].passageiro[j].nacionalidade << endl;

		}

	}
	// Lista De Passageiros Que Est�o No Terminal Do Aeroporto
	cout << "\n-------------------------------------------------------\n";
	cout << "No Terminal:\n";
	cout << "-------------------------------------------------------\n\n";
	
	for (int j = 0; j < 30; j++) {
			
		if(passageiros[j].turn!=-1)
			cout << passageiros[j].humman.segundo_nome << ", " << passageiros[j].humman.primeiro_nome << "\t->\t" << passageiros[j].humman.nacionalidade << endl;
	}

	
	
	pausa;
} // Fim Da 1� Fun��o Do Menu_Op��es