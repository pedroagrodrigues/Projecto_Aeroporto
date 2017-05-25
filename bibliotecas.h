//---------Bibliotecas
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
//---------Defini��es---------
#ifdef _WIN32
#define limpar system("CLS");
#define pausa system("PAUSE");
#else
#define limpar system("clear");
#define pausa system('PAUSE');
#endif

//---------Estruturas---------
#ifdef pessoa
#else
struct pessoa {
	struct pessoa_item {
		long bilhete;
		string primeiro_nome;
		string segundo_nome;
		string nacionalidade;
		pessoa_item * next;
	};
	pessoa_item * head;
	pessoa_item * end;
};
#endif
#ifdef aviao
#else
struct aviao {
	struct aviao_item {
		string nome_voo;
		string origem;
		string destino;
		string modelo;
		int capacidade = 0;
		pessoa passageiro;
		aviao_item * next;
	};
	aviao_item * head;
	aviao_item * end;
};
#endif
#ifdef terminal
#else
struct terminal {
	struct terminal_item {
		pessoa humman;
		int turn = -1;
		terminal_item * next;
	};
	terminal_item * head;
	terminal_item * end;

};
#endif
//---------Fun�oes_Stream-------
string * preencher_dados(string caminho);
bool is_written(string path);
void load_file_state(aviao &pista, aviao &aproximacao, aviao &descolar, terminal &passageiros, string);
bool save(aviao &pista, aviao &aproximacao, aviao &descolar, terminal &passageiros, string path);

//---------Fun��es_main---------
void var_load_file();
void new_struct(aviao &pista, aviao &aproximacao, aviao &descolar, terminal &passageiros);
void carregamento_inicial(aviao &pista, aviao &aproximacao, aviao &descolar, terminal &passageiros, string path);
void go_loop(aviao &pista, aviao &aproximacao, aviao &descolar, terminal &passageiros);

//int emergencia(aviao * pista, aviao * aproximacao, aviao * descolarolagem);

//---------Menu Op��o-----------
/*
int opcoes(aviao * pista, aviao * aprox, aviao * descolar, terminal * passageiros);

//---------Fun��es_opcoes------------------------------------------------------------------

// Op��o 1 Menu_Op��es - Fun��es
void lista_todos_passageiros(aviao * pista, aviao * aprox, aviao * descolar, terminal * passageiros); 
void lista_todos_passageiros_ordenados(aviao * pista, aviao * aprox, aviao * descolar, terminal * passageiros);

// Op��o 2 Menu_Op��es - Fun��es
void lista_todos_voos(aviao * pista, aviao * aprox, aviao * descolar);
void lista_voos_pista_descolarolar(aviao * pista, aviao * descolar);

// Op��o 3 Menu_Op��es - Fun��es
void lista_passageiros_pista(aviao * pista);

//Op��o 4 Menu_Op��es - Fun��es
void lista_passageiros_pista_nacionalidade(aviao * pista);



*/

	