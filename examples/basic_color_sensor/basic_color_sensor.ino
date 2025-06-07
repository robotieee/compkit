#include <compkit.h>

compkit::color_sensor<2> sensorDireita(A0, 2, 3, 4);
size_t verde;
size_t amarelo;

void setup() {
  Serial.begin(9600);

  delay(3000);
  compkit::color_point leitura1;
  sensorDireita.read(leitura1);
  verde = sensorDireita.add_color_point(leitura1);

  Serial.print(verde);
  Serial.print(": ");
  compkit::print_color(leitura1);
  Serial.println("");

  delay(3000);
  compkit::color_point leitura2;
  sensorDireita.read(leitura2);
  amarelo = sensorDireita.add_color_point(leitura2);

  Serial.print(amarelo);
  Serial.print(": ");
  compkit::print_color(leitura2);
  Serial.println("");

  delay(3000);
}

void loop() {
  compkit::color_point leituraCorDireita;
  sensorDireita.read(leituraCorDireita);

  int corAtual = sensorDireita.closest_color(leituraCorDireita);
  if(corAtual == verde) {
    Serial.println("sensorDireita: Verde");
  } else if(corAtual == amarelo) {
    Serial.println("sensorDireita: Amarelo");
  }
  delay(100);
}
