void init_port(void);
void outdata(char);
void outcontrol(char);
void Delay(int);
void lcd_control_write(void);
void lcd_control_write1(void);
void init_lcd(void);
void write_data(char);
volatile long i;

void setlcd()
{
init_port();
init_lcd();
}

void displaylcd(char y)
{
outcontrol(0x02);
write_data(y);
}


void init_port()
{
  volatile char portf_dir=(volatile char)0x21;
  volatile char portk_dir=(volatile char)0x27;
  *portf_dir=0xFF;
  *portk_dir=0x03; 
}

void outdata(char out_data)
{
  volatile char portf_data=(volatile char)0x22;
  *portf_data=out_data;
}

void outcontrol(char out_data)
{
  volatile char portk_data=(volatile char)0X28;
  *portk_data=out_data;
}

void init_lcd(void)
{
  outdata(0x38);
  lcd_control_write();// 8bit 2 line
   outdata(0x0f);// display on cursor blinking
  lcd_control_write();
   outdata(0x01);// clear display
  lcd_control_write();
   outdata(0x06);// Auto Icrement
  lcd_control_write();
}

void write_data(char x)
{

outdata(x);
lcd_control_write1();
}

void lcd_control_write(void)
{
  outcontrol(0x01);
  Delay(2);
  outcontrol(0x00);
  Delay(2);
}

void lcd_control_write1(void)
{
  outcontrol(0x03);
  Delay(2);
  outcontrol(0x02);
  Delay(2);
}

void Delay(int count)
{
  volatile char i;
  for(i=0;i<count;i++);
}
