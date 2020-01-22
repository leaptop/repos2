parent("Jon","Bob").
parent("Mary","Bob").
parent("Mary","Ann").
parent("Bob","Liz").
parent("Bob","Paul").
parent("Bob","Sam").
parent("Paul","Pat").

male("Jon").
male("Bob").
male("Paul").
male("Sam").
male("Pat").

famale("Mary").
famale("Ann").
famale("Liz").

father(X,Z):-parent(X,Z),male(X),X\==Z.

mather(X,Z):-parent(X,Z),famale(X),X\==Z.
mather(X):-parent(X,Y),famale(Y),X\==Y.

brather(X,Y):-parent(Z,X),parent(Z,Y),male(X),X\==Y,X\==Y.

sister(X,Y):-parent(Z,X),parent(Z,Y),famale(X),X\=Y.
sister(Y):-parent(Z,X),parent(Z,Y),famale(X),X\==Y.

grandsun(X,A):-parent(X,Z),parent(Z,A),X\==A,X\==Z,A\==Z.

ancle(X,Y):-parent(Z,X),parent(Z,B),parent(B,Y).
ancle(X):-parent(Z,X),parent(Z,B),parent(B,Y),X\=Y.

children2(X):- parent(X,A),not(parent(X,B)),A\=B.
next(X):-parent(X,Y),male(X),male(Y),X\==Y.
















