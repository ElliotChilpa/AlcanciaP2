// -------- Libreria para guardar los datos -------
#include <EEPROM.h> // Libreria para almacenar datos en EEPROM

// ------------ Asignamos Botones a utilizar ----------------
const int senM1 = 2; // Define el pin del botón
const int senM2 = 3; // Define el pin del botón
const int senM5 = 4; // Define el pin del botón
const int senM10 = 6; // Define el pin del botón
const int ledPin = 13; // Define el pin del LED
const int senRESET = 7; // Definimos el pin para resetear

// ------------ Variables para almacenar el estado del boton ----------
int valorSenM1 = 0;
int valorSenM2 = 0;
int valorSenM5 = 0;
int valorSenM10 = 0;
int valorSenRESET = 0;

// ------------ Variable para almacenar el valor a imprimir ----------
int valor1 = 0; // Variable para almacenar el valor a imprimir
int valor2 = 0; // Variable para almacenar el valor a imprimir
int valor5 = 0; // Variable para almacenar el valor a imprimir
int valor10 = 0; // Variable para almacenar el valor a imprimir

// ----------- Direcciones para Almacenar en EEPROM -------------------
int dir1 = 0;
int dir2 = 3;
int dir5 = 6;
int dir10 = 9;

// ----------- Variables de apoyo ----------------------
int casoS = 0;
//int totalDi = 0;


// -------------- Funcion para imprimir ------------
void imprimirValor(int v1, int v2, int v5, int v10) 
{
    int totalAC = v1 + v2 + v5 + v10;
    Serial.println("-------------"); // Imprime un mensaje
////////////////////////////
    Serial.print("Valor Moneda 1: "); // Imprime un mensaje
    Serial.println(v1); // Imprime el valor
    //Serial.print("Valor Moneda 1 EEPROM:");
    //Serial.println(EEPROM.get(dir1, v1));
///////////////////////////
    Serial.print("Valor Moneda 2: "); // Imprime un mensaje
    Serial.println(v2); // Imprime el valor
    //Serial.print("Valor Moneda 2 EEPROM:");
    //Serial.println(EEPROM.get(dir2, v2));
///////////////////////////
    Serial.print("Valor Moneda 5: "); // Imprime un mensaje
    Serial.println(v5); // Imprime el valor
    //Serial.print("Valor Moneda 5 EEPROM:");
    //Serial.println(EEPROM.get(dir5, v5));
////////////////////////
    Serial.print("Valor Moneda 10: "); // Imprime un mensaje
    Serial.println(v10); // Imprime el valor
    //Serial.print("Valor Moneda 10 EEPROM:");
    //Serial.println(EEPROM.get(dir10, v10));

    Serial.print("Total: ");
    Serial.println(totalAC);
}

 
void setup() {
  // --------- Setup para configurar Sensores de entrada --------------
  pinMode(senM1, INPUT); 
  pinMode(senM2, INPUT);
  pinMode(senM5, INPUT);
  pinMode(senM10, INPUT);
  pinMode(senRESET, INPUT);

  pinMode(ledPin, OUTPUT); // Configura el pin del LED como salida

  // ---------- SETUP  EEPROM -------------------------//
  valorSenRESET = digitalRead(senRESET);
  delay(100);
  if (valorSenRESET == LOW) // Modificar conado tengamos el Switch
  {
    // ---------- SETUP para guardar datos EEPROM 0-------------------------
    EEPROM.put(dir1, 0);
    EEPROM.put(dir2, 0); 
    EEPROM.put(dir5, 0); 
    EEPROM.put(dir10, 0); 
  }
  else if (valorSenRESET == HIGH)
  {
    // ---------- SETUP  EEPROM ya mas de una vez -------------------------//
    valor1 = EEPROM.get(dir1, valor1); // Aquí asignamos el valor que tenga EEPROM a valor
    valor2 = EEPROM.get(dir2, valor2);
    valor5 = EEPROM.get(dir5, valor5);
    valor10 = EEPROM.get(dir10, valor10);
  }

    Serial.begin(9600);
}

void loop() 
{
  valorSenM1 = digitalRead(senM1); // Lee el estado del botón
  valorSenM2 = digitalRead(senM2);
  valorSenM5 = digitalRead(senM5);
  valorSenM10 = digitalRead(senM10);

  if (valorSenM1 == LOW)
  {
    casoS = 1;
    //delay(200);
  }
  else if (valorSenM2 == LOW)
  {
    casoS = 2;
    //delay(200);
  }
  else if (valorSenM5 == LOW)
  {
    casoS = 3;
    //delay(200);
  }
  else if (valorSenM10 == LOW)
  {
    casoS = 4;
    //delay(200);
  }
  
  
  switch (casoS)
  {
  case 1:
    digitalWrite(ledPin, HIGH); // Enciende el LED
    valor1 = valor1+1; // Incrementa el valor
    //totalDi+valor1;
    EEPROM.put(dir1, valor1);
    imprimirValor(valor1, valor2, valor5, valor10);

    casoS = 0;
    delay(200);
    break;
  case 2:
    valor2 = valor2+2; // Incrementa el valor
    //totalDi = +valor2;
    EEPROM.put(dir2, valor2);
    imprimirValor(valor1, valor2, valor5, valor10);

    casoS = 0;
    delay(200);
    break;
  case 3:
    valor5 = valor5+5; // Incrementa el valor
    //totalDi = +valor5;
    EEPROM.put(dir5, valor5);
    imprimirValor(valor1, valor2, valor5, valor10);
   
    casoS = 0;
    delay(200);
    break;
  case 4:
    valor10 = valor10+10; // Incrementa el valor
    //totalDi = +valor10;
    EEPROM.put(dir10, valor10);
    imprimirValor(valor1, valor2, valor5, valor10);
 
    casoS = 0;
    delay(200);
    break;
  
  default:
    digitalWrite(ledPin, LOW); // Apaga el LED
    //totalDi = valor1 + valor2 + valor5 + valor10;
      break;
  }

}
