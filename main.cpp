#include "bibliotecas.h"

//Imprime aviões e respetivos passageiros
void print_aviao_passageiros(aviao &subject) {
	aviao::aviao_item *temp = subject.head;
	pessoa::pessoa_item *temp_passageiro = new pessoa::pessoa_item();
	while (temp != NULL) {
		cout.width(14);
		cout << left << temp->nome_voo;
		cout.width(18);
		cout << left << temp->modelo;
		cout.width(27);
		cout << left << temp->origem;
		cout.width(27);
		cout << left << temp->destino;
		temp_passageiro = temp->passageiro.head;
		for (int i = 0; i < 3 && temp_passageiro != NULL; i++) {
			if (i==2 && temp_passageiro->next != NULL) cout << temp_passageiro->segundo_nome << "... ";
			else if (temp_passageiro->next == NULL) cout << temp_passageiro->segundo_nome << ".";
			else cout << temp_passageiro->segundo_nome << ", ";
			temp_passageiro = temp_passageiro->next;
		}
		cout << endl;
		temp = temp->next;
	}
}

int main(int argc, char *argv[]) {
	string path;
	(argc < 2) ? path = "NULL" : path = string(argv[1]);
	setlocale(LC_ALL, "Portuguese"); //Faz a consola aceitar caracteres especiais.
	var_load_file();//Carrega os ficheiros para mem�ria
	aviao pista, aproximacao, descolar;
	terminal passageiros;
	new_struct(pista, aproximacao, descolar, passageiros);
	carregamento_inicial(pista, aproximacao, descolar, passageiros, path);


	while (1) {
		limpar;
		cout << "(e)mergências (o)pções (g)ravar\t\t 0 - Sair\n";
		cout << "----------------------------------------------------------------------------------------------------------------------\n";
		cout.width(65);
		cout << right << "Em Aproximação:\n";
		cout << "----------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "Voo";
		cout.width(18);
		cout << "Modelo";
		cout.width(23);
		cout << "Origem";
		cout.width(25);
		cout << "Destino";
		cout.width(35);
		cout << "Passageiros \n";
		print_aviao_passageiros(aproximacao);
		cout << "\n";
		cout << "----------------------------------------------------------------------------------------------------------------------\n";
		cout.width(65);
		cout << right << "Na Pista:\n";
		cout << "----------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "Voo";
		cout.width(18);
		cout << "Modelo";
		cout.width(21);
		cout << "Origem";
		cout.width(27);
		cout << "Destino";
		cout.width(35);
		cout << "Passageiros \n";
		print_aviao_passageiros(pista);
		cout << "\n";
		cout << "----------------------------------------------------------------------------------------------------------------------\n";
		cout.width(65);
		cout << right << "A Descolar:\n";
		cout << "----------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "Voo";
		cout.width(18);
		cout << "Modelo";
		cout.width(21);
		cout << "Origem";
		cout.width(27);
		cout << "Destino";
		cout.width(35);
		cout << "Passageiros \n";
		print_aviao_passageiros(descolar);

		//-------------Switch Case-------------
		switch (_getch()) {
		case 'e':
			if (queue_size(aproximacao) >= 10 && pista.head != NULL) {
				if (aproximacao.head->nome_voo.find("-Emergência") != string::npos) {
					limpar;
					cout << "Emergência já a Decorrer." << endl;
					pausa;
				}
				else if (emergencia(pista, aproximacao)) aproximacao.head->nome_voo = aproximacao.head->nome_voo + "-Emergência  "; // Função de Emergência
			}
			else {
				limpar;
				cout << "Só é Possível Aceder ao Menu Emergência Quando as Aproximações Estão Cheias.\n";
				pausa;
			}
			break;
		case 'o':
			opcoes(pista, aproximacao, descolar, passageiros); // Função Para Entrada Principal Menu_Opções
			break;
		case 'g':
			limpar;
			cout << "Escolheu a Opção Gravar.\n";
			if (path == "NULL") {
				cout << "Não foram defenidos ficheiros para gravar.\n";
				pausa;
				break;
			}
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
			else cout << "Essa Opção Não é Válida.\n";
			break;
		default:
			cout << "Essa Opção Não é Válida.\n";
			break;
		}

	} // Fim do While
} // Fim do main

