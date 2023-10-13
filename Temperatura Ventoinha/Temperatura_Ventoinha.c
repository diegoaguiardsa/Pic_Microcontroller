/******************************************************************************
*                                                                             *
*   Projeto: Monitoramento de Temperatura com Display e Ventoinha             *
*   Autor: Diego Aguiar                                                       *
*                                                                             *
*   Este código é destinado a um microcontrolador PIC18F4520 que monitora     *
*   a temperatura e controla uma ventoinha com base na leitura de um sensor   *
*   uma ventoinha com base na leitura de um sensor de temperatura analógico.  *
*                                                                             *
******************************************************************************/

#include <18f4520.h>         // Inclui a biblioteca específica para o 
                             // microcontrolador PIC18F4520
#device adc = 10             // Define a resolução do conversor AD como 10 bits
#fuses HS, NOWDT             // Configura os fusíveis (oscilador de alta 
                             // velocidade, sem Watchdog Timer)
#use delay (clock = 8000000) // Define que a frequência do clock será em 8MHz
#define LCD_RS_PIN      PIN_E0  // Define o pino para RS (Register Select)
                                // do LCD
#define LCD_RW_PIN      PIN_D2  // Define o pino para RW (Read/Write) do LCD
#define LCD_ENABLE_PIN  PIN_E1  // Define o pino para o pino de habilitação
                                // (Enable) do LCD
#define LCD_DATA4       PIN_D4  // Define o pino para D4 (Data 4) do LCD
#define LCD_DATA5       PIN_D5  // Define o pino para D5 (Data 5) do LCD
#define LCD_DATA6       PIN_D6  // Define o pino para D6 (Data 6) do LCD
#define LCD_DATA7       PIN_D7  // Define o pino para D7 (Data 7) do LCD

#include <lcd.c>       // Inclui a biblioteca para controle do LCD

// Declaração das variáveis globais
int16 q = 0;               // Variável para armazenar a leitura do conversor AD
float temperatura = 0;     // Variável para armazenar a temperatura
int1 vent = 0;             // Variável de controle da ventoinha
int cedilha[8] = {         // Define um caractere personalizado (cedilha)
    0b00000,
    0b01110,
    0b10000,
    0b10000,
    0b01110,
    0b00100,
    0b01000,
    0b00000
};

int a_til[8] = {           // Define um caractere personalizado (a com til)
    0b11111,
    0b00000,
    0b01110,
    0b00001,
    0b01111,
    0b10001,
    0b01111,
    0b00000
};

// Função para atualizar o display
void ihm (float a){
   lcd_gotoxy(1,1);  // Define a posição do cursor na linha 1, coluna 1
   printf(lcd_putc,"  Temperatura:  \n");  // Exibe o texto "Temperatura:"
   printf(lcd_putc,"    %f %cC       ",a,(char)223);  // Exibe a temperatura lida
   delay_ms(200);  // Aguarda um curto período de tempo
   if (vent == 1){
      lcd_gotoxy(1,2);  // Define a posição do cursor na linha 2, coluna 1
      printf(lcd_putc,"Ventila%c%coLigada",0,1);  // Exibe o estado da ventoinha
      delay_ms(500);  // Aguarda um curto período de tempo
   }
}

// Função para controlar a ventoinha
void ventoinha (){
   if (temperatura > 60){
      vent = 1;  // Liga a ventoinha se a temperatura for maior que 60°C
   }
   else  if (temperatura < 45){
      vent = 0;  // Desliga a ventoinha se a temperatura for menor que 45°C
   }
   output_bit(pin_c0,vent);  // Atualiza o estado da ventoinha
}
void main (){
   set_tris_a(0b00000001);  // Configura o pino RA0 como entrada
   set_tris_c(0b00000000);  // Configura todos os pinos de C como saída
   setup_adc_ports(AN0);  // Configura o pino AN0 como entrada analógica
   setup_adc(ADC_CLOCK_DIV_64);  // Configuração do ADC
   set_adc_channel(0);  // Seleciona o canal do ADC
   lcd_init();  // Inicializa o LCD
   delay_ms(5);  // Aguarda um curto período de tempo
   lcd_putc("Iniciando");  // Exibe a mensagem "Iniciando" no LCD
   delay_ms(500);  // Aguarda um curto período de tempo
   lcd_putc(".");  // Exibe um ponto no LCD
   delay_ms(500);  // Aguarda um curto período de tempo
   lcd_putc(".");  // Exibe um ponto no LCD
   delay_ms(500);  // Aguarda um curto período de tempo
   lcd_putc(".");  // Exibe um ponto no LCD
   delay_ms(500);  // Aguarda um curto período de tempo
   lcd_set_cgram_char(0, cedilha);  // Define o caractere cedilha no CGRAM
   lcd_set_cgram_char(1, a_til);  // Define o caractere a til no CGRAM

   while(true) {
      q = read_adc();  // Lê o valor do sensor de temperatura
      delay_us(20);
      temperatura = (500.00*q)/1023.00;// Calcula a temperatura em graus Celsius
      ihm(temperatura);  // Atualiza o display com a temperatura
      ventoinha();  // Controla a ventoinha com base na temperatura
   }
}
