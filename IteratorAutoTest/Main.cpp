#include <iostream>

// Template example: This function takes any kind of type and returns that same type
template<class Type> Type f(Type x) { return x + 1; }

// Example of templates use
template<class Type> struct Jim
{
	Type x, y, z;
};
typedef Jim<float> floatJim;
typedef Jim<int> intJim;


// Traits example: Traits are used when you need too many types or need to implement some if-then-else with types. 
// With type, you cannot access properties. With traits you can encapsulate.
struct Bigtraits
{
	typedef int intsize;
};
struct Smalltraits
{
	typedef char intsize;
};

template<typename T> size_t getSize()
{
	// if we did't use Traits, we would have to make an if-else type check here
	return sizeof(typename T::intsize);
}


// Exercise: sum a variable number of numbers
template<typename T> T adder(T t)
{
	return t;
}
template<typename T,typename... Ts> T adder(T t, Ts... args)
{
	return t + adder(args...);
}

int main()
{
	std::cout << f(1) << "\n";
	std::cout << f(1.5f) << "\n";

	int result = adder(1, 2, 3, 4);
	
	// The traits example
	size_t size;
	size = getSize<Smalltraits>();
	size = getSize<Bigtraits>();
}