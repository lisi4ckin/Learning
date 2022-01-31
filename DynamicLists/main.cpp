#include <iostream>
#include "List.h"

using namespace std;

int main() {
	List MyList;
	for (int i = 0; i < 3; i++) {
		MyList.AddComponent(MyList.CreateComponent(i));
	}
	MyList.AddComponentAfter(MyList.GetComponentByValue(1), MyList.CreateComponent(5));
	MyList.ShowAllList();
	return 0;
}