const int senM1 = 2; // Define el pin del botón
const int senM2 = 3; // Define el pin del botón
const int senM5 = 4; // Define el pin del botón
const int senM10 = 5; // Define el pin del botón
const int ledPin = 13; // Define el pin del LED

int valorSenM1 = 0; // Variable para almacenar el estado del botón
int valorSenM2 = 0;
int valorSenM5 = 0;
int valorSenM10 = 0;

int valor1 = 0; // Variable para almacenar el valor a imprimir
int valor2 = 0; // Variable para almacenar el valor a imprimir
int valor5 = 0; // Variable para almacenar el valor a imprimir
int valor10 = 0; // Variable para almacenar el valor a imprimir

int casoS = 0;

 
void setup() {
  pinMode(senM1, INPUT); // Configura el pin del botón como entrada
  pinMode(senM2, INPUT);
  pinMode(senM5, INPUT);
  pinMode(senM10, INPUT);

  pinMode(ledPin, OUTPUT); // Configura el pin del LED como salida

  Serial.begin(9600);
}

void loop() 
{
  valorSenM1 = digitalRead(senM1); // Lee el estado del botón
  valorSenM2 = digitalRead(senM2);
  valorSenM5 = digitalRead(senM5);
  valorSenM10 = digitalRead(senM10);

  if (valorSenM1 == HIGH)
  {
    casoS = 1;
    //delay(200);
  }
  else if (valorSenM2 == HIGH)
  {
    casoS = 2;
    //delay(200);
  }
  else if (valorSenM5 == HIGH)
  {
    casoS = 3;
    //delay(200);
  }
  else if (valorSenM10 == HIGH)
  {
    casoS = 4;
    //delay(200);
  }
  
  
  switch (casoS)
  {
  case 1:
    digitalWrite(ledPin, HIGH); // Enciende el LED
    valor1++; // Incrementa el valor

    Serial.print("Valor Moneda 1: "); // Imprime un mensaje

    Serial.println(valor1); // Imprime el valor
    
    casoS = 0;
    delay(200);
    break;
  case 2:
    valor2 = valor2+2; // Incrementa el valor

    Serial.print("Valor Moneda 2: "); // Imprime un mensaje

    Serial.println(valor2); // Imprime el valor

    casoS = 0;
    delay(200);
    break;
  
  default:
    digitalWrite(ledPin, LOW); // Apaga el LED
    break;
  }
}




/*
void encenderLED(int pin) {
  digitalWrite(pin, HIGH);
}

void apagarLED(int pin) {
  digitalWrite(pin, LOW);
}

void setup() {
  pinMode(13, OUTPUT); // Define el pin del LED como salida
}

void loop() {
  encenderLED(13); // Enciende el LED
  delay(1000); // Espera 1 segundo
  apagarLED(13); // Apaga el LED
  delay(1000); // Espera 1 segundo
}*/

