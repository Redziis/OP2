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

CPU - i5-9300H 4 cores 8 threads 2.4 ghz<br/>
RAM - Kingston HyperX Impact 2x8 GB 2600MHZ<br/>
SSD m.2 samsung mzvlb256hbhq-000l2<br/>

## Testavimo rezultatai

#### 1 strategija:

#### Vector:

|Studentų skaičius |  Nuskaitymo laikas | Skaičiavimas laikas | Rūšiavimo laikas | Įrašimo į buferį laikas | Pilnas įrašimo laikas |
| ---------------- |  ----------------- | ------------------- | ---------------- | ----------------------- | --------------------- |
| 1000             |  0.018525 s        | 0.000531 s          | 0.000665 s       |  0.000829 s             | 0.001698 s            |
| 10000            |    0.048041 s      |    0.000685 s       |   0.007394 s     |    0.007873 s           |    0.011220 s         |
| 100000           |     0.615828 s     |     0.002930 s      |      0.078734 s  |  0.082460 s             |   0.097304 s          |
| 1000000          |   4.115486 s       |    0.018452 s       |   0.994884 s     |   0.802577 s            |    0.924011 s         |
| 10000000         |     26.890814 s    |     0.086319 s      | 5.485796 s       |   4.382828 s            |      4.958608 s       |

#### List:

|Studentų skaičius |  Nuskaitymo laikas | Skaičiavimas laikas | Rūšiavimo laikas | Įrašimo į buferį laikas | Pilnas įrašimo laikas |
| ---------------- |  ----------------- | ------------------- | ---------------- | ----------------------- | --------------------- |
| 1000             |  0.019897 s        |0.000136 s           | 0.000342 s       | 0.000859 s              |0.001933 s             |
| 10000            |   0.049986 s       |    0.000558 s       |   0.004659 s     |   0.007986 s            |   0.010934 s          |
| 100000           |     0.609269 s     |    0.006022 s       |     0.067790 s   |  0.094484 s             |   0.107240 s          |
| 1000000          |   4.303545 s       |    0.032977 s       |    0.974123 s    |   0.835239 s            |    0.968338 s         |
| 10000000         |       26.807541 s  |     0.202444 s      | 6.424478 s       |   4.688235 s            |       5.230455 s      |

#### Deque:

|Studentų skaičius |  Nuskaitymo laikas | Skaičiavimas laikas | Rūšiavimo laikas | Įrašimo į buferį laikas | Pilnas įrašimo laikas |
| ---------------- |  ----------------- | ------------------- | ---------------- | ----------------------- | --------------------- |
| 1000             |  0.019134 s        | 0.000207 s          | 0.000647 s       |  0.000862 s             | 0.002151 s            |
| 10000            |    0.044909 s      |    0.000397 s       |  0.008070 s      |    0.008108 s           |   0.011065 s          |
| 100000           |     0.609020 s     |     0.004744 s      |      0.100477 s  |  0.083608 s             |   0.096319 s          |
| 1000000          |   4.110294 s       |    0.030471 s       |    1.359355 s    |   0.865812 s            |    0.992446 s         |
| 10000000         |       27.120232 s  |    0.201896 s       | 7.768315 s       |   4.511575 s            |      5.011196 s       |


#### 2 strategija:

#### Vector:

|Studentų skaičius |  Nuskaitymo laikas | Skaičiavimas laikas | Rūšiavimo laikas | Įrašimo į buferį laikas | Pilnas įrašimo laikas |
| ---------------- |  ----------------- | ------------------- | ---------------- | ----------------------- | --------------------- |
| 1000             |  0.007720 s        | 0.000188 s          | 0.000597 s       | 0.000834 s              | 0.001869 s            |
| 10000            |    0.039074 s      |    0.000365 s       |   0.005998 s     |    0.007923 s           |    0.010746 s         |
| 100000           |     0.548156 s     |     0.003233 s      |     0.065653 s   |  0.078402 s             |    0.091283 s         |
| 1000000          |   3.792698 s       |    0.016268 s       |    0.875766 s    |  0.754080 s             |    0.852496 s         |
| 10000000         |      24.485012 s   |     0.079543        | 4.940063 s       |   4.115565 s            |       4.653740 s      |

#### List:

|Studentų skaičius |  Nuskaitymo laikas | Skaičiavimas laikas | Rūšiavimo laikas | Įrašimo į buferį laikas | Pilnas įrašimo laikas |
| ---------------- |  ----------------- | ------------------- | ---------------- | ----------------------- | --------------------- |
| 1000             |  0.007212 s        | 0.000217 s          | 0.000285 s       |  0.000996 s             |  0.004266 s           |
| 10000            |    0.039058 s      |    0.000630 s       |   0.003773 s     |    0.008353 s           |    0.011525 s         |
| 100000           |     0.567019 s     |     0.005614 s      |      0.065533 s  |  0.088193 s             |   0.101014 s          |
| 1000000          |   3.745888 s       | 0.035473 s          |    1.029524 s    |   0.832052 s            |     0.934534 s        |
| 10000000         |       24.862976 s  |     0.220341 s      | 7.123599 s       |   4.502971 s            |      5.000355 s       |

#### Deque:

|Studentų skaičius |  Nuskaitymo laikas | Skaičiavimas laikas | Rūšiavimo laikas | Įrašimo į buferį laikas | Pilnas įrašimo laikas |
| ---------------- |  ----------------- | ------------------- | ---------------- | ----------------------- | --------------------- |
| 1000             |  0.007146 s        | 0.000179 s          | 0.000624 s       | 0.000860 s              |0.002058 s             |
| 10000            |     0.038378 s     |     0.000398 s      |  0.006895 s      |    0.008412 s           |    0.011029 s         |
| 100000           |    0.577493 s      |      0.005186 s     |      0.094161 s  |  0.081560 s             |   0.095201 s          |
| 1000000          |   3.726173 s       |    0.030681 s       |   1.230832 s     |   0.792141 s            |    0.885720 s         |
| 10000000         |      24.494511 s   |     0.214100 s      | 7.127771 s       |   4.356007 s            |      4.822920 s       | 

## Įdiegimas
Visus atsiustus failus įdėkite į viena atskyra aplankalą ir CMake.   
CMake aplinkoje į ``` Where is the source code``` įrašykite kelią iki atsiustų failų, o į ``` Where to build the binaries``` įrašykite kelią kur norite gauti veikiančia programa.

![Screenshot 2021-06-17 181319](https://user-images.githubusercontent.com/73912517/122425074-e7267280-cf97-11eb-9e4a-b89bf7bf92a5.png)

Toliau paspauskite Configure ir pasirinkite kokiai aplinkai generuosite projektą.

![Screenshot 2021-06-17 181335](https://user-images.githubusercontent.com/73912517/122425226-01605080-cf98-11eb-851f-4497f8e4d811.png)

Galiausiai spaudžiame Generate ir truputį palaukiame kol visi reikiami failai atsiras mūsų anksčiau pasirinktame aplanke.

## Versijos

[v0.1](https://github.com/Redziis/OP/tree/v0.1).<br/>
[v0.2](https://github.com/Redziis/OP/tree/v0.2).<br/>
[v0.3](https://github.com/Redziis/OP/tree/v0.3).<br/>
[v0.4](https://github.com/Redziis/OP/tree/v0.4).<br/>
[v0.5](https://github.com/Redziis/OP/tree/v0.5).<br/>
[v1.0](https://github.com/Redziis/OP/tree/v1.0).<br/>
