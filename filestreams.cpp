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

//Verifica Se Existe Algo Escrito No Ficheiro ".save" 
bool is_written(string path) {
	ifstream file(path, ios::beg | istream::binary);
	if (file.is_open()) {
		file.seekg(0, file.end);
		if (file.tellg() <= 0) { //Verifica a Existencia De Conteúdo
			file.close();
			return false;
		}
		else {
			file.close();
			return true;
		}
	}
	return false;

}
int queue_size(aviao::aviao_item *queue) {
	aviao::aviao_item * temp = queue;
	int current = 0;
	while (temp != NULL) {
		temp = temp->next;
		current++;
	}
	delete temp;
	return current;
}


//Guarda As Variáveis No Seu Estado Actual Num Ficheiro ".save" Para Que o Programa Continue a Partir Do Último Ponto
bool save(aviao &pista, aviao &aproximacao, aviao &descolar, terminal &pass, string path) {
	fstream file("estado.bin", ios::out | ofstream::binary);
	if (file.is_open()) {
		aviao::aviao_item *temp = aproximacao.head;
		pessoa::pessoa_item *temp_person = new pessoa::pessoa_item();
		int current = 0;
		while (current < 3){
			file << queue_size(temp) << endl;
			while (temp != NULL) {
				file << temp->capacidade << endl;
				file << temp->destino << endl;
				file << temp->modelo << endl;
				file << temp->nome_voo << endl;
				file << temp->origem << endl;
				temp_person = temp->passageiro.head;
				while (temp_person != NULL) {
					file << temp_person->bilhete << endl;
					file << temp_person->nacionalidade << endl;
					file << temp_person->primeiro_nome << endl;
					file << temp_person->segundo_nome << endl;
					temp_person = temp_person->next;
				}
				temp = temp->next;
			}
			current++;
			(current == 1) ? temp = pista.head : temp = descolar.head;
			
		}
		file.close();
		return 1;
	}
	else return 0;
	
	
}

//Carrega Do Ficheiro ".save" o Estado Que Foi Guardado Noutra Utilização
void load_file_state(aviao &pista, aviao &aproximacao, aviao &descolar, terminal &pass, string path) {
	fstream file(path, ios::in | ifstream::binary);
	if (file.is_open()) {
		string line;
		aviao::aviao_item * temp;
		pessoa::pessoa_item * temp_person;
		int current=0, aux;
		//while (current < 3) {
		getline(file, line);
		aux = stoi(line);
		//temp->destino = "teste";
		for (int i = 0; i < aux; i++) {
			temp = new aviao::aviao_item();
			getline(file, line);
			temp->capacidade = atoi(line.c_str());
			getline(file, temp->destino);
			getline(file, temp->modelo);
			getline(file, temp->nome_voo);
			getline(file, temp->origem);
			for (int j = 0; j < temp->capacidade; j++) {
				temp_person = new pessoa::pessoa_item();
				getline(file, line);
				temp_person->bilhete = stoi(line);
				getline(file, temp_person->nacionalidade);
				getline(file, temp_person->primeiro_nome);
				getline(file, temp_person->segundo_nome);
				temp_person->next = NULL;

				if (temp->passageiro.end == NULL) {
					temp->passageiro.head = temp_person;
					temp->passageiro.end = temp_person;
				}
				else {
					temp->passageiro.end->next = temp_person;
					temp->passageiro.end = temp_person;
				}
			}
			temp->next = NULL;
			if (aproximacao.end == NULL) {
				aproximacao.head = temp;
				aproximacao.end = temp;
			}
			else {
				aproximacao.end->next = temp;
				aproximacao.end = temp;
			}
		}
		getline(file, line);
		aux = stoi(line);
		for (int i = 0; i < aux; i++) {
			temp = new aviao::aviao_item();
			getline(file, line);
			temp->capacidade = atoi(line.c_str());
			getline(file, temp->destino);
			getline(file, temp->modelo);
			getline(file, temp->nome_voo);
			getline(file, temp->origem);
			for (int j = 0; j < temp->capacidade; j++) {
				temp_person = new pessoa::pessoa_item();
				getline(file, line);
				temp_person->bilhete = stoi(line);
				getline(file, temp_person->nacionalidade);
				getline(file, temp_person->primeiro_nome);
				getline(file, temp_person->segundo_nome);
				temp_person->next = NULL;

				if (temp->passageiro.end == NULL) {
					temp->passageiro.head = temp_person;
					temp->passageiro.end = temp_person;
				}
				else {
					temp->passageiro.end->next = temp_person;
					temp->passageiro.end = temp_person;
				}
			}
			temp->next = NULL;
			if (pista.end == NULL) {
				pista.head = temp;
				pista.end = temp;
			}
			else {
				pista.end->next = temp;
				pista.end = temp;
			}
		}
		getline(file, line);
		aux = stoi(line);
		for (int i = 0; i < aux; i++) {
			temp = new aviao::aviao_item();
			getline(file, line);
			temp->capacidade = atoi(line.c_str());
			getline(file, temp->destino);
			getline(file, temp->modelo);
			getline(file, temp->nome_voo);
			getline(file, temp->origem);
			for (int j = 0; j < temp->capacidade; j++) {
				temp_person = new pessoa::pessoa_item();
				getline(file, line);
				temp_person->bilhete = stoi(line);
				getline(file, temp_person->nacionalidade);
				getline(file, temp_person->primeiro_nome);
				getline(file, temp_person->segundo_nome);
				temp_person->next = NULL;

				if (temp->passageiro.end == NULL) {
					temp->passageiro.head = temp_person;
					temp->passageiro.end = temp_person;
				}
				else {
					temp->passageiro.end->next = temp_person;
					temp->passageiro.end = temp_person;
				}
			}
			temp->next = NULL;
			if (descolar.end == NULL) {
				descolar.head = temp;
				descolar.end = temp;
			}
			else {
				descolar.end->next = temp;
				descolar.end = temp;
			}
		}
		file.close();
	}
}
