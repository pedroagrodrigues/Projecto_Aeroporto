#include "bibliotecas.h"
//CPP Dedicado às Funções do Menu_Opções;

//----Sorting Functions----
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



// ----------------Funções_Menu_Opções-------------------

// 1ª Funcionalidade Menu_Opções
void lista_todos_passageiros(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros){
	limpar;

	cout << "\nLista De Todos os Passageiros.\n";

	// Lista De Passageiros Que Estão Nos Aviões Em Aproximação
	cout << "\n-------------------------------------------------------\n";
	cout << "Em Aproximação:\n";
	cout << "-------------------------------------------------------\n\n";
		for (int i = 0; i < 10; i++)
				for (int j = 0; j < aprox[i].capacidade; j++)
				    cout << aprox[i].passageiro[j].segundo_nome << ", " << aprox[i].passageiro[j].primeiro_nome << "\t->\t" << aprox[i].passageiro[j].nacionalidade << endl;

    // Lista De Passageiros Que Estão Nos Avições Em Pista
	cout << "\n-------------------------------------------------------\n";
	cout << "Em Pista:\n";
	cout << "-------------------------------------------------------\n\n";
	   for (int i = 0; i < 7; i++)
		  for (int j = 0; j < pista[i].capacidade; j++)
				cout << pista[i].passageiro[j].segundo_nome << ", " << pista[i].passageiro[j].primeiro_nome << "\t->\t" << pista[i].passageiro[j].nacionalidade << endl;


	// Lista De Passageiros Que Estão Nos Avições Em Descolagem
	cout << "\n-------------------------------------------------------\n";
	cout << "Em Descolar:\n";
	cout << "-------------------------------------------------------\n\n";
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < desc[i].capacidade; j++)
				cout << desc[i].passageiro[j].segundo_nome << ", " << desc[i].passageiro[j].primeiro_nome << "\t->\t" << desc[i].passageiro[j].nacionalidade << endl;

	// Lista De Passageiros Que Estão No Terminal Do Aeroporto
	cout << "\n-------------------------------------------------------\n";
	cout << "No Terminal:\n";
	cout << "-------------------------------------------------------\n\n";
	     for (int j = 0; j < 30; j++)
			if (passageiros[j].turn != -1)
				cout << passageiros[j].humman.segundo_nome << ", " << passageiros[j].humman.primeiro_nome << "\t->\t" << passageiros[j].humman.nacionalidade << endl;

	pausa;

} // Fim Da 1ª Função Do Menu_Opções
void lista_todos_passageiros_ordenados(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros) {
	limpar;
	//----------APROX--------
	pessoa * temp = new pessoa[150];
	int current = 0;//current serve para contar o interior do array temp
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < aprox[i].capacidade; j++) {
			temp[current] = aprox[i].passageiro[j];
			current++;
		}
	sort_by_name(temp, current);
	cout << "\nLista De Todos os Passageiros Ordenados Por Ordem Alfabética.\n";
	cout << "----------------------------------------------------------------------------\n\n";
	// Lista De Passageiros Que Estão Nos Aviões Em Aproximação
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(48);
	cout << right << "Em Aproximação:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	for (int i = 0; i < current; i++) {
		cout.width(49);
		cout << left << temp[i].segundo_nome + ", " + temp[i].primeiro_nome;
		cout << internal << temp[i].nacionalidade << endl;
	}

	//--------PISTA---------
	temp = new pessoa[107];
	current = 0;//current serve para contar o interior do array temp
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < pista[i].capacidade; j++) {
			temp[current] = pista[i].passageiro[j];
			current++;
		}
	sort_by_name(temp, current);

	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(45);
	cout << right << "Em Pista:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	for (int i = 0; i < current; i++) {
		cout.width(49);
		cout << left << temp[i].segundo_nome + ", " + temp[i].primeiro_nome;
		cout << internal << temp[i].nacionalidade << endl;
	}
	//-------DESC-------

	temp = new pessoa[75];
	current = 0;//current serve para contar o interior do array temp
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < desc[i].capacidade; j++) {
			temp[current] = desc[i].passageiro[j];
			current++;
		}
	sort_by_name(temp, current);
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(45);
	cout << right << "A Descolar:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	for (int i = 0; i < current; i++) {
		cout.width(49);
		cout << left << temp[i].segundo_nome + ", " + temp[i].primeiro_nome;
		cout << internal << temp[i].nacionalidade << endl;
	}
	//-----------No Terminal-------

	temp = new pessoa[30];
	current = 0;//current serve para contar o interior do array temp
	for (int i = 0; i < 30; i++)
		if(passageiros[i].turn!=-1){
			temp[current] = passageiros[i].humman;
			current++;
		}
	sort_by_name(temp, current);
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(45);
	cout << right << "No Terminal:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	for (int i = 0; i < current; i++) {
		cout.width(49);
		cout << left << temp[i].segundo_nome + ", " + temp[i].primeiro_nome;
		cout << internal << temp[i].nacionalidade << endl;
	}
	delete[] temp;
	pausa;
}

// 2ª Funcionalidade Menu_Opções
void lista_todos_voos(aviao * pista, aviao * aprox, aviao * desc) {
	limpar;
	cout << "\nLista De Todos os Voos.\n";

	
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(48);
	cout << right << "Em Aproximação:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Modelo";
	cout.width(30);
	cout << "Origem";
	cout.width(30);
	cout << "Destino\n\n";
	for (int i = 0; i < 10; i++) {
		cout.width(27);
		cout << left << aprox[i].modelo;
		cout.width(27);
		cout << left << aprox[i].origem;
		cout << aprox[i].destino << endl;
	}
	
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(45);
	cout << right << "Na Pista:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Modelo";
	cout.width(30);
	cout << "Origem";
	cout.width(30);
	cout << "Destino\n\n";
	for (int i = 0; i < 7; i++) {
		cout.width(27);
		cout << left << pista[i].modelo;
		cout.width(27);
		cout << left << pista[i].origem;
		cout << pista[i].destino << endl;
	}
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(45);
	cout << right << "Em Descolar:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Modelo";
	cout.width(30);
	cout << "Origem";
	cout.width(35);
	cout << "Destino\n\n";
	for (int i = 0; i < 5; i++) {
		cout.width(27);
		cout << left << desc[i].modelo;
		cout.width(27);
		cout << left << desc[i].origem;
		cout << desc[i].destino << endl;
	}
	pausa;
	

} // Fim da 2ª Funcionalidade
void lista_voos_pista_descolar(aviao * pista, aviao * desc) {
	limpar;
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(45);
	cout << right << "Na Pista:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Modelo";
	cout.width(30);
	cout << "Origem";
	cout.width(30);
	cout << "Destino\n\n";
	for (int i = 0; i < 7; i++) {
		cout.width(27);
		cout << left << pista[i].modelo;
		cout.width(27);
		cout << left << pista[i].origem;
		cout << pista[i].destino << endl;
	}
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(45);
	cout << right << "Em Descolar:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Modelo";
	cout.width(30);
	cout << "Origem";
	cout.width(35);
	cout << "Destino\n\n";
	for (int i = 0; i < 5; i++) {
		cout.width(27);
		cout << left << desc[i].modelo;
		cout.width(27);
		cout << left << desc[i].origem;
		cout << desc[i].destino << endl;
	}
	pausa;
}



// 3ª Funcionalidade Menu_Opções
void lista_passageiros_pista(aviao * pista) {
	limpar;
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(55);
	cout << right << "Lista De Todos os Passageiros Em Pista:";
	cout << "\n----------------------------------------------------------------------------\n\n";
	int line = 0; //variável para fazer endl
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < pista[i].capacidade; j++) {
			if (line == 3) {
				line = 0;
				cout << endl;
			}
			cout.width(12);
			cout << pista[i].passageiro[j].segundo_nome << ", " << pista[i].passageiro[j].primeiro_nome << "\t";
			line++;
		}
	}
	cout << endl;
	pausa;
} // Fim da 3ª Funcionalidade

// 4ª Funcionalidade Menu_Opções
void lista_passageiros_pista_nacionalidade(aviao * pista) {
	limpar;
	pessoa * temp = new pessoa[107];
	int current = 0;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < pista[i].capacidade; j++) {
			temp[current] = pista[i].passageiro[j];
			current++;
		}

	sort_by_nacionality(temp, current);
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(70);
	cout << "Lista De Todos Passageiros em Pista Ordenados Por Nacionalidade:";
	cout << "\n----------------------------------------------------------------------------\n\n";
	cout << "Nome";
	cout.width(60);
	cout << "Nacionalidade\n\n";
	for (int i = 0; i < current; i++) {
		cout.width(49);
		cout << left << temp[i].segundo_nome + ", " + temp[i].primeiro_nome;
		cout << internal << temp[i].nacionalidade << endl;
	}
	delete[] temp;
	pausa;

}
