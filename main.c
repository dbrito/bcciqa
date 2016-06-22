#include <stdio.h>
#include <math.h>
#define e 2.718281828459045235360287
#define pi 3.14159265358979323846

double p[9];
double q[9];
double oxigenio, coliformes, potencialHidrogenionico, demandaBioquimicaOxigenio, nitrato, fosfato, temperatura, turbidez, residuos;

/*Oxigenio Dissolvido (Peso 0.17)*/
double calculoOxigenio() {
	printf("Oxigenio Dissolvido: \n");
	scanf("%lf\n", &p[0]);	
	printf("Temperatura(ºC): \n");
	scanf("%lf\n", &p[6]);
	
	double saturacao, odx;	
	saturacao=(14.2*pow(e,-0.0212*p[6])-(0.0016*9.09*pow(e,-0.0264*p[6])))*(0.994-(0.0001042*860));
	odx=(q[0]/saturacao)*100;

	if(odx<=100) {
		double y1,y2,y3,y4,y5;
		y1=0.01396*odx+0.0873;
		y2=(pi/56.0)*(odx-27.0);
		y3=(pi/85.0)-(odx-15.0);
		y4=(odx-65.0)/10.0;
		y5=(65.0-odx)/10.0;
		q[0]=100*pow(sin(y1),2)-(2.5*sin(y2))-0.018*odx+6.86*sin(y3)+(12/pow(e,y4)+pow(e,y5));
	} else if(odx>100 && odx<=140) {
		q[0]= -0.00777142857142832*pow(odx,2)+(1.27854285714278*odx)+(49.8817148572);
	} else {
		q[0]=47.0;
	}
	oxigenio = pow(q[0], 0.17);
}

/*Coliformes Fecais (Peso 0.15)*/
double calculoColiformesFecais() {
	printf("Coliformes Fecais: \n");
	scanf("%lf\n", &p[1]);	
	if (p[1] <= 100000) {
		q[1] = 98.24034 - 34.7145 * (log10(p[1])) + 2.614267 * pow(log10(p[1]), 2) + 0.107821 * pow(log10(p[1]), 3); 
	} else {
		q[1] = 3.0;
	}
	coliformes = pow(q[1], 0.15);
}	

/*Potencial Hidrogenionico (Peso 0.12)*/
double CalculoPotencialHidrogenionico() {
	printf("Potencial Hidrogenionico(pH): \n");
	scanf("%lf\n", &p[2]);
	if (p[2] <= 2) {
		q[2] =  2.0;
	} else if (p[2] > 2 && p[2] <= 6.9) {
		q[2] = -37.1085 + 41.91277 * p[2] - 15.7043 * (pow(p[2], 2)) + 2.417486 * (pow(p[2], 3)) - 0.091252 * (pow(p[2], 4)); 
	} else if (p[2] > 6.9 && p[2] <= 7.1) {
		q[2] = -4.69365 - 21.4593 * p[2] - 68.4561 * (pow(p[2], 2)) + 21.638886 * (pow(p[2], 3)) - 1.59165 * (pow(p[2], 4));
	} else if (p[2] > 7.1 && p[2] <= 12) {
		q[2] = -7698.19 + 3262.031 * p[2] - 499.494 * (pow(p[2], 2)) + 33.1551 * (pow(p[2], 3)) - 0.810613 * (pow(p[2], 4));
	} else {
		q[2] = 3.0; 
	}
	potencialHidrogenionico = pow(q[2], 0.12);
}	

/*Demanda Bioquímica de Oxigênio (Peso 0.10)*/
double calculoDemandaBioquimicaOxigenio() {
	printf("Demanda Bioquimica de Oxigenio: \n");
	scanf("%lf\n", &p[3]);
	if (p[3] <= 30) {
		q[3] =  100.9571 - 10.7121 * p[3] + 0.49544 * (pow(p[3], 2)) - 0.011167 * (pow(p[3], 3)) + 0.0001 * (pow(p[3], 4));
	} else {
		q[3] = 2.0; 
	}
	demandaBioquimicaOxigenio = pow(q[3], 0.10);
}	

/*Nitratos (Peso 0.10)*/
double calculoNitrato() {
	printf("Nitratos: \n");
	scanf("%lf\n", &p[4]);
	if (p[4] <= 10) {
		q[4] = -5.1 * p[4] + 100.17;
	} else if (p[4] > 10 && p[4] <= 60) {
		q[4] = -22.853 * (log(p[4])) + 101.18;
	} else if (p[4] > 60 && p[4] <=90) {
		q[4] = 10000000000 * (pow(p[4], -5.1161));
	} else if (p[4] > 90) {
		q[4] = 1.0;
	}
	nitrato = pow(q[4], 0.10);
}


/*Fosfatos (Peso 0.10)*/
double calculoFosfato() {
	printf("Fosfatos: \n");
	scanf("%lf\n", &p[5]);
	if (p[5] <= 10) {
		q[5] = 79.7 * (pow((p[5] + 0.821), -1.15));
	} else if (p[5] > 10) {
		q[5] = 5.0;
	}
	fosfato = pow(q[5], 0.10);
}

/*Variação de Temperatura (Peso 0.10)*/
double calculoTemperatura() {
	q[6] = 93.0;
	temperatura = pow(q[6], 0.10);
}

/*Turbidez (Peso 0.08)*/
double calculoTurbidez() {
	printf("Turbidez: \n");
	scanf("%lf\n", &p[7]);
	if(p[7] <= 100) {
		q[7] = (90.37*pow(e,-0.0169*p[7])) - 15*cos(0.0571*(p[7] - 30))+10.22*pow(e,-0.231*p[7])-0.8;
	} else {
		q[7] = 5.0;
	}
	turbidez = pow(q[7], 0.08);
}

/*Residuos Totais (Peso 0.08)*/
double calculoResiduos() {
	printf("Residuos Totais: \n");
	scanf("%lf\n", &p[8]);
	if(p[8]<=500) {
		q[8] = 133.17*pow(e,-0.0027*p[8])-53.17*pow(e,-0.0141*p[8])+(-6.2*pow(e,-0.00462*p[8]))*sin(0.0146*p[8]);
	} else {
		q[8] = 30.0;
	}
	residuos = pow(q[8], 0.08);
}

/*Calculo do IQA*/
double calculoIQA() {
	double iqa=0;
	iqa = oxigenio * coliformes * potencialHidrogenionico * demandaBioquimicaOxigenio * nitrato * fosfato * temperatura * turbidez * residuos;
	printf("\n\nSeu IQA é %.10f\nA qualidade da água é: ",iqa);
	if (iqa <= 25) printf("Muito Ruim\n");
	else if (iqa > 25 && iqa <= 50) printf("Ruim\n");
	else if (iqa > 50 && iqa <= 70) printf("Médio\n");
	else if (iqa > 70 && iqa <= 90) printf("Boa\n");
	else printf("Muito Boa\n");
}

int main() {
	calculoOxigenio();
	calculoColiformesFecais();
	CalculoPotencialHidrogenionico();
	calculoDemandaBioquimicaOxigenio();
	calculoNitrato();
	calculoFosfato();
	calculoTemperatura();
	calculoTurbidez();
	calculoResiduos();
	calculoIQA();
	return 0;
}
