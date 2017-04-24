#include "bibliotecas.h"
string *destino_file, *capacidade_file, *modelo_file, *nacionalidade_file, *origem_file, *primeiro_file, *segundo_file, *voo_file;


void var_load_file() {
	//A POSIÇÃO ZERO DE CADA VECTOR CONTÉM O TAMANHO DO MESMO
	destino_file = preencher_dados("txt\\destino.txt");
	capacidade_file = preencher_dados("txt\\capacidade.txt");
	modelo_file = preencher_dados("txt\\modelo.txt");
	nacionalidade_file = preencher_dados("txt\\nacionalidade.txt");
	origem_file = preencher_dados("txt\\origem.txt");
	primeiro_file = preencher_dados("txt\\primeiro_nome.txt");
	segundo_file = preencher_dados("txt\\segundo_nome.txt");
	voo_file = preencher_dados("txt\\voo.txt");
}

//Devolve o Conteudo De Uma Linha Seleccionada ao Acaso.
string randomize(string * data) {
	int line = (rand() % stoi(data[0])) + 1;
	return data[line];
}
//Gera Um Numero Para o Bilhete de Voo(falta fazer a verificação se o numero já existe)
int generate_ticket() {
	int ticket_number;
	ticket_number = rand() % 1000000000 + 9999999999;
	return ticket_number;
}
//Carrega o Estado Dopprograma Se Tiver Algo Guardado
void primeiro_carregamento_vectores(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros) {
	if (is_written()) {
		load_file_state(pista, aproximacao, desc, passageiros);
	}
	else {
		for (int i = 0; i < 10; i++) {
			aproximacao[i].nome_voo = randomize(voo_file);
			aproximacao[i].origem = randomize(origem_file);
			aproximacao[i].destino = "Aeroporto EDA";
			aproximacao[i].modelo = randomize(modelo_file);
			aproximacao[i].capacidade = stoi(randomize(capacidade_file));
			aproximacao[i].passageiro = new pessoa[aproximacao[i].capacidade];
			for (int j = 0; j < aproximacao[i].capacidade; j++) {
				aproximacao[i].passageiro[j].bilhete = generate_ticket();
				aproximacao[i].passageiro[j].nacionalidade = randomize(nacionalidade_file);
				aproximacao[i].passageiro[j].primeiro_nome = randomize(primeiro_file);
				aproximacao[i].passageiro[j].segundo_nome = randomize(segundo_file);
			}
		}
		for (int i = 0; i < 7; i++) {
			pista[i].nome_voo = randomize(voo_file);
			pista[i].origem = "Aeroporto EDA";
			pista[i].destino = randomize(destino_file);
			pista[i].modelo = randomize(modelo_file);
			pista[i].capacidade = stoi(randomize(capacidade_file));
			pista[i].passageiro = new pessoa[pista[i].capacidade];
			for (int j = 0; j < pista[i].capacidade; j++) {
				pista[i].passageiro[j].bilhete = generate_ticket();
				pista[i].passageiro[j].nacionalidade = randomize(nacionalidade_file);
				pista[i].passageiro[j].primeiro_nome = randomize(primeiro_file);
				pista[i].passageiro[j].segundo_nome = randomize(segundo_file);
			}
		}
		for (int i = 0; i < 5; i++) {
			desc[i].nome_voo = randomize(voo_file);
			desc[i].origem = "Aeroporto EDA";
			desc[i].destino = randomize(destino_file);
			desc[i].modelo = randomize(modelo_file);
			desc[i].capacidade = stoi(randomize(capacidade_file));
			desc[i].passageiro = new pessoa[desc[i].capacidade];
			for (int j = 0; j < desc[i].capacidade; j++) {
				desc[i].passageiro[j].bilhete = generate_ticket();
				desc[i].passageiro[j].nacionalidade = randomize(nacionalidade_file);
				desc[i].passageiro[j].primeiro_nome = randomize(primeiro_file);
				desc[i].passageiro[j].segundo_nome = randomize(segundo_file);
			}
		}
	}
}
//Cria os Novos Elementos Do Novo Avião Na Pista
void pista_6(aviao pista[], aviao aprox[]) {
	pista[6].modelo = aprox[0].modelo;
	pista[6].capacidade = aprox[0].capacidade;
	pista[6].origem = "Aeroporto EDA";
	pista[6].destino = randomize(destino_file);
	pista[6].nome_voo = randomize(voo_file);
	pista[6].passageiro = new pessoa[pista[6].capacidade];
	for (int j = 0; j < pista[6].capacidade; j++) {
		pista[6].passageiro[j].bilhete = generate_ticket();
		pista[6].passageiro[j].nacionalidade = randomize(nacionalidade_file);
		pista[6].passageiro[j].primeiro_nome = randomize(primeiro_file);
		pista[6].passageiro[j].segundo_nome = randomize(segundo_file);
	}

}
//Cria um Novo Avião Para a Aproximação
void aprox_9(aviao aprox[]) {
	aprox[9].nome_voo = randomize(voo_file);
	aprox[9].origem = randomize(origem_file);
	aprox[9].destino = "Aeroporto EDA";
	aprox[9].modelo = randomize(modelo_file);
	aprox[9].capacidade = stoi(randomize(capacidade_file));
	aprox[9].passageiro = new pessoa[aprox[9].capacidade];
	for (int j = 0; j < aprox[9].capacidade; j++) {
		aprox[9].passageiro[j].bilhete = generate_ticket();
		aprox[9].passageiro[j].nacionalidade = randomize(nacionalidade_file);
		aprox[9].passageiro[j].primeiro_nome = randomize(primeiro_file);
		aprox[9].passageiro[j].segundo_nome = randomize(segundo_file);
	}

}
//Verifica o Estado Do Terminal, Limpa as Pessoas Que Estão há Dois Turnos
void check_terminal(aviao aprox, terminal * ppl) {
	for (int i = 0; i < 30; i++) {
		if (ppl[i].turn == 1) ppl[i] = { NULL };
		else if (ppl[i].turn == 0) ppl[i].turn++;
	}
	for (int i = 0; i < aprox.capacidade; i++) {
		for (int j = 0; j < 30; j++) {
			if (ppl[j].turn == -1) {
				ppl[j].humman.bilhete = aprox.passageiro[i].bilhete;
				ppl[j].humman.nacionalidade = aprox.passageiro[i].nacionalidade;
				ppl[j].humman.primeiro_nome = aprox.passageiro[i].primeiro_nome;
				ppl[j].humman.segundo_nome = aprox.passageiro[i].segundo_nome;
				ppl[j].turn = 0;
				break;
			}
		}	
	}
	
}
//Gera um Novo Ciclo
void go_loop(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros) {
	for (int i = 0; i < 4; i++)	desc[i] = desc[i + 1];
	desc[4] = pista[0];
	for (int i = 0; i < 6; i++) {
		pista[i] = pista[i + 1];
	}
	check_terminal(aprox[0], passageiros);
	pista_6(pista, aprox);

	for (int i = 0; i < 9; i++) {
		aprox[i] = aprox[i + 1];
	}
	aprox_9(aprox);
}

