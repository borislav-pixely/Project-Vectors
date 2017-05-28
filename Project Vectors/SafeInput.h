#ifndef SAFE_INPUT_H
#define SAFE_INPUT_H

#include <iostream>

template <typename T>
class SafeInput {

public:
	inline SafeInput<T>& operator >> (T& t) {
		for (std::cin >> t; std::cin.fail(); std::cin.clear(),
			 std::cout << " Невалидна стойност. Опитайте отново: ",
			 std::cin.getline(buffer, 1023),
			 std::cin >> t);
		return *this;
	}

private:
	char buffer[1024];

};

#endif /* SAFE_INPUT_H */