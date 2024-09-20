#include "orderbook.hpp"
#include "csv_reader.hpp"
#include <map>

/** construct reading a csv file */
OrderBook::OrderBook(std::string& filename) {
    m_orders = CSVReader::ReadCSV(filename);
}

/** return vector of all known products (eg: USD, ETH, etc.) */
std::vector<std::string> OrderBook::GetKnownProducts() {
    std::vector<std::string> products;
    std::map<std::string, bool> prod_map;

    for (auto& order: m_orders) {
        prod_map[order.GetProduct()] = true;
    }

    // now flatten the map to a vector of strings
    for (auto const& item : prod_map) {
        products.push_back(item.first);
    }

    return products;
}

/** return vector of orders according to the sent filters */
std::vector<OrderBookEntry> OrderBook::GetOrders(OrderType type, std::string product, std::string timestamp) {
    std::vector<OrderBookEntry> orders_sub;

    for (auto& item : m_orders) {
        if (item.GetOrderType() == type && item.GetProduct() == product && item.GetTimeStamp() == timestamp) {
            orders_sub.push_back(item);
        }
    }

    return orders_sub;
}

double OrderBook::GetHighPrice(std::vector<OrderBookEntry>& orders) {
    double max = orders[0].GetPrice();

    for (auto& order : orders) {
        if (order.GetPrice() > max)
            max = order.GetPrice();
    }

    return max;
}

double OrderBook::GetLowPrice(std::vector<OrderBookEntry>& orders) {
    double min = orders[0].GetPrice();

    for (auto& order : orders) {
        if (order.GetPrice() < min)
            min = order.GetPrice();
    }

    return min;
}

std::string OrderBook::GetEarliestTime() {
    return m_orders[0].GetTimeStamp();
}

std::string OrderBook::GetNextTime(std::string& timestamp) {
    std::string next_timestamp = "";

    for (auto& order : m_orders) {
        if (order.GetTimeStamp() > timestamp) {
            next_timestamp = order.GetTimeStamp();
            break;
        }
    }

    if (next_timestamp == "") {
        next_timestamp = m_orders[0].GetTimeStamp();
    }

    return next_timestamp;
}
