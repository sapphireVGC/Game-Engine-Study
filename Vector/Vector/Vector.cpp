#include "Vector.h"

namespace jrw {
	Vector::Vector()
	{
	}

	Vector::Vector(int input_x, int input_y)
		:x(input_x), y(input_y)
	{

	}

	Vector::Vector(int input_x, int input_y, int input_z)
		: x(input_x), y(input_y), z(input_z)
	{

	}

	Vector::~Vector() {

	}

	void Vector::print() const {
		std::cout << "v: (" << x << ", " << y << ")" << std::endl;
	}

	Vector& Vector::add(const Vector& other) {
		x += other.x;
		y += other.y;

		return *this;
	}

	Vector& Vector::minus(const Vector& other) {
		x -= other.x;
		y -= other.y;

		return *this;
	}

	Vector& Vector::times(const int& scale) {
		x *= scale;
		y *= scale;

		return *this;
	}

	Vector& Vector::divide(const int& scale) {
		x /= scale;
		y /= scale;

		return *this;
	}

	Vector& Vector::vtimes(const Vector& other) {
		x *= other.x;
		y *= other.y;

		return *this;
	}

	Vector& Vector::vdivide(const Vector& other) {
		x /= other.x;
		y /= other.y;

		return *this;
	}

	Vector operator+(Vector left, Vector right) {
		return left.add(right);
	}

	Vector operator-(Vector left, Vector right) {
		return left.minus(right);
	}

	Vector operator*(Vector origin, int scale) {
		return origin.times(scale);
	}

	Vector operator*(Vector left, Vector right) {
		return left.vtimes(right);
	}

	Vector operator/(Vector origin, int scale) {
		return origin.divide(scale);
	}

	Vector operator/(Vector left, Vector right) {
		return left.vdivide(right);
	}

	bool Vector::operator==(const Vector& other) const {
		return ((this->x == other.x) && (this->y == other.y));
	}

	int Vector::dot(const Vector& other) {
		return ((this->x * other.x) + (this->y * other.y));
	}

	int Vector::cross(const Vector& other) {
		return ((this->x * other.y) - (this->y * other.x));
	}

	double Vector::magnitude() {
		return std::sqrt(this->mag2());
	}

	double Vector::mag2() {//fix pow
		return std::pow(this->x, 2) + std::pow(this->y, 2);
	}

	Vector& Vector::normalized() {
		double magn = this->magnitude();
		x /= magn;
		y /= magn;

		return *this;
	}

	double Vector::eulerangle() {
		return std::atan(this->y / this->x);
	}

	double Vector::eulerangleToVector(Vector other) {
		int dot_value = this->dot(other);
		double thismag = this->magnitude();
		double thatmag = other.magnitude();
		double cos_value = std::cos(1);
		return cos_value;
	}
}