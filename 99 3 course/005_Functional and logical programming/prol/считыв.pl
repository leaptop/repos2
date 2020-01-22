start1:-
 open('output.txt',write,OS),
 X = 'Hi all',
 write(OS,X),
 close(OS),
 open('output.txt',read,OS2),
 read(OS2,Input).


start1:-
 absolute_file_name('X.data',Abs),
 open(Abs,write,Out),
 tell(Abs),
 write('HiAll'),
 told,
 close(Out),
 open(Abs,read,In),
 see('X.data'),
 read(X),
 seen,
 write(X).