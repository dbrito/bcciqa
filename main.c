
#include <stdio.h>
#include <stdlib.h>

main() {
  	float media[4], peso[4], mediafim=0, totpeso=0, totmedia=0;
  	int nota=1;
  	for(int i=0; i < 4; i++) {
		  printf("Digite a Nota %d: \n", nota);
		  scanf("%f", &media[i]);
		  printf("Digite o peso da Nota %d: \n", nota);
		  scanf("%f", &peso[i]);
		  totmedia= totmedia+(media[i]*peso[i]);
		  totpeso= totpeso+peso[i];
		  nota++;
  	}
  	mediafim= totmedia/totpeso;
  	printf("Média Final %.2f\n", mediafim);
}
