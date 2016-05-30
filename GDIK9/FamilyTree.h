#ifndef FAMILYTREE_H
#define FAMILYTREE_H

#include <string>
#include <vector>
#include <fstream>

struct person
    {
        std::string name;
        std::string surname;
        std::string bdate;
        std::string gender;
    };

class FamilyTree
    {
    private:
            std::vector <person> data ;
            std::fstream gtrFileStream;
            std::fstream xmlFileStream;

    public:
            FamilyTree();
            FamilyTree( std::string , std::string  ) ;

            void injectFiles( std::string, std::string );
            bool xmlFileIsOpen();
            bool gtrFileIsOpen();

            void loadGtrData();
            void loadXmlData();
            void writeGtrData();
            void writeXmlData();

            void erase();
    };

#endif // FAMILYTREE_H
