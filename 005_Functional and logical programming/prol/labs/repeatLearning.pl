% �����:
% ����: 25.11.2019

sq:-repeat,read(X),( X=stop,!;
          Y is X*X, write(Y), fail).

dountilstop :-
  repeat,
  read(X),
  (X = stop, !
   ;
   process(X),
   fail
  ).
  