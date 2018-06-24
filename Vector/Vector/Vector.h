#pragma once
#include <iostream>

namespace jrw {
	template <class T>
	class Vector {
	public:
		Vector<T>();
		Vector<T>(T x, T y);
		Vector<T>(T x, T y, T z);
		~Vector<T>();

		int x, y, z;

		void print() const;
		Vector& add(const Vector& other);
		Vector& minus(const Vector& other);
		Vector& times(const int& scale);
		Vector& divide(const int& scale);
		Vector& vtimes(const Vector& other);
		Vector& vdivide(const Vector& other);

		//overload operator +, -, *
		friend Vector operator+(Vector left, Vector right);
		friend Vector operator-(Vector left, Vector right);
		friend Vector operator*(Vector origin, int scale);
		friend Vector operator*(Vector left, Vector right);
		friend Vector operator/(Vector origin, int scale);
		friend Vector operator/(Vector left, Vector right);

		//overload operator ==
		bool operator==(const Vector& other) const;

		//class work
		int dot(const Vector& other); //dot product
		int cross(const Vector& other); //cross product
		double magnitude();
		double mag2();
		Vector& normalized();
		double eulerangle();
		double eulerangleToVector(Vector other);

		//overload operator <<, <=, >=, ==< !=, <, >, +, -, *, /, /=. *=, +=, -=
	};
}

