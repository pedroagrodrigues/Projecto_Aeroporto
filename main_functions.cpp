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

long generate_ticket() {
	long ticket_number;
	ticket_number = rand() % 1000000000 + 9999999999;
	return ticket_number;
}

void new_struct(aviao &pista, aviao &aproximacao, aviao &descolar, terminal &pass) { //RUN ONCE
	pista.end = NULL;
	pista.head = NULL;
	aproximacao.end = NULL;
	aproximacao.head = NULL;
	descolar.end = NULL;
	descolar.head = NULL;
	pass.head = NULL;
	pass.end = NULL;
}

pessoa::pessoa_item * generate_person() {
	pessoa::pessoa_item * person = new pessoa::pessoa_item();
	person->bilhete = generate_ticket();
	person->nacionalidade = randomize(nacionalidade_file);
	person->primeiro_nome = randomize(primeiro_file);
	person->segundo_nome = randomize(segundo_file);
	person->next = NULL;
	return person;
}

void fill_plane(pessoa & list, int size) {
	pessoa::pessoa_item * temp = new pessoa::pessoa_item();
	for (int i = 0; i < size; i++) {
		temp = generate_person();
		if (list.end == NULL) {
			list.head = temp;
			list.end = temp;
		}
		else {
			list.end->next = temp;
			list.end = temp;
		}
	}

}

void generate_aproximacao(aviao &aproximacao) {
	aviao::aviao_item * temp = new aviao::aviao_item();
	temp->capacidade = stoi(randomize(capacidade_file));
	temp->destino = "Aeroporto EDA";
	temp->modelo = randomize(modelo_file);
	temp->nome_voo = randomize(voo_file);
	temp->origem = randomize(origem_file);
	fill_plane(temp->passageiro, temp->capacidade);
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

void generate_pista(aviao & aproximacao, aviao & pista) {
	aviao::aviao_item * temp = new aviao::aviao_item();
	temp->capacidade = aproximacao.head->capacidade;
	temp->modelo = aproximacao.head->modelo;
	temp->destino = randomize(destino_file);
	temp->origem = "Aeroporto EDA";
	temp->nome_voo = randomize(voo_file);
	fill_plane(temp->passageiro, temp->capacidade);
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

void generate_descolar(aviao &pista, aviao &descolar) {
	aviao::aviao_item * temp = new aviao::aviao_item();
	temp->capacidade = pista.head->capacidade;
	temp->modelo = pista.head->modelo;
	temp->destino = pista.head->destino;
	temp->origem = pista.head->origem;
	temp->nome_voo = pista.head->nome_voo;
	temp->passageiro = pista.head->passageiro;
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

void carregamento_inicial(aviao &pista, aviao &aproximacao, aviao &descolar, terminal &passageiros, string path) {
	if (is_written(path)) {
		load_file_state(pista, aproximacao, descolar, passageiros, path);
	}
	generate_aproximacao(aproximacao);

}

int queue_size(aviao &queue) {
	aviao::aviao_item * temp = queue.head;
	int current = 0;
	while (temp != NULL) {
		temp = temp->next;
		current++;
	}
	delete temp;
	return current;
}

void remover(aviao & to_rem) {
	to_rem.head = to_rem.head->next;
}

void check_terminal(aviao::aviao_item * last_aproximacao, terminal & terminal) {
	terminal::terminal_item *temp = new terminal::terminal_item();
	temp->humman.head = last_aproximacao->passageiro.head;
	temp->next = NULL;
	temp->turn = -1;
	if (terminal.end == NULL) {
		terminal.head = temp;
		terminal.end = temp;
	}
	else {
		terminal.end->next = temp;
		terminal.end = temp;
	}

	temp = terminal.head;
	while (temp!= NULL) {
		if (temp->turn == 1) {
			terminal.head = terminal.head->next;
		}
		else temp->turn++;
		temp = temp->next;
	}

}

void go_loop(aviao &pista, aviao &aproximacao, aviao &descolar, terminal &pers) {
	if (queue_size(aproximacao) < 10) generate_aproximacao(aproximacao);
	else {
		check_terminal(aproximacao.head, pers);
		if (queue_size(pista) < 2) {
			generate_pista(aproximacao, pista);
			remover(aproximacao);
			generate_aproximacao(aproximacao);
		}
		else {
			generate_descolar(pista, descolar);
			remover(pista);
			generate_pista(aproximacao, pista);
			remover(aproximacao);
			generate_aproximacao(aproximacao);
			if (queue_size(descolar) > 5) remover(descolar);
		}
	}
}
/*
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
int emergencia(aviao * pista, aviao * aproximacaoimacao, aviao * descolarolagem) {
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
		cout << "2 - Selecione o Voo a descolarolar. \n";
		cout << "c - Confirma a Seleção.\n";
		cout << "0 - Cancelar.\n";
		switch (_getch()) {
		case '1'://Sub Seleção para aterragem
			selectE[0] = emergency_select(aproximacaoimacao, 10);
			selecao[0] = "\t Selecionou Voo a Aterrar: " + aproximacaoimacao[selectE[0]].nome_voo + "\t  Modelo: " + aproximacaoimacao[selectE[0]].modelo + "\n";
			break;
		case '2'://Submenu Seleção para descolarolar
			selectE[1] = emergency_select(pista, 7);
			selecao[1] = "\t Selecionou Voo a descolarolar: " + pista[selectE[1]].nome_voo + "\t  Modelo: " + pista[selectE[1]].modelo + "\n";
			break;
		case 'c':
			cout << endl;
			if (selectE[0] != -1 && selectE[1] != -1) {
				//aproximacao
				aproximacaoimacao[0] = aproximacaoimacao[selectE[0]];
				aproximacaoimacao[0].nome_voo += "-----EM EMÊRGENCIA!";
				for (int i = selectE[0]; i > 1; i--)
					aproximacaoimacao[i] = aproximacaoimacao[i - 1];
				//descolarolagem
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
	
	
	*/
	

