#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

struct comparator
{
	unsigned long int first;
	unsigned long int second;
	comparator *next;
};

int comparators = 0;
vector<int> tacts;
comparator *firstComp = NULL;
comparator *currentComp = NULL;

void push(int i1, int i2)
{
	cout << i1 << " " << i2 << endl;
	if (firstComp == NULL) {
		firstComp = new comparator;
		firstComp->first = i1;
		firstComp->second = i2;
		firstComp->next = NULL;
		currentComp = firstComp;
	}
	else {
		currentComp->next = new comparator;
		currentComp = currentComp->next;
		currentComp->first = i1;
		currentComp->second = i2;
		currentComp->next = NULL;
	}
	comparators++;
}

void join(int start1, int start2, int step, int n, int m)
{
	int tactCount0 = 0, tactCount1 = 0;
	int i, n1, m1;
	if (n * m < 1){
		return;
	}
	if (n == 1 && m == 1) {
		push(start1, start2);
		tacts[start1] = tacts[start2] = max(tacts[start1], tacts[start2]) + 1;
		return;
	}
	n1 = n - n / 2;
	m1 = m - m / 2;
	join(start1, start2, step * 2, n1, m1);
	join(start1 + step, start2 + step, step * 2, n - n1, m - m1);
	for (i = 1; i < n - 1; i += 2) {
		push(start1 + step * i, start1 + step * (i + 1));
	    tacts[start1 + step * i] = tacts[start1 + step * (i + 1)] = max(tacts[start1 + step * i], tacts[start1 + step * (i + 1)]) + 1;
	}
	if (n % 2 == 0){
		push(start1 + step * (n - 1), start2);
		tacts[start1 + step * (n - 1)] = tacts[start2] = max(tacts[start1 + step * (n - 1)], tacts[start2]) + 1;
	}
	for (i = (n % 2 == 0) ? 1 : 0; i < m - 1; i += 2) {
		push(start2 + step * i, start2 + step * (i + 1));
	    tacts[start2 + step * i] = tacts[start2 + step * (i + 1)] = max(tacts[start2 + step * i], tacts[start2 + step * (i + 1)]) + 1;
	}
	return;
}

void sort(int start, int step, int n)
{
	int tactCount0, tactCount1, tactCountJoin;
	if (n < 2)
		return;
	int half = n / 2;
	sort(start, step, half);
	sort(start + step * half, step, n - half);
	join(start, start + step * half, step, half, n - half);
	return;
}

void test(int n){
	bool testArray[24];
	unsigned int mask;
	bool isCorrect = true;
	for (unsigned int i = 0; i < (int)pow(2.0, n); i++) {
		mask = 1;
		for (int j = n - 1; j >= 0 ; j--) {
			testArray[j] = i & mask > 0 ? true : false;
			mask = mask << 1;
		}
		currentComp = firstComp;
		while (currentComp != NULL)
		{
			if (testArray[currentComp->first] != testArray[currentComp->second] && testArray[currentComp->first]) {
				testArray[currentComp->first] = false;
				testArray[currentComp->second] = true;
			}
			currentComp = currentComp->next;
		}
		for (int j = 0; j < n - 1; j++) {
			if (testArray[j] != testArray[j + 1] && testArray[j]) {
				isCorrect = false;
				break;
			}
		}
		if (!isCorrect) break;
	}
	if (n <= 24) printf(isCorrect ? "true\n" : "false\n");
}

int main(int argc, char* argv[])
{
	int n = 0, start = 0, tactMax = 0, step = 1;
	if (argc >= 2) {
		n = atoi(argv[1]);
	} else {
		cout << "Not arguments" << endl;
		return -1;
	}
	tacts = vector<int>(n, 0);
	cout << n << " " << 0 << " " << 0 << endl;
	sort(start, step, n);
	vector<int>::iterator it = tacts.begin();
	tactMax = *it;
	for (; it < tacts.end(); it++){
		if(tactMax < *it)
			tactMax = *it;
	}
	cout << comparators << endl << tactMax << endl;
	//test(n);
    return 0;
}
