;need to swap first and last elements of a list
;using list, last, append, car, cdr, cons, butlast with one argument
;(list 'a 'b 'c 'd)


(defun f (a); a - spisok; smena first and last
	(
		append (last a) (cdr(butlast a)) (list (car a));butlast cuts the last element
 
	)
)
(f '(1 2 3 4 5))