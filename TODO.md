### Tema 0

- [X] Nume proiect (poate fi schimbat ulterior)
- [X] Scurtă descriere a temei alese, ce v-ați propus să implementați

## Tema 1

#### Cerințe
- [X] definirea a minim 3-4 clase folosind compunere
- [X] constructori de inițializare
- [X] pentru o clasă: constructor de copiere, `operator=` de copiere, destructor
<!-- - [ ] pentru o altă clasă: constructor de mutare, `operator=` de mutare, destructor -->
<!-- - [ ] pentru o altă clasă: toate cele 5 funcții membru speciale -->
- [X] `operator<<` pentru toate clasele pentru afișare (std::ostream)
- [X] cât mai multe `const` (unde este cazul)
- [X] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese
- [X] scenariu de utilizare a claselor definite:
    - crearea de obiecte și apelarea funcțiilor membru publice în main
    - vor fi adăugate în fișierul `tastatura.txt` exemple de date de intrare de la tastatură (dacă există)
- [X] tag de `git`: de exemplu `v0.1`
- [X] serviciu de integrare continuă (CI); exemplu: GitHub Actions

## Tema 2

#### Cerințe
- [X] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [ ] moșteniri
    - [X] clasă cu atribut de tip pointer la o clasă de bază cu derivate
    - [X] funcții virtuale (pure) apelate prin pointeri de bază din clasa de mai sus, constructori virtuali (clone)
        - minim o funcție virtuală va fi **specifică temei** (e.g. nu simple citiri/afișări)
    - [X] apelarea constructorului din clasa de bază din constructori din derivate
    - [X] smart pointers
    - [ ] `dynamic_cast`
- [X] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
- [X] excepții
    - [X] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim 2 clase pentru erori specifice
    - [X] utilizare cu sens: de exemplu, `throw` în constructor, `try`/`catch` în `main`
- [X] funcții și atribute `static`
- [X] STL
- [X] cât mai multe `const`
- [X] la sfârșit: commit separat cu adăugarea unei noi derivate fără a modifica restul codului
- [ ] tag de `git`: de exemplu `v0.2`

## Tema 3

#### Cerințe
- [X] 2 șabloane de proiectare (design patterns)
- [X] o funcție șablon (template) cu sens; minim 2 instanțieri
- [X] o clasă șablon cu sens; minim 2 instanțieri
<!-- - [ ] o specializare pe funcție/clasă șablon -->
- [X] tag de `git`: de exemplu `v0.3` sau `v1.0`
