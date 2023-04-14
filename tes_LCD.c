#include <16f887.h> 
#device *=16 ADC=8
#FUSES NOWDT, HS, NOPUT, NOBROWNOUT,NOPROTECT, NOLVP 
#use delay(clock=16M)
#include <luutinh.h>
#include <LCD.h>
int x=0;
void Button_1(){

if(input(pin_a3)==0){

x++;
delay_ms(100);

}
if(x==1){
	//lcd_putc('\f');
    lcd_gotoxy(5,1);           // Go to column 4 row 1
    lcd_putc("ICE2018A");
    lcd_gotoxy(4,2);           // Go to column 4 row 2
    lcd_putc("LCD example");
    //delay_ms(500);
}

if(x==2){
	//lcd_putc('\f');             // LCD clear
    lcd_gotoxy(5, 1);           // Go to column 3 row 1
    lcd_putc("IB2018A");
    lcd_gotoxy(2,2);           // Go to column 2 row 2
    lcd_putc("Have a nice day");
    //delay_ms(500);
}
if(x==3){
    //lcd_putc('\f');             // LCD clear
    lcd_gotoxy(6,1);           // Go to column 3 row 1
    lcd_putc("AC2020B");
    lcd_gotoxy(4,2);           // Go to column 3 row 1
    lcd_putc("Double tour");
	x=0;    
//delay_ms(500);
}
}

void Button_2(){
while(input(pin_a4)==0){}
    lcd_putc('\f'); 
    lcd_gotoxy(5, 1);           
    lcd_putc("KEUKA2030A");
    lcd_gotoxy(6,2);           
    lcd_putc("IS-VNU");
	delay_ms(200);


while(input(pin_a4)==1){}
	lcd_putc('\f'); 
	lcd_gotoxy(5, 1);           
    lcd_putc("RICARDO KAKA");
    lcd_gotoxy(5,2);           
    lcd_putc("BRASIL");
	delay_ms(200);

}

void POSITIVE(){
	lcd_putc('\f');
	lcd_gotoxy(4,1);           
    lcd_putc("HARRY KANE");
    lcd_gotoxy(5,2);           
    lcd_putc("ENGLAND");

}
    void NEGATIVE(){

    lcd_gotoxy(3,1);           
    lcd_putc("ANDRE SILVA");
    lcd_gotoxy(5,2);           
    lcd_putc("PORTUGAL");

}
void Button_3(){
if(input(pin_a6)==0){
	output_b(0x88);
}
else{
	output_b(0x00);
}
}
void Button_4()
{
if(input(pin_a5)==0)
{
NEGATIVE();
}

if(input(pin_a5)==1)
{

POSITIVE();

}
}



void main ()
{
	set_tris_a(0xff); 
	set_tris_b(0x00); 
	set_tris_d(0x00); 

	//output_b(0x00);	

	LCD_INIT();
/*
	lcd_gotoxy(4,1);
	printf(lcd_putc,"NAME");
	lcd_gotoxy(4,2);
	printf(lcd_putc,"DATE OF BIRTH");
*/
    lcd_gotoxy(4,1);           
    lcd_putc("HARRY KANE");
    lcd_gotoxy(5,2);           
    lcd_putc("ENGLAND");


while(TRUE){
output_b(0x00);

    if(input(pin_a3)==0){
	lcd_putc('\f'); 	
	Button_1();
	}
	if(input(pin_a4)==0){
    Button_2();
	}
while(input(pin_a5)==0){
Button_4();
}

while(input(pin_a6)==0){
Button_3();
}


 }
}