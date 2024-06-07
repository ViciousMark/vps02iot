// C++ code
//
int aberto = 4;
int fechado = 2;
int comando = 8;
int ligado = 12;
int direcao = 13;
int led1 = 10; // LED indicador 1
int led2 = 11; // LED indicador 2
int dir = 1;

void setup()
{
  pinMode(aberto, INPUT);
  pinMode(fechado, INPUT);
  pinMode(comando, INPUT);
  pinMode(ligado, OUTPUT);
  pinMode(direcao, OUTPUT);
  pinMode(led1, OUTPUT); // LED indicador 1
  pinMode(led2, OUTPUT); // LED indicador 2
  
  // Pisca os LEDs quando a simulação começa
  for(int i = 0; i < 3; i++) {
    delay(300);
    delay(300);
  }

  Serial.begin(9600);
}

void loop()
{
  int inicioEstado = digitalRead(aberto);
  int fimEstado = digitalRead(fechado);
  int com = digitalRead(comando);
  delay(400);

  if (inicioEstado == HIGH)
  {
    Serial.println("Aberto");
    digitalWrite(ligado, 0);
    dir = 1;
  }
  else if (fimEstado == HIGH)
  {
    Serial.println("Fechado");
    digitalWrite(ligado, 0);
    dir = 0;
  }
  else
  {
    digitalWrite(direcao, dir);
    if (com == HIGH)
    {
      if (dir == 1)
      {
        dir = 0;
        Serial.println("Portão fechando");
      }
      else
      {
        dir = 1;
        Serial.println("Portão abrindo");
      }
      digitalWrite(ligado, 1);
    }
  }

  // Pisca os LEDs independentemente do motor estar ligado
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(500);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  delay(500);
}
