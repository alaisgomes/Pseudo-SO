#ifndef DEFINE_H
#define DEFINE_H

#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

//===== VARIAVEIS

typedef struct _proc {
	int pid;
	int inicializacao;
	int prioridade;
	int processador; //quantidade max de inst
	int offset;
	int bloc_ini;
	int impressora;
	int scanner;
	int modem;
	int disco;
	int estado;
	int pc; //qual instrucao esta

} proc_t;
typedef vector<proc_t> v_proc;

typedef struct _fila {
	int pseudo_pid; // index do vet_processos
	_fila *prox;
} fila_t;
extern queue<proc_t> fila_prioridade0;
extern queue<proc_t> fila_prioridade1;
extern queue<proc_t> fila_prioridade2;
extern queue<proc_t> fila_prioridade3;

typedef struct _recursos {
	int pseudo_pid;
	_recursos *prox;
} recursos_t;

extern queue<recursos_t> fila_impressora;
extern queue<recursos_t> fila_scanner;
extern queue<recursos_t> fila_driver;
extern queue<recursos_t> fila_disco;

namespace recursos_disp {
	extern vector<int> impressora;
	extern vector<int> disco;
	extern int scanner;
	extern int driver;
}

extern vector<int> v_mem;

//===== METODOS

class UTILS {
	private:
		static proc_t instVetorProcesso(vector<int> conf);
	public:
		static v_proc carregaProcesso(string arq);
};

#endif // DEFINE_H
