# AdamAsmaca
Bu proje, klasik Adam Asmaca oyununun C++ ile gerçekleştirilmiş bir versiyonudur. Oyun, kullanıcının gizli bir kelimeyi tahmin etmeye çalıştığı interaktif bir konsol uygulamasıdır.

## Özellikler

- Rastgele kelime seçimi: Oyun her başladığında farklı bir kelime seçilir.
- Dinamik zorluk seviyesi: Tahmin hakkı, seçilen kelimenin uzunluğuna göre belirlenir.
- Kullanıcı dostu arayüz: Oyun durumu, kalan haklar ve önceki tahminler sürekli güncellenir.
- Harf kontrolü: Daha önce tahmin edilen harfler ve geçersiz girişler kontrol edilir.

## Nasıl Oynanır

1. Oyun başladığında, gizli kelime için alt çizgiler gösterilir.
2. Her turda bir harf tahmin edin.
3. Doğru tahminler kelimede görünür hale gelir.
4. Yanlış tahminler kalan hakkınızı azaltır.
5. Kelimeyi tamamen doğru tahmin ederseniz veya haklarınız biterse oyun sona erer.

## Teknik Detaylar

- Dil: C++
- Kullanılan kütüphaneler: iostream, string, algorithm, cctype, random
- Rastgele kelime seçimi için modern C++ rastgele sayı üreteci kullanılmıştır.

Bu proje, C++ programlama becerilerimi geliştirmek ve temel oyun mantığını uygulamak için oluşturulmuştur. Kodun okunabilirliği ve verimlilik göz önünde bulundurularak yazılmıştır.
