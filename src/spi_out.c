void spi_out_(byte dat)  // Daten über SPI senden
{
  byte i = 8;                                             //dat = z.B. 15 = B0000 1111
  do
  { //          <<1          <<1         <<1          <<1          <<1         <<1         <<1
    if (dat & 0x80)                                    //0000 1111    0001 1110   0011 1100    0111 1000    1111 0000    1110 0000   1100 0000    1000 0000
      digitalWrite(SDA_, HIGH);                        //1000 0000    1000 0000   1000 0000    1000 0000    1000 0000    1000 0000   1000 0000    1000 0000
    else                                               //0000 0000                                          1000 0000
      digitalWrite(SDA_, LOW);                         //   LOW         LOW          LOW         LOW           HIGH        HIGH         HIGH        HIGH

    delayMicroseconds(60);
    digitalWrite(SCK_, HIGH);
    delayMicroseconds(60);

    dat <<= 1;

    digitalWrite(SCK_, LOW);
    delayMicroseconds(50);
  } while (--i);


}