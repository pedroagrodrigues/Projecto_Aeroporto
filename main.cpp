#include "bibliotecas.h"

int main() {
	setlocale(LC_ALL, "Portuguese");
	var_load_file();
	aviao pista[7], aproximacao[10], *descolar = new aviao;
	terminal * passageiros = new terminal[30];
	//for (int i = 0; i < 30; i++) passageiros[i] = { NULL };
	primeiro_carregamento_vectores(pista, aproximacao, descolar, passageiros);
	while (1) {
		limpar;
		cout << "(e)mergências (o)pções (g)ravar\t\t 0 - Sair\n";
		cout << "---------------\nEm aproximação\n---------------\n";
		cout << "Voo: " << aproximacao[0].nome_voo << endl;
		cout << "Modelo: " << aproximacao[0].modelo << endl;
		cout << "Origem: " << aproximacao[0].origem << endl;
		cout << "Destino: " << aproximacao[0].destino << endl;
		cout << "Passageiros: ";
		for (int i = 0; i < aproximacao[0].capacidade && i <= 4; i++) cout << aproximacao[0].passageiro[i].segundo_nome << ", ";
		if (aproximacao[0].capacidade > 4) cout << "...\n";
		else cout << "./n";
		cout << "---------------\nNa pista\n---------------\n";
		cout << "Voo: " << pista[0].nome_voo << endl;
		cout << "Modelo: " << pista[0].modelo << endl;
		cout << "Origem: " << pista[0].origem << endl;
		cout << "Destino: " << pista[0].destino << endl;
		cout << "Passageiros: ";
		for (int i = 0; i < pista[0].capacidade && i <= 4; i++) cout << pista[0].passageiro[i].segundo_nome << ", ";
		if (pista[0].capacidade > 4) cout << "...\n";
		else cout << "./n";
		cout << "---------------\nA descolar\n---------------\n";
		cout << "Voo: " << descolar->nome_voo << endl;
		cout << "Modelo: " << descolar->modelo << endl;
		cout << "Origem: " << descolar->origem << endl;
		cout << "Destino: " << descolar->destino << endl;
		cout << "Passageiros: ";
		for (int i = 0; i < descolar->capacidade && i <= 4; i++) cout << descolar->passageiro[i].segundo_nome << ", ";
		if (descolar->capacidade > 4) cout << "...\n";
		else cout << "./n";
		/*for (int i = 0; i < 30; i++)
			cout << passageiros[i].humman.segundo_nome << " teste\n";*/
		//-------------Switch Case-------------
		switch (_getch()) {
		case 'e':
			limpar;
			cout << "Este é o menu emergência \n \t Função por implementar\n"; //entra em estado de emergência (uma das últimas a implementar)
			break;
		case 'o':
			limpar;
			cout << "Este é o menu das opções\n\t Função por implementar\n"; //chama função com menu próprio
			break;
		case 'g':
			limpar;
			if (save(pista, aproximacao, descolar, passageiros))
				cout << "Escolheu a opção gravar, os seus documentos foram salvos.\n";
			else cout << "Erro, falha ao gravar!\n";
			pausa;
			break;
		case '0':
			limpar;
			cout << "Opção sair, até à próxima!\n";
			return 0;
		case 0xe0: //coresponde ao caracter indica que uma das setas foi precionada
			if (_getch() == 0x4D) //corresponde à seta para a direita
				go_loop(pista, aproximacao, descolar, passageiros);
			else cout << "Essa opção não é válida\n";
			break;
		default:
			cout << "Essa opção não é válida\n";
			break;
		}
	}
}

