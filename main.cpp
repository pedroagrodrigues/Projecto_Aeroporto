#include "bibliotecas.h"

//EXEMPPLO DE APRESENTAÇÃO
/*
cout << "-----------terminal---------\n";
terminal::terminal_item *temp = passageiros.head;
pessoa::pessoa_item *temp2 = new pessoa::pessoa_item();
while (temp != NULL) {
temp2 = temp->humman.head;
while (temp2 != NULL) {
cout << temp2->primeiro_nome << endl;
temp2 = temp2->next;

}
cout << temp->turn << endl;
temp = temp->next;
}*/

int main() {
	//cout << path << endl;
	string path = "estado.bin";
	setlocale(LC_ALL, "Portuguese"); //Faz a consola aceitar caracteres especiais.
	var_load_file();//Carrega os ficheiros para mem�ria
	aviao pista, aproximacao, descolar;
	terminal passageiros;
	new_struct(pista, aproximacao, descolar, passageiros);
	carregamento_inicial(pista, aproximacao, descolar, passageiros, path);

	
	while (1) {
		limpar;
		cout << "-----------terminal---------\n";
		terminal::terminal_item *temp = passageiros.head;
		pessoa::pessoa_item *temp2 = new pessoa::pessoa_item();
		while (temp != NULL) {
			temp2 = temp->humman.head;
			while (temp2 != NULL) {
				cout << temp2->primeiro_nome << endl;
				temp2 = temp2->next;

			}
			cout << temp->turn << endl;
			temp = temp->next;
		}
		/*
		limpar;
		cout << "(e)mergências (o)pções (g)ravar\t\t 0 - Sair\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------------------\n";
		cout.width(75);
		cout << right << "Em Aproximação:\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "Voo";
		cout.width(22);
		cout << "Modelo";
		cout.width(23);
		cout << "Origem";
		cout.width(25);
		cout << "Destino";
		cout.width(35);
		cout << "Passageiros \n";
		
		aviao::aviao_item *temp = aproximacao.head;
		pessoa::pessoa_item * temp_2 = new pessoa::pessoa_item();
		while (temp != NULL) {
			cout.width(18);
			cout << left << temp->nome_voo;
			cout.width(20);
			cout << left << temp->modelo;
			cout.width(27);
			cout << left << temp->origem;
			cout.width(27);
			cout << left << temp->destino;
			temp_2 = temp->passageiro.head;
			for (int i = 0; i <= 4 && i < temp->capacidade && temp_2 != NULL; i++) {
				cout << temp_2->segundo_nome << ", ";
				temp_2 = temp_2->next;
			}
			if (temp->capacidade > 4) cout << "..."; //Comparação para o caso de adicionarem uma capacidade de 4 ao ficheiro "capacidade.txt"
			else if (temp->capacidade > 0) cout << ".";
			else cout << endl;
			cout << "\n";
			temp = temp->next;			
		}
	
		cout << "\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------------------\n";
		cout.width(70);
		cout << right << "Na Pista:\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "Voo";
		cout.width(22);
		cout << "Modelo";
		cout.width(23);
		cout << "Origem";
		cout.width(25);
		cout << "Destino";
		cout.width(35);
		cout << "Passageiros \n";

		temp = pista.head;
		while (temp != NULL) {
			cout.width(18);
			cout << left << temp->nome_voo;
			cout.width(20);
			cout << left << temp->modelo;
			cout.width(27);
			cout << left << temp->origem;
			cout.width(27);
			cout << left << temp->destino;
			temp_2 = temp->passageiro.head;
			for (int i = 0; i <= 4 && i < temp->capacidade && temp_2 != NULL; i++) {
				cout << temp_2->segundo_nome << ", ";
				temp_2 = temp_2->next;
			}
			if (temp->capacidade > 4) cout << "..."; //Comparação para o caso de adicionarem uma capacidade de 4 ao ficheiro "capacidade.txt"
			else if (temp->capacidade > 0) cout << ".";
			else cout << endl;
			cout << "\n";
			temp = temp->next;			
		}
	
		cout << "\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------------------\n";
		cout.width(72);
		cout << right << "A Descolar:\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "Voo";
		cout.width(22);
		cout << "Modelo";
		cout.width(23);
		cout << "Origem";
		cout.width(25);
		cout << "Destino";
		cout.width(35);
		cout << "Passageiros \n";

		temp = descolar.head;
		while (temp != NULL) {
			cout.width(18);
			cout << left << temp->nome_voo;
			cout.width(20);
			cout << left << temp->modelo;
			cout.width(27);
			cout << left << temp->origem;
			cout.width(27);
			cout << left << temp->destino;
			temp_2 = temp->passageiro.head;
			for (int i = 0; i <= 4 && i < temp->capacidade && temp_2 != NULL; i++) {
				cout << temp_2->segundo_nome << ", ";
				temp_2 = temp_2->next;
			}
			if (temp->capacidade > 4) cout << "..."; //Comparação para o caso de adicionarem uma capacidade de 4 ao ficheiro "capacidade.txt"
			else if (temp->capacidade > 0) cout << ".";
			else cout << endl;
			cout << "\n";
			temp = temp->next;			
		}
	
		delete temp_2;
		delete temp;
		cout << endl;
		*/
		//-------------Switch Case-------------
		switch (_getch()) {
		case 'e':
			/*cout << emergencia(pista, aproximacao, descolar); // Função de Emergência
			break;*/
		case 'o':
			opcoes(pista, aproximacao, descolar, passageiros); // Função Para Entrada Principal Menu_Opções
			break;

		case 'g':
			limpar;
			cout << "Escolheu a Opção Gravar.\n";
			if (save(pista, aproximacao, descolar, passageiros, path))
				cout << "Os Seus Documentos Foram Salvos.\n";
			else cout << "Erro. Falha ao Gravar!\n";
			pausa;
			break;
		case '0':
			limpar;
			cout << "Opção Sair, Até à Próxima!\n";
			return 0;
		case 0xe0: //Indica que uma das setas foi percionada
			if (_getch() == 0x4D) //Corresponde à seta para a direita
				go_loop(pista, aproximacao, descolar, passageiros);
			else cout << "Essa Opção Não é Válida\n";
			break;
		default:
			cout << "Essa opção não é válida\n";
			break;
		}

	} // Fim do While
} // Fim do main
