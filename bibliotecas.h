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
	int capacidade = 0;
	pessoa * passageiro;
};
struct terminal {
	pessoa humman;
	int turn = -1;
};
//---------Fun�oes_Stream------
bool is_written();
void load_file_state(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros);
string * preencher_dados(string caminho);
bool save(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros);

//---------Fun��es_main---------
void go_loop(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);
void primeiro_carregamento_vectores(aviao * pista, aviao * aproximacao, aviao * desc, terminal * passageiros);
void var_load_file();
void emergencia(aviao * pista, aviao * aproximacao, aviao * descolagem);

//---------Menu Op��o---------
int opcoes(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);

//---------Fun��es_opcoes---------

// 1� Funcionalidade
void lista_todos_passageiros(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros); 
void lista_todos_passageiros_ordenados(aviao * pista, aviao * aprox, aviao * desc, terminal * passageiros);

// 2� Funcionalidade
void lista_todos_voos(aviao * pista, aviao * aprox, aviao * desc);
void lista_voos_pista_descolar(aviao * pista, aviao * desc);

// 3� Funcionalidade
void lista_passageiros_pista(aviao * pista);

//4� Funcionalidade
void lista_passageiros_pista_nacionalidade(aviao * pista);





	