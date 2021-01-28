Atmega328p uzerinde 14 adet digital ve 8 adet analog pine sahiptir. BU pinlerden bazilari ozel amaclar icin peripherallere baglidir (Orn: seri, I2C, SPI veya PWM)

# Pin eslemeleri :
## Digital pinler
### Seri Data
Role kontrolcusunu ilerde baska bir sistemler bhaberlestirme ihtiyaci dogrudugune bu pinler seri haberlesme amaciyla kullanilacaktir
* D0 Seri iletisim icin kullanilacak (RX)
* D1 Seri iletisim icin kullanilacak (TX)

### interrupt (kesme) gerektiren islemler icin
* D2 KS8820 Tone decoder tarafina interrupt
* D3 Squelch input icin interrupt (ya da daha hizli bir is icin)

### Direk chip kontrolu icin digital pin
* D4 Chip Select 1
* D5 Chip Select 2

### Mors ve data uretme
* D6 PWM cikisi olarak kullanialcak

### Acma kapama isleri
* D7 Role veya Digital  KOntrol 1
* D8 Role veya Digital  KOntrol 2
* D9 Role veya Digital  KOntrol 3

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
