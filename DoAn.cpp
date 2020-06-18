#include <bits/stdc++.h>
#include <fstream>
using namespace std;
// Định nghĩa danh sách liên kết đơn
struct LinkedList
{
	int data;
	struct LinkedList *next;
};
typedef LinkedList *node;
// Khởi tạo Node mới trong danh sách
node Khoitao(int data)
{
	node temp;
	temp = new LinkedList;
	temp->next = NULL;
	temp->data = data;
	return temp;
}
// Thêm dữ liệu vào đầu danh sách (Hỗ trợ cho hàm ThemVao)
node ThemDau(node head, int data)
{
	node temp = Khoitao(data);
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
	return head;
}
// Thêm dữ liệu vào cuối danh sách (Hỗ trợ cho hàm ThemVao)
node ThemCuoi(node head, int data)
{
	node temp, p;
	temp = Khoitao(data);
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = temp;
	}
	return head;
}
// Sử dụng 2 hàm hỗ trợ, thêm dữ liệu vào danh sách ở vị trí bất kì
node ThemVao(node head, int data, int vitri)
{
	if (vitri == 1 || head == NULL)
	{
		head = ThemDau(head, data);
	}
	else
	{
		int find = 2;
		node p = head;
		while (p != NULL && find != vitri)
		{
			p = p->next;
			++find;
		}

		if (find != vitri)
		{
			head = ThemCuoi(head, data);
		}
		else
		{
			node temp = Khoitao(data);
			temp->next = p->next;
			p->next = temp;
		}
	}
	return head;
}
// Xóa dữ liệu ở đầu danh sách (Hỗ trợ cho hàm Xoa)
node XoaDau(node head)
{
	if (head != NULL)
	{
		head = head->next;
	}
	return head;
}
// Xóa dữ liệu ở cuối danh sách (Hỗ trợ cho hàm Xoa)
node XoaCuoi(node head)
{
	node p = head;
	if (p == NULL || p->next == NULL)
		return NULL;
	else
	{
		while (p->next->next != NULL)
		{
			p = p->next;
		}
		p->next = p->next->next;
	}
	return head;
}
// Sử dụng 2 hàm hỗ trợ, xóa dữ liệu tại vị trí bất kì
node Xoa(node head, int vitri)
{
	if (vitri == 1 || head == NULL)
	{
		head = XoaDau(head);
	}
	else
	{
		int find = 1;
		node p = head;
		while (p->next->next != NULL && find != vitri && p->next != NULL)
		{
			p = p->next;
			find++;
		}

		if (find != vitri)
		{
			head = XoaCuoi(head);
		}
		else
		{
			p->next = p->next->next;
		}
	}
	return head;
}
// In ra danh sách cuối cùng
void Print(node head)
{
	for (node p = head; p != NULL; p = p->next)
	{
		cout << p->data << " ";
	}
}
// Chương trình chính
int main()
{
	int n, data, vt, i = 0, L = 0;
	string f;
	char cmd, code;
	node head = NULL;
	system("cls");
	// Menu lựa chọn Input nhập vào
	while (true)
	{
		cout << "Chon loai Input:" << endl;
		cout << "\t1.Input tu File co san" << endl
		cout << "\t2.Input nhap ban phim" << endl
		cout << "\t0.Ket thuc chuong trinh" << endl
		cout << "Chon option:  ";
		cin >> code;
		switch (code)
		{
		// Input từ File có sẵn
		case '1':
		{
			system("cls");
			cout << "Nhap ten file:  ";
			cin >> f;
			char input[100];
		// Khởi tạo đọc File nhiều dòng
			char *line = new char(f.size() + 1);
			for (int i = 0; i < f.size() + 1; i++)
				line[i] = f[i];
		// Khởi tạo đọc File chính, ghi dữ liệu nhiều dòng vào File chính
			fstream File;
			File.open(line, ios::in);
		// Kiểm tra tồn tại File
			if (!File.is_open())
			{
				cout << "Khong the doc file";
			}
			else
			{
				// Xử lí dữ liệu trong File
				File >> input;
				cout << input << endl;
				n = atoi(input); // Xử lí ký tự đầu tiên là n trong file thành dạng nguyên
				for (int i = 1; i <= n; i++)
				{
					File >> input;
					cout << input << endl;
					char key = input[0];
					switch (key)
					{
					case 'I':
					{
						File >> input;
						cout << input << endl;
						// Xử lí sô ở dạng string trong file thành dạng nguyên
						data = atoi(input);
						File >> input;
						cout << input << endl;
						// Xử lí số ở dạng string trong file thành dạng nguyên
						vt = atoi(input);
						if (vt >= 1 && vt <= L + 1)
						{
							head = ThemVao(head, data, vt);
							L++;
						}
						break;
					}
					case 'D':
					{
						File >> input;
						cout << input << endl;
						// Xử lí số ở dạng string trong file thành dạng nguyên
						vt = atoi(input);
						if (vt >= 1 && vt <= L)
						{
							head = Xoa(head, vt);
							L--;
						}
						break;
					}
					default:
					{
						// Trường hợp nhập vào ký tự đầu của thao tác khác "I" và "D"
						cout << "Sai lua chon vui long nhap lai " << endl;
					}
					}
				}
			}
			File.close();
			break;
		}
		// Input nhập từ bàn phím
		case '2':
		{
			system("cls");
			cout << "Nhap so luong thao tac:  ";
			cin >> n;
			while (i < n)
			{
				cout << "Lenh " << i + 1 << ": ";
				cin >> cmd;
				switch (cmd)
				{
				case 'D':
				{
					cin >> vt;
					if (vt >= 1 && vt <= L)
					{
						head = Xoa(head, vt);
						L--;
					}
					i++;
					break;
				}
				case 'I':
				{
					cin >> data >> vt;
					if (vt >= 1 && vt <= L + 1)
					{
						head = ThemVao(head, data, vt);
						L++;
					}
					i++;
					break;
				}
				default:
				{
					// Trường hợp nhập vào sai ký tự đầu của thao tác khác "I" và "D"
					cout << "Sai lua chon vui long nhap lai " << endl;
				}
				}
			}
			break;
		}
		case '0':
			return 0;
			break;
		}
		if ((code == '1') || (code == '2') || (code == '0'))
			break;
	}
	// Nếu không có gì trong danh sách
	if (L < 1)
		cout << "Khong co gi trong danh sach";
	else
	{
		// In ra kết quả cuối cùng
		cout << "Ket qua: ";
		Print(head);
	}
}
