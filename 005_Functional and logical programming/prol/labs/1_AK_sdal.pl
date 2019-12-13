%predicates:
parent("John","Bob").   %��������: ���������, ��� ����� ����, �� �� ����. �.�. ����� ����, � ���� ����� 2-� �����.
parent("Mary","Bob").
parent("Mary","Ann").
parent("Bob","Liz").
parent("Bob","Paul").
parent("Bob","Sam").
parent("Paul","Pat").
%facts:
male("John").
male("Bob").
male("Paul").
male("Sam").

female("Mary").
female("Ann").
female("Liz").
female("Pat").
%rules:
xIsAFatherToZ(X,Z):-parent(X,Z),male(X),X\==Z.                      %xIsAFatherToZ(A,"Sam").
mother(X,Z):-parent(X,Z),female(X),X\==Z.                           %mother(_,"Bob").
mother2(X):-parent(X,Y),female(Y),X\==Y.                            %mother2("Bob").
brother(X,Y):-parent(Z,X),parent(Z,Y),male(X),X\==Y.
brother2(X,Y):-parent(Z,X),parent(Z,Y),male(X),X\==Y,X\==Y.
sister(X,Y):-parent(Z,X),parent(Z,Y),female(X),X\==Y.               %sister(F,"Sam").%sister(_,"Liz").
sister2(Y):-parent(Z,X),parent(Z,Y),female(X),X\==Y.                %sister2("Liz").
                                                                    %brother(A,"Bob").
xHasAGrandsonA(X,A):-parent(X,Z),parent(Z,A),male(A),X\==A,X\==Z,A\==Z.   %xHasAGrandsonA("Mary",F).

xHasJustOneSibling(X,C,P):-parent(P,C), parent(P, C1), not(parent(P, S)), C\==C1.
xHasThreeChildren(X,C1,C2,C3):-parent(X,C1), parent(X,C2), parent(X,C3).
xHasTwoChildren(X,C1,C2):-parent(X,C1), parent(X,C2),not(parent(X,S)).

%if X has a child Z, and Z has a child A, and A is male, and the variables aren't equal, then true
xHasGrandchildren(X,A):-parent(X,Z),parent(Z,A),X\==A,X\==Z,A\==Z.
xHasGrandchildren(X):-parent(X,Z),parent(Z,A),X\==A,X\==Z,A\==Z.

aunt(X,Y):-parent(B,Y),sister(X,B).%X is aunt for Y if Y has a parent B, and X is a sister of B    %aunt("Ann",F).      %aunt("Ann","Paul").
%aunt(X):-parent(Z,X),parent(Z,B),parent(B,Y),X\==Y.

%xHasCousins(X,Y):-parent(B,X),xHasGrandchildren(B,Y).%a bad function, because it can count X's children as it's cousins
%xHasCousins(X):-parent(B,X),xHasGrandchildren(B).

%if X has a parent B, and the parent B is also a parent to A, and A is not the same as X, and A has children
xHasCousinsBetter(X,Y):-parent(B,X),parent(B,A),A\==X,parent(A,Y).%xHasCousinsBetter("Ann",_).%xHasCousinsBetter("Ann",B).

%xHas2Children(X):-parent(X,A),parent(X,B),A\==B.
 xHasExactly2Children(X):- setof(Y, parent(X,Y),L), length(L,2).
%children2(X):- parent(X,A),not(parent(X,B)),A\=B.
xHasAMaleSuccessorY(X,Y):-parent(X,Y),male(X),male(Y),X\==Y.

whoHas2Children(Y):-parent(Y,X),xHas2Children(Y).
                          %��� ����� ����� �� ������ �������������. ���� ����


