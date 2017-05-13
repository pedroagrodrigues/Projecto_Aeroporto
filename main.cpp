#include "bibliotecas.h"

int main() {
	setlocale(LC_ALL, "Portuguese"); //Faz a consola aceitar caracteres especiais.
	var_load_file();//Carrega os ficheiros para memória
	aviao * pista = new aviao[7], *aproximacao = new aviao[10], *descolar = new aviao[5];
	terminal * passageiros = new terminal[30];
	for (int i = 0; i < 30; i++) passageiros[i] = { NULL };
	primeiro_carregamento_vectores(pista, aproximacao, descolar, passageiros); //Carrega o estado ou inicia o programa
	while (1) {
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
		for (int j = 0; j <= 9; j++) {
			cout.width(18);
			cout << left << aproximacao[j].nome_voo;
			cout.width(20);
			cout << left << aproximacao[j].modelo;
			cout.width(27);
			cout << left << aproximacao[j].origem;
			cout.width(27);
			cout << left << aproximacao[j].destino;
			for (int i = 0; i < aproximacao[j].capacidade && i <= 4; i++) cout << aproximacao[j].passageiro[i].segundo_nome << ", ";
			if (aproximacao[j].capacidade > 4) cout << "..."; //Esta comparação serve para o caso de adicionarem uma capacidade de 4 ao ficheiro "capacidade.txt"
			else if (aproximacao[j].capacidade > 0) cout << ".";
			else cout << endl;
			cout << "\n";
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
		for (int j = 0; j <= 6; j++) {
			cout.width(18);
			cout << left << pista[j].nome_voo;
			cout.width(20);
			cout << left << pista[j].modelo;
			cout.width(27);
			cout << left << pista[j].origem;
			cout.width(27);
			cout << left << pista[j].destino;
			for (int i = 0; i < pista[j].capacidade && i <= 4; i++) cout << pista[j].passageiro[i].segundo_nome << ", ";
			if (pista[j].capacidade > 4) cout << "...";
			else if (pista[j].capacidade > 0) cout << ".";
			else cout << endl;
			cout << "\n";
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
		for (int j = 0; j <= 4; j++) {
			cout.width(18);
			cout << left << descolar[j].nome_voo;
			cout.width(20);
			cout << left << descolar[j].modelo;
			cout.width(27);
			cout << left << descolar[j].origem;
			cout.width(27);
			cout << left << descolar[j].destino;
			for (int i = 0; i < descolar[j].capacidade && i <= 4; i++) cout << descolar[j].passageiro[i].segundo_nome << ", ";
			if (descolar[j].capacidade > 4) cout << "...";
			else if (descolar[j].capacidade > 0) cout << ".";
			else cout << endl;
			cout << "\n";
		}
		
		//-------------Switch Case-------------
		switch (_getch()) {
		case 'e':
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
}