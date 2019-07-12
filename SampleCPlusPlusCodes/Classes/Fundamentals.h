#ifndef __Fundamentals_H__
#define __Fundamentals_H__
class MyClass
{
public:
	int val = 10;

	MyClass(int, int);
	MyClass(double, double);
	MyClass() { width = 1; length = 5; };
	~MyClass();
	void calculateArea(void);


private:
	int width, length;
	void print(int);

};


#endif // !__Fundamentals_H__
