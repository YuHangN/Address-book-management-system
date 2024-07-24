#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 1000 //�������

typedef struct {
	string m_Name; //����
	string m_Sex;
	int m_Age; //����
	string m_Phone; //�绰
	string m_Addr; //סַ
}Person;

//�˵�����
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

void addPerson(vector<Person>& records) {
	// ���ͨѶ¼�ǲ�������
	if (records.size() == MAX) {
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	Person newPerson;
	// Get name.
	cout << "������������" << endl;
	string name;
	cin >> name;
	newPerson.m_Name = name;
	// Get gender.
	int gender = 0;
	while (true) {
		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		cin >> gender;

		if (gender == 1 || gender == 2) {
			newPerson.m_Sex = (gender == 1) ? "Male" : "Female";
			break;
		}
		else {
			cout << "������������������";
		}
	}
	//����
	cout << "���������䣺" << endl;
	int age = 0;
	cin >> age;
	newPerson.m_Age = age;
	//��ϵ�绰
	cout << "��������ϵ�绰��" << endl;
	string phone = "";
	cin >> phone;
	newPerson.m_Phone = phone;
	//��ͥסַ
	cout << "�������ͥסַ��" << endl;
	string address;
	cin >> address;
	newPerson.m_Addr = address;

	records.push_back(newPerson);
	cout << "��ӳɹ�" << endl;
	system("pause");
	// �����������������
	system("cls");
}

void showPerson(vector<Person>& records) {
	if (records.size() == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
		return;
	}
	else {
		for (auto person : records) {
			cout << "������" << person.m_Name << "\t";
			cout << "�Ա�" << person.m_Sex << "\t";
			cout << "���䣺" << person.m_Age << "\t";
			cout << "�绰���룺" << person.m_Phone << "\t";
			cout << "סַ��" << person.m_Addr << "\n";
		}
	}
	system("pause");
	system("cls");
}

void deletePerson(vector<Person>& records) {
	string toDelete;
	cout << "��������Ҫɾ������ϵ��" << endl;
	cin >> toDelete;
	auto foundPerson = find_if(records.begin(), records.end(), [&](Person person) {
		return person.m_Name == toDelete;
		});
	if (foundPerson != records.end()) {
		records.erase(foundPerson);
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(vector<Person>& records) {
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	auto foundPerson = find_if(records.begin(), records.end(), [&](Person person) {
		return person.m_Name == name;
		});
	if (foundPerson != records.end()) {
		cout << "�鵽��" << endl;
		cout << "������" << (*foundPerson).m_Name << "\t";
		cout << "�Ա�" << (*foundPerson).m_Sex << "\t";
		cout << "���䣺" << (*foundPerson).m_Age << "\t";
		cout << "�绰��" << (*foundPerson).m_Phone << "\t";
		cout << "סַ��" << (*foundPerson).m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void editPerson(vector<Person>& records) {
	cout << "����Ҫ�޸�˭����Ϣ" << endl;
	string name;
	cin >> name;
	auto foundPerson = find_if(records.begin(), records.end(), [&](Person person) {
		return person.m_Name == name;
		});
	if (foundPerson != records.end()) {
		cout << "��������������" << endl;
		string name;
		cin >> name;
		(*foundPerson).m_Name = name;
		int gender = 0;
		while (true) {
			cout << "�������Ա�" << endl;
			cout << "1 -- ��" << endl;
			cout << "2 -- Ů" << endl;
			cin >> gender;

			if (gender == 1 || gender == 2) {
				(*foundPerson).m_Sex = (gender == 1) ? "Male" : "Female";
				break;
			}
			else {
				cout << "������������������";
			}
		}
		//��ϵ�绰
		cout << "�������µ���ϵ�绰��" << endl;
		string phone = "";
		cin >> phone;
		(*foundPerson).m_Phone = phone;
		cout << "�������µļ�ͥסַ��" << endl;
		string address;
		cin >> address;
		(*foundPerson).m_Addr = address;
		cout << "�޸ĳɹ�" << endl;
		system("pause");
		// �����������������
		system("cls");
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void clearRecords(vector<Person>& records) {
	cout << "��ȷ��Ҫ�����ϵ�ˣ�" << endl;
	cout << "�ظ���1��ȷ��" << endl;
	int answer = 0;
	cin >> answer;
	if (answer == 1) {
		records.clear();
		cout << "����ɹ�" << endl;
	}
	else {
		cout << "���ʧ��" << endl;
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
		case 1:  //�����ϵ��
			addPerson(records);
			break;
		case 2:  //��ʾ��ϵ��
			showPerson(records);
			break;
		case 3:  //ɾ����ϵ��
			deletePerson(records);
			break;
		case 4:  //������ϵ��
			findPerson(records);
			break;
		case 5:  //�޸���ϵ��
			editPerson(records);
			break;
		case 6:  //�����ϵ��
			clearRecords(records);
			break;
		case 0:  //�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}

	return 0;
}