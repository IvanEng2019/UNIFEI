mmc(X, X, X).
mmc(X, Y, Z) :-
	Z is abs(X * Y) / gcd(X,Y).
