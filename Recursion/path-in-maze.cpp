#include<bits/stdc++.h>
using namespace std;

// explore maze using recursion.
bool exploreMaze(int m[8][], int x, int y)
{
	if(y > 8 || y < 1 || x < 'A' || x > 'H' || m[x][y] == '*')
	{
		return false;
	}
	
	if(m[x][y] == 'E')
	{
		return true;
	}

	if(y - 1 >= 1 && m[x][y - 1] != '*')
	{
		m[x][y - 1] = '*';
		if(exploreMaze(m, x, y - 1)) return true;
		m[x][y - 1] = ' ';
	}
	if(y + 1 <= 8 && m[x][y + 1] != '*')
	{
		m[x][y + 1] = '*';
		if(exploreMaze(m, x, y + 1)) return true;
		m[x][y + 1] = ' ';
	}
	if(x - 1 >= 'A' && m[x - 1][y] != '*')
	{
		m[x - 1][y] = '*';
		if(exploreMaze(m, x - 1, y)) return true;
		m[x - 1][y] = ' ';
	}
	if(x + 1 <= 'H' && m[x + 1][y] != '*')
	{
		m[x + 1][y] = '*';
		if(exploreMaze(m, x + 1, y)) return true;
		m[x + 1][y] = ' ';
	}

	return false;
}