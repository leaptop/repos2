first:-
  %  ListA = [three,22,at,it], nl,
     write("Enter elements."), nl,
     readln(ListA),
    first(ListA,T1),
    write(T1).

first([Hs|Ts],[Hs, Hs|L_Out]):-
    first(Ts,L_Out).
first([],[]).

oal([Head|Tail],[H_Out|Tail2]):- bred(Head,H_Out), oal(Tail, Tail2).
oal([ ], [ ]).

pred:-
    open('input.txt',read,FILE),
    set_input(FILE),
    read_list(FILE, ListS),
    write(ListS),
    close(FILE),
    oal(ListS, L_Out),
    tell('output.txt'),
    write_list(L_Out),
    told.
read_list(_,[ ]):- at_end_of_stream,!.
read_list(F, [S|L_Out]):-
  read_line_to_codes(F,L),
  string_codes(S,L),
  write(S),
  read_list(F, L_Out).
  
write_list([S|List]):-
    writeln(S),
    write_list(List).

write_list([ ]) :- !.

bred(Str1, Str2):-
    string_length(Str1, 40),
    Str2 = Str1;
    Space = ' ',
    string_length(Str1,N),
    MaxVal is 40,
    MinVal is MaxVal - N,
    string_chars(Str1,List),
%    write(List).
    pred_3(List,L,Space,MinVal),
%    atomic_list_concat(L,'',Str),
    string_chars(Str,L),
    writeln(Str),
    bred(Str, Str2).


pred_3([Head|Tail], [Head|Tail2], Space, MinVal) :-
    MinVal \== 0,
    Space \== Head,
    pred_3(Tail, Tail2, Space,MinVal).

pred_3([Head|Tail], [Head, Space|Tail2], Space, MinVal) :-
    MinVal \==0,
    !,
    N_min is MinVal - 1,
    pred_3(Tail, Tail2, Space,N_min).

pred_3([Head|Tail],[Head|Tail2],_,MinVal):-
    MinVal == 0,
    !,
    pred_3(Tail,Tail2,_,MinVal).

pred_3([],[],_,_).