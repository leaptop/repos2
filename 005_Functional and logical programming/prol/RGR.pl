first:-                     % � ��� swi prolog
    ListA = [1,2,3,g,j,44], nl,       %nl = null
    first(ListA,T1),                         % � ���� ���� ��������� ���
    write(T1).

first([Hs|Ts],[Hs, Hs|L_Out]):-      %Hs ������ ������, Ts - �� ���������
    first(Ts,L_Out).
first([],[]).    % ��� ������ � ������ ���������� ��� ��������� ���������� ��� �������, ������� ������ �� ������

second:-
    %tell('user'),
    %check_exist(Filename),
    open('Starter.txt',read,S),
    %set_output(S),
    string_length(S,L),
    at_end_of_stream,
    write(L).
   % see('text2.txt').
