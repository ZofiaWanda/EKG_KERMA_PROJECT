# EKG_KERMA_PROJECT
Znajdziesz tu instrukcje jak zbudować swój model EKG oraz niezbędne oprogramowanie do jego obsługi

Opis projektu

Projekt umożliwia akwizycję sygnału EKG z wykorzystaniem mikrokontrolera Arduino (ja używam Nano) oraz modułu EKG (ja używam AD8232), a następnie wizualizację, zapis i analizę sygnału w środowisku MATLAB w czasie rzeczywistym.

System został zaprojektowany z myślą o zastosowaniach edukacyjnych.

Wymagane elementy sprzętowe:
→  Mikrokontroler - Arduino (np. Uno / Nano / Mega),
→  Moduł EKG np. AD8232,
→  Elektrody EKG (3 elektrody jednorazowe lub wielokrotnego użytku),
→  Przewody połączeniowe i płytka stykowa,
→  Komputer z dostępme do programu MATLAB-em
→  Przewód USB do komunikacji z mikrokontrolerem

Zawartość repozytorium

EKG_schmeat.png → schematyczny obarz modelu EKG

EKG_program_na_Arduino_NANO.ino → program dla Arduino (akwizycja sygnału, wygładzanie, transmisja szeregowa)

EKG_software.mlapp → aplikacja MATLAB do:
→  odbioru danych przez port COM,
→  przeliczania wartości ADC na napięcie,
→  wizualizacji EKG w czasie rzeczywistym,
→  zapisu i odczytu historii pomiarów,
→  eksportu danych (TXT / CSV / XLSX).

EKG_KERMA_PROJECT_INSTRUKCJA.txt →  plik do pobrania razem z EKG_software.mlapp, stanowi instrukcję do obsługi aplikacji 9która w aplikacji można otworzyć).

Konfiguracja i uruchomienie

1. Wgraj plik .ino do mikrokontrolera za pomocą Arduino IDE.
2. Podłącz moduł EKG do mikrokontrolera zgodnie z opisem pinów.
3. Uruchom aplikację MATLAB. W oknie konfiguracji wybierz:
   → port COM, do którego jest podpięty model EKG (to ten sam port przez który przegrywałyeś plik .ino do mikrokontrolera.
   → napięcie referencyjne (np. 3.3 V lub 5 V) - właściwe napieciu zasilajacego Arduino,
   → maksymalną rozdzielczość ADC dla Twojego Arduino (np. 1023 dla 10-bit, 4095 dla 12-bit).
4.  Elektrody po ciała podłącza się według następujacego schematu (dla modułu EKG AD8232):
   → Czerwona - prawa ręka,
   → Żółta - lewa ręka,
   → Zielona - prawa noga.
5.  Rozpocznij pomiar i obserwuj sygnał EKG w czasie rzeczywistym.

Obecne bezpieczne warunki pracy systemu:
Pomiar EKG musi być wykonywany wyłącznie wtedy, gdy:
    → laptop pracuje na baterii,
    → laptop jest zasilany z powerbanka.

Nie można używać (robisz to na włąsną odpowiedzialność) układu jeśli twój komputer jest połaczony z siecią elektryczną podczas akwizycji sygnału!

Jak możesz to obejść?

Kup - izolację galwaniczną USB (np. moduł izolatora USB ADUM3160), co umożliwi bezpieczne połączenie z komputerem podłączonym do sieci 230 V,
Szacunkowy koszt izolatora USB: ok. 60 zł.

Uwaga!!!
Autorka projektu nie ponosi odpowiedzialności za jakiekolwiek szkody, urazy, straty zdrowotne lub materialne wynikające z użycia, modyfikacji lub niewłaściwego zastosowania przedstawionego systemu. Projekt ma charakter edukacyjny i demonstarcyjny i nie jest certyfikowanym urządzeniem medycznym. 
Każde użycie systemu odbywa się na własną odpowiedzialność użytkownika. 
