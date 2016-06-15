#include <stdio.h>
#include <stdlib.h>

//Oxigênio Dissolvido, peso 0,17
int oxigenio() {
	printf("Oxigênio dissolvido (mg/L)\n");
}

//Coliformes Fecais, peso 0,15
int coliformes() {
	printf("Coliformes\n");
}

//Potencial Hidrogeniônico, peso 0,12
int potencialHidrogenionico() {
	printf("Potencial Hidrogeniônico\n");
}

//Demanda Bioquimica de Oxigênio, peso 0,10
int demandaOxigenio() {
	printf("Demanda Bioquimica de Oxigênio\n");
}

//Temperatura, peso 0,10
int temperatura() {
	printf("Temperatura\n");
}

//Nitrogênio Total, peso 0,10
int nitrogenio() {
	printf("Nitrogênio\n");
}

//Fósforo Total, peso 0,10
int fosforo() {
	printf("Fósforo\n");
}

//Turbidez, peso 0,08
int turbidez() {
	printf("Turbidez\n");
}

//Resíduo Total, peso 0,08
int residuos() {
	printf("Resíduo Total\n");
}

//Calcula o Indice de Qualidade da Água
int IQA() {
	printf("IQA\n");
}

int main() {
  	oxigenio();
  	coliformes();
  	potencialHidrogenionico();
  	demandaOxigenio();
  	temperatura();
  	nitrogenio();
  	fosforo();
  	turbidez();
  	residuos();
  	IQA();
  	return 0;
}
