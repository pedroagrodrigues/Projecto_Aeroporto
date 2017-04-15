#include "bibliotecas.h";
#include <fstream>
 
string * preencher_dados(string caminho) {
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
		string * nova = new string[current+1];
		nova[0] = to_string(current);
		for (int i = 1; i <= current; i++) {
			nova[i] = temp[i-1];
		}
		delete[] temp; //Array temporário, já cumpriu a sua função, pode ser apagado para libertar o seu espaço em memória 
		return nova;
	}
	else {
		cout << "ERROR, something prevent connection to the file: " << caminho << "\n";
		pausa;
		return 0;
	}
}

bool is_written() {
	ifstream file("estado.save", ios::beg | istream::binary);
	if (file.is_open()) {
		file.seekg(0, file.end);
		int size = file.tellg();
		if (size <= 0) {
			file.close();
			return 0;
		}
		else {
			file.close();
			return 1;
		}
	}
	else {
		return 0;
	}
	return false;
	
}

bool save(aviao pista[], aviao aprox[], aviao * desc) {
	fstream file("estado.save", ios_base::out | ios_base::binary);
	if (file.is_open()) {
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
		file << desc->capacidade << endl;
		file << desc->destino << endl;
		file << desc->modelo << endl;
		file << desc->nome_voo << endl;
		file << desc->origem << endl;
		for (int j = 0; j < desc->capacidade; j++) {
			file << desc->passageiro[j].bilhete << endl;
			file << desc->passageiro[j].nacionalidade << endl;
			file << desc->passageiro[j].primeiro_nome << endl;
			file << desc->passageiro[j].segundo_nome << endl;
		}
		file.close();
		return 1;
	}
	else return 0;
}

void load_file_state(aviao pista[], aviao aproximacao[], aviao * desc) {
	fstream file("estado.save", ios_base::in | ios_base::binary);
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
				string temp2;
				getline(file, temp2);
				pista[i].passageiro[j].bilhete = atoi(temp2.c_str());
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
				string temp2;
				getline(file, temp2);
				aproximacao[i].passageiro[j].bilhete = atoi(temp2.c_str());
				getline(file, aproximacao[i].passageiro[j].nacionalidade);
				getline(file, aproximacao[i].passageiro[j].primeiro_nome);
				getline(file, aproximacao[i].passageiro[j].segundo_nome);
			}
		}
		string temp;
		getline(file, temp);
		desc->capacidade = atoi(temp.c_str());
		getline(file, desc->destino);
		getline(file, desc->modelo);
		getline(file, desc->nome_voo);
		getline(file, desc->origem);
		desc->passageiro = new pessoa[desc->capacidade];
		for (int j = 0; j < desc->capacidade; j++) {
			string temp2;
			getline(file, temp2);
			desc->passageiro[j].bilhete = atoi(temp2.c_str());
			getline(file, desc->passageiro[j].nacionalidade);
			getline(file, desc->passageiro[j].primeiro_nome);
			getline(file, desc->passageiro[j].segundo_nome);
		}
		file.close();
	}
	else {
		cout << "ERROR, something prevent connection to the file! (load file state) \n";
		pausa;
	}

}
