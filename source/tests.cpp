#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"


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
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
