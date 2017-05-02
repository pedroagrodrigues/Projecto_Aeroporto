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
//---------Funçoes_Stream-------
bool is_written();
void load_file_state(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros);
string * preencher_dados(string caminho);
bool save(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros);

//---------Funções_main---------
void go_loop(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);
void primeiro_carregamento_vectores(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros);
void var_load_file();
int emergencia(aviao * pista, aviao * aproximacao, aviao * descolagem);

//---------Menu Opção-----------
int opcoes(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);

//---------Funções_opcoes------------------------------------------------------------------

// Opção 1 Menu_Opções - Funções
void lista_todos_passageiros(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros); 
void lista_todos_passageiros_ordenados(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);

// Opção 2 Menu_Opções - Funções
void lista_todos_voos(aviao * pista, aviao * aprox, aviao * desc);
void lista_voos_pista_descolar(aviao * pista, aviao * desc);

// Opção 3 Menu_Opções - Funções
void lista_passageiros_pista(aviao * pista);

//Opção 4 Menu_Opções - Funções
void lista_passageiros_pista_nacionalidade(aviao * pista);





	