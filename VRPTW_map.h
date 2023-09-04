#pragma once
#include <iostream>
#include <vector>
#include "tinyxml.h"
#include "tinystr.h"


typedef struct customer
{
    int pos_x;
    int pos_y;
    double serve_time;
    double need;
    int begin_window;
    int end_window;
} customer;

typedef struct truck{
    int capacity;
    int max_travel_time;
}truck;

class Map
{
    std::vector<customer> customer_list;    //0号节点是场站，其中服务时间和需求为0，时间窗从0-10000
    int depot_x;
    int depot_y;
    const char *Map_name;
    int truck_num;
    truck t; //卡车参数，包括容量和最长服务时间
    
public:
    Map(const char* file_name);         
    double get_distance(int p1, int p2);
    customer get_customer(int index);
};