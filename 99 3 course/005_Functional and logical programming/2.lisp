;#1
#|
(defun f (x l)
	(
		cond
			((NULL L)())
			((numberp (car L))( 
								cond
									((< (car L) 0) (cons (car L)(F x (cdr L))))
									(t(cons (list (car L) x) (F x (cdr L))))
							  ))				
				
			(t (cons (car L) (F x (cdr L))))
	)
)

(F'* '(-1 d 6 -3 a 0))
|#
;#2
#|
(defun f (A B)
	(
		cond
			((NULL A) (cdr B))
			((NULL B) (cdr A))
			(t (cons (car A) (cons (car B) (F (cdr A) (cdr B)))))
	)
)

(F '(1 2 3 4 5 6 7 8) '(a b c d f))
|#
;#3
(defun f(A)
	(
		cond
			((NULL A)())
			((NULL (cdr A))(list(car A)))
			(t(cons (+ (car A)(car (last A))) (F (cdr (butlast A)))))
	)
)

(F '(1 2 3 4 5 6 7))