(defun f (A B); 11
	(
		cond
			((NULL A) (cdr B));if the first argument is NULL, then use(create an array and print it with the cdr command) the rest of B
			((NULL B) (cdr A))
			(t (cons (car A) (cons (car B) (F (cdr A) (cdr B)))));otherwise concatenate the first element of A and concatenation of the first element
	);of B and  F of the rest of A & B lists
)

(F '(1 2 3 4 5 6 7 8) '(a b c d f))
