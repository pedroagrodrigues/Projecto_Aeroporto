#include "bibliotecas.h"


int main() {
	setlocale(LC_ALL, "Portuguese");
	var_load();



	/*aviao pista[7], aproximacao[10], descolar;
	int opt;
	preencher_dados(aproximacao, 9);
	int i = 0;
	while (1) { //Este é o nosso loop, o 1 representa o "verdadeiro" sendo que este é um loop infinito
		limpar;
		if (i == 9) i = 0;

		cout << "(e)mergências (o)pções (g)ravar\n";
		cout << "---------------\nEm aproximação\n---------------\n";
		cout << "Voo: " << aproximacao[i].nome_voo << endl;
		cout << "Modelo: " << aproximacao[i].modelo << endl;
		cout << "Origem: " << aproximacao[i].origem << endl;
		cout << "Destino: " << aproximacao[i].destino << endl;
		//cout << "Passageiros: " << aproximacao[1].passageiro.segundo_nome;
		//chamar função em_aproximacao
		cout << "---------------\nNa pista\n---------------\n";
		//chamar função na_pista
		cout << "---------------\nA descolar\n---------------\n";
		
		//-------------Switch Case-------------
		switch (_getch()) {
		case 'e':
			cout << "Este é o menu emergência \n \t Função por implementar\n"; //entra em estado de emergência (uma das últimas a implementar)
			break;
		case 'o':
			cout << "Este é o menu das opções\n\t Função por implementar\n"; //chama função com menu próprio
			break;
		case 'g':
			cout << "Escolheu a opção gravar, os seus documentos foram salvos\n \tFunção por implementar"; //Função para implementar, guarda o estado actual do programa em txt
			break;
		case '0':
			cout << "Opção sair, até à próxima!\n";
			return 0;
		case 0xe0: //coresponde ao primeiro caracter da seta para a direita ('à')
			if (_getch() == 0x4D) { //corresponde ao segundo caracter da seta para a direita
				cout << "proximo ciclo\n";
				i++;
			}
			else cout << "Essa opção não é válida\n";
			break;
		default:
			cout << "Essa opção não é válida\n";
			break;	
		}
	}*/
}

