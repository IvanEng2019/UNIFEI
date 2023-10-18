gcd(X, 0, X):- !.
gcd(0, X, X):- !.
gcd(X, Y, D):- X > Y, !, Z is X mod Y, gcd(Y, Z, D).
gcd(X, Y, D):- Z is Y mod X, gcd(X, Z, D).
mmc(X, Y, Z):-
        D is gcd(X, Y),
	Z is abs(X * Y)/D.
