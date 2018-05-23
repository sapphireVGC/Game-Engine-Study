#include <iostream>
#include <memory>

using namespace std;

class Foo {
private :
	int age;
}

int main() {
	shared_ptr<Foo> a = make_shared<Foo>();
	cout << a.use_count;
	int break_;
	return 0;
}