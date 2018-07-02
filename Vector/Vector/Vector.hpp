#pragma once
#include <iostream>

namespace jrw {
	template <class T>
	class Vector {
	public:
		Vector();
		Vector(T x, T y);
		~Vector();

		T x, y, z;

		void print() const;
		Vector<T>& add(const Vector<T>& other);
		Vector<T>& minus(const Vector<T>& other);
		Vector<T>& times(const T& scale);
		Vector<T>& divide(const T& scale);
		Vector<T>& vtimes(const Vector<T>& other);
		Vector<T>& vdivide(const Vector<T>& other);

		//overload operator +, -, *
		template <class T>
		friend Vector<T> operator+(Vector<T> left, Vector<T> right);
		template <class T>
		friend Vector<T> operator-(Vector<T> left, Vector<T> right);
		template <class T>
		friend Vector<T> operator*(Vector<T> origin, T scale);
		template <class T>
		friend Vector<T> operator*(Vector<T> left, Vector<T> right);
		template <class T>
		friend Vector<T> operator/(Vector<T> origin, T scale);
		template <class T>
		friend Vector<T> operator/(Vector<T> left, Vector<T> right);

		//overload operator ==
		bool operator==(const Vector<T>& other) const;

		//class work
		T dot(const Vector<T>& other); //dot product
		T cross(const Vector<T>& other); //cross product
		T magnitude();
		T mag2();
		Vector<T>& normalized();
		T eulerangle();
		T eulerangleToVector(Vector<T> other);

		//overload operator <<, <=, >=, ==< !=, <, >, +, -, *, /, /=. *=, +=, -=
	};

	template <class T>
	Vector<T>::Vector() {
	
	}

	template <class T>
	Vector<T>::Vector(T input_x, T input_y)
		:x(input_x), y(input_y) {

	}

	template <class T>
	Vector<T>::~Vector() {

	}

	template <class T>
	void Vector<T>::print() const {
		std::cout << "(" << x << ", " << y << ")" << std::endl;
	}

	template <class T>
	Vector<T>& Vector<T>::add(const Vector<T>& other) {
		x += other.x;
		y += other.y;

		return *this;
	}

	template <class T>
	Vector<T>& Vector<T>::minus(const Vector<T>& other) {
		x -= other.x;
		y -= other.y;

		return *this;
	}

	template <class T>
	Vector<T>& Vector<T>::times(const T& scale) {
		x *= scale;
		y *= scale;

		return *this;
	}

	template <class T>
	Vector<T>& Vector<T>::divide(const T& scale) {
		x /= scale;
		y /= scale;

		return *this;
	}

	template <class T>
	Vector<T>& Vector<T>::vtimes(const Vector<T>& other) {
		x *= other.x;
		y *= other.y;

		return *this;
	}

	template <class T>
	Vector<T>& Vector<T>::vdivide(const Vector<T>& other) {
		x /= other.x;
		y /= other.y;

		return *this;
	}

	template <class T>
	Vector<T> operator+(Vector<T> left, Vector<T> right) {
		return left.add(right);
	}

	template <class T>
	Vector<T> operator-(Vector<T> left, Vector<T> right) {
		return left.minus(right);
	}

	template <class T>
	Vector<T> operator*(Vector<T> origin, T scale) {
		return origin.times(scale);
	}

	template <class T>
	Vector<T> operator*(Vector<T> left, Vector<T> right) {
		return left.vtimes(right);
	}

	template <class T>
	Vector<T> operator/(Vector<T> origin, T scale) {
		return origin.divide(scale);
	}

	template <class T>
	Vector<T> operator/(Vector<T> left, Vector<T> right) {
		return left.vdivide(right);
	}

	template <class T>
	bool Vector<T>::operator==(const Vector<T>& other) const {
		return (this->x == other.x && this->y == other.y);
	}

	template <class T>
	T Vector<T>::dot(const Vector<T>& other) {
		return ((this->x * other.x) + (this->y * other.y));
	}

	template <class T>
	T Vector<T>::cross(const Vector<T>& other) {
		return ((this->x * other.y) - (this->y * other.x));
	}

	template <class T>
	T Vector<T>::magnitude() {
		return std::sqrt(this->mag2());
	}

	template <class T>
	T Vector<T>::mag2() {
		return (this->x * this->x) + (this->y * this->y);
	}

	template <class T>
	Vector<T>& Vector<T>::normalized() {
		T magn = this->magnitude();
		x /= magn;
		y /= magn;

		return *this;
	}

	template <class T>
	T Vector<T>::eulerangle() {
		return std::atan(this->y / this->x);
	}

	template <class T>
	T Vector<T>::eulerangleToVector(Vector<T> other) {
		T dot_value = this->dot(other);
		T thismag = this->magnitude();
		T thatmag = other.magnitude();
		T cos_value = std::cos(1);
		return cos_value;
	}
}

