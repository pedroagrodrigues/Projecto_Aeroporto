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

int emergency_select(aviao * select, int size) {
	limpar;
	int opt;
	cout << "\n------------------------------------------------------------------------------------\n";
	cout.width(50);
	cout << right << "Selecione o Voo\n";
	cout << "------------------------------------------------------------------------------------\n\n";
	cout.width(5);
	cout << left << "Nº";
	cout.width(27);
	cout << left << "Nome do Voo";
	cout.width(27);
	cout << left << "Modelo";
	cout << "Origem\n\n";
	for (int i = 0; i < size; i++) {
		cout.width(5);
		cout << left << i + 1;
		cout.width(27);
		cout << left << select[i].nome_voo;
		cout.width(27);
		cout << left << select[i].modelo;
		cout << left << select[i].origem << endl;
	}
	while (1) {
		while (!(cin >> opt))
		{
			cin.clear(); //Previne loop na introdução de cratéres não numéricos
			while (cin.get() != '\n') continue;
			cout << "ERRO opção inválida\n";
		}

		if (opt > 0 && opt <= size) {
			limpar;
			return --opt;
		}
		else {
			cout << "ERRO opção inválida\n";
			
		}
	}
	
}

//EMERGÊNCIA!
int emergencia(aviao * pista, aviao * aproximacao, aviao * descolagem) {
	limpar;
	string selecao[2];
	int selectE[2] = { -1, -1 };
	while (1) {
		cout << selecao[0];
		cout << selecao[1];
		cout << "\n----------------------------------------------------------------------------\n";
		cout.width(55);
		cout << right << "Entrou no modo de Emergência!\n";
		cout << "----------------------------------------------------------------------------\n\n";
		cout << "1 - Selecione o Voo em Emergência.\n";
		cout << "2 - Selecione o Voo a Descolar. \n";
		cout << "c - Confirma a Seleção.\n";
		cout << "0 - Cancelar.\n";
		switch (_getch()) {
		case '1'://Sub Seleção para aterragem
			selectE[0] = emergency_select(aproximacao, 10);
			selecao[0] = "\t Selecionou Voo a Aterrar: " + aproximacao[selectE[0]].nome_voo + "\t  Modelo: " + aproximacao[selectE[0]].modelo + "\n";
			break;
		case '2'://Submenu Seleção para Descolar
			selectE[1] = emergency_select(pista, 7);
			selecao[1] = "\t Selecionou Voo a Descolar: " + pista[selectE[1]].nome_voo + "\t  Modelo: " + pista[selectE[1]].modelo + "\n";
			break;
		case 'c':
			cout << endl;
			if (selectE[0] != -1 && selectE[1] != -1) {
				//Aprox
				aproximacao[0] = aproximacao[selectE[0]];
				aproximacao[0].nome_voo += "-----EM EMÊRGENCIA!";
				for (int i = selectE[0]; i > 2; i--)
					aproximacao[i] = aproximacao[i - 1];
				//Descolagem
				pista[0] = pista[selectE[1]];
				for (int i = selectE[1]; i > 1; i--)
					pista[i] = pista[i - 1];
				return 0;
			}
			else if (selectE[0] != -1 && selectE[1] == -1)	
				cout << "Faltou seleccionar um avião a levantar.\n";
			else if (selectE[0] == -1 && selectE[1] != -1)
				cout << "Faltou seleccionar um avião a aterrar.\n";
			else cout << "Não foram selecionados aviões.\n";
			cout << endl;
			pausa;
			limpar;
			break;
		case '0':
			limpar;
			return 0;
			break;
		default:
			limpar;
			cout << "Essa opção não é válida\n";
			break;
		}
	}

}
	
	
	
	

