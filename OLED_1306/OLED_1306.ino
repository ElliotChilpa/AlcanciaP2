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

// ------- Asignamos Pines --------
const int senM1 = 2;
const int Led = 13;

// ------- Libreria OLED ----------
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

// ------- Variables para almacenar estado de sensor --------
int valorSenM1 = 0;

// -------- Variables de apoyo -----------
int count1 = 0;

void setup()
{
    // Activación de pantalla OLED
    display.begin(SSD1306_SWITCHCAPVCC); // Inicia el display OLED
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

    pinMode(senM1, INPUT); // Configuración de pin de entrada
    pinMode(Led, OUTPUT); // Configuramos salida LED

    delay(2000); // Demora de 3 segundos.
}

void loop() 
{
    display.clearDisplay(); // Borrar imagen en el OLED

    valorSenM1 = digitalRead(senM1); //Leemos el estado del sensor

    display.setTextSize(0.4);
    
    
    if (valorSenM1 == HIGH)
    {
        count1++;
        digitalWrite(Led, HIGH);
                // ---- Monedas de 1 ----
        
    }
    else
    {
        digitalWrite(Led, LOW);
    }

    // ---- Monedas de 1 ----
    display.setCursor(0,0); // Definir posición Columna (0) Fila (0)
    display.println("Monedas 1:"); // Carga la información al buffer
    
    display.setCursor(60,0); // Definir posición Columna (0) Fila (0)
    display.println(count1); // Carga la información al buffer

    // ---- Monedas de 2 ----
    display.setCursor(0,8); // Definir posición inicio texto Columna (0) Fila (15)
    display.println("Monedas 2:"); // Carga la información al buffer

    // ---- Monedas de 5 ----
    display.setCursor(0,16); // Definir posición inicio texto Columna (0) Fila (15)
    display.println("Monedas 5:"); // Carga la información al buffer

    // ---- Monedas de 10 ----
    display.setCursor(0,24); // Definir posición inicio texto Columna (0) Fila (15)
    display.println("Monedas 10:"); // Carga la información al buffer

    // ---- Monedas TOTALES ----
    display.setCursor(85, 0);
    display.println("Total");

    display.setCursor(90, 10);
    display.println("0");

    display.display(); // Actualiza display con datos en Buffer

    delay(100); // Demora de 2 segundos.
}
