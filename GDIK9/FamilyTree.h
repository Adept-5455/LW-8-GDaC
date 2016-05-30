#ifndef FAMILYTREE_H
#define FAMILYTREE_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

void trimXmlSign( std::string& ) ;

struct person
    {
        std::string name;
        std::string surname;
        std::string bdate;
        std::string gender;
        std::string level;
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
