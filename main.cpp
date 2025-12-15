#include <iostream>
#include <sstream>
#include <fstream>

class passData
{
    public:




    private:
    std::string site;
    std::string password;

    void getPassword(const std::string& site, const std::string& password)
    {
        std::ofstream file("passwords.txt", std::ios::app);
        if(file.is_open())
        {
            file << site << " " << password << '\n';
        }
        else {
            std::cerr << "File wasnt opened" <<'\n';
        }
        file.close();

    }

    void fetchPasswords()
    {
        std::ifstream file("passwords.txt");
        if(file.is_open())
        {
            std::string site, password, line;
            while(std::getline(file, line))
            {
                std::stringstream ss(line);
                ss >> site >> password;
            }
        }
        else
        {
            std::cerr << "No go" <<'\n';
        }

    }

}



int main()
{

}

