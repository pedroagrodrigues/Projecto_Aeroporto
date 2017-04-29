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

// Cria um Novo Avião Para a Aproximação
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

//Carrega o Estado Dopprograma Se Tiver Algo Guardado
void primeiro_carregamento_vectores(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros) {
	if (is_written()) load_file_state(pista, aproximacao, desc, passageiros);
	else aprox_9(aproximacao);
}

//Cria os Novos Elementos Do Novo Avião Na Pista
void pista_6(aviao pista[], aviao aprox[]) {
	pista[6].modelo = aprox[0].modelo;
	pista[6].capacidade = aprox[0].capacidade;
	pista[6].origem = "Aeroporto EDA";
	pista[6].destino = randomize(destino_file);
	pista[6].nome_voo = randomize(voo_file);
	//if (pista[6].capacidade > 0) {
	pista[6].passageiro = new pessoa[pista[6].capacidade];
	for (int j = 0; j < pista[6].capacidade; j++) {
		pista[6].passageiro[j].bilhete = generate_ticket();
		pista[6].passageiro[j].nacionalidade = randomize(nacionalidade_file);
		pista[6].passageiro[j].primeiro_nome = randomize(primeiro_file);
		pista[6].passageiro[j].segundo_nome = randomize(segundo_file);
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
	if (aprox[0].capacidade != 0)
		pista_6(pista, aprox);

	for (int i = 0; i < 9; i++) {
		aprox[i] = aprox[i + 1];
	}
	aprox_9(aprox);
}

//EMERGÊNCIA!
void emergencia(aviao * pista, aviao * aproximacao, aviao * descolagem) {
	limpar;
    
	cout << "\nEntrou no Modo Emergência.\n";
	cout << "-------------------------------------------------------\n";
	cout << "\nSelecione o Voo Em Situação De Emergência!\n";
	for (int i = 0; i < 10; i++)
		cout << "\n" << i + 1 << " - Voo: " << aproximacao[i].nome_voo << "\n  " << " - Modelo: " << aproximacao[i].modelo << "\n  " << " - Origem: " << aproximacao[i].origem << endl;

	//variável de seleção
	int n;
	cin >> n;
    n--;
	cout << "\t Selecionou Voo: " << aproximacao[n].nome_voo << "\t  Modelo: " << aproximacao[n].modelo << endl;
	aproximacao[0] = aproximacao[n];
	aproximacao[0].nome_voo += "-----EM EMÊRGENCIA!";
	for (int i = n; i > 1; i--)
		aproximacao[i] = aproximacao[i - 1];
	//Descolagem
	cout << "\nSelecione o Voo a Descolar\n";
	for (int i = 0; i < 7; i++)
		cout << "\n" << i + 1 << " - Voo: " << pista[i].nome_voo << "\n  " << " - Modelo: " << pista[i].modelo << "\n  " << " - Origem: " << pista[i].origem << endl;
	//variável de seleção
	cin >> n;
	n--;
	//aviao temp = aproximacao[h - 1];
	pista[0] = pista[n];

	for (int i = n; i > 1; i--)
		pista[i] = pista[i - 1];
}

