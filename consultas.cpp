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
	for (int i = 0; i < stoi(origem_file[0]); i++) {
		cout << i << origem_file[i] << endl;
	}
	*/
}
string randomize(string * data) {
	int line = rand() % (stoi(data[0])) + 1;
	return data[line];
}

int rand_capacidade(string *data) {
	int line = rand() % (stoi(data[0])) + 1;
	int capacidade = stoi(data[line]);
	return capacidade;
}
aviao generate_aprox() {
	aviao data;
	data.nome_voo = randomize(voo_file);
	data.origem = randomize(origem_file);
	data.destino = "Aeroporto EDA"; 
	data.modelo = randomize(modelo_file);
	data.capacidade = rand_capacidade(capacidade_file);
	return data;
}

//O programa quebra nesta função
void carregamento_vectores(aviao pista[], aviao aproximacao[], aviao descolar) {
	for (int i = 0; i < 1; i++) {
		aproximacao[i] = generate_aprox();
			
		}
}

