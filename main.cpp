#include "bibliotecas.h"


int main() {
	setlocale(LC_ALL, "Portuguese");
	var_load();



	/*aviao pista[7], aproximacao[10], descolar;
	int opt;
	preencher_dados(aproximacao, 9);
	int i = 0;
	while (1) { //Este � o nosso loop, o 1 representa o "verdadeiro" sendo que este � um loop infinito
		limpar;
		if (i == 9) i = 0;

		cout << "(e)merg�ncias (o)p��es (g)ravar\n";
		cout << "---------------\nEm aproxima��o\n---------------\n";
		cout << "Voo: " << aproximacao[i].nome_voo << endl;
		cout << "Modelo: " << aproximacao[i].modelo << endl;
		cout << "Origem: " << aproximacao[i].origem << endl;
		cout << "Destino: " << aproximacao[i].destino << endl;
		//cout << "Passageiros: " << aproximacao[1].passageiro.segundo_nome;
		//chamar fun��o em_aproximacao
		cout << "---------------\nNa pista\n---------------\n";
		//chamar fun��o na_pista
		cout << "---------------\nA descolar\n---------------\n";
		
		//-------------Switch Case-------------
		switch (_getch()) {
		case 'e':
			cout << "Este � o menu emerg�ncia \n \t Fun��o por implementar\n"; //entra em estado de emerg�ncia (uma das �ltimas a implementar)
			break;
		case 'o':
			cout << "Este � o menu das op��es\n\t Fun��o por implementar\n"; //chama fun��o com menu pr�prio
			break;
		case 'g':
			cout << "Escolheu a op��o gravar, os seus documentos foram salvos\n \tFun��o por implementar"; //Fun��o para implementar, guarda o estado actual do programa em txt
			break;
		case '0':
			cout << "Op��o sair, at� � pr�xima!\n";
			return 0;
		case 0xe0: //coresponde ao primeiro caracter da seta para a direita ('�')
			if (_getch() == 0x4D) { //corresponde ao segundo caracter da seta para a direita
				cout << "proximo ciclo\n";
				i++;
			}
			else cout << "Essa op��o n�o � v�lida\n";
			break;
		default:
			cout << "Essa op��o n�o � v�lida\n";
			break;	
		}
	}*/
}

