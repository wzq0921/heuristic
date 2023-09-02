#pragma once
#include <iostream>
#include <vector>
#include <tinyxml.h>
#include <tinystr.h>
#include <string>
typedef struct customer
{
    int pos_x;
    int pos_y;
    int serve_time;
    int need;
} customer;

class Map
{
    std::vector<customer> customer_list;

public:
    Map(std::string file_name);
    int get_distance(int p1, int p2);
    customer get_customer(int index);
};