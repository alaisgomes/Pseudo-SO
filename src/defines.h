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

#define MAX_MEM 50
#define QUANTUM 1
#define INI_MEMORIA_USUARIO 25
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
	int estado; // Em execucao = 1, nao executado = 0, finalizado = 2, bloqueado = 3.
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

extern queue<int> fila_impressora;
extern queue<int> fila_scanner;
extern queue<int> fila_modem;
extern queue<int> fila_disco;


	extern vector<int> impressora;
	extern vector<int> disco;
	extern int scanner;
	extern int modem;


extern vector<int> vet_memoria;

// Vetor com processos novos a cada clock que "chegam"
//Para facil manipulacao
extern vector<int> processos_novos;


//===== CLASSES E METODOS

class UTILS {
	private:
		static proc_t instVetorProcesso(vector<int> conf);
	public:
		static void carregaProcesso(string arq);
		static void inicializaMemoria();
		//static void carregaFilaPrioridadeZero(proc_t proc);
		static void carregaFilasPrioridades();
		static void insereProcessoFila(proc_t proc);
		static void removeProcessoFila(int pid);
		static int verificaProximoParaExecutar();

};

class DEBUG {
	public:
		static void mostrarProcesso(proc_t proc);
		static void mostrarFilaPrioridadeZero();
		static void mostrarMemoria();
		static void mostrarFilas();
		static void mostraEstadoProcessos ();
};

class PROCESSOS {
	public:
		static int  verificaNovo(int clock);
		static int  verificaExecucao();
		static void atualizaPC(int pid);
		static void atualizaEstado(int pid, int estado);
		static int  verificaExisteMaisProcessos();
		static void mudaPrioridade(int pid);
		static int verificaRecurso(int pid);
		static int verificaBloqueado(int pid);
		static void bloqueiaProcesso(int pid);
};

class RECURSOS {
	public:
		static int verificaRecurso(int pid);
		static void liberaRecurso(int pid);
		static void atualizaRecurso();
		static void inicializaRecurso();
		static void insereFilaRecurso(int pid);
		static void alocaRecurso(int pid);
};

class MEMORIA {
	private:
		static int verificaDisponivel(int size, int inicio);
		static void realizaAlocacao (int bloco_inicial, int offset, int pid);
	public: 
		static void alocaMemoria();
		static void removeMemoria(int pid);
		static void desfragmentar();
};

class OUTOUT {
	public:
		static void OUTPUT::mostraDispatcher();
		static void OUTPUT::mostraExecucaoAtual(int pid);
};

#endif // DEFINE_H
