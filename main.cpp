#include <iostream>
#include <iomanip>
#include "LeituraASM.h"

//variaveis globais
int PC = 0; //linha 1
int contInstr = 0;

int main() {

    LeituraASM arquivo("/home/felipe/Documentos/teste.txt");

    cout << setw(7) << "Fetch" << setw(14) << "Decode" << setw(14) << "Execute" << setw(14) << "Memory" << setw(14) << "WriteBack" << endl;
    cout << setw(7) << "-----------------------------------------------------------------" << endl;

    while (contInstr < 8) {
        arquivo.fetch(PC,arquivo);
        cout << setw(7) << arquivo.passo_search.opCode << setw(14) << arquivo.passo_decode.opCode << setw(14) << arquivo.passo_execute.opCode << setw(14) << arquivo.passo_memory.opCode << setw(14) << arquivo.passo_register.opCode << endl;
        cout << setw(7) << "-----------------------------------------------------------------" << endl;
        arquivo.WriteBack();
        arquivo.memoria();
        arquivo.execute();
        arquivo.decode();
        contInstr++;
        PC++;
    }

    cout << "Instrucoes executadas: " << contInstr/2 << endl;

    for(int i = 0; i <= 22; i++){
        cout << "R[" << i << "] - " << arquivo.getR()[i] << endl;
    }

}