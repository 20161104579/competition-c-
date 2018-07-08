#include "head.h"

void Copy2(Judges* J)
{
	int i;
	ofstream file(fileName, ios::out);
	if (!file)
	{
		cout << "\t  �ļ���ʧ�ܣ�" << endl;
	}
	else
	{
		for (i = 0; i < J->last; i++)
		{
			file << J->elem[i].name << ","<< J->elem[i].sex << ","<< J->elem[i].phone << "\n";
		}
	}
}

void Load2(Judges* J)
{
	string str;
	int i = 1, j = 0, s = 0;
	ifstream file(fileName, ios::in);
	while (getline(file, str)) {
		istringstream sin(str);
		vector<string>fields;
		string field;
		while (getline(sin, field, ',')) {
			fields.push_back(field);
		}
		J->elem[s].name = Trim(fields[0]);
		J->elem[s].sex = Trim(fields[1]);
		J->elem[s].phone = Trim(fields[2]);
		s++;
	}
	J->last = s;
}

void UI2()
{
	printf("\t\t\t|-----------------�˵�-----------------|\n");
	printf("\t\t\t|------------1.�����ί��Ϣ------------|\n");
	printf("\t\t\t|------------2.��ʾȫ����ί��Ϣ--------|\n");
	printf("\t\t\t|------------3.��ί��Ϣ��ѯ------------|\n");
	printf("\t\t\t|------------0.�˳���ί��Ϣϵͳ--------|\n");
}

void menu2(Judges* J)
{
	UI2();
	//	load2(J);//�����ļ�����ί����
	int i, have = 1;
	printf("ѡ��Ҫ���еĹ��ܣ�");
	while (cin>>i)
	{
		have = 1;
		switch (i)
		{
		case 1: add(J); break;
		case 2: Show(J); break;
		case 3: Query2(J); break;
		case 0: have = 0; break;
		}
		Copy2(J);
		if (have == 0) {
			cout << "\t  ������Ϣ����ɹ���" << endl;
			break;

		}
		printf("ѡ��Ҫ���еĹ��ܣ�");
	}
}

void add(Judges* J)
{
	int i;
	i = J->last;
	printf("\t  ������ί���ϵͳ��\n");
	printf("\t  ������ί���֣�");
	cin>>J->elem[i].name;
	printf("\t  ������ί�Ա�");
	cin>>J->elem[i].sex;
	printf("\t  ������ί�绰��");
	cin>>J->elem[i].phone;
	J->last++;
	cout << "\t  �����ί��Ϣ�ɹ���" << endl;
}

void Show(Judges* J)
{
	printf("������ʾȫ����ί��Ϣϵͳ��\n");
	int i;
	printf("\t\t|      ����      | �Ա� |        �绰����        |\n");
	for (i = 0; i < J->last; i++)
	{
		cout << "\t\t|" << setw(16) << setfill(' ') << right << J->elem[i].name;
		cout << "|" << setw(6) << setfill(' ') << right << J->elem[i].sex;
		cout << "|" << setw(24) << setfill(' ') << right << J->elem[i].phone << "|" << endl;
		//cout<<"\t\t|     "<<J->elem[i].name<<"     |  "<<J->elem[i].sex<<"  |       "<<J->elem[i].phone<<"       |\n";
	}

}

int Find2(Judges* J)//���Һ������ҵ������±꣬�Ҳ�������-1
{
	string Name;
	cout << "\t  ������Ҫ���ҵ���ί���֣�";
	cin >> Name;
	int i = 0;
	while ((i < J->last) && !(J->elem[i].name == Name)) {
		i++;
	}
	if (i < J->last)
		return i;
	else
		return -1;
}

void Query2(Judges* J)
{
	cout << "\t  �ѽ�����ί��Ϣ����ϵͳ"<<endl;
	int i;
	i = Find2(J);
	if (i != -1) {
		cout << "�ҵ���" << J->elem[i].name << "��ί����Ϣ��" << endl;
		printf("\t\t|      ����      | �Ա� |        �绰����        |\n");
		cout << "\t\t|" << setw(16) << setfill(' ') << right << J->elem[i].name;
		cout << "|" << setw(6) << setfill(' ') << right << J->elem[i].sex;
		cout << "|" << setw(24) << setfill(' ') << right << J->elem[i].phone << "|" << endl;
	}
	else
		cout << "\t  ��Ǹ��û�д�����Ϣ��" << endl;

}

void Load1(Seqlist* L)
{
	string str;
	int i = 1, j = 0, s = 0;
	string scores;
	ifstream file(fileNames, ios::in);
	while (getline(file, str)) {
		istringstream sin(str);
		vector<string>fields;
		string field;
		while (getline(sin, field, ',')) {
			fields.push_back(field);
		}
		L->elem[s].player_name = Trim(fields[0]);
		L->elem[s].sex = Trim(fields[1]);
		L->elem[s].classroom = Trim(fields[2]);
		L->elem[s].phone = Trim(fields[2]);
		L->elem[s].show_name = Trim(fields[2]);
		L->elem[s].category = Trim(fields[2]);
		scores = Trim(fields[2]);
		L->elem[s].score = atof(scores.c_str());
		s++;
	}
	L->last = s;
}
string doubleTranStr(double integer) {
	stringstream ss;
	ss << integer;
	return ss.str();
}
void Copy1(Seqlist* L)
{
	int i;
	string Score;
	ofstream file(fileNames, ios::out);
	if (!file)
	{
		cout << "\t  �ļ���ʧ�ܣ�" << endl;
	}
	else
	{
		for (i = 0; i < L->last; i++)
		{
			Score = doubleTranStr(L->elem[i].score);
			file << L->elem[i].player_name << "," << L->elem[i].sex << "," << L->elem[i].classroom<<","<< L->elem[i].phone << ","<< L->elem[i].show_name << ","<< L->elem[i].category << "\n";
		}
	}
}


void UI1()
{
	cout<<"\t\t\t|-----------------�˵�-----------------|"<<endl;
	cout<<"\t\t\t|------------1.���ѡ����Ϣ------------|"<<endl;
	cout<<"\t\t\t|------------2.ɾ��ѡ����Ϣ------------|"<<endl;
	cout<<"\t\t\t|------------3.���ܳɼ�����------------|"<<endl;
	cout<<"\t\t\t|------------4.�ɼ���ѯ----------------|"<<endl;
	cout<<"\t\t\t|------------5.�޸�ѡ����Ϣ------------|"<<endl;
	cout<<"\t\t\t|------------6.��ʾȫ��ѡ����Ϣ--------|"<<endl;
	cout<<"\t\t\t|------------7.��ѡ�ֽ��д��----------|"<<endl;
	cout<<"\t\t\t|------------0.�˳�ѡ����Ϣϵͳ--------|"<<endl;
}

void menu1(Seqlist* L, Judges* J)
{
	UI1();
	int i, have = 1;
	cout << "ѡ��Ҫ���еĹ��ܣ�";
	while (cin>>i)
	{
		switch (i)
		{
			case 1:Add(L); break;
			case 2:Del(L); break;
			case 3:Sort(L); break;
			case 4:Query1(L); break;
			case 5:Change(L); break;
			case 6:Show1(L); break;
			case 7:Grade(L, J); break;
			case 0:have = 0; break;
		}
		Copy1(L);
		if (have == 0)
			break;
		cout << "ѡ��Ҫ���еĹ��ܣ�" ;
	}
//	copy(L);
}

void Add(Seqlist* L)
{
	cout << "����ѡ����Ϣ���ϵͳ��" << endl;
	int i = L->last;
	cout << "\t  ѡ��������";
	cin >> L->elem[i].player_name;
	cout << "\t  ѡ���Ա�";
	cin >> L->elem[i].sex;
	cout << "\t  ���ڰ༶��";
	cin >> L->elem[i].classroom;
	cout << "\t  ��Ŀ���ͣ�";
	cin >> L->elem[i].category;
	cout << "\t  ��Ŀ���ƣ�";
	cin >> L->elem[i].show_name;
	cout << "\t  ѡ�ֵ绰�ţ�";
	cin >> L->elem[i].phone;
	L->elem[i].score = -1;
	L->last++;
	cout << "\t  ѡ����Ϣ��ӳɹ���"<<endl;
}

int Find2(Seqlist* L)
{
	cout << "\t  ѡ��Ҫ���ҵķ�ʽ��";
	cout << "1.���ֲ��ң�2.�绰�źŲ��ң�3.��Ŀ���ֲ���\n";
	int have, i=0;
	string name, names, phones;
	cin >> have;
	switch (have)
	{
		case 1: {
			cout << "\t  �������֣�";
			cin >> name;
			while((i<L->last)&&(!(name==L->elem[i].player_name)))
				i++;
		}
				break;
		case 2: {
			cout << "\t  ����绰��";
			cin >> phones;
			while ((i<L->last) && (!(phones == L->elem[i].phone)))
				i++;
		}
				break;
		case 3: {
			cout << "\t  �����Ŀ���֣�";
			cin >> names;
			while ((i<L->last) && (!(names == L->elem[i].show_name)))
				i++;
		}
				break;
	}
	if (i < L->last)
		return i;
	else
		return -1;
}

void Del(Seqlist* L)
{
	cout<<"�ѽ���ѡ����Ϣɾ��ϵͳ\n";
	int s, i;
	s = Find2(L);
	if (s == -1)
		cout<<"δ�ҵ�ѡ����Ϣ��\n";
	else
	{
		cout << "\t  Ҫɾ����ѡ����Ϣ�ǣ�" << endl;
		cout << "\t\t|   ����   | �Ա� |  �༶��Ϣ  |  ��Ŀ����  |   ��Ŀ����   |	�绰��	| �ɼ� |" << endl;
		cout << "\t\t|" << setw(10) << setfill(' ') << right << L->elem[s].player_name;
		cout << "|" << setw(6) << setfill(' ') << right << L->elem[s].sex;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[s].classroom;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[s].category;
		cout << "|" << setw(14) << setfill(' ') << right << L->elem[s].show_name;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[s].phone;
		cout << "|" << setw(6) << setfill(' ') << right << L->elem[s].score << "|" << endl;
		for (i = s; i<L->last; i++)
			L->elem[i] = L->elem[i + 1];
		L->last--;
		cout<<"\tɾ���ɹ�\n";
	}
}

void Query1(Seqlist* L)
{
	cout << "\t  ����ѡ����Ϣ��ѯϵͳ��" << endl;
	int s = Find2(L);
	if (s == -1)
		cout << "δ�ҵ�ѡ����Ϣ��" << endl;
	else
	{
		cout << "\t  �ҵ���" << L->elem[s].player_name << "ѡ�֡�" << endl;
		cout << "\t\t|   ����   | �Ա� |  �༶��Ϣ  |  ��Ŀ����  |   ��Ŀ����   |	�绰��	| �ɼ� |" << endl;
		cout << "\t\t|" << setw(10) << setfill(' ') << right << L->elem[s].player_name;
		cout << "|" << setw(6) << setfill(' ') << right << L->elem[s].sex;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[s].classroom;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[s].category;
		cout << "|" << setw(14) << setfill(' ') << right << L->elem[s].show_name;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[s].phone;
		cout << "|" << setw(6) << setfill(' ') << right << L->elem[s].score << "|" << endl;
	}
}

void Change(Seqlist* L)
{
	cout << "\t  ����ѡ����Ϣ�޸�ϵͳ" << endl;
	int s = Find2(L);
	int have;
	if (s == -1)
		cout << "δ�ҵ�ѡ����Ϣ��" << endl;
	else
	{
		cout << "\t  �����޸�" << L->elem[s].player_name << "ѡ����Ϣ��" << endl;
		cout << "\t  ѡ��Ҫ�޸ĵ���Ϣ��1.�޸Ľ�Ŀ���� 2.�޸Ľ�Ŀ���� 3.�޸İ༶��Ϣ 4.�޸ĵ绰����" << endl;
		cin >> have;
		switch (have)
		{
			case 1:cin >> L->elem[s].show_name; break;
			case 2:cin >> L->elem[s].category; break;
			case 3:cin >> L->elem[s].classroom; break;
			case 4:cin >> L->elem[s].phone; break;
		}
		cout << "\t  �޸���ɣ�����ϢΪ��" << endl;
		cout << "\t\t|   ����   | �Ա� |  �༶��Ϣ  |  ��Ŀ����  |   ��Ŀ����   |	�绰��	| �ɼ� |" << endl;
		cout << "\t\t|" << setw(10) << setfill(' ') << right << L->elem[s].player_name;
		cout << "|" << setw(6) << setfill(' ') << right << L->elem[s].sex;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[s].classroom;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[s].category;
		cout << "|" << setw(14) << setfill(' ') << right << L->elem[s].show_name;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[s].phone;
		cout << "|" << setw(6) << setfill(' ') << right << L->elem[s].score << "|" << endl;
	}
}

void Grade(Seqlist* L, Judges* J)
{
	int s, i, min, max;
	double sum = 0.0;
	int score[100];
	int num;//��ί��
	int people = J->last;
	cout << people;
	num = J->last;

	s = Find2(L);
	if (s == -1)
		printf("δ�ҵ�ѡ����Ϣ��\n");
	else
	{
		cout << "������" << L->elem[s].player_name << "ѡ�ֽ��д�֡�\n������ί��ֳɼ�����" << num << "����ί��" << endl;
		for (i = 0; i<J->last; i++)
		{
			cout << J->elem[i].name << "��ί�����ķ����ǣ�";
			cin>>score[i];
			sum += score[i];
		}
		min = score[0];
		max = score[0];
		for (i = 0; i<J->last; i++)
		{
			if (score[i]<min)
				min = score[i];
			if (score[i]>max)
				max = score[i];
		}
		if (num > 2)
		{
			sum = sum - max;
			sum = sum - min;
			people -= 2;
		}
		sum = sum / people;
		L->elem[s].score = sum;
		cout << "������ĵ÷��ǣ�" << sum << ",���ķ�����������������Ϣ�С�������\n";
	}
}

void Show1(Seqlist* L)
{
	cout << "�ѽ���ѡ����Ϣ��ʾϵͳ��������ʾȫ��ѡ�ֵ���Ϣ��" << endl;
	int i;
	cout << "\t\t|   ����   | �Ա� |  �༶��Ϣ  |  ��Ŀ����  |   ��Ŀ����   |	�绰��	| �ɼ� |" << endl;
	for (i = 0; i < L->last; i++)
	{
		cout << "\t\t|" << setw(10) << setfill(' ') << right << L->elem[i].player_name;
		cout << "|" << setw(6) << setfill(' ') << right << L->elem[i].sex;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[i].classroom;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[i].category;
		cout << "|" << setw(14) << setfill(' ') << right << L->elem[i].show_name;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[i].phone;
		cout << "|" << setw(6) << setfill(' ') << right << L->elem[i].score<<"|"<<endl;
	}
}

void quicksort_min(Seqlist* L, int left, int right)
{
	NodePlayer t, temp;
	int i, j;

	if (left>right)
		return;
	temp = L->elem[left];
	j = right;
	i = left;

	while (i != j)
	{
		while (L->elem[j].score >= temp.score && i<j)
			j--;
		while (L->elem[i].score <= temp.score&& i<j)
			i++;
		if (i<j)
		{
			t = L->elem[j];
			L->elem[j] = L->elem[i];
			L->elem[i] = t;
		}
	}

	L->elem[left] = L->elem[i];
	L->elem[i] = temp;

	quicksort_min(L, left, i - 1);
	quicksort_min(L, i + 1, right);
}

void quicksort_max(Seqlist* L, int left, int right)
{
	NodePlayer t, temp;
	int i, j;

	if (left>right)
		return;
	temp = L->elem[left];
	j = right;
	i = left;

	while (i != j)
	{
		while (L->elem[j].score <= temp.score && i<j)
			j--;
		while (L->elem[i].score >= temp.score&& i<j)
			i++;
		if (i<j)
		{
			t = L->elem[j];
			L->elem[j] = L->elem[i];
			L->elem[i] = t;
		}
	}

	L->elem[left] = L->elem[i];
	L->elem[i] = temp;

	quicksort_max(L, left, i - 1);
	quicksort_max(L, i + 1, right);
}

void Sort(Seqlist* L)
{
	int have;
	printf("\t  �����Զ�����ϵͳ");
	cout << "\t  ѡ������������1.��С����2.�Ӵ�С" << endl;
	cin >> have;
	if(have==1)
		quicksort_min(L, 0, L->last - 1);
	else
		quicksort_max(L, 0, L->last - 1);
	printf("������ɣ�\n");
	Show1(L);
}

void UI()
{
	printf("\t\t\t|-----------------�˵�-----------------|\n");
	printf("\t\t\t|------------1.����ѡ����Ϣϵͳ--------|\n");
	printf("\t\t\t|------------2.������ί��Ϣϵͳ--------|\n");
	printf("\t\t\t|------------0.�˳�ϵͳ----------------|\n");
}

string Trim(string& str)
{
	str.erase(0, str.find_first_not_of("\t\r\n"));
	str.erase(str.find_last_not_of("\t\r\n") + 1);
	return str;
}

void Menu(Seqlist* L, Judges* J)
{
	UI();//���ز˵�
	int i, have = 1;
	Load2(J);
	Load1(L);
	printf("ѡ��Ҫ���еĹ��ܣ�");
	while (cin>>i)
	{
		switch (i)
		{
		case 1: menu1(L, J); break;
		case 2: menu2(J); break;
		case 0: have = 0; break;
		}
		if (have == 0)
			break;
		UI();//���ز˵�
		printf("ѡ��Ҫ���еĹ��ܣ�");
	}
}
