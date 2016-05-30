#include <iostream>
#include "FamilyTree.h"

int main()
    {
        FamilyTree fTree( "xmlFileExample.xml", "gtrFileExample.gtr " );
        fTree.loadXmlData ();
        fTree.injectFiles ( "test.xml", "gtrFileExample2.gtr ");
        fTree.writeXmlData ();

        return 0;
    }

