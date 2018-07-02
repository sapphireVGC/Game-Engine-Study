#pragma once
#include <iostream>

namespace jrw {
	template <class T>
	class Vector4i {
	public:
		Vector4i();
		Vector4i(T x, T y, T z, T a);
		~Vector4i();

		T x, y, z, a;

		void print() const;
		Vector4i<T>& add(const Vector4i<T>& other);
		Vector4i<T>& minus(const Vector4i<T>& other);
		Vector4i<T>& times(const T& scale);
		Vector4i<T>& divide(const T& scale);

		template <class T>
		friend Vector4i<T> operator+(Vector4i<t> left, Vector4i<T> right);
		template <class T>
		friend Vector4i<T> operator-(Vector4i<t> left, Vector4i<T> right);
		template <class T>
		friend Vector4i<T> operator*(Vector4i<t> origin, T scale);
		template <class T>
		friend Vector4i<T> operator/(Vector4i<t> origin, T scale);

		bool operator==(const Vector4i<T>& other) const;

		T dot(const Vector4i<T>& other);
		T cross(const Vector4i<T>& other);
		T magnitude();
		T mag2();
		Vector4i<T>& normalized();
		T eulerangle();
		T eulerangletoVector(Vector4i<T> other);
	};

	template <class T>
	Vector4i<T>::Vector4i() {

	}

	template <class T>
	Vector4i<T>::Vector4i(T input_x, T input_y, T input_z, T input_a)
		: x(input_x), y(input_y), z(input_z), a(input_a) {

	}

	template <class T>
	Vector4i<T>::~Vector4i() {

	}

	template <class T>
	void Vector4i<T>::print() const {
		std::cout << "(" << x << ", " << y << ", " << z << ", " << a << ")" << std::endl;
	}

	template <class T>
	Vector4i<T>& Vector4i<T>::add(const Vector4i<T>& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		a += other.a;

		return *this;
	}

	template <class T>
	Vector4i<T>& Vector4i<T>::minus(const Vector4i<T>& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		a -= other.a;

		return *this;
	}

	template <class T>
	Vector4i<T>& Vector4i<T>::times(const T& scale) {
		x *= scale;
		y *= scale;
		z *= scale;
		a *= scale;

		return *this;
	}

	template <class T>
	Vector4i<T>& Vector4i<T>::divide(const T& scale) {
		x /= scale;
		y /= scale;
		z /= scale;
		a /= scale;

		return *this;
	}

	template <class T>
	Vector4i<T> operator+(Vector4i<T> left, Vector4i<T> right) {
		return left.add(right);
	}

	template <class T>
	Vector4i<T> operator-(Vector4i<T> left, Vector4i<T> right) {
		return left.minus(right);
	}

	template <class T>
	Vector4i<T> operator*(Vector4i<T> origin, T scale) {
		return origin.times(scale);
	}

	template <class T>
	Vector4i<T> operator/(Vector4i<T> origin, T scale) {
		return origin.divide(scale);
	}

	template <class T>
	bool Vector4i<T>::operator==(const Vector4i<T>& other) const {
		return (this->x == other.x && 
			this->y == other.y && 
			this->z == other.z && 
			this->a == other.a);
	}

	template <class T>
	T Vector4i<T>::dot(const Vector4i<T>& other) {
		return (this->x * other.x + 
			this->y * other.y + 
			this->z * other.z +
			this->a * other.a);
	}

	template <class T>
	T Vector3i<T>::cross(const Vector3i<T>& other) {
		/*x = (this->y * other.z) - (this->z * other.y);
		y = (this->x * other.z) - (this->z * other.x);
		z = (this->x * other.y) - (this->y * other.x);

		return *this;*/
	}

	template <class T>
	T Vector4i<T>::magnitude() {
		return std::sqrt(this->mag2());
	}

	template <class T>
	T Vector4i<T>::mag2() {
		return (this->x * this->x) + 
			(this->y * this->y) + 
			(this->z * this->z) +
			(this->a * this->a);
	}

	template <class T>
	Vector4i<T>& Vector4i<T>::normalized() {
		T magn = this->magnitude();
		x /= magn;
		y /= magn;
		z /= magn;
		a /= magn;

		return *this;
	}

	template <class T>
	T Vector4i<T>::eulerangle() {
		return std::atan(this->y / this->x);
	}

	template <class T>
	T Vector4i<T>::eulerangleToVector(Vector4i<T> other) {
		T dot_value = this->dot(other);
		T thismag = this->magnitude();
		T thatmag = other.magnitude();
		T cos_value = std::cos(1);
		return cos_value;
	}
}

