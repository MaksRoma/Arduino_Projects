struct RAM{
   uint8_t SEGM1;
   uint8_t SEGM2;
   uint8_t SEGM3;
   uint8_t SEGM4;
};

RAM vram = {  127,  63, 79, 6  };
void printBuffer();
void setup() {                
  DDRB = DDRB | 0xF;  
  DDRD = 0xFF;
  PORTD = 0x00;
  PORTB &= 0x0;
}

void loop() 
{
  printBuffer();
}

void printBuffer()
{

  PORTD = vram.SEGM1;
  delay(1);
  PORTD = 0x00;
  PORTB &= ~(0x01);
  PORTB |= 0x02;

  PORTD = vram.SEGM2;
  delay(1);
  PORTD = 0x00;
  PORTB &= ~(0x02);
  PORTB |= 0x04;

  PORTD = vram.SEGM3;
  delay(1);
  PORTD = 0x00;
  PORTB &= ~(0x04);
  PORTB |= 0x08;

  PORTD = vram.SEGM4;
  delay(1);
  PORTD = 0x00;
  PORTB &= ~(0x08);
  PORTB |= 0x01;
  //delay(3);
  
}
