//---------Bibliotecas
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
//---------Defini��es---------
#ifdef _WIN32
#define limpar system("CLS");
#define pausa system("PAUSE");
#define red system("color C"); //emerg�ncia (para sair)
#define white system("color 7");
#else
#define limpar system("clear");
#define pausa system('PAUSE');

#endif

//---------Estruturas---------
struct pessoa {
	int bilhete;
	string primeiro_nome;
	string segundo_nome;
	string nacionalidade;
};
struct aviao {
	string nome_voo;
	string origem;
	string destino;
	string modelo;
	int capacidade;
	pessoa * passageiro;
};
struct terminal {
	pessoa humman;
	int turn = -1;
};

//---------Fun��es_main---------
bool is_written();
void load_file_state(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros);
string * preencher_dados(string caminho);
bool save(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros);

void go_loop(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);
void primeiro_carregamento_vectores(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros);
void var_load_file();

//---------Menu Op��o---------
int opcoes(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);

//---------Fun��es_opcoes---------

void lista_todos_passageiros(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);




