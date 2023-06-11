#pragma once
#include <iostream>

using namespace std;

template <typename T>
T isBig(T tData_1, T tData_2);

template <typename T1, typename T2>
void isBig(T1 tData_1, T2 tData_2);

template <typename T>
T returnValue(T Data);


template <typename T>
T isBig(T tData_1, T tData_2) {
	if (tData_1 > tData_2) return tData_1;
	else return tData_2;
}

template <typename T1, typename T2>
void isBig(T1 tData_1, T2 tData_2) {
	
	if (tData_1 > tData_2)
		cout << returnValue(tData_1) << endl;
	else cout << returnValue(tData_2) << endl;

}

template <typename T>
T returnValue(T Data) {
	return Data;
}