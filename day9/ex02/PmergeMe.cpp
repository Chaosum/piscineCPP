/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:33:47 by matthieu          #+#    #+#             */
/*   Updated: 2023/03/28 01:25:07 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

PmergeMe::PmergeMe(int ac, char **av){
	initContainers(ac, av);
}


PmergeMe::PmergeMe(const PmergeMe &src){
	this->vect = src.vect;
	this->lst = src.lst;
}

PmergeMe::~PmergeMe(){
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src){
	this->vect = src.vect;
	this->lst = src.lst;
	return (*this);
}

void	PmergeMe::initContainers(int ac, char **av){
	int i = 1;
	std::cout << "before : ";
	while (i < ac){
		vect.push_back(atoi(av[i]));
		lst.push_back(atoi(av[i]));
		std::cout << av[i] << " ";
		i++;
	}
	std::cout << std::endl;
}

void PmergeMe::mergeVector(std::vector<int>& nums, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> left_side(n1), right_side(n2);
    for (int i = 0; i < n1; ++i) {
        left_side[i] = nums[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        right_side[j] = nums[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (left_side[i] <= right_side[j]) {
            nums[k] = left_side[i];
            ++i;
        } else {
            nums[k] = right_side[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        nums[k] = left_side[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        nums[k] = right_side[j];
        ++j;
        ++k;
    }
}

void PmergeMe::insertionSort(std::vector<int>& nums, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = nums[i];
        int j = i - 1;
        while (j >= left && nums[j] > key) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = key;
    }
}

void PmergeMe::mergeInsertionSort(std::vector<int>& nums, int left, int right) {
    const int insertionSortThreshold = 16;
    if (right - left + 1 <= insertionSortThreshold) {
        insertionSort(nums, left, right);
    } else {
        int mid = left + (right - left) / 2;
        mergeInsertionSort(nums, left, mid);
        mergeInsertionSort(nums, mid + 1, right);
        mergeVector(nums, left, mid, right);
    }
}

void PmergeMe::mergeInsertionSort(std::vector<int>& nums) {
    mergeInsertionSort(nums, 0, nums.size() - 1);
}


void PmergeMe::mergeList(std::list<int>& nums, std::list<int>& left, std::list<int>& right) {
    std::list<int>::iterator itL = left.begin();
    std::list<int>::iterator itR = right.begin();
    while (itL != left.end() && itR != right.end()) {
        if (*itL <= *itR) {
            nums.push_back(*itL);
            ++itL;
        } else {
            nums.push_back(*itR);
            ++itR;
        }
    }
    while (itL != left.end()) {
        nums.push_back(*itL);
        ++itL;
    }
    while (itR != right.end()) {
        nums.push_back(*itR);
        ++itR;
    }
}

void PmergeMe::insertionSortList(std::list<int>& nums) {
	std::list<int>::iterator it = nums.begin();
    for (; it != nums.end(); ++it) {
        int key = *it;
        std::list<int>::iterator itPrev = it;
        while (itPrev != nums.begin() && *(--itPrev) > key) {
            std::iter_swap(itPrev, it);
            it = itPrev;
        }
    }
}

void PmergeMe::mergeInsertionSortList(std::list<int>& nums) {
    const int insertionSortThreshold = 32;
    if (nums.size() <= 1) {
        return;
    }
    if (nums.size() <= insertionSortThreshold) {
        insertionSortList(nums);
        return;
    }
    std::list<int> left, right;
    size_t i = 0;
    for (std::list<int>::iterator it = nums.begin(); it != nums.end(); ++it, ++i) {
        if (i < nums.size() / 2) {
            left.push_back(*it);
        } else {
            right.push_back(*it);
        }
    }
    nums.clear();
    mergeInsertionSortList(left);
    mergeInsertionSortList(right);
    mergeList(nums, left, right);
}

std::list<int> &PmergeMe::getList(){
	return (this->lst);
}
std::vector<int> &PmergeMe::getVector(){
	return (this->vect);
}


