#include "FamilyTree.h"

FamilyTree::FamilyTree()
    {
    }

 FamilyTree::FamilyTree( std::string xmlFile , std::string gtrFile  )
    {
        if( !xmlFile.empty () )
            xmlFileStream.open ( xmlFile );

        if( !gtrFile.empty () )
            gtrFileStream.open ( gtrFile );
    }

FamilyTree::~FamilyTree()
    {
        xmlFileStream.close ();
        gtrFileStream.close ();
    }

// ========================================================================

bool FamilyTree::xmlFileIsOpen ()
    {
        if( xmlFileStream.is_open ())
            return true;

        return false;
    }

bool FamilyTree::gtrFileIsOpen ()
    {
        if( gtrFileStream.is_open ())
            return true;

        return false;
    }

// ==========================================================================
