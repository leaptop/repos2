(defun f(A); 21
	(
		cond
			((NULL A)());if the list is empty do nothing
			((NULL (cdr A))(list(car A))); if the rest of the list is empty return the first element
			(t(cons (+ (car A)(car (last A))) (F (cdr (butlast A)))));otherwise CONStruct a new list of a summation of the first and the last elements
	);and the F of the cutted from both sides list
)

(F '(1 2 3 4  5 6 7 ))