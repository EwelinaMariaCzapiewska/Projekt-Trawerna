# Uruchamiaj tym 
clang++ main.cpp -o main && ./main 
clang++ test.cpp -o test && ./test

## Project Context
This is simple C++ console application for managing a tavern/restaurant with order management, menu.

# Podanie wstępnych danych (osoba 1)

* wyświetlanie danych restauracji (nazwa, adres, właściciel,
itp.)
* użytkownik wpisuje swoje imię
* użytkownik wybiera, czy danie ma być dostarczone na miejscu
czy na dowóz
* w przypadku wyboru na miejscu, podanie numeru stolika
* w przypadku wyboru dowozu, należy podać adres oraz preferowana
godzinę z podanego zakresu. Godzina oraz data powinny być
sprawdzane, czy mieszczą się w zakresie (godziny działania
restauracji, tylko dzisiaj itp)


# Wybór dań z menu (osoba 2)

* menu pobierane z pliku, gdzie każda pozycja ma nazwę, cenę za
porcje oraz główne składniki
* użytkownik może wybrać co najmniej 1 danie
* użytkownik ma możliwość wybrania liczby porcji danego dania
(liczby całkowite w zakresie)
* użytkownik ma możliwość usunięcia wybranej pozycji *
* po każdym wyborze cena zbiorcza jest aktualizowana
* po wprowadzeniu wyborów, należy je potwierdzić
* użytkownik może wyjść z aplikacji w dowolnym momencie


# Podsumowanie zamówienia (osoba 3)

* aplikacja wyświetla informacje o planowanym czasie
dostawy/przygotowania
* aplikacja zapisuje rachunek w pliku .txt (kwota, zamówione
dania itp)
* aplikacja ulega zamknięciu po wyświetleniu komunikatu i
oczekiwaniu na naciśnięcie dowolnego klawisza





