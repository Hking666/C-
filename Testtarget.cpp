bool Find(int target, vector<vector<int> > array) {

	int Csize = array.size();
	int Rszie = array[0].size();
	for (int i = 0; i< Csize; ++i)
	{
		if (target == array[i][Rszie - 1])
		{
			return true;
		}
		if (target < array[i][Rszie - 1])
		{
			for (int j = 0; i<Rszie; ++j)
			{
				if (target == array[i][j])
				{
					return true;
				}
			}

		}


	}
	return false;

}
int  main()
{
	vector<vector<int>> vv;

	vv.resize(10);
	for (int i = 0; i < 10; i++)
	{
		vv[i].resize(8);
		for (int j = 0; j < 8; j++)
		{
			
			vv[i][j] = i + j;
		}


	}
	cout<<vv.size()<<endl;
	cout<<vv[1].size()<<endl;
	
	if (Find(5, vv))
	{
		cout << "有" << endl;
	}
	else
	{
		cout << "没" << endl;
	}
	system("pause");
	return 0;
}
