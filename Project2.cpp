#include <iostream>
#include<string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <iterator>
#include <boost/algorithm/string.hpp>

using namespace std;


class CSVReader{
    std::string course_info;
    std::string delimeter;



public:
    CSVReader(std::string course_info, std::string delm = ",") :
        course_info(course_info), delimeter(delm){ 

        }
    std::vector<std::vector<std::string> > getData();

};

std::vector<std::vector<std::string> > CSVReader::getData()
{
    std::ifstream file(course_info);
    std::vector<std::vector<std::string> > dataList;
    std::string line = "";
    // Iterate through each line and split the content using delimeter
    while (getline(file, line))
    {
        std::vector<std::string> vec;
        boost::algorithm::split(vec, line, boost::is_any_of(delimeter));
        dataList.push_back(vec);
    }
    // Close the File
    file.close();
    return dataList;
}




int main()
{
    CSVReader reader("Project 2 - Sheet1.csv");




























cout<<"Welcome to the course Planner\n";
    while (true)
    {
        //Int flag variables 
       int flag;
       string flag2;
       flag=0;
       //Displays a menu to the user on what they want to do
       cout<<"\t 1.Load Data Structure.\n";
       cout<<"\t 2.Print Course List.\n";
       cout<<"\t 3.Print Course.\n";
       cout<<"\t 9.Exit.\n";      
       cout<<"What would you like to do?";
       cin>>flag;
       cout<<"\n";

       //if else statements that execute certain parts of the code.
       if (flag==9)
       {
           break;
       }
       else if (flag==1)
       {
           std::vector<std::vector<std::string> > dataList = reader.getData();
       }

       //This else if statement displays a sample schedule
       else if(flag==2)
       {
          // cout<<"Here is sample schedule:\n\n";
           //cout<<"CSCI100, Introduction to Computer Science\n";
           //cout<<"CSCI101, Introduction to Programming in C++\n";
           //cout<<"CSCI200, Data Structures\n";      
           //cout<<"CSCI301, Advance Programming in C++\n";
           //cout<<"CSCI300, Introduction to Algorithms\n";
           //cout<<"CSCI350, Operating Systems\n";
           //cout<<"CSCI400, Large Software Development\n";
           //cout<<"MATH201, Discrete Mathematics\n\n";

        for(std::vector<std::string> vec : dataList)
        {
         for(std::string data : vec)
            {
             std::cout<<data << " , ";
            }
         std::cout<<std::endl;
        }


       }


       //This else if statment asks user for input in which class they would like more information on
       else if (flag==3)
       {
           cout<<"What course do you want to know about?";
           cin>>flag2;
           cout<<"\n";
           transform(flag2.begin(), flag2.end(), flag2.begin(), ::tolower);
           if (flag2 == "csci100")
           {
               cout<<"CSCI100, Introduction to Computer Science \nPrerequisites: None\n\n";
           }
           else if (flag2 == "csci101")
           {
               cout<<"CSCI101, Introduction to Programming in C++\nPrerequisites: CSCI100\n\n";
           }
           else if (flag2 == "csci200")
           {
                cout<<"CSCI200, Data Structures \nPrerequisites: CSCI101\n\n";
           }
           else if (flag2 == "math201")
           {
               cout<<"MATH201, Discrete Mathematics \nPrerequisites: None\n\n";
           }
           else if (flag2 == "csci300")
           {
               cout<<"CSCI300, Introduction to Algorithms \nPrerequisites: CSCI200, MATH201\n\n";
           }
           else if (flag2 == "csci301")
           {
               cout<<"CSCI301, Advanced Programming in C++ \nPrerequisites: CSCI101\n\n";
           }
           else if (flag2 == "csci350")
           {
               cout<<"CSCI350, Operating Systems \nPrerequisites: CSCI300\n\n";
           }
           else if (flag2 == "csci400")
           {
               cout<<"CSCI400, Large Software Development \nPrerequisites: CSCI301, CSCI350\n\n";
           }
       }


       //Displays an error if one of the options above is not chosen.
       else
       {
           cout<<flag;
           cout<<" is not a valid option\n";
       }
   }

    return 0;
}
