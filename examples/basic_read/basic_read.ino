#include <compkit.h>

// Variável com algum tom de verde qualquer
color_point verdeCali  = {120, 600, 120, 100};
// Variável com algum tom de branco qualquer
color_point brancoCali = {600, 600, 600, 100};

// Cria sensor de cor dentro do código
color_sensor<2> sensorCor(A0, 2, 3, 4);

// Guarda a representação de cada cor em forma de um número
// A função de comparação retornará o resultado na forma deste número da cor
int verde;
int branco;

void setup() {
  // Adiciona uma cor calibrada na lista de resultados possíveis
  verde  = sensorCor.add_color_point(verdeCali);  // Calibra o verde
  branco = sensorCor.add_color_point(brancoCali); // Calibra o branco
}

void loop() {
  // Lê o sensor de cor e armazena na variável leituraCor
  color_point leituraCor;
  sensorCor.read(leituraCor);

  // Compara o valor de leituraCor com as cores calibradas
  // Retorna qual cor calibrada é mais próxima da leitura
  // Guarda o resultado em corAtual
  int corAtual = sensorCor.closest_color(leituraCor);

  // Se corAtual for igual o número da cor verde
  if(corAtual == verde) {
    Serial.println("sensorDireita: Verde");
  }
  // Se não, se corAtual for igual o número da cor branca
  else if(corAtual == branco) {
    Serial.println("sensorDireita: Amarelo");
  }
}