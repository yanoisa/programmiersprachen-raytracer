# ifndef SHAPE_HPP
# define SHAPE_HPP
#include "color.hpp"
class Shape {
	public:
		Shape();
		Shape(Color color, std::string const& name);
		/*virtual */ ~Shape();
		virtual float area() const = 0;
		virtual float volume() const = 0;
		virtual std::ostream& print(std::ostream& os) const;
		std::string getName()const;
		Color getColor()const;
	private:
		std::string name_;
		Color color_;
};
std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif