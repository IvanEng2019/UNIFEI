mmc(X,X,X).

mmc(X, Y, Z):-
    Z is abs(X*Y)/gcd(X,Y).

gcd(X, X, X).

gcd(X, Y, D):-
    X < Y,
    Y1 is Y-X,
    gcd(X, Y1, D).

gcd(X, Y, D):-
    X > Y,
    gcd(Y, X, D).


