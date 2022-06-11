
/*****************************************************************************/
/* Arquivo: bmp280test.ino | Versão 1.0 | Ano: 2022                          */
/*---------------------------------------------------------------------------*/
/* Autor: Prof. Me. Lucas Kriesel Sperotto                                   */
/*---------------------------------------------------------------------------*/
/* E-mail: sperotto@unemat.br                                                */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/* Descrição: Código que demonstra como ligar dois sensores BMP280 no        */
/* ESP32 usando protocolo SPI                                                */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*    Compilador:                                                            */ 
/*    IDE: Arduino v 1.8.19                                                  */
/*                                                                           */
/*****************************************************************************/

/****************************/
/* Inclusão de bibliotecas  */
/****************************/
#include <Adafruit_BMP280.h>

/***********************************/
/* Definição dos pinos de ligação  */
/***********************************/
#define BMP_SCK  (18)
#define BMP_MISO (19)
#define BMP_MOSI (23)
#define BMP_CS_A  (4) //BMP280 A
#define BMP_CS_B  (5) //BMP280 B

/***********************************/
/* Definição dos pinos de ligação  */
/***********************************/
Adafruit_BMP280 bmp_A(BMP_CS_A, BMP_MOSI, BMP_MISO,  BMP_SCK);// SPI
Adafruit_BMP280 bmp_B(BMP_CS_B, BMP_MOSI, BMP_MISO,  BMP_SCK);// SPI

/***********************************************/
/* Inicializa e configura sensores e conexoes  */
/***********************************************/
void setup() {
  Serial.begin(9600);
  while ( !Serial ) delay(100);   // aguarda conexão

  Serial.println("Teste do BMP280");

  bmp_A.begin();// inicia sensor A
  bmp_B.begin();// inicia sensor B

  /* Default settings from datasheet. */
  bmp_A.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                    Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                    Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                    Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                    Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  /* Default settings from datasheet. */
  bmp_B.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                    Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                    Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                    Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                    Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

/*****************************************************************/
/* Leitura dos dados dos sensores e enviado para a porta serial  */
/*****************************************************************/
void loop() {
  
  Serial.print("Temperatura_A = ");
  Serial.print(bmp_A.readTemperature()); // Leitura da Temperatura do sensor A
  Serial.println(" ºC");

  Serial.print("Pressão_A = ");
  Serial.print(bmp_A.readPressure()); // Leitura da Pressão Atmosférica do sensor A
  Serial.println(" Pa");

  Serial.print("Altitude_Aproximada_A = ");
  Serial.print(bmp_A.readAltitude(1013.25)); // Leitura da Altitude Aproximada do sensor A
  Serial.println(" m");
  Serial.println();

  Serial.print("Temperatura_B = ");
  Serial.print(bmp_B.readTemperature()); // Leitura da Temperatura do sensor B
  Serial.println(" ºC");

  Serial.print("Pressão_B = ");
  Serial.print(bmp_B.readPressure()); // Leitura da Pressão Atmosférica do sensor B
  Serial.println(" Pa");

  Serial.print(F("Altitude_Aproximada_B = "));
  Serial.print(bmp_B.readAltitude(1013.25)); // Leitura da Altitude Aproximada do sensor B
  Serial.println(" m");
  Serial.println();

  delay(1000);
}
