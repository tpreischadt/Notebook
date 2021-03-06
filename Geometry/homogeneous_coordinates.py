class Point3D:
	# O(1) - Constructor.
	def __init__(self, x, y, z):
		self.x, self.y, self.z = x, y, z

	# O(1) - Vector sum.
	def __add__(self, p):
		return Point3D(self.x + p.x, self.y + p.y, self.z + p.z)

	# O(1) - Negative vector.
	def __neg__(self):
		return Point3D(-self.x, -self.y, -self.z)

	# O(1) - Vector subtraction.
	def __sub__(self, p):
		return Point3D(self.x - p.x, self.y - p.y, self.z - p.z)

	# O(1) - Dot product.
	def __mul__(self, p):
		return self.x * p.x + self.y * p.y + self.z * p.z

	# O(1) - Cross product.
	def __xor__(self, p):
		return Point3D(self.y * p.z - self.z * p.y, self.z * p.x - self.x * p.z, self.x * p.y - self.y * p.x)

	# O(1) - Lesser than.
	def __lt__(self, p):
		if self.x == p.x:
			if self.y == p.y:
				return self.z < p.z

			return self.y < p.y

		return self.x < p.x

	# O(1) - Greater than.
	def __gt__(self, p):
		return p < self

	# O(1) - Equal.
	def __eq__(self, p):
		return self.x == p.x and self.y == p.y and self.z == p.z

	# O(1) - Different.
	def __ne__(self, p):
		return not self == p

	# O(1) - String conversion.
	def __str__(self):
		return "(%s, %s, %s)" % (str(self.x), str(self.y), str(self.z))

	# O(1) - String conversion for printing arrays.
	def __repr__(self):
		return str(self)

class Point2D:
	# O(1) - Constructor.
	def __init__(self, x, y):
		self.x, self.y = x, y

	# O(1) - Vector sum.
	def __add__(self, p):
		return Point2D(self.x + p.x, self.y + p.y)

	# O(1) - Negative vector.
	def __neg__(self):
		return Point2D(-self.x, -self.y)

	# O(1) - Vector subtraction.
	def __sub__(self, p):
		return Point2D(self.x - p.x, self.y - p.y)

	# O(1) - Dot product.
	def __mul__(self, p):
		return self.x * p.x + self.y * p.y

	# O(1) - Cross product.
	def __xor__(self, p):
		return self.x * p.y - self.y * p.x

	# O(1) - Lesser than.
	def __lt__(self, p):
		if self.x == p.x:
			return self.y < p.y

		return self.x < p.x

	# O(1) - Greater than.
	def __gt__(self, p):
		return p < self

	# O(1) - Equal.
	def __eq__(self, p):
		return self.x == p.x and self.y == p.y

	# O(1) - Different.
	def __ne__(self, p):
		return not self == p

	# O(1) - String conversion.
	def __str__(self):
		return "(%s, %s)" % (str(self.x), str(self.y))

	# O(1) - String conversion for printing arrays.
	def __repr__(self):
		return str(self)

# O(1) - Converts between 2D points and 3D points.
def convert(p):
	if isinstance(p, Point2D):
		return Point3D(p.x, p.y, 1)

	return Point2D(p.x / p.z, p.y / p.z)
