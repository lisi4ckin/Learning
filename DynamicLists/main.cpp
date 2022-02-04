#include <iostream>
#include "List.h"
#include "BidirectionalList.h"

using namespace std;

int main() {
	List MyList;
	BidirectionalList MyBiList;
	for (int i = 0; i < 3; i++) {
		MyList.AddComponent(MyList.CreateComponent(i));
	}
	for (int i = 0; i < 3; i++) {
		MyBiList.AddComponent(MyBiList.CreateComponent(i));
	}
	MyList.AddComponentAfter(MyList.GetComponentByValue(1), MyList.CreateComponent(5));
	MyList.ShowAllList();
	MyList.DeleteComponent(MyList.GetComponentByValue(5));
	cout << endl;
	MyList.ShowAllList();
	cout << endl;
	MyBiList.ShowAllList();
	cout << endl;
	MyBiList.DeleteComponent(MyBiList.GetComponentByValue(0));
	MyBiList.ShowAllList();
	return 0;
}