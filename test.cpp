#include <iostream>

using namespace std;

class B{
private:
	char c;

public:
	B(char o){
		c = o;
	}

	B(){
		c = 0;
	}
};

class A{
	private:
		int a;
		B b;

	public:
		A(int s, B obj){
			a = s;
			b = obj;
		}
};

int main(){
	B b('a');

	A a(34, b);
}
