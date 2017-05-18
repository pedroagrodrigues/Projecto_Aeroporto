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

void new_struct(aviao &pista, aviao &aprox, aviao &desc, terminal &pass) { //RUN ONCE
	pista.end = NULL;
	pista.head = NULL;
	aprox.end = NULL;
	aprox.head = NULL;
	desc.end = NULL;
	desc.head = NULL;
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

void generate_aprox(aviao &aprox) {
	aviao::aviao_item * temp = new aviao::aviao_item();
	temp->capacidade = stoi(randomize(capacidade_file));
	temp->destino = "Aeroporto EDA";
	temp->modelo = randomize(modelo_file);
	temp->nome_voo = randomize(voo_file);
	temp->origem = randomize(origem_file);
	fill_plane(temp->passageiro, temp->capacidade);
	temp->next = NULL;
	if (aprox.end == NULL) {
		aprox.head = temp;
		aprox.end = temp;
	}
	else {
		aprox.end->next = temp;
		aprox.end = temp;
	}
}

void generate_pista(aviao & aprox, aviao & pista) {
	aviao::aviao_item * temp = new aviao::aviao_item();
	temp->capacidade = aprox.head->capacidade;
	temp->modelo = aprox.head->modelo;
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

void generate_desc(aviao &pista, aviao &desc) {
	aviao::aviao_item * temp = new aviao::aviao_item();
	temp->capacidade = pista.head->capacidade;
	temp->modelo = pista.head->modelo;
	temp->destino = pista.head->destino;
	temp->origem = pista.head->origem;
	temp->nome_voo = pista.head->nome_voo;
	temp->passageiro = pista.head->passageiro;
	temp->next = NULL;
	if (desc.end == NULL) {
		desc.head = temp;
		desc.end = temp;
	}
	else {
		desc.end->next = temp;
		desc.end = temp;
	}
}

void carregamento_inicial(aviao &pista, aviao &aprox, aviao &desc, terminal &passageiros) {
	generate_aprox(aprox);

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

void check_terminal(aviao::aviao_item * last_aprox, terminal & terminal) {
	terminal::terminal_item *temp = new terminal::terminal_item();
	temp->humman.head = last_aprox->passageiro.head;
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
	while (terminal.head != NULL) {
		if (terminal.head->turn == 1) {
			terminal.head = NULL;
			break;
		}
		else terminal.head->turn++;
	}
	terminal.head = temp;
}

void go_loop(aviao &pista, aviao &aprox, aviao &desc, terminal &pers) {
	if (queue_size(aprox) < 10) generate_aprox(aprox);
	else {
		check_terminal(aprox.head, pers);
		if (queue_size(pista) < 7) {
			generate_pista(aprox, pista);
			remover(aprox);
			generate_aprox(aprox);
		}
		else {
			generate_desc(pista, desc);
			remover(pista);
			generate_pista(aprox, pista);
			remover(aprox);
			generate_aprox(aprox);
			if (queue_size(desc) > 5) remover(desc);
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
				for (int i = selectE[0]; i > 1; i--)
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
	
	
	*/
	

