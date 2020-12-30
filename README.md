Bu projenin amaci role olarak kullanilmak uzere hazirlanan duzeneklerin kontrolunu saglamak ve bu sistemin uzaktan kumandasi ile tanitim bilgilerini olusturacak bir kart tasarimi yapmaktir.

Bu proje **_TA7OM Hudaverdi Gunes_**'in tesviki ile baslatilmistir. Mevcutta yillar once yaptigimiz ve pek cok rolede kullanilan genelde PIC tabanli Role Kontrol kartlarinin daha modern hale getirilmesi hedeflenecektir.

Aklimizdaki ozellikler asagidaki gibidir;

### Temel Ozellikler
1. Islemci unitesi olarak PIC yerine kolay erisilebilir ve programlanabilir ATMEL (Arduino) tercih edilecektir
1. 12 Volt ile beslenecektir
1. Role kontrol ozellikleri olacaktir
1. Durum gosterimi icin LED bulunacaktir
1. Dis arayuz baglantilari optokupler veya roleler uzerinden yapilacaktir
1. COR/CAS destegi olmalidir
1. COR/CAS destegi +/- olabilmelidir
1. Ayarlarin gosterimi icin LCD bulunacaktir (opsiyonel)
1. Ayarlarin goruntulenmesi/degistirilmesi icin rotary encoder bulunacaktir (opsiyonel)
1. Sistem icinde gercek zaman saati bulunacaktir (opsiyonel)
1. Roleye simplex Link sistemi ilave edilebilmelidir
  * Link COR girişi olmalı
  * Ancak Link girişinden sinyal geldiğinde Role de Kuyruk süresi olmamalı
  * İki VHF cihaz ile yapılan Role bir birine UHF üzerinden ücüncü cihaz ile Linkli olsun. 
  * iki cihazdan yapılan VHF Role Normal aktivtesini sürdürürken Kullanıcı Mandalı attığında Role göndermede iken aynı zamanda UHF link cihazı da göndermeye geçmelidir. 
  * Kullanıcı Mandalı bıraktığında Role Kuruk süresi sonrasında kapanacak ancak Link ise hiçbir gecikme olmadan, yani kuyruk süresi olmadan anında kapanacak. Bunun amacı Link üzerinden gelen sinyal zaten bir rokleden gelmekte olup, üzerinde kuyruk süresi vardır. 
  * ikinci bir kuyruk süresine ihtiyaç yoktur.
  
1. ...

### Role KOntrol Ozellikleri
1. Squelch/Sinyal girisi
2. Otomatik enterferans engelleme
3. ... 

### Uzaktan Kumanda Ozellikleri
1. DTMF ile uzaktan kumanda ozelligi olacaktir
2. Role acma/kapatma
3. Ton acma/kapatma
4. Morse tanitim acma/kapatma
5. belirlenen sure boyunca kapali kalma
6. Otomatik enterferans engelleme acma/kapama
7. Link acma/kapama
8. AX25 ile uzaktan ayar yuklenmesi yapilabilecektir (opsiyonel)
9. ...

### Tanitim Bilgisi
1. Beacon Tanitim ozelligi bulunacaktir (Orn: YM7KO 88.5 KN80WU 5W -10C 138V 121220 1919)
  * Morse olarak istasyon tanitimi basacaktir
  * Morse tanitim icinde asagidaki bilgiler olacaktir
  * Ton bilgisi
  * Lokasyon bilgisi (grid   square)
  * Cikis Gucu
  * Ortam sicakligi
  * Aku voltajlari
  * Tarih ve saat (gercek zamani opsiyonu durumunda
  * ...
  
2. Uzaktan kumanda sifre kontrollu olacaktir
  * Sifre uzaktan degistirilebilecektir
  * Sifre tanimli bir sifre kumesinden (Orn: 10 degisik sifre) sirayla degisecektir, aktif sifre no sorgulanabilecektir
  * ...
  
3. Beacon sinyali AX25 olarak da gonderilecektir
  * AX25 beacon sinyali icinde rolenin tum ayarlarinin aktif durumu bulunabilecektir
  * ...

**NOT:** Liste ilgili goruslerinizi ve eklenmesini istediginiz ozellikleri ISSUE bolumunden veya email ile bize bildiriniz. (barisdinc###gmail.com) 
