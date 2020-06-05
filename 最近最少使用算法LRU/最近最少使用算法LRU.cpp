// 最近最少使用算法LRU.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

int List_MaxSize = 0;
int Page_MaxSize = 0;
vector <int> List;
vector <int> Page;
int sum;//用于计算缺页中断率




void SetList()
{
	List = { 4,3,2,1,4,3,5,4,3,2,1,5,3,5,4,3,2,1,5,5 };//最大为12
	cout << "序列：";
	for (int i = 0; i < List_MaxSize; i++)
	{
		cout << List.at(i) << " ";
	}
	cout << endl;
}

void SetPage()
{
	for (int i = 0; i < Page_MaxSize; i++)
	{
		Page.push_back(0);
	}
}






bool LRU(int temp)
{
	bool okk = true;

	for (int i = 0; i < Page_MaxSize; i++)
	{

		if (Page.at(i) == temp)
		{
		
			vector<int>::iterator k = Page.begin()+i;
			Page.erase(k);
			Page.insert(Page.begin(), temp);
			 okk = false;
		}
		else
		{
			if (Page.at(i) == 0)
			{
				Page.at(i) = temp;
				sum = sum + 1;
				return true;
			}

		}
	}

	if (Page.at(Page_MaxSize - 1) != 0 && okk)
	{
		//vector<int>::iterator k = Page.begin();
		sum = sum + 1;
		//Page.erase(k);
		Page.pop_back();
		Page.insert(Page.begin(), temp);
	}
}

void Show()
{
	cout << "页面：";
	for (int i = 0; i < Page_MaxSize; i++)
	{
		cout << Page.at(i) << " ";
	}
	cout << endl;

}

void Run()
{
	for (int i = 0; i < List_MaxSize; i++)
	{
		LRU(List.at(i));
		Show();
	}
}


int main()
{
	cout << "请输入序列的长度" << endl;
	cin >> List_MaxSize;
	SetList();
	cout << "请输入页表的个数" << endl;
	cin >> Page_MaxSize;
	SetPage();
	Run();
	cout << "缺页中断率：" << float(sum) / float(List_MaxSize);
}
