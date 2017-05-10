#include "bibliotecas.h"

int main() {
	setlocale(LC_ALL, "Portuguese"); //Faz a consola aceitar caracteres especiais.
	var_load_file();//Carrega os ficheiros para mem�ria
	aviao * pista = new aviao[7], *aproximacao = new aviao[10], *descolar = new aviao[5];
	terminal * passageiros = new terminal[30];
	for (int i = 0; i < 30; i++) passageiros[i] = { NULL };
	primeiro_carregamento_vectores(pista, aproximacao, descolar, passageiros); //Carrega o estado ou inicia o programa
	while (1) {
		limpar;
		cout << "(e)merg�ncias (o)p��es (g)ravar\t\t 0 - Sair\n";
		/*if (aproximacao[0].capacidade != 0) {*/
		cout << "---------------\nEm aproxima��o\n---------------\n";
		for (int j = 0; j <= 9; j++) {
			cout << "Voo: " << aproximacao[j].nome_voo << endl;
			cout << "Modelo: " << aproximacao[j].modelo << endl;
			cout << "Origem: " << aproximacao[j].origem << endl;
			cout << "Destino: " << aproximacao[j].destino << endl;
			cout << "Passageiros: ";
			for (int i = 0; i < aproximacao[j].capacidade && i <= 4; i++) cout << aproximacao[j].passageiro[i].segundo_nome << ", ";
			if (aproximacao[j].capacidade > 4) cout << "...\n"; //Esta compara��o serve para o caso de adicionarem uma capacidade de 4 ao ficheiro "capacidade.txt"
			else if (aproximacao[j].capacidade > 0) cout << ".\n";
			else cout << endl;
			cout << "\n";
		}
		cout << "\n";
		cout << "---------------\nNa pista\n---------------\n";
		for (int j = 0; j <= 6; j++) {
			cout << "Voo: " << pista[j].nome_voo << endl;
			cout << "Modelo: " << pista[j].modelo << endl;
			cout << "Origem: " << pista[j].origem << endl;
			cout << "Destino: " << pista[j].destino << endl;
			cout << "Passageiros: ";
			for (int i = 0; i < pista[j].capacidade && i <= 4; i++) cout << pista[j].passageiro[i].segundo_nome << ", ";
			if (pista[j].capacidade > 4) cout << "...\n";
			else if (pista[j].capacidade > 0) cout << ".\n";
			else cout << endl;
			cout << "\n";
		}
		cout << "\n";
		cout << "---------------\nA descolar\n---------------\n";
		for (int j = 0; j <= 4; j++) {
			cout << "Voo: " << descolar[j].nome_voo << endl;
			cout << "Modelo: " << descolar[j].modelo << endl;
			cout << "Origem: " << descolar[j].origem << endl;
			cout << "Destino: " << descolar[j].destino << endl;
			cout << "Passageiros: ";
			for (int i = 0; i < descolar[j].capacidade && i <= 4; i++) cout << descolar[j].passageiro[i].segundo_nome << ", ";
			if (descolar[j].capacidade > 4) cout << "...";
			else if (descolar[j].capacidade > 0) cout << ".";
			else cout << endl;
			cout << "\n";
		}
		/*}
		else {
			cout << "---------------\nEm aproxima��o (A carregar)\n---------------\n";
			for (int i = 9; i >-1; i--)
				cout << i + 1 << "� Voo: " << aproximacao[i].nome_voo << endl;
			}*/

		//-------------Switch Case-------------
		switch (_getch()) {
		case 'e':
			cout << emergencia(pista, aproximacao, descolar); // Fun��o de Emerg�ncia
			break;
		case 'o':
			limpar;
			opcoes(pista, aproximacao, descolar, passageiros); // Fun��o para o Menu_Op��es
			break;
		case 'g':
			limpar;
			cout << "Escolheu a Op��o Gravar.\n";
			if (save(pista, aproximacao, descolar, passageiros))
				cout << "Os Seus Documentos Foram Salvos.\n";
			else cout << "Erro. Falha ao Gravar!\n";
			pausa;
			break;
		case '0':
			limpar;
			cout << "Op��o Sair, At� � Pr�xima!\n";
			return 0;
		case 0xe0: //Indica que uma das setas foi percionada
			if (_getch() == 0x4D) //Corresponde � seta para a direita
				go_loop(pista, aproximacao, descolar, passageiros);
			else cout << "Essa Op��o N�o � V�lida\n";
			break;
		default:
			cout << "Essa op��o n�o � v�lida\n";
			break;
		}
	} // Fim do While
}