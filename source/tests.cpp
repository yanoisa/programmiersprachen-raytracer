#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include <iostream>
#include "color.hpp"
# include <glm/glm.hpp>
# include <glm/gtx/intersect.hpp>
TEST_CASE("intersect_ray_sphere","[intersect]")
{
	// Ray
	glm::vec3 ray_origin{ 0.0f, 0.0f, 0.0f };
	// ray direction has to be normalized !
	// you can use :
	// v = glm :: normalize ( some_vector )
	glm::vec3 ray_direction{ 0.0f, 0.0f, 1.0f };
	// Sphere
	glm::vec3 sphere_center{ 0.0f ,0.0f, 5.0f };
	float sphere_radius{1.0f};
	float distance = 0.0f;
	auto result = glm::intersectRaySphere(
		ray_origin, ray_direction,
		sphere_center,
		sphere_radius * sphere_radius, // squared radius !!!
		distance);
	REQUIRE(distance == Approx(4.0f));
}
TEST_CASE("sphere", "[sphere]") {
	Sphere sphere(glm::vec3(0.0f, 0.0f, 0.0f), 0.0f);
	Sphere sphere1 = Sphere();
	Sphere sphere2(glm::vec3(5.0f, 3.0f, 20.0f), 3.0f);
	Sphere sphere3(glm::vec3(1.0f, 1.0f, 23.0f), 1.8f);
	REQUIRE(0 == sphere.area());
	REQUIRE(0 == sphere.volume());
	REQUIRE(0 == sphere1.area());
	REQUIRE(0 == sphere1.volume());
	REQUIRE(sphere2.area() == Approx(113.097));
	REQUIRE(sphere2.volume() ==Approx(113.097));
	REQUIRE(sphere3.area() == Approx(40.715));
	REQUIRE(sphere3.volume() == Approx(24.429));
}

TEST_CASE("box", "[box]") {
	Box box = Box();
	Box box1(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	Box box2(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 4.0f, 2.0f));
	Box box3(glm::vec3(5.0f, 1.0f, 10.0f), glm::vec3(2.0f, 3.0f, 2.0f));
	REQUIRE(box.area() == 0);
	REQUIRE(box.volume() == 0);
	REQUIRE(box1.area() == 0);
	REQUIRE(box1.volume() == 0);
	REQUIRE(box2.area() == 28.0f);
	REQUIRE(box2.volume() == 8.0f);
	REQUIRE(box3.area() == 92.0f);
	REQUIRE(box3.volume() == 48.0f);
}

TEST_CASE("print","[print]") {
	Color myColor;
	myColor.r = 1.0f;
	myColor.g = 0.5f;
	myColor.b = 0.0f;
	Sphere sphere1 = Sphere();
	Sphere sphere2 = Sphere(glm::vec3(5.0f, 3.0f, 20.0f), 3.0f);
	Sphere sphere3 = Sphere(glm::vec3(2.0f, 1.0f, 40.0f), 5.3f, myColor, std::string("Hallo"));
	Sphere sphere4 = Sphere(glm::vec3(5.0f, 0.0f, 8.0f), 1.2f, Color{0.0f,0.35f,0.2f}, std::string("Tschss"));
	Box box1 = Box();
	Box box2 = Box(glm::vec3(2.0f, 1.0f, 4.0f), glm::vec3(1.0f, 3.0f, 16.7f) );
	Box box3 = Box(glm::vec3(0.0f, 0.1f, 1.0f), glm::vec3(1.1f, 3.3f, 16.16f), Color{ 0.6f,0.8f,0.0f }, std::string("12344121"));
	Box box4 = Box(glm::vec3(3.0f,3.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), Color{ 0.0f,0.0f,0.0f }, std::string(""));
	std::cout << sphere1;	
	std::cout << "\n";
	std::cout << sphere1;
	std::cout << "\n";
	std::cout << sphere3;
	std::cout << "\n";
	std::cout << sphere4;
	std::cout << "\n";
	std::cout << box1;
	std::cout << "\n";
	std::cout << box1;
	std::cout << "\n";
	std::cout << box3;
	std::cout << "\n";
	std::cout << box4;

	
}
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
