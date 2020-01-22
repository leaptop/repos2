;( = (car A) (car B)) f( (cdr A) (cdr B))(print "mnojestva ne rav)
(defun f (A B)
	(
		cond
		((NULL A)())
		((NULL B)())
		(t(
			cond
				((numberp((car A))(
					cond
						((numberp(car B))(
							cond
								( (= (car A)(car B)) (F (cdr B)) (print "Mnojestva ravni!"))
								(t(print "Mnojestva ne ravni"))
									)
						))
						(t (
							cond
								(=((equal (car A) (car B))) (F (cdr A) (cdr B)))
							))
				)
			)
		)
	)
)
(=((equal (3) (3))) (F (4) (4)))
(F '(1 2 3 4 5) '(1 2 3 4 5))