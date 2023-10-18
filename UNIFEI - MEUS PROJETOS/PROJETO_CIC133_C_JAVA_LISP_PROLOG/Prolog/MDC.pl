mdc(X, X, X).
mdc(X, Y, D) :-
    X < Y,
    Y1 is Y-X,
    mdc(X, Y1, D).
mdc(X, Y, D) :-
    X > Y,
    mdc(Y, X, D).
