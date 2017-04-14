#include "bibliotecas.h"
string *destino_file, *capacidade_file, *modelo_file, *nacionalidade_file, *origem_file, *primeiro_file, *segundo_file, *voo_file;
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

void var_load_file() {
	//A POSIÇÃO ZERO DE CADA VECTOR INDICA O TAMANHO DO MESMO
	destino_file = preencher_dados("txt\\destino.txt");
	capacidade_file = preencher_dados("txt\\capacidade.txt");
	modelo_file = preencher_dados("txt\\modelo.txt");
	nacionalidade_file = preencher_dados("txt\\nacionalidade.txt");
	origem_file = preencher_dados("txt\\origem.txt");
	primeiro_file = preencher_dados("txt\\primeiro_nome.txt");
	segundo_file = preencher_dados("txt\\segundo_nome.txt");
	voo_file = preencher_dados("txt\\voo.txt");

	//confirmação de carregamento
	/*
	for (int i = 1; i < stoi(origem_file[0]); i++) {
		cout << origem_file[i] << endl;
	}*/
	
}
string randomize(string * data) {

	return "2";
}

void carregamento_vectores(aviao * pista, aviao * aproximacao, aviao * descolar) {
	for (int i = 0; i < 10; i++) {
		aproximacao[i].capacidade = stoi(randomize(capacidade_file));
	}


}
