/******************************************************************************
*                                                                             *
*   Projeto: Rotacionador de Mensagem em Display LCD                          *
*   Autor: Diego Aguiar                                                       *
*                                                                             *
*   Este c�digo � destinado a um microcontrolador PIC18F4520 que controla     *
*   um display LCD alfanum�rico. Ele exibe a mensagem inicial e em seguida    *
*   rotaciona os caracteres exibidos de forma c�clica.                        *
*                                                                             *
******************************************************************************/

#include <18f4520.h>         // Inclui o arquivo espec�fico para o 
                             //microcontrolador PIC18F4520
#fuses HS, NOWDT             // Configura os fus�veis do microcontrolador 
                             // (cristal de alta velocidade e desativa o 
                             // watchdog timer)
#use delay(clock = 8000000)  // Define que a frequ�ncia do clock ser� em 8MHz

#define LCD_RS_PIN      PIN_D0  // Define o pino para RS (Register Select) 
                                // do LCD
#define LCD_RW_PIN      PIN_D1  // Define o pino para RW (Read/Write) do LCD
#define LCD_ENABLE_PIN  PIN_D2  // Define o pino para o pino de habilita��o 
                                // (Enable) do LCD
#define LCD_DATA4       PIN_D4  // Define o pino para D4 (Data 4) do LCD
#define LCD_DATA5       PIN_D5  // Define o pino para D5 (Data 5) do LCD
#define LCD_DATA6       PIN_D6  // Define o pino para D6 (Data 6) do LCD
#define LCD_DATA7       PIN_D7  // Define o pino para D7 (Data 7) do LCD

#include <lcd.c>       // Inclui a biblioteca para controle do LCD

char velho[] = "Selecione a Maquina ";  // Define a mensagem inicial
char novo[] =  "Selecione a Maquina ";  // Define uma string para manipula��o

int strlen(char s[]) {  // Fun��o para calcular o comprimento de uma string
   int i;
   for (i = 0; s[i] != '\0'; i++) ;
   return i;
}

void main (){
   lcd_init();  // Inicializa o LCD
   delay_ms(50);  // Aguarda 50 milissegundos
   lcd_putc("Microcontrolador\n");  // Exibe a mensagem inicial
   printf(lcd_putc,"%s",velho);  // Exibe a mensagem "velho" no LCD
   delay_ms(2000);  // Aguarda 2 segundos
   int x = strlen(velho);  // Calcula o comprimento da string "velho"

   while(true) {
      for(int a = 1; a<x+1; a++){
         velho[a-1] = lcd_getc(a,2);  // L� os caracteres exibidos no LCD
      }
      for(a = 1; a<x; a++){
         novo[a-1] = velho[a];  // Realiza a rota��o dos caracteres
      }
      novo[x-1] = velho[0];  // Move o primeiro caractere para o final
      for(a = 0; a<x; a++){
        velho[a] = novo[a];// Atualiza a string "velho" com a nova configura��o
      }
     lcd_gotoxy(1,2);  // Move o cursor para a segunda linha
      for(a = 0; a<x; a++){
         lcd_putc(novo[a]);  // Exibe a nova configura��o no LCD
      }
      delay_ms(500);  // Aguarda meio segundo
   }
}
