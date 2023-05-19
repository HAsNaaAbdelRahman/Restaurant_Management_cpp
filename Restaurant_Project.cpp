#include <bits/stdc++.h>
using namespace std;

class CustomerSignup
{
public:
    char user_name[10], password[20], areacode[20];
    int phone;
};

class DeliveryBoy
{
public:
    char DeliveryBoyName[50], PhoneNumber[30], AreaCode[20], Login_username[50];
};

class Menue
{
public:
    int id, quantity;
    char type[20];
    double charge;
};
class Discount
{
    // productDiscount
public:
    int Discount_id;
    char start_date[20]; // 20Mar2023
    char end_date[20];
    float Discount_amount;
    int Menue_id;        // here we will connect with the "Menue" class
    char Menue_type[20]; // name will be used to displayed on the file
    double charge;
};
class Order
{
public:
    char type[20];
    double charge;
    int amount;
};
void AddRecord(int n);
void dispalyALLRecord(int n);
void SearchRecord(int n);
void DeleteRecord(int n);
void UpdateRecord(int n);

double Searchcharge(char str[20]);
void encrypt(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] += 6;
    }
}
void decrypt(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] -= 6;
    }
}

void AddRecord(int n)
{
    if (n == 1)
    {
        // Adding new customer in file

        ofstream file;
        file.open("Login.txt", ios::out);
        CustomerSignup c;

        if (file.is_open())
        {
            cout << "Please , Enter Your User Name    : ";
            cin >> c.user_name;
            cout << "Please , Enter Your Password     : ";
            cin >> c.password;
            encrypt(c.password);
            cout << "Please , Enter Your phone number : ";
            cin >> c.phone;
            cout << "Please , Enter Your area code    : ";
            cin >> c.areacode;
            file.write((char *)&c, sizeof(c));
            cout << "\n-----------Welcome :)---------- \n";
            file.close();
        }
        else
        {

            cout << "Sorry , File Not Found\n";
        }
    }
    else if (n == 2)
    {
        // Adding New Record in Delivery Boy
        ofstream f("DeliveryBoy.txt", ios::out | ios::app);
        DeliveryBoy obj;
        if (f.is_open())
        {
            char ch = 'Y';
            do
            {

                cout << "Enter Area Code for Delivery Boy : ";
                cin >> obj.AreaCode;
                cout << "Enter Name for Delivery Boy : ";
                cin >> obj.DeliveryBoyName;
                cout << "Enter Phone Number for Delivery Boy : ";
                cin >> obj.PhoneNumber;
                cout << "Enter username for Delivery Boy : ";
                cin >> obj.Login_username;
                encrypt(obj.Login_username);

                cout << "Enter record agin (Y/N) : ";
                cin >> ch;
                f.write((char *)&obj, sizeof(obj));
            } while (ch == 'Y');
            f.close();
        }
        else
        {
            cout << "Cannot open file :( \n";
        }
    }
    else if (n == 3)
    {
        // Adding New Record in Menue
        ofstream outFile;
        outFile.open("Menue.txt", ios::out | ios::app);
        Menue m;
        if (outFile.is_open())
        {
            char c;
            do
            {
                /* Record data from admin */
                cout << "Enter ID: ";
                cin >> m.id;
                cout << "Enter type: ";
                cin >> m.type;
                cout << "Enter Charge: ";
                cin >> m.charge;
                outFile.write((char *)&m, sizeof(m));
                cout << "enter record again(y/n)?";
                cin >> c;
            } while (c == 'y');
            outFile.close();
        }
        else
        {
            cout << "cannot open the specified file." << endl;
        }
    }
    else if (n == 4)
    {
        // Adding New Record in discounts
        fstream discounts;
        discounts.open("product_discounts.txt", ios::out | ios::app);
        if (discounts.is_open())
        {
            Discount d;
            char c = 'Y';
            while (c == 'Y')
            {
                cout << "  -----Entre discount id-----  " << endl;
                cin >> d.Discount_id;

                cout << "  -----Entre discount start date-----  " << endl;
                cin >> d.start_date;

                cout << "  -----Entre discount End date-----  " << endl;
                cin >> d.end_date;

                cout << "  -----Entre product id-----  " << endl;
                cin >> d.Menue_id;

                cout << "  -----Entre product name-----  " << endl;
                cin >> d.Menue_type;

                cout << "  -----Entre the original price of the product-----  " << endl;
                cin >> d.charge;

                cout << "  -----Entre Amount of Discount-----  " << endl;
                cin >> d.Discount_amount;

                discounts.write((char *)&d, sizeof(d));

                cout << "----------Do You Want to Add a new Discount? (Y/N)----------" << endl;
                cin >> c; // take decision to complete asking for new discounts
            }
            discounts.close();
        }
        else
        {
            cout << "Ooops!...We Cannot access file" << endl;
        }
    }
    else if (n == 5)
    { // order file -> is file to display order of one customer
        // Adding  new Record in Make Order
        dispalyALLRecord(3);
        remove("order.txt");
        fstream f("order.txt", ios::in | ios::out | ios::app);
        if (f.is_open())
        {
            Order order;

            char ok;
            do
            {
                cout << "Enter type of Item you want to buy\n";
                cin >> order.type;

                order.charge = Searchcharge(order.type);
                if (order.charge == -1)
                    cout << "** Item you want to buy not fount :( **\n ";
                else
                {
                    cout << "what is the amount ? \n";
                    cin >> order.amount;
                    f.write((char *)&order, sizeof(order));
                }
                cout << "Another thing ?! :) (y/n) : ";
                cin >> ok;
            } while (ok == 'y');

            f.close();
            dispalyALLRecord(4);
        }
        else
        {
            cout << "cant open file /n";
        }
    }
    else if (n == 6)
    {
        // Adding New Record in my  Order
        dispalyALLRecord(3);

        ofstream out("order.txt", ios::out | ios::app);
        if (out.is_open())
        {
            Order order;

            char ok;
            do
            {
                cout << "Enter type of Item you want to buy\n";
                cin >> order.type;

                order.charge = Searchcharge(order.type);
                if (order.charge == -1)
                    cout << "** Item you want to buy not fount :( **\n ";
                else
                {
                    cout << "what is the amount ? \n";
                    cin >> order.amount;
                    out.write((char *)&order, sizeof(order));
                }
                cout << "Another thing ?! :) (y/n) : ";
                cin >> ok;
            } while (ok == 'y');

            out.close();
            dispalyALLRecord(4);
        }
        else
        {
            cout << "cant open file /n";
        }
    }
    else if (n == 7)
    {
        AddRecord(3);
    }
}
void dispalyALLRecord(int n)
{
    if (n == 1)
    {
        // display for pssword "ADMIN" only
        ifstream in("Login.txt", ios::in);
        if (in.is_open())
        {
            string password;
            cout << "Enter Admin passward : ";
            cin >> password;
            if (password == "ADMIN")
            {
                CustomerSignup s;
                cout << "CustomerName\tpassword\tPhoneNumber\tAreaCode \n ";
                cout << "_________________________________________________________\n";
                while (in.read((char *)&s, sizeof(s)))
                {
                    cout << s.user_name << "\t\t" << s.password << "\t\t" << s.phone << "\t\t" << s.areacode << "\n";
                }
                in.close();
            }
            else
            {
                cout << "cannot do this function :( ";
            }
            in.close();
        }
        else
        {
            cout << "Sorry , File Not Found\n";
        }
    }
    else if (n == 2)
    {
        // Display All Deliveryboys
        DeliveryBoy obj;
        ifstream in;
        in.open("DeliveryBoy.txt", ios::in);
        if (in.is_open())
        {

            cout << "AreaCode |Name |PhoneNumber |Login_username " << endl;
            cout << "__________________________________________________________" << endl;
            while (in.read((char *)&obj, sizeof(obj)))
            {
                decrypt(obj.Login_username);
                cout << obj.AreaCode << "\t " << obj.DeliveryBoyName << "  " << obj.PhoneNumber << "\t" << obj.Login_username << endl;
            }

            in.close();
        }
        else
        {
            cout << "Cannot open the specified file :( " << endl;
        }
    }
    else if (n == 3)
    {
        //*display Data from menue */
        Menue m;
        ifstream in;
        in.open("Menue.txt", ios::in);
        if (in.is_open())
        { // eof end of file

            cout << "\n\n\t\t** Menue **\n\n";

            cout << "ID\ttype\t\tcharge\n";
            cout << "________________________________\n";

            while (in.read((char *)&m, sizeof(m)))
            {

                cout << m.id << "\t" << m.type << "\t\t" << m.charge << "\n";
            }

            in.close();
        }
        else
        {
            cout << "can not open the file\n";
        }
    }
    else if (n == 4)
    {
        // Dispaly order
        ifstream in("order.txt", ios::in);
        if (in.is_open())
        {
            Order order;
            cout << "\t------your order-----\n\n";
            cout << "Type    \tcharge\tamount\n";
            cout << "_______________________________________\n\n";

            while (in.read((char *)&order, sizeof(order)))
            {

                cout << order.type << "   \t" << order.charge << "   \t" << order.amount << "\n";
            }
            in.close();
        }
        else
        {
            cout << "cant open file \n";
        }
    }
    else if (n == 5)
    {
        // display product_discounts
        fstream file;
        file.open("product_discounts.txt", ios::in);
        Discount d;
        if (file.is_open())
        {

            file.read((char *)&d, sizeof(d));
            while (!file.eof())
            {

                cout << "product:             " << '\t' << d.Menue_type << endl;
                cout << "Amount of disccount: " << '\t' << d.Discount_amount << "%" << endl;
                cout << "from:                " << '\t' << d.start_date << endl;
                cout << "to:                  " << '\t' << d.end_date << endl;
                cout << "new Price!:          " << '\t' << (d.charge - (d.charge * (d.Discount_amount / 100))) << endl;
                cout << "---------------------------------------------------------" << endl;

                file.read((char *)&d, sizeof(d));
            }
            file.close();
        }
        else
        {
            cout << "Ooops!...We Cannot access file" << endl;
        }
    }
}

void SearchRecord(int n)
{
    if (n == 1)
    {
        // search for a ("signin customer") in SignUp data by username & password
        char username[10], password[20];
        cout << "Enter username :";
        cin >> username;
        cout << "Enter password :";
        cin >> password;
        bool isValid = false;

        ifstream read;
        read.open("Login.txt", ios::in);
        CustomerSignup c;

        if (read.is_open())
        {

            while (read.read((char *)&c, sizeof(c)))
            {

                decrypt(c.password);
                if (strcmp(username, c.user_name) == 0 && strcmp(password, c.password) == 0)
                {
                    isValid = true;
                }
            }
            read.close();
        }
        else
        {
            cout << "\nSorry , File Not Found\n";
        }

        if (isValid)
        {
            cout << "\nWelcome , Login Successful :) \n";
        }
        else
        {
            cout << "\nPlease , Try Again :( \n";
        }
    }
    else if (n == 2)
    {
        // search for Deliveryboy by name
        DeliveryBoy obj;
        char str[13], ch;
        int flag = 0;
        cout << "Enter name search Record : ";
        cin >> str;
        ifstream in;
        in.open("DeliveryBoy.txt", ios::in);
        if (in.is_open())
        {

            cout << "AreaCode\t| DeliveryBoyName \t| PhoneNumber \t| Login_username " << endl;
            cout << "__________________________________________________________________________________________" << endl;

            while (in.read((char *)&obj, sizeof(obj)))
            {

                if (strcmp(obj.DeliveryBoyName, str) == 0)
                {
                    decrypt(obj.Login_username);
                    cout << obj.AreaCode << "\t  \t  " << obj.DeliveryBoyName << "\t \t \t  " << obj.PhoneNumber << "\t\t" << obj.Login_username << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "not found :( ";
            }

            in.close();
        }
        else
        {
            cout << "cannot open the specified file." << endl;
        }
    }
    else if (n == 3)
    {
        /*searching item in menue*/
        char str1[10];
        cout << "Enter a item to search for? ";
        cin >> str1;
        bool found = false;
        Menue m;
        ifstream in;
        in.open("Menue.txt", ios::in);
        if (in.is_open())
        {
            while (in.read((char *)&m, sizeof(m)))
            {
                if (strcmp(str1, m.type) == 0)
                {
                    cout << "ID\ttype\t\tcharge"
                         << "\n";
                    cout << "________________________________\n";
                    cout << m.id << "\t" << m.type << "\t\t" << m.charge << "\n\n\n";
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Not avaliable"
                     << "\n";

            in.close();
        }
        else
        {
            cout << "can not open the file\n";
        }
    }
    else if (n == 4)
    {
        // Search item in order
        ifstream in("order.txt", ios::in);
        if (in.is_open())
        {
            Order order;
            cout << "Enter item you want to search : ";
            string item;
            cin >> item;

            bool ok = false;

            while (in.read((char *)&order, sizeof(order)))
            {

                if (order.type == item)
                {
                    cout << "----your order-----\n";
                    cout << "Type    \tcharge\tamount\n";
                    cout << "____________________________________\n";
                    cout << order.type << "   \t" << order.charge << "\t" << order.amount << "\n";
                    ok = true;
                }
            }
            if (!ok)
                cout << "** not found **\n\n";
            in.close();
        }
        else
        {
            cout << "cant open file /n";
        }
    }
    else if (n == 5)
    {
        // Search discound for product 
        char product[30];
        cout << "  -----Entre the product to check discount-----  ";
        cin >> product;

        fstream file;
        file.open("product_discounts.txt", ios::in);
        Discount d;
        bool found = false;
        if (file.is_open())
        {
            file.read((char *)&d, sizeof(d));
            while (!file.eof())
            {
                if (!strcmp(product, d.Menue_type))
                {
                    cout << "product:             " << '\t' << d.Menue_type << endl;
                    cout << "Amount of disccount: " << '\t' << d.Discount_amount << "%" << endl;
                    cout << "from:                " << '\t' << d.start_date << endl;
                    cout << "to:                  " << '\t' << d.end_date << endl;
                    cout << "new Price!:          " << '\t' << (d.charge - (d.charge * (d.Discount_amount / 100))) << endl;
                    cout << "---------------------------------------------------------" << endl;

                    found = true;
                }

                file.read((char *)&d, sizeof(d));
            }
            if (!found)
                cout << "Unfortunately, No discounts Avaliable!\n";
            file.close();
        }
        else
        {
            cout << "Ooops!...We Cannot access file" << endl;
        }
    }
    else if (n == 6)
    {
        //search for delivery boy  by areacode
        DeliveryBoy obj;
        char str[30], ch;
        int flag = 0;
        cout << "Enter area code Customer , Search Delivery Boy : ";
        cin >> str;
        ifstream in;
        in.open("DeliveryBoy.txt", ios::in);
        if (in.is_open())
        {

            cout << "\t\t\t\t\t---------Delivery Boy Data----------- \t\t\t" << endl;

            while (in.read((char *)&obj, sizeof(obj)))
            {

                if (strcmp(obj.AreaCode, str) == 0)
                {
                    decrypt(obj.Login_username);
                    cout << "Area Code : " << obj.AreaCode << "\nDelivery Boy Name : " << obj.DeliveryBoyName << "\nPhoneNumber : " << obj.PhoneNumber << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "not found Delivery Boy :( \n";
            }

            in.close();
        }
        else
        {
            cout << "cannot open the specified file." << endl;
        }
    }
}
void DeleteRecord(int n)
{
    if (n == 1)
    {

        // delete customer
        // displayALLCustomer();
        ifstream in("Login.txt", ios::in);
        ofstream out("temp.txt", ios::out | ios::app);
        if (in.is_open() && out.is_open())
        {
            CustomerSignup s;
            char password[20];
            cout << "Enter your password : ";
            cin >> password;
            encrypt(password);
            bool ok = false;
            while (in.read((char *)&s, sizeof(s)))
            {

                if (strcmp(password, s.password) != 0)
                {

                    out.write((char *)&s, sizeof(s));
                }
                else
                {
                    ok = true;
                }
            }
            in.close();
            out.close();
            remove("Login.txt");
            rename("temp.txt", "Login.txt");

            if (ok)
                cout << "logout Successful \n";
            else
                cout << "wrong password\n";
            dispalyALLRecord(1);
        }
        else
        {
            cout << "Sorry , File Not Found\n";
        }
        // displayALLCustomer();
    }
    else if (n == 2)
    {
        // Delete Deliveryboy
        dispalyALLRecord(2);
        ifstream in("DeliveryBoy.txt", ios::in);
        ofstream out("DeliveryBoy temp.txt", ios::out);
        DeliveryBoy obj;
        if (in.is_open())
        {
            cout << "Enter Name DeliveryBoy to delete his record : ";
            char str[50];
            cin >> str;
            while (in.read((char *)&obj, sizeof(obj)))
            {
                if (strcmp(str, obj.DeliveryBoyName) != 0)
                {
                    out.write((char *)&obj, sizeof(obj));
                }
            }
            in.close();
            out.close();
            remove("DeliveryBoy.txt");
            rename("DeliveryBoy temp.txt", "DeliveryBoy.txt");
        }
        dispalyALLRecord(2);
    }
    else if (n == 3)
    {
        //delete item from menue
        dispalyALLRecord(3);
        char str1[10];
        cout << "Enter a type to delete for? ";
        cin >> str1;
        bool found = false;
        Menue m;
        ifstream in("Menue.txt", ios::in);
        ofstream out("Copy.txt", ios::out);
        if (in.is_open())
        {

            while (in.read((char *)&m, sizeof(m)))
            {
                if (strcmp(str1, m.type) != 0)
                {
                    out.write((char *)&m, sizeof(m));
                    found = true;
                }
            }
            if (!found)
                cout << "type not found"
                     << "\n";
            else
                cout << "DONE...\n";
            in.close();
            out.close();
            remove("Menue.txt");
            rename("Copy.txt", "Menue.txt");
        }
        else
        {
            cout << "can not open the file\n";
        }
        dispalyALLRecord(3);
    }
    else if (n == 4)
    {
        // Delete item from order
        ifstream in("order.txt", ios::in);
        ofstream out("temp.txt", ios::out | ios::app);
        if (in.is_open() && out.is_open())
        {
            cout << "Enter item you want to Delete : ";
            string item;
            cin >> item;

            Order order;
            bool ok = false;
            while (in.read((char *)&order, sizeof(order)))
            {

                if (order.type != item)
                {
                    out.write((char *)&order, sizeof(order));
                }
                else
                {
                    ok = true;
                }
            }
            if (!ok)
                cout << "** Item you want to delete not found ** \n";
            in.close();
            out.close();
            remove("order.txt");
            rename("temp.txt", "order.txt");
            dispalyALLRecord(4);
        }
        else
        {
            cout << "cant open file \n";
        }
    }
    else if (n == 5)
    {
        // Delete discount of specific product 
        char product[30];
        cout << "  -----Entre the discount you want delete-----  \n";
        cin >> product;

        fstream file("product_discounts.txt", ios::in);
        fstream outfile("temp.txt", ios::out);

        Discount d;
        bool found = false;
        if (file.is_open())
        {
            file.read((char *)&d, sizeof(d));
            while (!file.eof())
            {
                if (strcmp(product, d.Menue_type))
                {
                    outfile.write((char *)&d, sizeof(d));

                    found = true;
                }

                file.read((char *)&d, sizeof(d));
            }
            file.close();
            outfile.close();
            remove("product_discounts.txt");
            rename("temp.txt", "product_discounts.txt");

            if (!found)
                cout << "There is no disconts on that product!";
            file.close();
        }
        else
        {
            cout << "Ooops!...We Cannot access file" << endl;
        }
    }
}
void UpdateRecord(int n)
{
    if (n == 1)
    {
        // update password
        // Reset 'password'
        // user name static

        CustomerSignup c;

        char Old_password[10];

        fstream upDate;
        upDate.open("Login.txt", ios::in | ios::out);
        if (upDate.is_open())
        {
            cout << "Please , Enter Your Old Password\n";
            cin >> Old_password; // 1111

            while (upDate.read((char *)&c, sizeof(c)))
            {
                decrypt(c.password);
                if (strcmp(Old_password, c.password) == 0)
                {
                    int curr_pos = upDate.tellg();
                    int stu_size = sizeof(c);
                    cout << "Please , Enter Your New Password\n";
                    cin >> c.password;
                    encrypt(c.password);
                    upDate.seekp(curr_pos - stu_size, ios::beg);
                    upDate.write((char *)&c, sizeof(c));
                    upDate.seekg(curr_pos - stu_size, ios::beg);
                    upDate.read((char *)&c, sizeof(c));
                    decrypt(c.password);
                    cout << " UserName : " << c.user_name << "\tNewPassword : " << c.password << "\n";
                    cout << "Password Updated :) \n";
                    break;
                }
                else
                {
                    cout << "Incorrect password, please try again. :( \n";
                    break;
                }
            }
            upDate.close();
        }
        else
        {

            cout << "Sorry , File Not Found\n";
        }
    }
    else if (n == 2)
    {
        // Update Phone of Deliveryboy
        dispalyALLRecord(2);
        DeliveryBoy obj;
        fstream f("DeliveryBoy.txt", ios::in | ios::out);
        if (f.is_open())
        {
            bool found = false;
            char str[20];
            cout << "Enter name Delivery Boy : ";
            cin >> str;
            while (!f.eof())
            {
                f.read((char *)&obj, sizeof(obj));
                if (strcmp(str, obj.DeliveryBoyName) == 0)
                {
                    cout << "Enter the new Phone Number for Delivery Boy " << str << " : ";
                    cin >> obj.PhoneNumber;
                    int curPos = f.tellg(); //
                    int studentSize = sizeof(obj);
                    f.seekp(curPos - studentSize, ios::beg);
                    f.write((char *)&obj, sizeof(obj));
                    found = true;
                    break;
                }
            }
            f.close();
            if (!found)
            {
                cout << "Delivery Name does not exist :( ";
            }
        }
        dispalyALLRecord(2);
    }
    else if (n == 3)
    {
        /*update charge */
        dispalyALLRecord(3);

        char type[20];
        cout << "\n=>Enter a type to search for? ";
        cin >> type;
        bool found = false;
        Menue m;
        fstream in;
        in.open("Menue.txt", ios::in | ios::out);
        if (in.is_open())
        {

            while (in.read((char *)&m, sizeof(m)))
            {
                if (strcmp(type, m.type) == 0)
                {
                    cout << "\n=>Enter the new charge for " << type << " ";
                    cin >> m.charge;
                    int curpos = in.tellg();
                    int msize = sizeof(m);
                    in.seekp(curpos - msize, ios::beg);
                    in.write((char *)&m, sizeof(m));
                    in.seekg(curpos - msize, ios::beg);
                    in.read((char *)&m, sizeof(m));
                    cout << "ID\ttype\tcharge"
                         << "\n";
                    cout << m.id << "\t" << m.type << "\t" << m.charge << "\n";
                    found = true;
                    dispalyALLRecord(3);
                    break;
                }
            }
            if (!found)
                cout << "name not found"
                     << "\n";
            in.close();
        }
        else
        {
            cout << "can not open the file\n";
        }
    }
    else if (n == 4)
    {
        // Update amount of order
        fstream in("order.txt", ios::in | ios::out);
        if (in.is_open())
        {
            Order order;
            cout << "Enter item you want to update : ";
            string item;
            cin >> item;

            bool ok = false;

            while (in.read((char *)&order, sizeof(order)))
            {

                if (item == order.type)
                {
                    cout << "Enter new amount : ";
                    cin >> order.amount;
                    int curr_pos = in.tellg();
                    int recordsz = sizeof(order);
                    in.seekp(curr_pos - recordsz, ios::beg);

                    in.write((char *)&order, sizeof(order));

                    ok = true;
                    break;
                }
            }
            if (!ok)
                cout << "** item you want to replace not found :( **\n";
            in.close();
            dispalyALLRecord(4);
        }
        else
        {
            cout << "cant open file \n";
        }
    }

    else if (n == 5)
    {
        // Update discount
        dispalyALLRecord(5);
        Discount obj;
        fstream f("product_discounts.txt", ios::in | ios::out);
        if (f.is_open())
        {
            bool found = false;
            char str[20];
            cout << "Enter Product name : ";
            cin >> str;
            while (!f.eof())
            {
                f.read((char *)&obj, sizeof(obj));
                if (strcmp(str, obj.Menue_type) == 0)
                {
                    cout << "Enter the new new discount " << str << " : ";
                    cin >> obj.Discount_amount;
                    int curPos = f.tellg(); //
                    int studentSize = sizeof(obj);
                    f.seekp(curPos - studentSize, ios::beg);
                    f.write((char *)&obj, sizeof(obj));
                    found = true;
                    break;
                }
            }
            f.close();
            if (!found)
            {
                cout << "Product Name does not exist :( \n";
            }
            else{
                cout<<"Done!\n";
            }
        }
        dispalyALLRecord(5);
    }
}

double Searchcharge(char str[20])
{
    /*searching for charge*/

    Menue m;
    ifstream in;
    in.open("Menue.txt", ios::in);
    if (in.is_open())
    {
        while (in.read((char *)&m, sizeof(m)))
        {
            if (strcmp(str, m.type) == 0)
            {
                return m.charge;
            }
        }
        in.close();
    }
    else
    {
        cout << "can not open the file\n";
    }
    return -1;
}

int main()
{
    cout << "\n\n";
    cout << "\t\t\t\t****Welcome to us. Our service is to deliver food to homes***\n";
    cout << "\t\t\t\t\t\t***We wish you a good service***";
    cout << "\n";
    cout << "\n";

    char another;
    int ch;
    do
    {
        cout << "1.Signup \n2.SignIn \n3.Update_Password \n4.Logout \n5.View Menue \n6.Make order \n7.Dispaly order \n8.Search Item In Order \n9.Delete Item \n10.Update Amount of item in your Order \n11.add new item To Order \n12.Find DeliveryBoy\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            AddRecord(1);
            dispalyALLRecord(3);
            break;
        case 2:
            SearchRecord(1);
            dispalyALLRecord(3);
            break;
        case 3:
            UpdateRecord(1);
            break;
        case 4:
            DeleteRecord(1);
            break;
        case 5:
            dispalyALLRecord(3);
            break;
        case 6:
            AddRecord(5);
            break;
        case 7:
            dispalyALLRecord(4);
            break;
        case 8:
            SearchRecord(4);
            break;
        case 9:
            DeleteRecord(4);

            break;

        case 10:
            UpdateRecord(4);

            break;
        case 11:
            AddRecord(6);
            break;
        case 12:
            SearchRecord(6);
            break;

        default:
            break;
        }
        cout << "another operation (y/n) : ";
        cin >> another;
    } while (another == 'y');

    return 0;
}
