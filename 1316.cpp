/*
* File:   main.cpp
* Author: magic282
*
* Created on 2012年7月26日, 上午11:00
*/
 
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <stack>
#include <bitset>
#include <numeric>
#include <functional>
#include <climits>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <string>
 
using namespace std;
 
/*
*
*/
 
const int maxn = 100;
 
int valid(char a, char b) {
    int v[5][5] = {
        {5, -1, -2, -1, -3},
        {-1, 5, -3, -2, -4},
        {-2, -3, 5, -2, -2},
        {-1, -2, -2, 5, -1},
        {-3, -4, -2, -1, INT_MIN}
    };
    int x, y;
    switch (a) {
        case 'A':
            x = 0;
            break;
        case 'C':
            x = 1;
            break;
        case 'G':
            x = 2;
            break;
        case 'T':
            x = 3;
            break;
        default:
            x = 4;
            break;
    }
    switch (b) {
        case 'A':
            y = 0;
            break;
        case 'C':
            y = 1;
            break;
        case 'G':
            y = 2;
            break;
        case 'T':
            y = 3;
            break;
        default:
            y = 4;
            break;
    }
    return v[x][y];
}
 
int result[maxn + 10][maxn + 10];
 
int max3(int a, int b, int c) {
    int m = a;
    m = (b > m) ? b : m;
    m = (c > m) ? c : m;
    return m;
}
 
int main(int argc, char** argv) {
    freopen("1316.in", "r", stdin);
    //    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    string a, b;
    while (t--) {
        memset(result, 0, sizeof (result));
        int m, n;
        cin >> m >> a >> n >> b;
        result[0][0] = 0;
        for (int j = 1; j <= n; ++j) {
            result[0][j] = result[0][j - 1] + valid('-', b[j - 1]);
        }
        for (int i = 1; i <= m; ++i) {
            result[i][0] = result[i - 1][0] + valid(a[i - 1], '-');
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                result[i][j] = max3(
                        result[i - 1][j - 1] + valid(a[i - 1], b[j - 
1]),
                        result[i][j - 1] + valid('-', b[j - 1]),
                        result[i - 1][j] + valid(a[i - 1], '-'));
            }
        }
	for(int i=0; i<=m; ++i){
		for(int j=0; j<=n; ++j)
			printf("%3d", result[i][j]);
		putchar('\n');
	}
        printf("%d\n", result[m][n]);
    }
 
    fclose(stdin);
    //    fclose(stdout);
    return 0;
}
