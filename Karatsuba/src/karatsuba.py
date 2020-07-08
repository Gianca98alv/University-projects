"""
	Tarea Programada Karatsuba

	Andrés Álvarez Durán
	Giancarlo Alvarado Sánchez
	Hilary Granados Álvarez

	Grupo: 03
	Hora: 08:00am

"""
from functools import total_ordering

class NumValidor:
	def __init__(self,digit):
		self.digit
	def check_num(self, digit):
		correcto = False
		num = 0
		while(not correcto):
			try:
				num = int(self.digit)
				correcto = True
			except ValueError:
				print('Error, introduce un numero entero')
		return num

@total_ordering
class Num(NumValidor):
	def __init__(self, digit = "", base = 10, size = 16):
		self.digit = [int(i) for i in str(digit)]
		self.base = base
		self.size = size
	def __eq__(self, other):
		return isinstance(other, type(self)) and (self.digit, self.base == other.digit, other.base)
	def __lt__(self, other):
		return isinstance(other, type(self)) and (self.digit, self.base < other.digit, other.base)
	def __len__(self):
		return len(self.digit)
	def __str__(self):
		return(f"""{int("".join(map(str,self.digit)))} [siz={self.size}]""")
	def __repr__(self):
		return self.__str__()
	def __getitem__(self, key):
		pass
	def __add__(self, other):
		suma = []
		temp = 0
		temp2 = 0
		if len(self.digit) < len(other.digit):
			while len(self.digit) < len(other.digit):
				self.digit.insert(0, 0)
		elif len(other.digit) < len(self.digit):
			while len(other.digit) < len(self.digit):
				other.digit.insert(0, 0)
		elif len(self.digit) == len(other.digit):
			self.digit.insert(0, 0)
			other.digit.insert(0, 0)
		xi = self.digit[::-1]
		yi = other.digit[::-1]
		for i in range(0, len(xi)):
			temp = (xi[i] + temp2) + yi[i]
			temp2 = 0
			if temp >= 10:
				temp2 += temp//10
				suma.insert(0, temp%10)
			else:
				suma.insert(0, temp)
		return int("".join(map(str,suma)))
	def __mul__(self, other):
		temp = 0
		mult = []
		suma = 0
		cero = []
		n = 0
		xi = self.digit[::-1]
		yi = other.digit[::-1]
		for i in range(0, len(yi)):
			temp2 = 0
			for j in range(0, len(xi)):
				temp = xi[j] * yi[i]
				temp = temp + temp2
				if temp >= 10:
					temp2 = 0
					temp2 += temp//10
					mult.insert(0, temp%10)
				else:
					temp2 = 0
					mult.insert(0, temp)
			for i in range(n):
				mult.append(0)
			suma += int("".join(map(str,mult)))
			mult = [] 
			n += 1
		return suma
	def __invert__(self):
		new = []
		for i in self.digit:
			new += [abs(self.base -1 -i)]
		return Num(new, self.base, self.size)
	def __sub__(self, other):
		other = Num.check_num(other, Num)
		base = self.base
		if other.base != base:
			other = Num(other.digit, base = base)
		return self + ~other

class Knum(Num):
	def __add__(self, other):
		return super().__add__(other)
	def __sub__(self, other):
		return super().__sub__(other)
	def __add__(self, other):
		return super().__add__(other)
	def __lshift__(self, positions):
		return isinstance(other, type(self)) and self.base << other.base
	def __mul__(self, other):
		def ceros(numero, ceros, izq = True):
			for i in range(ceros):
				if izq:
					numero = '0' + numero
				else:
					numero = numero + '0'
			return numero

		def karatsuba(x ,y):
			x = str(x)
			y = str(y)
			if len(x) == 1 and len(y) == 1:
				return int(x) * int(y)
			if len(x) < len(y):
				x = ceros(x, len(y) - len(x))
			elif len(y) < len(x):
				y = ceros(y, len(x) - len(y))
			n = len(x)
			j = n//2
			if (n % 2) != 0:
				j += 1    
			Bceros = n - j
			Aceros = Bceros * 2
			a = int(x[:j])
			b = int(x[j:])
			c = int(y[:j])
			d = int(y[j:])
			ac = karatsuba(a, c)
			bd = karatsuba(b, d)
			k = karatsuba(a + b, c + d)
			A = int(ceros(str(ac), Aceros, False))
			B = int(ceros(str(k - ac - bd), Bceros, False))
			return A + B + bd
		x = int("".join(map(str,self.digit)))
		y = int("".join(map(str,other.digit)))
		kara = karatsuba(x, y)
		return kara
	def __invert__(self):
		new = 0
		for i in self.digit:
			new += abs(self.base - 1 - i)
		return Knum(new, self.base, self.size)
		
		