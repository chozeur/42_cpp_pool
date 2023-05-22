#include "PmergeMe.hpp"
#include <ctime>

int	main(int ac, char **av)
{

	system("clear");std::cout << std::endl;

	PmergeMe	pmm(ac, av);

	std::cout << BOLD << ITALIC << "Unsorted vector: " << RESET << std::endl;
	std::cout << ORANGE;
	PmergeMe::printVector(pmm.getVector());
	std::cout << RESET;

	std::cout << BOLD << ITALIC << "Sorted vector: " << RESET << std::endl;
	std::clock_t start = std::clock();
	std::cout << GREEN;
	PmergeMe::printVector(pmm.mergeInsertionSortVector());
	std::cout << RESET;
	std::clock_t end = std::clock();
	double duration = (end - start) / (double) CLOCKS_PER_SEC;
	std::cout << "Time taken by function: " << BLUE << duration * 1000000 << " microseconds" << RESET << std::endl;

	std::cout << std::endl;

	std::cout << BOLD << ITALIC << "Unsorted list: " << RESET << std::endl;
	std::cout << ORANGE;
	PmergeMe::printList(pmm.getList());
	std::cout << RESET;

	std::list<int>	l = pmm.getList();
	std::cout << BOLD << ITALIC << "Sorted list: " << RESET << std::endl;
	std::clock_t start2 = std::clock();
	std::cout << GREEN;
	PmergeMe::printList(pmm.mergeInsertionSortList(l));
	std::cout << RESET;
	std::clock_t end2 = std::clock();
	double duration2 = (end2 - start2) / (double) CLOCKS_PER_SEC;
	std::cout << "Time taken by function: " << BLUE << duration2 * 1000000 << " microseconds" << RESET << std::endl;

	return (0);
}
