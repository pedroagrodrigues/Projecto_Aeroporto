#include "bibliotecas.h"
//CPP Dedicado �s Fun��es do Menu_Op��es;

// 1� Funcionalidade Menu_Op��es
void lista_todos_passageiros(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros){
	limpar;
	cout << "\nLista De Todos os Passageiros.\n";
	
	// Lista De Passageiros Que Est�o Nos Avi�es Em Aproxima��o
	cout << "\n-------------------------------------------------------\n";
	cout << "Em Aproxima��o:\n"; 
	cout << "-------------------------------------------------------\n\n";
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < aprox[i].capacidade; j++)
			cout << aprox[i].passageiro[j].segundo_nome << ", " << aprox[i].passageiro[j].primeiro_nome << "\t->\t" << aprox[i].passageiro[j].nacionalidade << endl;

	// Lista De Passageiros Que Est�o Nos Avi��es Em Pista
	cout << "\n-------------------------------------------------------\n";
	cout << "Em Pista:\n";
	cout << "-------------------------------------------------------\n\n";
	for (int i = 0; i < 7; i++) 
		for (int j = 0; j < pista[i].capacidade; j++)		
			cout << pista[i].passageiro[j].segundo_nome << ", " << pista[i].passageiro[j].primeiro_nome << "\t->\t" << pista[i].passageiro[j].nacionalidade << endl;
	
	// Lista De Passageiros Que Est�o Nos Avi��es Em Descolagem
	cout << "\n-------------------------------------------------------\n";
	cout << "Em Descolar:\n";
	cout << "-------------------------------------------------------\n\n";
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < desc[i].capacidade; j++)	
			cout << desc[i].passageiro[j].segundo_nome << ", " << desc[i].passageiro[j].primeiro_nome << "\t->\t" << desc[i].passageiro[j].nacionalidade << endl;
	
	// Lista De Passageiros Que Est�o No Terminal Do Aeroporto
	cout << "\n-------------------------------------------------------\n";
	cout << "No Terminal:\n";
	cout << "-------------------------------------------------------\n\n";
	for (int j = 0; j < 30; j++)
		if(passageiros[j].turn!=-1)
			cout << passageiros[j].humman.segundo_nome << ", " << passageiros[j].humman.primeiro_nome << "\t->\t" << passageiros[j].humman.nacionalidade << endl;
	pausa;
} // Fim Da 1� Fun��o Do Menu_Op��es

// 2� Funcionalidade Menu_Op��es
void lista_todos_voos(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros) {
	limpar;
	cout << "\nLista De Todos os Voos.\n";

	
	cout << "\n----------------------------------------------------------------------------\n";
	cout << "Em Aproxima��o:\n";
	cout << "-----------------------------------------------------------------------------\n\n";
	cout << "Modelo" << "\t\t\t\t" << "Origem" << "\t\t\t\t" << "Destino\n\n";
	for (int i = 0; i < 10; i++) {
		cout << aprox[i].modelo << setw(35) << aprox[i].origem << setw(35) << aprox[i].destino << endl;
	}

	cout << "\n----------------------------------------------------------------------------\n";
	cout << "Na Pista:\n";
	cout << "-----------------------------------------------------------------------------\n\n";
	cout << "Modelo" << "\t\t\t\t" << "Origem" << "\t\t\t\t" << "Destino\n\n";
	for (int i = 0; i < 7; i++) {
		cout << pista[i].modelo << setw(35) << pista[i].origem << setw(35) << pista[i].destino << endl;
	}
	
	cout << "\n----------------------------------------------------------------------------\n";
	cout << "Em Descolar:\n";
	cout << "-----------------------------------------------------------------------------\n\n";
	cout << "Modelo" << "\t\t\t\t" << "Origem" << "\t\t\t\t" << "Destino\n\n"; 
	for (int i = 0; i < 5; i++) {
		cout <<  desc[i].modelo << setw(35) << desc[i].origem << setw(35) << desc[i].destino << endl;
	}
	pausa;
	

} // Fim da 2� Funcionalidade

// 3� Funcionalidade Menu_Op��es
void lista_passageiros_pista(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros) {
	limpar;
	cout << "\nLista De Todos os Passageiros Em Pista.\n";

	cout << "\n-------------------------------------------------------\n";
	cout << "Em Pista:\n";
	cout << "-------------------------------------------------------\n\n";
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < pista[i].capacidade; j++)
			cout << pista[i].passageiro[j].segundo_nome << ", " << pista[i].passageiro[j].primeiro_nome << endl;
pausa;
} // Fim da 3� Funcionalidade

// 4� Funcionalidade Menu_Op��es
void lista_passageiros_pista_nacionalidade(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros) {
	limpar;
	cout << "\nLista De Todos Passageiros em Pista Ordenados Por Nacionalidade.\n";
	cout << "\n-------------------------------------------------------\n";
	cout << "Em Pista:\n";
	cout << "-------------------------------------------------------\n\n";
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < pista[i].capacidade; j++)
			cout << pista[i].passageiro[j].segundo_nome << ", " << pista[i].passageiro[j].primeiro_nome << "\t->\t" << pista[i].passageiro[j].nacionalidade << endl;
	pausa;

}
