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

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void setup(){
display.begin(SSD1306_SWITCHCAPVCC); // Inicia el display OLED
display.clearDisplay(); // Borrar imagen en el OLED
display.setTextSize(1); // Tamaño del texto
display.setTextColor(WHITE); // Definir color del texto (WHITE-BLACK)
// display.setCursor(25,15); // Definir posición Columna (25) Fila (15)
// display.println("OLED SSD1306"); // Carga la información al buffer
display.display(); // Actualiza display con datos en Buffer
delay(3000); // Demora de 3 segundos.
}

void loop() {
 display.clearDisplay(); // Borrar imagen en el OLED
 display.setTextSize(1);
 display.setCursor(0,0); // Definir posición Columna (0) Fila (0)
 display.println("Robotics Space NV"); // Carga la información al buffer
 display.setCursor(0,10); // Definir posición inicio texto Columna (0) Fila (15)
 display.println("Prueba de la pantalla"); // Carga la información al buffer
 display.display(); // Actualiza display con datos en Buffer
 delay(2000); // Demora de 2 segundos.
}
