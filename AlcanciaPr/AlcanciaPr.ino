// -------- Libreria para guardar los datos -------
#include <EEPROM.h> // Libreria para almacenar datos en EEPROM

// ------- Librerias Para Pantalla OLED -----
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

// ------- Pines para nuestra pantalla OLED ---
#define OLED_MOSI 9
#define OLED_CLK 10
#define OLED_DC 11
#define OLED_CS 12
#define OLED_RESET 13

// ------------ Asignamos Botones a utilizar ----------------
const int senM1 = 3; // Define el pin del botón
const int senM2 = 4; // Define el pin del botón
const int senM5 = 5; // Define el pin del botón
const int senM10 = 6; // Define el pin del botón
//const int ledPin = 13; // Define el pin del LED
const int senRESET = 7; // Definimos el pin para resetear

// ------------ Asignamos Botones a utilizar ----------------
//#define senM1 2 // Define el pin del botón
//#define senM2 3 // Define el pin del botón
//#define senM5 4 // Define el pin del botón
//#define senM10 5 // Define el pin del botón
//const int ledPin = 13; // Define el pin del LED
//#define senRESET 7 // Definimos el pin para resetear

// ------- Libreria OLED ----------
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

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


// -------------- Funcion para imprimir Serial ------------
void imprimirValorSerial(int v1, int v2, int v5, int v10) 
{
    int totalAC = v1 + v2 + v5 + v10;
    Serial.println("-------------"); // Imprime un mensaje
////////////////////////////
    //Serial.print("Valor Moneda 1: "); // Imprime un mensaje
    //Serial.println(v1); // Imprime el valor
    Serial.print("Valor Moneda 1 EEPROM:");
    Serial.println(EEPROM.get(dir1, valor1));
///////////////////////////
    //Serial.print("Valor Moneda 2: "); // Imprime un mensaje
    //Serial.println(v2); // Imprime el valor
    Serial.print("Valor Moneda 2 EEPROM:");
    Serial.println(EEPROM.get(dir2, valor2));
///////////////////////////
    //Serial.print("Valor Moneda 5: "); // Imprime un mensaje
    //Serial.println(v5); // Imprime el valor
    Serial.print("Valor Moneda 5 EEPROM:");
    Serial.println(EEPROM.get(dir5, valor5));
////////////////////////
    //Serial.print("Valor Moneda 10: "); // Imprime un mensaje
    //Serial.println(v10); // Imprime el valor
    Serial.print("Valor Moneda 10 EEPROM:");
    Serial.println(EEPROM.get(dir10, valor10));

    Serial.print("Total: ");
    Serial.println(totalAC);
}

// -------------- Funcion para imprimir ------------
void imprimirValorOLED(int v1, int v2, int v5, int v10) 
{
  int totalAC = v1 + v2 + v5 + v10;

  display.clearDisplay(); // Borrar imagen en el OLED
  display.setTextSize(0.4);

  ///////////////////////////////
  // ---- Monedas de 1 ----
  display.setCursor(0,0); // Definir posición Columna (0) Fila (0)
  display.println("Monedas 1:"); // Carga la información al buffer

  display.setCursor(60,0); // Definir posición Columna (0) Fila (0)
  display.println(v1); // Carga la información al buffer

  // ---- Monedas de 2 ----
  display.setCursor(0,8); // Definir posición inicio texto Columna (0) Fila (15)
  display.println("Monedas 2:"); // Carga la información al buffer

  display.setCursor(60,8); // Definir posición Columna (0) Fila (0)
  display.println(v2); // Carga la información al buffer

  // ---- Monedas de 5 ----
  display.setCursor(0,16); // Definir posición inicio texto Columna (0) Fila (15)
  display.println("Monedas 5:"); // Carga la información al buffer

  display.setCursor(60,16); // Definir posición Columna (0) Fila (0)
  display.println(v5); // Carga la información al buffer
  // ---- Monedas de 10 ----
  display.setCursor(0,24); // Definir posición inicio texto Columna (0) Fila (15)
  display.println("Monedas 10:"); // Carga la información al buffer

  display.setCursor(65,24); // Definir posición Columna (0) Fila (0)
  display.println(v10); // Carga la información al buffer

  // ---- Monedas TOTALES ----
  display.setCursor(85, 0);
  display.println("Total");

  display.setCursor(90, 10);
  display.println(totalAC);

  display.display(); // Actualiza display con datos en Buffer
}

// -------------- Funcion para imprimir ------------
void imprimirPress() 
{
  // Activación de pantalla OLED
  //display.begin(SSD1306_SWITCHCAPVCC); // Inicia el display OLED
  display.clearDisplay(); // Borrar imagen en el OLED
  display.setTextSize(0.5); // Tamaño del texto
  display.setTextColor(WHITE); // Definir color del texto (WHITE-BLACK)

  //---- Presentación OLED -----
  display.setCursor(25,0); // Definir posición Columna (25) Fila (15)
  display.println("Alcancia"); // Carga la información al buffer
  // ---- Elliot ----
  display.setCursor(0,8); // Definir posición inicio texto Columna (0) Fila (15)
  display.println("Elliot Chilpa"); // Carga la información al buffer
  // ---- Edgar ----
  display.setCursor(0,16); // Definir posición inicio texto Columna (0) Fila (15)
  display.println("Edgar Yanez"); // Carga la información al buffer
  // ---- Eduardo Barquera ----
  display.setCursor(0,24); // Definir posición inicio texto Columna (0) Fila (15)
  display.println("Eduardo Barquera"); // Carga la información al buffer

  display.display(); // Actualiza display con datos en Buffer
  delay(2000);
}

 
void setup() {
  // Activación de pantalla OLED
  display.begin(SSD1306_SWITCHCAPVCC); // Inicia el display OLED
  //display.clearDisplay(); // Borrar imagen en el OLED
  //display.setTextSize(0.5); // Tamaño del texto
  //display.setTextColor(WHITE); // Definir color del texto (WHITE-BLACK)
  imprimirPress();

  
  // --------- Setup para configurar Sensores de entrada --------------
  pinMode(senM1, INPUT); 
  pinMode(senM2, INPUT);
  pinMode(senM5, INPUT);
  pinMode(senM10, INPUT);
  pinMode(senRESET, INPUT);
  //pinMode(ledPin, OUTPUT); // Configura el pin del LED como salida

  // ---------- SETUP  EEPROM -------------------------//
  valorSenRESET = digitalRead(senRESET);
  delay(100);
  if (valorSenRESET == HIGH) // Modificar conado tengamos el Switch
  {
    // ---------- SETUP para guardar datos EEPROM 0-------------------------
    EEPROM.put(dir1, 0);
    EEPROM.put(dir2, 0); 
    EEPROM.put(dir5, 0); 
    EEPROM.put(dir10, 0); 
  }
  else if (valorSenRESET == LOW)
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
    //digitalWrite(ledPin, HIGH); // Enciende el LED
    valor1 = valor1+1; // Incrementa el valor
    
    EEPROM.put(dir1, valor1);
    
    imprimirValorSerial(valor1, valor2, valor5, valor10);
    imprimirValorOLED(valor1, valor2, valor5, valor10);

    casoS = 0;
    delay(200);
    break;
  case 2:
    valor2 = valor2+2; // Incrementa el valor
    
    EEPROM.put(dir2, valor2);
    imprimirValorSerial(valor1, valor2, valor5, valor10);
    imprimirValorOLED(valor1, valor2, valor5, valor10);

    casoS = 0;
    delay(200);
    break;
  case 3:
    valor5 = valor5+5; // Incrementa el valor
    
    EEPROM.put(dir5, valor5);
    imprimirValorSerial(valor1, valor2, valor5, valor10);
    imprimirValorOLED(valor1, valor2, valor5, valor10);
   
    casoS = 0;
    delay(200);
    break;
  case 4:
    valor10 = valor10+10; // Incrementa el valor
    
    EEPROM.put(dir10, valor10);
    imprimirValorSerial(valor1, valor2, valor5, valor10);
    imprimirValorOLED(valor1, valor2, valor5, valor10);
 
    casoS = 0;
    delay(200);
    break;
  
  default:
    //digitalWrite(ledPin, LOW); // Apaga el LED
      break;
  }
}
