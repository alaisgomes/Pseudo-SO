#include "defines.h"

//PRIVATE
int MEMORIA::verificaDisponivel(int size, int inicio) {
	int j = 0; 
	for (unsigned int i = inicio; i < vet_memoria.size(); i++ ){
		if (vet_memoria[i] == -1)
			j++;
		else
			j = 0;
		if (j == size)
			return i-size+1;
	}
	return -1;

}

void MEMORIA::realizaAlocacao (int bloco_inicial, int offset, int pid) {
	for (int i = bloco_inicial; i < bloco_inicial+offset; i++) {
		vet_memoria[i] = pid;
	}	
	vet_processos[pid].bloc_ini = bloco_inicial;
}


//PUBLIC
void MEMORIA::alocaMemoria() {
	int bloco_inicial;

	for (unsigned int i = 0; i < processos_novos.size(); i++) {
		proc_t proc = vet_processos[processos_novos[i]];
		
		//Se for processo em tempo real comeca do 0, se nao, comeca do inicio determinado pra memoria de usuario
		if (proc.prioridade == 0) {

			bloco_inicial = MEMORIA::verificaDisponivel(proc.offset, 0);
		} else {
			bloco_inicial = MEMORIA::verificaDisponivel(proc.offset, INI_MEMORIA_USUARIO);
		}


		if (bloco_inicial > -1) {
			MEMORIA::realizaAlocacao (bloco_inicial, proc.offset, processos_novos[i]);
		} else {
			//Nao ha memoria disponivel, o que fazer?
			// Poderia alterar o numero de inicializacao dele como se fosse (chegue no proximo clock e veja se tem memoria agora)
		}
		 
	}
}

void MEMORIA::removeMemoria(int pid) {

	int inicio = vet_processos[pid].bloc_ini;
	int offset = vet_processos[pid].offset;

	for (int i = inicio; i < inicio + offset; i++ ){
		vet_memoria[i] = -1;
	}
}


void MEMORIA::desfragmentar() {
    int i, j;
    for (i=INI_MEMORIA_USUARIO;i<MAX_MEM;i++){
        if(vet_memoria[i]!=-1) //procura um espaço vazio
            continue;
        	//DEBUG::mostrarMemoria();
        	//printf("%d\n", i);
        for(j=i+1;j<MAX_MEM;j++){ //procura o proximo espaço ocupado
            if(vet_memoria[j]!=-1){
                vet_memoria[i]=vet_memoria[j]; //transfere para a parte vazia
                vet_memoria[j]=-1; //libera a parte antiga

              //  DEBUG::mostrarMemoria();
                break;
            }
        }
        
    }

}
