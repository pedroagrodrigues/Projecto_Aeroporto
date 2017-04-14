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
			nova[i] = temp[i];
		}
		delete[] temp; //Array temporário, já cumpriu a sua função, pode ser apagado para libertar o seu espaço em memória 
		return nova;

	}
	else {
		cout << "ERROR, something prevent connection to the file!\n";
		return 0;
	}
	
	

}
