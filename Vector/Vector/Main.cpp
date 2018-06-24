#include "Vector.hpp"
#include <string>
#include <iostream>

using namespace jrw;

void compare(bool condition) {
	if (condition) {
		std::cout << "[o] compare success" << std::endl;
	}
	else {
		std::cout << "[x] compare failed" << std::endl;
	}
}

void Vector2Op() {
	Vector<int> v1(1, 2);
	Vector<int> v2(4, 6);

	std::cout << "v1 = ";
	v1.print();
	std::cout << "v2 = ";
	v2.print();
	std::cout << std::endl;

	std::cout << "v1 + v2 = ";
	(v1 + v2).print();
	//compare((v1 + v2) == Vector(5, 8));
	std::cout << "v1 - v2 = ";
	(v2 - v1).print();
	//compare((v2 - v1) == Vector(3, 4));
	std::cout << "v1 * v2 = ";
	(v1 * v2).print();
	//compare((v1 * 2) == Vector(2, 4));
	std::cout << "v2 * v2 = ";
	(v2 * v2).print();
	//compare((v2 * 2) == Vector(8, 12));
	std::cout << "v2 / 2 = ";
	(v2 / 2).print();
	//compare((v2 / 2) == Vector(2, 3));
	std::cout << std::endl;

	std::cout << "v1 dot v2 = ";
	std::cout << v1.dot(v2) << std::endl;
	std::cout << "v1 cross v2 = ";
	std::cout << v1.cross(v2) << std::endl;
	std::cout << std::endl;

	Vector<int> v3(3, 4);
	std::cout << "v3 = ";
	v3.print();
	std::cout << "Magnitude of v3 = ";
	std::cout << v3.magnitude() << std::endl;
	std::cout << "Magnitude squared of v3 = ";
	std::cout << v3.mag2() << std::endl;

	Vector<int> v4 = v3;
	std::cout << "Normalized of v3 = ";
	v4.normalized();
	v4.print();

	std::cout << "Eulerangle of v3 = ";
	std::cout << v3.eulerangle() << std::endl;
}

int main() {
	Vector2Op();

	getchar();
	return 0;
}