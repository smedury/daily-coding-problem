def cons(a, b):
	return lambda f: f(a, b)

def car(f):
	return f(lambda a, b: a)

def cdr(f):
	return f(lambda a, b: b)
