#include <iostream>
#include <stack>
#include <algorithm>


using namespace std;

int main(void)
{
	int n;
	scanf("%d", &n);

	int order, num;
	stack<int> basket;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &order);
		if (order == 1) {
			scanf("%d", &num);
			basket.push(num);
		}
		else if (order == 2) {
			if (basket.size() != 0) {
				printf("%d", basket.top());
				basket.pop();
			}
			else {
				printf("%d", -1);
			}
			printf("\n");
		}
		else if (order == 3) {
			printf("%d", basket.size());
			printf("\n");
		}
		else if (order == 4) {
			if (basket.size() == 0) {
				printf("%d", 1);
			}
			else {
				printf("%d", 0);
			}
			printf("\n");
		}
		else if (order == 5) {
			if (basket.size() != 0) {
				printf("%d", basket.top());
			}
			else {
				printf("%d", -1);
			}
			printf("\n");
		}
	}
	
	return 0;
}