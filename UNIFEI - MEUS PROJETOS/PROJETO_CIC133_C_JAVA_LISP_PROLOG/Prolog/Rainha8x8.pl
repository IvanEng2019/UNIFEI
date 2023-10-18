solucaonrainhas([]).

solucaonrainhas([X/Y | OUTRASCOORDENADAS]) :-
solucaonrainhas(OUTRASCOORDENADAS),
membro(Y,[1,2,3,4,5,6,7,8]),
naopodeatacar(X/Y,OUTRASCOORDENADAS).

naopodeatacar(_,[]).

naopodeatacar(X/Y,[X1/Y1|OUTRASCOORDENADAS]) :-
Y=\=Y1,
Y1-Y=\=X1-X,
Y1-Y=\=X-X1,
naopodeatacar(X/Y,OUTRASCOORDENADAS).

membro(X,[X|LISTA]).
membro(X,[Y|LISTA]) :- membro(X,LISTA).

linhadivisoria :- write(' +---------------+'),nl.

tabelainferior :-
write(' +---------------+'),nl,
write('  1 2 3 4 5 6 7 8 '),nl.

rainha8(X,[X|LISTA]) :- X == 1/8,write('8|R|/|/|/|/|/|/|/|'),nl.
rainha8(X,[X|LISTA]) :- X == 2/8,write('8|/|R|/|/|/|/|/|/|'),Nl.
Rainha8(X,[X|LISTA]) :- X == 3/8,write('8|/|/|R|/|/|/|/|/|'),nl.
rainha8(X,[X|LISTA]) :- X == 4/8,write('8|/|/|/|R|/|/|/|/|'),nl.
rainha8(X,[X|LISTA]) :- X == 5/8,write('8|/|/|/|/|R|/|/|/|'),nl.
rainha8(X,[X|LISTA]) :- X == 6/8,write('8|/|/|/|/|/|R|/|/|'),nl.
rainha8(X,[X|LISTA]) :- X == 7/8,write('8|/|/|/|/|/|/|R|/|'),nl.
rainha8(X,[X|LISTA]) :- X == 8/8,write('8|/|/|/|/|/|/|/|R|'),nl.
rainha8(X,[Y|LISTA]) :- rainha8(X,LISTA).

rainha7(X,[X|LISTA]) :- X == 1/7,write('7|R|/|/|/|/|/|/|/|'),nl.
rainha7(X,[X|LISTA]) :- X == 2/7,write('7|/|R|/|/|/|/|/|/|'),nl.
rainha7(X,[X|LISTA]) :- X == 3/7,write('7|/|/|R|/|/|/|/|/|'),nl.
rainha7(X,[X|LISTA]) :- X == 4/7,write('7|/|/|/|R|/|/|/|/|'),nl.
rainha7(X,[X|LISTA]) :- X == 5/7,write('7|/|/|/|/|R|/|/|/|'),nl.
rainha7(X,[X|LISTA]) :- X == 6/7,write('7|/|/|/|/|/|R|/|/|'),nl.
rainha7(X,[X|LISTA]) :- X == 7/7,write('7|/|/|/|/|/|/|R|/|'),nl.
rainha7(X,[X|LISTA]) :- X == 8/7,write('7|/|/|/|/|/|/|/|R|'),nl.
rainha7(X,[Y|LISTA]) :- rainha7(X,LISTA).

rainha6(X,[X|LISTA]) :- X == 1/6,write('6|R|/|/|/|/|/|/|/|'),nl.
rainha6(X,[X|LISTA]) :- X == 2/6,write('6|/|R|/|/|/|/|/|/|'),nl.
rainha6(X,[X|LISTA]) :- X == 3/6,write('6|/|/|R|/|/|/|/|/|'),nl.
rainha6(X,[X|LISTA]) :- X == 4/6,write('6|/|/|/|R|/|/|/|/|'),nl.
rainha6(X,[X|LISTA]) :- X == 5/6,write('6|/|/|/|/|R|/|/|/|'),nl.
rainha6(X,[X|LISTA]) :- X == 6/6,write('6|/|/|/|/|/|R|/|/|'),nl.
rainha6(X,[X|LISTA]) :- X == 7/6,write('6|/|/|/|/|/|/|R|/|'),nl.
rainha6(X,[X|LISTA]) :- X == 8/6,write('6|/|/|/|/|/|/|/|R|'),nl.
rainha6(X,[Y|LISTA]) :- rainha6(X,LISTA).

rainha5(X,[X|LISTA]) :- X == 1/5,write('5|R|/|/|/|/|/|/|/|'),nl.
rainha5(X,[X|LISTA]) :- X == 2/5,write('5|/|R|/|/|/|/|/|/|'),nl.
rainha5(X,[X|LISTA]) :- X == 3/5,write('5|/|/|R|/|/|/|/|/|'),nl.
rainha5(X,[X|LISTA]) :- X == 4/5,write('5|/|/|/|R|/|/|/|/|'),nl.
rainha5(X,[X|LISTA]) :- X == 5/5,write('5|/|/|/|/|R|/|/|/|'),nl.
rainha5(X,[X|LISTA]) :- X == 6/5,write('5|/|/|/|/|/|R|/|/|'),nl.
rainha5(X,[X|LISTA]) :- X == 7/5,write('5|/|/|/|/|/|/|R|/|'),nl.
rainha5(X,[X|LISTA]) :- X == 8/5,write('5|/|/|/|/|/|/|/|R|'),nl.
rainha5(X,[Y|LISTA]) :- rainha5(X,LISTA).

rainha4(X,[X|LISTA]) :- X == 1/4,write('4|R|/|/|/|/|/|/|/|'),nl.
rainha4(X,[X|LISTA]) :- X == 2/4,write('4|/|R|/|/|/|/|/|/|'),nl.
rainha4(X,[X|LISTA]) :- X == 3/4,write('4|/|/|R|/|/|/|/|/|'),nl.
rainha4(X,[X|LISTA]) :- X == 4/4,write('4|/|/|/|R|/|/|/|/|'),nl.
rainha4(X,[X|LISTA]) :- X == 5/4,write('4|/|/|/|R|/|/|/|/|'),nl.
rainha4(X,[X|LISTA]) :- X == 6/4,write('4|/|/|/|/|/|R|/|/|'),nl.
rainha4(X,[X|LISTA]) :- X == 7/4,write('4|/|/|/|/|/|/|R|/|'),nl.
rainha4(X,[X|LISTA]) :- X == 8/4,write('4|/|/|/|/|/|/|/|R|'),nl.
rainha4(X,[Y|LISTA]) :- rainha4(X,LISTA).

rainha3(X,[X|LISTA]) :- X == 1/3,write('3|R|/|/|/|/|/|/|/|'),nl.
rainha3(X,[X|LISTA]) :- X == 2/3,write('3|/|R|/|/|/|/|/|/|'),nl.
rainha3(X,[X|LISTA]) :- X == 3/3,write('3|/|/|R|/|/|/|/|/|'),nl.
rainha3(X,[X|LISTA]) :- X == 4/3,write('3|/|/|/|R|/|/|/|/|'),nl.
rainha3(X,[X|LISTA]) :- X == 5/3,write('3|/|/|/|R|/|/|/|/|'),nl.
rainha3(X,[X|LISTA]) :- X == 6/3,write('3|/|/|/|/|/|R|/|/|'),nl.
rainha3(X,[X|LISTA]) :- X == 7/3,write('3|/|/|/|/|/|/|R|/|'),nl.
rainha3(X,[X|LISTA]) :- X == 8/3,write('3|/|/|/|/|/|/|/|R|'),nl.
rainha3(X,[Y|LISTA]) :- rainha3(X,LISTA).

rainha2(X,[X|LISTA]) :- X == 1/2,write('2|R|/|/|/|/|/|/|/|'),nl.
rainha2(X,[X|LISTA]) :- X == 2/2,write('2|/|R|/|/|/|/|/|/|'),nl.
rainha2(X,[X|LISTA]) :- X == 3/2,write('2|/|/|R|/|/|/|/|/|'),nl.
rainha2(X,[X|LISTA]) :- X == 4/2,write('2|/|/|/|R|/|/|/|/|'),nl.
rainha2(X,[X|LISTA]) :- X == 5/2,write('2|/|/|/|/|R|/|/|/|'),nl.
rainha2(X,[X|LISTA]) :- X == 6/2,write('2|/|/|/|/|/|R|/|/|'),nl.
rainha2(X,[X|LISTA]) :- X == 7/2,write('2|/|/|/|/|/|/|R|/|'),nl.
rainha2(X,[X|LISTA]) :- X == 8/2,write('2|/|/|/|/|/|/|/|R|'),nl.
rainha2(X,[Y|LISTA]) :- rainha2(X,LISTA).

rainha1(X,[X|LISTA]) :- X == 1/1,write('1|R|/|/|/|/|/|/|/|'),nl.
rainha1(X,[X|LISTA]) :- X == 2/1,write('1|/|R|/|/|/|/|/|/|'),nl.
rainha1(X,[X|LISTA]) :- X == 3/1,write('1|/|/|R|/|/|/|/|/|'),nl.
rainha1(X,[X|LISTA]) :- X == 4/1,write('1|/|/|/|R|/|/|/|/|'),nl.
rainha1(X,[X|LISTA]) :- X == 5/1,write('1|/|/|/|/|R|/|/|/|'),nl.
rainha1(X,[X|LISTA]) :- X == 6/1,write('1|/|/|/|/|/|R|/|/|'),nl.
rainha1(X,[X|LISTA]) :- X == 7/1,write('1|/|/|/|/|/|/|R|/|'),nl.
rainha1(X,[X|LISTA]) :- X == 8/1,write('1|/|/|/|/|/|/|/|R|'),nl.
rainha1(X,[Y|LISTA]) :- rainha1(X,LISTA).

tabuleiro(S) :-
nl,
write('Representacao Grafica para o Problema das Oito Rainhas'),
nl,
write('------------------------------------------------------'),
nl,
linhadivisoria,
rainha8(Y8,S),
linhadivisoria,
rainha7(Y7,S),
linhadivisoria,
rainha6(Y6,S),
linhadivisoria,
rainha5(Y5,S),
linhadivisoria,
rainha4(Y4,S),
linhadivisoria,
rainha3(Y3,S),
linhadivisoria,
rainha2(Y2,S),
linhadivisoria,
rainha1(Y1,S),
tabelainferior,
nl,nl,write('Lista contendo a solucao: '),nl.

imprimeresposta([1/Y1,2/Y2,3/Y3,4/Y4,5/Y5,6/Y6,7/Y7,8/Y8]).

resolveproblema(S) :-
imprimeresposta(S),
solucaonrainhas(S),
tabuleiro(S).
