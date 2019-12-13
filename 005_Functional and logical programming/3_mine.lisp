;#1
(defun f (A B)
	(
		cond
			((NULL A)())
			((NULL B)())
			(t(
				cond
				((numberp (car A))(
						cond
							((numberp(car B))(;numberp checks if the argument is a number
									cond
										( (= (car A)(car B)) (print "Mnojestva ravni!") (F (cdr A) (cdr B)) )
										(t(print "Mnojestva ne ravni!" (F (cdr A) (cdr B))))
											 )
							)
							(t(print "Numbers aren't equal and Mnojestva ne ravni!"))
							)
				)
				(t (
					cond	
						( (equal (car A)(car B)) (print "Simvoli identichnu") (F (cdr A) (cdr B)))
						(t(print "Simvoli aren't equal and Mnojestva ne ravni!"(F (cdr A) (cdr B))))
					))
			   )
			)
	)
)

(F '(1 2 3 4 5 a) '(1 2 b 4 5 a))

;#2

(defun f(A B)
	(
		cond
			((NULL A)())
			((NULL B)())
			(t(
				cond
				((numberp (car A))(
						cond
							((numberp(car B))(
									cond
										( (= (car A)(car B)) (cons (car A) (F (cdr A) (cdr B))) )
										(t(F (cdr A) (cdr B)))
											 )
							)
							(t(F (cdr A) (cdr B)) )
							)
				)
				(t (
					cond	
						( (equal (car A)(car B)) (cons(car A) (F (cdr A) (cdr B))) );letters and numbers are compared by different commands
					))
			   )
			)
	)
)

(f '(1 2 4 8 * b 5) '(1 2 3 5 * b 5))

;#3
(defun f(func List)
	(
		cond
			((NULL List)())
			( (funcall func ( car List)) (cons '* (cons(car List) (F func (cdr List)))) )
			( t(cons (car List) (f func (cdr List))))
	)
)

(f (lambda(x)(>= x 0)) '(1 2 3 0 -1 -2 9 -3 -8))
(f #'evenp '(1 2 3 0 -1 -2 9 -3 -8))