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
struct terminal {
	struct terminal_item {
		pessoa humman;
		int turn = -1;
		terminal_item * next;
	};
	terminal_item * head;
	terminal_item * end;

};

//---------Fun�oes_Stream-------
string * preencher_dados(string caminho);

//bool is_written();
//void load_file_state(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros);

//bool save(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros);

//---------Fun��es_main---------
void carregamento_inicial(aviao &pista, aviao &aprox, aviao &desc, terminal &passageiros);
void var_load_file();
void new_struct(aviao &pista, aviao &aprox, aviao &desc, terminal &pass);
void go_loop(aviao &pista, aviao &aprox, aviao &desc, terminal &passageiros);

//int emergencia(aviao * pista, aviao * aproximacao, aviao * descolagem);

//---------Chamada Menu_Op��es - PRINCIPAL
int opcoes(aviao &pista, aviao &aprox, aviao &desc, terminal &passageiros);

//---------Fun��es_Op��es------------------------------------------------------------------


// Op��o 1 Menu_Op��es - Fun��es
void lista_todos_passageiros(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros);
void lista_todos_passageiros_ordenados(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros);

// Op��o 2 Menu_Op��es - Fun��es
void lista_todos_voos(aviao &pista, aviao &aproximar, aviao &descolar);
void lista_voos_pista_descolar(aviao &pista, aviao &descolar);

// Op��o 3 Menu_Op��es - Fun��es
void lista_passageiros_pista(aviao &pista);

//Op��o 4 Menu_Op��es - Fun��es
void lista_passageiros_pista_nacionalidade(aviao &pista);

// Op��o 5 - Menu_Op��es - Func��es
void lista_passageiros_estrangeiros_aeroporto(aviao &pista, terminal &passageiros);
int pesquisa_passageiros_estrangeiros_aeroporto_manualmente(aviao &pista, terminal &passageiros);
void pesquisa_passageiros_estrangeiros_aeroporto_lista(aviao &pista, terminal &passageiros);
void pesquisa_passageiros_estrangeiros_aeroporto_primeiro_nome(aviao &pista, terminal &passageiros);
void pesquisa_passageiros_estrangeiros_aeroporto_segundo_nome(aviao &pista, terminal &passageiros);

// Op��o 6 - Menu_Op��es - Fun��es
void pesquisa_passageiros_estrangeiros_aeroporto_ordenados(aviao &pista, terminal &passageiros);

// Op��o 7 - Menu_Op��es - Fun��es
void pesquisa_sobre_passageiros_primeiro_nome(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros);
void pesquisa_sobre_passageiros_segundo_nome(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros);


// Op��o 8 - Menu_Op��es - Fun��es
void editar_nome_passageiro(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros);

// Op��o 9 - Menu_Op��es - Fun��es
void editar_nacionalidade_passageiro(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros);

// Op��o 10 - Menu_Op��es - Fun��es
void editar_destino_voo(aviao &pista, aviao &aproximar, aviao &descolar);

















	