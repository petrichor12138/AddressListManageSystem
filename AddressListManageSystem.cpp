#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

struct Person
{
    string p_name;
    int p_gender;
    int p_age;
    string p_phone;
    string p_addr;
};

struct AddressBook
{
    struct Person personArray[MAX];

    int size;
};

void show_menu()
{
    cout << "----------------------------" << endl;
    cout << "------- 1. 添加联系人--------" << endl;
    cout << "------- 2. 显示联系人--------" << endl;
    cout << "------- 3. 删除联系人--------" << endl;
    cout << "------- 4. 查找联系人--------" << endl;
    cout << "------- 5. 修改联系人--------" << endl;
    cout << "------- 6. 清空联系人--------" << endl;
    cout << "------- 0. 退出系统 --------" << endl;
    cout << "----------------------------" << endl;
}

void add_person(AddressBook *adb)
{
    if (adb->size >= MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }
    else
    {
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        adb->personArray[adb->size].p_name = name;

        int gender = 0;
        cout << "请输入性别：" << endl;
        cout << "1. 男性" << endl;
        cout << "2. 女性" << endl;
        while (true)
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                adb->personArray[adb->size].p_gender = gender;
                break;
            }
            else
            {
                cout<<"您的输入有误，请重新输入"<<endl;
            }
        }

        cout<<"请输入年龄："<<endl;
        int age=0;
        cin>>age;
        adb->personArray[adb->size].p_age=age;

        cout<<"请输入电话号码："<<endl;
        string phone;
        cin>>phone;
        adb->personArray[adb->size].p_phone=phone;

        cout<<"请输入家庭地址："<<endl;
        string addr;
        cin>>addr;
        adb->personArray[adb->size].p_addr=addr;

        ++adb->size;

        cout<<"添加成功！"<<endl;
        system("pause");//按任意键继续
        system("cls");
        
    }
}

string show_gender(int gender)
{
    return gender==1?"男性":"女性";
}

void show(AddressBook* adb)
{
    if(adb->size==0)
        cout<<"通讯录为空！"<<endl;
    for(int i=0;i<adb->size;++i)
    {
        cout<<"姓名："<<adb->personArray[i].p_name<<"\t"
            <<"性别："<<show_gender(adb->personArray[i].p_gender)<<"\t"
            <<"年龄："<<adb->personArray[i].p_age<<"\t"
            <<"电话号码："<<adb->personArray[i].p_phone<<"\t"
            <<"家庭住址："<<adb->personArray[i].p_addr<<endl;
    }
}

void del_person(AddressBook* adb)
{
    cout<<"请输入您想删除的联系人姓名："<<endl;

    string name;
    cin>>name;

    int index = -1;
    for(int i=0;i<adb->size;++i)
    {
        if(adb->personArray[i].p_name==name)
        {
            index = i;
        }
    }
    if(index==-1)
        cout<<"抱歉！查无此人！"<<endl;
    else
    {
        int choice=0;
        cout<<"此人信息为："<<endl;
        cout<<"姓名："<<adb->personArray[index].p_name<<"\t"
            <<"性别："<<show_gender(adb->personArray[index].p_gender)<<"\t"
            <<"年龄："<<adb->personArray[index].p_age<<"\t"
            <<"电话号码："<<adb->personArray[index].p_phone<<"\t"
            <<"家庭住址："<<adb->personArray[index].p_addr<<endl;
        cout<<"是否确认删除此人?"<<endl;
        cout<<"1. 确认"<<endl;
        cout<<"2. 取消"<<endl;
        cin>>choice;
        if(choice==1)
        {
            for(int i=index;i<adb->size;++i)
            {
                adb->personArray[i]=adb->personArray[i+1];
            }
            --adb->size;
            cout<<"删除成功！"<<endl;
        }
        else
        {
            return;
        }
    }
}

void find_p(AddressBook* adb)
{  
    cout<<"请输入您想查找的联系人姓名："<<endl;

    string name;
    cin>>name;

    int index = -1;
    for(int i=0;i<adb->size;++i)
    {
        if(adb->personArray[i].p_name==name)
        {
            index = i;
        }
    }
    if(index==-1)
        cout<<"抱歉！查无此人！"<<endl;
    else
    {
        cout<<"姓名："<<adb->personArray[index].p_name<<"\t"
            <<"性别："<<show_gender(adb->personArray[index].p_gender)<<"\t"
            <<"年龄："<<adb->personArray[index].p_age<<"\t"
            <<"电话号码："<<adb->personArray[index].p_phone<<"\t"
            <<"家庭住址："<<adb->personArray[index].p_addr<<endl;
    }

}

void modify_p(AddressBook* adb)
{
    cout<<"请输入您想修改的联系人姓名："<<endl;

    string name;
    cin>>name;

    int index = -1;
    for(int i=0;i<adb->size;++i)
    {
        if(adb->personArray[i].p_name==name)
        {
            index = i;
        }
    }
    if(index==-1)
        cout<<"抱歉！查无此人！"<<endl;
    else
    {
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        adb->personArray[index].p_name = name;

        int gender = 0;
        cout << "请输入性别：" << endl;
        cout << "1. 男性" << endl;
        cout << "2. 女性" << endl;
        while (true)
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                adb->personArray[index].p_gender = gender;
                break;
            }
            else
            {
                cout<<"您的输入有误，请重新输入"<<endl;
            }
        }

        cout<<"请输入年龄："<<endl;
        int age=0;
        cin>>age;
        adb->personArray[index].p_age=age;

        cout<<"请输入电话号码："<<endl;
        string phone;
        cin>>phone;
        adb->personArray[index].p_phone=phone;

        cout<<"请输入家庭地址："<<endl;
        string addr;
        cin>>addr;
        adb->personArray[index].p_addr=addr;

        cout<<"修改成功！"<<endl;
    }
}

void clear_p(AddressBook* adb)
{
    adb->size=0;
    cout<<"通讯录已清空"<<endl;
}

void exit_sys()
{
    cout << "欢迎下次使用该系统" << endl;
    system("pause");
}

int main()
{
    AddressBook adb;

    adb.size = 0;

    int choice = -1;
    while (true)
    {
        show_menu();

        cin >> choice;

        switch (choice)
        {
        case 0:
            exit_sys();
            return 0;
            break;
        case 1:
            add_person(&adb);
            break;
        case 2:
            show(&adb);
            break;
        case 3:
            del_person(&adb);
            /* code */
            break;
        case 4:
            find_p(&adb);
            /* code */
            break;
        case 5:
            modify_p(&adb);
            /* code */
            break;
        case 6:
            clear_p(&adb);
            /* code */
            break;
        default:
            exit_sys();
            return 0;
            break;
        }
    }
}