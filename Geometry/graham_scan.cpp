struct Point{
	long long x, y;

	Point(){}

	Point(long long x, long long y){
		this->x = x;
		this->y = y;
	}

	// Vector subtraction.
	Point operator - (const Point &b) const{
		return Point(this->x - b.x, this->y - b.y);
	}

	// Cross product.
	long long operator ^ (const Point &b) const{
		return this->x * b.y - this->y * b.x;
	}

	bool operator < (const Point &b) const{
		if (this->x == b.x){
			return this->y < b.y;
		}

		return this->x < b.x;
	}
};

Point pivot;

/* O(1) - Compares points A and B using their angle relative to the Pivot. */
bool comp(const Point &a, const Point &b){
	// Same angle. Closest point first.
	if (((a - pivot) ^ (b - pivot)) == 0){
		return a < b;
	}

	// True if PA -> PB is a left turn.
	return ((a - pivot) ^ (b - pivot)) > 0;
}

/* O(N * Log(N)) - Sorts the points in a convex polygon in counter-clockwise order. */
void sort_convex_polygon(vector<Point> &p){
	int i;

	// Retrieving a pivot point.
	pivot = *min_element(p.begin(), p.end());

	// Sorting according to angles relative to the pivot.
	sort(p.begin(), p.end(), comp);

	for (i = (int)p.size() - 2; i >= 1; i--){
		if (((p.back() - pivot) ^ (p[i] - pivot)) != 0){
			break;
		}
	}

	// Reversing last collinear part.
	reverse(p.begin() + i + 1, p.end());
}

/* O(N * Log(N)) - Returns the Convex Hull of a set of points. Expects at least 3 points and expects that not all of them are collinear. */
stack<Point> graham_scan(vector<Point> p){
	stack<Point> ch;
	Point a, b, c;

	// Sorting the points and pushing and extra Pivot to the back as a sentinel.
	sort_convex_polygon(p);
	p.push_back(pivot);

	// Pushing first two points.
	ch.push(p[0]); // Pivot.
	ch.push(p[1]);

	// Appending points to the Convex Hull one by one.
	for (int i = 2; i < p.size(); i++){
		c = p[i];

		// There are always at least 2 points in the stack at this point.
		do{
			// Retrieving the top 2 from stack (A and B).
			b = ch.top();
			ch.pop();
			a = ch.top();
			ch.pop();

			// If it is a left turn, the three points belong to the current Convex Hull.
			if (((b - a) ^ (c - a)) > 0){
				// Pushing back A and B.
				ch.push(a);
				ch.push(b);
				break;
			}

			// Not a left turn. Removing B by only pushing back A.
			ch.push(a);
		}while (ch.size() >= 2);

		// Appending C.
		ch.push(c);
	}

	// Removing the Pivot initially pushed as a sentinel.
	ch.pop();

	return ch;
}