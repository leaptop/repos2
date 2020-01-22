(defun f (x L); my numbers are 1, 11, 21
	(
		cond
			((NULL L)());if the list isn't existing, do nothing
			((numberp (car L))(;if the first element of L is a number, then new if: 
								cond
									((< (car L) 0) (cons (car L)(F x (cdr L))));if the number is less than zero, then CONStruct a new list, using the number
;and the function of the rest of the list L
									(t(cons (list (car L) x) (F x (cdr L))));if the number is more than zero, then CONStruct a new list, using 
;a new LIST made of the number concatenated with x and and the function of the rest of the list L
							  ))				
				
			(t (cons (car L) (F x (cdr L))));if its not a number, then CONStruct a new list, using the number
;and the function of the rest of the list L
	)
)

(F'* '(-1 5 u 18 a k -8 8))
