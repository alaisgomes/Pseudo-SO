#include "defines.h"
//#include <unistd.h>

// Instanciado uma vez variavel extern
vector<proc_t> vet_processos;
vector<int> vet_memoria;
queue<proc_t> fila_prioridade_zero;
queue<proc_t> fila_prioridade_um;
queue<proc_t> fila_prioridade_dois;
queue<proc_t> fila_prioridade_tres;

queue<int> fila_impressora;
queue<int> fila_scanner;
queue<int> fila_modem;
queue<int> fila_disco;

vector<int> impressora;
vector<int> disco;
int modem, scanner;


vector<int> processos_novos;

#define CLOCK 100000  


int main(int argc, char **argv) {

	int clock_atual = 1; // É incrementado sempre que roda o loop
	
	int pid_exec = -1;
	


	// Le arquivo de processos
	string	arq;
	if(argc < 2) {
		cout << "passe arquivo de processos\n";
		return -1;
	}
	else {
		arq.assign(argv[1]);
	}
	
	// Carrega vetor de processos
	UTILS::carregaProcesso(arq.data());
	
   
	// Carrega vetor de memoria
	UTILS::inicializaMemoria();

	// Inicializa recursos

	RECURSOS::inicializaRecurso();

	
	// Inicia Fluxo
	while(1) {
		
		//Ha novos processos? SIM
		if(vet_processos.size() > 0) {

			if (PROCESSOS::verificaNovo(clock_atual)) {
			
				// aloca memoria
				MEMORIA::alocaMemoria();

				//poe na fila de processos
				UTILS::carregaFilasPrioridades();

				//imprime informações de inicialização
				OUTPUT::mostraDispatcher();
				
				
			}
		
		
		
			// Ha um processo em execucao? SIM
			
			if ((pid_exec = PROCESSOS::verificaExecucao()) > -1) {

				//Incrementa PC dele
				PROCESSOS::atualizaPC(pid_exec);

				//imprime informações 
				OUTPUT::mostraExecucaoAtual(pid_exec);
		

			
	
			}  else { // Nao ha um processo em execucao
				//procura um processo
				
				//procura um processo
				while(pid_exec  < 0){

					//Verifica em Cada fila por um Processo returna o pid do proximo a ser executado pid_exec
					pid_exec = UTILS::verificaProximoParaExecutar();

					
					//PROCESSO PRECISA DE RECURSO? SIM
					if (PROCESSOS::verificaRecurso(pid_exec)) {
						
						//RECURSO DISPONIVEL? SIM
						if (RECURSOS::verificaRecurso(pid_exec)){
							
							//aloca recurso
							RECURSOS::alocaRecurso(pid_exec);
							
							//atualiza fila
							UTILS::removeProcessoFila(pid_exec);

							//coloca em execucao
							PROCESSOS::atualizaEstado(pid_exec, 1);
							PROCESSOS::atualizaPC(pid_exec);
							//IMPRIME INSFORMACOES
							OUTPUT::mostraExecucaoAtual(pid_exec);

						}//NAO
						else{
							//PROCESSO JA BLOQUEADO? NAO
							if(PROCESSOS::verificaBloqueado(pid_exec) != 1){
							//BLOQUEIA O PROCESSO 
							PROCESSOS::bloqueiaProcesso(pid_exec);

							//Insere na fila dos Recursos
							RECURSOS::insereFilaRecurso(pid_exec);
							}
							//diminui prioridadE
							PROCESSOS::mudaPrioridade(pid_exec);

							//poe de volta na fila
							UTILS::insereProcessoFila(vet_processos[pid_exec]);
							
						
						
						}
					} else { //NAO PRECISA DE RECURSO
						
						
						//coloca em execucao
						PROCESSOS::atualizaEstado(pid_exec, 1);
						//EXECUTA UMA INTRUCAO
						PROCESSOS::atualizaPC(pid_exec);
						//IMPRIME INSFORMACOES
						OUTPUT::mostraExecucaoAtual(pid_exec);

						//ATUALIZA FILA
						UTILS::removeProcessoFila(pid_exec);

						


					}
					
					
				}
			}

			//Acabou processo em execucao? SIM
			if (vet_processos[pid_exec].pc == vet_processos[pid_exec].processador) {
				
				//Marca  que terminou e libera processador
				PROCESSOS::atualizaEstado(pid_exec, 2);
				
				//libera memoria e dispositivos
				MEMORIA::removeMemoria(pid_exec);
				
				RECURSOS::liberaRecurso(pid_exec);

				//DESFRAGMENTA A MEMORIA
				MEMORIA::desfragmentar();
				


			} else { // NAO ACABOU


				//Verifica se nao eh um processo em tempo real. Se for, pula atualizacoes
				if (vet_processos[pid_exec].prioridade != 0) {

					//Acabou o Quantum? SIM 
					if ((vet_processos[pid_exec].pc % QUANTUM) == 0) {
						
							//diminui prioridadE
							PROCESSOS::mudaPrioridade(pid_exec);

							//poe de volta na fila
							UTILS::insereProcessoFila(vet_processos[pid_exec]);

							// devolve processador
							PROCESSOS::atualizaEstado(pid_exec, 0);
							
						} 

				}

			}


			//incrementa clock
			clock_atual++;
			processos_novos.clear();
			
			//ATUALIZA AS FILAS DOS RECURSOS 
			RECURSOS::atualizaRecurso();
			

			//SE NAO HOUVEREM MAIS PROCESSOS O PROGRAMA TERMNIA
			if (!PROCESSOS::verificaExisteMaisProcessos()) {
				break;	
			}

			//DEBUG::mostrarFilas();
			//DEBUG::mostraEstadoProcessos();
			//DEBUG::mostrarMemoria();

			getchar();

		} else //Se Arquivo vazio, so sai
			break;
	}
	

	//DEBUG::mostrarProcesso(vet_processos[0]);
	//DEBUG::mostrarProcesso(vet_processos[1]);
	//DEBUG::mostrarFilaPrioridadeZero();

	return 0;
}
