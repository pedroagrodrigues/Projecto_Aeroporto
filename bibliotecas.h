//---------Bibliotecas
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
//---------Definições
#ifdef _WIN32
	#define limpar system("CLS");
	#define pausa system("PAUSE");
#endif

#ifdef _unix_
	#define limpar system("clear");
	#define pausa system('PAUSE');\\não tenho a certeza se funciona em linux
#endif

//---------Estruturas-----
struct aviao {
	string nome_voo;
	string origem;
	string destino;
	string modelo;
	int capacidade;
	//pessoa passageiro;
};
struct pessoa {
	int bi;
	string primeiro_nome;
	string segundo_nome;
	string nacionalidade;
};
//---------Funções---------
void var_load();
void preencher_dados(string * data, string caminho);

