#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include "ArgumentManager.h"
#include "LinkedList.h"

using namespace std;

int main(int argc, char *argv[]) 
{
  ArgumentManager am(argc, argv);
   string input = am.get("input");
   string command = am.get("command");
   string output = am.get("output");

  //string input = "input9.txt";
  //string command = "command9.txt";
  //string output = "outputT.txt";

  ifstream ifs(input);
  ifstream cmd(command);
  ofstream ofs(output);

  // variables
  string inputline;
  string name;
  int age, nDrinks;
  float deposit;

  LinkedList list;

  // Processing the input files
  // [name: Rob; age: 34; deposit: 1234; number of drinks: 1]
  while (getline(ifs, inputline)) {
    // clean the inputline
    inputline.erase(remove(inputline.begin(), inputline.end(), '\n'), inputline.end());
    inputline.erase(remove(inputline.begin(), inputline.end(), '\r'), inputline.end());

    name = inputline.substr(7, inputline.find(';') - 7);
    //cout << name << endl;

    inputline = inputline.substr(inputline.find(';') + 2);
    //cout << "Now inputline is: " << inputline << endl;

    age = stoi(inputline.substr(5, inputline.find(';') - 5));
    inputline = inputline.substr(inputline.find(';') + 2);
    //cout << age << endl;

    deposit = stof(inputline.substr(9, inputline.find(';') - 9));
    inputline = inputline.substr(inputline.find(';') + 2);
    //cout << deposit << endl;

    nDrinks = stoi(inputline.substr(18, inputline.find(']') - 18));
    //cout << nDrinks << endl;

    node *temp = new node(name, age, deposit, nDrinks);

    list.insertAtEnd(temp);
  }
  
    string inStr = "";
    string cmndStr = "";
    string indexStr = "";
    string cred = "";
    string attribute = "";
    int val = 0;

  while(getline(cmd, inStr))
    {
        
        inStr.erase(remove(inStr.begin(), inStr.end(), '\n'), inStr.end());
        inStr.erase(remove(inStr.begin(), inStr.end(), '\r'), inStr.end());

        if(inStr.empty())
        {
            continue;
        }

        stringstream ss(inStr);

        ss >> cmndStr;

        if(cmndStr == "Add")
        {
            int size = 0;
            
            size = list.getSize();
            //cout << "\nthis is the cur size of list: " << size;

            ss >> indexStr;
            string index;
            int ind = 0;

            for(int i = 0; i < indexStr.length(); i++)
            {
                if(isdigit(indexStr[i]))
                {
                    index+= indexStr[i];
                }
            }
            ind = stoi(index);

            //cout << "\n this is the index: " << ind;

            if(ind == 0)
            {

                cred = inStr.substr(inStr.find("["));
                //cout << "\n this is the inStr: " << inStr;
                //cout << "\n this is the cred: " << cred << endl;

                name = cred.substr(7, cred.find(';') - 7);
                //cout << name << endl;

                cred = cred.substr(cred.find(';') + 2);
                //cout << "Now cred is: " << cred << endl;

                age = stoi(cred.substr(5, cred.find(';') - 5));
                cred = cred.substr(cred.find(';') + 2);
                //cout << age << endl;

                deposit = stof(cred.substr(9, cred.find(';') - 9));
                cred = cred.substr(cred.find(';') + 2);
                //cout << deposit << endl;

                nDrinks = stoi(cred.substr(18, cred.find(']') - 18));
                //cout << nDrinks << endl;

                node *temp = new node(name, age, deposit, nDrinks);

                list.insertAtHead(temp);
            }
            
            else if (ind >= size)
            {
                cred = inStr.substr(inStr.find("["));
                //cout << "\n this is the inStr: " << inStr;
                //cout << "\n this is the cred: " << cred << endl;

                name = cred.substr(7, cred.find(';') - 7);
                //cout << name << endl;

                cred = cred.substr(cred.find(';') + 2);
                //cout << "Now cred is: " << cred << endl;

                age = stoi(cred.substr(5, cred.find(';') - 5));
                cred = cred.substr(cred.find(';') + 2);
                //cout << age << endl;

                deposit = stof(cred.substr(9, cred.find(';') - 9));
                cred = cred.substr(cred.find(';') + 2);
                //cout << deposit << endl;

                nDrinks = stoi(cred.substr(18, cred.find(']') - 18));
                //cout << nDrinks << endl;

                node *temp = new node(name, age, deposit, nDrinks);
                list.insertAtEnd(temp);
            }

            else if (ind < size)
            {
                cred = inStr.substr(inStr.find("["));
                //cout << "\n this is the inStr: " << inStr;
                //cout << "\n this is the cred: " << cred << endl;

                name = cred.substr(7, cred.find(';') - 7);
                //cout << name << endl;

                cred = cred.substr(cred.find(';') + 2);
                //cout << "Now cred is: " << cred << endl;

                age = stoi(cred.substr(5, cred.find(';') - 5));
                cred = cred.substr(cred.find(';') + 2);
                //cout << age << endl;

                deposit = stof(cred.substr(9, cred.find(';') - 9));
                cred = cred.substr(cred.find(';') + 2);
                //cout << deposit << endl;

                nDrinks = stoi(cred.substr(18, cred.find(']') - 18));
                //cout << nDrinks << endl;

                node *temp = new node(name, age, deposit, nDrinks);
                list.insertAtPos(temp, ind);
            }

        }

        //ex: Remove (number of drinks: 7)
        else if(cmndStr == "Remove")
        {
            ss >> indexStr;
            //cout << "\nThis is the indexStr: " << indexStr;
            string value ="";
            string nameFind = "";
            string attri = "";
            int val = 0;
            attribute = inStr.substr(inStr.find("("));
            //cout << "\n this is the attribute: " << attribute;

            
           if (indexStr == "(number") //number of drinks
            {
                for(int i = 0; i < attribute.length(); i++)
                {
                if(isdigit(attribute[i]))
                {
                    value+= attribute[i];
                }
                }

            val = stoi(value);
            //cout << "\n this is val: " << val;

            list.removeNumDrinks(val);       

            }

            else if(indexStr == "(deposit:")
            {
                for(int i = 0; i < attribute.length(); i++)
                {
                if(isdigit(attribute[i]))
                {
                    value+= attribute[i];
                }
                }

            val = stoi(value);
            //cout << "\n this is val: " << val;

            list.removeDeposit(val);
            }

            else if(indexStr == "(age:")
            {
                for(int i = 0; i < attribute.length(); i++)
                {
                if(isdigit(attribute[i]))
                {
                    value+= attribute[i];
                }
                }

            val = stoi(value);
            //cout << "\n this is val: " << val;

            list.removeAge(val);
            }

            else if(indexStr == "(name:")
            {
                attri = attribute.substr(attribute.find(": "));
                //cout << "\n this is attri: " << attri;

                for(int i = 0; i < attri.length(); i++)
                {
                if(isalpha(attri[i]))
                {
                    nameFind+= attri[i];
                }
                }
                //cout << "\nthis is the name to be found: " << nameFind;

                list.removeName(nameFind);
            }

        }

        
        else if(cmndStr == "Sort")
        {
            string toBeSort="";
            //ss >> indexStr;
            inStr.erase(remove(inStr.begin(), inStr.end(), '['), inStr.end());
            inStr.erase(remove(inStr.begin(), inStr.end(), ']'), inStr.end());
            //cout << "\nthis is the sort: " << indexStr;

            attribute = inStr.substr(inStr.find("("));
            //cout << "\n this is the attribute: " << attribute;

            for(int i = 0; i < attribute.length(); i++)
                {
                if(isalpha(attribute[i]))
                {
                    toBeSort+= attribute[i];
                }
                }
                //cout << "\n this is what is being sorted: " << toBeSort;

                if(toBeSort == "deposit")
                {
                    list.sortDeposit();
                }

                else if(toBeSort == "age")
                {
                    list.sortAge();
                }

                else if(toBeSort == "numberofdrinks")
                {
                    list.sortDrinks();
                }

                else if(toBeSort == "name")
                {
                    list.sortNames();
                }
        }


    }
    //cout << endl << endl;
    list.print(ofs);
    //list.print();
    return 0;
}
