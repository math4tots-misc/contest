# 2008 Qaulifier Problem C

# Area of triangle determined by points a, b, and c
def triangle_area a, b, c
	x1, y1 = a
	x2, y2 = b
	x3, y3 = c
	(x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1).abs / 2
end

# Area of circular segment determined by the radius and the
# endpoints of the circular segment.
def chord_area r, a, b
	a, b = [a,b].sort
	(Math.acos(a[0]/r)-Math.acos(b[0]/r))*r**2/2 - triangle_area([0,0],a,b)
end

# gets area of intersection between a circle at the origin
# and a square.
def circle_square_area r, x, y, s
	if x ** 2 + y ** 2 >= r ** 2
		# Entire square lies outside of the circle
		0
		
	elsif (x+s) ** 2 + (y+s) ** 2 <= r ** 2
		# Entire square lies inside the circle
		s * s
		
	elsif (x+s) ** 2 + y ** 2 >= r ** 2 and x ** 2 + (y+s) ** 2 >= r ** 2
		# Exactly 1 corner of the square, (x,y), is in the circle.
		a = [x,Math.sqrt(r*r-x*x)]
		b = [Math.sqrt(r*r-y*y),y]
		triangle_area([x,y],a,b) + chord_area(r,a,b)
		
	elsif (x+s) ** 2 + y ** 2 <= r ** 2 and x ** 2 + (y+s) ** 2 >= r ** 2
		# (x,y) and (x+s,y) are inside the circle
		a = [x  ,Math.sqrt(r**2 - x**2)]
		b = [x+s,Math.sqrt(r**2 - (x+s)**2)]
		# Trapezoidal area plus cirular segment
		s*((a[1]-y)+(b[1]-y))/2 + chord_area(r,a,b)
		
	elsif (x+s) ** 2 + y ** 2 >= r ** 2 and x ** 2 + (y+s) ** 2 <= r ** 2
		# (x,y) and (x,y+s) are inside the circle
		a = [Math.sqrt(r**2 - y**2), y]
		b = [Math.sqrt(r**2 - (y+s)**2), y+s]
		s*((a[0]-x)+(b[0]-x))/2 + chord_area(r,a,b)
		
	elsif (x+s) ** 2 + y ** 2 <= r ** 2 and x ** 2 + (y+s) ** 2 <= r ** 2
		# 3 points are inside the square
		a = [Math.sqrt(r**2 - (y+s)**2), y+s]
		b = [x+s, Math.sqrt(r**2 - (x+s)**2)]
		s*s - triangle_area([x+s,y+s],a,b) + chord_area(r,a,b)
	end
end

(1..gets.to_i).each do |n|
	f, ro, t, r, g = gets.split.map(&:to_f)
	
	# p is probability of hitting the fly
	# (the final result that we want)
	p = if g <= 2 * f
		1.0
	else
		g -= 2 * f            # adjusted gap square side length
		r += f                # adjusted string radius
		ri = ro - t - f       # inner radius
		
		s = g + 2 * r         # side length of tesselation square
		c = (ri/s).to_i.next  # upper bound on number of squares from origin to end
		
		gap = 0.0             # total gap area fly can use to escape
		
		c.times do |i|
			x = r + i * s
			c.times do |j|
				y = r + j * s
				gap += circle_square_area(ri,x,y,g)
			end
		end
		
		1.0 - 4*gap/(Math::PI * ro ** 2)
	end
	
	puts "Case ##{n}: #{p}"
end
