#include "bibliotecas.h";
#include <fstream>
void preencher_dados(string * data, string caminho) {
	string  line, * temp = new string[500];
	fstream file(caminho);
	int current = 0;
	if (file.is_open()) {
		while (getline(file, line)) {
			if (line != "") {
				temp[current] = line;
				current++;
			}
		}
		file.close();

		data = new string[current];
		for (int i = 0; i < current; i++) {
			data[i] = temp[i];
		}
		delete[] temp; //Array temporário, já cumpriu a sua função, pode ser apagado para libertar o seu espaço em memória 
		
		//verificação de carregamento	
		/*
		for (int i = 0; i < current; i++) {
			cout << data[i] << endl;
		}
		*/

	} else cout << "ERROR, something prevent connection to the file!\n";
		
	

}
void var_load() {
	string *destino_file = 0, *capacidade_file = 0, *modelo_file = 0, *nacionalidade_file = 0, *origem_file = 0, *primeiro_file = 0, *segundo_file = 0, *voo_file = 0;
	preencher_dados(destino_file, "txt\\destino.txt");
	preencher_dados(capacidade_file, "txt\\capacidade.txt");
	preencher_dados(modelo_file, "txt\\modelo.txt");
	preencher_dados(nacionalidade_file, "txt\\nacionalidade.txt");
	preencher_dados(origem_file, "txt\\origem.txt");
	preencher_dados(primeiro_file, "txt\\primeiro_nome.txt");
	preencher_dados(segundo_file, "txt\\segundo_nome.txt");
	preencher_dados(voo_file, "txt\\voo.txt");

}
