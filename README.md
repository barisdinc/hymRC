Bu projenin amaci role olarak kullanilmak uzere hazirlanan duzeneklerin kontrolunu saglamak ve bu sistemin uzaktan kumandasi ile tanitim bilgilerini olusturacak bir kart tasarimi yapmaktir.

Bu proje TA7OM Hudaverdi Gunes'in tesviki ile baslatilmistir. Mevcutta yillar once yaptigimiz ve pek cok rolede kullanilan genelde PIC tabanli Role Kontrol kartlarinin daha modern hale getirilmesi hedeflenecektir.

Temel olarak aklimizdakiler asagidaki gibidir;

#Temel Ozellikler
- Islemci unitesi olarak PIC yerine kolay erisilebilir ve programlanabilir ATMEL (Arduino) tercih edilecektir
- 12 Volt ile beslenecektir
- Role kontrol ozellikleri olacaktir
- Durum gosterimi icin LED bulunacaktir
- Ayarlarin gosterimi icin LCD bulunacaktir (opsiyonel)
- Ayarlarin goruntulenmesi/degistirilmesi icin rotary encoder bulunacaktir (opsiyonel)
- Sistem icinde gercek zaman saati bulunacaktir (opsiyonel)

#Role KOntrol Ozellikleri
-- Squelch/Sinyal girisi
-- Otomatik enterferans engelleme
-- 

#Uzaktan Kumanda Ozellikleri
- DTMF ile uzaktan kumanda ozelligi olacaktir
-- Role acma/kapatma
-- Ton acma/kapatma
-- Morse tanitim acma/kapatma
-- belirlenen sure boyunca kapali kalma
-- Otomatik enterferans engelleme acma/kapama
-- AX25 ile uzaktan ayar yuklenmesi yapilabilecektir (opsiyonel)

#Tanitim Bilgisi
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


