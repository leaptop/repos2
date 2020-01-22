;01_3a build a list using "cons": (1 (2 3))
;(cons '1 '((2 3)));need to build ((2 3)) using  the other way
;(cons 1 (cons(cons (2 cons(3)))))

;(cons 1 (cons(cons 2 '(3))nil))

(cons 1 (cons(cons 2 (cons 3 nil))nil))

