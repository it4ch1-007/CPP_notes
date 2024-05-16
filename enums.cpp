#include <iostream>


E& operator ++ (E& e)
{
	if (e == E::end) {
		throw std::out_of_range("For E& operator ++ (E&)");
	}
	e = E(static_cast<std::underlying_type<E>::type>(e) + 1);
	return e;
};
first& operator ++ (first& e)
{
	if (e == first::end) {
		throw std::out_of_range("For first& operator ++ (first&)");
	}
	e = first(static_cast<std::underlying_type<first>::type>(e) + 1);
	return e;
}
enum first {
	v1,
	v2,
	v3 = 5,
	v4 = 0,
	v5 = v3 + 4
};
enum E {
	Begin,
	E1 = Begin,
	E2,
	E3,
	End
};
int main() {
	//the default values given to the enum members is the count.
	
	

	//iteration inside the enum
	for (E e = E::Begin; e != E::End; ++e) {

	}

	for (first it = first::v1; it != v5; ++it) {
		std::cout << it << std::endl;
	}
}