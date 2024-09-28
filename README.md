*PA - Tema 2
*Samson Alexandru-Valentin
*322CC

-Problema 1:
    Solutia aleasa utilizeaza o abordare de parcurgere in adancime pentru a
    explora fiecare nod si a calcula numarul de cai de la un nod la altul.
    In primul rand, se citesc muchiile din ambele grafuri si se adauga invers in
    listele de adiacenta. Apoi, se initializeaza numarul de cai de la nodul de
    start la el insusi cu 1 si se adauga nodul de sfarsit in stiva pentru a
    incepe parcurgerea in adancime.
    In timpul parcurgerii, pentru fiecare nod, se verifica daca mai are vecini cu
    care sa actualizeze numarul de cai. Daca vecinul nu a fost vizitat, se adauga
    in stiva. Daca vecinul a fost vizitat si muchia curenta este comuna in ambele
    grafuri, se actualizeaza numarul de cai pentru nodul curent si se elimina
    vecinul din lista de adiacenta. In final, se afiseaza numarul de lanturi
    elementare comune pentru nodul de sfarsit.
    Complexitatea temporala a solutiei este O(m * log m), unde m este numarul de
    muchii, deoarece fiecare nod si muchie este procesat o singura data.
    Complexitatea spatiala este O(n + m), unde n este numarul de noduri, deoarece
    se stocheaza lista de adiacenta, numarul de cai si starea de vizitare pentru
    fiecare nod.

-Problema 2:
    Solutia aleasa utilizeaza o abordare de parcurgere in adancime pentru a gasi
    lungimea maxima a caii intre doua noduri intr-un graf. In primul rand, se
    citesc nodurile de start si de sfarsit, x si y, si se indexeaza daca nu au
    fost inca indexate. Apoi, se citesc muchiile din fisier si pentru fiecare
    muchie, se verifica daca nodurile au fost deja indexate. Daca nu, se indexeaza
    si se adauga muchia inversa in lista de adiacenta. Dupa aceea, se initializeaza
    lungimea maxima a caii de la nodul x la el insusi cu 1 si se adauga nodul y in
    stiva pentru a incepe parcurgerea in adancime. In timpul parcurgerii, pentru
    fiecare nod, se verifica daca mai are vecini cu care nu a actualizat lungimea
    sa maxima. Daca vecinul nu a fost vizitat, se adauga in stiva. Daca vecinul a
    fost vizitat si lungimea maxima a caii pana la el nu este 0, se actualizeaza
    lungimea maxima a caii pana la nodul curent. In final, se afiseaza lungimea
    maxima a caii de la nodul x la nodul y.
    Complexitatea temporala a solutiei este O(m * log m), unde m este numarul de
    muchii, deoarece fiecare nod si muchie este procesat o singura data.
    Complexitatea spatiala este O(n + m), unde n este numarul de noduri, deoarece
    se stocheaza lista de adiacenta, lungimea maxima a caii si starea de vizitare
    pentru fiecare nod.

-Problema 3:
    Solutia aleasa utilizeaza algoritmul Dijkstra pentru a calcula distantele
    minime de la fiecare nod de start la toate celelalte noduri. In primul rand,
    se citesc muchiile si se adauga in listele de adiacenta. Apoi, se calculeaza
    distantele minime de la nodurile de start la toate celelalte noduri folosind
    algoritmul Dijkstra. Dupa aceea, se initializeaza distanta minima cu o valoare
    mare si se itereaza peste punctul de intersectie al drumurilor de la nodurile
    de start la nodul de sfarsit, combinand costurile si actualizand solutia
    minima. In final, se afiseaza suma minima a drumurilor.
    Complexitatea temporala a solutiei este O((n + m) * log m), unde n este
    numarul de noduri si m este numarul de muchii, deoarece algoritmul Dijkstra are
    o complexitate temporala de O((n + m) * log m) si fiecare muchie este procesata
    o singura data.
    Complexitatea spatiala este O(n + m), deoarece se stocheaza lista de adiacenta
    si distantele minime pentru fiecare nod.

-Problema 4:
    Solutia aleasa utilizeaza o implementare a algoritmului Tarjan pentru gasirea
    componentelor tare conexe intr-un graf. In contextul problemei, fiecare nod din
    graf reprezinta o persoana si o regula asociata cu aceasta. In functia
    SCCUtil, se parcurg vecinii fiecarui nod si se actualizeaza timpul minim de
    vizitare. Daca un nod este radacina unei componente tare conexe, se elimina
    toate nodurile din stiva si se adauga in lista de componente tare conexe.
    Functia findSCCs parcurge toate nodurile si gaseste componentele tare conexe
    folosind functia SCCUtil. In functia main, se citesc muchiile si se adauga in
    lista de adiacenta. Se construieste un nou graf in functie de reguli, unde
    fiecare nod are doua reprezentari: una pentru prezenta persoanei si una pentru
    absenta ei. Vom considera ca k = prezent, iar k + n = absent. Pentru regula
    0, punem arc de la x + n la y si de la y + n la x. Pentru regula 1, punem arc
    de la x la y + n si de la y la x. Pentru regula 2, punem arc de la y la x + n
    si de la x la y. Pentru regula 3, punem arc de la x la y + n si de la y la x +
    n. Apoi se gasesc toate componentele tare conexe in noul graf. Se
    parcurg toate componentele tare conexe si se adauga in lista de invitati
    persoanele ale caror noduri ce reprezinta prezenta se gasesc inaintea nodurilor
    ce reprezinta absenta in parcurgerea componentelor tare conexe. In final, se
    afiseaza numarul de persoane invitate si lista lor.
    Complexitatea temporala a acestui algoritm este O(n + m), unde n este numarul
    de noduri si m este numarul de muchii, deoarece fiecare nod si fiecare muchie
    sunt vizitate o singura data.
    Complexitatea spatiala este O(n + m), deoarece se stocheaza timpul de
    descoperire, timpul minim de vizitare, stiva si lista de adiacenta pentru
    fiecare nod.
