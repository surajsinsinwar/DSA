
// An Optimizationn done in the find function.

int find(int x)
{
	if(parent[x] == x)
	{
		return x;
	}

	parent[x] = find(x);

	return parent[x];
}