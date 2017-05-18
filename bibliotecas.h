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
	long bilhete;
	string primeiro_nome;
	string segundo_nome;
	string nacionalidade;
};
struct aviao {
	string nome_voo;
	string origem;
	string destino;
	string modelo;
	int capacidade = 0;
	pessoa * passageiro;
};
struct terminal {
	pessoa humman;
	int turn = -1;
};
//---------Fun�oes_Stream-------
bool is_written();
void load_file_state(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros);
string * preencher_dados(string caminho);
bool save(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros);

//---------Fun��es_main---------
void go_loop(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);
void primeiro_carregamento_vectores(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros);
void var_load_file();
int emergencia(aviao * pista, aviao * aproximacao, aviao * descolagem);

//---------Menu Op��o-----------
int opcoes(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);

//---------Fun��es_opcoes------------------------------------------------------------------

// Op��o 1 Menu_Op��es - Fun��es
void lista_todos_passageiros(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros); 
void lista_todos_passageiros_ordenados(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);

// Op��o 2 Menu_Op��es - Fun��es
void lista_todos_voos(aviao * pista, aviao * aprox, aviao * desc);
void lista_voos_pista_descolar(aviao * pista, aviao * desc);

// Op��o 3 Menu_Op��es - Fun��es
void lista_passageiros_pista(aviao * pista);

//Op��o 4 Menu_Op��es - Fun��es
void lista_passageiros_pista_nacionalidade(aviao * pista, terminal * passageiros);

// Op��o 5 - Menu_Op��es - Func��es
void lista_passageiros_estrangeiros_aeroporto(aviao * pista, terminal * passageiro);
int pesquisa_passageiros_estrangeiros_aeroporto_manualmente(aviao * pista, terminal * passageiro);
void pesquisa_passageiros_estrangeiros_aeroporto_lista(aviao * pista, terminal * passageiro);
void pesquisa_passageiros_estrangeiros_aeroporto_primeiro_nome(aviao * pista, terminal * passageiro);
void pesquisa_passageiros_estrangeiros_aeroporto_segundo_nome(aviao * pista, terminal * passageiro);

// Op��o 6 - Menu_Op��es - Fun��es
void pesquisa_passageiros_estrangeiros_aeroporto_ordenados(aviao * pista, terminal * passageiros);

// Op��o 7 - Menu_Op��es - Fun��es
void pesquisa_sobre_passageiros_primeiro_nome(aviao * pista, aviao * desc, aviao * aprox, terminal * passageiros);
void pesquisa_sobre_passageiros_segundo_nome(aviao * pista, aviao * desc, aviao * aprox, terminal * passageiros);


// Op��o 8 - Menu_Op��es - Fun��es
void editar_nome_passageiro(aviao * pista, aviao * desc, aviao * aprox, terminal * passageiros);

// Op��o 9 - Menu_Op��es - Fun��es
void editar_nacionalidade_passageiro(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);

// Op��o 10 - Menu_Op��es - Fun��es
void editar_destino_voo(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);