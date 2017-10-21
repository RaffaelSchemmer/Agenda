#ifndef Fun__hpp // Caso não esteja definido Fun_hpp ele executa o codigo
#define Func_hpp // Define Func_hpp
#include<string>
using namespace std;   
string lista_estado_civil(int);  // Prototipo da Funcao Lista Estado Civil
string lista_sexo(int); // Prototipo da Funcao Lista Sexo
void cadastra_contato(int,string,string,string,string,string,string,string,int,int); // Prototipo da Funcao Cadastra Contato
int excluir_contato(int,char vet[],string); // Prototipo da Funcao Exclui Contato
int lista_contato(char vet[],int); // Prototipo da Funcao Lista Contato
int procura_nome(char vet[],string,int *); // Prototipo da Funcao Procura Nome
int procura_estado_civil(char vet[],int,int); // Prototipo da Funcao Procura Estado Civil
int procura_sexo(char vet[],int,int); // Prototipo da Funcao Procura Sexo
int procura_sexo_estado_civil(char vet[],int,int,int); // Prototipo da Funcao Procura Sexo e Estado Civil
#endif
