#include <LiquidCrystal.h>
 //variaveis de medições
 float vazao;
 float litros = 0;
 float mililitros = 0;
 int contapulso;
 
 //varaiaveis para calculos de valor
 float dinheiro;
 
 //variaveis para calculo de tempo 
 int segundos = 0;
 int minutos = 0;
 int horas = 0;
 int dias = 0;

 LiquidCrystal lcd(12, 11, 6 , 5, 4, 3);// 1 = GND, 2 = VCC, 3 = resistor e GND, 4 = 12D, 5 = GND, 6 = 11D, 11 = 6D, 12 = 5D, 13 = 4D, 14 = 3D, 15 = 5V, 16 = GND;
 void setup() {
  pinMode(2, INPUT);
  lcd.begin(16,2);
  attachInterrupt (0, interrupcao, RISING);
  }

 void interrupcao (){
 contapulso++;
  }
void loop() {
  sei();
  contapulso = 0;
  delay(1000); 
  cli();
  segundos++;
 
  vazao = (contapulso / 5.5);
  dinheiro = (litros*0.002238);
  lcd.setCursor(0, 0);
  lcd.print("R$ ");
  lcd.print(dinheiro, 2);
  lcd.print(" ");

  lcd.print(litros ,2);
  lcd.print("L ");
  
//escrita de tempo 
  lcd.setCursor(0, 1);
  lcd.print(dias);
  lcd.print(":");
  lcd.print(horas);
  lcd.print(":");
  lcd.print(minutos);
  lcd.print(":");
  lcd.print(segundos);
  lcd.print(" Time");

mililitros = (vazao / 60);
litros = (litros + mililitros);

//medida de tempo
if (segundos == 60){
  minutos++;
  segundos = 0;
}
if (minutos == 60) {
  horas++;
  minutos = 0;
}
if (horas == 24){
  dias++;
  horas = 0;
}
if (dias == 30){
    
}
  }
