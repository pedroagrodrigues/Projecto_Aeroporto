#include "bibliotecas.h";
#include <fstream>

//Carrega Para Uma Variável Com Todas As Linhas Do Ficheiro ".txt" Recebido
string * preencher_dados(string caminho) {
	string  line, *temp = new string [500];
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
		string * nova = new string[current + 1];
		nova[0] = to_string(current);
		for (int i = 1; i <= current; i++) {
			nova[i] = temp[i - 1];
		}
		delete[] temp; //Array Temporário, Já Cumpriu a Sua Função, Pode Ser Apagado Para Libertar o Seu Espaço Em Memória 
		return nova;
	}
	else {
		cout << "ERROR, something prevent connection to the file: " << caminho << "\n";
		pausa;
		return 0;
	}
}
/*
//Verifica Se Existe Algo Escrito No Ficheiro ".save" 
bool is_written() {
	ifstream file("estado.save", ios::beg | istream::binary);
	if (file.is_open()) {
		file.seekg(0, file.end);
		if (file.tellg() <= 0) { //Verifica a Existencia De Conteúdo
			file.close();
			return 0;
		}
		else {
			file.close();
			return 1;
		}
	}
	else { //Caso Não Exista o Ficheiro
		return 0;
	}
	return false;

}

//Guarda As Variáveis No Seu Estado Actual Num Ficheiro ".save" Para Que o Programa Continue a Partir Do Último Ponto
bool save(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros) {
	fstream file("estado.save", ios::out | ofstream::binary);

	if(file.is_open()){
		for (int i = 0; i < 7; i++) {
			file << pista[i].capacidade << endl;
			file << pista[i].destino << endl;
			file << pista[i].modelo << endl;
			file << pista[i].nome_voo << endl;
			file << pista[i].origem << endl;
			for (int j = 0; j < pista[i].capacidade; j++) {
				file << pista[i].passageiro[j].bilhete << endl;
				file << pista[i].passageiro[j].nacionalidade << endl;
				file << pista[i].passageiro[j].primeiro_nome << endl;
				file << pista[i].passageiro[j].segundo_nome << endl;
			}
		}
		for (int i = 0; i < 10; i++) {
			file << aprox[i].capacidade << endl;
			file << aprox[i].destino << endl;
			file << aprox[i].modelo << endl;
			file << aprox[i].nome_voo << endl;
			file << aprox[i].origem << endl;
			for (int j = 0; j < aprox[i].capacidade; j++) {
				file << aprox[i].passageiro[j].bilhete << endl;
				file << aprox[i].passageiro[j].nacionalidade << endl;
				file << aprox[i].passageiro[j].primeiro_nome << endl;
				file << aprox[i].passageiro[j].segundo_nome << endl;
			}
		}
		for (int i = 0; i < 5; i++) {
			file << desc[i].capacidade << endl;
			file << desc[i].destino << endl;
			file << desc[i].modelo << endl;
			file << desc[i].nome_voo << endl;
			file << desc[i].origem << endl;
			for (int j = 0; j < desc[i].capacidade; j++) {
				file << desc[i].passageiro[j].bilhete << endl;
				file << desc[i].passageiro[j].nacionalidade << endl;
				file << desc[i].passageiro[j].primeiro_nome << endl;
				file << desc[i].passageiro[j].segundo_nome << endl;
			}
		}
		for (int i = 0; i < 30; i++) {
			file << passageiros[i].humman.bilhete << endl;
			file << passageiros[i].humman.nacionalidade << endl;
			file << passageiros[i].humman.primeiro_nome << endl;
			file << passageiros[i].humman.segundo_nome << endl;
			file << passageiros[i].turn << endl;
		}
		
		file.close();
		return 1;
	}
	else return 0;
}

//Carrega Do Ficheiro ".save" o Estado Que Foi Guardado Noutra Utilização
void load_file_state(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros) {
	ifstream file("estado.save", ios::in | ifstream::binary);
	if (file.is_open()) {
		for (int i = 0; i < 7; i++) {
			string temp;
			getline(file, temp);
			pista[i].capacidade = atoi(temp.c_str());
			getline(file, pista[i].destino);
			getline(file, pista[i].modelo);
			getline(file, pista[i].nome_voo);
			getline(file, pista[i].origem);
			pista[i].passageiro = new pessoa[pista[i].capacidade];
			for (int j = 0; j < pista[i].capacidade; j++) {
				string temp;
				getline(file, temp);
				pista[i].passageiro[j].bilhete = atoi(temp.c_str());
				getline(file, pista[i].passageiro[j].nacionalidade);
				getline(file, pista[i].passageiro[j].primeiro_nome);
				getline(file, pista[i].passageiro[j].segundo_nome);
			}
		}
		for (int i = 0; i < 10; i++) {
			string temp;
			getline(file, temp);
			aproximacao[i].capacidade = atoi(temp.c_str());
			getline(file, aproximacao[i].destino);
			getline(file, aproximacao[i].modelo);
			getline(file, aproximacao[i].nome_voo);
			getline(file, aproximacao[i].origem);
			aproximacao[i].passageiro = new pessoa[aproximacao[i].capacidade];
			for (int j = 0; j < aproximacao[i].capacidade; j++) {
				getline(file, temp);
				aproximacao[i].passageiro[j].bilhete = atoi(temp.c_str());
				getline(file, aproximacao[i].passageiro[j].nacionalidade);
				getline(file, aproximacao[i].passageiro[j].primeiro_nome);
				getline(file, aproximacao[i].passageiro[j].segundo_nome);
			}
		}
		
		for (int i = 0; i < 5; i++) {
			string temp;
			getline(file, temp);
			desc[i].capacidade = atoi(temp.c_str());
			getline(file, desc[i].destino);
			getline(file, desc[i].modelo);
			getline(file, desc[i].nome_voo);
			getline(file, desc[i].origem);
			desc[i].passageiro = new pessoa[desc[i].capacidade];
			for (int j = 0; j < desc[i].capacidade; j++) {
				getline(file, temp);
				desc[i].passageiro[j].bilhete = atoi(temp.c_str());
				getline(file, desc[i].passageiro[j].nacionalidade);
				getline(file, desc[i].passageiro[j].primeiro_nome);
				getline(file, desc[i].passageiro[j].segundo_nome);
			}
		}
		for (int i = 0; i < 30; i++) {
			string temp;
			getline(file, temp);
			passageiros[i].humman.bilhete=atoi(temp.c_str());
			getline(file, passageiros[i].humman.nacionalidade);
			getline(file, passageiros[i].humman.primeiro_nome);
			getline(file, passageiros[i].humman.segundo_nome);
			getline(file, temp);
			passageiros[i].turn = atoi(temp.c_str());
		}

		file.close();
	}
	else {
		cout << "ERROR, something prevent connection to the file! (load file state) \n";
		pausa;
	}

}
*/