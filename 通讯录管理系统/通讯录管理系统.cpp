#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 1000 //最大人数

typedef struct {
	string m_Name; //姓名
	string m_Sex;
	int m_Age; //年龄
	string m_Phone; //电话
	string m_Addr; //住址
}Person;

//菜单界面
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

void addPerson(vector<Person>& records) {
	// 检查通讯录是不是满了
	if (records.size() == MAX) {
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	Person newPerson;
	// Get name.
	cout << "请输入姓名：" << endl;
	string name;
	cin >> name;
	newPerson.m_Name = name;
	// Get gender.
	int gender = 0;
	while (true) {
		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		cin >> gender;

		if (gender == 1 || gender == 2) {
			newPerson.m_Sex = (gender == 1) ? "Male" : "Female";
			break;
		}
		else {
			cout << "输入有误，请重新输入";
		}
	}
	//年龄
	cout << "请输入年龄：" << endl;
	int age = 0;
	cin >> age;
	newPerson.m_Age = age;
	//联系电话
	cout << "请输入联系电话：" << endl;
	string phone = "";
	cin >> phone;
	newPerson.m_Phone = phone;
	//家庭住址
	cout << "请输入家庭住址：" << endl;
	string address;
	cin >> address;
	newPerson.m_Addr = address;

	records.push_back(newPerson);
	cout << "添加成功" << endl;
	system("pause");
	// 清除命令行里的输出。
	system("cls");
}

void showPerson(vector<Person>& records) {
	if (records.size() == 0) {
		cout << "当前记录为空" << endl;
		return;
	}
	else {
		for (auto person : records) {
			cout << "姓名：" << person.m_Name << "\t";
			cout << "性别：" << person.m_Sex << "\t";
			cout << "年龄：" << person.m_Age << "\t";
			cout << "电话号码：" << person.m_Phone << "\t";
			cout << "住址：" << person.m_Addr << "\n";
		}
	}
	system("pause");
	system("cls");
}

void deletePerson(vector<Person>& records) {
	string toDelete;
	cout << "请输入您要删除的联系人" << endl;
	cin >> toDelete;
	auto foundPerson = find_if(records.begin(), records.end(), [&](Person person) {
		return person.m_Name == toDelete;
		});
	if (foundPerson != records.end()) {
		records.erase(foundPerson);
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(vector<Person>& records) {
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	auto foundPerson = find_if(records.begin(), records.end(), [&](Person person) {
		return person.m_Name == name;
		});
	if (foundPerson != records.end()) {
		cout << "查到了" << endl;
		cout << "姓名：" << (*foundPerson).m_Name << "\t";
		cout << "性别：" << (*foundPerson).m_Sex << "\t";
		cout << "年龄：" << (*foundPerson).m_Age << "\t";
		cout << "电话：" << (*foundPerson).m_Phone << "\t";
		cout << "住址：" << (*foundPerson).m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void editPerson(vector<Person>& records) {
	cout << "你想要修改谁的信息" << endl;
	string name;
	cin >> name;
	auto foundPerson = find_if(records.begin(), records.end(), [&](Person person) {
		return person.m_Name == name;
		});
	if (foundPerson != records.end()) {
		cout << "请输入新姓名：" << endl;
		string name;
		cin >> name;
		(*foundPerson).m_Name = name;
		int gender = 0;
		while (true) {
			cout << "请输入性别：" << endl;
			cout << "1 -- 男" << endl;
			cout << "2 -- 女" << endl;
			cin >> gender;

			if (gender == 1 || gender == 2) {
				(*foundPerson).m_Sex = (gender == 1) ? "Male" : "Female";
				break;
			}
			else {
				cout << "输入有误，请重新输入";
			}
		}
		//联系电话
		cout << "请输入新的联系电话：" << endl;
		string phone = "";
		cin >> phone;
		(*foundPerson).m_Phone = phone;
		cout << "请输入新的家庭住址：" << endl;
		string address;
		cin >> address;
		(*foundPerson).m_Addr = address;
		cout << "修改成功" << endl;
		system("pause");
		// 清除命令行里的输出。
		system("cls");
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void clearRecords(vector<Person>& records) {
	cout << "你确定要清空联系人？" << endl;
	cout << "回复“1”确定" << endl;
	int answer = 0;
	cin >> answer;
	if (answer == 1) {
		records.clear();
		cout << "清楚成功" << endl;
	}
	else {
		cout << "清除失败" << endl;
	}
	system("pause");
	system("cls");
}

int main() {

	vector<Person> records;

	while (true) {
		showMenu();

		int select;
		cin >> select;

		switch (select)
		{
		case 1:  //添加联系人
			addPerson(records);
			break;
		case 2:  //显示联系人
			showPerson(records);
			break;
		case 3:  //删除联系人
			deletePerson(records);
			break;
		case 4:  //查找联系人
			findPerson(records);
			break;
		case 5:  //修改联系人
			editPerson(records);
			break;
		case 6:  //清空联系人
			clearRecords(records);
			break;
		case 0:  //退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}

	return 0;
}