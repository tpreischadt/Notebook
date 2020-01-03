struct Point {
	double x, y;

	// Vector sum.
	Point operator + (const Point &b) const {
		return {this->x + b.x, this->y + b.y};
	}

	// Vector subtraction.
	Point operator - (const Point &b) const {
		return {this->x - b.x, this->y - b.y};
	}
};

/* O(1) - Rotates vector v by theta radians. */
Point rotate(const Point &v, double theta) {
	return {v.x * cos(theta) - v.y * sin(theta), v.x * sin(theta) + v.y * cos(theta)};
}

/* O(1) - Rotates points p around pivot by theta radians. */
Point rotate(const Point &pivot, const Point &p, double theta) {
	return pivot + rotate(p - pivot, theta);
}