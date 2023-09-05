#include "heap.h"


void AAA::print()
{
	std::cout << x;
}

int AAA::getPriority() const
{
	return x;
}



namespace heap
{
	Heap create(int maxsize, CMP(*f)(void*, void*))
	{
		return *(new Heap(maxsize, f));
	}

	int Heap::left(int ix)
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}

	int Heap::right(int ix)
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}

	int Heap::parent(int ix)
	{
		return (ix + 1) / 2 - 1;
	}

	void Heap::swap(int i, int j)
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}

	void Heap::heapify(int ix)
	{
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(storage[l], storage[ix])) irl = l;
			if (r > 0 && isGreat(storage[r], storage[irl])) 	irl = r;
			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}

	void Heap::insert(void* x)
	{
		int i;
		if (!isFull())
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}

	void* Heap::extractMax()
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[0];
			storage[0] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}

	void* Heap::extractMin()
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[size - 1];
			storage[size - 2] = storage[size - 1];
			size--;
			heapify(0);
		}
		return rc;
	}

	void Heap::scan(int i) const     //Вывод значений элементов на экран
	{
		int probel = 20;
		std::cout << '\n';
		if (size == 0)
			std::cout << "Куча пуста";
		for (int u = 0, y = 0; u < size; u++)
		{
			std::cout << std::setw(probel + 10) << std::setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{
				std::cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}
			probel /= 2;
		}
		std::cout << '\n';
	}


	void Heap::minHeapify(int ix)
	{
		int l = left(ix), r = right(ix), irm = ix;
		if (l > 0 && isLess(storage[l], storage[ix])) irm = l;
		if (r > 0 && isLess(storage[r], storage[irm])) irm = r;
		if (irm != ix)
		{
			swap(ix, irm);
			minHeapify(irm);
		}
	}


	

	void Heap::deleteI(int ix)
	{
		if (ix >= size) return;
		if (ix == size - 1)
		{
			size--;
			return;
		}
		swap(ix, size - 1);
		size--;
		minHeapify(ix);
	}


	void Heap::merge(Heap& other)
	{
		for (int i = 0; i < other.size; i++)
		{
			insert(other.storage[i]);
		}
		other.size = 0;
	}

	void Heap::unionHeap(Heap& other)
	{
		merge(other);
		delete[] other.storage;
	}

}


using namespace std;

heap::CMP cmpAAA(void* a1, void* a2)  //Функция сравнения
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)

	heap::CMP rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else if (A2->x > A1->x)
		rc = heap::LESS;
	return rc;

#undef A2
#undef A1 
}

int main()
{
	heap::Heap h = heap::create(100, cmpAAA);

	while (true) {
		int choice;
		cout << "\nMenu:\n";
		cout << "1. Print the heap\n";
		cout << "2. Add an element to the heap\n";
		cout << "3. Remove min/max/element at index\n";
		cout << "4. Merge heaps\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			h.scan(0);
			break;
		case 2: {
			int priority;
			cout << "Enter the priority of the new element: ";
			cin >> priority;
			AAA* newElem = new AAA;
			newElem->x = priority;
			h.insert(newElem);
			break;
		}
		case 3:
			int removeChoice;
			cout << "1. Remove min element\n";
			cout << "2. Remove max element\n";
			cout << "3. Remove element at index\n";
			cout << "Enter your choice: ";
			cin >> removeChoice;

			switch (removeChoice) {
			case 1:
				h.extractMin();
				break;
			case 2:
				h.extractMax();
				break;
			case 3:
				int index;
				cout << "Enter the index of the element to remove: ";
				cin >> index;
				h.deleteI(index);
				break;
			default:
				cout << "Invalid choice\n";
				break;
			}
			break;
		case 4: {
			int heapSize;
			cout << "Enter the size of the new heap: ";
			cin >> heapSize;
			heap::Heap newHeap = heap::create(heapSize, cmpAAA);
			for (int i = 0; i < heapSize; i++) {
				int priority;
				cout << "Enter the priority of element " << i + 1 << ": ";
				cin >> priority;
				AAA* newElem = new AAA;
				newElem->x = priority;
				newHeap.insert(newElem);
			}
			h.unionHeap(newHeap);
			break;
		}
		case 5:
			return 0;
		default:
			cout << "Invalid choice\n";
			break;
		}
	}

	return 0;
}