#include <iostream>
#include <string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
//sort(memory.begin(), memory.end(), [&](int a, int b) {return a >b; });
//struct node
//{ int val;   node *next;
//	int x, y;
//} a[100005];
//while (cin >> n >> k)
//{
//	for (int i = 0; i < n; i++)//保存每个数据的颜色，以及这个节点的位置
//	{
//		cin >> a[i].color;
//		a[i].pos = i;
//	}
//}

//周赛第一题
int numIdenticalPairs(vector<int>& nums) {
	int a[101];
	for (auto & n : nums)
	{
		a[n] += 1;
	}

	int count = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (a[i] >= 2)
		{
			count += ((1 + a[i] - 1)*(a[i] - 1) / 2);
		}
	}
	return count;

	/*
	vector<int> vint;
	vint.push_back(1);
	vint.push_back(2);
	vint.push_back(3);
	//vint.push_back(1);
	//vint.push_back(1);
	//vint.push_back(3);

	cout << numIdenticalPairs(vint) << endl;
	*/
}

//周赛第第二题
int numSub(string s) {
	char * chr = (char*)s.c_str();

	long long indexMax = s.size();

	//cout << chr[1] << endl;
	//cout << s.size() << endl;

	if (indexMax == 1)
	{
		if (chr[0] == '1')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	long long firstID = -1;
	long long secondID = -1;

	long long count = 0;
	for (long long i = 0; i < indexMax; i++)
	{
		if (chr[i] == '1')
		{
			if (firstID == -1)
			{
				firstID = i;
			}
		}
		else
		{
			if (secondID == -1 && firstID != -1)
			{
				secondID = i - 1;
				long long num = secondID + 1 - firstID;
				count += ((1 + num)*num / 2);

				firstID = -1;
				secondID = -1;
			}
		}

		if (i == indexMax - 1)
		{
			if (secondID == -1 && firstID != -1)
			{
				secondID = i;
				long long num = secondID + 1 - firstID;
				count += ((1 + num)*num / 2);
			}
		}
	}

	//cout <<"final num :"<< count << endl;

	return count % (1000000000 + 7);
}

//牛客剑指JZ9
int jumpFloorII(int number) {
	vector<int > cap(number + 1);
	for (auto & i : cap)
	{
		i = 0;
	}

	for (int i = 1; i <= number; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (j == 0 || j == i - 1)
			{
				cap[i] += 1;
			}
			else if (j == 1)
			{
				cap[i] += cap[i - 1];
			}
			else
			{
				cap[i] += cap[j] + cap[i - j];
			}
			cout << "now is " << i << " the first step is " << j << " and accumulate num is " << cap[i] << endl;
		}
	}
	return cap[number];
}

//牛客剑指JZ43
string LeftRotateString2(string str, int n) {
	if (n < 0) return NULL;
	if (n == 0) return str;
	string s1 = str.substr(0, n);
	str.erase(0, n);
	str += s1;
	return str;
}

string LeftRotateString(string str, int n) {
	char * chr = (char*)str.c_str();
	long long indexMax = str.size();

	if (n == 0 || indexMax == 0)
	{
		return str;
	}
	else
	{
		long long dis = n % indexMax;
		char * char2 = new char[indexMax];
		//strcpy_s(char2, indexMax, str.c_str());
		for (int i = 0; i < dis; i++)
		{
			char2[indexMax - 1 - i] = chr[dis - 1 - i];
		}

		for (int i = dis; i < indexMax; i++)
		{
			char2[i - dis] = chr[i];
		}
		string str2 = char2;
		return str2;
	}
}

//牛客剑指JZ60
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
vector<vector<int> > Print(TreeNode* pRoot) {

	vector<vector<TreeNode*> > roots;
	vector<TreeNode*> rt;
	rt.push_back(pRoot);
	roots.push_back(rt);
	int level = 0;

	//while(!roots[level].empty())
	while (1)
	{
		vector<TreeNode*> rts = roots[level];
		break;

		vector<TreeNode*> rts_new;
		for (auto & rt : rts)
		{
			if (rt->left != NULL)
			{
				rts_new.push_back(rt->left);
			}
			if (rt->right != NULL)
			{
				rts_new.push_back(rt->right);
			}
		}
		if (!rts_new.empty())
		{
			roots.push_back(rts_new);
			level += 1;
		}
		else break;

	}

	vector<vector<int>> sum;
	
	for (int i = 0; i < roots.size(); i++)
	{
		if (!roots[i].empty())
		{
			vector<int> a;
			for (auto& rt : roots[i])
			{
				a.push_back(rt->val);
				//cout<<rt->val;
			}
			sum.push_back(a);
			//cout<<endl;
		}
		else break;
	}
	//for (auto & rts : roots)
	//{
	//	if (!rts.empty())
	//	{
	//		vector<int> a;
	//		for (auto& rt : rts)
	//		{
	//			a.push_back(rt->val);
	//			//cout<<rt->val;
	//		}
	//		sum.push_back(a);
	//		//cout<<endl;
	//	}
	//	else break;
	//}
	return sum;
}

//牛客剑指JZ19
vector<int> printMatrix(vector<vector<int> > matrix) {
	int dire = 0; //定义方向，0往右，也就是 row不变 col+1,做完之后minRow+=1
			  // 1往下，col不变，row+1，做完之后maxCol-=1
			  // 2往左，row不变，col-1,maxRow-=1
			  // 3往上，col不变，row-1,minCol+=1
			  // 停止条件就是min=max (col or row)
	vector<int > res;
	if (matrix.size() == 1)
	{
		for (auto & num : matrix[0])
		{
			res.push_back(num);
		}
	}
	else if (matrix.size()>1)
	{
		int dire = 0;
		int nowRow = 0;
		int nowCol = 0;
		int maxRow = matrix.size() - 1;
		int maxCol = matrix[0].size() - 1;
		int minRow = 0;
		int minCol = 0;
		res.push_back(matrix[0][0]);
		while (1)
		{
			if (dire == 0)
			{
				//for (nowCol += 1; nowCol <= maxCol; nowCol++)
				//{
				//	res.push_back(matrix[nowRow][nowCol]);
				//}
				for (int k = nowCol+1; k <= maxCol; k++)
				{
					res.push_back(matrix[nowRow][k]);
					cout << matrix[nowRow][k] << endl;
				}
				nowCol = maxCol;
				minRow++;
				dire++;
			}
			else  if (dire == 1)
			{
				/*for (nowRow += 1; nowRow <= maxRow; nowRow++)
				{
					res.push_back(matrix[nowRow][nowCol]);
				}*/
				for(int k = nowRow+1;k<=maxRow;k++)
				{
					res.push_back(matrix[k][nowCol]);
				}
				nowRow = maxRow;
				maxCol--;
				dire++;
			}
			else  if (dire == 2)
			{
				//for (nowCol -= 1; nowCol >= minCol; nowCol--)
				//{
				//	res.push_back(matrix[nowRow][nowCol]);
				//}
				for (int k= nowCol-1; k >= minCol; k--)
				{
					res.push_back(matrix[nowRow][k]);
				}
				nowCol = minCol;
				maxRow--;
				dire++;
			}
			else  if (dire == 3)
			{
				//for (nowRow -= 1; nowRow >= minRow; nowRow--)
				//{
				//	res.push_back(matrix[nowRow][nowCol]);
				//}
				for (int k = nowRow- 1; k >= minRow; k--)
				{
					res.push_back(matrix[k][nowCol]);
				}
				nowRow = minRow;
				minCol++;
				dire = 0;
			}
			if (minCol>maxCol || minRow>maxRow)
			{
				break;
			}
		}
	}
	return res;
}

//滴滴笔试-1
void rowCount(int n)
{
	int k = n * n;
	vector<long long > fbnq(k);
	if (n == 1) cout << 1 << endl;
	else
	{
		fbnq[0] = 1;
		fbnq[1] = 1;
		for (int i = 2; i < k; i++)
		{
			fbnq[i] = fbnq[i - 1] + fbnq[i - 2];
		}
		vector<vector<long long> > matrix(n, vector<long long>(n, 0));
		int dire = 0; //定义方向，0往右，也就是 row不变 col+1,做完之后minRow+=1
					  // 1往下，col不变，row+1，做完之后maxCol-=1
					  // 2往左，row不变，col-1,maxRow-=1
					  // 3往上，col不变，row-1,minCol+=1
					  // 停止条件就是min>max (col or row)
		int nowRow = 0;
		int nowCol = 0;
		int maxRow = n - 1;
		int maxCol = n - 1;
		int minRow = 0;
		int minCol = 0;

		int nowIDX = k - 1;
		matrix[0][0] = fbnq[nowIDX];
		while (1)
		{
			if (dire == 0)
			{
				for (int k = nowCol + 1; k <= maxCol; k++)
				{
					nowIDX--;
					matrix[nowRow][k] = fbnq[nowIDX];
				}
				nowCol = maxCol;
				minRow++;
				dire++;
			}
			else  if (dire == 1)
			{
				for (int k = nowRow + 1; k <= maxRow; k++)
				{
					nowIDX--;
					matrix[k][nowCol] = fbnq[nowIDX];
				}
				nowRow = maxRow;
				maxCol--;
				dire++;
			}
			else  if (dire == 2)
			{
				for (int k = nowCol - 1; k >= minCol; k--)
				{
					nowIDX--;
					matrix[nowRow][k] = fbnq[nowIDX];
				}
				nowCol = minCol;
				maxRow--;
				dire++;
			}
			else  if (dire == 3)
			{
				for (int k = nowRow - 1; k >= minRow; k--)
				{
					nowIDX--;
					matrix[k][nowCol] = fbnq[nowIDX];
				}
				nowRow = minRow;
				minCol++;
				dire = 0;
			}
			if (minCol>maxCol || minRow>maxRow)
			{
				break;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
}

//滴滴笔试中的选择
//int C[15][15];
//memset(C, 0, sizeof(C));
//for (int i = 1; i <= 10; ++i)
//{
//	for (int j = 1; j <= i; ++j)
//	{
//		if (j == 1) C[i][j] = i;
//		else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
//	}
//}
//cout << C[8][3] << endl;

//滴滴笔试-2
//main里的
/*
int n;
cin >> n;
if (n <= 2)
{
	cout << 0;
	return 0;
}

maxRow = n - 1;
maxCol = n - 1;
//vector<vector<char >> matrix(n, vector<char>(n, 0));
for (int i = 0; i < n; i++)
{
	vector<char > mtx;
	for (int j = 0; j < n; j++)
	{
		//cin >> matrix[i][j];
		char k;
		cin >> k;
		mtx.push_back(k);
	}
	matrix.push_back(mtx);
}

for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
	{
		if (matrix[i][j] == 'C')
		{
			find(i, j, 'C');
		}
	}
}
cout << countA << endl;
*/
//long long countA = 0;
//int minRow = 0;
//int minCol = 0;
//int maxRow;
//int maxCol;
//vector<vector<char >> matrix;
//void find(int row, int col, char zimu)
//{	
//	int row_1 = row - 1;  //往上走
//	int col_1 = col;
//
//	int row_2 = row + 1; //往下走
//	int col_2 = col;
//
//	int row_3 = row;
//	int col_3 = col - 1; //往左走
//
//	int row_4 = row;
//	int col_4 = col + 1; //往右走
//	char next;
//	if (zimu == 'C')
//	{
//		next = 'H';
//	}
//	else if (zimu == 'H')
//	{
//		next = 'I';
//	}
//	else if (zimu == 'I')
//	{
//		next = 'N';
//	}
//	else if (zimu == 'N')
//	{
//		next = 'A';
//	}
//	if (zimu == 'A')
//	{
//		countA ++;
//	}
//	else
//	{
//		if (minRow <= row_1 && row_1 <= maxRow && minCol <= col_1 && col_1 <= maxCol)
//		{
//			if (matrix[row_1][col_1] == next)
//			{
//				find( row_1, col_1, next);
//			}
//		}
//		if (minRow <= row_2 && row_2 <= maxRow && minCol <= col_2 && col_2 <= maxCol)
//		{
//			if (matrix[row_2][col_2] == next)
//			{
//				find( row_2, col_2, next);
//			}
//		}
//		if (minRow <= row_3 && row_3 <= maxRow && minCol <= col_3 && col_3 <= maxCol)
//		{
//			if (matrix[row_3][col_3] == next)
//			{
//				find( row_3, col_3, next);
//			}
//		}
//		if (minRow <= row_4 && row_4 <= maxRow && minCol <= col_4 && col_4 <= maxCol)
//		{
//			if (matrix[row_4][col_4] == next)
//			{
//				find( row_4, col_4, next);
//			}
//		}
//
//	}
//}

//牛客剑指 JZ66 机器人运动范围
/*
int countA = 1;
int minRow = 0;
int minCol = 0;
int maxRow;
int maxCol;
vector<vector<bool >> matrix;
int maxSum;
bool canGo(int row, int col)
{
	int sumNum = 0;
	int beichu = row / 10;
	int yushu = row % 10;
	while (yushu != 0 || beichu != 0)
	{
		sumNum += yushu;
		yushu = beichu % 10;
		beichu = beichu / 10;
	}
	yushu = col % 10;
	beichu = col / 10;
	while (yushu != 0 || beichu != 0)
	{
		sumNum += yushu;
		yushu = beichu % 10;
		beichu = beichu / 10;
	}
	if (sumNum>maxSum) return false;
	else return true;
}
void find(int row, int col)
{
	int row_1 = row - 1;  //往上走
	int col_1 = col;
	int row_2 = row + 1; //往下走
	int col_2 = col;
	int row_3 = row;
	int col_3 = col - 1; //往左走
	int row_4 = row;
	int col_4 = col + 1; //往右走
	if (minRow <= row_1 && row_1 <= maxRow && minCol <= col_1 && col_1 <= maxCol)
	{
		if (matrix[row_1][col_1] == false && canGo(row_1, col_1))
		{
			matrix[row_1][col_1] = true;
			find(row_1, col_1);
			countA++;
		}
	}
	if (minRow <= row_2 && row_2 <= maxRow && minCol <= col_2 && col_2 <= maxCol)
	{
		if (matrix[row_2][col_2] == false && canGo(row_2, col_2))
		{
			matrix[row_2][col_2] = true;
			countA++;
			find(row_2, col_2);
		}
	}
	if (minRow <= row_3 && row_3 <= maxRow && minCol <= col_3 && col_3 <= maxCol)
	{
		if (matrix[row_3][col_3] == false && canGo(row_3, col_3))
		{
			matrix[row_3][col_3] = true;
			countA++;
			find(row_3, col_3);
		}
	}
	if (minRow <= row_4 && row_4 <= maxRow && minCol <= col_4 && col_4 <= maxCol)
	{
		if (matrix[row_4][col_4] == false && canGo(row_4, col_4))
		{
			matrix[row_4][col_4] = true;
			countA++;
			find(row_4, col_4);
		}
	}
}

int movingCount(int threshold, int rows, int cols)
{
	if (threshold<0) return 0;
	maxSum = threshold;
	maxRow = rows - 1;
	maxCol = cols - 1;
	matrix.resize(rows);
	for (int i = 0; i < rows; i++)
		matrix[i].resize(cols);
	//memset(matrix[i],false,sizeof(matrix[i]));

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j<cols; j++)
		{
			matrix[i][j] = false;
		}
	}

	matrix[0][0] = true;
	find(0, 0);

	return countA;
}
*/

//牛客剑指JZ32  把数组排成最小数字的样子
static bool cmp(int  a, int  b)
{
	int a_weishu = 1;
	int a_chushu = a / 10;
	int a_maxNum = a % 10;
	while (a_chushu != 0)
	{
		a_weishu += 1;
		a_maxNum = a_chushu;
		a_chushu = a_chushu / 10;
	}

	int b_weishu = 1;
	int b_chushu = b / 10;
	int b_maxNum = b % 10;
	while (b_chushu != 0)
	{
		b_weishu += 1;
		b_maxNum = b_chushu;
		b_chushu = b_chushu / 10;
	}

	//cout <<"a num is "<<a<< " a_max " << a_maxNum << " a_ws " << a_weishu << " and b num is " << b << " b_max" << b_maxNum << " b_ws " << b_weishu << endl;

	if (a_maxNum<b_maxNum) return true;
	else if (a_maxNum>b_maxNum) return false;
	else if (a_maxNum == b_maxNum)
	{
		if (b_weishu>a_weishu)
		{
			int cha = b_weishu - a_weishu;
			int a_num = a * pow(10, cha);
			int a_res = 0;
			while (cha>0)
			{
				a_res += a_maxNum * pow(10, cha - 1);
				cha--;
			}
			a_num += a_res;
			//cout << "a " << a_num << " b " << b << endl;
			if (a_num<b || a_num == b) return true;
			else return false;
		}
		else if (b_weishu == a_weishu)
		{
			if (a<b || a == b) return true;
			else return false;
		}
		else
		{
			int cha = a_weishu - b_weishu;
			int b_num = b * pow(10, cha);
			int b_res = 0;
			while (cha>0)
			{
				b_res += b_maxNum * pow(10, cha - 1);
				cha--;
			}
			b_num += b_res;
			//cout << "a " << a << " b " << b_num << endl;
			if (a<b_num || a == b_num) return true;
			else return false;
		}
	}
}

static bool cmp_2(int a, int b)
{
	if (cmp(a, b)) return false;
	else return true;
}

string PrintMinNumber(vector<int> numbers) {
	sort(numbers.begin(), numbers.end(), cmp);
	string whole = "";
	for (auto & num : numbers)
	{	
		cout << num << endl;
		whole += to_string(num);
	}
	cout << whole << endl;
	return whole;
}


int main()
{	
	vector<int> numbers;
	numbers.push_back(3);
	numbers.push_back(32);
	numbers.push_back(321);
	PrintMinNumber(numbers);

	system("PAUSE");
	return 0;
}
