#include "bibliotecas.h"

int main() {
	setlocale(LC_ALL, "Portuguese"); //Faz a consola aceitar caracteres especiais.
	var_load_file();//Carrega os ficheiros para mem�ria
	aviao * pista = new aviao[7], * aproximacao = new aviao[10], * descolar = new aviao[5];
	terminal * passageiros = new terminal[30];
	for (int i = 0; i < 30; i++) passageiros[i] = { NULL };
	primeiro_carregamento_vectores(pista, aproximacao, descolar, passageiros); //Carrega o estado ou inicia o programa
	while (1) {
		limpar;
		cout << "(e)merg�ncias (o)p��es (g)ravar\t\t 0 - Sair\n";
		if (aproximacao[0].capacidade != 0) {
			cout << "---------------\nEm aproxima��o\n---------------\n";
			cout << "Voo: " << aproximacao[0].nome_voo << endl;
			cout << "Modelo: " << aproximacao[0].modelo << endl;
			cout << "Origem: " << aproximacao[0].origem << endl;
			cout << "Destino: " << aproximacao[0].destino << endl;
			cout << "Passageiros: ";
			for (int i = 0; i < aproximacao[0].capacidade && i <= 4; i++) cout << aproximacao[0].passageiro[i].segundo_nome << ", ";
			if (aproximacao[0].capacidade > 4) cout << "...\n"; //Esta compara��o serve para o caso de adicionarem uma capacidade de 4 ao ficheiro "capacidade.txt"
			else if (aproximacao[0].capacidade > 0) cout << ".\n";
			else cout << endl;
			cout << ".\n.\n";
			cout << "---------------\nNa pista\n---------------\n";
			cout << "Voo: " << pista[6].nome_voo << endl;
			cout << "Modelo: " << pista[6].modelo << endl;
			cout << "Origem: " << pista[6].origem << endl;
			cout << "Destino: " << pista[6].destino << endl;
			cout << "Passageiros: ";
			for (int i = 0; i < pista[6].capacidade && i <= 4; i++) cout << pista[6].passageiro[i].segundo_nome << ", ";
			if (pista[6].capacidade > 4) cout << "...\n";
			else if (pista[6].capacidade > 0) cout << ".\n";
			else cout << endl;
			cout << ".\n.\n";
			cout << "---------------\nA descolar\n---------------\n";
			cout << "Voo: " << descolar[4].nome_voo << endl;
			cout << "Modelo: " << descolar[4].modelo << endl;
			cout << "Origem: " << descolar[4].origem << endl;
			cout << "Destino: " << descolar[4].destino << endl;
			cout << "Passageiros: ";
			for (int i = 0; i < descolar[4].capacidade && i <= 4; i++) cout << descolar[4].passageiro[i].segundo_nome << ", ";
			if (descolar[4].capacidade > 4) cout << "...";
			else if (descolar[4].capacidade > 0) cout << ".";
		}
		else {
			cout << "---------------\nEm aproxima��o (A carregar)\n---------------\n";
			for (int i = 9; i >-1; i--)
				cout << i+1 << "� Voo: " << aproximacao[i].nome_voo << endl;
			
			
		}

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

