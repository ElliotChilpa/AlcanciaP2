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

// ------- Pines para sensores ----


Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

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
    // ---- Monedas de 5 ----
    display.setCursor(0,16); // Definir posición inicio texto Columna (0) Fila (15)
    display.println("Edgar Yanez"); // Carga la información al buffer
    // ---- Monedas de 10 ----
    display.setCursor(0,24); // Definir posición inicio texto Columna (0) Fila (15)
    display.println("Eduardo Barquera"); // Carga la información al buffer

    display.display(); // Actualiza display con datos en Buffer
    delay(3000); // Demora de 3 segundos.
}

void loop() 
{
    display.clearDisplay(); // Borrar imagen en el OLED

    if ()
    {
        /* code */
    }
    
    display.setTextSize(0.4);
    // ---- Monedas de 1 ----
    display.setCursor(0,0); // Definir posición Columna (0) Fila (0)
    display.println("Monedas 1:"); // Carga la información al buffer
    // ---- Monedas de 2 ----
    display.setCursor(0,8); // Definir posición inicio texto Columna (0) Fila (15)
    display.println("Monedas 2:"); // Carga la información al buffer
    // ---- Monedas de 5 ----
    display.setCursor(0,16); // Definir posición inicio texto Columna (0) Fila (15)
    display.println("Monedas 5:"); // Carga la información al buffer
    // ---- Monedas de 10 ----
    display.setCursor(0,24); // Definir posición inicio texto Columna (0) Fila (15)
    display.println("Monedas 10:"); // Carga la información al buffer

    display.display(); // Actualiza display con datos en Buffer
    delay(2000); // Demora de 2 segundos.
}
