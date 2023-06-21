# ifndef SHAPE_HPP
# define SHAPE_HPP
#include "color.hpp"
class Shape {
	public:
		Shape();
		Shape(Color color, std::string const& name);
		virtual float area() const = 0;
		virtual float volume() const = 0;
	private:
		std::string name_;
		Color color_;
};

#endif