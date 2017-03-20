#include "bibliotecas.h"

string random(string nome) {
	nome = "txt\\" + nome;
	inicio:
	int random = rand() % 50;
	string linha;
	ifstream file(nome);
	if (file.is_open()) {
		for (int i = 0; i <= random; i++) {
			getline(file, linha);
			if (linha == "") goto inicio;
		}
		return linha;
	}
	else return "erro";

}
/* Erros conhecidos: 
quando o valor random pertence à primeira linha aparece lixo antes do nome obtido
*/

void preencher_dados(aviao a[], int size) {
	for (int i = 0; i < size; i++) {
		a[i].nome_voo = random("voo.txt");
		a[i].destino = random("destino.txt");
		a[i].modelo = random("modelo.txt");
		a[i].origem = random("origem.txt");
		a[i].capacidade = (rand() % (15 - 5)) + 5;
		/*a.passageiro.bi=14047585;
		a.passageiro.nacionalidade=random("nacionalidade.txt");
		a.passageiro.primeiro_nome=random("primeiro_nome.txt");
		a.passageiro.segundo_nome=random("segundo_nome.txt");*/
	}
}