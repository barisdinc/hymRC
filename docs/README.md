Atmega328p uzerinde 14 adet digital ve 8 adet analog pine sahiptir. BU pinlerden bazilari ozel amaclar icin peripherallere baglidir (Orn: seri, I2C, SPI veya PWM)

# Pin eslemeleri :
## Digital pinler
### Seri Data
Role kontrolcusunu ilerde baska bir sistemler bhaberlestirme ihtiyaci dogrudugune bu pinler seri haberlesme amaciyla kullanilacaktir
* D0 Seri iletisim icin kullanilacak (RX)
* D1 Seri iletisim icin kullanilacak (TX)

### interrupt (kesme) gerektiren islemler icin
* D2 KS8870 StD (interrupt)
* D3 Squelch input icin interrupt (ya da daha hizli bir is icin)

###TOne Decoder baglantisi (4+1 Pin)

* D4 MT8870 Q1
* D5 MT8870 Q2
* D6 MT8870 Q3
* D7 MT8870 Q4

### Mors ve data uretme
* ???? PWM cikisi olarak kullanialcak

### Acma kapama isleri
* D8 PTT kontrol
* D9 Role veya Digital  KOntrol 1

### Harici veriyolu (sensorler vb icin SPI)
* D10 SPI ihtiyaci icin kullanialcak (SS)
* D11 SPI ihtiyaci icin kullanialcak (MOSI)
* D12 SPI ihtiyaci icin kullanialcak (MISO)
* D13 SPI ihtiyaci icin kullanialcak (SCK)

## Analog Okuyucular
### Algilayicilar
* A0 Aku Durumu
* A1 Analog Sensor 1 (ornek: sicaklik, isik durumu, ruzgar)
* A2 Analog Sensor 2 (ornek: sicaklik, isik durumu, ruzgar)

* A3 BOS (AX25 dinleme icin kullanilabilir)

### Harici veriyolu (sensorler vb icin I2C)
* A4 I2C iletisim icin kullanilacak (SDA)
* A5 I2C iletisim icin kullanilacak (SCL)

* A6 BOS
* A7 BOS

Onemli Not:
-----------
* Rolenin mors ciktisina ek olarak AX25 paket radyo verisi olusturmak icin en az 4 pin ayristirilmasi gerekebilir ya da harici bir DAC chip kullanilabilir
* Rolenin AX25 alma islemi yapabilmesi icin analog portlardan birinin bu ise ayrilmasi gerekebilir


### Test Devresi
## MT3170 / KT8870 Bacak Baglantilari
Piyasada en kolay bulunan versiyonu 18 bacakli hali olup eger benim gibi kazara 20 bacakli versiyonunu kullaniyorsaniz internette cok kolay bulunamayan bacak baglanti detaylari asagidaki gibidir;

<IMG SRC=https://github.com/barisdinc/hymRC/blob/main/docs/MT3170_pinout_variants.png>
  
Ilk ornek uygulamamda asagidaki gibi bir devreyi kucuk bir protoboard uzerine kurup calismaya basladim;
<IMG SRC=https://github.com/barisdinc/hymRC/blob/main/docs/MT3170_application.png>

Kurulu hali gorunumu

<IMG WIDTH=50% HEIGHT=50% SRC=https://github.com/barisdinc/hymRC/blob/main/docs/Initial_test_setup.jpeg>
  
## 16 Bit port genisletici kullanimi
 
 <IMG SRC=https://github.com/barisdinc/hymRC/blob/main/docs/MCP23017_application.png>
  
 * A0
 * A1
 * A2
 * A3
 * A4
 * A5
 * A6
 * A7
 * A8
  
 * B0 MT8870 Q1       (input) Interrupt On Pin
 * B1 MT8870 Q2       (input) Interrupt On Pin
 * B2 MT8870 Q3       (input) Interrupt On Pin
 * B3 MT8870 Q4       (input) Interrupt On Pin
 * B4 MT8870 StD      (input) Interrupt On Change 
 * B5 General Purpose (input) No Interrupt
 * B6 General Purpose (input) No Interrupt
 * B7 General Purpose (input) No Interrupt
  
 * INTA -> Pin 2 of MCU (INT0)
 * INTB -> Pin 3 of MCU (INT1)

<IMG WIDTH=50% HEIGHT=50% SRC=https://github.com/barisdinc/hymRC/blob/main/docs/Extender_test_setup.png>
  
  
  
  
  
