#include "bibliotecas.h"
//CPP Dedicado às Funções do Menu_Opções;

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



// ----------------Funções_Menu_Opções-------------------

// (Sub Menu Com 2 Opções) - Opção 1 Menu_Opções
void lista_todos_passageiros(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros){
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
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < aprox[i].capacidade; j++) {
				cout.width(49);
				cout << left << aprox[i].passageiro[j].segundo_nome + ", " + aprox[i].passageiro[j].primeiro_nome;
				cout << internal << aprox[i].passageiro[j].nacionalidade << endl;
			}

    // Lista De Passageiros Que Estão Nos Avições Em Pista
		cout << "\n----------------------------------------------------------------------------\n";
		cout.width(48);
		cout << right << "Em Pista:\n";
		cout << "----------------------------------------------------------------------------\n\n";
		cout << "Nome";
		cout.width(60);
		cout << "Nacionalidade\n\n";
		for (int i = 0; i < 7; i++)
			for (int j = 0; j < pista[i].capacidade; j++) {
				cout.width(49);
				cout << left << pista[i].passageiro[j].segundo_nome + ", " + pista[i].passageiro[j].primeiro_nome;
				cout << internal << pista[i].passageiro[j].nacionalidade << endl;
			}

	// Lista De Passageiros Que Estão Nos Avições Em Descolagem
	   cout << "\n----------------------------------------------------------------------------\n";
	   cout.width(48);
	   cout << right << "Em Descolar:\n";
	   cout << "----------------------------------------------------------------------------\n\n";
	   cout << "Nome";
	   cout.width(60);
	   cout << "Nacionalidade\n\n";
	   for (int i = 0; i < 5; i++)
		   for (int j = 0; j < desc[i].capacidade; j++){
		   cout.width(49);
		   cout << left << desc[i].passageiro[j].segundo_nome + ", " + desc[i].passageiro[j].primeiro_nome;
		   cout << internal << desc[i].passageiro[j].nacionalidade << endl;
	   }

	// Lista De Passageiros Que Estão No Terminal Do Aeroporto
		cout << "\n----------------------------------------------------------------------------\n";
		cout.width(48);
		cout << right << "No Terminal:\n";
		cout << "----------------------------------------------------------------------------\n\n";
		cout << "Nome";
		cout.width(60);
		cout << "Nacionalidade\n\n";
		for (int j = 0; j < 30; j++) {
			if (passageiros[j].turn != -1) {
				cout.width(49);
				cout << left << passageiros[j].humman.segundo_nome + ", " + passageiros[j].humman.primeiro_nome;
				cout << internal << passageiros[j].humman.nacionalidade << endl;
			}
			}
	pausa;

} // Fim Da 1ª Função Do Menu_Opções
void lista_todos_passageiros_ordenados(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros) {
	limpar;
	//----------APROX--------
	pessoa * temp = new pessoa[360];
	int current = 0;//current serve para contar o interior do array temp
	for (int i = 0; i < 30; i++)
		if (passageiros[i].turn != -1) {
			temp[current] = passageiros[i].humman;
			current++;
		}
	for (int i = 0; i < 7; i++)
		for (int j = i; j < pista[i].capacidade; j++){
			temp[current] = pista[i].passageiro[j];
			current++;
		}
	for (int i = 0; i < 10; i++)
		for (int j = i; j < aprox[i].capacidade; j++) {
			temp[current] = aprox[i].passageiro[j];
			current++;
		}
		for (int i = 0; i < 5; i++)
			for (int j = i; j < desc[i].capacidade; j++) {
				temp[current] = desc[i].passageiro[j];
				current++;
			}
	sort_by_name(temp, current);
	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(65);
	cout << right << "Lista de Passageiros Ordenada Alfabeticamente.\n";
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

// (Sub Menu Com 2 Opções) - Opção 2 Menu_Opções
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
	cout.width(30);
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
	aviao * temp = new aviao[7];
	for (int i = 0; i < 7; i++) {
		temp[i] = pista[i];
	}
	sort_by_destino(temp, 7);

	limpar;
	cout << "\nLista Todos os Voos, em Pista e a Descolar, Ordenados Alfabéticamente.\n";
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
		cout << left << temp[i].modelo;
		cout.width(27);
		cout << left << temp[i].origem;
		cout << temp[i].destino << endl;
	}

	temp = new aviao[5];
	for (int i = 0; i < 5; i++) {
		temp[i] = desc[i];
	}
	sort_by_destino(temp, 5);

	cout << "\n----------------------------------------------------------------------------\n";
	cout.width(45);
	cout << right << "Em Descolar:\n";
	cout << "----------------------------------------------------------------------------\n\n";
	cout << "Modelo";
	cout.width(30);
	cout << "Origem";
	cout.width(30);
	cout << "Destino\n\n";
	for (int i = 0; i < 5; i++) {
		cout.width(27);
		cout << left << temp[i].modelo;
		cout.width(27);
		cout << left << temp[i].origem;
		cout << temp[i].destino << endl;
	}
	delete[] temp;
	pausa;
}


// Opção 3 - Menu_Opções
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

// Opção 4 - Menu_Opções
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
