#include "VRPTW_map.h"
#include "tinyxml.h"
Map::Map(const char* file_name)
{
    // TiXmlDocument instance(file_name);
    TiXmlDocument instance;                              
    instance.LoadFile(file_name);
    TiXmlElement *instance_element = instance.RootElement();
    TiXmlElement *info_element = instance_element->FirstChildElement();
    TiXmlElement *network_element = info_element->NextSiblingElement();
    TiXmlElement *fleet_element = network_element->NextSiblingElement();
    TiXmlElement *requests_element = fleet_element->NextSiblingElement();

    auto p = fleet_element->FirstChildElement()->FirstChildElement("capacity");
    Map::t.capacity = atoi(p->GetText());
    p = fleet_element->FirstChildElement()->FirstChildElement("max_travel_time");
    Map::t.max_travel_time = atoi(p->GetText());

    Map::truck_num = atoi(fleet_element->FirstChildElement()->Attribute("number"));
    Map::Map_name = info_element->FirstChildElement("name")->GetText();

    auto nodes = network_element->FirstChildElement();
    for (auto p1 = nodes->FirstChildElement(), p2 = requests_element->FirstChildElement();
         p1 != NULL; p1 = p1->NextSiblingElement(), p2 = p2->NextSiblingElement())
    {
        auto cx = p1->FirstChildElement("cx")->GetText();
        auto cy = p1->FirstChildElement("cy")->GetText();
        auto start = p2->FirstChildElement()->FirstChildElement("start")->GetText();
        auto end = p2->FirstChildElement()->FirstChildElement("end")->GetText();
        auto need = p2->FirstChildElement("quantity")->GetText();
        auto service = p2->FirstChildElement("service_time")->GetText();

        customer tmp;
        tmp.pos_x = atoi(cx);
        tmp.pos_y = atoi(cy);
        tmp.need = strtod(need, NULL);
        tmp.serve_time = strtod(service, NULL);
        tmp.begin_window = atoi(start);
        tmp.end_window = atoi(end);

        Map::customer_list.emplace_back(tmp);
    }
}