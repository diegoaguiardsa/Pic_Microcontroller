/******************************************************************************
*                                                                             *
*   Projeto: Acionador de M�quinas com Display LCD                            *
*   Autor: Diego Aguiar                                                       *
*                                                                             *
*   Este c�digo � destinado a um microcontrolador PIC18F4520 de um sistema    *
*   de acionamento de m�quinas que possui 10 canais e um display LCD 16x02.   *
*   O programa permite selecionar m�quinas e ligar/desligar cada uma delas.   *
*                                                                             *
******************************************************************************/

#include <18f4520.h>         // Inclui o arquivo espec�fico para o 
                             // microcontrolador PIC18F4520
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

int menu = 0;  // Vari�vel para armazenar o menu selecionado
int maq1=0,maq2=0,maq3=0,maq4=0,maq5=0,maq6=0,
    maq7=0,maq8=0,maq9=0,maq10=0;  // Vari�veis para o estado das m�quinas

#INT_EXT
void botao_avancar(){  // Avan�a no menu para selecionar uma m�quina 
   menu++;
   if (menu == 10){
      menu = 0;
   }
}

#INT_EXT1
void botao_voltar(){  // Volta no menu para selecionar uma m�quina 
   menu--;
   if (menu == -1){
      menu = 9;
   }
}

#INT_EXT2
void botao_confirmar(){ // Aciona ou desliga a m�quina selecionada
   if (menu == 0){
      maq1 = 1 - maq1;
      output_bit(pin_b3,maq1);
   }
   else if (menu == 1){
      maq2 = 1 - maq2;
      output_bit(pin_b4,maq2);
   }
   else if (menu == 2){
      maq3 = 1 - maq3;
      output_bit(pin_c0,maq3);
   }
   else if (menu == 3){
      maq4 = 1 - maq4;
      output_bit(pin_c1,maq4);
   }
   else if (menu == 4){
      maq5 = 1 - maq5;
      output_bit(pin_c2,maq5);
   }
   else if (menu == 5){
      maq6 = 1 - maq6;
      output_bit(pin_c3,maq6);
   }
   else if (menu == 6){
      maq7 = 1 - maq7;
      output_bit(pin_c4,maq7);
   }
   else if (menu == 7){
      maq8 = 1 - maq8;
      output_bit(pin_c5,maq8);
   }
   else if (menu == 8){
      maq9 = 1 - maq9;
      output_bit(pin_c6,maq9);
   }
   else if (menu == 9){
      maq10 = 1 - maq10;
      output_bit(pin_c7,maq10);
   }
}

void ihm(){
    if (menu == 0){
        lcd_gotoxy(1,1);  // Define a posi��o do cursor na linha 1, coluna 1
        lcd_putc("Maquina 01   ");  // Exibe o texto "Maquina 01"
        if (maq1 == 1){  // Verifica se a m�quina 1 est� ligada
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Ligado   ");  // Exibe o estado "Ligado"
        }
        else{
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Desligado");  // Exibe o estado "Desligado"
        }
    }
    else if (menu == 1){
        lcd_gotoxy(1,1);  // Define a posi��o do cursor na linha 1, coluna 1
        lcd_putc("Maquina 02   ");  // Exibe o texto "Maquina 02"
        if (maq2 == 1){  // Verifica se a m�quina 2 est� ligada
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Ligado   ");  // Exibe o estado "Ligado"
        }
        else{
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Desligado");  // Exibe o estado "Desligado"
        }
    }
    else if (menu == 2){
        lcd_gotoxy(1,1);  // Define a posi��o do cursor na linha 1, coluna 1
        lcd_putc("Maquina 03   ");  // Exibe o texto "Maquina 03"
        if (maq3 == 1){  // Verifica se a m�quina 3 est� ligada
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Ligado   ");  // Exibe o estado "Ligado"
        }
        else{
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Desligado");  // Exibe o estado "Desligado"
        }
    }
    else if (menu == 3){
        lcd_gotoxy(1,1);  // Define a posi��o do cursor na linha 1, coluna 1
        lcd_putc("Maquina 04   ");  // Exibe o texto "Maquina 04"
        if (maq4 == 1){  // Verifica se a m�quina 4 est� ligada
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Ligado   ");  // Exibe o estado "Ligado"
        }
        else{
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Desligado");  // Exibe o estado "Desligado"
        }
    }
    else if (menu == 4){
        lcd_gotoxy(1,1);  // Define a posi��o do cursor na linha 1, coluna 1
        lcd_putc("Maquina 05   ");  // Exibe o texto "Maquina 05"
        if (maq5 == 1){  // Verifica se a m�quina 5 est� ligada
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Ligado   ");  // Exibe o estado "Ligado"
        }
        else{
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Desligado");  // Exibe o estado "Desligado"
        }
    }
    else if (menu == 5){
        lcd_gotoxy(1,1);  // Define a posi��o do cursor na linha 1, coluna 1
        lcd_putc("Maquina 06   ");  // Exibe o texto "Maquina 06"
        if (maq6 == 1){  // Verifica se a m�quina 6 est� ligada
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Ligado   ");  // Exibe o estado "Ligado"
        }
        else{
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Desligado");  // Exibe o estado "Desligado"
        }
    }
    else if (menu == 6){
        lcd_gotoxy(1,1);  // Define a posi��o do cursor na linha 1, coluna 1
        lcd_putc("Maquina 07   ");  // Exibe o texto "Maquina 07"
        if (maq7 == 1){  // Verifica se a m�quina 7 est� ligada
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Ligado   ");  // Exibe o estado "Ligado"
        }
        else{
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Desligado");  // Exibe o estado "Desligado"
        }
    }
    else if (menu == 7){
        lcd_gotoxy(1,1);  // Define a posi��o do cursor na linha 1, coluna 1
        lcd_putc("Maquina 08   ");  // Exibe o texto "Maquina 08"
        if (maq8 == 1){  // Verifica se a m�quina 8 est� ligada
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Ligado   ");  // Exibe o estado "Ligado"
        }
        else{
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Desligado");  // Exibe o estado "Desligado"
        }
    }
    else if (menu == 8){
        lcd_gotoxy(1,1);  // Define a posi��o do cursor na linha 1, coluna 1
        lcd_putc("Maquina 09   ");  // Exibe o texto "Maquina 09"
        if (maq9 == 1){  // Verifica se a m�quina 9 est� ligada
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Ligado   ");  // Exibe o estado "Ligado"
        }
        else{
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Desligado");  // Exibe o estado "Desligado"
        }
    }
    else if (menu == 9){
        lcd_gotoxy(1,1);  // Define a posi��o do cursor na linha 1, coluna 1
        lcd_putc("Maquina 10   ");  // Exibe o texto "Maquina 10"
        if (maq10 == 1){  // Verifica se a m�quina 10 est� ligada
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Ligado   ");  // Exibe o estado "Ligado"
        }
        else{
            lcd_gotoxy(1,2);  // Define a posi��o do cursor na linha 2, coluna 1
            lcd_putc("Desligado");  // Exibe o estado "Desligado"
        }
    }
}

void main (){
   lcd_init();  // Inicializa o LCD
   lcd_putc("Iniciando");  // Exibe mensagem de inicializa��o
   delay_ms(500);  // Aguarda meio segundo
   lcd_putc(".");  // Exibe ponto
   delay_ms(500);  // Aguarda meio segundo
   lcd_putc(".");  // Exibe ponto
   delay_ms(500);  // Aguarda meio segundo
   lcd_putc(".");  // Exibe ponto
   delay_ms(500);  // Aguarda meio segundo
   clear_interrupt(INT_EXT);  // Limpa a interrup��o externa
   clear_interrupt(INT_EXT1);  // Limpa a interrup��o externa 1
   clear_interrupt(INT_EXT2);  // Limpa a interrup��o externa 2
   enable_interrupts(INT_EXT);  // Habilita interrup��o externa
   enable_interrupts(INT_EXT1); // Habilita interrup��o externa 1
   enable_interrupts(INT_EXT2); // Habilita interrup��o externa 2
   enable_interrupts(GLOBAL);   // Habilita todas as interrup��es

   while(true) {
      ihm();  // Chama a fun��o de ihm
   }
}
