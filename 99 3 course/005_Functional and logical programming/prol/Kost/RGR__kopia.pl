first:-
    readln(ListA),nl,
    first(ListA,T1),
    write(T1).

first([Hs|Ts],[Hs, Hs|L_Out]):-
    first(Ts,L_Out).
first([],[]).

oral([Head|Tail],[H_Out|Tail2]):- bred(Head,H_Out), oral(Tail, Tail2).
oral([ ], [ ]).

pred:-
    ListA = "A_muxi_toje_vertolet=>",
    ListB = "Po_stolu_polzet_pelmen=>",
    %open('Starter.txt',read,FILE),
    %set_input(FILE),
    %read_list(FILE, ListS),
%    write(ListA),
    bred(ListA,List),
    writeln(List),
    bred(ListB,List1),
    writeln(List1),
    writeln("Operation end").
    %close(FILE),
    %oral(ListS, L_Out),
   % tell('Finisher.txt'),
    %write_list(L_Out).
    %told.
read_list(_,[ ]):- at_end_of_stream,!.
read_list(F, [S|L_Out]):-
  read_line_to_codes(F,L),
  string_to_list(S,L),
  write(S),
  read_list(F, L_Out).



write_list([S|List]):-
    writeln(S),
    write_list(List).

write_list([ ]) :- !.

bred(Str1, Str2):-
    string_length(Str1, 40),
    Str2 = Str1;
    Space = '_',
    string_length(Str1,N),
    MaxVal is 40,
    MinVal is MaxVal - N,
    string_chars(Str1,List),
%    write(List).
    pred_3(List,L,Space,MinVal),
%    atomic_list_concat(L,'',Str),
    string_chars(Str,L),
%    writeln(Str),
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


