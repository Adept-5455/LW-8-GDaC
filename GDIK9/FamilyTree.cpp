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

void trimXmlSign( std::string& tmpStr )
    {
        tmpStr.erase( tmpStr.begin (),  tmpStr.begin() + tmpStr.find( ">"  ) + 1 ) ;
        tmpStr.erase( tmpStr.begin () + tmpStr.find( "<" ), tmpStr.end () ) ;
    }

void FamilyTree::injectFiles ( std::string xmlFile , std::string gtrFile )
    // Neloreck
    {
        if( !xmlFile.empty () )
            xmlFileStream.open ( xmlFile );
        else
            {
                xmlFileStream.close ();
                xmlFileStream.open ( xmlFile );
            }

        if( !gtrFile.empty () )
            gtrFileStream.open ( gtrFile );
        else
            {
                gtrFileStream.close ();
                gtrFileStream.open ( xmlFile );
            }
    }

void FamilyTree::loadXmlData ()
    // Neloreck
    {
        if( !xmlFileStream.is_open () )
            return ;

        xmlFileStream.seekg (0) ;

        std::string buff ;
        person tmpPerson ;

         // ================================================
        while(  !xmlFileStream.eof()  )
            {
                std::getline( xmlFileStream, buff );

                if( buff.find( "<name>" ) != std::string::npos )
                    {
                        trimXmlSign( buff ) ;
                        tmpPerson.name = buff ;
                    }

                if( buff.find( "<surname>" ) != std::string::npos )
                    {
                        trimXmlSign( buff ) ;
                        tmpPerson.surname = buff ;
                    }

                if( buff.find( "<gender>" ) != std::string::npos )
                    {
                        trimXmlSign( buff ) ;
                        tmpPerson.gender = buff ;
                    }

                if( buff.find( "<bdate>" ) != std::string::npos )
                    {
                        trimXmlSign( buff ) ;
                        tmpPerson.bdate = buff ;
                    }

                if( buff.find( "<level>" ) != std::string::npos )
                    {
                        trimXmlSign( buff ) ;
                        tmpPerson.level = buff ;

                        data.push_back ( tmpPerson );
                    }

                // ================================================
            }
    }

void FamilyTree::writeXmlData ()
    // Neloreck
    {
        if( !xmlFileStream.is_open () )
            return ;

        xmlFileStream.seekg (0) ;
        xmlFileStream << "<tree>" << std::endl ;

        for( unsigned int i = 0 ; i < data.size () ; i ++ )
            {
                xmlFileStream   << '\t' << "<person>" << std::endl ;

                xmlFileStream   << "\t  " << "<name>"
                                << data[i].name << "</name>" << std::endl ;

                xmlFileStream   << "\t  " << "<surname>"
                                << data[i].surname << "</surname>" << std::endl ;

                xmlFileStream   << "\t  " << "<gender>"
                                << data[i].gender << "</gender>" << std::endl ;

                xmlFileStream   << "\t  " << "<bdate>"
                                << data[i].bdate << "</bdate>" << std::endl ;

                xmlFileStream   << "\t  " << "<level>"
                                << data[i].level << "<//level>" << std::endl ;

                xmlFileStream   << '\t' << "</person>"
                                << std::endl << std::endl ;
            }

        xmlFileStream << "</tree>" << std::endl ;
    }
