/* Bagian 1 */

/* Deklarasi Fakta */
pria(panji).
pria(barok).
pria(qika).
pria(aqua).
pria(eriq).
pria(shelby).
pria(rifia).
pria(francesco).
pria(mauang).
pria(jamet).

wanita(frieren).
wanita(roxy).
wanita(mary).
wanita(myers).
wanita(ruby).
wanita(yennefer).
wanita(gizelle).
wanita(aihoshino).
wanita(suzy).
wanita(rhiannon).
wanita(eve).

usia(panji, 78).
usia(frieren, 75).
usia(barok, 75).
usia(roxy, 73).
usia(mary, 51).
usia(qika, 55).
usia(myers, 40).
usia(aqua, 53).
usia(ruby, 48).
usia(eriq, 50).
usia(shelby, 25).
usia(yennefer, 30).
usia(rifia, 35).
usia(gizelle, 20).
usia(aihoshino, 32).
usia(francesco, 23).
usia(suzy, 23).
usia(rhiannon, 5).
usia(eve, 10).
usia(mauang, 15).
usia(jamet, 3).

menikah(panji, frieren).
menikah(frieren, panji).
menikah(barok, roxy).
menikah(roxy, barok).
menikah(qika, mary).
menikah(mary, qika).
menikah(myers, qika).
menikah(qika, myers).
menikah(eriq, ruby).
menikah(ruby, eriq).
menikah(yennefer, rifia).
menikah(rifia, yennefer).
menikah(rifia, aihoshino).
menikah(aihoshino, rifia).
menikah(suzy, francesco).
menikah(francesco, suzy).

anak(qika, panji).
anak(qika, frieren).
anak(aqua, barok).
anak(aqua, roxy).
anak(ruby, barok).
anak(ruby, roxy).
anak(shelby, qika).
anak(shelby, mary).
anak(yennefer, qika).
anak(yennefer, mary).
anak(gizelle, qika).
anak(gizelle, myers).
anak(aihoshino, aqua).
anak(francesco, ruby).
anak(francesco, eriq).
anak(rhiannon, shelby).
anak(eve, rifia).
anak(eve, yennefer).
anak(mauang, rifia).
anak(mauang, aihoshino).
anak(jamet, francesco).
anak(jamet, suzy).

/* Deklarasi Rule */
saudara(X, Y) :- 
    anak(X, Z), 
    anak(Y, Z), 
    X \= Y.

saudaratiri(X, Y) :- 
    anak(X, A), 
    anak(Y, B), 
    anak(X, Z),
    anak(Y, Z),
    A \= B,
    X \= Y,
    menikah(Z, A),
    menikah(Z, B),
    \+ (menikah(A, B)).

kakak(X, Y) :- 
    saudara(X, Y),
    usia(X, AgeX),
    usia(Y, AgeY),
    AgeX > AgeY.

keponakan(X, Y) :- 
    anak(X, Z),
    saudara(Z, Y),
    !.

mertua(X, Y) :-
    menikah(Y, Z),
    anak(Z, X).

nenek(X, Y) :-
    wanita(X),
    anak(Z, X),
    anak(Y, Z).

keturunan(X , Y) :-
    anak(X, Y).
keturunan(X , Y) :-
    anak(X, Z),
    keturunan(Z, Y).

lajang(X) :- 
    \+ (menikah(X, _)).

anakbungsu(X) :- 
    anak(X, Z),
    anak(X, V),
    usia(X, AgeX),
    V @< Z,
    \+ (anak(Y, Z), anak(Y, V), X \= Y, usia(Y, AgeY), AgeY < AgeX).

anaksulung(X) :-
    anak(X, Z),
    anak(X, V),
    usia(X, AgeX),
    V @< Z,
    \+ (anak(Y, Z), anak(Y, V), x \= Y, usia(Y, AgeY), AgeY > AgeX).

yatimpiatu(X) :- \+ anak(X, _).
    
/* Bagian 2 */
/* 1. Exponent */
exponent(A, 0, 1) :- A \= 0.
exponent(A, 1, A).
exponent(A, B, C) :-
    B > 1,
    B1 is B - 1,
    exponent(A, B1, C1),
    C is A * C1.
   
/* 2. Growth */
punyafaktor(N, F) :- N mod F =:= 0, !.
punyafaktor(N, F) :- (F * F =< N), punyafaktor(N, F1), F1 is F + 1.

isPrime(2).
isPrime(3).
isPrime(X) :- X > 3, \+ punyafaktor(X, 2).

growth(I, _, _, 0, I) :- I > 0, !.
growth(I, G, H, T, X) :- 
    T > 0, 
    T1 is T - 1, 
    growth(I, G, H, T1, X1), 
    ((isPrime(T), X is X1 + G) ; X is X1 - H).

/* 3. Si Imut Anak Nakal */
harvestFruits(N, _, TreeNumber, _) :- TreeNumber > N, !.
harvestFruits(_, _, _, 0) :- write('Si Imut pulang sambil menangis :('), nl, !.
harvestFruits(N, Fruits, TreeNumber, FinalFruits) :-    
    ((TreeNumber mod 3 =:= 0, Mod3 is 2) ; Mod3 is 0),
    ((TreeNumber mod 4 =:= 0, Mod4 is -5); Mod4 is 0),
    ((TreeNumber mod 5 =:= 0, Mod5 is 3) ; Mod5 is 0),
    ((isPrime(TreeNumber), Prime is -10) ; Prime is 0),
    NextFruits is Fruits + Mod3 + Mod4 + Mod5 + Prime,
    TreeNumber1 is TreeNumber + 1,
    harvestFruits(N, NextFruits, TreeNumber1, FinalFruits).

/* 4. KPK */
fpb(A, 0, A) :- A > 0.
fpb(A, B, C) :- 
    A1 is B, 
    B1 is A mod B, 
    fpb(A1, B1, C).
kpk(X, Y, Z) :- fpb(X, Y, F), Z is (X * Y) / F.
/* kpk(a,b) * fpb(a,b) = a*b */ 

/* 5. Factorial */
factorial(0, 1).
factorial(1, 1).
factorial(N, X) :- 
    N > 1,
    N1 is N-1,
    factorial(N1, X1),
    X is N * X1.
    
/* 6. Make Pattern */
makePattern(N) :- makePatternBaris(0, N).

% Stop saat Row = N (basis)
generateRows(Row, N) :- Row = N, !.

%Mencetak pola dari suatu baris, terus lanjut ke baris selanjutnya (rekursi)
generateRows(Row, N) :- 
    printRow(Row, N, 0), 
    nl, 
    NextRow is Row + 1, 
    generateRows(NextRow, N).

% Cetak tiap barisnya
% Stop saat kolom = N (basis)
printRow(_, N, Col) :- Col = N, !.

% Hitung jarak dari tiap sisi
printRow(Row, N, Col) :- 
    findMin(Row, Col, MinRC), 
    findMin(N - Row - 1, N - Col - 1, MinEdge), 
    findMin(MinRC, MinEdge, MinVal),
    Element is MinVal + 1,
    write(Element), write(' '),
    NextCol is Col + 1,
    printRow(Row, N, NextCol).

% Fungsi mencari nilai min
findMin(A, B, Min) :- (A =< B, Min is A ; Min is B).

/* Bagian 3 */
/* 1. List Statistic */

% 1a. Min
min([X], X) :- !.
min([H|T], Min) :- min(T, MinT), findMin(H, MinT, Min).

% 1b. Max
findMax(A, B, Max) :- (A >= B, Max is A ; Max is B).

max([X], X) :- !.
max([H|T], Max) :- max(T, MaxT), findMax(H, MaxT, Max).


% 1c. Range
range([_], 0) :- !.
range([H|T], R) :-
    min([H|T], Min),
    max([H|T], Max),
    R is Max - Min.

% 1d. Count
count([], 0) :- !.
count([_|T], Count):- count(T, C1), Count is C1 + 1.

% 1e. Sum
sum([], 0) :- !.
sum([H|T], Sum) :- sum(T, SumT), Sum is H + SumT.   

/* 2. List Manipulation */
% 2a. MergeSort
mergeSort([], [], []) :- !. % Basis

% Kalo salah satu kosong, hasilnya L
mergeSort([], L, Result) :- Result = L, !.
mergeSort(L, [], Result) :- Result = L, !.

% Merge-sort algo
mergeSort([H1|T1], [H2|T2], [H1|Result]) :-
    H1 =< H2,
    mergeSort(T1, [H2|T2], Result).

mergeSort([H1|T1], [H2|T2], [H2|Result]) :-
    H1 > H2,
    mergeSort([H1|T1], T2, Result).

% 2b. filterArray
filterArray([], _, _, []).

% Cek berdasarkan syarat
filterArray([H|T], Element1, Element2, [H|Result]) :-
    H > Element1,
    H mod Element2 =:= 0,
    filterArray(T, Element1, Element2, Result). 

filterArray([_|T], Element1, Element2, Result) :-
    filterArray(T, Element1, Element2, Result).
% Gak di-flter, skip elemen

% 2c. reverse
% Fungsi antara append
appendTo([], L, L).
appendTo([H | T], L, [H | Result]) :-
    appendTo(T, L, Result).

reverse_list([], []).
reverse_list([H | T], Result) :- 
    reverse_list(T, RevT),
    appendTo(RevT, [H], Result).


% 2d. cekPalindrom
cekPalindrom([]).
cekPalindrom([_]).
cekPalindrom(L) :- 
    reverse_list(L, Rev),
    L = Rev.

% 2e. rotate
% fungsi antara insertLast
insertLast(Elmt, [], [Elmt]) :- !.
insertLast(Elmt, [Head|Tail], [Head|Res]) :- insertLast(Elmt, Tail, Res), !.

%%% Fungsi pembantu rotateSekali
rotateSekali([], []).
rotateSekali([H|T], Result) :- insertLast(H, T, Result).

rotate([], _, []) :- !.
rotate(List, 0, List) :- !.

rotate(List, N, Result) :- 
    count(List, L), 
    Neff is (N + L) mod L,
    rotateSekali(List, Temp),
    NextN is Neff - 1,
    rotate(Temp, NextN, Result).


%% 2f. Mapping
% fungsi antara insertFirst
insertFirst(Elmt, [], [Elmt]) :- !.
insertFirst(Elmt, List, [Elmt|List]) :- !.

% fungsi antara mapNilai
mapNilai(Nilai, Huruf) :-  (
    Nilai >= 80, Huruf = 'A';
    Nilai >= 70, Huruf = 'B';
    Nilai >= 60, Huruf = 'C';
    Nilai >= 50, Huruf = 'D';
    Huruf = 'E'
).

% fungsi antara mapArrayNilai
mapArrayNilai([], []).
mapArrayNilai([Head|Tail], [Indeks|Res]) :- mapNilai(Head, Indeks), mapArrayNilai(Tail, Res).

% fungsi pembantu avg
avg(L, Rata) :- sum(L, Sum), count(L, Count), Rata is Sum / Count.

prosesMahasiswa(Name, Grades, Result) :- 
    insertLast(Name, [], PrevResult1), 
    mapArrayNilai(Grades, Indeks), insertLast(Indeks, PrevResult1, PrevResult2), 
    avg(Grades, Rata), insertLast(Rata, PrevResult2, PrevResult3),
    ((Rata >= 80, Status = 'Pass'); Status = 'Fail'), 
    insertLast(Status, PrevResult3, Result).