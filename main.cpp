#include<iostream>
#include<vector>
#include <iomanip>
#include<fstream>
using namespace std;

string divide(string s)
{
    string word="";
    for(auto x:s)
    {
        if(x==' ')
        {
            return word;
        }
        else
        {
            word+=x;
        }
    }

}

int main()
{
    int role;
    label:
    cout<<" PRESS 1 FOR NEW "<<endl;
    cout<<" PRESS 2 FOR ALL ACCOUNTS "<<endl;
    cout<<" PRESS 3 FOR SEARCH "<<endl;
    cout<<" PRESS 4 TO UPDATE "<<endl;
    cout<<" PRESS 5 TO DELETE ACCOUNT "<<endl;
    cout<<" PRESS 6 TO EXIT "<<endl;
    cin>>role;
    cin.ignore();
    if(role==1)
    {
        string firstName,LastName,FatherName,MotherName;
        int age,total;
        cout<<"Enter name 'excuding' surname : ";
        getline(cin, firstName);
        cin.ignore();
        cout<<"Enter your surname : ";
        cin>>LastName;
        cin.ignore();
        cout<<"Enter your age : ";
        cin>>age;
        cin.ignore();
        cout<<"Enter father's full name : ";
        getline(cin, FatherName);
        cin.ignore();
        cout<<"Enter mother's full name : ";
        getline(cin, MotherName);
        cin.ignore();
        ofstream MotherBook("mothers.txt", std::ios_base::app);
        ofstream FatherBook("fathers.txt", std::ios_base::app);
        ofstream First_Name_book("user_name.txt", std::ios_base::app);
        ofstream AgeBook("ages.txt", std::ios_base::app);
        ofstream surname_book("surname.txt", std::ios_base::app);
        MotherBook<<MotherName<<endl;
        FatherBook<<FatherName<<endl;
        First_Name_book<<firstName<<endl;
        surname_book<<LastName<<endl;
        AgeBook<<age<<endl;
        MotherBook.close();
        FatherBook.close();
        First_Name_book.close();
        surname_book.close();
        AgeBook.close();
        ifstream RecordTake("total.txt");
        RecordTake>>total;
        RecordTake.close();
        total++;
        ofstream RecordGive("total.txt");
        RecordGive<<total;
        RecordGive.close();
        cout<<"REGESTRATION DONE !!!"<<"   YOUR REGESTRATION NUMBER :  "<<total<<endl<<endl;
        goto label;
    }
    if(role==2)
    {
        int people_size;
        ifstream record("total.txt");
        record>>people_size;
        string final_name[people_size];
        string user_names[people_size],surnames[people_size],fathers[people_size],mothers[people_size];
        int ages[people_size];
        ifstream user_file("user_name.txt"),user_surname("surname.txt"),ages_file("ages.txt"),father_file("fathers.txt"),mother_file("mothers.txt");
        for(int i=0;i<people_size;i++)
        {
            getline(user_file,user_names[i]);
            user_surname>>surnames[i];
            ages_file>>ages[i];
            getline(father_file,fathers[i]);
            getline(mother_file,mothers[i]);
            final_name[i]=user_names[i]+" "+surnames[i];
        }
        cout<<left<<setw(29)<<"account holder:"<<setw(13)<<"age:"<<setw(26)<<"father's name:"<<setw(26)<<"mother's name"<<endl<<endl;
        for(int i=0;i<people_size;i++)
        {
            cout<<left<<setw(29)<<final_name[i]<<setw(13)<<ages[i]<<setw(26)<<fathers[i]<<setw(26)<<mothers[i]<<endl;

        }
        cout<<endl;
        goto label;
    }
    if(role==3)
    {
        int new_role;
        cout<<endl;
        cout<<"Press 1. for search by first name "<<endl;
        cout<<"Press 2. for search by surname "<<endl;
        cout<<"press 3. for search by age "<<endl;
        cin>>new_role;
        cin.ignore();
        if(new_role==1)
        {
            cout<<"Enter only 'First letter' of name : ";
            vector<string> show_father,show_mother,show_user;
            vector<int> show_age;
            int people_size,showing_size=0;
            string name_in;
            cin>>name_in;
            cin.ignore();
            ifstream names("user_name.txt");
            ifstream total_record("total.txt");
            total_record>>people_size;
            total_record.close();
            string first_names_book[people_size];
            for(int i=0;i<people_size;i++)
            {
                string full_name;
                getline(names, full_name);
                first_names_book[i]=divide(full_name);
            }
            for(int i=0;i<people_size;i++)
            {
                if(first_names_book[i]==name_in)
                {
                    ifstream all_fathers("fathers.txt");
                    ifstream all_mothers("mothers.txt");
                    ifstream all_ages("ages.txt");
                    ifstream all_names("user_name.txt");
                    ifstream all_surnames("surname.txt");
                    string all_fathers_copied[people_size],all_mothers_copied[people_size],all_names_copied[people_size],all_surnames_copied[people_size];
                    int all_ages_copied[people_size];
                    for(int j=0;j<people_size;j++)
                    {
                        getline(all_fathers,all_fathers_copied[j]);
                        getline(all_mothers,all_mothers_copied[j]);
                        all_ages>>all_ages_copied[j];
                        string name1,name2;
                        getline(all_names,name1);
                        getline(all_surnames,name2);
                        all_names_copied[j]=name1+" "+name2;
                    }
                    show_father.push_back(all_fathers_copied[i]);
                    show_age.push_back(all_ages_copied[i]);
                    show_mother.push_back(all_mothers_copied[i]);
                    show_user.push_back(all_names_copied[i]);
                    showing_size=show_age.size();
                }

             }
            cout<<endl;
            cout<<left<<setw(29)<<"account holder:"<<setw(13)<<"age:"<<setw(26)<<"father's name:"<<setw(26)<<"mother's name"<<endl<<endl;
            for(int i=0;i<showing_size;i++)
            {
                cout<<left<<setw(29)<<show_user[i]<<setw(13)<<show_age[i]<<setw(26)<<show_father[i]<<setw(26)<<show_mother[i]<<endl;
            }
            cout<<endl;
             if(showing_size==0)
             {
                cout<<"No Record Found"<<endl;
             }

              goto label;
        }
        if(new_role==2)
        {
            string find_surname;
            cout<<"Enter only 'Surname' of name : ";
            cin>>find_surname;
            cin.ignore();

            vector<string> show_father,show_mother,show_user;
            vector<int> show_age;
            int people_size,showing_size=0;
            ifstream surnames("surname.txt");
            ifstream total_record("total.txt");
            total_record>>people_size;
            total_record.close();
            string surnames_book[people_size];
            for(int i=0;i<people_size;i++)
            {
                getline(surnames, surnames_book[i]);
            }
            for(int i=0;i<people_size;i++)
            {
                if(surnames_book[i]==find_surname)
                {
                    ifstream all_fathers("fathers.txt");
                    ifstream all_mothers("mothers.txt");
                    ifstream all_ages("ages.txt");
                    ifstream all_names("user_name.txt");
                    ifstream all_surnames("surname.txt");
                    string all_fathers_copied[people_size],all_mothers_copied[people_size],all_names_copied[people_size],all_surnames_copied[people_size];
                    int all_ages_copied[people_size];
                    for(int j=0;j<people_size;j++)
                    {
                        getline(all_fathers,all_fathers_copied[j]);
                        getline(all_mothers,all_mothers_copied[j]);
                        all_ages>>all_ages_copied[j];
                        string name1,name2;
                        getline(all_names,name1);
                        getline(all_surnames,name2);
                        all_names_copied[j]=name1+" "+name2;
                    }
                    show_father.push_back(all_fathers_copied[i]);
                    show_age.push_back(all_ages_copied[i]);
                    show_mother.push_back(all_mothers_copied[i]);
                    show_user.push_back(all_names_copied[i]);
                    showing_size=show_age.size();
                }

             }
             cout<<endl;
            cout<<left<<setw(29)<<"account holder:"<<setw(13)<<"age:"<<setw(26)<<"father's name:"<<setw(26)<<"mother's name"<<endl<<endl;
            for(int i=0;i<showing_size;i++)
            {
                cout<<left<<setw(29)<<show_user[i]<<setw(13)<<show_age[i]<<setw(26)<<show_father[i]<<setw(26)<<show_mother[i]<<endl;
            }
            cout<<endl;
             if(showing_size==0)
             {
                cout<<"No Record Found"<<endl<<endl;
             }

              goto label;
        }
        if(new_role==3)
        {
            cout<<"Enter Age : ";
            int find_age;
            cin>>find_age;
            cin.ignore();
            vector<string> show_father,show_mother,show_user;
            vector<int> show_age;
            int people_size,showing_size=0;
            ifstream ages_record("ages.txt");
            ifstream total_record("total.txt");
            total_record>>people_size;
            total_record.close();
            int ages_book[people_size];
            for(int i=0;i<people_size;i++)
            {
                ages_record>>ages_book[i];
            }
            for(int i=0;i<people_size;i++)
            {
                if(ages_book[i]==find_age)
                {
                    ifstream all_fathers("fathers.txt");
                    ifstream all_mothers("mothers.txt");
                    ifstream all_ages("ages.txt");
                    ifstream all_names("user_name.txt");
                    ifstream all_surnames("surname.txt");
                    string all_fathers_copied[people_size],all_mothers_copied[people_size],all_names_copied[people_size],all_surnames_copied[people_size];
                    int all_ages_copied[people_size];
                    for(int j=0;j<people_size;j++)
                    {
                        getline(all_fathers,all_fathers_copied[j]);
                        getline(all_mothers,all_mothers_copied[j]);
                        all_ages>>all_ages_copied[j];
                        string name1,name2;
                        getline(all_names,name1);
                        getline(all_surnames,name2);
                        all_names_copied[j]=name1+" "+name2;
                    }
                    show_father.push_back(all_fathers_copied[i]);
                    show_age.push_back(all_ages_copied[i]);
                    show_mother.push_back(all_mothers_copied[i]);
                    show_user.push_back(all_names_copied[i]);
                    showing_size=show_age.size();
                }

             }
             cout<<endl;
            cout<<left<<setw(29)<<"account holder:"<<setw(13)<<"age:"<<setw(26)<<"father's name:"<<setw(26)<<"mother's name"<<endl<<endl;
            for(int i=0;i<showing_size;i++)
            {
                cout<<left<<setw(29)<<show_user[i]<<setw(13)<<show_age[i]<<setw(26)<<show_father[i]<<setw(26)<<show_mother[i]<<endl;
            }
            cout<<endl;
             if(showing_size==0)
             {
                cout<<"No Record Found"<<endl<<endl;
             }

              goto label;
        }
     }
     if(role==4)
     {
         int reg_number,people_size;
         cout<<"Enter your Regestration Number : ";
         cin>>reg_number;
         cin.ignore();
         cout<<endl;
         ifstream total_record("total.txt");
         total_record>>people_size;
         if(reg_number>people_size)
         {
             cout<<"No Account found"<<endl;
             goto label;
         }
        ifstream all_fathers("fathers.txt");
        ifstream all_mothers("mothers.txt");
        ifstream all_ages("ages.txt");
        ifstream all_names("user_name.txt");
        ifstream all_surnames("surname.txt");
        vector<string> all_fathers_copied,all_mothers_copied,all_names_copied,all_surnames_copied,all_firstname_copied;
        vector<int> all_ages_copied;
        for(int j=0;j<people_size;j++)
        {
            string name_take;
            int age_take;
            getline(all_fathers,name_take);
            all_fathers_copied.push_back(name_take);
            getline(all_mothers,name_take);
            all_mothers_copied.push_back(name_take);
            all_ages>>age_take;
            all_ages_copied.push_back(age_take);
            string name1,name2;
            getline(all_names,name1);
            all_firstname_copied.push_back(name1);
            getline(all_surnames,name2);
            all_surnames_copied.push_back(name2);
            all_names_copied.push_back(name1+" "+name2);
        }
         cout<<"Account Found !!!!"<<endl<<endl;
         cout<<"            Current Details are as follows : "<<endl<<endl;
         cout<<left<<setw(13)<<"User Name  "<<setw(20)<<":"<<all_names_copied[reg_number-1]<<endl;
         cout<<left<<setw(13)<<"User Age  "<<setw(20)<<":"<<all_ages_copied[reg_number-1]<<endl;
         cout<<left<<setw(13)<<"Father Name  "<<setw(20)<<":"<<all_fathers_copied[reg_number-1]<<endl;
         cout<<left<<setw(13)<<"Mother Name  "<<setw(20)<<":"<<all_mothers_copied[reg_number-1]<<endl<<endl;
         cout<<"Press 1. To Update Name "<<endl;
         cout<<"Press 2. To Update Age "<<endl;
         cout<<"Press 3. To Update Father's Name "<<endl;
         cout<<"Press 4. To Update Mother's Name "<<endl;
         int new_role;
         cin>>new_role;
         cin.ignore();
         if(new_role==1)
         {
             string first_name,last_name;
             cout<<"Enter Name 'excluding' surname : ";
             getline(cin, first_name);
             cin.ignore();
             cout<<"Enter Surname : ";
             getline(cin, last_name);
             cin.ignore();
             all_firstname_copied.at(reg_number-1)=first_name;
             all_surnames_copied.at(reg_number-1)=last_name;
             ofstream giving_all_firstnames("user_name.txt");
             ofstream giving_all_surnames("surname.txt");
             for(int i=0;i<all_firstname_copied.size();i++)
             {
                 giving_all_firstnames<<all_firstname_copied[i]<<endl;
                 giving_all_surnames<<all_surnames_copied[i]<<endl;
             }
             cout<<"NAME UPDATED SUCCESSFULLY !!!!! "<<endl;
             goto label;
         }
         if(new_role==2)
         {
             int new_age;
             cout<<"Enter new age  : ";
             cin>>new_age;
             cin.ignore();
             all_ages_copied.at(reg_number-1)=new_age;
             ofstream giving_all_ages("ages.txt");
             for(int i=0;i<all_ages_copied.size();i++)
             {
                 giving_all_ages<<all_ages_copied[i]<<endl;
             }
             cout<<" AGE UPDATED !!!!! "<<endl<<endl;
             goto label;
         }
         if(new_role==3)
         {
             string correct_father;
             cout<<"Enter father's full name correctly : ";
             getline(cin, correct_father);
             cin.ignore();
             all_fathers_copied.at(reg_number-1)=correct_father;
             ofstream giving_all_fathers("fathers.txt");
             for(int i=0;i<all_fathers_copied.size();i++)
             {
                 giving_all_fathers<<all_fathers_copied[i]<<endl;
             }
             cout<<" FATHER'S NAME UPDATED !!!!! "<<endl<<endl;
             goto label;
         }
         if(new_role==4)
         {
             string correct_mother;
             cout<<"Enter mother's full name correctly : ";
             getline(cin, correct_mother);
             cin.ignore();
             all_mothers_copied.at(reg_number-1)=correct_mother;
             ofstream giving_all_mothers("mothers.txt");
             for(int i=0;i<all_mothers_copied.size();i++)
             {
                 giving_all_mothers<<all_mothers_copied[i]<<endl;
             }
             cout<<" MOTHER'S NAME UPDATED !!!!! "<<endl<<endl;
             goto label;
         }

     }
     if(role==5)
     {
         int which_account,total,people_size;
         cout<<"Enter Regestration Number of account to be Deleted : ";
         cin>>which_account;
         cin.ignore();
         ifstream full_record("total.txt");
         full_record>>total;
         if(which_account>total)
         {
             cout<<"No Account Found"<<endl<<endl;
             goto label;
         }
         people_size=total;
         total--;

        ifstream all_fathers("fathers.txt");
        ifstream all_mothers("mothers.txt");
        ifstream all_ages("ages.txt");
        ifstream all_names("user_name.txt");
        ifstream all_surnames("surname.txt");
        vector<string> all_fathers_copied,all_mothers_copied,all_names_copied,all_surnames_copied,all_firstname_copied;
        vector<int> all_ages_copied;
        for(int j=0;j<people_size;j++)
        {
            string name_take;
            int age_take;
            getline(all_fathers,name_take);
            all_fathers_copied.push_back(name_take);
            getline(all_mothers,name_take);
            all_mothers_copied.push_back(name_take);
            all_ages>>age_take;
            all_ages_copied.push_back(age_take);
            string name1,name2;
            getline(all_names,name1);
            all_firstname_copied.push_back(name1);
            getline(all_surnames,name2);
            all_surnames_copied.push_back(name2);
        }
        all_fathers_copied.erase(all_fathers_copied.begin() + (which_account-1));
        all_mothers_copied.erase(all_mothers_copied.begin() + (which_account-1));
        all_ages_copied.erase(all_ages_copied.begin() + (which_account-1));
        all_firstname_copied.erase(all_firstname_copied.begin() + (which_account-1));
        all_surnames_copied.erase(all_surnames_copied.begin() + (which_account-1));
        ofstream fill_fathers("fathers.txt");
        ofstream fill_mothers("mothers.txt");
        ofstream fill_ages("ages.txt");
        ofstream fill_first_names("user_name.txt");
        ofstream fill_surnames("surname.txt");
        ofstream give_record("total.txt");
        give_record<<total;
        give_record.close();
        for(int i=0;i<total;i++)
        {

            fill_fathers<<all_fathers_copied[i]<<endl;

            fill_mothers<<all_mothers_copied[i]<<endl;

            fill_first_names<<all_firstname_copied[i]<<endl;

            fill_surnames<<all_surnames_copied[i]<<endl;
            fill_ages<<all_ages_copied[i]<<endl;
        }
        cout<<"ACCOUNT DELETED !!!!!"<<endl<<endl;
        goto label;
     }
     if(role==6)
     {
         return 0;
     }

}
