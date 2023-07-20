#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // biblioteca time.h

//Nome:Davi Tiago Soares, Nº: 12211BSI240

struct funcionario {
    // definir estruturas no inicio do programa
    char cpf[12];
    char nome[30];
    time_t entrada;
    time_t saida;
    char status;    
};
struct log {
    char cpf[11];
    time_t horario;
    char evento;
    };
void registro(FILE *funcionarios, FILE *log) {
    // completar
    int result = 0;
    char cpf[11];
    struct funcionario help;
    struct log helplog;
    for(int i=0;i<1;i++){
    printf("Informe o CPF do funcionario: ");
    scanf(" %s", cpf);
    if(strlen(cpf)>11 || strlen(cpf)<11){
        printf("O CPF DEVE CONTER 11 NUMEROS\n");
        i--;
    }
    }
    strcpy(help.cpf,cpf);   
    // procurar funcionario no arquivo funcionarios.bin começando do inicio
    fseek(funcionarios, 0, SEEK_SET);
    while(fread(&help, sizeof(struct funcionario), 1, funcionarios) == 1) {
    // compara o cpf do funcionário com o cpf desejado
        if(strcmp(help.cpf, cpf) == 0) {
        // encontrou o funcionário! 
        
            result = 1;
    
            for(int i=0; i<1;i++){
                printf("Informe o Evento [E]Entrada,[S]Saida: ");
                setbuf(stdin, NULL);
                scanf(" %c",&helplog.evento);
                if((helplog.evento != 'E' )&& (helplog.evento != 'S')){
                    printf("Evento errado, digite de novo\n");
                    i--;
                }
            }
            if(helplog.evento == 'E'){
                help.status = 'P';
                help.entrada = time(NULL);
            }
            else{
                help.status ='A';
                help.saida = time(NULL);
            }
            strcpy(helplog.cpf,help.cpf);
            helplog.horario = time(NULL);
        // escreve as informações atualizadas no arquivo funcionarios.bin
            fseek(funcionarios, -1 * (int) sizeof(struct funcionario), SEEK_CUR);
            fwrite(&help, sizeof(struct funcionario), 1, funcionarios);
        // escreve o novo registro no arquivo log.bin
            fseek(log,0,SEEK_END);
            fwrite(&helplog, sizeof(struct log), 1, log);
        return; }

    }//CPF nao encontrado
     if(result == 0) {
        strcpy(help.cpf,cpf);
        printf("Funcionario nao encontrado.\n");
        printf("Informe o nome do funcionario:\n");
        setbuf(stdin, NULL);
        fgets(help.nome,sizeof(help.nome),stdin);
                for(int i=0; i<1;i++){
                printf("Informe o Evento [E]Entrada,[S]Saida: ");
                setbuf(stdin, NULL);
                scanf(" %c",&helplog.evento);
                if((helplog.evento != 'E' )&& (helplog.evento != 'S')){
                    printf("Evento digitado errado, digite de novo\n");
                    i--;
                }
            }
            if(helplog.evento == 'E'){
                help.status = 'P';
                help.entrada = time(NULL);
            }
            else{
                help.status ='A';
                help.saida = time(NULL);
            }
            strcpy(helplog.cpf,help.cpf);
            helplog.horario = time(NULL);
            fwrite(&help, sizeof(struct funcionario), 1, funcionarios);
            // escreve o novo registro no arquivo log.bin
            fseek(log,0,SEEK_END);
            fwrite(&helplog, sizeof(struct log), 1, log);


    }
}
void listagem_funcionarios(FILE *funcionarios) {
    // completar
    struct funcionario help;
    fseek(funcionarios, 0, SEEK_SET);
    while(fread(&help, sizeof(struct funcionario), 1, funcionarios) == 1) {
        if(feof(funcionarios)){
            printf("Erro em ler o arquivo funcionarios");
            break;

        }
        printf("\nCPF: %s\nNome: %sStatus: %c\nEntrada: %sSaida: %s\n", help.cpf,help.nome,help.status,ctime(&help.entrada),ctime(&help.saida));
    }
}

void listagem_log(FILE *log) {
    // completar
    struct log helplog;
    fseek(log, 0, SEEK_SET);
    while(fread(&helplog, sizeof(struct log), 1, log) == 1) {
        if(feof(log)){
            printf("Erro em ler o arquivo log");
            break;
        }
        printf("\nCPF: %s\nHorário: %sEvento: %c\n",helplog.cpf,ctime(&helplog.horario),helplog.evento);
    }
}
int main() {
    // abrir arquivos (completar). Sugestão: tentar abrir com "rb+", e se não abrir, tentar abrir com "wb+", 
    FILE *funcionarios;
    funcionarios = fopen("funcionarios.bin","rb+");
	// e se não abrir, informar o usuário que não foi possível
    if(funcionarios == NULL){ funcionarios = fopen("funcionarios.bin","wb+");
    } 
    else if(funcionarios==NULL){
        printf("Erro em abrir arquivo, funcionarios\n");
        system("pause");
        exit(1);
    }
    FILE *log;
    log = fopen("log.bin","rb+");
    if(log==NULL){ log = fopen("log.bin","wb+");
    }
    else if(log==NULL){
        printf("Erro em abrir arquivo log\n");
        system("pause");
        exit(1);
    }

    // a partir daqui nesta função main() o código não deve ser alterado
    int opcao;
    do {
        printf("\n\n 0-sair\n 1-registro entrada/saida\n 2-lista funcionarios\n 3-lista log\n");
        printf("\n Opcao: "); scanf(" %d",&opcao);
        switch(opcao) {
            case 1: registro(funcionarios,log); break;
            case 2: listagem_funcionarios(funcionarios); break;
            case 3: listagem_log(log); break;
            printf("\n\n\n");
        }
    } while (opcao != 0);

    fclose(funcionarios);
    fclose(log);
    return 0;
}