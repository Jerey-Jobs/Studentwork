extern a;
int function(int m)
{
	int i, s=1;
	for(i = 0; i < m; i++)
	{
		s*=a;
	}
	return s;
}
