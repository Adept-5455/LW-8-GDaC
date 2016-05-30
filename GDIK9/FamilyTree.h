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
            ~FamilyTree();

            bool xmlFileIsOpen();
            bool gtrFileIsOpen();

            void injectFiles( std::string, std::string );
            void loadGtrData();
            void loadXmlData();
            void writeGtrData();
            void writeXmlData();

            void clear();
    };

#endif // FAMILYTREE_H
