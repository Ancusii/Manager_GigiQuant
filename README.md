Proiect Proiectarea Algoritmilor-Manager de portofoliu la GigiQuant
Descrierea proiectului:
Proiectul conține 4 task-uri structurate sub forma unor interviuri pentru poziția de manager de portofoliu la compania fictivă „GigiQuant”. La fiecare sunt folosite diferite structuri de date (liste, sive, cozi, arbori binari, grafuri) și sunt dezvoltați algoritmi pentru a rezolva diferite probleme din domeniul financiar.
Pentru fiecare task am implementat câte un fișier.c și un header.h, corespunzător fișierului menționat. Fișierele au nume sugestive, precum functii_task1.c și task1h.h. Toate funcțiile corespunzătoare task-urilor sunt apelate într-un fișier main.c
Task 1: Sharpe ratio
Pentru acest task trebuie să se calculeze indicatorul Sharpe Ratio, pentru care am modelat evoluția unui portofoliu pe mai multe zile folosind o listă simplu înlănțuită. De asemenea, am introdus câteva funcții pentru a ajuta la calcul, precum calcul_zecimale, rand_mediu și calcul_volatilitate.
Task 2: Arbitraj
La acest interviu trebuie să se identifice și să se capitalizeze oportunități de arbitraj. Se dă un fișier cu numele a 3 piețe și un număr necunoscut de prețuti în ordine cronologică pentru fiecare. Este garantat că ultimul preț este din aceeași zi pentru toate fișierele și nu există zile lipsă.
Acest fișier cu prețuti trebuie prelucrat în așa fel încât să se separe piețele și să se identifice oportunitățile de arbitraj.
Pentru acest task am implementat funcții pentru stive și cozi, precum push, pop, enQueue sau creareQueue.
Pentru acest task, am folosit 3 stive, unde am introdus, pe rând, numele și valorile din zilele respective.
De asemenea, am implementat o funcție adaugare_coada, unde se adaugă într-o coadă ziua în care se află oportunitatea de arbitraj, diferența și numele orașului.
Task 3: Diversificarea portofoliului
În acest interviu se cere să se optimizeze un portofoliu prin diversificare (transformând mai multe acțiuni riscante într-un singur portofoliu.
Pentru acest task am utilizat o structură de tip arbore binar, care conține un vector de liste, un element din vector fiind asociat cu un nume de companie. De asemenea, nodul meu mai conține numarul de companii și înălțimea arborelui.
Fișierul conține o funcție pentru citirea datelor, pe care le pune în nodul root, dar și date despre companie într-un vector de liste stocks, pentru a putea să construiesc arborele.
Pentru construirea arborelui am realizat un vector de liste, astfel: dacă prețul din ziua n este mai mic decât cel din ziua n+1, voi duce acea companie în subarborele drept, alfel, spre subarborele stâng.
Pentru a găsi perechile de companii cerute am parcurs arborele și am pus într-un vector, path, calea de la root până la frunză (0 dacă sunt pe stânga și 1 dacă sunt pe dreapta).
Apoi, pentru path-ul meu inițial am folosit o funcție, cautare_inversa, pentru a găsi path-ul oglindă și de a găsi nodul corespunzător.
Aceste noduri le pun într-un vector el (deoarece pot avea mai multe companii într-un singur nod), care conține nodul găsit și oglinditul lui, vector pe care îl ordonez după pentru a afișa perechile de noduri corespunzător.
La final, se afișează vectorul el cu perechile cerute.
Task 4: Lanțuri Markov
În acest task se construiesc intervale de preț (stări Markov), matricea de tranziție și probabulitatea ca acțiunea să ajungă din intervalul lui Pstart în intervalul Ptarget în fiecare zi timp de K zile.
Pentru citirea datelor am observat o relație între prețuri, prețul minim și maxim si distanța din interval, astfel încât am putut construi matricea inițială.
Apoi am transformat matricea mea inițială în matrice markov.
După aceea am parcurs graful meu utilizând matricea creată, utilizându-mă pe parcurs de doi vectori, prob_c, probabilitatea curentă și prob_urm, probabilitatea următoare, pentru a calcula și transmite probabilitățile către noduri în fiecare zi.
La final, afișez probabilitatea nodului meu corespunzător intervalului în care se află
Compilare: gcc main.c functii_task1.c functii_task2.c functii_task3.c functii_task4.c -o test
Îmbunătățiri:
Fișierul funcții_task3.c este destul de greu de urmărit, iar funcțiile sunt destul de complicate. Cred că s-ar putea face mai puțin complicat, fără să folosesc vectori de liste.
