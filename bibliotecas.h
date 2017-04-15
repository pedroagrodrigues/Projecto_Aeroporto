//---------Bibliotecas
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
//---------Definições
#ifdef _WIN32
	#define limpar system("CLS");
	#define pausa system("PAUSE");
#else
	#define limpar system("clear");
	#define pausa system('PAUSE');
#endif

//---------Estruturas-----
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
<<<<<<< HEAD
	//pessoa passageiro;
=======
	pessoa * passageiro;
>>>>>>> origin/randomize
};


//---------Funções---------
<<<<<<< HEAD
void var_load_file();
string * preencher_dados(string caminho);
void carregamento_vectores(aviao * pista, aviao * aproximacao, aviao * descolar);
=======
bool is_written();
void load_file_state(aviao pista[], aviao aproximacao[], aviao * desc);
string * preencher_dados(string caminho); 
bool save(aviao pista[], aviao aproximacao[], aviao * desc);

void go_loop(aviao pista[], aviao aprox[], aviao * desc);
void primeiro_carregamento_vectores(aviao pista[], aviao aproximacao[], aviao * desc);
void var_load_file();
>>>>>>> origin/randomize

