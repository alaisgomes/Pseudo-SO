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

#define MAX_MEM 10

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

	// sobrecarregando o operador para que possa printar todas as variaveis
	friend ostream& operator<<(ostream &os, const _proc &proc) {
		os << proc.pid;
		os << proc.inicializacao;
		os << proc.prioridade;
		os << proc.processador;
		os << proc.offset;
		os << proc.impressora;
		os << proc.scanner;
		os << proc.modem;
		os << proc.disco << '\n';
		return os;
	}

} proc_t;

extern vector<proc_t> vet_processos;

/*typedef struct _fila {
	int pseudo_pid; // index do vet_processos
	_fila *prox;
} fila_t;
*/

extern queue<proc_t> fila_prioridade_zero;
extern queue<proc_t> fila_prioridade_um;
extern queue<proc_t> fila_prioridade_dois;
extern queue<proc_t> fila_prioridade_tres;

/*typedef struct _recursos {
	int pseudo_pid;
	_recursos *prox;
} recursos_t;
*/

extern queue<proc_t> fila_impressora;
extern queue<proc_t> fila_scanner;
extern queue<proc_t> fila_driver;
extern queue<proc_t> fila_disco;

namespace recursos_disp {
	extern vector<int> impressora;
	extern vector<int> disco;
	extern int scanner;
	extern int driver;
}

extern vector<int> vet_memoria;

//===== CLASSES E METODOS

class UTILS {
	private:
		static proc_t instVetorProcesso(vector<int> conf);
	public:
		static void carregaProcesso(string arq);
		static void inicializaMemoria();
		static void carregaFilaPrioridadeZero();

};

class DEBUG {
	public:
		static void mostrarProcesso(proc_t proc);
		static void mostrarFilaPrioridadeZero();
};

#endif // DEFINE_H
