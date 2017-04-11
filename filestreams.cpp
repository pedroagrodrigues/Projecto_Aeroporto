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
		delete[] temp; //Array tempor�rio, j� cumpriu a sua fun��o, pode ser apagado para libertar o seu espa�o em mem�ria 
		
		//verifica��o de carregamento	
		/*
		for (int i = 0; i < current; i++) {
			cout << data[i] << endl;
		}
		*/

	} else cout << "ERROR, something prevent connection to the file!\n";
		
	

}
