#include "FamilyTree.h"

FamilyTree::FamilyTree()
    {
    }

 FamilyTree::FamilyTree( std::string xmlFile , std::string gtrFile  )
    // Neloreck
    {
        if( !xmlFile.empty () )
            xmlFileStream.open ( xmlFile );

        if( !gtrFile.empty () )
            gtrFileStream.open ( gtrFile );
    }

FamilyTree::~FamilyTree()
    // Neloreck
    {
        xmlFileStream.close ();
        gtrFileStream.close ();
    }

// ========================================================================

bool FamilyTree::xmlFileIsOpen ()
    // Neloreck
    {
        if( xmlFileStream.is_open ())
            return true;

        return false;
    }

bool FamilyTree::gtrFileIsOpen ()
    // Neloreck
    {
        if( gtrFileStream.is_open ())
            return true;

        return false;
    }

void FamilyTree::clear()
    // Neloreck
    {
        data.clear();
    }

// ==========================================================================

void FamilyTree::injectFiles ( std::string xmlFile , std::string gtrFile )
    // Neloreck
    {
        if( !xmlFile.empty () )
            xmlFileStream.open ( xmlFile );

        if( !gtrFile.empty () )
            gtrFileStream.open ( gtrFile );
    }

void FamilyTree::loadXmlData ()
    // Neloreck
    {
        if( !xmlFileStream.is_open () )
            return ;

        xmlFileStream.setf();

    }

void FamilyTree::writeXmlData ()
    // Neloreck
    {
        if( !xmlFileStream.is_open () )
            return ;


    }
