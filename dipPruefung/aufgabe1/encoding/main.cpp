#include <iostream>
#include <cstdlib>
#include <string>

std::string decode(std::string str);

std::string decode(std::string str)
{
    if (str.empty())
    {
        return "";
    }
    else
    {
        std::string::iterator it = str.begin();

        std::string digitSTR;
        std::string out;

        while (it != str.end())
        {
            if (std::isdigit(*it) )
            {
                digitSTR += *it;
            }
            else
            {
                for(int i = 0; i < std::stoi(digitSTR); i++)
                {
                    out += *it;
                }
                digitSTR = "";
            }
            it++;
        }

        return out;
    }


}

int main(int argc, char *argv[])
{

    std::string testString1 = "";
    std::string testString2 = "1a1b1c";
    std::string testString3 = "2n5b6c11v";

    std::cout << testString1 << ", " << decode(testString1) << std::endl;
    std::cout << testString2 << ", " << decode(testString2) << std::endl;
    std::cout << testString3 << ", " << decode(testString3) << std::endl;

    return 0;
}


