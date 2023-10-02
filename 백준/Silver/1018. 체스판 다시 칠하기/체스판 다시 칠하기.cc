#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
    };

    string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
    };

    vector<string> input;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        input.push_back(str);
    }
    vector<int> total;

    // 시작이 W 일때
    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j++)
        {
            int count = 0;
            for (int k = i; k < i + 8; k++)
            {
                for (int l = j; l < j + 8; l++)
                {
                    if (WB[k - i][l - j] != input[k][l])
                        count++;
                }
            }
            total.push_back(count);
        }
    }

    // 시작이 B 일때
    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j++)
        {
            int count = 0;
            for (int k = i; k < i + 8; k++)
            {
                for (int l = j; l < j + 8; l++)
                {
                    if (BW[k - i][l - j] != input[k][l])
                        count++;
                }
            }
            total.push_back(count);
        }
    }

    cout << *min_element(total.begin(), total.end());

	return 0;
}