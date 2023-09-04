#include "VRPTW_map.h"
#include "tinyxml.h"
#include <cmath>
Map::Map(const char *file_name)
{
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
    auto depot = nodes->FirstChildElement();
    Map::depot_x = atoi(depot->FirstChildElement("cx")->GetText());
    Map::depot_y = atoi(depot->FirstChildElement("cy")->GetText());
    customer tmp;
    tmp.pos_x = Map::depot_x;
    tmp.pos_y = Map::depot_y;
    tmp.need = 0;
    tmp.serve_time = 0;
    tmp.begin_window = 0;
    tmp.end_window = 10000;
    Map::customer_list.emplace_back(tmp);
    for (auto p1 = depot->NextSiblingElement(), p2 = requests_element->FirstChildElement();
         p1 != NULL; p1 = p1->NextSiblingElement(), p2 = p2->NextSiblingElement())
    {
        auto cx = p1->FirstChildElement("cx")->GetText();
        auto cy = p1->FirstChildElement("cy")->GetText();
        auto start = p2->FirstChildElement()->FirstChildElement("start")->GetText();
        auto end = p2->FirstChildElement()->FirstChildElement("end")->GetText();
        auto need = p2->FirstChildElement("quantity")->GetText();
        auto service = p2->FirstChildElement("service_time")->GetText();

        tmp.pos_x = atoi(cx);
        tmp.pos_y = atoi(cy);
        tmp.need = strtod(need, NULL);
        tmp.serve_time = strtod(service, NULL);
        tmp.begin_window = atoi(start);
        tmp.end_window = atoi(end);

        Map::customer_list.emplace_back(tmp);
    }
}

double Map::get_distance(int p1,int p2){
    double x2 = pow(customer_list[p1].pos_x-customer_list[p2].pos_x,2);
    double y2 = pow(customer_list[p1].pos_y-customer_list[p2].pos_y,2);
    return sqrt(x2+y2);
}

customer Map::get_customer(int index){
    return customer_list[index];
}