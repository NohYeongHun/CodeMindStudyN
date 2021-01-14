// 람다를 이해해보자..
// #include <iostream>
// #include <functional>
// #include <map>

// using namespace std;

// int* manipulate(int(*x)(int), int* y) {
	
// 	for (int i = 0; i < 5; i++) {
// 		y[i] = x(y[i]);
// 	}
// 	return y;
// }

// int add(int x) {
// 	return x + 1;
// }

// int* addOne(int*value) {
// 	return manipulate(add, value);
// }

// int twoTime(int x) {
// 	return x * 2;
// }

// int* multiplyTwo(int*value) {
// 	return manipulate(twoTime, value);
// }

// auto addOneAndMultiplyTwo = [=](int* value) { multiplyTwo(addOne(value)); };

// //int* addOneAndMultiplyTwo(int* value) {
// //	return multiplyTwo(addOne(value));
// //}

// int main()
// {
// 	int data[] = { 1,2,3,4,5 };
// 	addOneAndMultiplyTwo(data);
// 	for (int i = 0; i < 5; i++) {
// 		printf("%d ", data[i]);
// 	}
// }
