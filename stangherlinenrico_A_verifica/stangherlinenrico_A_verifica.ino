int pinLedRosso = 10;
int pinLedGiallo = 8;
int pinLedBianco = 6;
int pinLedVerde = 4;
int ciclo = 0;
int durataMin = 0;
int durataMax = 0;
int tmpSpento = 0;
bool minMax = true;
bool trueCiclo = true;

void infoLed(){
  while (trueCiclo) {
  Serial.print("Quanti cicli vuoi far eseguire?\n");
  while(Serial.available() == 0);
  ciclo = Serial.readString().toInt();
  Serial.print("Ho ricevuto "); Serial.print(ciclo); Serial.print(" cicli.\n");
  if (ciclo > 0)
    trueCiclo = false;
  else
    Serial.println("I cicli devono essere maggiori di 0");
  }
  
  while (minMax)
  {
    Serial.print("Qual è il tempo minimo di spegnimento dei led? (millisecondi)\n");
  while(Serial.available() == 0);
  durataMin = Serial.readString().toInt();
  Serial.print("Ho ricevuto "); Serial.print(durataMin); Serial.print(" millisecondi.\n");

  Serial.print("Qual è il tempo massimo di spegnimento dei led? (millisecondi)\n");
  while(Serial.available() == 0);
  durataMax = Serial.readString().toInt();
  Serial.print("Ho ricevuto "); Serial.print(durataMax); Serial.print(" millisecondi.\n");
  Serial.println();
  if (durataMin < durataMax and durataMin >= 0)
    minMax = false;
  else
    Serial.print("Il numero minimo deve essere maggiore o uguale a 0 e minore del numero massimo\n");
  }
  tmpSpento = random(durataMin, durataMax);
  trueCiclo = true; minMax = true;
}

void accendeAll() {
  digitalWrite(pinLedRosso, HIGH);
  digitalWrite(pinLedGiallo, HIGH);
  digitalWrite(pinLedBianco, HIGH);
  digitalWrite(pinLedVerde, HIGH);
}

void esegui() {
  accendeAll();
  digitalWrite(pinLedRosso, LOW);
  digitalWrite(pinLedGiallo, LOW);
  delay(tmpSpento);
  accendeAll();
  digitalWrite(pinLedBianco, LOW);
  digitalWrite(pinLedVerde, LOW);
  delay(tmpSpento);
  accendeAll();
}

void setup() {
  pinMode(pinLedRosso, OUTPUT);
  pinMode(pinLedGiallo, OUTPUT);
  pinMode(pinLedBianco, OUTPUT);
  pinMode(pinLedVerde, OUTPUT);
  Serial.begin(9600);
  accendeAll();
  infoLed();
}

void loop() {
  for (int i = 0; i < ciclo; i++)
  {
    esegui();
  }
  setup();
}
