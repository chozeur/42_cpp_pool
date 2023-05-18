#include <iostream>
#include <list>

void mergeInsertionSort(std::list<int>& arr) {
    if (arr.size() < 2) {
        return;
    }

    // Divide the list into two halves
    std::list<int> left, right;
    int size = arr.size();
    int mid = size / 2;
    for (int i = 0; i < mid; i++) {
        left.push_back(arr.front());
        arr.pop_front();
    }
    while (!arr.empty()) {
        right.push_back(arr.front());
        arr.pop_front();
    }

    // Recursively sort the two halves
    mergeInsertionSort(left);
    mergeInsertionSort(right);

    // Merge the two sorted halves
    arr.clear();
    while (!left.empty() && !right.empty()) {
        if (left.front() < right.front()) {
            arr.push_back(left.front());
            left.pop_front();
        }
        else {
            arr.push_back(right.front());
            right.pop_front();
        }
    }
    while (!left.empty()) {
        arr.push_back(left.front());
        left.pop_front();
    }
    while (!right.empty()) {
        arr.push_back(right.front());
        right.pop_front();
    }

    // Perform Insertion Sort on the list
    std::list<int>::iterator it1, it2;
    for (it1 = arr.begin(); it1 != arr.end(); it1++) {
        int temp = *it1;
        it2 = it1;
        while (it2 != arr.begin() && *(--it2) > temp) {
            std::iter_swap(it2, std::next(it2));
        }
        *it2 = temp;
    }
}

int	main(int ac, char **av)
{
	std::list<int>	arr;

	for (int i = 1; i < ac; ++i){
		arr.push_back(atoi(av[i]));
	}

	std::list<int> arr_copy(arr);
	mergeInsertionSort(arr_copy);

	for (std::list<int>::iterator i = arr_copy.begin(); i != arr_copy.end(); ++i)
		std::cout << *i << " ";

	std::cout << std::endl;

	return (0);
}
