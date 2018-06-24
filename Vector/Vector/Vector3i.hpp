#pragma once
#include <iostream>

namespace jrw {
	template <class T>
	class Vector3i {
	public:
		Vector3i();
		Vector3i(T x, T y, T z);
		~Vector3i();

		T x, y, z;

		void print() const;
		void printCross() const;
		Vector3i<T>& add(const Vector3i<T>& other);
		Vector3i<T>& minus(const Vector3i<T>& other);
		Vector3i<T>& times(const T& scale);
		Vector3i<T>& divide(const T& scale);
		Vector3i<T>& vtimes(const Vector3i<T>& other);
		Vector3i<T>& vdivide(const Vector3i<T>& other);

		//overload operator +, -, *
		template <class T>
		friend Vector3i<T> operator+(Vector3i<T> left, Vector3i<T> right);
		template <class T>
		friend Vector3i<T> operator-(Vector3i<T> left, Vector3i<T> right);
		template <class T>
		friend Vector3i<T> operator*(Vector3i<T> origin, T scale);
		template <class T>
		friend Vector3i<T> operator*(Vector3i<T> left, Vector3i<T> right);
		template <class T>
		friend Vector3i<T> operator/(Vector3i<T> origin, T scale);
		template <class T>
		friend Vector3i<T> operator/(Vector3i<T> left, Vector3i<T> right);

		//overload operator ==
		bool operator==(const Vector3i<T>& other) const;

		//class work
		T dot(const Vector3i<T>& other); //dot product
		T cross(const Vector3i<T>& other); //cross product
		T magnitude();
		T mag2();
		Vector3i<T>& normalized();
		T eulerangle();
		T eulerangleToVector(Vector3i<T> other);

		//overload operator <<, <=, >=, ==< !=, <, >, +, -, *, /, /=. *=, +=, -=
	};

	template <class T>
	Vector3i<T>::Vector3i() {

	}

	template <class T>
	Vector3i<T>::Vector3i(T input_x, T input_y, T input_z)
		: x(input_x), y(input_y), z(input_z) {

	}

	template <class T>
	Vector3i<T>::~Vector3i() {

	}

	template <class T>
	void Vector3i<T>::print() const {
		std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
	}

	template <class T>
	void Vector3i<T>::printCross() const {
		std::cout << x << "i + " << y << "j + " << z << "k" << std::endl;
	}

	template <class T>
	Vector3i<T>& Vector3i<T>::add(const Vector3i<T>& other) {
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	template <class T>
	Vector3i<T>& Vector3i<T>::minus(const Vector3i<T>& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	template <class T>
	Vector3i<T>& Vector3i<T>::times(const T& scale) {
		x *= scale;
		y *= scale;
		z -= scale;

		return *this;
	}

	template <class T>
	Vector3i<T>& Vector3i<T>::divide(const T& scale) {
		x /= scale;
		y /= scale;
		z /= scale;

		return *this;
	}

	template <class T>
	Vector3i<T>& Vector3i<T>::vtimes(const Vector3i<T>& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}

	template <class T>
	Vector3i<T>& Vector3i<T>::vdivide(const Vector3i<T>& other) {
		x /= other.x;
		y /= other.y;
		z /= other.z;

		return *this;
	}

	template <class T>
	Vector3i<T> operator+(Vector3i<T> left, Vector3i<T> right) {
		return left.add(right);
	}

	template <class T>
	Vector3i<T> operator-(Vector3i<T> left, Vector3i<T> right) {
		return left.minus(right);
	}

	template <class T>
	Vector3i<T> operator*(Vector3i<T> origin, T scale) {
		return origin.times(scale);
	}

	template <class T>
	Vector3i<T> operator*(Vector3i<T> left, Vector3i<T> right) {
		return left.vtimes(right);
	}

	template <class T>
	Vector3i<T> operator/(Vector3i<T> origin, T scale) {
		return origin.divide(scale);
	}

	template <class T>
	Vector3i<T> operator/(Vector3i<T> left, Vector3i<T> right) {
		return left.vdivide(right);
	}

	template <class T>
	bool Vector3i<T>::operator==(const Vector3i<T>& other) const {
		return ((this->x == other.x) && (this->y == other.y) && this->z == other.z);
	}

	template <class T>
	T Vector3i<T>::dot(const Vector3i<T>& other) {
		return ((this->x * other.x) + (this->y * other.y) + (this->z * other.z));
	}

	template <class T>
	T Vector3i<T>::cross(const Vector3i<T>& other) {
		x = (this->y * other.z) - (this->z * other.y);
		y = (this->x * other.z) - (this->z * other.x);
		z = (this->x * other.y) - (this->y * other.x);

		return *this;
	}

	template <class T>
	T Vector3i<T>::magnitude() {
		return std::sqrt(this->mag2());
	}

	template <class T>
	T Vector3i<T>::mag2() {
		return (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
	}

	template <class T>
	Vector3i<T>& Vector3i<T>::normalized() {
		T magn = this->magnitude();
		x /= magn;
		y /= magn;
		z /= magn;

		return *this;
	}

	template <class T>
	T Vector3i<T>::eulerangle() {
		return std::atan(this->y / this->x);
	}

	template <class T>
	T Vector3i<T>::eulerangleToVector(Vector3i<T> other) {
		T dot_value = this->dot(other);
		T thismag = this->magnitude();
		T thatmag = other.magnitude();
		T cos_value = std::cos(1);
		return cos_value;
	}
}

