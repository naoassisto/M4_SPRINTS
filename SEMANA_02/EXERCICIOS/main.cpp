#include <iostream>
#include <string>
using namespace std;

// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor

// 2 - Faça uma função que simule a leitura de um sensor lendo o 
// valor do teclado ao final a função retorna este valor

// 3 - Faça uma função que armazena uma medida inteira qualquer 
// em um vetor fornecido. Note que como C não possui vetores 
// nativos da linguagem, lembre-se que você precisa passar o 
// valor máximo do vetor assim como a última posição preenchida
// Evite também que, por acidente, um valor seja escrito em 
// uma área de memória fora do vetor



// 4 - Faça uma função que recebe um vetor com 4 posições que contém 
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção 
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a 
// segunda é esta maior distância.




// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e 
// retorna verdadeiro ou falso


// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", 
// "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno 
// para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja 
// enviado pelo usuário. 
//
//      Complete a função com a chamada das funções já criadas

int converteSensor(int x,int VMin,int VMax){
	
    VMax = VMax - VMin;
	x = x - VMin;
	int v = (x*100)/VMax;
	return v;

}

int leituraSensor(){
    
    int numero = 0;
    printf("digite um numero: ");
    cin >> numero;
    return numero;

}

int armazenaVetor(int posic, int x, int *vet, int tamanho){
    
    int *poV = vet;
	poV[tamanho];
	poV[posic] = x;
    return (posic + 1);

} 

const char *direcaoMenorCaminho(int *vet,int *dir){
	
    const char *direcao[] = {"Direita", "Esquerda", "Frente", "Tras"};
	int k = 0;
	for (int i = 0; i < 4; i++) {
		if (vet[i] > *dir){
			*dir = vet[i];
			k = i;
		
        }
	
    }
	// printf("O maior valor eh %d e o sentido eh %s",j,direcao[k]);
	return direcao[k];

}

int leComando(){
	
    int resposta = 0;
	printf("Deseja continuar? (1 - Sim / 2 - Não) \n");
	scanf("%d",&resposta);
	if (resposta == 1) {
		return 1;
	}
	
    else {
		return 0;
	
    }

}

int dirige(int *v,int maxv){
	
    int maxV = maxv;
	int *movVet = v;
	int posicV = 0;
	int dirigindo = 1;		
	while(dirigindo == 1){
		for (int i = 0; i < 4; i++)	{
			int medida = leituraSensor();/// .. Chame a função de de leitura da medida para a "Direita"
			medida = converteSensor(medida,0,830);
			posicV = armazenaVetor(posicV,medida,movVet,maxV);
		
        }
		;// Chame a função para armazenar a medida no vetor
        ///////////////////////////////////////////////////////////////////////////		
		// Repita as chamadas acima para a "Esquerda", "Frente", "Tras"
		// ................
		///////////////////////////////////////////////////////////////////////////
		
        dirigindo = leComando();		


	}
	
    return posicV;

}



// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado 
// na maior distância a cada movimento

void percorre(int *v,int tamPercorrido){		
	
    int *movVet = v;
	int mDire = 0;	
	for(int i = 0; i< tamPercorrido; i+=4){
		const char *direcao = direcaoMenorCaminho(&(movVet[i]),&mDire);
		printf("Movimentando para %s distancia = %i\n",direcao,mDire);
	
    }

}

int main(int argc, char** argv) {
	
    int maxV = 100;
	int movVet[maxV*4];
	int posicV = 0;
	posicV = dirige(movVet,maxV);
	percorre(movVet,posicV);
	
	return 0;

}