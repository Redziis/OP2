# Studentų pažymių skaičiuotuvas

## Funkcijos

Programa geba apskaičiuoti studentų pažymių vidurkį arba medianą, suteikiant vartotojui galimybę pasirinkti.

Duomenys įvedami ranka arba nuskaitomi iš failo.

Vartotojas prašomas įvesti studentų vardą ir pavardę, pažymius, bei turi galimybę pasirinkti, kad pažymiai būtų sugeneruojami atsitiktiniu būdu.

Galima generuoti kursiokai.txt failą, o rezultatas išvedamas į kietiakai.txt ir vargšiukai.txt

## Programos paleidimas

- Parsisiųskite programą zip formatu ir ją išsiarchyvuokite
- Programos kodą sukompiliuokite per komandinę eilute ar jums prieinamą IDE
- Gautą vykdomąjį failą paleiskite ir vykdykite nurodytas instrukcijas

> g++ array.cpp -o array
> 
> ./array

## Programos pavyzdys

![SC](https://user-images.githubusercontent.com/73912517/108632874-c7fc5600-7479-11eb-9da1-7adbdbd22efd.png)

## Testavimas

Paleisti testavimo režimą galima per komandine eilutė į vedus flag’ą test1 arba test2 (priklausomai kurią strategiją norite patikrinti) ir konteinerį norimą patikrinti.

Paleidus testavimo režimą programoje bus sugeneruoti 1000, 10000, 1000000, 10000000 studentų failai ir išmatuotas jų apdorojimo laikas pasirinktam konteineriui. Jeigu studentų failai jau egzistuoja nauji nebus generuojami.

#Sistemos parametrai

CPU - i5-9300H 4 cores 8 threads 2.4 ghz/
RAM - Kingston HyperX Impact 2x8 GB 2600MHZ
SSD m.2 samsung mzvlb256hbhq-000l2

## Testavimo rezultatai

	1000	10000	100000	1000000	10000000
Vector					
Nuskaitymas	0.016s	0.095s	1.02s	8.87s	64.654s
Rūšiavimas	0.122s	0.01s	0.059s	0.776s	8.522s
List					
Nuskaitymas	0.014s	0.148s	1.232s	7.529s	87.119s
Rūšiavimas	0.001s	0.009s	0.079s	0.661s	6.954s
Deque					
Nuskaitymas	0.012s	0.102s	1.113s	8.552s	87.766s
Rūšiavimas	0.001s	0.009s	0.071s	0.606s	6.246s


## Versijos

[v0.1](https://github.com/Redziis/OP/tree/v0.1).<br/>
[v0.2](https://github.com/Redziis/OP/tree/v0.2).<br/>
[v0.3](https://github.com/Redziis/OP/tree/v0.3).<br/>
[v0.4](https://github.com/Redziis/OP/tree/v0.4).<br/>
[v0.5](https://github.com/Redziis/OP/tree/v0.5).<br/>
[v1.0](https://github.com/Redziis/OP/tree/v1.0).<br/>
