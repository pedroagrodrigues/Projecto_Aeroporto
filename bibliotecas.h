//---------Bibliotecas
#include <iostream>
#include <string>
#include <conio.h>

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
//---------Funçoes_Stream-------
string * preencher_dados(string caminho);
bool is_written(string path);
void load_file_state(aviao &pista, aviao &aproximacao, aviao &descolar, terminal &passageiros, string);
bool save(aviao &pista, aviao &aproximacao, aviao &descolar, terminal &passageiros, string path);

//---------Funções_main---------
void var_load_file();
void new_struct(aviao &pista, aviao &aproximacao, aviao &descolar, terminal &passageiros);
void carregamento_inicial(aviao &pista, aviao &aproximacao, aviao &descolar, terminal &passageiros, string path);
void go_loop(aviao &pista, aviao &aproximacao, aviao &descolar, terminal &passageiros);
bool emergencia(aviao &pista, aviao &aproximacao);
int queue_size(aviao &queue);
//---------Menu Opção-----------

// Chamada Menu_Opções - PRINCIPAL
int opcoes(aviao & pista, aviao & aprox, aviao & descolar, terminal & passageiros);

// Opção 1 Menu_Opções - Funções
void lista_todos_passageiros(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros);
void lista_todos_passageiros_ordenados(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros);

// Opção 2 Menu_Opções - Funções
void lista_voos_pista_descolar(aviao &pista, aviao &descolar);

// Opção 3 Menu_Opções - Funções
void lista_passageiros_pista(aviao &pista);

//Opção 4 Menu_Opções - Funções
void lista_passageiros_pista_nacionalidade(aviao &pista);

// Opção 5 - Menu_Opções - Funcções
int pesquisa_estrangeiros_aeroporto(aviao &pista, terminal &passageiros);

// Opção 6 - Menu_Opções - Funções
void pesquisa_passageiros_estrangeiros_aeroporto_ordenados(aviao &pista, terminal &passageiros);

// Opção 7 - Menu_Opções - Funções
void pesquisa_sobre_passageiros(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros);

// Opção 8-9-10 - Menu_Opções - Funções
void lista_inicial_menu_8(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros);
void lista_inicial_menu_9(aviao &pista, aviao &aproximar, aviao &descolar);
int tkt_select(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros);
int primeiro_nome(aviao &pista, aviao &aproximar, aviao &descolar, terminal &passageiros);
int aviao_edit(aviao &pista, aviao &aproximar, aviao &descolar, string nome);
