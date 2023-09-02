#include "VRPTW_map.h"

Map::Map(std::string file_name){
    TiXmlDocument* tinyXmlDoc = new TiXmlDocument();
    tinyXmlDoc->LoadFile(file_name);

}