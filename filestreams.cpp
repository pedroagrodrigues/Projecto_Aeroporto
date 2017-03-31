#include "bibliotecas.h";
#include <fstream>
void var_load() {
	string * destinos, line, * temp = new string[500];
	ifstream file("txt\\destino.txt");
	int current = 0;
	if (file.is_open()) {
		while (getline(file, line)) {
			if (line != "") {
				temp[current] = line;
				current++;
			}
		}
		file.close();

		destinos = new string[current];
		for (int i = 0; i < current; i++) {
			destinos[i] = temp[i];
		}
		delete[] temp; //Array temporário, já cumpriu a sua função, pode ser apagado para libertar o seu espaço em memória 
		
		//verificação de carregamento			   
		for (int i = 0; i < current; i++) {
			cout << destinos[i] << endl;
		}


	} else cout << "ERROR, something prevent connection to the file!\n";
		
	

}
/*
void preencher_dados(aviao a[], int size) {
	for (int i = 0; i < size; i++) {
		a[i].nome_voo = random("voo.txt");
		a[i].destino = random("destino.txt");
		a[i].modelo = random("modelo.txt");
		a[i].origem = random("origem.txt");
		a[i].capacidade = (rand() % (15 - 5)) + 5;
		/*a.passageiro.bi=14047585;
		a.passageiro.nacionalidade=random("nacionalidade.txt");
		a.passageiro.primeiro_nome=random("primeiro_nome.txt");
		a.passageiro.segundo_nome=random("segundo_nome.txt");
		}
		}*/