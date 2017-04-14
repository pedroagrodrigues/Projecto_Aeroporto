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
		nova[0] = to_string(current + 1);
		for (int i = 1; i <= current; i++) {
			nova[i] = temp[i-1];
		}
		delete[] temp; //Array temporário, já cumpriu a sua função, pode ser apagado para libertar o seu espaço em memória 
		return nova;
	}
	else {
		cout << "ERROR, something prevent connection to the file: " << caminho << "\n";
		return 0;
	}
}

bool is_written() {
	fstream file("txt//Estado.txt");
	if (file.is_open()) {
		file.seekg(0, file.end);
		int size = file.tellg();
		if (size == 0) {
			file.close();
			return 0;
		}
		else {
			file.close();
			return 1;
		}
	}
	else {
		cout << "ERROR, something prevent connection to the file!\n";
		return 0;
	}
	
}