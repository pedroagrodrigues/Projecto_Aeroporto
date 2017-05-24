#include "bibliotecas.h"

int main() {
	setlocale(LC_ALL, "Portuguese"); //Faz a consola aceitar caracteres especiais.
	var_load_file();//Carrega os ficheiros para mem�ria
	aviao pista, aproximacao, descolar;
	terminal passageiros;
	new_struct(pista, aproximacao, descolar, passageiros);
	carregamento_inicial(pista, aproximacao, descolar, passageiros); 
	
	while (1) {
		limpar;
		cout << "(e)mergências (o)pções (g)ravar\t\t 0 - Sair\n";
		cout << "-----------aprox---------\n";
		aviao::aviao_item *temp = aproximacao.head;

		while (temp != NULL) {
			cout << temp->nome_voo << "\n";
			temp = temp->next;
		}
		cout << "-----------Pista---------\n";
		temp = pista.head;

		while (temp != NULL) {
			cout << temp->nome_voo << "\n";
			temp = temp->next;
		}

		cout << "-----------desc---------\n";
		temp = descolar.head;
		while (temp != NULL) {
			cout << temp->nome_voo << "\n";
			temp = temp->next;
		}
		delete temp;

		cout << endl;

		//-------------Switch Case-------------
		switch (_getch()) {
		/*case 'e':
			cout << emergencia(pista, aproximacao, descolar); // Função de Emergência
			break;
		case 'o':
			limpar;
			opcoes(pista, aproximacao, descolar, passageiros); // Função para o Menu_Opções
			break;
		case 'g':
			limpar;
			cout << "Escolheu a Opção Gravar.\n";
			if (save(pista, aproximacao, descolar, passageiros))
				cout << "Os Seus Documentos Foram Salvos.\n";
			else cout << "Erro. Falha ao Gravar!\n";
			pausa;
			break;*/
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
	} // Fim do While*/
}

