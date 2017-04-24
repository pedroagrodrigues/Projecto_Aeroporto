#include "bibliotecas.h"

int main() {
	setlocale(LC_ALL, "Portuguese");
	var_load_file();
	aviao * pista = new aviao[7], * aproximacao = new aviao[10], * descolar = new aviao[5];
	terminal * passageiros = new terminal[30];
	for (int i = 0; i < 30; i++) passageiros[i] = { NULL };
	primeiro_carregamento_vectores(pista, aproximacao, descolar, passageiros);
	while (1) {
		limpar;
		cout << "(e)merg�ncias (o)p��es (g)ravar\t\t 0 - Sair\n";
		cout << "---------------\nEm aproxima��o\n---------------\n";
		cout << "Voo: " << aproximacao[0].nome_voo << endl;
		cout << "Modelo: " << aproximacao[0].modelo << endl;
		cout << "Origem: " << aproximacao[0].origem << endl;
		cout << "Destino: " << aproximacao[0].destino << endl;
		cout << "Passageiros: ";
		for (int i = 0; i < aproximacao[0].capacidade && i <= 4; i++) cout << aproximacao[0].passageiro[i].segundo_nome << ", ";
		if (aproximacao[0].capacidade > 4) cout << "...\n";
		else cout << ".\n";
		cout << ".\n.\n";
		cout << "---------------\nNa pista\n---------------\n";
		cout << "Voo: " << pista[0].nome_voo << endl;
		cout << "Modelo: " << pista[0].modelo << endl;
		cout << "Origem: " << pista[0].origem << endl;
		cout << "Destino: " << pista[0].destino << endl;
		cout << "Passageiros: ";
		for (int i = 0; i < pista[0].capacidade && i <= 4; i++) cout << pista[0].passageiro[i].segundo_nome << ", ";
		if (pista[0].capacidade > 4) cout << "...\n";
		else cout << ".\n";
		cout << ".\n.\n";
		cout << "---------------\nA descolar\n---------------\n";
		cout << "Voo: " << descolar[4].nome_voo << endl;
		cout << "Modelo: " << descolar[4].modelo << endl;
		cout << "Origem: " << descolar[4].origem << endl;
		cout << "Destino: " << descolar[4].destino << endl;
		cout << "Passageiros: ";
		for (int i = 0; i < descolar[4].capacidade && i <= 4; i++) cout << descolar[4].passageiro[i].segundo_nome << ", ";
		if (descolar[4].capacidade > 4) cout << "...\n";
		else cout << ".\n";

		//Teste Para Ver Se As Pessoas Est�o a Entrar e a Sair Do Terminal
		//for (int i = 0; i < 30; i++)
			//if (passageiros[i].turn != -1) cout << passageiros[i].humman.segundo_nome << " turno \t" << passageiros[i].turn << endl;

			
		//-------------Switch Case-------------
		switch (_getch()) {
		case 'e':
			limpar;
			red;
			cout << "Este � o menu emerg�ncia \n \t Fun��o por implementar\n"; //entra em estado de emerg�ncia (uma das �ltimas a implementar)
			pausa;
			white;
			break;
		case 'o':
			limpar;
			opcoes(pista, aproximacao, descolar, passageiros); // Fun��o Criada Para o Menu_Op��es
			break;
		case 'g':
			limpar;
			cout << "Escolheu a op��o gravar.\n";
			if (save(pista, aproximacao, descolar, passageiros))
				cout << "Os seus documentos foram salvos.\n";
			else cout << "Erro, falha ao gravar!\n";
			pausa;
			break;
		case '0':
			limpar;
			cout << "Op��o sair, at� � pr�xima!\n";
			return 0;
		case 0xe0: //Coresponde ao Caracter Indica Que Uma Das Setas Foi Precionada
			if (_getch() == 0x4D) //Corresponde � Seta Para a Direita
				go_loop(pista, aproximacao, descolar, passageiros);
			else cout << "Essa op��o n�o � v�lida\n";
			break;
		default:
			cout << "Essa op��o n�o � v�lida\n";
			break;
		}
	}
}

