#include <iostream>
#include <sstream>
#include <fstream>

class passwordManager
{
    public:

    void displayMenu()
    {
        do
        {
            std::cout<<"Enter a choice" << '\n';
            std::cin >> check;

            switch(check)
            {
                case 1:
                    std::cout<<"Enter site name" << '\n';
                    std::cin >>site;
                    std::cout<<"Enter site password" << '\n';
                    std::cin >> password;
                    getPassword(site,password);
                    break;
                case 2:
                    std::cout<<"Your passwords will be read as followed" << '\n';
                    fetchPasswords();
                    break;
                case 3:
                    std::cout<<"Program will be exited now" << '\n';
                    break;
            }


            
        }while(check != 3);
    }



    private:
    std::string site;
    std::string password;
    int check;

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
                std::cout << " Site " << site << " Password " << password << '\n';
            }
        }
        else
        {
            std::cerr << "No go" <<'\n';
        }
    }

};



int main()
{
    passwordManager dataobj;
    dataobj.displayMenu();
}

