;Lab 1

;#1
;(cdr(car(cdr(car(car '(((1 (2 *)) 3) 4) )))))

;#2
;(cons nil nil); Sliynie pustoti

;#3

;A
;(cons 1 (cons(cons 2 '(3))nil))

;B
;(list 1(list 2 3))

;#4
(defun f (a); a - spisok; smena 1 i last
	(
		append (last a) (cdr(butlast a)) (list (car a))
 
	)
)

;(defun g (a) ;smena 2 i 3
;	(
;		append (list (car a)) (list (car (cdr (cdr a)))) (list (car (cdr a))) (cdddr a)
;	)
;)

(f '(1 5 4 7 8))