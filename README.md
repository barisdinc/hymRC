Bu projenin amaci role olarak kullanilmak uzere hazirlanan duzeneklerin kontrolunu saglamak ve bu sistemin uzaktan kumandasi ile tanitim bilgilerini olusturacak bir kart tasarimi yapmaktir.

Bu proje *TA7OM Hudaverdi Gunes*'in tesviki ile baslatilmistir. Mevcutta yillar once yaptigimiz ve pek cok rolede kullanilan genelde PIC tabanli Role Kontrol kartlarinin daha modern hale getirilmesi hedeflenecektir.

Temel olarak aklimizdakiler asagidaki gibidir;

# Temel Ozellikler
1. Islemci unitesi olarak PIC yerine kolay erisilebilir ve programlanabilir ATMEL (Arduino) tercih edilecektir
2. 12 Volt ile beslenecektir
3. Role kontrol ozellikleri olacaktir
4. Durum gosterimi icin LED bulunacaktir
5. Dis arayuz baglantilari optokupler veya roleler uzerinden yapilacaktir
6. Ayarlarin gosterimi icin LCD bulunacaktir (opsiyonel)
7. Ayarlarin goruntulenmesi/degistirilmesi icin rotary encoder bulunacaktir (opsiyonel)
8. Sistem icinde gercek zaman saati bulunacaktir (opsiyonel)

# Role KOntrol Ozellikleri
. Squelch/Sinyal girisi
. Otomatik enterferans engelleme
. ... 

# Uzaktan Kumanda Ozellikleri
1 DTMF ile uzaktan kumanda ozelligi olacaktir
2 Role acma/kapatma
3 Ton acma/kapatma
4 Morse tanitim acma/kapatma
5 belirlenen sure boyunca kapali kalma
6 Otomatik enterferans engelleme acma/kapama
7 AX25 ile uzaktan ayar yuklenmesi yapilabilecektir (opsiyonel)

# Tanitim Bilgisi
- Beacon Tanitim ozelligi bulunacaktir (Orn: YM7KO 88.5 KN80WU 5W -10C 138V 121220 1919)
-- Morse olarak istasyon tanitimi basacaktir
-- Morse tanitim icinde asagidaki bilgiler olacaktir
--- Ton bilgisi
--- Lokasyon bilgisi (grid   square)
--- Cikis Gucu
-- Uzaktan kumanda sifre kontrollu olacaktir
-- Sifre uzaktan degistirilebilecektir
-- Sifre tanimli bir sifre kumesinden (Orn: 10 degisik sifre) sirayla degisecektir, aktif sifre no sorgulanabilecektir
-- Beacon sinyali AX25 olarak da gonderilecektir
-- AX25 beacon sinyali icinde rolenin tum ayarlarinin aktif durumu bulunabilecektir
-- Ortam sicakligi
-- Aku voltajlari
-- Tarih ve saat (gercek zamani opsiyonu durumunda)

**NOT:** Liste ilgili goruslerinizi ve eklenmesini istediginiz ozellikleri ISSUE bolumunden veya email ile bize bildiriniz. (barisdinc###gmail.com) 
