//---------Bibliotecas
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>

using namespace std;
//---------Definições---------
#ifdef _WIN32
#define limpar system("CLS");
#define pausa system("PAUSE");
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

//---------Funções_main---------
bool is_written();
void load_file_state(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros);
string * preencher_dados(string caminho);
bool save(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros);

void go_loop(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);
void primeiro_carregamento_vectores(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros);
void var_load_file();

//---------Menu Opção---------
int opcoes(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);

//---------Funções_opcoes---------

void lista_todos_passageiros(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros); 

void lista_todos_voos(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);

void lista_passageiros_pista(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);

void lista_passageiros_pista_nacionalidade(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);


//---------Função_EMERGÊNCIA---------

void emergencia(aviao * pista, aviao * aproximacao, aviao * descolagem); 

	