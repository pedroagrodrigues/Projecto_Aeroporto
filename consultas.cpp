#include "bibliotecas.h"
/*
string random(string nome) {
	nome = "txt\\" + nome;
	inicio:
	int random = rand() % 50;
	string linha; // para sair daqui
	ifstream file(nome);

	if (file.is_open()) {
		file.seekg(0, ios::beg);
		for (int i = 0; i <= random; i++) {
			getline(file, linha);

			if (linha == "") goto inicio; //para sair daqui
		}

		file.close();
		return linha;
		
	}
	else return "erro";

}
/* Erros conhecidos: 
quando o valor random pertence à primeira linha aparece lixo antes do nome obtido
*/

void var_load() {
	string *destino_file=0, *capacidade_file = 0, *modelo_file = 0, *nacionalidade_file = 0, *origem_file = 0, *primeiro_file = 0, *segundo_file = 0, *voo_file = 0;
	preencher_dados(destino_file, "txt\\destino.txt");
	preencher_dados(capacidade_file, "txt\\capacidade.txt");
	preencher_dados(modelo_file, "txt\\modelo.txt");
	preencher_dados(nacionalidade_file, "txt\\nacionalidade.txt");
	preencher_dados(origem_file, "txt\\origem.txt");
	preencher_dados(primeiro_file, "txt\\primeiro_nome.txt");
	preencher_dados(segundo_file, "txt\\segundo_nome.txt");
	preencher_dados(voo_file, "txt\\voo.txt");

}
