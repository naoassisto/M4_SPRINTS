#define sensorLDR 4
#define BUZZ 2

#define Botao1 10
#define Botao2 9

#define L1 3
#define L2 18
#define L3 16
#define L4 7

#include <vector>



using namespace std; 

int o = 0;
vector< int > valores;

void setup() {
  Serial.begin(9600);

  pinMode(sensorLDR, INPUT);
  pinMode(BUZZ, OUTPUT);

  pinMode(Botao1, INPUT);
  pinMode(Botao2, INPUT);


  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
}

void loop() {
  if (digitalRead(Botao1) == HIGH) {
    delay(500);
    converteSensor();
    delay(1000);
  }

  if(digitalRead(Botao2) == HIGH) {
    delay(500);
    ALL_VALUES();
    delay(1000);
  }
}

void converteSensor() { 
  int binas[4];
  int divi = (4095 - 500)/16;
  int valor = analogRead(sensorLDR);
  int bina = valor/divi, bina2 = valor/divi;

  Serial.println(valor);   
  Serial.println(bina);   
   
  for(int i = 0; i < 4 ; i++)    
  {    
    binas[i] = bina % 2; 
    bina = bina/2;   
    Serial.println(binas[i]);
    valores.push_back(binas[i]);
  }
  valores.push_back(bina2);
  Serial.println(valores[4+o]);
  LED_BUZZ_ACTION(o);
} 

void ALL_VALUES() {

  int x = 0;
  Serial.println("Valores armazenados: ");
  delay(1000);

  for (int j = 0; j < valores.size()/4 ; j++){

    LED_BUZZ_ACTION(x);
    Serial.println("Seguinte: ");
    delay(1500);
    x += 5;
  }

  valores.clear();
  o = 0;
  Serial.println("Vet esvaziado");
}

void LED_BUZZ_ACTION (int count) {

  int Tones[15] = {150,400,2000,3500, 4000, 4699, 5000, 5500, 6000, 6272, 6800, 7000, 7200, 7500, 7902};

  if(valores[0 + count] == 1) {
    digitalWrite(L1, HIGH); 
  }
  if(valores[1 + count] == 1) {
    digitalWrite(L2, HIGH);
  }
  if(valores[2 + count] == 1) {
    digitalWrite(L3, HIGH);
  }
  if(valores[3 + count] == 1) {
    digitalWrite(L4, HIGH);  
  }

  tone(BUZZ,Tones[valores[4 + count]],1000);
  delay(1000);

  digitalWrite(L1 ,LOW);
  digitalWrite(L2 ,LOW);
  digitalWrite(L3 ,LOW);
  digitalWrite(L4 ,LOW);
  o += 5;
  
}