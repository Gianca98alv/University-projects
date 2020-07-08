"""
	Tarea Programada Karatsuba
	
	Test

	Andrés Álvarez Durán
	Giancarlo Alvarado Sánchez
	Hilary Granados Álvarez

	Grupo: 03
	Hora: 08:00am

"""
from Karatsuba import *
if __name__ == "__main__":

	print(f"***Test***")

	x_val = 123
	y_val = 456

	x = Num(x_val)
	y = Num(y_val)

	print(f"x = {x}")
	print(f"y = {y}")
	print(f"x = {x} + y = {y} = {x + y} (In Python == {x_val + int(y_val)})))")
	print(f"x = {x} * y = {y} = {x * y} (In Python == {x_val * int(y_val)})))")

	print(f"***Test Kara***")
	x_val = 12345
	y_val = 6789
	z_val = 123
	q_val = 3
	kx = Knum(x_val)
	ky = Knum(y_val)
	kz = Knum(z_val)
	kq = Knum(q_val)

	print(f"kz = {kz} + kq = {kq} = {kz + kq} (In Python == {int(z_val) + int(q_val)}))")
	
	print(f"kx = {kx} * ky = {ky} = {kx * ky} (In Python == {x_val * y_val})")

	print(f"***Test Kara Complement***")
	x = Knum(5)
	nx = ~x
	print(f"x = {x} + nx = {nx} = {x + nx}")
	print(f"x = {x} * nx = {nx} = {x * nx}")
