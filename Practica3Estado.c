#INCLUDE <18f4550.h>
#FUSES NOPROTECT, NOWDT, NOLVP, HSPLL, PLL5, CPUDIV2
#USE delay(clock = 48M)

#BYTE TRISD = 0xF95
#BYTE PORTD = 0XF83

#BYTE TRISB = 0xF93
#BYTE PORTB = 0xF81

int display = 0;

void main(){
   TRISD = 0x00;
   PORTD = 0x00;
   
   while(TRUE){

      TRISB = 0x0F;
      PORTD = 0b00000011;
      delay_ms(500);
      PORTB = 0x00;
      
      switch(PORTB){
         case 0x00:
            display = 0x3F;
         break;
         case 0x01:
            display = 0x06;
         break;
         case 0x02:
            display = 0x5B;
         break;
         case 0x03:
            display = 0x4F;
         break;
         case 0x04:
            display = 0x66;
         break;
         case 0x05:
            display = 0x6D;
         break;
         case 0x06:
            display = 0x7D;
         break;
         case 0x07:
            display = 0x07;
         break;
         case 0x08:
            display = 0x7F;
         break;
         case 0x09:
            display = 0x67;//dhdhd
         break;
         case 0x0A:
            display = 0x77;//A
         break;
         case 0x0B:
            display = 0x7C;//B 0X7C
         break;
         case 0x0C:
            display = 0x39;//C
         break;
         case 0x0D:
            display = 0x5E;//D 0X5E
         break;
         case 0x0E:
            display = 0x79;//E
         break;
         case 0x0F:
            display = 0x71;//F
         break;
      }
      
      PORTD = 0b00000101;
      delay_ms(100);
      TRISB = 0x00;
      PORTB = display;
      delay_ms(1000);
   }
}
