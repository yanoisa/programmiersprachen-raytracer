#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"


TEST_CASE("sphereconstruct", "[sphereconstruct]") {
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
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
